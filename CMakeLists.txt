cmake_minimum_required(VERSION 4.2.1)

project(ComputerRoomReservationSystem)

set(CMAKE_CXX_STANDARD 11)

file(GLOB HEADERS "include/*.h")
file(GLOB SOURCES "src/*.cpp")

add_executable(app ${SOURCES} ${HEADERS})

target_include_directories(app PRIVATE include)

# 【新增】定义所有需要用到的数据文件
# 假设你把 txt 文件放在了项目根目录下的 data 文件夹里
set(DATA_FILES
    data/admin.txt
    data/teacher.txt
    data/student.txt
    data/order.txt
    data/computerRoom.txt
)

# 【新增】将这些文件拷贝到可执行文件所在的目录
# CMAKE_CURRENT_SOURCE_DIR 指的是 CMakeLists.txt 所在的目录
# CMAKE_CURRENT_BINARY_DIR 指的是 build 目录
foreach(FILE ${DATA_FILES})
    # 为了保持文件在 build 里也是平铺的（不在 data 子文件夹里），我们要取文件名
    get_filename_component(FILENAME ${FILE} NAME)
    
    # 配置拷贝指令：如果源文件比目标文件新，就拷贝
    configure_file(
        ${CMAKE_CURRENT_SOURCE_DIR}/${FILE}
        ${CMAKE_CURRENT_BINARY_DIR}/${FILENAME}
        COPYONLY
    )
endforeach()