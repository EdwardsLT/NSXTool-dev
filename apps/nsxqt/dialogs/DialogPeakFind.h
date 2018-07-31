#pragma once

#include <map>
#include <memory>
#include <string>

#include <Eigen/Dense>

#include <QDialog>
#include <QGraphicsPixmapItem>
#include <QGraphicsScene>
#include <QResizeEvent>
#include <QShowEvent>
#include <QStandardItem>

#include <nsxlib/CrystalTypes.h>
#include <nsxlib/DataTypes.h>

#include "ColorMap.h"

namespace Ui {
class DialogPeakFind;
}

class DialogPeakFind : public QDialog
{
    Q_OBJECT

public:
    explicit DialogPeakFind(const nsx::DataList& data,QWidget *parent = 0);
    ~DialogPeakFind();

    void setPreviewFrame(const Eigen::MatrixXi& frame);
    void setColorMap(const std::string& name);
    void showEvent(QShowEvent*) override;
    void resizeEvent(QResizeEvent*) override;
    double peakScale() const;
    double bkgBegin() const;
    double bkgEnd() const;

    const nsx::PeakList& peaks() const;

private slots:

    void clipPreview(int state);

    void changeThreshold();

    void changeConvolver(QString convolver_type);
    void changeConvolverParameters(int row, int col);

    void changeMinSize(int size);
    void changeMaxSize(int size);
    void changeMaxFrames(int size);

    void changeSelectedData(int selected_data);
    void changeSelectedFrame(int selected_frame);

    void find();

private:

    void buildConvolverParametersList();

    std::map<std::string,double> convolverParameters() const;

    void updatePreview();

private:
    Ui::DialogPeakFind *ui;
    QGraphicsScene* _scene;
    QGraphicsPixmapItem* _pxmapPreview;
    nsx::DataList _data;
    nsx::sptrPeakFinder _peakFinder;
    nsx::PeakList _peaks;

    std::unique_ptr<ColorMap> _colormap;
};
