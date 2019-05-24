#include <stdlib.h>
#include <stdio.h>

#ifndef LINKED_LIST_H
#define LINKED_LIST_H

struct Node {
    struct Node *next;
    int value;
    char *key;
};

size_t length(char list[]); 
struct Node *node_new(char key[], int value);
void add_node_to_head(struct Node **head, char key[], int value);
void print_list(struct Node *head);
void delete_head_node(struct Node **head);

#endif
