cmake_minimum_required(VERSION 3.20.0)

project(SearchEngine)

set (CMAKE_CXX_STANDARD 17)

set(INC_DIR "${CMAKE_CURRENT_SOURCE_DIR}/inc")
file(GLOB INC_FILES "${INC_DIR}/*.h")
include_directories(${INC_DIR})

set(SRC_DIR "${CMAKE_CURRENT_SOURCE_DIR}/src")
file(GLOB SRC_FILES "${SRC_DIR}/*.cpp")

find_package(OpenSSL REQUIRED)

include_directories("${CMAKE_CURRENT_SOURCE_DIR}/lib/boost_1_85_0")

if (NOT TARGET pqxx)
add_subdirectory("${CMAKE_CURRENT_SOURCE_DIR}/lib/libpqxx-7.8.1" libpqxx_build)
endif() 

target_link_libraries(${EXECUTABLE} pqxx)
target_link_libraries(${EXECUTABLE} OpenSSL::SSL)

add_subdirectory("${CMAKE_CURRENT_SOURCE_DIR}/spider")
add_subdirectory("${CMAKE_CURRENT_SOURCE_DIR}/server")