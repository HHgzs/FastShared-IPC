# 获取安装目录
get_target_property(MyLibrary_LOCATION MyLibrary LOCATION)

# 删除动态链接库文件
file(REMOVE "${MyLibrary_LOCATION}")

# 删除安装的头文件
file(REMOVE_RECURSE "${CMAKE_INSTALL_PREFIX}/include")

# 输出卸载完成消息
message(STATUS "Uninstall complete")