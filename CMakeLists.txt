cmake_minimum_required(VERSION 3.7)

if(WIN32 AND DEFINED ENV{VCPKG_ROOT} AND NOT DEFINED CMAKE_TOOLCHAIN_FILE)
  set(CMAKE_TOOLCHAIN_FILE "$ENV{VCPKG_ROOT}/scripts/buildsystems/vcpkg.cmake"
      CACHE STRING "")
endif()

if (CMAKE_VERSION VERSION_LESS "3.8")
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14")
else()
  set(CMAKE_CXX_STANDARD 17)
endif()


project(Converter
    VERSION 1.0.0
    LANGUAGES CXX
    DESCRIPTION "Converter"
)

################################################################################
# Options
################################################################################
option(UTILS_BUILD_TESTS "Build test programs" OFF)

################################################################################
# Sources
################################################################################
set (DIR_INCLUDE ${CMAKE_SOURCE_DIR}/include)
set (DIR_SRC ${CMAKE_SOURCE_DIR}/src)

file(GLOB_RECURSE include_h ${DIR_INCLUDE}/*.h)
file(GLOB_RECURSE src_h ${DIR_SRC}/*.h)
file(GLOB_RECURSE src_cpp ${DIR_SRC}/*.cpp)

################################################################################
# Executable
################################################################################
add_executable(${PROJECT_NAME} ${include_h} ${src_h} ${src_cpp})

target_include_directories(${PROJECT_NAME} PRIVATE
  ${PROJECT_SOURCE_DIR}
  ${PROJECT_BINARY_DIR}
  ${DIR_INCLUDE}
)


################################################################################
# Compilation flags
################################################################################
include (${CMAKE_SOURCE_DIR}/cmake/compilation_flags.cmake)

################################################################################
# Tests
################################################################################
if(UTILS_BUILD_TESTS)
  enable_testing()
  add_subdirectory(tests)
endif()