#include <stdlib.h>
#include <stdio.h>
#include "linked_list.h"

int main() {
    struct Node* head;
    char key[] = "Cameron";
    char key2[] = "World";

    head = node_new(key, 1);

    add_node_to_head(&head, key2, 0);

    print_list(head);

    delete_head_node(&head);

    print_list(head);

    return 0;
}
