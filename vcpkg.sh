#!/bin/bash

script_path=$(readlink -f "$0")
script_dir=$(dirname "$script_path")
vcpkg_path=${script_dir}/vcpkg

echo "删除 vcpkg"
rm -rf ${script_dir}/vcpkg
rm -rf ${script_dir}/vcpkg_installed

echo "安装 vcpkg"
# cd ${script_dir} && git clone https://github.com/Microsoft/vcpkg.git
cd ${script_dir} && git clone git@gitee.com:mirrors/vcpkg.git
cd ${vcpkg_path} && sh bootstrap-vcpkg.sh

export PATH=${vcpkg_path}:$PATH
vcpkg x-update-baseline --add-initial-baseline
vcpkg install --triplet=x64-linux-dynamic

# echo "安装 fmt"
# cd ${vcpkg_path} && ${vcpkg_path}/vcpkg install fmt:x64-linux-dynamic

# echo "安装 spdlog"
# cd ${vcpkg_path} && ${vcpkg_path}/vcpkg install spdlog:x64-linux-dynamic

# echo "安装 gmp"
# cd ${vcpkg_path} && ${vcpkg_path}/vcpkg install gmp:x64-linux-dynamic

echo "已安装的库"
vcpkg list
