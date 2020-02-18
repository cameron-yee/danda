/*
 * Given an unsigned 8-bit integer, swap its even and odd bits. The 1st and 2nd bit should be swapped, the 3rd and 4th bit should be swapped, and so on.
 * For example, 10101010 should be 01010101. 11100010 should be 11010001.
*/

#include <stdlib.h>
#include <stdio.h>

int main(int argc, char *argv[]) {
    char *eight_bit_int;
    size_t length;
    char temp;

    if (argc != 2) {
        printf("Script takes 1 argument.\n");
        exit(1);
    }

    eight_bit_int = argv[1];

    for (length = 0; eight_bit_int[length] != '\0'; ++length);

    printf("%lu\n", length);

    for (size_t i = 0; i < length; i += 2) {
        temp = eight_bit_int[i];
        eight_bit_int[i] = eight_bit_int[i + 1];
        eight_bit_int[i + 1] = temp;
    }

    printf("%s\n", eight_bit_int);

    return 0;
}
