//
// Created by Del Cooper on 2020/10/6.
//

#ifndef CRYPTOGRAPHY_FROM_SCRATCH_BYTE_UTIL_H
#define CRYPTOGRAPHY_FROM_SCRATCH_BYTE_UTIL_H

#include <stdint.h>
#include <stdio.h>

void byte_to_bin_str(uint8_t byte, char ans[]) {
    memset(ans, 0, sizeof(char) * 9);
    for (size_t i = 0; i < 8; i++) {
        ans[8 - i - 1] = (size_t) byte >> i & (size_t) 1 ? '1' : '0';
    }
}

void display_byte_as_hex(uint8_t *buf, size_t size) {
    for (size_t i = 0; i < size; i++) {
        printf("%02X ", buf[i]);
    }
    printf("\n");
}

void display_byte_as_bin(uint8_t *buf, size_t size) {
    char tmp[9];
    for (size_t i = 0; i < size; i++) {
        byte_to_bin_str(buf[i], tmp);
        printf("%s ", tmp);
    }
    printf("\n");
}

#endif //CRYPTOGRAPHY_FROM_SCRATCH_BYTE_UTIL_H
