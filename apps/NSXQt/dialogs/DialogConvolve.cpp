// author: Jonathan Fisher
// j.fisher@fz-juelich.de

#include "DialogConvolve.h"
#include "ui_ConvolveDialog.h"

#include "KernelFactory.h"

#include "ColorMap.h"
#include <QImage>
#include <QTreeView>
#include <QStandardItem>
#include <QStandardItemModel>
#include <QList>

#include <Eigen/Core>
#include <QDebug>

#include <iostream>

#include "Types.h"

using RealMatrix = SX::Types::RealMatrix;

using std::cout;
using std::endl;

DialogConvolve::DialogConvolve(const Eigen::MatrixXi& currentFrame, std::shared_ptr<SX::Data::PeakFinder> peakFinder, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogConvolve),
    frame(currentFrame)
{
    ui->setupUi(this);

    //this->setWindowTitle(nsx");

    // disable resizing
    this->setFixedSize(this->size());

    if (!peakFinder)
        _peakFinder = std::shared_ptr<SX::Data::PeakFinder>(new SX::Data::PeakFinder);
    else
        setPeakFinder(peakFinder);

    //ui->graphicsView->setAcceptDrops();

    scene = new QGraphicsScene(this);
    ui->graphicsView->setScene(scene);
    // flip image vertically to conform with DetectorScene
    ui->graphicsView->scale(1, -1);

    // get pixmap from current frame
    int nrows = frame.rows();
    int ncols = frame.cols();
    int max_intensity = 1000;

    Eigen::Matrix<int,Eigen::Dynamic,Eigen::Dynamic,Eigen::RowMajor> rowFrame(frame);
    // jmf debug testing
    pxmapPreview = scene->addPixmap(QPixmap::fromImage(Mat2QImage(rowFrame.data(), nrows, ncols, 0, ncols-1, 0, nrows-1, max_intensity)));

    SX::Imaging::KernelFactory* kernelFactory=SX::Imaging::KernelFactory::Instance();

    ui->filterComboBox->clear();
    ui->filterComboBox->addItem("none");
    for (const auto& k : kernelFactory->list())
        ui->filterComboBox->addItem(QString::fromStdString(k));
}

DialogConvolve::~DialogConvolve()
{
    delete ui;
    // this should be handled by Qt. check with valgrind?
    // delete _peakFindModel;
}

void DialogConvolve::setPeakFinder(std::shared_ptr<SX::Data::PeakFinder> peakFinder)
{

    if (_peakFinder)
        return;

    _peakFinder = peakFinder;

    std::shared_ptr<SX::Imaging::ConvolutionKernel> kernel = peakFinder->getKernel();
    std::string kernelName = kernel ? kernel->getName() : "none";

    // need to update widgets with appropriate values
    ui->thresholdSpinBox->setValue(_peakFinder->getThresholdValue());
    ui->thresholdComboBox->setCurrentIndex(_peakFinder->getThresholdType());
    ui->confidenceSpinBox->setValue(_peakFinder->getConfidence());
    ui->minCompBox->setValue(_peakFinder->getMinComponents());
    ui->maxCompBox->setValue(_peakFinder->getMaxComponents());
    ui->filterComboBox->setCurrentText(QString::fromStdString(kernelName));

    buildTree();
}

void DialogConvolve::buildTree()
{
    // reset tree
    QTreeView* treeView = ui->treeView;
    treeView->reset();
    treeView->header()->hide();

    // no peakfinder set?!
    if (!_peakFinder)
        return;

    // get the selected kernel (if any)
    std::shared_ptr<SX::Imaging::ConvolutionKernel> kernel = _peakFinder->getKernel();

    QStandardItemModel* model = new QStandardItemModel(this);

    // no kernel selected: do nothing
    if (kernel)
    {
		// get parameters
		std::map<std::string, double> parameters = kernel->getParameters();

		// iterate through parameters to build the tree
		for (auto it: parameters) {
			// rows parameter fixed by data frame
			if ( it.first == "rows")
				continue;
			// cols parameter fixed by data frame
			if ( it.first == "cols" )
				continue;

			// otherwise, editable parameter so add it to the list

			QStandardItem* name = new QStandardItem();
			name->setText(it.first.c_str());
			name->setEditable(false);

			QStandardItem* value = new QStandardItem();

			name->setText(it.first.c_str());
			value->setData(QVariant(it.second), Qt::EditRole|Qt::DisplayRole);
			value->setData(QVariant(it.first.c_str()), Qt::UserRole);

			model->appendRow(QList<QStandardItem*>() << name << value);
		}
    }

	treeView->setModel(model);

    connect(model, SIGNAL(itemChanged(QStandardItem*)), this, SLOT(parameterChanged(QStandardItem*)));
}

