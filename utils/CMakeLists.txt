cmake_minimum_required(VERSION 3.0)

project(CameraTest)
set(Tutorial_VERSION_MAJOR 1)
set(Tutorial_VERSION_MINOR 0)

#------------------------------------------------------
# Build type
#------------------------------------------------------

IF(NOT CMAKE_BUILD_TYPE )
   SET( CMAKE_BUILD_TYPE "Release" )
ENDIF()

#------------------------------------------------------
# Lib Names and Dirs
#------------------------------------------------------

    # Postfix of so's:
set(PROJECT_DLLVERSION)
SET(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} ${CMAKE_INSTALL_PREFIX}/lib/cmake/ /usr/lib/cmake)

OPTION(BUILD_SHARED_LIBS 	"Set to OFF to build static libraries" ON)
OPTION(BUILD_UTILS 	"Acitvates/Deactivates building utils  libraries" ON)

# ----------------------------------------------------------------------------
#   Find Dependencies
# ----------------------------------------------------------------------------
 #Add include to dependencies dir
include_directories(${PROJECT_SOURCE_DIR}/dependencies/current  ${PROJECT_SOURCE_DIR}/dependencies/current/interface ${PROJECT_SOURCE_DIR}/dependencies/current/interface/mmal   )
#find the mmal libraries(I use conditional because I normally comile in pc)

if(${CMAKE_SYSTEM_PROCESSOR} MATCHES arm*) 
FIND_LIBRARY(mmalcore_LIBS NAMES mmal_core PATHS /opt/vc/lib)
FIND_LIBRARY(mmalutil_LIBS NAMES mmal_util PATHS /opt/vc/lib)
FIND_LIBRARY(mmal_LIBS NAMES mmal PATHS /opt/vc/lib)
IF( (NOT mmal_LIBS ) OR (NOT mmalutil_LIBS) OR (NOT mmalcore_LIBS) )
    MESSAGE(FATAL_ERROR "Could not find mmal libraries")
 ENDIF()
 set(REQUIRED_LIBRARIES ${REQUIRED_LIBRARIES} ${mmalcore_LIBS} ${mmalutil_LIBS} ${mmal_LIBS}  )
ENDIF()




#If opencv installed, creates the libraspicam_cv library module
FIND_PACKAGE(OpenCV)
IF(OpenCV_FOUND)
  include_directories(${OpenCV_INCLUDE_DIRS})
  SET(LIB_COMPONENTS ${LIB_COMPONENTS} ${PROJECT_NAME}_cv)
  SET(PROJECT_CV_CREATED_FLAG "YES")  
ENDIF()

INCLUDE_DIRECTORIES(${PROJECT_SOURCE_DIR}/src)
LINK_LIBRARIES(${PROJECT_NAME} )

 
ADD_EXECUTABLE(raspicam_test raspicam_test.cpp )
INSTALL(TARGETS raspicam_test   RUNTIME DESTINATION bin)
 
ADD_EXECUTABLE(raspicam_still_test raspicam_still_test.cpp )
INSTALL(TARGETS raspicam_still_test   RUNTIME DESTINATION bin)

IF (OpenCV_FOUND)
ADD_EXECUTABLE(raspicam_cv_test raspicam_cv_test.cpp )
target_link_libraries(raspicam_cv_test  ${PROJECT_NAME}_cv)
ADD_EXECUTABLE(raspicam_cv_still_test raspicam_cv_still_test.cpp )
target_link_libraries(raspicam_cv_still_test ${PROJECT_NAME}_cv)
INSTALL(TARGETS raspicam_cv_test  raspicam_cv_still_test RUNTIME DESTINATION bin)

ENDIF()
