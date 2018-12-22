#pragma once

#include <string>

#include <QStandardItemModel>
#include <QTransform>

#include <nsxlib/DataSet.h>
#include <nsxlib/Experiment.h>
#include <nsxlib/Peak.h>

#include "ColorMap.h"

class DataSet;
class Experiment;
class ExperimentItem;
class Peak;
class SXPlot;

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

    void selectPeak(nsx::sptrPeak selected_peak);

signals:

    void inspectWidget(QWidget*);

    void signalUpdatePeaks();

    void signalResetScene();

    void signalSelectedDataChanged(nsx::sptrDataSet, int frame);

    void signalChangeSelectedPeak(nsx::sptrPeak peak);

    void signalEnabledPeakChanged(nsx::sptrPeak peak);

    void signalMaskedPeaksChanged(nsx::sptrDataSet data);

    void signalUnitCellRemoved(nsx::sptrUnitCell unit_cell);

    void signalChangeColorMap(const ColorMap &color_map);

    void signalChangeDetectorViewTransformation(const QTransform &transformation);

    void signalChangePlot(SXPlot* plot);

public slots:

    void onItemChanged(QStandardItem* item);

private:

    ColorMap _color_map;

    QTransform _detector_view_transformation;
};
