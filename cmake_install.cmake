# Install script for directory: /home/xetql/Dropbox/projects/cpp/nbody/liblj

# Set the install prefix
if(NOT DEFINED CMAKE_INSTALL_PREFIX)
  set(CMAKE_INSTALL_PREFIX "/usr/local")
endif()
string(REGEX REPLACE "/$" "" CMAKE_INSTALL_PREFIX "${CMAKE_INSTALL_PREFIX}")

# Set the install configuration name.
if(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)
  if(BUILD_TYPE)
    string(REGEX REPLACE "^[^A-Za-z0-9_]+" ""
           CMAKE_INSTALL_CONFIG_NAME "${BUILD_TYPE}")
  else()
    set(CMAKE_INSTALL_CONFIG_NAME "Release")
  endif()
  message(STATUS "Install configuration: \"${CMAKE_INSTALL_CONFIG_NAME}\"")
endif()

# Set the component getting installed.
if(NOT CMAKE_INSTALL_COMPONENT)
  if(COMPONENT)
    message(STATUS "Install component: \"${COMPONENT}\"")
    set(CMAKE_INSTALL_COMPONENT "${COMPONENT}")
  else()
    set(CMAKE_INSTALL_COMPONENT)
  endif()
endif()

# Install shared libraries without execute permission?
if(NOT DEFINED CMAKE_INSTALL_SO_NO_EXE)
  set(CMAKE_INSTALL_SO_NO_EXE "1")
endif()

if("${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  list(APPEND CMAKE_ABSOLUTE_DESTINATION_FILES
   "/usr/lib/liblj/liblj.a")
  if(CMAKE_WARN_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(WARNING "ABSOLUTE path INSTALL DESTINATION : ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  if(CMAKE_ERROR_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(FATAL_ERROR "ABSOLUTE path INSTALL DESTINATION forbidden (by caller): ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
file(INSTALL DESTINATION "/usr/lib/liblj" TYPE STATIC_LIBRARY FILES "/home/xetql/Dropbox/projects/cpp/nbody/liblj/lib/liblj.a")
endif()

if("${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  list(APPEND CMAKE_ABSOLUTE_DESTINATION_FILES
   "/usr/include/liblj/atomic_cells.hpp;/usr/include/liblj/common.hpp;/usr/include/liblj/kdtree.hpp;/usr/include/liblj/linkedlist.hpp;/usr/include/liblj/ljsim.hpp;/usr/include/liblj/matrix.hpp;/usr/include/liblj/nbody_io.hpp;/usr/include/liblj/neighborhood.hpp;/usr/include/liblj/params.hpp;/usr/include/liblj/space.hpp")
  if(CMAKE_WARN_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(WARNING "ABSOLUTE path INSTALL DESTINATION : ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  if(CMAKE_ERROR_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(FATAL_ERROR "ABSOLUTE path INSTALL DESTINATION forbidden (by caller): ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
file(INSTALL DESTINATION "/usr/include/liblj" TYPE FILE FILES
    "/home/xetql/Dropbox/projects/cpp/nbody/liblj/includes/atomic_cells.hpp"
    "/home/xetql/Dropbox/projects/cpp/nbody/liblj/includes/common.hpp"
    "/home/xetql/Dropbox/projects/cpp/nbody/liblj/includes/kdtree.hpp"
    "/home/xetql/Dropbox/projects/cpp/nbody/liblj/includes/linkedlist.hpp"
    "/home/xetql/Dropbox/projects/cpp/nbody/liblj/includes/ljsim.hpp"
    "/home/xetql/Dropbox/projects/cpp/nbody/liblj/includes/matrix.hpp"
    "/home/xetql/Dropbox/projects/cpp/nbody/liblj/includes/nbody_io.hpp"
    "/home/xetql/Dropbox/projects/cpp/nbody/liblj/includes/neighborhood.hpp"
    "/home/xetql/Dropbox/projects/cpp/nbody/liblj/includes/params.hpp"
    "/home/xetql/Dropbox/projects/cpp/nbody/liblj/includes/space.hpp"
    )
endif()

if(CMAKE_INSTALL_COMPONENT)
  set(CMAKE_INSTALL_MANIFEST "install_manifest_${CMAKE_INSTALL_COMPONENT}.txt")
else()
  set(CMAKE_INSTALL_MANIFEST "install_manifest.txt")
endif()

string(REPLACE ";" "\n" CMAKE_INSTALL_MANIFEST_CONTENT
       "${CMAKE_INSTALL_MANIFEST_FILES}")
file(WRITE "/home/xetql/Dropbox/projects/cpp/nbody/liblj/${CMAKE_INSTALL_MANIFEST}"
     "${CMAKE_INSTALL_MANIFEST_CONTENT}")
