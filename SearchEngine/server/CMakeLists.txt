cmake_minimum_required(VERSION 3.20.0)

project(Server)

set (CMAKE_CXX_STANDARD 17)

set(EXECUTABLE ${PROJECT_NAME})

set(INC_DIR "${CMAKE_CURRENT_SOURCE_DIR}/../inc")
file(GLOB INC_FILES "${INC_DIR}/*.h")
include_directories(${INC_DIR})

set(SRC_DIR "${CMAKE_CURRENT_SOURCE_DIR}/../src")
file(GLOB SRC_FILES "${SRC_DIR}/*.cpp")

if (NOT TARGET pqxx)
add_subdirectory("${CMAKE_CURRENT_SOURCE_DIR}/../lib/libpqxx-7.8.1" libpqxx_build)
endif() 

add_executable(${EXECUTABLE} ${SRC_FILES} main.cpp)

target_link_libraries(${EXECUTABLE} pqxx)
target_link_libraries(${EXECUTABLE} OpenSSL::SSL)

add_custom_command(
        TARGET Server POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy
                "${CMAKE_CURRENT_SOURCE_DIR}/../config.ini"
                "${CMAKE_CURRENT_BINARY_DIR}/config.ini"
)