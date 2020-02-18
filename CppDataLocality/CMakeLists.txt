cmake_minimum_required (VERSION 3.13)

find_package(benchmark CONFIG REQUIRED)

add_executable (CppDataLocality "CppDataLocality.cpp")
target_link_libraries(CppDataLocality benchmark::benchmark msvcrt)