#include<stdio.h>
#include<stdlib.h>

struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
};

struct Node* head;

struct Node* GetNewNode(int x) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node)); //malloc allocates memory on the heap so the data will persist
    newNode->data = x;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

void insert_at_head(int x) {
    struct Node* newNode = GetNewNode(x);
    if(head == NULL) {
        head = newNode;
        return;
    }

    head->prev = newNode; //(head*).prev = NewNode    //Reference to head = New Node
    newNode->next = head;
    head = newNode;
}

void insert_at_position(int data, int index) {
    struct Node* temp = head;

    if(index == 0) {
        insert_at_head(data);
        return;
    }

    int currentPosition = 0;
    while(temp->next != NULL) {
        if(currentPosition == index) {
            struct Node* newNode = GetNewNode(data);
            newNode->prev = temp->prev;
            newNode->prev->next = newNode;
            newNode->next = temp;
            temp->prev = newNode;
            if(index == 1) {
                head = newNode->prev; 
            }
            //printf("%d, %d, %d", newNode->data, newNode->next->data,  newNode->prev->data);
            //printf("%d, %d, %d", temp->data, temp->next->data, temp->prev->data);
            //printf("%d, %d, %d", newNode->prev->data, newNode->prev->next->data, newNode->prev->prev->data);
            //printf("%d", head->data);
            //printf("\n");
            return;
        }

        currentPosition++;
        temp = temp->next;
    }

    printf("Index out of range.");
}

void insert_at_tail(int x) {
    struct Node* newNode = GetNewNode(x);
    if(head == NULL) {
        head = newNode;
        return;
    }

    struct Node* temp = head;

    while(temp->next != NULL) {
        temp = temp->next;
    }

    temp->next = newNode; //(head*).prev = NewNode
    newNode->prev = temp;
}

void delete_head() {
    if(head == NULL) {
        return;
    }

    struct Node* old_head = head;

    struct Node* new_head = old_head->next;
    new_head->prev = NULL;
    head = new_head;
    free(old_head);
}

void delete_tail() {
    struct Node* temp = head;

    while(temp->next != NULL) {
        temp = temp->next;
    }

    temp = temp->prev;
    temp->next = NULL;
    free(temp->next);
}

void delete_at_position(int position) {
    int current_position = 0;
    struct Node* temp = head;
    if(head == NULL) {
        return;
    }

    while(temp->next != NULL) {
        if(current_position == position) {
            temp = temp->prev;
            temp->next=temp->next->next;
            temp->next->next->prev = temp;
            free(temp->next);
            return;
        }

        temp = temp->next;
        current_position++;
    }

    if(current_position == position) {
        temp = temp->prev;
        temp->next = NULL;
        free(temp->next);
        return;
    }

    printf("Position out of list range.");
}

void print() {
    struct Node* temp = head;
    printf("Forward: ");
    while(temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

void reverse_print() {
    struct Node* temp = head;
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

int main() {
    head = NULL;
    
    printf("insert_at_head(1)\n");
    insert_at_head(1);
    print();
    reverse_print();
    printf("\n");

    printf("insert_at_head(2)\n");
    insert_at_head(2);
    print();
    reverse_print();
    printf("\n");

    printf("insert_at_head(3)\n");
    insert_at_head(3);
    print();
    reverse_print();
    printf("\n");

    printf("insert_at_tail(7)\n");
    insert_at_tail(7);
    print();
    reverse_print();
    printf("\n");

    printf("insert_at_head(4)\n");
    insert_at_head(4);
    print();
    reverse_print();
    printf("\n");

    printf("delete_tail()\n");
    delete_tail();
    print();
    reverse_print();
    printf("\n");

    printf("delete_head()\n");
    delete_head();
    print();
    reverse_print();
    printf("\n");

    printf("insert_at_position(19, 1)\n");
    insert_at_position(19, 1);
    print();
    reverse_print();
    printf("\n");

    printf("insert_at_head(5)\n");
    insert_at_head(5);
    print();
    reverse_print();
    printf("\n");

    printf("delete_at_position(2)\n");
    delete_at_position(2);
    print();
    reverse_print();
    printf("\n");
}
