cmake_minimum_required(VERSION 2.8)

project(Marcha)

find_package(OpenGL REQUIRED)
find_package(GLUT REQUIRED)

if(PROJECT_BINARY_DIR STREQUAL ${PROJECT_SOURCE_DIR})
  message(FATAL_ERROR "Building in the source tree is not allowed")
endif(PROJECT_BINARY_DIR STREQUAL ${PROJECT_SOURCE_DIR})

set(CMAKE_CXX_STANDARD 11)
set(EXECUTABLE_OUTPUT_PATH ${PROJECT_BINARY_DIR})
set(LIBRARY_OUTPUT_PATH ${PROJECT_BINARY_DIR})
mark_as_advanced(
  CMAKE_BACKWARDS_COMPATIBILITY
  EXECUTABLE_OUTPUT_PATH
  LIBRARY_OUTPUT_PATH
  )

include_directories(${OPENGL_INCLUDE_DIRS} ${GLUT_INCLUDE_DIRS})

add_executable(run.exe main.cxx)

target_link_libraries(run.exe ${OPENGL_LIBRARIES} ${GLUT_LIBRARIES})
