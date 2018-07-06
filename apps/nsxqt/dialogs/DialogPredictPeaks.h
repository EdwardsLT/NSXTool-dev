#pragma once

#include <QDialog>
#include <set>

#include <nsxlib/CrystalTypes.h>

namespace Ui {
class DialogPredictPeaks;
}

class DialogPredictPeaks : public QDialog
{
    Q_OBJECT

public:
    explicit DialogPredictPeaks(const std::set<nsx::sptrUnitCell>& cells, QWidget *parent = 0);
    ~DialogPredictPeaks();

    double dMin();
    double dMax();
    double radius();
    double nframes();

    int minNeighbors();

    nsx::sptrUnitCell cell(); 

private:
    Ui::DialogPredictPeaks *ui;
    std::set<nsx::sptrUnitCell> _cells;
};
