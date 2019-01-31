#-------------------------------------------------
#
# Project created by QtCreator 2014-07-23T10:58:01
#
#-------------------------------------------------

QT += core gui printsupport opengl widgets

QMAKE_CXXFLAGS += -DNDEBUG -DEIGEN_FFTW_DEFAULT

win32: {
    LIBS += -lnsx
}
unix:!macx {
    CONFddIG += c++11dd

    QMAKE_CXXFLAGS += -std=c++0x -fopenmp
    QMAKE_LFLAGS += -fopenmp
    QMAKE_LFLAGS += "-Wl,-rpath,/home/lewisedwards/bin/nsxtool-dev/build/nsxlib"

    INCLUDEPATH += /usr/include\
/home/lewisedwards/bin/nsxtool-dev/externals/eigen3\
/usr/include/hdf5/serial\
/home/lewisedwards/.local/lib/python3.6/site-packages/numpy/core/include\
/home/lewisedwards/bin/nsxtool-dev/externals/c-blosc/blosc\
/usr/include\
/usr/include/x86_64-linux-gnu\
/usr/include\
/usr/local/include\
/home/lewisedwards/bin/nsxtool-dev/apps/nsxqt\
/home/lewisedwards/bin/nsxtool-dev/apps/nsxqt/blendfiles\
/home/lewisedwards/bin/nsxtool-dev/apps/nsxqt/delegates\
/home/lewisedwards/bin/nsxtool-dev/apps/nsxqt/dialogs\
/home/lewisedwards/bin/nsxtool-dev/apps/nsxqt/externals\
/home/lewisedwards/bin/nsxtool-dev/apps/nsxqt/frames\
/home/lewisedwards/bin/nsxtool-dev/apps/nsxqt/logger\
/home/lewisedwards/bin/nsxtool-dev/apps/nsxqt/menus\
/home/lewisedwards/bin/nsxtool-dev/apps/nsxqt/models\
/home/lewisedwards/bin/nsxtool-dev/apps/nsxqt/opengl\
/home/lewisedwards/bin/nsxtool-dev/apps/nsxqt/plot\
/home/lewisedwards/bin/nsxtool-dev/apps/nsxqt/resources\
/home/lewisedwards/bin/nsxtool-dev/apps/nsxqt/tree\
/home/lewisedwards/bin/nsxtool-dev/apps/nsxqt/ui\
/home/lewisedwards/bin/nsxtool-dev/apps/nsxqt/utils\
/home/lewisedwards/bin/nsxtool-dev/apps/nsxqt/views\
/home/lewisedwards/bin/nsxtool-dev/apps/nsxqt/widgets\
/home/lewisedwards/bin/nsxtool-dev/build/nsxlib/include

    LIBS += -L/home/lewisedwards/bin/nsxtool-dev/build/nsxlib -lnsx 

    LIBS += -lfftw3
}
macx {
    CONFIG += c++11

    QMAKE_CXXFLAGS += -std=c++11
    QMAKE_LFLAGS += "-Wl,-rpath,/home/lewisedwards/bin/nsxtool-dev/build/nsxlib"

    INCLUDEPATH += /usr/include\
/home/lewisedwards/bin/nsxtool-dev/externals/eigen3\
/usr/include/hdf5/serial\
/home/lewisedwards/.local/lib/python3.6/site-packages/numpy/core/include\
/home/lewisedwards/bin/nsxtool-dev/externals/c-blosc/blosc\
/usr/include\
/usr/include/x86_64-linux-gnu\
/usr/include\
/usr/local/include\
/home/lewisedwards/bin/nsxtool-dev/apps/nsxqt\
/home/lewisedwards/bin/nsxtool-dev/apps/nsxqt/blendfiles\
/home/lewisedwards/bin/nsxtool-dev/apps/nsxqt/delegates\
/home/lewisedwards/bin/nsxtool-dev/apps/nsxqt/dialogs\
/home/lewisedwards/bin/nsxtool-dev/apps/nsxqt/externals\
/home/lewisedwards/bin/nsxtool-dev/apps/nsxqt/frames\
/home/lewisedwards/bin/nsxtool-dev/apps/nsxqt/logger\
/home/lewisedwards/bin/nsxtool-dev/apps/nsxqt/menus\
/home/lewisedwards/bin/nsxtool-dev/apps/nsxqt/models\
/home/lewisedwards/bin/nsxtool-dev/apps/nsxqt/opengl\
/home/lewisedwards/bin/nsxtool-dev/apps/nsxqt/plot\
/home/lewisedwards/bin/nsxtool-dev/apps/nsxqt/resources\
/home/lewisedwards/bin/nsxtool-dev/apps/nsxqt/tree\
/home/lewisedwards/bin/nsxtool-dev/apps/nsxqt/ui\
/home/lewisedwards/bin/nsxtool-dev/apps/nsxqt/utils\
/home/lewisedwards/bin/nsxtool-dev/apps/nsxqt/views\
/home/lewisedwards/bin/nsxtool-dev/apps/nsxqt/widgets\
/home/lewisedwards/bin/nsxtool-dev/build/nsxlib/include

    LIBS += -L/home/lewisedwards/bin/nsxtool-dev/build/nsxlib -lnsx

    LIBS += -L/usr/local/opt/fftw/lib -lfftw3
    
    ICON = /home/lewisedwards/bin/nsxtool-dev/apps/nsxqt/resources/nsxtool.icns

}

