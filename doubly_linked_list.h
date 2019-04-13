#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
};

struct Node* node_new(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node)); //malloc allocates memory on the heap so the data will persist
    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

void node_delete(struct Node* node) {
    if(node != NULL) {
        free(node);
        node = NULL;
    }
}

void insert_at_head(struct Node* head, int data) {
    struct Node* new_node = node_new(data);
    if(head == NULL) {
        head = new_node;
        return;
    }

    head->prev = new_node; //(head*).prev = NewNode    //Reference to head = New Node
    new_node->next = head;
    head = new_node;
}

void insert_at_position(struct Node* head, int data, int index) {
    struct Node* temp = head;

    if(index == 0) {
        insert_at_head(head, data);
        return;
    }

    int currentPosition = 0;
    while(temp->next != NULL) {
        if(currentPosition == index) {
            struct Node* newNode = node_new(data);
            newNode->prev = temp->prev;
            newNode->prev->next = newNode;
            newNode->next = temp;
            temp->prev = newNode;
            if(index == 1) {
                head = newNode->prev; 
            }
            return;
        }

        currentPosition++;
        temp = temp->next;
    }

    printf("Index out of range.");
}

void insert_at_tail(struct Node* head, int data) {
    struct Node* new_node;
    struct Node* temp;

    new_node = node_new(data);
    temp = head;

    if(head == NULL) {
        head = new_node;
        return;
    }


    while(temp->next != NULL) {
        temp = temp->next;
    }

    temp->next = new_node; //(head*).prev = NewNode
    new_node->prev = temp;
}

void delete_head(struct Node* head) {
    struct Node* old_head;
    struct Node* new_head;

    if(head == NULL) {
        return;
    }

    old_head = head;
    new_head = old_head->next;

    new_head->prev = NULL;
    head = new_head;
    node_delete(old_head);
}

void delete_tail(struct Node* head) {
    struct Node* temp;
    temp = head;

    while(temp->next != NULL) {
        temp = temp->next;
    }

    temp = temp->prev;
    temp->next = NULL;
    node_delete(temp->next);
}

void delete_at_position(struct Node* head, int position) {
    struct Node* temp;
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
        struct Node* new_next = temp->next->next;
        node_delete(temp->next);
        temp->next=new_next;
        new_next->prev = temp;
        return;
    } else {
        printf("Position out of list range.");
    }
}

void print(struct Node* head) {
    struct Node* temp;
    temp = head;

    printf("Forward: ");
    while(temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

void reverse_print(struct Node* head) {
    struct Node* temp;
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

