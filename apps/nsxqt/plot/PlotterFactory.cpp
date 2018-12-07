#include <stdexcept>

#include "PeakPlot.h"
#include "PlotterFactory.h"
#include "SimplePlot.h"
#include "SXPlot.h"

template <typename T>
SXPlot* create_plotter(QWidget *parent)
{
    return new T(parent);
}

PlotterFactory::PlotterFactory() : _callbacks()
{
    _callbacks["simple"] = &create_plotter<SimplePlot>;
    _callbacks["peak"] = &create_plotter<PeakPlot>;
}

SXPlot* PlotterFactory::create(const std::string& plotter_type, QWidget *parent) const
{
    const auto it = _callbacks.find(plotter_type);

    // could not find key
    if (it == _callbacks.end()) {
        throw std::runtime_error("Unknown plotter type.");
    }

    return (it->second)(parent);
}