TARGET = nsxqt

TEMPLATE = app

RESOURCES = /home/lewisedwards/bin/nsxtool-dev/apps/nsxqt/NSXQt.qrc

SOURCES = /home/lewisedwards/bin/nsxtool-dev/apps/nsxqt/ColorMap.cpp\
/home/lewisedwards/bin/nsxtool-dev/apps/nsxqt/ColorMapData.cpp\
/home/lewisedwards/bin/nsxtool-dev/apps/nsxqt/Main.cpp\
/home/lewisedwards/bin/nsxtool-dev/apps/nsxqt/MainWindow.cpp\
/home/lewisedwards/bin/nsxtool-dev/apps/nsxqt/NSXQtApp.cpp\
/home/lewisedwards/bin/nsxtool-dev/apps/nsxqt/NoteBook.cpp\
/home/lewisedwards/bin/nsxtool-dev/apps/nsxqt/delegates/DoubleItemDelegate.cpp\
/home/lewisedwards/bin/nsxtool-dev/apps/nsxqt/dialogs/DialogAbout.cpp\
/home/lewisedwards/bin/nsxtool-dev/apps/nsxqt/dialogs/DialogAbsorption.cpp\
/home/lewisedwards/bin/nsxtool-dev/apps/nsxqt/dialogs/DialogCalibrateDistance.cpp\
/home/lewisedwards/bin/nsxtool-dev/apps/nsxqt/dialogs/DialogExperiment.cpp\
/home/lewisedwards/bin/nsxtool-dev/apps/nsxqt/dialogs/DialogHDF5Converter.cpp\
/home/lewisedwards/bin/nsxtool-dev/apps/nsxqt/dialogs/DialogIntegrate.cpp\
/home/lewisedwards/bin/nsxtool-dev/apps/nsxqt/dialogs/DialogIsotopesDatabase.cpp\
/home/lewisedwards/bin/nsxtool-dev/apps/nsxqt/dialogs/DialogMCAbsorption.cpp\
/home/lewisedwards/bin/nsxtool-dev/apps/nsxqt/dialogs/DialogPeakFilter.cpp\
/home/lewisedwards/bin/nsxtool-dev/apps/nsxqt/dialogs/DialogPredictPeaks.cpp\
/home/lewisedwards/bin/nsxtool-dev/apps/nsxqt/dialogs/DialogRawData.cpp\
/home/lewisedwards/bin/nsxtool-dev/apps/nsxqt/dialogs/DialogShapeLibrary.cpp\
/home/lewisedwards/bin/nsxtool-dev/apps/nsxqt/dialogs/DialogSpaceGroup.cpp\
/home/lewisedwards/bin/nsxtool-dev/apps/nsxqt/dialogs/DialogTransformationMatrix.cpp\
/home/lewisedwards/bin/nsxtool-dev/apps/nsxqt/dialogs/DialogUnitCellParameters.cpp\
/home/lewisedwards/bin/nsxtool-dev/apps/nsxqt/externals/QCustomPlot.cpp\
/home/lewisedwards/bin/nsxtool-dev/apps/nsxqt/frames/FrameAutoIndexer.cpp\
/home/lewisedwards/bin/nsxtool-dev/apps/nsxqt/frames/FrameDetectorGlobalOffsets.cpp\
/home/lewisedwards/bin/nsxtool-dev/apps/nsxqt/frames/FrameInstrumentStates.cpp\
/home/lewisedwards/bin/nsxtool-dev/apps/nsxqt/frames/FramePeakFinder.cpp\
/home/lewisedwards/bin/nsxtool-dev/apps/nsxqt/frames/FrameRefiner.cpp\
/home/lewisedwards/bin/nsxtool-dev/apps/nsxqt/frames/FrameSampleGlobalOffsets.cpp\
/home/lewisedwards/bin/nsxtool-dev/apps/nsxqt/frames/FrameStatistics.cpp\
/home/lewisedwards/bin/nsxtool-dev/apps/nsxqt/frames/FrameUserDefinedUnitCellIndexer.cpp\
/home/lewisedwards/bin/nsxtool-dev/apps/nsxqt/frames/NSXQFrame.cpp\
/home/lewisedwards/bin/nsxtool-dev/apps/nsxqt/logger/QtStreamWrapper.cpp\
/home/lewisedwards/bin/nsxtool-dev/apps/nsxqt/menus/ActionManager.cpp\
/home/lewisedwards/bin/nsxtool-dev/apps/nsxqt/menus/DetectorMenu.cpp\
/home/lewisedwards/bin/nsxtool-dev/apps/nsxqt/models/CrystalFaceItem.cpp\
/home/lewisedwards/bin/nsxtool-dev/apps/nsxqt/models/CrystalNodeItem.cpp\
/home/lewisedwards/bin/nsxtool-dev/apps/nsxqt/models/CrystalScene.cpp\
/home/lewisedwards/bin/nsxtool-dev/apps/nsxqt/models/CutLineGraphicsItem.cpp\
/home/lewisedwards/bin/nsxtool-dev/apps/nsxqt/models/CutterGraphicsItem.cpp\
/home/lewisedwards/bin/nsxtool-dev/apps/nsxqt/models/DataItem.cpp\
/home/lewisedwards/bin/nsxtool-dev/apps/nsxqt/models/DetectorItem.cpp\
/home/lewisedwards/bin/nsxtool-dev/apps/nsxqt/models/DetectorSceneModel.cpp\
/home/lewisedwards/bin/nsxtool-dev/apps/nsxqt/models/DrawableGraphicsItem.cpp\
/home/lewisedwards/bin/nsxtool-dev/apps/nsxqt/models/ExperimentItem.cpp\
/home/lewisedwards/bin/nsxtool-dev/apps/nsxqt/models/HorizontalSliceGraphicsItem.cpp\
/home/lewisedwards/bin/nsxtool-dev/apps/nsxqt/models/InspectableTreeItem.cpp\
/home/lewisedwards/bin/nsxtool-dev/apps/nsxqt/models/InstrumentItem.cpp\
/home/lewisedwards/bin/nsxtool-dev/apps/nsxqt/models/LibraryItem.cpp\
/home/lewisedwards/bin/nsxtool-dev/apps/nsxqt/models/MaskGraphicsItem.cpp\
/home/lewisedwards/bin/nsxtool-dev/apps/nsxqt/models/NumorItem.cpp\
/home/lewisedwards/bin/nsxtool-dev/apps/nsxqt/models/PeakGraphicsItem.cpp\
/home/lewisedwards/bin/nsxtool-dev/apps/nsxqt/models/PeakListItem.cpp\
/home/lewisedwards/bin/nsxtool-dev/apps/nsxqt/models/PeakListModel.cpp\
/home/lewisedwards/bin/nsxtool-dev/apps/nsxqt/models/PeaksItem.cpp\
/home/lewisedwards/bin/nsxtool-dev/apps/nsxqt/models/PinItem.cpp\
/home/lewisedwards/bin/nsxtool-dev/apps/nsxqt/models/RulerItem.cpp\
/home/lewisedwards/bin/nsxtool-dev/apps/nsxqt/models/SXGraphicsItem.cpp\
/home/lewisedwards/bin/nsxtool-dev/apps/nsxqt/models/SampleItem.cpp\
/home/lewisedwards/bin/nsxtool-dev/apps/nsxqt/models/SampleShapeItem.cpp\
/home/lewisedwards/bin/nsxtool-dev/apps/nsxqt/models/SessionModel.cpp\
/home/lewisedwards/bin/nsxtool-dev/apps/nsxqt/models/SessionModelDelegate.cpp\
/home/lewisedwards/bin/nsxtool-dev/apps/nsxqt/models/SourceItem.cpp\
/home/lewisedwards/bin/nsxtool-dev/apps/nsxqt/models/TaskManagerModel.cpp\
/home/lewisedwards/bin/nsxtool-dev/apps/nsxqt/models/TaskManagerViewDelegate.cpp\
/home/lewisedwards/bin/nsxtool-dev/apps/nsxqt/models/TreeItem.cpp\
/home/lewisedwards/bin/nsxtool-dev/apps/nsxqt/models/UnitCellItem.cpp\
/home/lewisedwards/bin/nsxtool-dev/apps/nsxqt/models/UnitCellsItem.cpp\
/home/lewisedwards/bin/nsxtool-dev/apps/nsxqt/models/VerticalSliceGraphicsItem.cpp\
/home/lewisedwards/bin/nsxtool-dev/apps/nsxqt/opengl/GLActor.cpp\
/home/lewisedwards/bin/nsxtool-dev/apps/nsxqt/opengl/GLReciprocalLattice.cpp\
/home/lewisedwards/bin/nsxtool-dev/apps/nsxqt/opengl/GLScene.cpp\
/home/lewisedwards/bin/nsxtool-dev/apps/nsxqt/opengl/GLSphere.cpp\
/home/lewisedwards/bin/nsxtool-dev/apps/nsxqt/opengl/GLTrackball.cpp\
/home/lewisedwards/bin/nsxtool-dev/apps/nsxqt/opengl/GLWidget.cpp\
/home/lewisedwards/bin/nsxtool-dev/apps/nsxqt/plot/PeakPlot.cpp\
/home/lewisedwards/bin/nsxtool-dev/apps/nsxqt/plot/PlotterFactory.cpp\
/home/lewisedwards/bin/nsxtool-dev/apps/nsxqt/plot/SXPlot.cpp\
/home/lewisedwards/bin/nsxtool-dev/apps/nsxqt/plot/SimplePlot.cpp\
/home/lewisedwards/bin/nsxtool-dev/apps/nsxqt/tree/DetectorPropertyWidget.cpp\
/home/lewisedwards/bin/nsxtool-dev/apps/nsxqt/tree/EmptyPropertyWidget.cpp\
/home/lewisedwards/bin/nsxtool-dev/apps/nsxqt/tree/NumorPropertyWidget.cpp\
/home/lewisedwards/bin/nsxtool-dev/apps/nsxqt/tree/PeakListPropertyWidget.cpp\
/home/lewisedwards/bin/nsxtool-dev/apps/nsxqt/tree/PeaksPropertyWidget.cpp\
/home/lewisedwards/bin/nsxtool-dev/apps/nsxqt/tree/SamplePropertyWidget.cpp\
/home/lewisedwards/bin/nsxtool-dev/apps/nsxqt/tree/SampleShapePropertyWidget.cpp\
/home/lewisedwards/bin/nsxtool-dev/apps/nsxqt/tree/SourcePropertyWidget.cpp\
/home/lewisedwards/bin/nsxtool-dev/apps/nsxqt/tree/UnitCellPropertyWidget.cpp\
/home/lewisedwards/bin/nsxtool-dev/apps/nsxqt/utils/CustomEventFilters.cpp\
/home/lewisedwards/bin/nsxtool-dev/apps/nsxqt/utils/PeaksUtils.cpp\
/home/lewisedwards/bin/nsxtool-dev/apps/nsxqt/views/AbsorptionWidget.cpp\
/home/lewisedwards/bin/nsxtool-dev/apps/nsxqt/views/DetectorSceneView.cpp\
/home/lewisedwards/bin/nsxtool-dev/apps/nsxqt/views/PeakListView.cpp\
/home/lewisedwards/bin/nsxtool-dev/apps/nsxqt/views/ProgressView.cpp\
/home/lewisedwards/bin/nsxtool-dev/apps/nsxqt/views/SessionTreeView.cpp\
/home/lewisedwards/bin/nsxtool-dev/apps/nsxqt/views/TaskManagerView.cpp\
/home/lewisedwards/bin/nsxtool-dev/apps/nsxqt/widgets/CopyPasteTableView.cpp\
/home/lewisedwards/bin/nsxtool-dev/apps/nsxqt/widgets/ScientificNotationSpinBox.cpp\
/home/lewisedwards/bin/nsxtool-dev/apps/nsxqt/widgets/WidgetFoundPeaks.cpp\
/home/lewisedwards/bin/nsxtool-dev/apps/nsxqt/widgets/WidgetRefinerFit.cpp\
/home/lewisedwards/bin/nsxtool-dev/apps/nsxqt/widgets/WidgetUnitCell.cpp
          
