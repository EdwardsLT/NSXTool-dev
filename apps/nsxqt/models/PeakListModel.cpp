#include <algorithm>
#include <fstream>
#include <iomanip>
#include <limits>
#include <vector>

#include <QIcon>
#include <QString>

#include <nsxlib/CrystalTypes.h>
#include <nsxlib/DataSet.h>
#include <nsxlib/Detector.h>
#include <nsxlib/DirectVector.h>
#include <nsxlib/Diffractometer.h>
#include <nsxlib/IDataReader.h>
#include <nsxlib/InterpolatedState.h>
#include <nsxlib/Logger.h>
#include <nsxlib/MetaData.h>
#include <nsxlib/MillerIndex.h>
#include <nsxlib/Peak.h>
#include <nsxlib/PeakFilter.h>
#include <nsxlib/ReciprocalVector.h>
#include <nsxlib/UnitCell.h>
#include <nsxlib/Units.h>

#include "PeakListModel.h"
#include "PeaksUtils.h"
#include "ProgressView.h"
#include "SessionModel.h"

QString PeakListModelColumnToString(int column)
{
    auto section = static_cast<PeakListModel::Column>(column);

    switch(section) {
    case PeakListModel::Column::H:
        return QString("h");
    case PeakListModel::Column::K:
        return QString("k");
    case PeakListModel::Column::L:
        return QString("l");
    case PeakListModel::Column::PixelX:
        return QString("pixel x");
    case PeakListModel::Column::PixelY:
        return QString("pixel y");
    case PeakListModel::Column::Frame:
        return QString("frame");
    case PeakListModel::Column::Gamma:
        return QString("%1 (%2)").arg(QChar(0x03B3)).arg(QChar(0x00B0));
    case PeakListModel::Column::Nu:
        return QString("%1 (%2)").arg(QChar(0x03B7)).arg(QChar(0x00B0));
    case PeakListModel::Column::TwoTheta:
        return QString("%1 (%2)").arg(QChar(0x03B8)).arg(QChar(0x00B0));
    case PeakListModel::Column::DSpacing:
        return QString("d");
    case PeakListModel::Column::LorentzFactor:
        return QString("lorentz factor");
    case PeakListModel::Column::Intensity:
        return QString("intensity");
    case PeakListModel::Column::SigmaIntensity:
        return QString(QChar(0x03C3))+"(intensity)";
    case PeakListModel::Column::DataSet:
        return QString("dataset");
    case PeakListModel::Column::UnitCell:
        return QString("unit cell");
    case PeakListModel::Column::Status:
        return QString("status");
    default:
        return QString();
    }
}

PeakListModel::PeakListModel(SessionModel* session_model, nsx::sptrExperiment experiment, const nsx::PeakList &peaks, QObject *parent)
: QAbstractTableModel(parent),
  _session_model(session_model),
  _experiment(experiment),
  _peaks(peaks)
{
    connect(_session_model,SIGNAL(signalEnabledPeakChanged(nsx::sptrPeak)),this,SLOT(slotChangeEnabledPeak(nsx::sptrPeak)));
    connect(_session_model,SIGNAL(signalMaskedPeaksChanged(nsx::sptrDataSet)),this,SLOT(slotChangeMaskedPeaks(nsx::sptrDataSet)));
    connect(_session_model,SIGNAL(signalUnitCellRemoved(nsx::sptrUnitCell)),this,SLOT(slotRemoveUnitCell(nsx::sptrUnitCell)));
}

PeakListModel::PeakListModel(SessionModel* session_model, nsx::sptrExperiment experiment, QObject *parent)
: PeakListModel(session_model,experiment,{},parent)
{
}

void PeakListModel::slotRemoveUnitCell(const nsx::sptrUnitCell unit_cell)
{
    Q_UNUSED(unit_cell)

    QModelIndex topleft_index = index(0,0);
    QModelIndex bottomright_index = index(rowCount(QModelIndex())-1,columnCount(QModelIndex())-1);

    emit dataChanged(topleft_index,bottomright_index);
}

void PeakListModel::slotChangeMaskedPeaks(nsx::sptrDataSet data)
{
    for (auto peak : _peaks) {
        if (peak->data() == data) {
            emit layoutChanged();
            return;
        }
    }
}

