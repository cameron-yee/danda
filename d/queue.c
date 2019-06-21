#include<stdio.h>
#include<stdlib.h>
#include "queue.h"

struct Node *node_new(int data);
int queue_get_head_data(struct Node **head);
void node_delete(struct Node *node); 


void node_delete(struct Node *node) {
    if (node != NULL) {
        free(node);
        node = NULL;
    }
}

struct Node *node_new(int data) {
    struct Node *new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->data = data;
    new_node->next = NULL;
    return new_node;
};

int queue_is_empty(struct Node **head) {
    return head == NULL;
}

int queue_get_head_data(struct Node **head) {
    if (head != NULL) {
        return (*head)->data;
    } else {
        return -1;
    }
}

void queue_add_node(struct Node **head, struct Node **tail, int data) {
    struct Node *new_node;

    new_node = node_new(data);

    if (tail != NULL) {
        (*tail)->next = new_node;
    }

    *tail = new_node;
    if(head == NULL) {
        *head = new_node;
    }
}

int queue_remove_head(struct Node **head, struct Node **tail) {
    int data;
    struct Node *old;

    data = (*head)->data;
    old = *head;
    *head = (*head)->next;
    node_delete(old);

    if (head == NULL) {
        *tail = NULL;
    }

    return data;
}

void print_queue(struct Node **head) {
    struct Node *temp;

    temp = *head;

    while (temp->next != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }

    printf("\n");
}

int main() {
    struct Node *head;
    struct Node *tail;

    head = node_new(1);
    tail = head;

    queue_add_node(&head, &tail, 1);
    queue_add_node(&head, &tail, 2);
    queue_add_node(&head, &tail, 3);

    print_queue(&head);

    queue_remove_head(&head, &tail);

    print_queue(&head);

    int head_data = queue_get_head_data(&head);
    printf("headData: %d\n", head_data);

    return 0;
}
