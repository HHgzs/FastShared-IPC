cmake_minimum_required(VERSION 3.8)
project(MyLibrary)

# 设置编译选项
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# 设置库名称
set(LIBRARY_NAME fsipc)

# 设置库的版本号
set(LIBRARY_VERSION 1.0)

# 设置库的源文件，使用GLOB_RECURSE命令递归查找
file(GLOB_RECURSE
    SOURCES
        ${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp
)

# 添加库的头文件路径
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include/fsipc)

# 编译生成动态链接库
add_library(${LIBRARY_NAME} SHARED ${SOURCES})

# 设置动态链接库的输出路径
set_target_properties(${LIBRARY_NAME} PROPERTIES
    LIBRARY_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/lib
)

# 设置动态链接库的版本号
set_target_properties(${LIBRARY_NAME} PROPERTIES VERSION ${LIBRARY_VERSION})

# 链接其他库
# target_link_libraries(fsipc PRIVATE OtherLibrary)



# 设置动态链接库的安装路径
install(TARGETS ${LIBRARY_NAME}
    LIBRARY DESTINATION lib
    ARCHIVE DESTINATION lib
    RUNTIME DESTINATION bin
)


# 设置头文件的安装路径
install(FILES include/fsipc.h
    DESTINATION include
)

# 导出目标，用于在外部项目中使用find_package命令查找库
export(TARGETS fsipc
    FILE fsipcTargets.cmake
)

# 设置Config.cmake文件的安装路径
set(ConfigPackageLocation lib/cmake/fsipc)


# 根据模板生成Config.cmake文件
configure_file(Config.cmake.in 
    ${CMAKE_CURRENT_BINARY_DIR}/fsipcConfig.cmake @ONLY
)

# 安装Config.cmake文件
install(FILES ${CMAKE_CURRENT_BINARY_DIR}/fsipcConfig.cmake
    DESTINATION ${ConfigPackageLocation}
)

