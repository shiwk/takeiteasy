add_executable(${my_map} linkmap.cpp linkmap.h main.cpp)

target_include_directories (${my_map} PUBLIC "${CPLUS_INCLUDE_PATH}/cryptopp")
target_link_libraries(${my_map} LINK_PUBLIC "${CPLUS_LIB_PATH}/cryptopp/8.1.0/lib/libcryptopp.a")