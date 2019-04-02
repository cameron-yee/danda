include<stdio.h>
#include<stdlib.h>

struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
};

struct Node* head;

struct Node* GetNewNode(int x) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node)); //malloc allocates memory on the heap so the data will persist
    newNode -> data = x;
    newNode -> prev = NULL;
    newNode -> next = NULL;
    return newNode;
};

void InsertAtHead(int x) {
    struct Node* newNode = GetNewNode(x);
    if(head == NULL) {
        head = newNode;
        return;
    }

    head -> prev = newNode; //(head*).prev = NewNode    //Reference to head = New Node
    newNode -> next = head;
    head = newNode;
}

void InsertAtPosition(int data, int index) {
    struct Node* temp = head;

    if(index == 0) {
        InsertAtHead(data);
        return;
    }

    int currentPosition = 0;
    while(temp -> next != NULL) {
        if(currentPosition == index) {
            struct Node* newNode = GetNewNode(data);
            newNode -> prev = temp -> prev;
            newNode -> prev -> next = newNode;
            newNode -> next = temp;
            temp -> prev = newNode;
            if(index == 1) {
                head = newNode -> prev; 
            }
            //printf("%d, %d, %d", newNode -> data, newNode -> next -> data,  newNode -> prev -> data);
            //printf("%d, %d, %d", temp -> data, temp -> next -> data, temp -> prev -> data);
            //printf("%d, %d, %d", newNode -> prev -> data, newNode -> prev -> next -> data, newNode -> prev -> prev -> data);
            //printf("%d", head -> data);
            //printf("\n");
            return;
        }

        currentPosition++;
        temp = temp -> next;
    }

    printf("Index out of range.");
}

void InsertAtTail(int x) {
    struct Node* newNode = GetNewNode(x);
    if(head == NULL) {
        head = newNode;
        return;
    }

    struct Node* temp = head;

    while(temp -> next != NULL) {
        temp = temp -> next;
    }

    temp -> next = newNode; //(head*).prev = NewNode
    newNode -> prev = temp;
}

void DeleteHead() {
    struct Node* temp = head;

    temp = temp -> next;
    temp -> prev = NULL;
    head = temp;
}

void DeleteTail() {
    struct Node* temp = head;

    while(temp -> next != NULL) {
        temp = temp -> next;
    }

    temp = temp -> prev;
    temp -> next = NULL;
}

void Print() {
    struct Node* temp = head;
    printf("Forward: ");
    while(temp != NULL) {
        printf("%d ", temp -> data);
        temp = temp -> next;
    }
    printf("\n");
}

void ReversePrint() {
    struct Node* temp = head;
    if(temp == NULL) return;
    while(temp -> next != NULL) {
        temp = temp -> next;
    }
    printf("Reverse: ");
    while(temp != NULL) {
        printf("%d ", temp -> data);
        temp = temp -> prev;
    }
    printf("\n");
}

int main() {
    head = NULL;
    
    printf("InsertAtHead(1)\n");
    InsertAtHead(1);
    Print();
    ReversePrint();
    printf("\n");

    printf("InsertAtHead(2)\n");
    InsertAtHead(2);
    Print();
    ReversePrint();
    printf("\n");

    printf("InsertAtHead(3)\n");
    InsertAtHead(3);
    Print();
    ReversePrint();
    printf("\n");

    printf("InsertAtTail(7)\n");
    InsertAtTail(7);
    Print();
    ReversePrint();
    printf("\n");

    printf("InsertAtHead(4)\n");
    InsertAtHead(4);
    Print();
    ReversePrint();
    printf("\n");

    printf("DeleteTail()\n");
    DeleteTail();
    Print();
    ReversePrint();
    printf("\n");

    printf("DeleteHead()\n");
    DeleteHead();
    Print();
    ReversePrint();
    printf("\n");

    printf("InsertAtPosition(19, 1)\n");
    InsertAtPosition(19, 1);
    Print();
    ReversePrint();
    printf("\n");
}