HEADERS = /home/lewisedwards/bin/nsxtool-dev/apps/nsxqt/ColorMap.h\
/home/lewisedwards/bin/nsxtool-dev/apps/nsxqt/MainWindow.h\
/home/lewisedwards/bin/nsxtool-dev/apps/nsxqt/NSXQtApp.h\
/home/lewisedwards/bin/nsxtool-dev/apps/nsxqt/NoteBook.h\
/home/lewisedwards/bin/nsxtool-dev/apps/nsxqt/delegates/DoubleItemDelegate.h\
/home/lewisedwards/bin/nsxtool-dev/apps/nsxqt/dialogs/DialogAbout.h\
/home/lewisedwards/bin/nsxtool-dev/apps/nsxqt/dialogs/DialogAbsorption.h\
/home/lewisedwards/bin/nsxtool-dev/apps/nsxqt/dialogs/DialogCalibrateDistance.h\
/home/lewisedwards/bin/nsxtool-dev/apps/nsxqt/dialogs/DialogExperiment.h\
/home/lewisedwards/bin/nsxtool-dev/apps/nsxqt/dialogs/DialogHDF5Converter.h\
/home/lewisedwards/bin/nsxtool-dev/apps/nsxqt/dialogs/DialogIntegrate.h\
/home/lewisedwards/bin/nsxtool-dev/apps/nsxqt/dialogs/DialogIsotopesDatabase.h\
/home/lewisedwards/bin/nsxtool-dev/apps/nsxqt/dialogs/DialogMCAbsorption.h\
/home/lewisedwards/bin/nsxtool-dev/apps/nsxqt/dialogs/DialogPeakFilter.h\
/home/lewisedwards/bin/nsxtool-dev/apps/nsxqt/dialogs/DialogPredictPeaks.h\
/home/lewisedwards/bin/nsxtool-dev/apps/nsxqt/dialogs/DialogRawData.h\
/home/lewisedwards/bin/nsxtool-dev/apps/nsxqt/dialogs/DialogShapeLibrary.h\
/home/lewisedwards/bin/nsxtool-dev/apps/nsxqt/dialogs/DialogSpaceGroup.h\
/home/lewisedwards/bin/nsxtool-dev/apps/nsxqt/dialogs/DialogTransformationMatrix.h\
/home/lewisedwards/bin/nsxtool-dev/apps/nsxqt/dialogs/DialogUnitCellParameters.h\
/home/lewisedwards/bin/nsxtool-dev/apps/nsxqt/externals/QCustomPlot.h\
/home/lewisedwards/bin/nsxtool-dev/apps/nsxqt/frames/FrameAutoIndexer.h\
/home/lewisedwards/bin/nsxtool-dev/apps/nsxqt/frames/FrameDetectorGlobalOffsets.h\
/home/lewisedwards/bin/nsxtool-dev/apps/nsxqt/frames/FrameInstrumentStates.h\
/home/lewisedwards/bin/nsxtool-dev/apps/nsxqt/frames/FramePeakFinder.h\
/home/lewisedwards/bin/nsxtool-dev/apps/nsxqt/frames/FrameRefiner.h\
/home/lewisedwards/bin/nsxtool-dev/apps/nsxqt/frames/FrameSampleGlobalOffsets.h\
/home/lewisedwards/bin/nsxtool-dev/apps/nsxqt/frames/FrameStatistics.h\
/home/lewisedwards/bin/nsxtool-dev/apps/nsxqt/frames/FrameUserDefinedUnitCellIndexer.h\
/home/lewisedwards/bin/nsxtool-dev/apps/nsxqt/frames/NSXQFrame.h\
/home/lewisedwards/bin/nsxtool-dev/apps/nsxqt/logger/QtStreamWrapper.h\
/home/lewisedwards/bin/nsxtool-dev/apps/nsxqt/menus/ActionManager.h\
/home/lewisedwards/bin/nsxtool-dev/apps/nsxqt/menus/DetectorMenu.h\
/home/lewisedwards/bin/nsxtool-dev/apps/nsxqt/models/CrystalFaceItem.h\
/home/lewisedwards/bin/nsxtool-dev/apps/nsxqt/models/CrystalNodeItem.h\
/home/lewisedwards/bin/nsxtool-dev/apps/nsxqt/models/CrystalScene.h\
/home/lewisedwards/bin/nsxtool-dev/apps/nsxqt/models/CutLineGraphicsItem.h\
/home/lewisedwards/bin/nsxtool-dev/apps/nsxqt/models/CutterGraphicsItem.h\
/home/lewisedwards/bin/nsxtool-dev/apps/nsxqt/models/DataItem.h\
/home/lewisedwards/bin/nsxtool-dev/apps/nsxqt/models/DetectorItem.h\
/home/lewisedwards/bin/nsxtool-dev/apps/nsxqt/models/DetectorSceneModel.h\
/home/lewisedwards/bin/nsxtool-dev/apps/nsxqt/models/DrawableGraphicsItem.h\
/home/lewisedwards/bin/nsxtool-dev/apps/nsxqt/models/ExperimentItem.h\
/home/lewisedwards/bin/nsxtool-dev/apps/nsxqt/models/HorizontalSliceGraphicsItem.h\
/home/lewisedwards/bin/nsxtool-dev/apps/nsxqt/models/InspectableTreeItem.h\
/home/lewisedwards/bin/nsxtool-dev/apps/nsxqt/models/InstrumentItem.h\
/home/lewisedwards/bin/nsxtool-dev/apps/nsxqt/models/LibraryItem.h\
/home/lewisedwards/bin/nsxtool-dev/apps/nsxqt/models/MaskGraphicsItem.h\
/home/lewisedwards/bin/nsxtool-dev/apps/nsxqt/models/MetaTypes.h\
/home/lewisedwards/bin/nsxtool-dev/apps/nsxqt/models/NumorItem.h\
/home/lewisedwards/bin/nsxtool-dev/apps/nsxqt/models/PeakGraphicsItem.h\
/home/lewisedwards/bin/nsxtool-dev/apps/nsxqt/models/PeakListItem.h\
/home/lewisedwards/bin/nsxtool-dev/apps/nsxqt/models/PeakListModel.h\
/home/lewisedwards/bin/nsxtool-dev/apps/nsxqt/models/PeaksItem.h\
/home/lewisedwards/bin/nsxtool-dev/apps/nsxqt/models/PinItem.h\
/home/lewisedwards/bin/nsxtool-dev/apps/nsxqt/models/RulerItem.h\
/home/lewisedwards/bin/nsxtool-dev/apps/nsxqt/models/SXGraphicsItem.h\
/home/lewisedwards/bin/nsxtool-dev/apps/nsxqt/models/SampleItem.h\
/home/lewisedwards/bin/nsxtool-dev/apps/nsxqt/models/SampleShapeItem.h\
/home/lewisedwards/bin/nsxtool-dev/apps/nsxqt/models/SessionModel.h\
/home/lewisedwards/bin/nsxtool-dev/apps/nsxqt/models/SessionModelDelegate.h\
/home/lewisedwards/bin/nsxtool-dev/apps/nsxqt/models/SourceItem.h\
/home/lewisedwards/bin/nsxtool-dev/apps/nsxqt/models/TaskManagerModel.h\
/home/lewisedwards/bin/nsxtool-dev/apps/nsxqt/models/TaskManagerViewDelegate.h\
/home/lewisedwards/bin/nsxtool-dev/apps/nsxqt/models/TreeItem.h\
/home/lewisedwards/bin/nsxtool-dev/apps/nsxqt/models/UnitCellItem.h\
/home/lewisedwards/bin/nsxtool-dev/apps/nsxqt/models/UnitCellsItem.h\
/home/lewisedwards/bin/nsxtool-dev/apps/nsxqt/models/VerticalSliceGraphicsItem.h\
/home/lewisedwards/bin/nsxtool-dev/apps/nsxqt/opengl/GLActor.h\
/home/lewisedwards/bin/nsxtool-dev/apps/nsxqt/opengl/GLReciprocalLattice.h\
/home/lewisedwards/bin/nsxtool-dev/apps/nsxqt/opengl/GLScene.h\
/home/lewisedwards/bin/nsxtool-dev/apps/nsxqt/opengl/GLSphere.h\
/home/lewisedwards/bin/nsxtool-dev/apps/nsxqt/opengl/GLTrackball.h\
/home/lewisedwards/bin/nsxtool-dev/apps/nsxqt/opengl/GLWidget.h\
/home/lewisedwards/bin/nsxtool-dev/apps/nsxqt/plot/PeakPlot.h\
/home/lewisedwards/bin/nsxtool-dev/apps/nsxqt/plot/PlotterFactory.h\
/home/lewisedwards/bin/nsxtool-dev/apps/nsxqt/plot/SXPlot.h\
/home/lewisedwards/bin/nsxtool-dev/apps/nsxqt/plot/SimplePlot.h\
/home/lewisedwards/bin/nsxtool-dev/apps/nsxqt/tree/DetectorPropertyWidget.h\
/home/lewisedwards/bin/nsxtool-dev/apps/nsxqt/tree/EmptyPropertyWidget.h\
/home/lewisedwards/bin/nsxtool-dev/apps/nsxqt/tree/NumorPropertyWidget.h\
/home/lewisedwards/bin/nsxtool-dev/apps/nsxqt/tree/PeakListPropertyWidget.h\
/home/lewisedwards/bin/nsxtool-dev/apps/nsxqt/tree/PeaksPropertyWidget.h\
/home/lewisedwards/bin/nsxtool-dev/apps/nsxqt/tree/SamplePropertyWidget.h\
/home/lewisedwards/bin/nsxtool-dev/apps/nsxqt/tree/SampleShapePropertyWidget.h\
/home/lewisedwards/bin/nsxtool-dev/apps/nsxqt/tree/SourcePropertyWidget.h\
/home/lewisedwards/bin/nsxtool-dev/apps/nsxqt/tree/UnitCellPropertyWidget.h\
/home/lewisedwards/bin/nsxtool-dev/apps/nsxqt/utils/CustomEventFilters.h\
/home/lewisedwards/bin/nsxtool-dev/apps/nsxqt/utils/GlobalInfo.h\
/home/lewisedwards/bin/nsxtool-dev/apps/nsxqt/utils/PeaksUtils.h\
/home/lewisedwards/bin/nsxtool-dev/apps/nsxqt/views/AbsorptionWidget.h\
/home/lewisedwards/bin/nsxtool-dev/apps/nsxqt/views/DetectorSceneView.h\
/home/lewisedwards/bin/nsxtool-dev/apps/nsxqt/views/PeakListView.h\
/home/lewisedwards/bin/nsxtool-dev/apps/nsxqt/views/ProgressView.h\
/home/lewisedwards/bin/nsxtool-dev/apps/nsxqt/views/SessionTreeView.h\
/home/lewisedwards/bin/nsxtool-dev/apps/nsxqt/views/TaskManagerView.h\
/home/lewisedwards/bin/nsxtool-dev/apps/nsxqt/widgets/CopyPasteTableView.h\
/home/lewisedwards/bin/nsxtool-dev/apps/nsxqt/widgets/ScientificNotationSpinBox.h\
/home/lewisedwards/bin/nsxtool-dev/apps/nsxqt/widgets/WidgetFoundPeaks.h\
/home/lewisedwards/bin/nsxtool-dev/apps/nsxqt/widgets/WidgetRefinerFit.h\
/home/lewisedwards/bin/nsxtool-dev/apps/nsxqt/widgets/WidgetUnitCell.h

