#pragma once

#include <Eigen/Dense>

#include <QDialog>

#include <nsxlib/CrystalTypes.h>

namespace Ui {
class DialogTransformationmatrix;
}

class Widget;

class DialogTransformationmatrix : public QDialog
{
    Q_OBJECT

signals:
    void getMatrix(const Eigen::Matrix3d& m);

public:
    explicit DialogTransformationmatrix(nsx::sptrUnitCell unitCell, QWidget *parent=0);
    ~DialogTransformationmatrix();

public slots:
    void getTransformation();

private:
    Ui::DialogTransformationmatrix *ui;
    nsx::sptrUnitCell _unitCell;
};
