cmake_minimum_required(VERSION 3.17)
project(cryptography_from_scratch C)

add_subdirectory(01_naive_bit_flipping_encrypt)

set(CMAKE_C_STANDARD 11)

add_executable(cryptography_from_scratch main.c)