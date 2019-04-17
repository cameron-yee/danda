#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>


struct Node {
    int data;
    struct Node* next;
};

struct Node* node_new(int data) {
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->data = data;
    new_node->next = NULL;
    return new_node;
};

bool IsEmpty(struct Node** head) {
    return head == NULL;
}

int peek(struct Node** head) {
    if(head != NULL) {
        return (*head)->data;
    } else {
        return -1;
    }
}

void add(struct Node** head, struct Node** tail, int data) {
    struct Node* new_node = node_new(data);

    if(tail != NULL) {
        (*tail)->next = new_node;
    }

    *tail = new_node;
    if(head == NULL) {
        *head = new_node;
    }
}

int removeHead(struct Node** head, struct Node** tail) {
    int data = (*head)->data;
    struct Node* old = *head;
    *head = (*head)->next;
    free(old);

    if(head == NULL) {
        *tail = NULL;
    }

    return data;
}

void printQueue(struct Node** head) {
    struct Node* temp = *head;

    while(temp->next != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }

    printf("\n");
}

int main() {
    struct Node* head;
    struct Node* tail;

    head = node_new(1);
    tail = head;

    add(&head, &tail, 1);
    add(&head, &tail, 2);
    add(&head, &tail, 3);

    printQueue(&head);

    removeHead(&head, &tail);

    printQueue(&head);

    int headData = peek(&head);
    printf("headData: %d", headData);

    return 0;
}
