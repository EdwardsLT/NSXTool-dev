set(CMAKE_SWIG_OUTDIR ${CMAKE_CURRENT_BINARY_DIR})

GET_SUBDIRECTORIES(NSX_SUBDIRS ${CMAKE_SOURCE_DIR}/nsxlib)

include_directories(${CMAKE_CURRENT_BINARY_DIR})
include_directories(${CMAKE_BINARY_DIR}/nsxlib/generated)
include_directories(${PYTHON_INCLUDE_DIRS})
include_directories(${NSX_SUBDIRS})

if (NSX_DOCS)
    GeneratePythonDocs(pynsx_doc.i ${CMAKE_SOURCE_DIR}/swig)
else()
    file(WRITE ${CMAKE_CURRENT_BINARY_DIR}/pynsx_doc.i "")
endif()

set_property(SOURCE pynsx.i PROPERTY CPLUSPLUS ON)
set_property(SOURCE pynsx.i PROPERTY SWIG_MODULE_NAME pynsx)

# Set the nsxlib headers path at the swig level
get_directory_property(PYNSX_INCLUDE_DIRECTORIES INCLUDE_DIRECTORIES)
list(REMOVE_DUPLICATES PYNSX_INCLUDE_DIRECTORIES)
set(PYNSX_SWIG_INCLUDE_DIRECTORIES)
foreach(it ${PYNSX_INCLUDE_DIRECTORIES})
    set(PYNSX_SWIG_INCLUDE_DIRECTORIES ${PYNSX_SWIG_INCLUDE_DIRECTORIES} "-I${it}")
endforeach()
set_property(SOURCE pynsx.i PROPERTY SWIG_FLAGS ${PYNSX_SWIG_INCLUDE_DIRECTORIES})

if(${CMAKE_VERSION} VERSION_GREATER 3.8)
    swig_add_library(pynsx TYPE MODULE LANGUAGE python SOURCES pynsx.i)
else()
    swig_add_module(pynsx python pynsx.i)
endif()

swig_link_libraries(pynsx nsx ${PYTHON_LIBRARIES})

if(ENABLE_CPACK)
    if(APPLE)
        set_target_properties(${SWIG_MODULE_pynsx_REAL_NAME} PROPERTIES INSTALL_RPATH "@loader_path/../../../Frameworks;@loader_path/../../")
    elseif(LINUX)
        set_target_properties(${SWIG_MODULE_pynsx_REAL_NAME} PROPERTIES INSTALL_RPATH "\$ORIGIN/../../")
    endif()
endif()

install(TARGETS ${SWIG_MODULE_pynsx_REAL_NAME} DESTINATION ${NSX_INSTALL_DIR}${PYTHON_SITE} COMPONENT LIB)
install(FILES ${CMAKE_CURRENT_BINARY_DIR}/pynsx.py DESTINATION ${NSX_INSTALL_DIR}${PYTHON_SITE} COMPONENT LIB)
