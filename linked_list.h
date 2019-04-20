#include <stdlib.h>
#include <stdio.h>
#include <string.h>

struct Node {
    struct Node* next;
    char value[];
};

struct Node* node_new(char value[]) {
    struct Node* new_node;

    new_node = (struct Node*)malloc(sizeof(struct Node));

    for(size_t i = 0; i < strlen(value); i++) {
        new_node->value[i] = value[i];
    }
    //new_node->value = value;
    new_node->next = NULL;

    return new_node;
}

void add_node_to_head(struct Node** head, char value[]) {
    struct Node* new_node;

    new_node = node_new(value);

    if(head == NULL) {
        *head = new_node;
        return;
    }

    (*head)->next = NULL;
    new_node->next = *head;
    (*head) = new_node;
}

void print_list(struct Node* head) {
    struct Node* temp;

    temp = head;

    while(temp != NULL) {
        printf("%s\n", temp->value);
        temp = temp->next;
    }
}
