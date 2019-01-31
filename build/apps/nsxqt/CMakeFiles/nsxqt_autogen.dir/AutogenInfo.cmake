# Meta
set(AM_MULTI_CONFIG "SINGLE")
# Directories and files
set(AM_CMAKE_BINARY_DIR "/home/lewisedwards/bin/nsxtool-dev/build/")
set(AM_CMAKE_SOURCE_DIR "/home/lewisedwards/bin/nsxtool-dev/")
set(AM_CMAKE_CURRENT_SOURCE_DIR "/home/lewisedwards/bin/nsxtool-dev/apps/nsxqt/")
set(AM_CMAKE_CURRENT_BINARY_DIR "/home/lewisedwards/bin/nsxtool-dev/build/apps/nsxqt/")
set(AM_CMAKE_INCLUDE_DIRECTORIES_PROJECT_BEFORE "")
set(AM_BUILD_DIR "/home/lewisedwards/bin/nsxtool-dev/build/apps/nsxqt/nsxqt_autogen")
set(AM_SOURCES "/home/lewisedwards/bin/nsxtool-dev/apps/nsxqt/ColorMap.cpp;/home/lewisedwards/bin/nsxtool-dev/apps/nsxqt/ColorMapData.cpp;/home/lewisedwards/bin/nsxtool-dev/apps/nsxqt/Main.cpp;/home/lewisedwards/bin/nsxtool-dev/apps/nsxqt/MainWindow.cpp;/home/lewisedwards/bin/nsxtool-dev/apps/nsxqt/NSXQtApp.cpp;/home/lewisedwards/bin/nsxtool-dev/apps/nsxqt/NoteBook.cpp;/home/lewisedwards/bin/nsxtool-dev/apps/nsxqt/delegates/DoubleItemDelegate.cpp;/home/lewisedwards/bin/nsxtool-dev/apps/nsxqt/dialogs/DialogAbout.cpp;/home/lewisedwards/bin/nsxtool-dev/apps/nsxqt/dialogs/DialogAbsorption.cpp;/home/lewisedwards/bin/nsxtool-dev/apps/nsxqt/dialogs/DialogCalibrateDistance.cpp;/home/lewisedwards/bin/nsxtool-dev/apps/nsxqt/dialogs/DialogExperiment.cpp;/home/lewisedwards/bin/nsxtool-dev/apps/nsxqt/dialogs/DialogHDF5Converter.cpp;/home/lewisedwards/bin/nsxtool-dev/apps/nsxqt/dialogs/DialogIntegrate.cpp;/home/lewisedwards/bin/nsxtool-dev/apps/nsxqt/dialogs/DialogIsotopesDatabase.cpp;/home/lewisedwards/bin/nsxtool-dev/apps/nsxqt/dialogs/DialogMCAbsorption.cpp;/home/lewisedwards/bin/nsxtool-dev/apps/nsxqt/dialogs/DialogPeakFilter.cpp;/home/lewisedwards/bin/nsxtool-dev/apps/nsxqt/dialogs/DialogPredictPeaks.cpp;/home/lewisedwards/bin/nsxtool-dev/apps/nsxqt/dialogs/DialogRawData.cpp;/home/lewisedwards/bin/nsxtool-dev/apps/nsxqt/dialogs/DialogShapeLibrary.cpp;/home/lewisedwards/bin/nsxtool-dev/apps/nsxqt/dialogs/DialogSpaceGroup.cpp;/home/lewisedwards/bin/nsxtool-dev/apps/nsxqt/dialogs/DialogTransformationMatrix.cpp;/home/lewisedwards/bin/nsxtool-dev/apps/nsxqt/dialogs/DialogUnitCellParameters.cpp;/home/lewisedwards/bin/nsxtool-dev/apps/nsxqt/externals/QCustomPlot.cpp;/home/lewisedwards/bin/nsxtool-dev/apps/nsxqt/frames/FrameAutoIndexer.cpp;/home/lewisedwards/bin/nsxtool-dev/apps/nsxqt/frames/FrameDetectorGlobalOffsets.cpp;/home/lewisedwards/bin/nsxtool-dev/apps/nsxqt/frames/FrameInstrumentStates.cpp;/home/lewisedwards/bin/nsxtool-dev/apps/nsxqt/frames/FramePeakFinder.cpp;/home/lewisedwards/bin/nsxtool-dev/apps/nsxqt/frames/FrameRefiner.cpp;/home/lewisedwards/bin/nsxtool-dev/apps/nsxqt/frames/FrameSampleGlobalOffsets.cpp;/home/lewisedwards/bin/nsxtool-dev/apps/nsxqt/frames/FrameStatistics.cpp;/home/lewisedwards/bin/nsxtool-dev/apps/nsxqt/frames/FrameUserDefinedUnitCellIndexer.cpp;/home/lewisedwards/bin/nsxtool-dev/apps/nsxqt/frames/NSXQFrame.cpp;/home/lewisedwards/bin/nsxtool-dev/apps/nsxqt/logger/QtStreamWrapper.cpp;/home/lewisedwards/bin/nsxtool-dev/apps/nsxqt/menus/ActionManager.cpp;/home/lewisedwards/bin/nsxtool-dev/apps/nsxqt/menus/DetectorMenu.cpp;/home/lewisedwards/bin/nsxtool-dev/apps/nsxqt/models/CrystalFaceItem.cpp;/home/lewisedwards/bin/nsxtool-dev/apps/nsxqt/models/CrystalNodeItem.cpp;/home/lewisedwards/bin/nsxtool-dev/apps/nsxqt/models/CrystalScene.cpp;/home/lewisedwards/bin/nsxtool-dev/apps/nsxqt/models/CutLineGraphicsItem.cpp;/home/lewisedwards/bin/nsxtool-dev/apps/nsxqt/models/CutterGraphicsItem.cpp;/home/lewisedwards/bin/nsxtool-dev/apps/nsxqt/models/DataItem.cpp;/home/lewisedwards/bin/nsxtool-dev/apps/nsxqt/models/DetectorItem.cpp;/home/lewisedwards/bin/nsxtool-dev/apps/nsxqt/models/DetectorSceneModel.cpp;/home/lewisedwards/bin/nsxtool-dev/apps/nsxqt/models/DrawableGraphicsItem.cpp;/home/lewisedwards/bin/nsxtool-dev/apps/nsxqt/models/ExperimentItem.cpp;/home/lewisedwards/bin/nsxtool-dev/apps/nsxqt/models/HorizontalSliceGraphicsItem.cpp;/home/lewisedwards/bin/nsxtool-dev/apps/nsxqt/models/InspectableTreeItem.cpp;/home/lewisedwards/bin/nsxtool-dev/apps/nsxqt/models/InstrumentItem.cpp;/home/lewisedwards/bin/nsxtool-dev/apps/nsxqt/models/LibraryItem.cpp;/home/lewisedwards/bin/nsxtool-dev/apps/nsxqt/models/MaskGraphicsItem.cpp;/home/lewisedwards/bin/nsxtool-dev/apps/nsxqt/models/NumorItem.cpp;/home/lewisedwards/bin/nsxtool-dev/apps/nsxqt/models/PeakGraphicsItem.cpp;/home/lewisedwards/bin/nsxtool-dev/apps/nsxqt/models/PeakListItem.cpp;/home/lewisedwards/bin/nsxtool-dev/apps/nsxqt/models/PeakListModel.cpp;/home/lewisedwards/bin/nsxtool-dev/apps/nsxqt/models/PeaksItem.cpp;/home/lewisedwards/bin/nsxtool-dev/apps/nsxqt/models/PinItem.cpp;/home/lewisedwards/bin/nsxtool-dev/apps/nsxqt/models/RulerItem.cpp;/home/lewisedwards/bin/nsxtool-dev/apps/nsxqt/models/SXGraphicsItem.cpp;/home/lewisedwards/bin/nsxtool-dev/apps/nsxqt/models/SampleItem.cpp;/home/lewisedwards/bin/nsxtool-dev/apps/nsxqt/models/SampleShapeItem.cpp;/home/lewisedwards/bin/nsxtool-dev/apps/nsxqt/models/SessionModel.cpp;/home/lewisedwards/bin/nsxtool-dev/apps/nsxqt/models/SessionModelDelegate.cpp;/home/lewisedwards/bin/nsxtool-dev/apps/nsxqt/models/SourceItem.cpp;/home/lewisedwards/bin/nsxtool-dev/apps/nsxqt/models/TaskManagerModel.cpp;/home/lewisedwards/bin/nsxtool-dev/apps/nsxqt/models/TaskManagerViewDelegate.cpp;/home/lewisedwards/bin/nsxtool-dev/apps/nsxqt/models/TreeItem.cpp;/home/lewisedwards/bin/nsxtool-dev/apps/nsxqt/models/UnitCellItem.cpp;/home/lewisedwards/bin/nsxtool-dev/apps/nsxqt/models/UnitCellsItem.cpp;/home/lewisedwards/bin/nsxtool-dev/apps/nsxqt/models/VerticalSliceGraphicsItem.cpp;/home/lewisedwards/bin/nsxtool-dev/apps/nsxqt/opengl/GLActor.cpp;/home/lewisedwards/bin/nsxtool-dev/apps/nsxqt/opengl/GLReciprocalLattice.cpp;/home/lewisedwards/bin/nsxtool-dev/apps/nsxqt/opengl/GLScene.cpp;/home/lewisedwards/bin/nsxtool-dev/apps/nsxqt/opengl/GLSphere.cpp;/home/lewisedwards/bin/nsxtool-dev/apps/nsxqt/opengl/GLTrackball.cpp;/home/lewisedwards/bin/nsxtool-dev/apps/nsxqt/opengl/GLWidget.cpp;/home/lewisedwards/bin/nsxtool-dev/apps/nsxqt/plot/PeakPlot.cpp;/home/lewisedwards/bin/nsxtool-dev/apps/nsxqt/plot/PlotterFactory.cpp;/home/lewisedwards/bin/nsxtool-dev/apps/nsxqt/plot/SXPlot.cpp;/home/lewisedwards/bin/nsxtool-dev/apps/nsxqt/plot/SimplePlot.cpp;/home/lewisedwards/bin/nsxtool-dev/apps/nsxqt/tree/DetectorPropertyWidget.cpp;/home/lewisedwards/bin/nsxtool-dev/apps/nsxqt/tree/EmptyPropertyWidget.cpp;/home/lewisedwards/bin/nsxtool-dev/apps/nsxqt/tree/NumorPropertyWidget.cpp;/home/lewisedwards/bin/nsxtool-dev/apps/nsxqt/tree/PeakListPropertyWidget.cpp;/home/lewisedwards/bin/nsxtool-dev/apps/nsxqt/tree/PeaksPropertyWidget.cpp;/home/lewisedwards/bin/nsxtool-dev/apps/nsxqt/tree/SamplePropertyWidget.cpp;/home/lewisedwards/bin/nsxtool-dev/apps/nsxqt/tree/SampleShapePropertyWidget.cpp;/home/lewisedwards/bin/nsxtool-dev/apps/nsxqt/tree/SourcePropertyWidget.cpp;/home/lewisedwards/bin/nsxtool-dev/apps/nsxqt/tree/UnitCellPropertyWidget.cpp;/home/lewisedwards/bin/nsxtool-dev/apps/nsxqt/utils/CustomEventFilters.cpp;/home/lewisedwards/bin/nsxtool-dev/apps/nsxqt/utils/PeaksUtils.cpp;/home/lewisedwards/bin/nsxtool-dev/apps/nsxqt/views/AbsorptionWidget.cpp;/home/lewisedwards/bin/nsxtool-dev/apps/nsxqt/views/DetectorSceneView.cpp;/home/lewisedwards/bin/nsxtool-dev/apps/nsxqt/views/PeakListView.cpp;/home/lewisedwards/bin/nsxtool-dev/apps/nsxqt/views/ProgressView.cpp;/home/lewisedwards/bin/nsxtool-dev/apps/nsxqt/views/SessionTreeView.cpp;/home/lewisedwards/bin/nsxtool-dev/apps/nsxqt/views/TaskManagerView.cpp;/home/lewisedwards/bin/nsxtool-dev/apps/nsxqt/widgets/CopyPasteTableView.cpp;/home/lewisedwards/bin/nsxtool-dev/apps/nsxqt/widgets/ScientificNotationSpinBox.cpp;/home/lewisedwards/bin/nsxtool-dev/apps/nsxqt/widgets/WidgetFoundPeaks.cpp;/home/lewisedwards/bin/nsxtool-dev/apps/nsxqt/widgets/WidgetRefinerFit.cpp;/home/lewisedwards/bin/nsxtool-dev/apps/nsxqt/widgets/WidgetUnitCell.cpp")
set(AM_HEADERS "/home/lewisedwards/bin/nsxtool-dev/apps/nsxqt/ColorMap.h;/home/lewisedwards/bin/nsxtool-dev/apps/nsxqt/MainWindow.h;/home/lewisedwards/bin/nsxtool-dev/apps/nsxqt/NSXQtApp.h;/home/lewisedwards/bin/nsxtool-dev/apps/nsxqt/NoteBook.h;/home/lewisedwards/bin/nsxtool-dev/apps/nsxqt/delegates/DoubleItemDelegate.h;/home/lewisedwards/bin/nsxtool-dev/apps/nsxqt/dialogs/DialogAbout.h;/home/lewisedwards/bin/nsxtool-dev/apps/nsxqt/dialogs/DialogAbsorption.h;/home/lewisedwards/bin/nsxtool-dev/apps/nsxqt/dialogs/DialogCalibrateDistance.h;/home/lewisedwards/bin/nsxtool-dev/apps/nsxqt/dialogs/DialogExperiment.h;/home/lewisedwards/bin/nsxtool-dev/apps/nsxqt/dialogs/DialogHDF5Converter.h;/home/lewisedwards/bin/nsxtool-dev/apps/nsxqt/dialogs/DialogIntegrate.h;/home/lewisedwards/bin/nsxtool-dev/apps/nsxqt/dialogs/DialogIsotopesDatabase.h;/home/lewisedwards/bin/nsxtool-dev/apps/nsxqt/dialogs/DialogMCAbsorption.h;/home/lewisedwards/bin/nsxtool-dev/apps/nsxqt/dialogs/DialogPeakFilter.h;/home/lewisedwards/bin/nsxtool-dev/apps/nsxqt/dialogs/DialogPredictPeaks.h;/home/lewisedwards/bin/nsxtool-dev/apps/nsxqt/dialogs/DialogRawData.h;/home/lewisedwards/bin/nsxtool-dev/apps/nsxqt/dialogs/DialogShapeLibrary.h;/home/lewisedwards/bin/nsxtool-dev/apps/nsxqt/dialogs/DialogSpaceGroup.h;/home/lewisedwards/bin/nsxtool-dev/apps/nsxqt/dialogs/DialogTransformationMatrix.h;/home/lewisedwards/bin/nsxtool-dev/apps/nsxqt/dialogs/DialogUnitCellParameters.h;/home/lewisedwards/bin/nsxtool-dev/apps/nsxqt/externals/QCustomPlot.h;/home/lewisedwards/bin/nsxtool-dev/apps/nsxqt/frames/FrameAutoIndexer.h;/home/lewisedwards/bin/nsxtool-dev/apps/nsxqt/frames/FrameDetectorGlobalOffsets.h;/home/lewisedwards/bin/nsxtool-dev/apps/nsxqt/frames/FrameInstrumentStates.h;/home/lewisedwards/bin/nsxtool-dev/apps/nsxqt/frames/FramePeakFinder.h;/home/lewisedwards/bin/nsxtool-dev/apps/nsxqt/frames/FrameRefiner.h;/home/lewisedwards/bin/nsxtool-dev/apps/nsxqt/frames/FrameSampleGlobalOffsets.h;/home/lewisedwards/bin/nsxtool-dev/apps/nsxqt/frames/FrameStatistics.h;/home/lewisedwards/bin/nsxtool-dev/apps/nsxqt/frames/FrameUserDefinedUnitCellIndexer.h;/home/lewisedwards/bin/nsxtool-dev/apps/nsxqt/frames/NSXQFrame.h;/home/lewisedwards/bin/nsxtool-dev/apps/nsxqt/logger/QtStreamWrapper.h;/home/lewisedwards/bin/nsxtool-dev/apps/nsxqt/menus/ActionManager.h;/home/lewisedwards/bin/nsxtool-dev/apps/nsxqt/menus/DetectorMenu.h;/home/lewisedwards/bin/nsxtool-dev/apps/nsxqt/models/CrystalFaceItem.h;/home/lewisedwards/bin/nsxtool-dev/apps/nsxqt/models/CrystalNodeItem.h;/home/lewisedwards/bin/nsxtool-dev/apps/nsxqt/models/CrystalScene.h;/home/lewisedwards/bin/nsxtool-dev/apps/nsxqt/models/CutLineGraphicsItem.h;/home/lewisedwards/bin/nsxtool-dev/apps/nsxqt/models/CutterGraphicsItem.h;/home/lewisedwards/bin/nsxtool-dev/apps/nsxqt/models/DataItem.h;/home/lewisedwards/bin/nsxtool-dev/apps/nsxqt/models/DetectorItem.h;/home/lewisedwards/bin/nsxtool-dev/apps/nsxqt/models/DetectorSceneModel.h;/home/lewisedwards/bin/nsxtool-dev/apps/nsxqt/models/DrawableGraphicsItem.h;/home/lewisedwards/bin/nsxtool-dev/apps/nsxqt/models/ExperimentItem.h;/home/lewisedwards/bin/nsxtool-dev/apps/nsxqt/models/HorizontalSliceGraphicsItem.h;/home/lewisedwards/bin/nsxtool-dev/apps/nsxqt/models/InspectableTreeItem.h;/home/lewisedwards/bin/nsxtool-dev/apps/nsxqt/models/InstrumentItem.h;/home/lewisedwards/bin/nsxtool-dev/apps/nsxqt/models/LibraryItem.h;/home/lewisedwards/bin/nsxtool-dev/apps/nsxqt/models/MaskGraphicsItem.h;/home/lewisedwards/bin/nsxtool-dev/apps/nsxqt/models/MetaTypes.h;/home/lewisedwards/bin/nsxtool-dev/apps/nsxqt/models/NumorItem.h;/home/lewisedwards/bin/nsxtool-dev/apps/nsxqt/models/PeakGraphicsItem.h;/home/lewisedwards/bin/nsxtool-dev/apps/nsxqt/models/PeakListItem.h;/home/lewisedwards/bin/nsxtool-dev/apps/nsxqt/models/PeakListModel.h;/home/lewisedwards/bin/nsxtool-dev/apps/nsxqt/models/PeaksItem.h;/home/lewisedwards/bin/nsxtool-dev/apps/nsxqt/models/PinItem.h;/home/lewisedwards/bin/nsxtool-dev/apps/nsxqt/models/RulerItem.h;/home/lewisedwards/bin/nsxtool-dev/apps/nsxqt/models/SXGraphicsItem.h;/home/lewisedwards/bin/nsxtool-dev/apps/nsxqt/models/SampleItem.h;/home/lewisedwards/bin/nsxtool-dev/apps/nsxqt/models/SampleShapeItem.h;/home/lewisedwards/bin/nsxtool-dev/apps/nsxqt/models/SessionModel.h;/home/lewisedwards/bin/nsxtool-dev/apps/nsxqt/models/SessionModelDelegate.h;/home/lewisedwards/bin/nsxtool-dev/apps/nsxqt/models/SourceItem.h;/home/lewisedwards/bin/nsxtool-dev/apps/nsxqt/models/TaskManagerModel.h;/home/lewisedwards/bin/nsxtool-dev/apps/nsxqt/models/TaskManagerViewDelegate.h;/home/lewisedwards/bin/nsxtool-dev/apps/nsxqt/models/TreeItem.h;/home/lewisedwards/bin/nsxtool-dev/apps/nsxqt/models/UnitCellItem.h;/home/lewisedwards/bin/nsxtool-dev/apps/nsxqt/models/UnitCellsItem.h;/home/lewisedwards/bin/nsxtool-dev/apps/nsxqt/models/VerticalSliceGraphicsItem.h;/home/lewisedwards/bin/nsxtool-dev/apps/nsxqt/opengl/GLActor.h;/home/lewisedwards/bin/nsxtool-dev/apps/nsxqt/opengl/GLReciprocalLattice.h;/home/lewisedwards/bin/nsxtool-dev/apps/nsxqt/opengl/GLScene.h;/home/lewisedwards/bin/nsxtool-dev/apps/nsxqt/opengl/GLSphere.h;/home/lewisedwards/bin/nsxtool-dev/apps/nsxqt/opengl/GLTrackball.h;/home/lewisedwards/bin/nsxtool-dev/apps/nsxqt/opengl/GLWidget.h;/home/lewisedwards/bin/nsxtool-dev/apps/nsxqt/plot/PeakPlot.h;/home/lewisedwards/bin/nsxtool-dev/apps/nsxqt/plot/PlotterFactory.h;/home/lewisedwards/bin/nsxtool-dev/apps/nsxqt/plot/SXPlot.h;/home/lewisedwards/bin/nsxtool-dev/apps/nsxqt/plot/SimplePlot.h;/home/lewisedwards/bin/nsxtool-dev/apps/nsxqt/tree/DetectorPropertyWidget.h;/home/lewisedwards/bin/nsxtool-dev/apps/nsxqt/tree/EmptyPropertyWidget.h;/home/lewisedwards/bin/nsxtool-dev/apps/nsxqt/tree/NumorPropertyWidget.h;/home/lewisedwards/bin/nsxtool-dev/apps/nsxqt/tree/PeakListPropertyWidget.h;/home/lewisedwards/bin/nsxtool-dev/apps/nsxqt/tree/PeaksPropertyWidget.h;/home/lewisedwards/bin/nsxtool-dev/apps/nsxqt/tree/SamplePropertyWidget.h;/home/lewisedwards/bin/nsxtool-dev/apps/nsxqt/tree/SampleShapePropertyWidget.h;/home/lewisedwards/bin/nsxtool-dev/apps/nsxqt/tree/SourcePropertyWidget.h;/home/lewisedwards/bin/nsxtool-dev/apps/nsxqt/tree/UnitCellPropertyWidget.h;/home/lewisedwards/bin/nsxtool-dev/apps/nsxqt/utils/CustomEventFilters.h;/home/lewisedwards/bin/nsxtool-dev/apps/nsxqt/utils/GlobalInfo.h;/home/lewisedwards/bin/nsxtool-dev/apps/nsxqt/utils/PeaksUtils.h;/home/lewisedwards/bin/nsxtool-dev/apps/nsxqt/views/AbsorptionWidget.h;/home/lewisedwards/bin/nsxtool-dev/apps/nsxqt/views/DetectorSceneView.h;/home/lewisedwards/bin/nsxtool-dev/apps/nsxqt/views/PeakListView.h;/home/lewisedwards/bin/nsxtool-dev/apps/nsxqt/views/ProgressView.h;/home/lewisedwards/bin/nsxtool-dev/apps/nsxqt/views/SessionTreeView.h;/home/lewisedwards/bin/nsxtool-dev/apps/nsxqt/views/TaskManagerView.h;/home/lewisedwards/bin/nsxtool-dev/apps/nsxqt/widgets/CopyPasteTableView.h;/home/lewisedwards/bin/nsxtool-dev/apps/nsxqt/widgets/ScientificNotationSpinBox.h;/home/lewisedwards/bin/nsxtool-dev/apps/nsxqt/widgets/WidgetFoundPeaks.h;/home/lewisedwards/bin/nsxtool-dev/apps/nsxqt/widgets/WidgetRefinerFit.h;/home/lewisedwards/bin/nsxtool-dev/apps/nsxqt/widgets/WidgetUnitCell.h")
# Qt environment
set(AM_QT_VERSION_MAJOR "5")
set(AM_QT_VERSION_MINOR "9")
set(AM_QT_MOC_EXECUTABLE "/usr/lib/qt5/bin/moc")
set(AM_QT_UIC_EXECUTABLE )
set(AM_QT_RCC_EXECUTABLE "/usr/lib/qt5/bin/rcc")
# MOC settings
set(AM_MOC_SKIP "/home/lewisedwards/bin/nsxtool-dev/build/apps/nsxqt/nsxqt_autogen/EWIEGA46WW/qrc_NSXQt.cpp;/home/lewisedwards/bin/nsxtool-dev/build/apps/nsxqt/nsxqt_autogen/mocs_compilation.cpp;/home/lewisedwards/bin/nsxtool-dev/build/apps/nsxqt/ui_AbsorptionWidget.h;/home/lewisedwards/bin/nsxtool-dev/build/apps/nsxqt/ui_DetectorPropertyWidget.h;/home/lewisedwards/bin/nsxtool-dev/build/apps/nsxqt/ui_DialogAbsorption.h;/home/lewisedwards/bin/nsxtool-dev/build/apps/nsxqt/ui_DialogCalibrateDistance.h;/home/lewisedwards/bin/nsxtool-dev/build/apps/nsxqt/ui_DialogExperiment.h;/home/lewisedwards/bin/nsxtool-dev/build/apps/nsxqt/ui_DialogHDF5Converter.h;/home/lewisedwards/bin/nsxtool-dev/build/apps/nsxqt/ui_DialogIntegrate.h;/home/lewisedwards/bin/nsxtool-dev/build/apps/nsxqt/ui_DialogIsotopesDatabase.h;/home/lewisedwards/bin/nsxtool-dev/build/apps/nsxqt/ui_DialogMCAbsorption.h;/home/lewisedwards/bin/nsxtool-dev/build/apps/nsxqt/ui_DialogPeakFilter.h;/home/lewisedwards/bin/nsxtool-dev/build/apps/nsxqt/ui_DialogPredictPeaks.h;/home/lewisedwards/bin/nsxtool-dev/build/apps/nsxqt/ui_DialogRawData.h;/home/lewisedwards/bin/nsxtool-dev/build/apps/nsxqt/ui_DialogShapeLibrary.h;/home/lewisedwards/bin/nsxtool-dev/build/apps/nsxqt/ui_DialogSpaceGroup.h;/home/lewisedwards/bin/nsxtool-dev/build/apps/nsxqt/ui_DialogTransformationMatrix.h;/home/lewisedwards/bin/nsxtool-dev/build/apps/nsxqt/ui_DialogUnitCellParameters.h;/home/lewisedwards/bin/nsxtool-dev/build/apps/nsxqt/ui_EmptyPropertyWidget.h;/home/lewisedwards/bin/nsxtool-dev/build/apps/nsxqt/ui_FrameAutoIndexer.h;/home/lewisedwards/bin/nsxtool-dev/build/apps/nsxqt/ui_FrameDetectorGlobalOffsets.h;/home/lewisedwards/bin/nsxtool-dev/build/apps/nsxqt/ui_FrameInstrumentStates.h;/home/lewisedwards/bin/nsxtool-dev/build/apps/nsxqt/ui_FramePeakFinder.h;/home/lewisedwards/bin/nsxtool-dev/build/apps/nsxqt/ui_FrameRefiner.h;/home/lewisedwards/bin/nsxtool-dev/build/apps/nsxqt/ui_FrameSampleGlobalOffsets.h;/home/lewisedwards/bin/nsxtool-dev/build/apps/nsxqt/ui_FrameStatistics.h;/home/lewisedwards/bin/nsxtool-dev/build/apps/nsxqt/ui_FrameUserDefinedUnitCellIndexer.h;/home/lewisedwards/bin/nsxtool-dev/build/apps/nsxqt/ui_NumorPropertyWidget.h;/home/lewisedwards/bin/nsxtool-dev/build/apps/nsxqt/ui_PeakFilterDialog.h;/home/lewisedwards/bin/nsxtool-dev/build/apps/nsxqt/ui_PeakListPropertyWidget.h;/home/lewisedwards/bin/nsxtool-dev/build/apps/nsxqt/ui_PeaksPropertyWidget.h;/home/lewisedwards/bin/nsxtool-dev/build/apps/nsxqt/ui_ReciprocalSpaceViewer.h;/home/lewisedwards/bin/nsxtool-dev/build/apps/nsxqt/ui_SamplePropertyWidget.h;/home/lewisedwards/bin/nsxtool-dev/build/apps/nsxqt/ui_SampleShapePropertyWidget.h;/home/lewisedwards/bin/nsxtool-dev/build/apps/nsxqt/ui_SourcePropertyWidget.h;/home/lewisedwards/bin/nsxtool-dev/build/apps/nsxqt/ui_UnitCellPropertyWidget.h;/home/lewisedwards/bin/nsxtool-dev/build/apps/nsxqt/ui_WidgetFoundPeaks.h;/home/lewisedwards/bin/nsxtool-dev/build/apps/nsxqt/ui_WidgetRefinerFit.h;/home/lewisedwards/bin/nsxtool-dev/build/apps/nsxqt/ui_WidgetUnitCell.h")
set(AM_MOC_DEFINITIONS "EIGEN_FFTW_DEFAULT;NSXTOOL_GSL_VERSION_MAJOR=2;NSXTOOL_GSL_VERSION_MINOR=5;QT_CORE_LIB;QT_GUI_LIB;QT_NO_DEBUG;QT_OPENGL_LIB;QT_PRINTSUPPORT_LIB;QT_WIDGETS_LIB;_USE_MATH_DEFINES")
set(AM_MOC_INCLUDES "/home/lewisedwards/bin/nsxtool-dev/build/apps/nsxqt;/home/lewisedwards/bin/nsxtool-dev/apps/nsxqt;/home/lewisedwards/bin/nsxtool-dev/build/apps/nsxqt/nsxqt_autogen/include;/home/lewisedwards/bin/nsxtool-dev/externals/eigen3;/usr/include/hdf5/serial;/home/lewisedwards/.local/lib/python3.6/site-packages/numpy/core/include;/home/lewisedwards/bin/nsxtool-dev/externals/c-blosc/blosc;/usr/include/x86_64-linux-gnu;/usr/local/include;/home/lewisedwards/bin/nsxtool-dev/apps/nsxqt/blendfiles;/home/lewisedwards/bin/nsxtool-dev/apps/nsxqt/delegates;/home/lewisedwards/bin/nsxtool-dev/apps/nsxqt/dialogs;/home/lewisedwards/bin/nsxtool-dev/apps/nsxqt/externals;/home/lewisedwards/bin/nsxtool-dev/apps/nsxqt/frames;/home/lewisedwards/bin/nsxtool-dev/apps/nsxqt/logger;/home/lewisedwards/bin/nsxtool-dev/apps/nsxqt/menus;/home/lewisedwards/bin/nsxtool-dev/apps/nsxqt/models;/home/lewisedwards/bin/nsxtool-dev/apps/nsxqt/opengl;/home/lewisedwards/bin/nsxtool-dev/apps/nsxqt/plot;/home/lewisedwards/bin/nsxtool-dev/apps/nsxqt/resources;/home/lewisedwards/bin/nsxtool-dev/apps/nsxqt/tree;/home/lewisedwards/bin/nsxtool-dev/apps/nsxqt/ui;/home/lewisedwards/bin/nsxtool-dev/apps/nsxqt/utils;/home/lewisedwards/bin/nsxtool-dev/apps/nsxqt/views;/home/lewisedwards/bin/nsxtool-dev/apps/nsxqt/widgets;/home/lewisedwards/bin/nsxtool-dev/build/nsxlib/include;/usr/include/x86_64-linux-gnu/qt5;/usr/include/x86_64-linux-gnu/qt5/QtCore;/usr/lib/x86_64-linux-gnu/qt5/mkspecs/linux-g++;/usr/include/x86_64-linux-gnu/qt5/QtGui;/usr/include/x86_64-linux-gnu/qt5/QtOpenGL;/usr/include/x86_64-linux-gnu/qt5/QtWidgets;/usr/include/x86_64-linux-gnu/qt5/QtPrintSupport;/usr/include")
set(AM_MOC_OPTIONS "")
set(AM_MOC_RELAXED_MODE "FALSE")
set(AM_MOC_MACRO_NAMES "Q_OBJECT;Q_GADGET;Q_NAMESPACE")
set(AM_MOC_DEPEND_FILTERS "")
set(AM_MOC_PREDEFS_CMD "/usr/bin/c++;-dM;-E;-c;/usr/share/cmake-3.10/Modules/CMakeCXXCompilerABI.cpp")
# UIC settings
set(AM_UIC_SKIP )
set(AM_UIC_TARGET_OPTIONS )
set(AM_UIC_OPTIONS_FILES )
set(AM_UIC_OPTIONS_OPTIONS )
set(AM_UIC_SEARCH_PATHS )
# RCC settings
set(AM_RCC_SOURCES "/home/lewisedwards/bin/nsxtool-dev/apps/nsxqt/NSXQt.qrc")
set(AM_RCC_BUILDS "/home/lewisedwards/bin/nsxtool-dev/build/apps/nsxqt/nsxqt_autogen/EWIEGA46WW/qrc_NSXQt.cpp")
set(AM_RCC_OPTIONS "{-name;NSXQt}")
set(AM_RCC_INPUTS "{/home/lewisedwards/bin/nsxtool-dev/apps/nsxqt/resources/IconpickCenter.png;/home/lewisedwards/bin/nsxtool-dev/apps/nsxqt/resources/sampleIcon.png;/home/lewisedwards/bin/nsxtool-dev/apps/nsxqt/resources/unitCellTransformIcon.png;/home/lewisedwards/bin/nsxtool-dev/apps/nsxqt/resources/verticalSliceIcon.png;/home/lewisedwards/bin/nsxtool-dev/apps/nsxqt/resources/runTaskIcon.png;/home/lewisedwards/bin/nsxtool-dev/apps/nsxqt/resources/cutlineIcon.png;/home/lewisedwards/bin/nsxtool-dev/apps/nsxqt/resources/dataIcon.png;/home/lewisedwards/bin/nsxtool-dev/apps/nsxqt/resources/transformationMatrixImage.png;/home/lewisedwards/bin/nsxtool-dev/apps/nsxqt/resources/detectorAspectRatioOnIcon.png;/home/lewisedwards/bin/nsxtool-dev/apps/nsxqt/resources/findPeakIcon.png;/home/lewisedwards/bin/nsxtool-dev/apps/nsxqt/resources/detectorAspectRatioOffIcon.png;/home/lewisedwards/bin/nsxtool-dev/apps/nsxqt/resources/peakDeselectedIcon.png;/home/lewisedwards/bin/nsxtool-dev/apps/nsxqt/resources/detectorIcon.png;/home/lewisedwards/bin/nsxtool-dev/apps/nsxqt/resources/removeTaskIcon.png;/home/lewisedwards/bin/nsxtool-dev/apps/nsxqt/resources/saveIcon.png;/home/lewisedwards/bin/nsxtool-dev/apps/nsxqt/resources/sortUpIcon.png;/home/lewisedwards/bin/nsxtool-dev/apps/nsxqt/resources/unitCellsIcon.png;/home/lewisedwards/bin/nsxtool-dev/apps/nsxqt/resources/IconremovingPoints.png;/home/lewisedwards/bin/nsxtool-dev/apps/nsxqt/resources/horizontalSliceIcon.png;/home/lewisedwards/bin/nsxtool-dev/apps/nsxqt/resources/slice3D.png;/home/lewisedwards/bin/nsxtool-dev/apps/nsxqt/resources/aboutNSXTool;/home/lewisedwards/bin/nsxtool-dev/apps/nsxqt/resources/writeToPDFIcon.png;/home/lewisedwards/bin/nsxtool-dev/apps/nsxqt/resources/numorIcon.png;/home/lewisedwards/bin/nsxtool-dev/apps/nsxqt/resources/peakLibraryIcon.png;/home/lewisedwards/bin/nsxtool-dev/apps/nsxqt/resources/zoomIcon.png;/home/lewisedwards/bin/nsxtool-dev/apps/nsxqt/resources/addExperimentIcon.png;/home/lewisedwards/bin/nsxtool-dev/apps/nsxqt/resources/crystalIcon.png;/home/lewisedwards/bin/nsxtool-dev/apps/nsxqt/resources/ill_logo.png;/home/lewisedwards/bin/nsxtool-dev/apps/nsxqt/resources/Icontriangulate.png;/home/lewisedwards/bin/nsxtool-dev/apps/nsxqt/resources/selectIcon.png;/home/lewisedwards/bin/nsxtool-dev/apps/nsxqt/resources/peakListIcon.png;/home/lewisedwards/bin/nsxtool-dev/apps/nsxqt/resources/openFileIcon.png;/home/lewisedwards/bin/nsxtool-dev/apps/nsxqt/resources/gonioIcon.png;/home/lewisedwards/bin/nsxtool-dev/apps/nsxqt/resources/frm2_logo.png;/home/lewisedwards/bin/nsxtool-dev/apps/nsxqt/resources/matrixIcon.png;/home/lewisedwards/bin/nsxtool-dev/apps/nsxqt/resources/sortDownIcon.png;/home/lewisedwards/bin/nsxtool-dev/apps/nsxqt/resources/IconpickingPoints.png;/home/lewisedwards/bin/nsxtool-dev/apps/nsxqt/resources/toHKLIcon.png;/home/lewisedwards/bin/nsxtool-dev/apps/nsxqt/resources/abortTaskIcon.png;/home/lewisedwards/bin/nsxtool-dev/apps/nsxqt/resources/jcns_logo.png;/home/lewisedwards/bin/nsxtool-dev/apps/nsxqt/resources/instrumentIcon.png;/home/lewisedwards/bin/nsxtool-dev/apps/nsxqt/resources/unitCellIcon.png;/home/lewisedwards/bin/nsxtool-dev/apps/nsxqt/resources/rectangularMaskIcon.png;/home/lewisedwards/bin/nsxtool-dev/apps/nsxqt/resources/splashScreen.png;/home/lewisedwards/bin/nsxtool-dev/apps/nsxqt/resources/IconmeasureDistance.png;/home/lewisedwards/bin/nsxtool-dev/apps/nsxqt/resources/experimentIcon.png;/home/lewisedwards/bin/nsxtool-dev/apps/nsxqt/resources/reciprocal_space.png;/home/lewisedwards/bin/nsxtool-dev/apps/nsxqt/resources/sourceIcon.png;/home/lewisedwards/bin/nsxtool-dev/apps/nsxqt/resources/ellipsoidalMaskIcon.png;/home/lewisedwards/bin/nsxtool-dev/apps/nsxqt/resources/peakSelectedIcon.png;/home/lewisedwards/bin/nsxtool-dev/apps/nsxqt/resources/NSXToolIcon.png;/home/lewisedwards/bin/nsxtool-dev/apps/nsxqt/resources/singlePeakIcon.png;/home/lewisedwards/bin/nsxtool-dev/apps/nsxqt/resources/IconcalibrateDistance.png}")
# Configurations options
set(AM_CONFIG_SUFFIX_Release "_Release")
