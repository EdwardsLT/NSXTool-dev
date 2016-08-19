#ifndef SIMPLEPLOT_H
#define SIMPLEPLOT_H

#include <string>

#include "SXPlot.h"

class QWidget;

class SimplePlot : public SXPlot
{
    Q_OBJECT
public:

    static SXPlot* create(QWidget* parent);

    explicit SimplePlot(QWidget *parent = 0);

    // Getters and setters
    std::string getType() const;

};

#endif // SIMPLEPLOT_H