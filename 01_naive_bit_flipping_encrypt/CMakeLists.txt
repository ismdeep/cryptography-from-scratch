cmake_minimum_required(VERSION 3.17)

set(CMAKE_C_STANDARD 11)

include_directories("../include")

add_executable(naive_bit_flipping_encrypt naive_bit_flipping_encrypt.c)
