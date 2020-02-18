#include <stdlib.h>
#include <stdio.h>
#include <string.h>

size_t get_hamming_distance(char *one, char *two) {
   size_t check_length, hamming_distance, i;
   
   if (strlen(one) < strlen(two)) {
       check_length = strlen(one);   
       hamming_distance = strlen(two) - strlen(one);
   } else {
       check_length = strlen(two);
       hamming_distance = strlen(one) - strlen(two);
   }

   for (i = 0; i < check_length; i++) {
       if (one[i] != two[i]) {
           hamming_distance++;
       }
   }

   return hamming_distance;
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("Must supply two strings to compare.");
        exit(1);
    }
    
    size_t hamming_distance = get_hamming_distance(argv[1], argv[2]);

    printf("Hemming Distance: %lu\n", hamming_distance);
    
    return 0;
}

