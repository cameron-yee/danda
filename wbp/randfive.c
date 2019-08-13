#include <stdlib.h>
#include <stdio.h>
#include <time.h>

size_t rand7() {
    srand( time(NULL) ); //seeds the random number generator

    return rand() % 8; //range 0-7
}

size_t rand5_gotten_by_7() {
    size_t rand_7;

    rand_7 = rand7();

    if (rand_7 > 0 && rand_7 < 6) {
        return rand_7;
    } else {
        return rand5_gotten_by_7();
    }
}

int main() {
    size_t rand_5;

    rand_5 = rand5_gotten_by_7();

    printf("%lu\n", rand_5);

    return 0;
}
