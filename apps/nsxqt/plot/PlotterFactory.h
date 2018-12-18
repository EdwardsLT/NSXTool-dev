#pragma once

#include <functional>
#include <map>
#include <string>

class QWidget;
class SXPlot;

class PlotterFactory{

public:

    PlotterFactory();

    SXPlot* create(const std::string& plotter_type, QWidget *parent) const;

private:

    std::map<std::string,std::function<SXPlot*(QWidget*)>> _callbacks;
};
