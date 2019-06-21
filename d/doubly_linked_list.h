#include <stdio.h>
#include <stdlib.h>

#ifndef DOUBLY_LINKED_LIST_H
#define DOUBLY_LINKED_LIST_H

struct Node {
    int data;
    struct Node *next;
    struct Node *prev;
};

void dll_insert_at_head(struct Node **node, int data);
void dll_insert_at_position(struct Node **node, int data, int index);
void dll_insert_at_tail(struct Node **head, int data);
void dll_delete_head(struct Node **head);
void dll_delete_tail(struct Node *head);
void dll_delete_at_position(struct Node *head, int position);
void print_dll(struct Node *head);
void reverse_print_dll(struct Node *head);



#endif
