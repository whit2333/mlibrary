# $Id: CMakeLists.txt 86065 2014-11-07 08:51:15Z gcosmo $

#----------------------------------------------------------------------------
# Setup the project
cmake_minimum_required(VERSION 3.8 FATAL_ERROR)
project(MLIBRARY VERSION 0.0.1)

include(GNUInstallDirs)

SET(MLIBRARY_MAJOR_VERSION 0)
SET(MLIBRARY_MINOR_VERSION 0)
SET(MLIBRARY_PATCH_VERSION 0)
set(MLIBRARY_VERSION ${MLIBRARY_MAJOR_VERSION}.${MLIBRARY_MINOR_VERSION}.${MLIBRARY_PATCH_VERSION})

SET(SHARE_DIR_NAME bubble_sim)
SET(MACRO_DIR    share/${SHARE_DIR_NAME})
SET(GEOMETRY_DIR share/${SHARE_DIR_NAME}/geometry_files)

SET(MLIBRARY_MACRO_DIR ${CMAKE_INSTALL_PREFIX}/${MACRO_DIR} )
SET(MLIBRARY_GEOMETRY_DIR ${CMAKE_INSTALL_PREFIX}/${GEOMETRY_DIR} )


#----------------------------------------------------------------------------
# Find Geant4 package, activating all available UI and Vis drivers by default
# You can set WITH_GEANT4_UIVIS to OFF via the command line or ccmake/cmake-gui
# to build a batch mode only executable
#
option(WITH_GEANT4_UIVIS "Build example with Geant4 UI and Vis drivers" ON)
if(WITH_GEANT4_UIVIS)
  find_package(Geant4 REQUIRED ui_all vis_all)
else()
  find_package(Geant4 REQUIRED)
endif()

# Find includes in corresponding build directories
set(CMAKE_INCLUDE_CURRENT_DIR ON)
# Instruct CMake to run moc automatically when needed
set(CMAKE_AUTOMOC ON)
# Create code from a list of Qt designer ui files
set(CMAKE_AUTOUIC ON)

# Find the QtWidgets library
find_package(Qt5Widgets  CONFIG REQUIRED)
find_package(Qt5Xml  CONFIG REQUIRED)
find_package(Qt5OpenGL  CONFIG REQUIRED)
#Qt5PrintSupport Qt5Core Qt5Widgets Qt5Xml Qt5Sql 

#----------------------------------------------------------------------------
# ROOT
list(APPEND CMAKE_PREFIX_PATH $ENV{ROOTSYS})
find_package(ROOT REQUIRED COMPONENTS MathCore RIO Hist MathMore Graf Graf3d
   Gpad GX11 GeomPainter X3d Gviz3d RGL
   Eve EG Foam GenVector Geom GLEW Gui HistPainter MathCore Matrix MLP Net
   Physics Spectrum Thread Tree TreeViewer)
#find_package(ROOT REQUIRED COMPONENTS MathCore RIO Hist MathMore Graf HistPainter Rint)
include(${ROOT_USE_FILE})
include_directories(${CMAKE_SOURCE_DIR} ${ROOT_INCLUDE_DIRS})
add_definitions(${ROOT_CXX_FLAGS})


# CADMesh
find_package(cadmesh REQUIRED)
if(cadmesh_FOUND)
endif(cadmesh_FOUND)

#----------------------------------------------------------------------------
# Setup Geant4 include directories and compile definitions
# Setup include directory for this project
#
include(${Geant4_USE_FILE})
include_directories(
  ${PROJECT_SOURCE_DIR}/include
  ${PROJECT_BINARY_DIR}
  )


