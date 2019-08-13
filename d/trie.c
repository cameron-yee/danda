#include <stdlib.h>
#include <stdio.h>

typedef struct Node {
    char *parent_string;
    char *children;
    size_t is_word;
} node;

node *node_new() {
    node *new_node;

    //new_node = (node *Node)malloc(sizeof(node));
    new_node = malloc(sizeof(node));

    if (new_node == NULL) {
        printf("malloc failed.");
        exit(1);
    }

    new_node->parent_string = NULL;
    new_node->children = NULL;
    new_node->is_word = 0;

    return new_node;
}

int main() {
    node *new_node;

    new_node = node_new();

    return 0;
}


