cmake_minimum_required(VERSION 2.6)

project(readjson)

add_definitions(-std=c++11)



include_directories(${PROJECT_SOURCE_DIR})


#link_directories(/usr/local/cuda/lib64) #连接库文件

add_executable(readjson ${PROJECT_SOURCE_DIR}/Json.cpp
	${PROJECT_SOURCE_DIR}/jsoncpp.cpp
	)

#target_link_libraries(yolo ${OpenCV_LIBS})
#target_link_libraries(yolo /home/ubuntu/soft/TensorRT-8.2.5.1/lib/stubs/libnvonnxparser.so)

