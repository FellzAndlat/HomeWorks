cmake_minimum_required (VERSION 3.20)

project(HomeWork_4_0)

set(PostgreSQL_ADDITIONAL_VERSIONS "16")

add_executable(HomeWork_4_0 main.cpp)

add_subdirectory("G:/project/Working_with_PostgreSQL_from_C++/libpqxx-7.9.0" libpqxx-build)

target_compile_features(HomeWork_4_0 PRIVATE cxx_std_17)

target_link_libraries(HomeWork_4_0 pqxx)