#include <stdlib.h>
#include <stdio.h>
#include "linked_list.h"

size_t ll_length(char *list) {
    size_t i;

    i = 0;
    while (list[i] != '\0') {
        i++;
    }

    return i;
}

//TODO: pass in char * instead of []
struct Node *node_new(char *key, int value) {
    struct Node *new_node;
    //char *key_pointer;

    //Malloc error on this line.
    new_node = (struct Node*)malloc(sizeof(struct Node));

    if(new_node == NULL) {
        printf("Error during malloc.");
        exit(1);
    }

    //Not sure if this is right
    //for(size_t i = 0; i < length(key); i++) {
    //    new_node->key[i] = key[i];
    //}

    new_node->next = NULL;
    new_node->value = value;
    new_node->key = key;

    return new_node;
}

//TODO: pass in char * instead of []
void ll_add_node_to_head(struct Node **head, char *key, int value) {
    struct Node *new_node;

    new_node = node_new(key, value);

    if(head == NULL) {
        head = &new_node;
        return;
    }

    (*head)->next = NULL;
    new_node->next = *head;
    (*head) = new_node;
}

void ll_delete_node_from_memory(struct Node *node) {
    if(node != NULL) {
        free(node);
    }
}

void ll_delete_head_node(struct Node **head) {
    if(head == NULL) {
        return;
    }

    *head = (*head)->next;
    ll_delete_node_from_memory(*head);
}

//TODO: pass in char * instead of []
int ll_get_node_data_by_lookup(struct Node *head, char *key) {
    struct Node *temp;
    struct Node *match;

    match = NULL;
    temp = head;
    while(temp != NULL) {
        if(match != NULL) {
            return match->value;
        }

        //printf("%s, %s\n", key, temp->key);
        for(size_t i = 0; i < ll_length(key); i++) {
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

void ll_print_list(struct Node *head) {
    struct Node *temp;

    temp = head;

    while(temp != NULL) {
        printf("(%s, %d), ", temp->key, temp->value);
        temp = temp->next;
    }

    printf("\n");
}

//int main() {
//    struct Node* head;
//    char key[] = "Cameron";
//    char key2[] = "World";
//
//    head = node_new(key, 1);
//
//    add_node_to_head(&head, key2, 0);
//
//    print_list(head);
//
//    int wanted_data = get_node_data_by_lookup(head, key);
//
//    printf("%d\n", wanted_data);
//
//    delete_head_node(&head);
//
//    print_list(head);
//
//    return 0;
//}
