#include <stdlib.h>
#include <stdio.h>

#ifndef QUEUE_H
#define QUEUE_H

struct Node {
    int data;
    struct Node* next;
};

void queue_add_node(struct Node **head, struct Node **tail, int data);
int queue_remove_head(struct Node **head, struct Node **tail); 
void print_queue(struct Node **head);
int queue_is_empty(struct Node **head);

#endif
