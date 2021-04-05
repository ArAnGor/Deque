set(target ${MP2_LIBRARY})

file(GLOB header_files "*.h*")
file(GLOB source_files "*.cpp")

add_library(${target} STATIC ${source_files} ${header_files})
target_link_libraries(${target} ${LIBRARY_DEPS})