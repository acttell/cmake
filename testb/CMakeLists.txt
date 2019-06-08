# CMake最低版本2.8
cmake_minimum_required (VERSION 2.8)
#项目名testb
project (testb)
# 查找当前目录下的所有源文件
# 并将名称保存到 srcs 变量
aux_source_directory(./ srcs)
#生成可执行文件main
add_executable(main ${srcs})
