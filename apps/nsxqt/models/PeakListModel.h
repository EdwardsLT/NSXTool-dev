#pragma once

#include <memory>
#include <string>
#include <vector>

#include <QAbstractTableModel>
#include <QModelIndexList>

#include <nsxlib/CrystalTypes.h>
#include <nsxlib/DataTypes.h>
#include <nsxlib/InstrumentTypes.h>

class QObject;

class SessionModel;

QString PeakListModelColumnToString(int column);

class PeakListModel : public QAbstractTableModel
{
    Q_OBJECT
public:

    enum Column {H,K,L,PixelX,PixelY,Frame,Gamma,Nu,TwoTheta,DSpacing,LorentzFactor,Intensity,SigmaIntensity,DataSet,UnitCell,Status,Count};

    PeakListModel(SessionModel* session_model, nsx::sptrExperiment experiment, const nsx::PeakList& peaks, QObject *parent=nullptr);

    PeakListModel(SessionModel* session_model, nsx::sptrExperiment experiment,QObject* parent=nullptr);

    virtual int rowCount(const QModelIndex& parent) const override;

    virtual int columnCount(const QModelIndex& parent) const override;

    void reset();

    QVariant data(const QModelIndex &index, int role) const override;

    Qt::ItemFlags flags(const QModelIndex &index) const override;

    QVariant headerData(int section, Qt::Orientation orientation, int role) const override;

    void setPeaks(const nsx::PeakList& peaks);

    const nsx::PeakList& peaks() const;

    bool indexIsValid(const QModelIndex& index) const;

    void sort(int column, Qt::SortOrder order) override;

    void normalizeToMonitor(double factor);

    QModelIndexList unindexedPeaks();

    QModelIndexList selectedPeaks();

    nsx::sptrExperiment experiment();

    void selectPeak(const QModelIndex& index);

    void togglePeakSelection(QModelIndex peak_index);

public slots:

    void slotChangeEnabledPeak(nsx::sptrPeak peak);

    void slotChangeMaskedPeaks(nsx::sptrDataSet data);

    void slotRemoveUnitCell(const nsx::sptrUnitCell unit_cell);

    void setUnitCell(const nsx::sptrUnitCell& unitCell, QModelIndexList selectedPeaks=QModelIndexList());

    void sortEquivalents();

signals:

    void unitCellUpdated();

private:

    SessionModel* _session_model;

    nsx::sptrExperiment _experiment;

    nsx::PeakList _peaks;
};
