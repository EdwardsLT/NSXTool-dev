#ifndef DIALOGUNITCELLPARAMETERS_H
#define DIALOGUNITCELLPARAMETERS_H

#include <QDialog>

#include "Types.h"

namespace Ui
{
class DialogUnitCellParameters;
}

using SX::Crystal::sptrUnitCell;

class DialogUnitCellParameters : public QDialog
{
    Q_OBJECT

public:
    explicit DialogUnitCellParameters(sptrUnitCell unitCell, QWidget *parent=0);
    ~DialogUnitCellParameters();

public slots:

    void setUnitCellParameters();

private:
    Ui::DialogUnitCellParameters *ui;
    sptrUnitCell _unitCell;
};

#endif // DIALOGUNITCELLPARAMETERS_H
