part1
代码  https://github.com/acttell/cmake/tree/master/test
一个目录test，一个文件main.cpp
目录结构：
# tree test
test
├── CMakeLists.txt
└── main.cpp

//main.cpp
#include<iostream>
using namespace std;
void swap(int& i,int& j)
{
    int t=i;
    i=j;
    j=t;
}
int main()
{
    int i=1;
    int j=2;
    swap(i,j);
    cout<<i<<" "<<j<<endl;
    return 0;
}

执行
g++ main.cpp -o main
./main
输出
2 1
----------------------------
#CMakeLists.txt
# CMake最低版本2.8
cmake_minimum_required (VERSION 2.8)
#项目名test
project (test)
#生成可执行文件main
add_executable(main main.cpp)

在test目录里执行
cmake CMakeLists.txt
make
./main
输出
2 1
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
part2
代码 https://github.com/acttell/cmake/tree/master/testb
一个目录testb,多个文件（拆解part1 main.cpp）
# tree testb
testb
├── CMakeLists.txt
├── main.cpp
├── swap.cpp
└── swap.h

//swap.h
#ifndef SWAP_H
#define SWAP_H
void swap(int& i,int& j); 
#endif

//swap.cc
#include"swap.h"
void swap(int& i,int& j)
{
    int t=i;
    i=j;
    j=t;
}

//main.cpp
#include<iostream>
#include"swap.h"
using namespace std;
int main()
{
    int i=1;
    int j=2;
    swap(i,j);
    cout<<i<<" "<<j<<endl;
    return 0;
}

执行：
g++ -c swap.cpp
g++ -c main.cpp
g++ swap.o main.o -o main
 ./main 
2 1

#编写CMakeLists.txt
# CMake最低版本2.8
cmake_minimum_required (VERSION 2.8)
#项目名testb
project (testb)
#生成可执行文件main
add_executable(main main.cpp swap.cpp)

唯一的改动只是在 add_executable 命令中增加swap.cpp，
文件多时，通用方法是使用
aux_source_directory 查找指定目录下的所有源文件，
然后将结果存进指定变量名。其语法如下：
aux_source_directory(<dir> <variable>)
可以修改 CMakeLists.txt 如下：

# CMake最低版本2.8
cmake_minimum_required (VERSION 2.8)
#项目名testb
project (testb)
# 查找当前目录下的所有源文件
# 并将名称保存到 srcs 变量
aux_source_directory(./ srcs)
#生成可执行文件main
add_executable(main ${srcs})
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
part3 
多个目录  https://github.com/acttell/cmake/blob/master/testc/
# tree testc
testc
├── CMakeLists.txt
├── main.cpp
└── swap
    ├── CMakeLists.txt
    ├── swap.cpp
    └── swap.h

swap目录下：
g++ -c swap.cpp
ar -cr libswap.a swap.o
生成静态库文件libswap.a,移动到testc目录，然后到在estc目录下：
g++ -c main.cpp
g++ main.o -o main -L. -lswap
./main
2 1
当然可以用动态库
g++ -shared -fPCI -o libswap.so swap.o
g++ main.o -o main -L. -lswap

cmake写两个文件，
可以先将 swap 目录里的文件编译成静态库再由 main 函数调用。
#子目录swap 
# 查找当前目录下的所有源文件
# 并将名称保存到 libsrcs 变量
aux_source_directory(. libsrcs)
message("subsrcs: ${libsrcs}")
#生成swap静态链接库
add_library(swaplib ${libsrcs})

命令 add_library 将 swap 目录中的源文件编译为静态链接库


#根目录testc CMakeLists.txt:
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

add_subdirectory 指明本项目包含一个子目录 swap，
target_link_libraries 指明 连接 swaplib静态库 
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
part 4   https://github.com/acttell/cmake/tree/master/testd
分成include和swap文件夹
先在swap下生成libswap.a
g++ -c swap.cpp -I ../include
ar -cr libswap.a swap.o

#CMakeLists.txt
cmake_minimum_required(VERSION 2.8)
include_directories(${PROJECT_SOURCE_DIR}/include)
message("${PROJECT_SOURCE_DIR}")
find_library(libs libswap.a ${PROJECT_SOURCE_DIR}/swap)
message("${libs}")
#生成可执行文件main
add_executable(main main.cpp)
target_link_libraries(main ${libs})

