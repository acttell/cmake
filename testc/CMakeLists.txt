#CMake最低版本2.8
cmake_minimum_required (VERSION 2.8)
#项目名testc
project (testc)
# 查找当前目录下的所有源文件
# 并将名称保存到 srcs 变量
aux_source_directory(. srcs)
message(“srcs: ${srcs}”)
#生成可执行文件main
add_executable(main ${srcs})

# 添加 swap 子目录
add_subdirectory(swap)
# 添加链接库
target_link_libraries(main swaplib)
