cmake_minimum_required(VERSION 3.15)
project(FastShared-IPC)


set(CMAKE_CXX_STANDARD 20)
set(CMAKE_BUILD_TYPE DEBUG)
add_compile_options(-g -O0 -w -fno-omit-frame-pointer -Wno-notes)

# set(CMAKE_BUILD_TYPE RELEASE)
# add_compile_options(-w -O3)

add_library(
    fsipc
        SHARED
)
target_sources(
    fsipc
        PRIVATE
        ${CMAKE_SOURCE_DIR}/src/fsipc.cpp
)
target_include_directories(
    fsipc
        PRIVATE
        $<BUILD_INTERFACE:${CMAKE_SOURCE_DIR}/include>
        $<INSTALL_INTERFACE:include/fsipc>
)


# 安装
install(
    TARGETS
        fsipc
    EXPORT
        FSIPCTarget
    RUNTIME DESTINATION
        bin
    LIBRARY DESTINATION
        lib
    ARCHIVE DESTINATION
        lib
)

install(
    DIRECTORY
        ${CMAKE_SOURCE_DIR}/include/
    DESTINATION 
        include/fsipc
)

install(
    EXPORT
        FSIPCTarget
    NAMESPACE
        fsipc::
    DESTINATION
        lib/cmake/fsipc
)

include(CMakePackageConfigHelpers)

configure_package_config_file(
    ${CMAKE_SOURCE_DIR}/cmake/FSIPCConfig.cmake.in
    ${CMAKE_CURRENT_BINARY_DIR}/FSIPCConfig.cmake
    INSTALL_DESTINATION
        lib/cmake/fsipc
)

install(
    FILES
        ${CMAKE_CURRENT_BINARY_DIR}/FSIPCConfig.cmake
    DESTINATION
        lib/cmake/fsipc
)

