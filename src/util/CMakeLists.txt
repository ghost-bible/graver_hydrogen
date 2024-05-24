aux_source_directory(. SRCS_LIB_UTIL)
add_library(${lib_util_name} SHARED ${SRCS_LIB_UTIL})

# 指定链接库
target_link_libraries(${lib_util_name} PUBLIC
    spdlog::spdlog
)

set_target_properties(${lib_util_name} PROPERTIES INSTALL_RPATH "\${ORIGIN}/")

# 设置动态库生成目录
set_target_properties(${lib_util_name} PROPERTIES LIBRARY_OUTPUT_DIRECTORY ${lib_dir})
