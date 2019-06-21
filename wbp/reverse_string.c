#include <stdlib.h>
#include <stdio.h>


char *string_reverse(char *string, size_t string_length);
void print_string(char *string, size_t string_length);

char *string_reverse(char *string, size_t string_length) {
    char *new_string;
    int i;
    size_t x;

    new_string = malloc(sizeof(char) * string_length);

    if (new_string == NULL) {
        printf("Malloc failed.");
        exit(1);
    }

    for (i = string_length - 1, x = 0; i > -1; i--, x++) {
        new_string[x] = string[i];
    }

    return new_string;
}

void print_string(char *string, size_t string_length) {
    size_t i;

    for (i = 0; i < string_length; i++) {
        printf("%c", string[i]);
    }

    printf("\n");
}

int main() {
    char string[] = "String";
    size_t string_length = sizeof(string)/sizeof(char);
    char *new_string;

    print_string(string, string_length);

    new_string = string_reverse(string, string_length);

    print_string(new_string, string_length);

    return 0;
}
