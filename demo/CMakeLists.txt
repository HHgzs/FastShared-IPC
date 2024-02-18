cmake_minimum_required(VERSION 3.15)
project(FSIPC-DEMO)

set(CMAKE_CXX_STANDARD 14)

find_package(FSIPC REQUIRED)

include_directories(${FSIPC_INCLUDE_DIRS})

add_executable(send send.cpp)
target_link_libraries(send ${FSIPC_LIBS})

add_executable(receive receive.cpp)
target_link_libraries(receive ${FSIPC_LIBS})