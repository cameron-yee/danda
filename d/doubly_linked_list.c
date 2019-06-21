//TODO
//1. Check if malloc returns NULL
//2. Set head global variable as function parameter
//    *Need to be able to mutate head somehow
//3. Declare all functions at top of file before setting

#include <stdio.h>
#include <stdlib.h>
#include "doubly_linked_list.h"

void node_delete(struct Node *node);
struct Node *node_new(int data);


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
    if (node != NULL) {
        free(node);
        node = NULL;
    }
}

void dll_insert_at_head(struct Node **head, int data) {
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

void dll_insert_at_position(struct Node **head, int data, int index) {
    struct Node *temp, *new_node;
    int current_position;

    temp = (*head);

    if (index == 0) {
        //head = insert_at_head(head, data);
        dll_insert_at_head(head, data);
        return;
    }

    current_position = 0;
    while (temp->next != NULL) {
        if (current_position == index) {
            new_node = node_new(data);
            new_node->prev = temp->prev;
            new_node->prev->next = new_node;
            new_node->next = temp;
            temp->prev = new_node;
            if (index == 1) {
                *head = new_node->prev; 
                return;
            }
        }

        current_position++;
        temp = temp->next;
    }

    printf("Index out of range.");
}

void dll_insert_at_tail(struct Node **head, int data) {
    struct Node *new_node;
    struct Node *temp;

    new_node = node_new(data);
    temp = (*head);

    if (head == NULL) {
        *head = new_node;
        return;
    }


    while (temp->next != NULL) {
        temp = temp->next;
    }

    temp->next = new_node; //(head*).prev = NewNode
    new_node->prev = temp;
}

void dll_delete_head(struct Node** head) {
    struct Node* old_head;
    struct Node* new_head;

    if (head == NULL) {
        return;
    }

    old_head = (*head);
    new_head = old_head->next;

    new_head->prev = NULL;
    *head = new_head;
    node_delete(old_head);
}

void dll_delete_tail(struct Node *head) {
    struct Node *temp;
    temp = head;

    while (temp->next != NULL) {
        temp = temp->next;
    }

    temp = temp->prev;
    temp->next = NULL;
    node_delete(temp->next);
}

void dll_delete_at_position(struct Node *head, int position) {
    struct Node *temp, *new_next;
    int current_position;

    temp = head;
    current_position = 0;

    while (temp->next != NULL && current_position < position) {
        temp = temp->next;
        current_position++;
    }

    if (temp->next == NULL && current_position == position) {
        node_delete(temp);
        return;
    } else if (current_position == position) {
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

void print_dll(struct Node *head) {
    struct Node *temp;
    temp = head;

    printf("Forward: ");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

void reverse_print_dll(struct Node *head) {
    struct Node *temp;
    temp = head;

    if (temp == NULL) return;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    printf("Reverse: ");
    while( temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->prev;
    }
    printf("\n");
}

int main() {
    struct Node* head;
    struct Node* head_two;

    //head = NULL;
    //head_two = NULL;
    head = node_new(1);
    head_two = node_new(2);

    printf("insert_at_head(1)\n");
    dll_insert_at_head(&head, 1);
    print_dll(head);
    reverse_print_dll(head);
    printf("\n");

    printf("insert_at_head(2)\n");
    dll_insert_at_head(&head, 2);
    print_dll(head);
    reverse_print_dll(head);
    printf("\n");

    printf("insert_at_head(3)\n");
    dll_insert_at_head(&head, 3);
    print_dll(head);
    reverse_print_dll(head);
    printf("\n");

    printf("2. insert_at_head(19)\n");
    dll_insert_at_head(&head_two, 19);
    print_dll(head_two);
    reverse_print_dll(head_two);
    printf("\n");

    printf("2. insert_at_head(28)\n");
    dll_insert_at_head(&head_two, 28);
    print_dll(head_two);
    reverse_print_dll(head_two);
    printf("\n");

    printf("insert_at_tail(7)\n");
    dll_insert_at_tail(&head, 7);
    print_dll(head);
    reverse_print_dll(head);
    printf("\n");

    printf("insert_at_head(4)\n");
    dll_insert_at_head(&head, 4);
    print_dll(head);
    reverse_print_dll(head);
    printf("\n");

    printf("delete_tail()\n");
    dll_delete_tail(head);
    print_dll(head);
    reverse_print_dll(head);
    printf("\n");

    printf("delete_head()\n");
    dll_delete_head(&head);
    print_dll(head);
    reverse_print_dll(head);
    printf("\n");

    printf("insert_at_position(19, 1)\n");
    dll_insert_at_position(&head, 19, 1);
    print_dll(head);
    reverse_print_dll(head);
    printf("\n");

    printf("insert_at_head(5)\n");
    dll_insert_at_head(&head, 5);
    print_dll(head);
    reverse_print_dll(head);
    printf("\n");

    printf("delete_at_position(2)\n");
    dll_delete_at_position(head, 2);
    print_dll(head);
    reverse_print_dll(head);
    printf("\n");

    return 0;
}
