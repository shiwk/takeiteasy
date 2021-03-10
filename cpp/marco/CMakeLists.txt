file(GLOB SOURCES  ${CMAKE_CURRENT_SOURCE_DIR}/*.cpp ${CMAKE_CURRENT_SOURCE_DIR}/*.hpp)
#add_compile_options(-fno-elide-constructors)

add_executable(${my_marco} ${SOURCES})