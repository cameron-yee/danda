#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

//LIFO structure

struct Node {
    struct Node* next;
    int data;
};

struct Node* head;

struct Node* GetNewNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode -> data = data;
    newNode -> next = NULL;
    return newNode;
};

void addNode(int data) {
    struct Node* newNode = GetNewNode(data);
    if(head == NULL) {
        head = newNode;
        return;
    }

    struct Node* temp = head;
    while(temp -> next != NULL) {
        temp = temp -> next;
    }

    temp -> next = newNode;
}

void removeFromStack() {
    if(head == NULL) {
        return;
    }

    struct Node* old = head;
    head = head -> next;
    free(old);
}

void printStack() {
    struct Node* temp = head;

    while(temp != NULL) {
        printf("%d ", temp -> data);
        temp = temp -> next;
    }

    printf("\n");
}

int main() {
    head = NULL;

    addNode(1);
    printStack();

    addNode(2);
    printStack();

    addNode(3);
    printStack();

    removeFromStack();
    printStack();
}
