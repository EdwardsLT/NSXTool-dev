// author: Jonathan Fisher
// j.fisher@fz-juelich.de

#ifndef NSXTOOL_DIALOGCONVOLVE_H_
#define NSXTOOL_DIALOGCONVOLVE_H_

#include <QDialog>
#include <QGraphicsScene>
#include <QGraphicsPixmapItem>
#include <QStandardItemModel>
#include <QStandardItem>

#include <Eigen/Core>

#include <map>
#include <string>
#include <memory>

#include <nsxlib/imaging/Convolver.h>
#include <nsxlib/imaging/ConvolutionKernel.h>
#include <nsxlib/data/PeakFinder.h>
#include "ColorMap.h"

namespace Ui {
class DialogConvolve;
}

class DialogConvolve : public QDialog
{
    Q_OBJECT

public:
    explicit DialogConvolve(const Eigen::MatrixXi& currentFrame,
                            std::shared_ptr<nsx::Data::PeakFinder> peakFinder=nullptr,
                            QWidget *parent = 0);
    ~DialogConvolve();

    void setPreviewFrame(const Eigen::MatrixXi& frame);
    void buildTree();
    void setColorMap(const std::string& name);
    int exec() override;

private slots:
    void on_previewButton_clicked();
    void on_filterComboBox_currentIndexChanged(int index);
    void on_thresholdSpinBox_valueChanged(double arg1);
    void on_confidenceSpinBox_valueChanged(double arg1);
    void on_minCompBox_valueChanged(int arg1);
    void on_maxCompBox_valueChanged(int arg1);
    void on_thresholdComboBox_currentIndexChanged(int index);
    void parameterChanged(QStandardItem* item);

private:
    Ui::DialogConvolve *ui;
    QGraphicsScene* _scene;
    QGraphicsPixmapItem* _pxmapPreview;
    Eigen::MatrixXi _frame;

    std::shared_ptr<nsx::Data::PeakFinder> _peakFinder;
    std::unique_ptr<ColorMap> _colormap;
};
#endif // NSXTOOL_DIALOGCONVOLVE_H_
