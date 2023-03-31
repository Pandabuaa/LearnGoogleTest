# cmake的最小版本号，设置项目的cmake最低要求版本
cmake_minimum_required(VERSION 3.12) 

# 项目名称
project(learngtest)


set(GTEST_DIR ".\\googletest")
find_library(gtest gtest HINTS "${GTEST_DIR}\\build\\lib\\Debug" required)
find_library(gtest_main gtest_main HINTS "${GTEST_DIR}\\build\\lib\\Debug" required)
find_library(gmock gmock HINTS "${GTEST_DIR}\\build\\lib\\Debug" required)
find_library(gmock_main gmock_main HINTS "${GTEST_DIR}\\build\\lib\\Debug" required)
set(googletest ${gtest} ${gtest_main} ${gmock} ${gmock_main})

include_directories("${GTEST_DIR}\\googletest\\include")
include_directories("${GTEST_DIR}\\googlemock\\include")

aux_source_directory(. ALL_SRCS)
add_executable(mytest ${ALL_SRCS})

target_link_libraries(mytest ${googletest})


