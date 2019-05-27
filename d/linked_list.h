#include <stdlib.h>
#include <stdio.h>

#ifndef LINKED_LIST_H
#define LINKED_LIST_H

struct Node {
    struct Node *next;
    int value;
    char *key;
};

size_t ll_length(char *list); 
struct Node *node_new(char key[], int value);
void ll_add_node_to_head(struct Node **head, char key[], int value);
void ll_print_list(struct Node *head);
void ll_delete_head_node(struct Node **head);
int ll_get_node_data_by_lookup(struct Node *head, char *key);

#endif
