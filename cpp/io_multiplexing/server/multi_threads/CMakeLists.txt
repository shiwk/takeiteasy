file(GLOB SOURCES  ${CMAKE_CURRENT_SOURCE_DIR}/*.cpp ${CMAKE_CURRENT_SOURCE_DIR}/include/*.hpp)

add_executable(multi_threads_server ${SOURCES})