FORMS = /home/lewisedwards/bin/nsxtool-dev/apps/nsxqt/ui/AbsorptionWidget.ui\
/home/lewisedwards/bin/nsxtool-dev/apps/nsxqt/ui/DetectorPropertyWidget.ui\
/home/lewisedwards/bin/nsxtool-dev/apps/nsxqt/ui/DialogAbsorption.ui\
/home/lewisedwards/bin/nsxtool-dev/apps/nsxqt/ui/DialogCalibrateDistance.ui\
/home/lewisedwards/bin/nsxtool-dev/apps/nsxqt/ui/DialogExperiment.ui\
/home/lewisedwards/bin/nsxtool-dev/apps/nsxqt/ui/DialogHDF5Converter.ui\
/home/lewisedwards/bin/nsxtool-dev/apps/nsxqt/ui/DialogIntegrate.ui\
/home/lewisedwards/bin/nsxtool-dev/apps/nsxqt/ui/DialogIsotopesDatabase.ui\
/home/lewisedwards/bin/nsxtool-dev/apps/nsxqt/ui/DialogMCAbsorption.ui\
/home/lewisedwards/bin/nsxtool-dev/apps/nsxqt/ui/DialogPeakFilter.ui\
/home/lewisedwards/bin/nsxtool-dev/apps/nsxqt/ui/DialogPredictPeaks.ui\
/home/lewisedwards/bin/nsxtool-dev/apps/nsxqt/ui/DialogRawData.ui\
/home/lewisedwards/bin/nsxtool-dev/apps/nsxqt/ui/DialogShapeLibrary.ui\
/home/lewisedwards/bin/nsxtool-dev/apps/nsxqt/ui/DialogSpaceGroup.ui\
/home/lewisedwards/bin/nsxtool-dev/apps/nsxqt/ui/DialogTransformationMatrix.ui\
/home/lewisedwards/bin/nsxtool-dev/apps/nsxqt/ui/DialogUnitCellParameters.ui\
/home/lewisedwards/bin/nsxtool-dev/apps/nsxqt/ui/EmptyPropertyWidget.ui\
/home/lewisedwards/bin/nsxtool-dev/apps/nsxqt/ui/FrameAutoIndexer.ui\
/home/lewisedwards/bin/nsxtool-dev/apps/nsxqt/ui/FrameDetectorGlobalOffsets.ui\
/home/lewisedwards/bin/nsxtool-dev/apps/nsxqt/ui/FrameInstrumentStates.ui\
/home/lewisedwards/bin/nsxtool-dev/apps/nsxqt/ui/FramePeakFinder.ui\
/home/lewisedwards/bin/nsxtool-dev/apps/nsxqt/ui/FrameRefiner.ui\
/home/lewisedwards/bin/nsxtool-dev/apps/nsxqt/ui/FrameSampleGlobalOffsets.ui\
/home/lewisedwards/bin/nsxtool-dev/apps/nsxqt/ui/FrameStatistics.ui\
/home/lewisedwards/bin/nsxtool-dev/apps/nsxqt/ui/FrameUserDefinedUnitCellIndexer.ui\
/home/lewisedwards/bin/nsxtool-dev/apps/nsxqt/ui/NumorPropertyWidget.ui\
/home/lewisedwards/bin/nsxtool-dev/apps/nsxqt/ui/PeakFilterDialog.ui\
/home/lewisedwards/bin/nsxtool-dev/apps/nsxqt/ui/PeakListPropertyWidget.ui\
/home/lewisedwards/bin/nsxtool-dev/apps/nsxqt/ui/PeaksPropertyWidget.ui\
/home/lewisedwards/bin/nsxtool-dev/apps/nsxqt/ui/ReciprocalSpaceViewer.ui\
/home/lewisedwards/bin/nsxtool-dev/apps/nsxqt/ui/SamplePropertyWidget.ui\
/home/lewisedwards/bin/nsxtool-dev/apps/nsxqt/ui/SampleShapePropertyWidget.ui\
/home/lewisedwards/bin/nsxtool-dev/apps/nsxqt/ui/SourcePropertyWidget.ui\
/home/lewisedwards/bin/nsxtool-dev/apps/nsxqt/ui/UnitCellPropertyWidget.ui\
/home/lewisedwards/bin/nsxtool-dev/apps/nsxqt/ui/WidgetFoundPeaks.ui\
/home/lewisedwards/bin/nsxtool-dev/apps/nsxqt/ui/WidgetRefinerFit.ui\
/home/lewisedwards/bin/nsxtool-dev/apps/nsxqt/ui/WidgetUnitCell.ui
          
    
