add_subdirectory(server)
add_subdirectory(client)
file(GLOB SOURCES  ${CMAKE_CURRENT_SOURCE_DIR}/*.cpp ${CMAKE_CURRENT_SOURCE_DIR}/*.hpp)

add_executable(${my_io} ${SOURCES})