void PeakListModel::setPeaks(const nsx::PeakList& peaks) {
    reset();
    _peaks = peaks;

    QModelIndex topleft_index = index(0,0);
    QModelIndex bottomright_index = index(rowCount(QModelIndex())-1,columnCount(QModelIndex())-1);

    emit dataChanged(topleft_index,bottomright_index);
}

const nsx::PeakList& PeakListModel::peaks() const
{
    return _peaks;
}

void PeakListModel::slotChangeEnabledPeak(nsx::sptrPeak peak)
{
    auto it = std::find(_peaks.begin(),_peaks.end(),peak);
    if (it == _peaks.end()) {
        return;
    }

    int row = std::distance(_peaks.begin(),it);

    QModelIndex topleft_index = index(row,0);
    QModelIndex bottomright_index = index(row,columnCount(QModelIndex())-1);

    emit dataChanged(topleft_index,bottomright_index);
}


int PeakListModel::rowCount(const QModelIndex& parent) const
{
    Q_UNUSED(parent);

    return _peaks.size();
}

int PeakListModel::columnCount(const QModelIndex& parent) const
{
    Q_UNUSED(parent);

    return Column::Count;
}

void PeakListModel::reset()
{
    beginResetModel();
    _peaks.clear();
    endResetModel();
}

Qt::ItemFlags PeakListModel::flags(const QModelIndex &index) const
{
    if (!indexIsValid(index)) {
        return Qt::ItemIsEnabled;
    }

    return QAbstractTableModel::flags(index);
}

QVariant PeakListModel::headerData(int section, Qt::Orientation orientation, int role) const
{
    if (role != Qt::DisplayRole) {
        return QVariant();
    }

    return (orientation == Qt::Horizontal ? PeakListModelColumnToString(section) : QVariant(section+1));
}

QVariant PeakListModel::data(const QModelIndex &index, int role) const
{
    if (!indexIsValid(index)) {
        return QVariant();
    }

    Eigen::RowVector3i hkl = {0,0,0};
    Eigen::RowVector3d hkl_error = {0.0,0.0,0.0};

    int row = index.row();
    int column = index.column();
    auto cell = _peaks[row]->unitCell();
    if (cell) {
        nsx::MillerIndex miller_index(_peaks[row]->q(), *cell);
        if (miller_index.indexed(cell->indexingTolerance())) {
            hkl = miller_index.rowVector();
            hkl_error = miller_index.error();
        }
    }

    auto peak = _peaks[row];

    double intensity = peak->correctedIntensity().value();
    double sigma_intensity = peak->correctedIntensity().sigma();

    auto peak_center = nsx::DirectVector(peak->shape().center());

    auto state = peak->data()->interpolatedState(peak_center(2));

    switch (role) {

    case Qt::DisplayRole:        

        switch (column) {
        case Column::H: {
            return hkl(0);
        }
        case Column::K: {
            return hkl(1);
        }
        case Column::L: {
            return hkl(2);
        }
        case Column::PixelX: {
            return peak_center(0);
        }
        case Column::PixelY: {
            return peak_center(1);
        }
        case Column::Frame: {
            return peak_center(2);
        }
        case Column::Gamma: {
            return state.gamma(peak_center)/nsx::deg;
        }
        case Column::Nu: {
            return state.nu(peak_center)/nsx::deg;
        }
        case Column::TwoTheta: {
            return state.twoTheta(peak_center)/nsx::deg;
        }
        case Column::DSpacing: {
            return peak->d();
        }
        case Column::LorentzFactor: {
            return state.lorentzFactor(peak_center[0],peak_center[1]);
        }
        case Column::Intensity: {
            return intensity;
        }
        case Column::SigmaIntensity: {
            return sigma_intensity;
        }
        case Column::DataSet: {
            return peak->data()->reader()->metadata().key<int>("Numor");
        }
        case Column::UnitCell: {
            auto unit_cell = peak->unitCell();
            if (unit_cell) {
                return QString::fromStdString(unit_cell->name());
            } else {
                return QString("not set");
            }
        }
        case Column::Status: {
            return (peak->masked() ? "masked" : PeakStatusToString(_peaks[row]));
        }
        }
        break;
    case Qt::BackgroundRole: {
        return QBrush(peak->masked() ? Qt::gray : Qt::white);
        break;
    }
    case Qt::ToolTipRole:
        switch (column) {
        case Column::H:
            return hkl[0]+hkl_error[0];
        case Column::K:
            return hkl[1]+hkl_error[1];
        case Column::L:
            return hkl[2]+hkl_error[2];
        }
        break;
    }
    return QVariant::Invalid;
}

