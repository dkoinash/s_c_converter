cmake_minimum_required(VERSION 3.7)

project(ConverterTests
    VERSION 1.0.0
    LANGUAGES CXX
    DESCRIPTION "Converter Tests"
)

################################################################################
# Library
################################################################################
find_package(GTest REQUIRED)

################################################################################
# Sources
################################################################################
file(GLOB_RECURSE src_cpp ${CMAKE_SOURCE_DIR}/src/*.cpp)
file(GLOB_RECURSE test_cpp *.cpp)
file(GLOB_RECURSE test_h *.h)

add_executable(${PROJECT_NAME} ${test_cpp} ${test_h} ${src_cpp})
# add_test(NAME ${PROJECT_NAME} COMMAND ${PROJECT_NAME})
add_test(NAME ${PROJECT_NAME} COMMAND $<TARGET_FILE:${PROJECT_NAME}>)

target_include_directories(${PROJECT_NAME} PRIVATE
  ${PROJECT_SOURCE_DIR}
  ${PROJECT_BINARY_DIR}
  ${CMAKE_SOURCE_DIR}/include
)
target_link_libraries(${PROJECT_NAME} 
  PRIVATE
    GTest::GTest GTest::Main
)

################################################################################
# Compilation flags
################################################################################
include (${CMAKE_SOURCE_DIR}/cmake/compilation_flags.cmake)

# ################################################################################
# # Resources
# ################################################################################
# set(RESOURCES_DIR ${CMAKE_CURRENT_SOURCE_DIR}/resources)
# file(GLOB files ${RESOURCES_DIR}/*.*)

# foreach(item IN LISTS files)
#   get_filename_component(dest_filename ${item} NAME)

#   add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
#                      COMMAND ${CMAKE_COMMAND} -E copy ${item}
#                              $<TARGET_FILE_DIR:${PROJECT_NAME}>/${dest_filename}
#   )
# endforeach()