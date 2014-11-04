#-------------------------------------------------
#
# Project created by QtCreator 2014-07-23T10:58:01
#
#-------------------------------------------------

QT       += core widgets printsupport opengl
CONFIG   += debug_and_release
QMAKE_CXXFLAGS += -std=c++0x -fopenmp -DNDEBUG -DEIGEN_FFTW_DEFAULT
QMAKE_LFLAGS += -fopenmp
TARGET = nsxtool
TEMPLATE = app

RESOURCES = NSXQt.qrc \

SOURCES += src/Main.cpp \
    src/MainWindow.cpp \
    src/Data.cpp \
    src/DetectorView.cpp \
    src/ColorMap.cpp \
    externals/src/qcustomplot.cpp \
    src/Plotter1D.cpp \
    src/PeakPlotter.cpp \
    src/SliceRect.cpp \
    src/PeakTableView.cpp \
    src/DialogTransformationMatrix.cpp \
    src/DialogUnitCell.cpp \
    src/NoteBook.cpp \
    src/Logger.cpp \
    src/DialogUnitCellSolutions.cpp \
    src/ExperimentDialog.cpp

HEADERS  += include/MainWindow.h \
    include/DetectorView.h \
    include/DialogPeakFind.h \
    include/Data.h \
    include/ColorMap.h \
    externals/include/qcustomplot.h \
    include/Plotter1D.h \
    include/PeakPlotter.h \
    include/SliceRect.h \
    include/PeakTableView.h \
    include/DialogUnitCell.h \
    include/DialogTransformationMatrix.h \
    include/NoteBook.h \
    include/Logger.h \
    include/DialogUnitCellSolutions.h \
    include/ExperimentDialog.h

FORMS    += ui/mainwindow.ui \
    ui/dialog_PeakFind.ui \
    ui/plotter1d.ui \
    ui/peakplotter.ui \
    ui/dialog_UnitCell.ui \
    ui/dialogtransformationmatrix.ui \
    dialogunitcellsolutions.ui \
    ui/ExperimentDialog.ui

win32:CONFIG(release, debug|release): LIBS += -lNSXTool
else:unix: LIBS += -lNSXTool -lboost_date_time -lfftw3

INCLUDEPATH += $$PWD include externals/include