void PeakListModel::sort(int column, Qt::SortOrder order)
{
    std::function<bool(nsx::sptrPeak, nsx::sptrPeak)> compareFn = [](nsx::sptrPeak, nsx::sptrPeak) { return false; };

    switch (column) {
    case Column::H: {
        compareFn = [&](nsx::sptrPeak p1, nsx::sptrPeak p2) {
            auto cell1 = p1->unitCell();
            auto cell2 = p2->unitCell();
            if (cell1 && cell2){
                nsx::MillerIndex miller_index1(p1->q(), *cell1);
                nsx::MillerIndex miller_index2(p2->q(), *cell2);
                return (miller_index1[0]<miller_index2[0]);
            } else {
                return ((cell1 != nullptr) < (cell2 != nullptr));
            }
        };
        break;
    }
    case Column::K: {
        compareFn = [&](nsx::sptrPeak p1, nsx::sptrPeak p2) {
            auto cell1 = p1->unitCell();
            auto cell2 = p2->unitCell();
            if (cell1 && cell2){
                nsx::MillerIndex miller_index1(p1->q(), *cell1);
                nsx::MillerIndex miller_index2(p2->q(), *cell2);
                return (miller_index1[1]<miller_index2[1]);
            } else {
                return ((cell1 != nullptr) < (cell2 != nullptr));
            }
        };
        break;
    }
    case Column::L: {
        compareFn = [](nsx::sptrPeak p1, nsx::sptrPeak p2) {
            auto cell1 = p1->unitCell();
            auto cell2 = p2->unitCell();
            if (cell1 && cell2){
                nsx::MillerIndex miller_index1(p1->q(), *cell1);
                nsx::MillerIndex miller_index2(p2->q(), *cell2);
                return (miller_index1[2]<miller_index2[2]);
            } else {
                return ((cell1 != nullptr) < (cell2 != nullptr));
            }
        };
        break;
    }
    case Column::PixelX: {
        compareFn = [](nsx::sptrPeak p1, nsx::sptrPeak p2) {
            auto center1 = p1->shape().center();
            auto center2 = p2->shape().center();
            return (center1[0] < center2[0]);
        };
        break;
    }
    case Column::PixelY: {
        compareFn = [](nsx::sptrPeak p1, nsx::sptrPeak p2) {
            auto center1 = p1->shape().center();
            auto center2 = p2->shape().center();
            return (center1[1] < center2[1]);
        };
        break;
    }
    case Column::Frame: {
        compareFn = [](nsx::sptrPeak p1, nsx::sptrPeak p2) {
            auto center1 = p1->shape().center();
            auto center2 = p2->shape().center();
            return (center1[2] < center2[2]);
        };
        break;
    }
    case  Column::Intensity: {
        compareFn = [](nsx::sptrPeak p1, nsx::sptrPeak p2) {
            auto intensity1 = p1->correctedIntensity().value();
            auto intensity2 = p2->correctedIntensity().value();
            return (intensity1 < intensity2);
        };
        break;
    }
    case Column::SigmaIntensity: {
        compareFn = [](nsx::sptrPeak p1, nsx::sptrPeak p2) {
            auto sigma_intensity1 = p1->correctedIntensity().sigma();
            auto sigma_intensity2 = p2->correctedIntensity().sigma();
            return (sigma_intensity1 < sigma_intensity2);
        };
        break;
    }
    case Column::DataSet: {
        compareFn = [&](nsx::sptrPeak p1, nsx::sptrPeak p2) {
            int numor1=p1->data()->reader()->metadata().key<int>("Numor");
            int numor2=p2->data()->reader()->metadata().key<int>("Numor");
            return (numor1 < numor2);
        };
        break;
    }
    case Column::UnitCell: {
        compareFn = [&](nsx::sptrPeak p1, const nsx::sptrPeak p2) {
            auto uc1 = p1->unitCell();
            auto uc2 = p2->unitCell();
            std::string uc1Name = uc1 ? uc1->name() : "";
            std::string uc2Name = uc2 ? uc2->name() : "";
            return (uc2Name<uc1Name);
        };
        break;
    }
    case Column::Status: {
        compareFn = [&](nsx::sptrPeak p1, const nsx::sptrPeak p2) {
            auto status1 = p1->status();
            auto status2 = p2->status();
            return (status1<status2);
        };
        break;
    }
    }
    std::sort(_peaks.begin(), _peaks.end(), compareFn);

    if (order == Qt::DescendingOrder) {
        std::reverse(_peaks.begin(),_peaks.end());
    }
    emit layoutChanged();
}

