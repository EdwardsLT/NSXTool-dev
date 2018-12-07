#pragma once

#include <string>

#include <QStandardItemModel>
#include <QTransform>

#include <nsxlib/DataSet.h>
#include <nsxlib/Experiment.h>
#include <nsxlib/Peak3D.h>

#include "ColorMap.h"

class DataSet;
class Experiment;
class ExperimentItem;
class Peak3D;

class SessionModel: public QStandardItemModel {

    Q_OBJECT

public:

    enum class DETECTOR_VIEW {FROM_SAMPLE=0, FROM_BEHIND=1};

    SessionModel();

    nsx::PeakList peaks(nsx::sptrDataSet data) const;

    void selectData(nsx::sptrDataSet data);

    ExperimentItem* selectExperiment(nsx::sptrDataSet data);

    void addExperiment(nsx::sptrExperiment experiment);

    bool removeRows(int row, int count, const QModelIndex& parent) override;

    void setColorMap(const ColorMap &color_map);
    const ColorMap& colorMap() const;

    void setDetectorViewTransformation(DETECTOR_VIEW detector_view);

    const QTransform& detectorViewTranformation() const;

signals:

    void plotData(nsx::sptrDataSet);

    void inspectWidget(QWidget*);

    void updatePeaks();

    void signalResetScene();

    void signalSelectedDataChanged(nsx::sptrDataSet, int frame);

    void signalSelectedPeakChanged(nsx::sptrPeak3D peak);

    void signalEnabledPeakChanged(nsx::sptrPeak3D peak);

    void signalMaskedPeaksChanged(const nsx::PeakList& peaks);

    void signalUnitCellRemoved(nsx::sptrUnitCell unit_cell);

    void signalChangeColorMap(const ColorMap &color_map);

    void signalChangeDetectorViewTransformation(const QTransform &transformation);

public slots:

    void onItemChanged(QStandardItem* item);

private:

    ColorMap _color_map;

    QTransform _detector_view_transformation;
};
