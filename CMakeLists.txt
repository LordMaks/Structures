  
project("structures")

file(GLOB SRC src/*.cpp src/*.cxx *.cxx *.cpp)

if("${CMAKE_SYSTEM}" MATCHES "Windows")
    add_executable(${PROJECT_NAME} ${SRC})
    target_link_libraries(${PROJECT_NAME} ${COMMON_DEPS})
else()
    add_executable(${PROJECT_NAME} ${SRC})
    target_link_libraries(${PROJECT_NAME} ${COMMON_DEPS})
endif()