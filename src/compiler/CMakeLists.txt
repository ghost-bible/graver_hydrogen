aux_source_directory(. SRCS_LIB_COMPILER)
add_library(${lib_compiler_name} SHARED ${SRCS_LIB_COMPILER})

# 指定链接库
target_link_libraries(${lib_compiler_name} PUBLIC
    spdlog::spdlog
    fmt::fmt
)

set_target_properties(${lib_compiler_name} PROPERTIES INSTALL_RPATH "\${ORIGIN}/")

# 设置动态库生成目录
set_target_properties(${lib_compiler_name} PROPERTIES LIBRARY_OUTPUT_DIRECTORY ${lib_dir})