void PeakListModel::togglePeakSelection(QModelIndex peak_index)
{
    int row = peak_index.row();

    auto peak = _peaks[row];

    using Status = nsx::Peak::Status;

    peak->setStatus(peak->status() == Status::Selected ? Status::Unselected : Status::Selected);

    QModelIndex topleft_index = index(row,0);
    QModelIndex bottomright_index = index(row,columnCount(QModelIndex())-1);

    emit dataChanged(topleft_index,bottomright_index);

    emit _session_model->signalEnabledPeakChanged(peak);
}

void PeakListModel::selectPeak(const QModelIndex& index)
{
    auto selected_peak = _peaks[index.row()];

    _session_model->selectPeak(selected_peak);
}

bool PeakListModel::indexIsValid(const QModelIndex& index) const
{
    return index.isValid() && (index.row() < static_cast<int>(_peaks.size()));
}

void PeakListModel::sortEquivalents()
{
    // todo: investigate this method. Likely incorrect if there are multiple unit cells.
    auto cell=_peaks[0]->unitCell();

    // If no unit cell defined for the peak collection, return.
    if (!cell) {
        nsx::error() << "No unit cell defined for the peaks";
        return;
    }

    std::sort(_peaks.begin(), _peaks.end(), [&](nsx::sptrPeak p1, nsx::sptrPeak p2) {
        nsx::MillerIndex miller_index1(p1->q(), *cell);
        nsx::MillerIndex miller_index2(p2->q(), *cell);
        return cell->spaceGroup().isEquivalent(miller_index1,miller_index2);
    });
}

void PeakListModel::setUnitCell(const nsx::sptrUnitCell& unitCell, QModelIndexList selectedPeaks)
{
    if (selectedPeaks.isEmpty()) {
        for (int i=0;i<rowCount(QModelIndex());++i) {
            selectedPeaks << index(i,0);
        }
    }
    for (auto&& index : selectedPeaks) {
        auto peak = _peaks[index.row()];
        peak->setUnitCell(unitCell);
    }
    emit layoutChanged();
    emit unitCellUpdated();
}

void PeakListModel::normalizeToMonitor(double factor)
{
    for (auto&& peak : _peaks) {
        double monitor = peak->data()->reader()->metadata().key<double>("monitor");
        peak->setScale(factor/monitor);
    }

    QModelIndex topleft_index = index(0,0);
    QModelIndex bottomright_index = index(rowCount(QModelIndex())-1,columnCount(QModelIndex())-1);

    emit dataChanged(topleft_index,bottomright_index);
}

QModelIndexList PeakListModel::unindexedPeaks()
{
    QModelIndexList list;

    for (int i=0; i<rowCount(QModelIndex()); ++i) {
        auto peak = _peaks[i];
        if (!peak->unitCell()) {
            list.append(index(i,0));
        }
    }
    return list;
}

QModelIndexList PeakListModel::selectedPeaks()
{
    QModelIndexList list;

    for (int i=0; i<rowCount(QModelIndex()); ++i) {
        auto peak = _peaks[i];
        if (peak->enabled()) {
            list.append(index(i,0));
        }
    }
    return list;
}

nsx::sptrExperiment PeakListModel::experiment()
{
    return _experiment;
}
