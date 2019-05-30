#include <stdio.h>
#include <stdlib.h>

#ifndef DOUBLY_LINKED_LIST_H
#define DOUBLY_LINKED_LIST_H

struct Node {
    int data;
    struct Node *next;
    struct Node *prev;
};

void node_delete(struct Node *node);
void insert_at_head(struct Node **node, int data);
void insert_at_position(struct Node **node, int data, int index);
void insert_at_tail(struct Node **head, int data);
void delete_head(struct Node **head);
void delete_tail(struct Node *head);
void delete_at_position(struct Node *head, int position);
void print(struct Node *head);
void reverse_print(struct Node *head);


struct Node *node_new(int data) {
    struct Node *new_node;

    new_node = (struct Node*)malloc(sizeof(struct Node)); //malloc allocates memory on the heap so the data will persist

    if (new_node == NULL) {
        printf("Error in malloc.");
        exit(1);
    }

    new_node->data = data;
    new_node->prev = NULL;
    new_node->next = NULL;
    return new_node;
};

void node_delete(struct Node *node) {
    if(node != NULL) {
        free(node);
        node = NULL;
    }
}

void insert_at_head(struct Node **head, int data) {
    struct Node *new_node;

    new_node = node_new(data);

    if (head == NULL) {
        *head = new_node;
        return;
    }

    (*head)->prev = new_node; //(head*).prev = NewNode    //Reference to head = New Node
    new_node->next = *head;
    (*head) = new_node;
    //return head;
}

void insert_at_position(struct Node **head, int data, int index) {
    struct Node *temp, *new_node;
    int current_position; 

    temp = (*head);

    if(index == 0) {
        //head = insert_at_head(head, data);
        insert_at_head(head, data);
        return;
    }

    current_position = 0;
    while(temp->next != NULL) {
        if(current_position == index) {
            new_node = node_new(data);
            new_node->prev = temp->prev;
            new_node->prev->next = new_node;
            new_node->next = temp;
            temp->prev = new_node;
            if(index == 1) {
                *head = new_node->prev; 
                return;
            }
        }

        current_position++;
        temp = temp->next;
    }

    printf("Index out of range.");
}

void insert_at_tail(struct Node **head, int data) {
    struct Node *new_node;
    struct Node *temp;

    new_node = node_new(data);
    temp = (*head);

    if(head == NULL) {
        *head = new_node;
        return;
    }


    while(temp->next != NULL) {
        temp = temp->next;
    }

    temp->next = new_node; //(head*).prev = NewNode
    new_node->prev = temp;
}

void delete_head(struct Node** head) {
    struct Node* old_head;
    struct Node* new_head;

    if(head == NULL) {
        return;
    }

    old_head = (*head);
    new_head = old_head->next;

    new_head->prev = NULL;
    *head = new_head;
    node_delete(old_head);
}

void delete_tail(struct Node *head) {
    struct Node *temp;
    temp = head;

    while(temp->next != NULL) {
        temp = temp->next;
    }

    temp = temp->prev;
    temp->next = NULL;
    node_delete(temp->next);
}

void delete_at_position(struct Node *head, int position) {
    struct Node *temp, *new_next;
    int current_position;

    temp = head;
    current_position = 0;

    while(temp->next != NULL && current_position < position) {
        temp = temp->next;
        current_position++;
    }

    if(temp->next == NULL && current_position == position) {
        node_delete(temp);
        return;
    } else if(current_position == position) {
        temp = temp->prev;
        new_next = temp->next->next;
        node_delete(temp->next);
        temp->next=new_next;
        new_next->prev = temp;
        return;
    } else {
        printf("Position out of list range.");
    }
}

void print(struct Node *head) {
    struct Node *temp;
    temp = head;

    printf("Forward: ");
    while(temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

void reverse_print(struct Node *head) {
    struct Node *temp;
    temp = head;

    if(temp == NULL) return;
    while(temp->next != NULL) {
        temp = temp->next;
    }
    printf("Reverse: ");
    while(temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->prev;
    }
    printf("\n");
}

#endif
