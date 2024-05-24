# 指定 cmake 最小版本, 意指 cmake 版本小于指定版本则构建过程终止
cmake_minimum_required(VERSION 3.26)

# 语言环境配置 ###########################################################################################################

# 语言版本
set(CMAKE_CXX_STANDARD 14)

# 如果指定的语言版本不受支持, 则构建过程终止
set(CMAKE_CXX_STANDARD_REQUIRED True)

# 只弃用 ISO C++ 标准的编译器标志, 而不使用特定编译器的扩展
set(CMAKE_CXX_EXTENSIONS OFF)

# 将 install_rpath 的设置应用在 build_rpath 上
# 避免在开发期间出现动态库找不到的问题
set(CMAKE_BUILD_WITH_INSTALL_RPATH True)

# 项目配置 ##############################################################################################################

# 项目名称和语言
project(graver LANGUAGES CXX VERSION 1.0.0)

# 发布目录
set(dist_dir ${CMAKE_BINARY_DIR}/dist)

# 二进制文件目录
set(bin_dir ${dist_dir}/bin)
file(MAKE_DIRECTORY ${bin_dir})

# 库文件目录
set(lib_dir ${dist_dir}/lib)
file(MAKE_DIRECTORY ${lib_dir})

# 内部库

# 工具类库
set(lib_util_name util)

# 编译器
set(lib_compiler_name compiler)

# vcpkg find package ###################################################################################################
# fmt 库
find_package(fmt CONFIG REQUIRED)
get_target_property(fmt_LOCATION fmt::fmt LOCATION)
get_filename_component(fmt_DIRECTORY ${fmt_LOCATION} DIRECTORY)

if(CMAKE_BUILD_TYPE STREQUAL "Release")
    string(REPLACE "debug/" "" fmt_DIRECTORY ${fmt_DIRECTORY})
endif()

message(STATUS "fmt_DIRECTORY:${fmt_DIRECTORY}")

# spdlog 库
find_package(spdlog CONFIG REQUIRED)
get_target_property(spdlog_LOCATION spdlog::spdlog LOCATION)
get_filename_component(spdlog_DIRECTORY ${spdlog_LOCATION} DIRECTORY)

if(CMAKE_BUILD_TYPE STREQUAL "Release")
    string(REPLACE "debug/" "" spdlog_DIRECTORY ${spdlog_DIRECTORY})
endif()

message(STATUS "spdlog_DIRECTORY:${spdlog_DIRECTORY}")

# 编译相关配置 ###########################################################################################################

# 复制脚本文件
configure_file(${CMAKE_SOURCE_DIR}/example/test.graver ${bin_dir}/)

# 生成 compile_commands.json
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# 包含全局头文件
include_directories(${PROJECT_SOURCE_DIR}/include)

# 添加子目录
add_subdirectory(src)

# 启用测试 ##############################################################################################################
enable_testing()
add_subdirectory(test)
