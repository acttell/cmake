cmake_minimum_required(VERSION 2.8)
include_directories(${PROJECT_SOURCE_DIR}/include)
message("${PROJECT_SOURCE_DIR}")
find_library(libs libswap.a ${PROJECT_SOURCE_DIR}/swap)
message("${libs}")
#生成可执行文件main
add_executable(main main.cpp)
#依赖静态库swaplib
target_link_libraries(main ${libs})
