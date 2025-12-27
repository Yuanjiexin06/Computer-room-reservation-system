cmake_minimum_required(VERSION 4.2.1)

project(ComputerRoomReservationSystem)

set(CMAKE_CXX_STANDARD 11)

file(GLOB HEADERS "include/*.h")
file(GLOB SOURCES "src/*.cpp")

add_executable(app ${SOURCES} ${HEADERS})

target_include_directories(app PRIVATE include)