# 查找当前目录下的所有源文件
# 并将名称保存到 libsrcs 变量
aux_source_directory(. libsrcs)
message("subsrcs: ${libsrcs}")
#生成swap静态链接库
add_library(swaplib ${libsrcs})
