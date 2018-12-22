#include <fstream>
#include <map>
#include <memory>
#include <stdexcept>
#include <vector>

#include <hdf5.h>
#include <H5Exception.h>

#include <QAbstractItemView>
#include <QDate>
#include <QFileDialog>
#include <QFileInfo>
#include <QKeyEvent>

#include <QList>
#include <QListIterator>
#include <QMenu>
#include <QModelIndexList>
#include <QStandardItem>
#include <QString>
#include <QVector>

#include <nsxlib/CC.h>
#include <nsxlib/CrystalTypes.h>
#include <nsxlib/Detector.h>
#include <nsxlib/Diffractometer.h>
#include <nsxlib/Ellipsoid.h>
#include <nsxlib/GeometryTypes.h>
#include <nsxlib/InstrumentState.h>
#include <nsxlib/Logger.h>
#include <nsxlib/MergedData.h>
#include <nsxlib/MergedPeak.h>
#include <nsxlib/MillerIndex.h>
#include <nsxlib/Peak.h>
#include <nsxlib/PeakFilter.h>
#include <nsxlib/PeakFinder.h>
#include <nsxlib/ProgressHandler.h>
#include <nsxlib/ReciprocalVector.h>
#include <nsxlib/Sample.h>
#include <nsxlib/SpaceGroup.h>
#include <nsxlib/PixelSumIntegrator.h>
#include <nsxlib/Source.h>
#include <nsxlib/UnitCell.h>

#include "DataItem.h"
#include "DetectorItem.h"
#include "DialogExperiment.h"
#include "ExperimentItem.h"
#include "GLSphere.h"
#include "GLWidget.h"
#include "InstrumentItem.h"
#include "MetaTypes.h"
#include "NumorItem.h"
#include "PeakListItem.h"
#include "ProgressView.h"
#include "QCustomPlot.h"
#include "PeaksItem.h"
#include "SampleItem.h"
#include "SessionModel.h"
#include "SourceItem.h"
#include "TreeItem.h"
#include "UnitCellItem.h"

SessionModel::SessionModel()
: _color_map(),
  _detector_view_transformation()
{
    setDetectorViewTransformation(DETECTOR_VIEW::FROM_SAMPLE);
    connect(this,SIGNAL(itemChanged(QStandardItem*)),this,SLOT(onItemChanged(QStandardItem*)));
}

bool SessionModel::removeRows(int row, int count, const QModelIndex& parent)
{
    emit signalResetScene();

    return QStandardItemModel::removeRows(row,count,parent);
}

ExperimentItem* SessionModel::selectExperiment(nsx::sptrDataSet data)
{
    ExperimentItem *experiment_item=nullptr;

    for (auto i = 0; i < rowCount(); ++i) {
        experiment_item = dynamic_cast<ExperimentItem*>(item(i));
        if (!experiment_item) {
            continue;
        }

        auto data_item  = experiment_item->dataItem();
        for (auto j = 0; j < data_item->rowCount(); ++j) {
            auto numor_item = dynamic_cast<NumorItem*>(data_item->child(j));
            if (!numor_item) {
                continue;
            }

            if (numor_item->data(Qt::UserRole).value<nsx::sptrDataSet>() == data) {
                return experiment_item;
            }
        }
    }

    return experiment_item;
}

void SessionModel::selectData(nsx::sptrDataSet data)
{
    emit signalSelectedDataChanged(data,0);
}

void SessionModel::onItemChanged(QStandardItem *item)
{
    Q_UNUSED(item)

    emit signalUpdatePeaks();
}

nsx::PeakList SessionModel::peaks(nsx::sptrDataSet data) const
{
    nsx::PeakList list;

    for (auto i = 0; i < rowCount(); ++i) {
        auto exp_item = dynamic_cast<ExperimentItem*>(item(i));
        auto&& peaks = exp_item->peaksItem()->selectedPeaks();

        for (auto peak: peaks) {
            if (data == nullptr || peak->data() == data) {
                list.push_back(peak);
            }
        }
    }
    return list;
}


void SessionModel::addExperiment(nsx::sptrExperiment experiment)
{
    // Create an experiment item out of the experiment
    ExperimentItem* expt = new ExperimentItem(experiment);
    appendRow(expt);
}

void SessionModel::selectPeak(nsx::sptrPeak selected_peak)
{
    emit signalChangeSelectedPeak(selected_peak);
}

void SessionModel::setColorMap(const ColorMap &color_map)
{
    _color_map = color_map;

    emit signalChangeColorMap(_color_map);
}

const ColorMap& SessionModel::colorMap() const
{
    return _color_map;
}

void SessionModel::setDetectorViewTransformation(DETECTOR_VIEW detector_view)
{
    QTransform detector_view_transformation;

    switch (detector_view) {
    case (DETECTOR_VIEW::FROM_SAMPLE):
        detector_view_transformation.scale(1,-1);
        break;
    case (DETECTOR_VIEW::FROM_BEHIND):
        detector_view_transformation.scale(-1,-1);
        break;
    default:
        break;
    }

    _detector_view_transformation = detector_view_transformation;

    emit signalChangeDetectorViewTransformation(_detector_view_transformation);
}

const QTransform& SessionModel::detectorViewTranformation() const
{
    return _detector_view_transformation;
}
