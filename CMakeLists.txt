cmake_minimum_required(VERSION 3.27)
project(brain_example C)

set(CMAKE_C_STANDARD 23)
add_library(linked_list SHARED linked_list.c)
add_library(closures SHARED closures.c)
add_library(testing SHARED test.c)

add_executable(brain_example main.c)
add_dependencies(brain_example linked_list closures testing)
target_link_libraries(brain_example linked_list closures testing)
target_compile_options(brain_example PUBLIC -foptimize-sibling-calls)