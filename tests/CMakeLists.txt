cmake_minimum_required(VERSION 3.2.2)

project(evalexptests)

find_package(Threads REQUIRED)

include_directories(./ ../inc)

file(GLOB SOURCES "${CMAKE_CURRENT_SOURCE_DIR}/*.cpp" "${CMAKE_HOME_DIRECTORY}/src/*.cpp")
list(REMOVE_ITEM SOURCES ${CMAKE_HOME_DIRECTORY}/src/main.cpp)

add_executable(evalexptests ${SOURCES})

target_link_libraries(evalexptests
                          gmock
												  gmock_main
												  ${CMAKE_THREAD_LIBS_INIT})

add_test(NAME evalexptests COMMAND $<TARGET_FILE:evalexptests>)

