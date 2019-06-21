#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include "stack.h"

//LIFO structure

struct Node *get_new_node(int data);
void free_node_memory(struct Node *node);

struct Node *get_new_node(int data) {
    struct Node *new_node;

    new_node = (struct Node*)malloc(sizeof(struct Node));

    if (new_node == NULL) {
        printf("Malloc failed in get_new_node");
        exit(1);
    }

    new_node -> data = data;
    new_node -> next = NULL;
    return new_node;
};

void free_node_memory(struct Node *node) {
    if (node != NULL) {
        free(node);
        node = NULL;
    }
}

struct Node *add_node(struct Node *head, int data) {
    struct Node *new_node;
    struct Node *temp;

    new_node = get_new_node(data);

    if (head == NULL) {
        head = new_node;
        return head;
    }

    temp = head;

    while (temp -> next != NULL) {
        temp = temp -> next;
    }

    temp -> next = new_node;

    return head;
}

struct Node *remove_from_stack(struct Node *head) {
    struct Node *old;

    if (head == NULL) {
        return head;
    }

    old = head;
    head = head -> next;
    free_node_memory(old);

    return head;
}

void print_stack(struct Node *head) {
    struct Node *temp;

    temp = head;

    while (temp != NULL) {
        printf("%d ", temp -> data);
        temp = temp -> next;
    }

    printf("\n");
}

int main() {
    struct Node *head;

    head = NULL;

    head =add_node(head, 1);
    print_stack(head);

    head = add_node(head, 2);
    print_stack(head);

    head = add_node(head, 3);
    print_stack(head);

    head = remove_from_stack(head);
    print_stack(head);

    return 0;
}
