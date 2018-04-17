cmake_minimum_required (VERSION 2.8)
project(Track_Lab)

find_package(OpenGL REQUIRED)
find_package(GLUT REQUIRED)
SET(CMAKE_CXX_STANDARD 11)

if(PROJECT_BINARY_DIR STREQUAL ${PROJECT_SOURCE_DIR})
  message(FATAL_ERROR "Building in the source tree is not allowed")
endif(PROJECT_BINARY_DIR STREQUAL ${PROJECT_SOURCE_DIR})

# the search paths
include_directories(${OPENGL_INCLUDE_DIRS} ${GLUT_INCLUDE_DIRS})
include_directories(${PROJECT_SOURCE_DIR}/include/)

add_executable(track_lab ${PROJECT_SOURCE_DIR}/src/main.cxx ${PROJECT_SOURCE_DIR}/src/track_lab.cxx)
target_link_libraries(track_lab ${OPENGL_LIBRARIES} ${GLUT_LIBRARIES})
