add_subdirectory(server/single_thread)
add_subdirectory(server/multi_threads)
add_subdirectory(client)
file(GLOB SOURCES  ${CMAKE_CURRENT_SOURCE_DIR}/*.cpp ${CMAKE_CURRENT_SOURCE_DIR}/*.hpp)

add_executable(${my_io} ${SOURCES})