void DialogConvolve::on_previewButton_clicked()
{
    RealMatrix data, result;
    Eigen::Matrix<int, Eigen::Dynamic, Eigen::Dynamic, Eigen::RowMajor> clamped_result;

    int nrows, ncols;

    nrows = frame.rows();
    ncols = frame.cols();

    // note that treeWidget retains ownership!
    //ui->treeWidgetOld->retrieveParameters();
    //_kernel = ui->treeWidgetOld->getKernel();
    auto kernel = _peakFinder->getKernel();

    if (!kernel) {
        qDebug() << "null kernel returned!";
        return;
    }

    std::cout<<_peakFinder<<std::endl;
    std::cout<<kernel->getName()<<std::endl;

    // dimensions must match image dimensions
    kernel->getParameters()["rows"] = frame.rows();
    kernel->getParameters()["cols"] = frame.cols();
    std::cout<<kernel->getName()<<std::endl;

    // set up convolver
    auto convolver = _peakFinder->getConvolver();
    convolver->setKernel(kernel->getKernel());
    std::cout<<kernel->getKernel()<<std::endl;

    // compute the convolution!
    data = frame.cast<double>();

    result = convolver->apply(data);
    clamped_result.resize(frame.rows(),frame.cols());

    int max_intensity = 1000;

    // apply a simple theshold
    // TODO: incorporate into GUI, or improve in some other way

    double background;

    // threshold relative to background
    if (_peakFinder->getThresholdType() == 0)
        background = data.sum() / ((double)frame.rows()*frame.cols());
    else
        background = 1.0;

    qDebug() << "Generating preview image with background of " << background;

    for ( int i = 0; i < nrows*ncols; ++i)
        clamped_result.data()[i] =
                result.data()[i] > _peakFinder->getThresholdValue()*background ? max_intensity-1 : 0;

    QImage image = Mat2QImage(clamped_result.data(), frame.rows(), frame.cols(), 0, ncols-1, 0, nrows-1, max_intensity);
    QPixmap pixmap = QPixmap::fromImage(image);
    pxmapPreview->setPixmap(pixmap);
}

void DialogConvolve::on_filterComboBox_currentIndexChanged(int index)
{
    std::shared_ptr<SX::Imaging::ConvolutionKernel> kernel;

    switch(index)
    {
    // no kernel
    case 0:
        kernel.reset();
        break;
    default:
        std::string kernelName = ui->filterComboBox->currentText().toStdString();
        SX::Imaging::KernelFactory* kernelFactory = SX::Imaging::KernelFactory::Instance();
        if (!kernelFactory->hasCallback(kernelName))
        {
            qDebug() << "Warning: unrecognized kernel selected -- defaulting to NO kernel";
            kernel.reset();
        }
        kernel.reset(kernelFactory->create(kernelName));
        break;
    }

    if (kernel )
    {
        kernel->getParameters()["rows"] = frame.rows();
        kernel->getParameters()["cols"] = frame.cols();
    }

    // propagate changes to peak finder
    _peakFinder->setKernel(kernel);

    // update dialog with list of parameters
    buildTree();
}


void DialogConvolve::on_thresholdSpinBox_valueChanged(double arg1)
{
    _peakFinder->setThresholdValue(arg1);
}

void DialogConvolve::on_confidenceSpinBox_valueChanged(double arg1)
{
    _peakFinder->setConfidence(arg1);
}

void DialogConvolve::on_minCompBox_valueChanged(int arg1)
{
    _peakFinder->setMinComponents(arg1);
}

void DialogConvolve::on_maxCompBox_valueChanged(int arg1)
{
    _peakFinder->setMaxComponents(arg1);
}

void DialogConvolve::on_thresholdComboBox_currentIndexChanged(int index)
{
    _peakFinder->setThresholdType(index);
    qDebug() << "threshold type index is " << index;
}

void DialogConvolve::parameterChanged(QStandardItem *item)
{
    // nothing to do
    if (!item || !_peakFinder)
        return;

    auto kernel = _peakFinder->getKernel();

    // still nothing to do
    if (!kernel)
        return;

    auto& parameters = kernel->getParameters();

    // extract name and value
    auto name = item->data(Qt::UserRole).toString().toStdString();
    auto value = item->data(Qt::EditRole).toDouble();

    // update
    parameters[name] = value;
}
