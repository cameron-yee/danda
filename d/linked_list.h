#include <stdlib.h>
#include <stdio.h>

struct Node {
    struct Node* next;
    int value;
    char key[];
};

size_t length(char list[]); 
struct Node* node_new(char key[], int value);
void add_node_to_head(struct Node** head, char key[], int value);
void print_list(struct Node* head);
void delete_head_node(struct Node** head);

size_t length(char list[]) {
    size_t i;

    i = 0;
    while(list[i] != '\0') {
        i++;
    }

    return i;
}

struct Node* node_new(char key[], int value) {
    struct Node* new_node;

    //Malloc error on this line.
    new_node = (struct Node*)malloc(sizeof(struct Node));

    if(new_node == NULL) {
        printf("Error during malloc.");
        exit(1);
    }

    for(size_t i = 0; i < length(key); i++) {
        new_node->key[i] = key[i];
    }

    new_node->next = NULL;
    new_node->value = value;

    printf("h5\n");
    return new_node;
}

void add_node_to_head(struct Node** head, char key[], int value) {
    struct Node* new_node;

    new_node = node_new(key, value);

    if(head == NULL) {
        *head = new_node;
        return;
    }

    (*head)->next = NULL;
    new_node->next = *head;
    (*head) = new_node;
}

void delete_node_from_memory(struct Node* node) {
    if(node != NULL) {
        free(node);
    }
}

void delete_head_node(struct Node** head) {
    if(head == NULL) {
        return;
    }

    *head = (*head)->next;
    delete_node_from_memory(*head);
}

int get_node_data_by_lookup(struct Node* head, char key[]) {
    struct Node* temp;
    struct Node* match;

    match = NULL;
    temp = head;
    while(temp != NULL) {
        if(match != NULL) {
            return match->value;
        }

        printf("%s, %s\n", key, temp->key);
        for(size_t i = 0; i < length(key); i++) {
            printf("%d, %d\n", key[i], temp->key[i]);
            if(key[i] != temp->key[i]) {
                match = NULL;
                break;
            } else {
                printf("%s\n", temp->key);
                match = temp;
            }
        }

        temp = temp->next;
    }

    if(match != NULL) {
        return match->value;
    }

    return -1;
}

void print_list(struct Node* head) {
    struct Node* temp;

    temp = head;

    while(temp != NULL) {
        printf("(%s, %d), ", temp->key, temp->value);
        temp = temp->next;
    }

    printf("\n");
}
