#include <stdlib.h>
#include <stdio.h>

#ifndef STACK_H
#define STACK_H

struct Node {
    struct Node *next;
    int data;
};

struct Node *add_node(struct Node *head, int data);
struct Node *remove_from_stack(struct Node *head);
void print_stack(struct Node *head);

#endif