#----------------------------------------------------------------------------
# Locate sources and headers for this project
# NB: headers are included so they will show up in IDEs
#
set(sources  
  #cadmesh/examples/basic/cadmesh_example.cc
  #cadmesh/examples/basic/src/DetectorConstruction.cc
  #cadmesh/examples/basic/src/PhysicsList.cc
  #cadmesh/examples/basic/src/PrimaryGeneratorAction.cc
  #cadmesh/examples/template/cadmesh_template.cc
  #cadmesh/examples/template/src/DetectorConstruction.cc
  #cadmesh/examples/template/src/PhysicsList.cc
  #cadmesh/examples/template/src/PrimaryGeneratorAction.cc
  #cadmesh/src/CADMesh.cc
  #frequencySyncSignal/example.cc
  frequencySyncSignal/frequencySyncSignal.cc
  g4display/displayUI.cc
  #g4display/example.cc
  g4display/g4display.cc
  g4display/tabs/gcamera.cc
  g4display/tabs/gslice.cc
  g4display/utilities.cc
  #g4volume/example.cc
  g4volume/g4systemFactories/cad/logical.cc
  g4volume/g4systemFactories/cad/physical.cc
  g4volume/g4systemFactories/cad/solid.cc
  g4volume/g4systemFactories/checkDependencies.cc
  g4volume/g4systemFactories/getG4Volumes.cc
  g4volume/g4systemFactories/native/checkAndReturnParameters.cc
  g4volume/g4systemFactories/native/g4SolidConstructorDescription.cc
  g4volume/g4systemFactories/native/logical.cc
  g4volume/g4systemFactories/native/physical.cc
  g4volume/g4systemFactories/native/solid.cc
  g4volume/g4systemFactories/registerFactory.cc
  g4volume/g4volume.cc
  g4volume/utilities.cc
  g4volume/world.cc
  #gdata/example.cc
  gdata/gdata.cc
  gdata/observables/gobservables.cc
  gdynamic/ctofRoutinesExample.cc
  #gdynamic/example.cc
  gdynamic/trueObservable.cc
  gdynamic/truePulse.cc
  #gfactory/factoryExample/DodgeFactory.cc
  ##gfactory/factoryExample/example.cc
  #gfactory/factoryExample/FordFactory.cc
  #gfactory/factoryExample/ShapeFactory.cc
  #gfields/example.cc
  gfields/gfield.cc
  gfields/gFieldManager.cc
  gfields/gMap.cc
  gfields/gMapCoordinates.cc
  ghit/buildHitInfos.cc
  ghit/calculations.cc
  #ghit/example.cc
  ghit/ghit.cc
  #gmedia/example.cc
  gmedia/factories/root/connection.cc
  gmedia/factories/root/event.cc
  gmedia/factories/root/gmediaROOTFactory.cc
  gmedia/factories/root/gRootTree.cc
  gmedia/factories/root/publishDetectorDigiObservables.cc
  gmedia/factories/root/publishDetectorTrueObservables.cc
  gmedia/factories/root/publishHeader.cc
  gmedia/factories/txt/connection.cc
  gmedia/factories/txt/event.cc
  gmedia/factories/txt/gmediaTxtFactory.cc
  gmedia/factories/txt/publishDetectorDigiObservables.cc
  gmedia/factories/txt/publishDetectorTrueObservables.cc
  gmedia/factories/txt/publishHeader.cc
  gmedia/gmedia.cc
  gruns/defineOptions.cc
  #gruns/example.cc
  gruns/gruns.cc
  #gstring/example.cc
  gstring/gstring.cc
  #gtouchable/example.cc
  gtouchable/gtouchable.cc
  #gvolume/example.cc
  gvolume/gmaterial.cc
  gvolume/gsystem.cc
  gvolume/gvolume.cc
  gvolume/systemFactories/cad/gmaterial.cc
  gvolume/systemFactories/cad/gvolume.cc
  gvolume/systemFactories/gdml/gmaterial.cc
  gvolume/systemFactories/gdml/gvolume.cc
  gvolume/systemFactories/registerFactory.cc
  gvolume/systemFactories/text/gmaterial.cc
  gvolume/systemFactories/text/gvolume.cc
  gvolume/utilities.cc
  #options/example.cc
  options/goptions.cc
  #qtButtonsWidget/example.cc
  qtButtonsWidget/qtButtonsWidget.cc
  #splash/example.cc
  splash/gsplash.cc
  #textProgressBar/example.cc
  textProgressBar/textProgressBar.cc
  #translationTable/example.cc
  translationTable/translationTable.cc
  )

