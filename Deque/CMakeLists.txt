set(target ${MP2_LIBRARY})

file(GLOB header_files "*.h*")
file(GLOB source_files "*.cpp")

add_executable(${target} ${source_files} ${header_files})