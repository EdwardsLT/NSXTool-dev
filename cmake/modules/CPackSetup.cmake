set(CPACK_PACKAGE_NAME "nsxtool")
set(CPACK_PACKAGE_DESCRIPTION"NSXTool: single crystal data reduction")
set(CPACK_PACKAGE_VENDOR "Institut Laue Langevin")
set(CPACK_PACKAGE_URL http://www.code.fr/scientific-software/nsxtool.git)
set(CPACK_PACKAGE_VERSION ${NSXTOOL_VERSION})
set(CPACK_PACKAGE_VERSION_MAJOR ${NSXTOOL_VERSION_MAJOR})
set(CPACK_PACKAGE_VERSION_MINOR ${NSXTOOL_VERSION_MINOR})
set(CPACK_PACKAGE_VERSION_PATCH ${NSXTOOL_VERSION_PATCH})

configure_file(LICENSE.txt LICENSE.txt COPYONLY)
set(CPACK_RESOURCE_FILE_LICENSE "${CMAKE_BINARY_DIR}/LICENSE.txt")

# binary package setup
set(CPACK_PACKAGE_RELOCATABLE True)

if(CMAKE_BUILD_TYPE STREQUAL Release)
    set(CPACK_PACKAGE_FILE_NAME "${CMAKE_PROJECT_NAME}-${NSXTOOL_VERSION}-${NSXTOOL_ARCHITECTURE}")
else()
    set(CPACK_PACKAGE_FILE_NAME "${CMAKE_PROJECT_NAME}-${NSXTOOL_VERSION}-${NSXTOOL_ARCHITECTURE}-${CMAKE_BUILD_TYPE}")
endif()

set(CPACK_PACKAGE_INSTALL_DIRECTORY "${CMAKE_PROJECT_NAME}-${NSXTOOL_VERSION}")

if(WIN32)
    include(CPackWindows)
elseif(APPLE)
    include(CPackApple)
elseif(UNIX)
  include(CheckLinuxDistro)
  if (DEBIAN_LIKE)
    include(CPackDebian)
  else()
    include(CPackRPM)
  endif()
else()
  set(CPACK_GENERATOR "STGZ;TGZ")
endif()

set(CPACK_SOURCE_IGNORE_FILES "/\\\\.git/;" )

# Generating the source package
set(CPACK_SOURCE_GENERATOR "TGZ")
set(CPACK_SOURCE_PACKAGE_FILE_NAME "${CPACK_PACKAGE_NAME}-${CPACK_PACKAGE_VERSION_MAJOR}.${CPACK_PACKAGE_VERSION_MINOR}.${CPACK_PACKAGE_VERSION_PATCH}")
    
include(CPack)

set(CPACK_COMPONENTS_ALL LIB HEADERS DATA APLICATIONS)


