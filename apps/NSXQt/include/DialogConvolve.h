// author: Jonathan Fisher
// j.fisher@fz-juelich.de

#ifndef NSXTOOL_DIALOGCONVOLVE_H_
#define NSXTOOL_DIALOGCONVOLVE_H_

#include <QDialog>
#include <QGraphicsScene>
#include <QGraphicsPixmapItem>
#include <QStandardItemModel>

#include <Eigen/Core>

#include <map>
#include <string>
#include <memory>

#include "Convolver.h"
#include "ConvolutionKernel.h"
#include "PeakFindModel.h"
#include "PeakFinder.h"


namespace Ui {
class DialogConvolve;
}

class DialogConvolve : public QDialog
{
    Q_OBJECT

public:
    explicit DialogConvolve(const Eigen::MatrixXi& currentFrame, QWidget *parent = 0);
    ~DialogConvolve();
/*
    double getThreshold();
    double getConfidence();

    int getMinComponents();
    int getMaxComponents();

    bool thesholdIsRelative();

    std::shared_ptr<SX::Imaging::Convolver> getConvolver();
    std::shared_ptr<SX::Imaging::ConvolutionKernel> getKernel();
*/
    void setPreviewFrame(const Eigen::MatrixXi& frame);
    void setPeakFinder(std::shared_ptr<SX::Data::PeakFinder> peakFinder);


private slots:
    void on_previewButton_clicked();

    void on_filterComboBox_currentIndexChanged(int index);

    void on_parameter1_valueChanged(int arg1);
    void on_parameter2_valueChanged(int arg1);
    void on_parameter3_valueChanged(int arg1);

    void on_thresholdSpinBox_valueChanged(double arg1);

    void on_confidenceSpinBox_valueChanged(double arg1);

    void on_minCompBox_valueChanged(int arg1);

    void on_maxCompBox_valueChanged(int arg1);

    void on_thresholdComboBox_currentIndexChanged(int index);

private:
    Ui::DialogConvolve *ui;
    QGraphicsScene* scene;
    QGraphicsPixmapItem* pxmapPreview;

    Eigen::MatrixXi frame;

    std::shared_ptr<SX::Data::PeakFinder> _peakFinder;
    std::shared_ptr<SX::Imaging::Convolver> _convolver;

};
#endif // NSXTOOL_DIALOGCONVOLVE_H_
