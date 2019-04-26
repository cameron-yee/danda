//TODO
//1. Check if malloc returns NULL
//2. Set head global variable as function parameter
//    *Need to be able to mutate head somehow
//3. Declare all functions at top of file before setting

#include <stdio.h>
#include <stdlib.h>
#include "doubly_linked_list.h"

int main() {
    struct Node* head;
    struct Node* head_two;

    //head = NULL;
    //head_two = NULL;
    head = node_new(1);
    head_two = node_new(2);

    printf("insert_at_head(1)\n");
    insert_at_head(&head, 1);
    print(head);
    reverse_print(head);
    printf("\n");

    printf("insert_at_head(2)\n");
    insert_at_head(&head, 2);
    print(head);
    reverse_print(head);
    printf("\n");

    printf("insert_at_head(3)\n");
    insert_at_head(&head, 3);
    print(head);
    reverse_print(head);
    printf("\n");

    printf("2. insert_at_head(19)\n");
    insert_at_head(&head_two, 19);
    print(head_two);
    reverse_print(head_two);
    printf("\n");

    printf("2. insert_at_head(28)\n");
    insert_at_head(&head_two, 28);
    print(head_two);
    reverse_print(head_two);
    printf("\n");

    printf("insert_at_tail(7)\n");
    insert_at_tail(&head, 7);
    print(head);
    reverse_print(head);
    printf("\n");

    printf("insert_at_head(4)\n");
    insert_at_head(&head, 4);
    print(head);
    reverse_print(head);
    printf("\n");

    printf("delete_tail()\n");
    delete_tail(head);
    print(head);
    reverse_print(head);
    printf("\n");

    printf("delete_head()\n");
    delete_head(&head);
    print(head);
    reverse_print(head);
    printf("\n");

    printf("insert_at_position(19, 1)\n");
    insert_at_position(&head, 19, 1);
    print(head);
    reverse_print(head);
    printf("\n");

    printf("insert_at_head(5)\n");
    insert_at_head(&head, 5);
    print(head);
    reverse_print(head);
    printf("\n");

    printf("delete_at_position(2)\n");
    delete_at_position(head, 2);
    print(head);
    reverse_print(head);
    printf("\n");

    return 0;
}