set(headers 
  frequencySyncSignal/frequencySyncSignal.h
  g4display/displayUI.h
  g4display/g4display.h
  g4display/tabs/gcamera.h
  g4display/tabs/gslice.h
  g4volume/g4systemFactories/cad/g4CadSetupFactory.h
  g4volume/g4systemFactories/g4SetupFactory.h
  g4volume/g4systemFactories/native/g4NativeSetupFactory.h
  g4volume/g4volume.h
  gdata/gdata.h
  gdata/observables/gdetectorObservables.h
  gdata/observables/gobservables.h
  gdynamic/ctofRoutinesExample.h
  gdynamic/gdynamic.h
  #gfactory/factoryExample/Car.h
  #gfactory/factoryExample/DodgeFactory.h
  #gfactory/factoryExample/FordFactory.h
  #gfactory/factoryExample/ShapeFactory.h
  gfactory/gdl.h
  gfactory/gfactory.h
  gfields/gfield.h
  gfields/gMapCoordinates.h
  gfields/gMap.h
  ghit/ghit.h
  gmedia/factories/root/gmediaROOTFactory.h
  gmedia/factories/root/gRootTree.h
  gmedia/factories/txt/gmediaTxtFactory.h
  gmedia/gmedia.h
  gruns/gruns.h
  gstring/gstring.h
  gtouchable/gtouchable.h
  gvolume/gmaterial.h
  gvolume/gsystem.h
  gvolume/gvolume.h
  gvolume/systemFactories/cad/systemCadFactory.h
  gvolume/systemFactories/gdml/systemGDMLFactory.h
  gvolume/systemFactories/systemDynamicFactory.h
  gvolume/systemFactories/systemFactory.h
  gvolume/systemFactories/text/systemTextFactory.h
  options/goptions.h
  qtButtonsWidget/qtButtonsWidget.h
  splash/gsplash.h
  textProgressBar/textProgressBar.h
  translationTable/translationTable.h
  )

add_library(MLibrary  SHARED ${sources} )

target_include_directories(MLibrary
  PUBLIC #$<INSTALL_INTERFACE:include>
  $<INSTALL_INTERFACE:include>
  $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/options>
  $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/g4display>
  $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/gvolume>
  $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/g4volume>
  $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/gvolume/systemFactories>
  $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/gvolume/systemFactories/gdml>
  $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/gvolume/systemFactories/cad>
  $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/gvolume/systemFactories/text>
  $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/qtButtonsWidget>
  $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/gstring>
  $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/gfactory>
  $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/gfields>
  $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/ghit>
  $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/gdata/observables>
  $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/gdata>
  $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/gmedia>
  $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/splash>
  $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/gtouchable>
  $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/frequencySyncSignal>
  $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/gdynamic>
  $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/translationTable>
  $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
  $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/textProgressBar>

  $<INSTALL_INTERFACE:include/options>
  $<INSTALL_INTERFACE:include/g4display>
  $<INSTALL_INTERFACE:include/gvolume>
  $<INSTALL_INTERFACE:include/g4volume>
  $<INSTALL_INTERFACE:include/gvolume/systemFactories>
  $<INSTALL_INTERFACE:include/gvolume/systemFactories/gdml>
  $<INSTALL_INTERFACE:include/gvolume/systemFactories/cad>
  $<INSTALL_INTERFACE:include/gvolume/systemFactories/text>
  $<INSTALL_INTERFACE:include/qtButtonsWidget>
  $<INSTALL_INTERFACE:include/gstring>
  $<INSTALL_INTERFACE:include/gfactory>
  $<INSTALL_INTERFACE:include/gfields>
  $<INSTALL_INTERFACE:include/ghit>
  $<INSTALL_INTERFACE:include/gdata/observables>
  $<INSTALL_INTERFACE:include/gdata>
  $<INSTALL_INTERFACE:include/gmedia>
  $<INSTALL_INTERFACE:include/splash>
  $<INSTALL_INTERFACE:include/gtouchable>
  $<INSTALL_INTERFACE:include/frequencySyncSignal>
  $<INSTALL_INTERFACE:include/gdynamic>
  $<INSTALL_INTERFACE:include/translationTable>
  $<INSTALL_INTERFACE:include/include>
  $<INSTALL_INTERFACE:include/textProgressBar>

    PUBLIC ${CADMESH_INCLUDE_DIRS}
    #$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include/hcana>
    #$<BUILD_INTERFACE:${Podd_DIR}/../../include/podd2>
    #$<BUILD_INTERFACE:${CMAKE_CURRENT_BINARY_DIR}>  # for hc_compiledata.h
    #$<BUILD_INTERFACE:${SPDLOG_INCLUDE_DIR}>
    #$<INSTALL_INTERFACE:${SPDLOG_INCLUDE_DIR}>
    #$<BUILD_INTERFACE:${FMT_INCLUDE_DIR}>
  )

#jtarget_compile_options(MLibrary
#j  PUBLIC
#j    ${${PROJECT_NAME_UC}_CXX_FLAGS_LIST}
#j  PRIVATE
#j    ${${PROJECT_NAME_UC}_DIAG_FLAGS_LIST}
#j  )

target_link_libraries(MLibrary
  PUBLIC Qt5::Widgets
  PUBLIC Qt5::Xml
  PUBLIC Qt5::OpenGL
  PUBLIC ${Geant4_LIBRARIES} 
  PUBLIC ${cadmesh_LIBRARIES}
  ${CMAKE_DL_LIBS}
  )
