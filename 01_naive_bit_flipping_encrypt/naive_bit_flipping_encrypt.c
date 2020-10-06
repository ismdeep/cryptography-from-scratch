//
// Created by Del Cooper on 2020/10/5.
//

#include <stdio.h>
#include <string.h>
#include <byte_util.h>

#define BUF_SIZE 1024*1024

void help_msg() {
    printf("Usage: bit-flipping-encrypt ${source_path} ${destination_path}");
}

void bit_flipping_encrypt(const uint8_t *plain_text, uint8_t *encrypt_text, size_t size) {
    for (size_t i = 0; i < size; i++) {
        encrypt_text[i] = plain_text[i] ^ (uint8_t) 0xff;
    }
}

int main(int argc, char *argv[]) {
    if (argc < 3) {
        help_msg();
        return -1;
    }

    /* Open the FILE. */
    char *source_path = argv[1];
    FILE *source_file = fopen(source_path, "rb");
    if (source_file == NULL) {
        printf("File is not accessible. [%s]\n", source_path);
        return -1;
    }

    char *dest_path = argv[2];
    FILE *dest_file = fopen(dest_path, "wb");
    if (dest_file == NULL) {
        printf("File is not accessible. [%s]\n", dest_path);
        return -1;
    }

    /* Core Fragment Code */
    uint8_t buffer[BUF_SIZE];
    uint8_t encrypt_text[BUF_SIZE];
    size_t read_count;
    while ((read_count = fread(buffer, 1, BUF_SIZE, source_file)) > 0) {
        /* Bit Flipping Encrypt Algorithm, Simple and NAIVE. */
        bit_flipping_encrypt(buffer, encrypt_text, read_count);

        display_byte_as_hex(buffer, read_count);
        display_byte_as_bin(buffer, read_count);

        display_byte_as_hex(encrypt_text, read_count);
        display_byte_as_bin(encrypt_text, read_count);

        fwrite(encrypt_text, read_count, 1, dest_file);
    }

    fclose(source_file);
    fclose(dest_file);
    return 0;
}
