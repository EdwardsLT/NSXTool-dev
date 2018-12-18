#pragma once

#include <string>

#include "QCustomPlot.h"

class SXPlot : public QCustomPlot
{
    Q_OBJECT
public:

    static SXPlot* create(QWidget* parent);

    explicit SXPlot(QWidget *parent = 0);

    void keyPressEvent(QKeyEvent *);

    virtual ~SXPlot();

    virtual std::string getType() const;

public slots:

    //
    void mousePress();

    //
    void mouseWheel();

    void titleDoubleClick(QMouseEvent *event, QCPPlotTitle *title);

    // Double click on the legend
    void legendDoubleClick(QCPLegend *legend, QCPAbstractLegendItem *item);

    // Context menu
    void setmenuRequested(QPoint);

    // Export the graphs into column ASCII format
    void exportToAscii();

private:

    void copyViewToClipboard();

};
