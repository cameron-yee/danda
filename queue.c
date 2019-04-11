#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>


struct Node {
    int data;
    struct Node* next;
};

struct Node* head;
struct Node* tail;

struct Node* GetNewNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode -> data = data;
    newNode -> next = NULL;
    return newNode;
};

bool IsEmpty() {
    return head == NULL;
}

int peek() {
    if(head != NULL) {
        return head -> data;
    } else {
        return -1;
    }
}

void add(int data) {
    struct Node* newNode = GetNewNode(data);

    if(tail != NULL) {
        tail -> next = newNode;
    }

    tail = newNode;
    if(head == NULL) {
        head = newNode;
    }
}

int removeHead() {
    int data = head -> data;
    struct Node* old = head;
    head = head -> next;
    free(old);

    if(head == NULL) {
        tail = NULL;
    }

    return data;
}

void printQueue() {
    struct Node* temp = head;

    while(temp -> next != NULL) {
        printf("%d ", temp -> data);
        temp = temp -> next;
    }

    printf("\n");
}

int main() {
    head = NULL;

    add(1);
    add(2);
    add(3);

    printQueue();

    removeHead();

    printQueue();

    int headData = peek();
    printf("headData: %d", headData);
}