target_compile_features(MLibrary PUBLIC cxx_std_17)

#set_target_properties(${LIBNAME} PROPERTIES
#  SOVERSION ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
#  VERSION ${PROJECT_VERSION}
#  EXPORT_NAME ${LIBNAME}
#  )

install(TARGETS MLibrary
  EXPORT MLibraryTargets
  LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
  ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR}
  RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
  )
install(FILES ${allheaders} DESTINATION ${CMAKE_INSTALL_INCLUDEDIR})
#install(DIRECTORY nlohmann DESTINATION ${CMAKE_INSTALL_INCLUDEDIR})

install(DIRECTORY fields DESTINATION include FILES_MATCHING PATTERN "*.h")
install(DIRECTORY frequencySyncSignal DESTINATION include FILES_MATCHING PATTERN "*.h")
install(DIRECTORY g4display DESTINATION include FILES_MATCHING PATTERN "*.h")
install(DIRECTORY g4volume DESTINATION include FILES_MATCHING PATTERN "*.h")
install(DIRECTORY gdata DESTINATION include FILES_MATCHING PATTERN "*.h")
install(DIRECTORY gdynamic DESTINATION include FILES_MATCHING PATTERN "*.h")
install(DIRECTORY gfactory DESTINATION include FILES_MATCHING PATTERN "*.h")
install(DIRECTORY gfields DESTINATION include FILES_MATCHING PATTERN "*.h")
install(DIRECTORY ghit DESTINATION include FILES_MATCHING PATTERN "*.h")
install(DIRECTORY gmedia DESTINATION include FILES_MATCHING PATTERN "*.h")
install(DIRECTORY gruns DESTINATION include FILES_MATCHING PATTERN "*.h")
install(DIRECTORY gstring DESTINATION include FILES_MATCHING PATTERN "*.h")
install(DIRECTORY gtouchable DESTINATION include FILES_MATCHING PATTERN "*.h")
install(DIRECTORY gvolume DESTINATION include FILES_MATCHING PATTERN "*.h")
install(DIRECTORY options DESTINATION include FILES_MATCHING PATTERN "*.h")
install(DIRECTORY splash DESTINATION include FILES_MATCHING PATTERN "*.h")
install(DIRECTORY qtButtonsWidget DESTINATION include FILES_MATCHING PATTERN "*.h")
install(DIRECTORY textProgressBar DESTINATION include FILES_MATCHING PATTERN "*.h")
install(DIRECTORY translationTable DESTINATION include FILES_MATCHING PATTERN "*.h")
      #install(DIRECTORY include/hcana  DESTINATION ${CMAKE_INSTALL_INCLUDEDIR})
#install(DIRECTORY include/spdlog DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}/hcana)
#file(GLOB sources ${PROJECT_SOURCE_DIR}/src/*.cc)
#file(GLOB headers ${PROJECT_SOURCE_DIR}/include/*.hh ${PROJECT_BINARY_DIR}/MLIBRARY.h)

#----------------------------------------------------------------------------
# install library config
include(CMakePackageConfigHelpers)

# Install and export targets
install(EXPORT MLibraryTargets
    FILE MLibraryTargets.cmake
    NAMESPACE MLibrary::
    DESTINATION lib/MLibrary
    )

  set(TARGETS_INSTALL_PATH MLibrary/MLibraryTargets.cmake)
CONFIGURE_PACKAGE_CONFIG_FILE(
  cmake/MLibraryConfig.cmake.in  
  ${CMAKE_CURRENT_BINARY_DIR}/MLibraryConfig.cmake
  INSTALL_DESTINATION lib
  PATH_VARS TARGETS_INSTALL_PATH
  )

write_basic_package_version_file("MLibraryConfigVersion.cmake"
    VERSION ${VERSION}
    COMPATIBILITY SameMajorVersion
    )

install(FILES
  ${CMAKE_CURRENT_BINARY_DIR}/MLibraryConfig.cmake
  ${CMAKE_CURRENT_BINARY_DIR}/MLibraryConfigVersion.cmake
  DESTINATION lib/MLibrary
  )


# Add the executable, and link it to the Geant4 libraries
#
#add_executable(exampleB1 exampleB1.cc ${sources} ${headers})
#target_include_directories(exampleB1 PUBLIC ${CADMESH_INCLUDE_DIRS} )
#target_link_libraries(exampleB1 ${Geant4_LIBRARIES} ${cadmesh_LIBRARIES} )

