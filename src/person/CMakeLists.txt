aux_source_directory(. SRCS_LIB_PERSON)
add_library(${lib_person_name} SHARED ${SRCS_LIB_PERSON})

# 设置动态库生成目录
set_target_properties(${lib_person_name} PROPERTIES LIBRARY_OUTPUT_DIRECTORY ${lib_dir})
