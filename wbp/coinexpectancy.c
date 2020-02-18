/*
 * You have n fair coins and you flip them all at the same time. Any that come up tails you set aside.
 * The ones that come up heads you flip again. How many rounds do you expect to play before only one coin remains?
 * Write a function that, given n, returns the number of rounds you'd expect to play until one coin remains.
*/ 

#include <stdlib.h>
#include <stdio.h>

int main(int argc, char *argv[]) {
    size_t is_tails;
    size_t heads_remaining;
    size_t count;

    heads_remaining = atoi(argv[1]);

    if (heads_remaining == 0) {
        printf("Argument must be an Int\n");
        exit(1);
    }

    for (count = 0; heads_remaining > 1; count++) {
        for (size_t i = 0; i < heads_remaining; i++) {
            is_tails = rand() % (1 + 1 - 0) + 0;

            if (is_tails == 0) {
                heads_remaining = heads_remaining - 1;    
            }
        }
    }

    printf("%lu\n", count);
    return 0;
}