#add_executable(bubble_chamber bubble_chamber.cc ${sources} ${headers})
#target_include_directories(bubble_chamber PUBLIC ${CADMESH_INCLUDE_DIRS} )
#target_link_libraries(bubble_chamber ${Geant4_LIBRARIES} ${cadmesh_LIBRARIES})
#
##----------------------------------------------------------------------------
## For internal Geant4 use - but has no effect if you build this
## example standalone
##
#add_custom_target(MLIBRARY DEPENDS bubble_chamber)
#
##----------------------------------------------------------------------------
## Copy all scripts to the build directory, i.e. the directory in which we
## build B1. This is so that we can run the executable directly because it
## relies on these scripts being in the current working directory.
##
#set(EXAMPLEB1_SCRIPTS
#  exampleB1.in
#  exampleB1.out
#  examples/init_vis.mac
#  examples/run1.mac
#  examples/run2.mac
#  examples/vis.mac
#  examples/vis2.mac
#  examples/trajectory_model.mac
#  )
#foreach(_script ${EXAMPLEB1_SCRIPTS})
#  configure_file(
#    ${PROJECT_SOURCE_DIR}/${_script}
#    ${PROJECT_BINARY_DIR}/${_script}
#    COPYONLY
#    )
#endforeach()
#install(FILES ${EXAMPLEB1_SCRIPTS} 
#  DESTINATION share/${SHARE_DIR_NAME}/examples )
#
#install(DIRECTORY  ${PROJECT_SOURCE_DIR}/geometry_files
#  DESTINATION share/${SHARE_DIR_NAME} )
#
#install(FILES
#  ${PROJECT_SOURCE_DIR}/bin/run_bubble_sim 
#  DESTINATION bin
#  PERMISSIONS WORLD_READ WORLD_EXECUTE
#  )
#
#
##----------------------------------------------------------------------------
## Install the executable to 'bin' directory under CMAKE_INSTALL_PREFIX
##
##install(TARGETS exampleB1 DESTINATION bin)
#install(TARGETS bubble_chamber DESTINATION bin)
#
## ----------------------------------------------------------------------------
## Configured files 
## These files end with ".in" which is removed when installed
#set(EXAMPLEB1_CONF_FILES
#  BubbleChamberSim.h
#  init_default.mac
#  #vis.mac
#  )
#foreach(_script ${EXAMPLEB1_CONF_FILES})
#  configure_file("${_script}.in" "${PROJECT_BINARY_DIR}/${_script}" @ONLY)
#  install(FILES ${PROJECT_BINARY_DIR}/${_script} DESTINATION ${CMAKE_INSTALL_PREFIX}/share/${SHARE_DIR_NAME} )
#endforeach()
#
#
### Add all targets to the build-tree export set
#export(TARGETS bubble_chamber FILE "${PROJECT_BINARY_DIR}/${PROJECT_NAME}Targets.cmake")
##
### Export the package for use from the build-tree
### (this registers the build-tree with a global CMake-registry)
##export(PACKAGE ${PROJECT_NAME})
##
##set(CONF_LIBRARIES ${PROJECT_NAME})
##
##set(CONF_EXECUTABLES insane-config)
##
##set(CONF_INCLUDE_DIRS 
##   ${CMAKE_INSTALL_PREFIX}/include
##   ${CMAKE_INSTALL_PREFIX}/include/${PROJECT_NAME}
##   )
##
##set(CONF_LIBRARY_DIRS ${CMAKE_INSTALL_PREFIX}/lib)
##
###configure_file(${PROJECT_NAME}Config.cmake.in "${PROJECT_BINARY_DIR}${CMAKE_FILES_DIRECTORY}/${PROJECT_NAME}Config.cmake" @ONLY)
##
##configure_file(${PROJECT_NAME}ConfigVersion.cmake.in "${PROJECT_BINARY_DIR}/${PROJECT_NAME}ConfigVersion.cmake" @ONLY)
##
### Install the FooBarConfig.cmake and FooBarConfigVersion.cmake
##install(FILES
##  "${PROJECT_BINARY_DIR}${CMAKE_FILES_DIRECTORY}/${PROJECT_NAME}Config.cmake"
##  "${PROJECT_BINARY_DIR}/${PROJECT_NAME}ConfigVersion.cmake"
##  DESTINATION "${INSTALL_CMAKE_DIR}" COMPONENT dev)
##
### Install the export set for use with the install-tree
##install(EXPORT ${PROJECT_NAME}Targets DESTINATION
##  "${INSTALL_CMAKE_DIR}" COMPONENT dev)

