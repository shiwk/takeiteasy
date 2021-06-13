file(GLOB SOURCES  ${CMAKE_CURRENT_SOURCE_DIR}/*.cpp ${CMAKE_CURRENT_SOURCE_DIR}/*.hpp ${CMAKE_CURRENT_SOURCE_DIR}/../include/*.hpp)
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/../include)

add_executable(my_server ${SOURCES})