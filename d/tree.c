#include <stdlib.h>
#include <stdio.h>

struct Node {
    struct Node *left;
    struct Node *right;
    int value;
};

struct Node *tree_new_node(int value) {
    struct Node *new_node;

    new_node = (struct Node*)malloc(sizeof(struct Node));

    new_node->left = NULL;
    new_node->right = NULL;
    new_node->value = value;

    return new_node;
}

struct Node *tree_add_value(struct Node *node, int value) {
    struct Node *new_node;
    if (node == NULL) {
        new_node = tree_new_node(value);
        return new_node;
    } else {
        if (value == node->value) {
            return NULL;
        } else if (value < node->value) {
            new_node = tree_add_value(node->left, value);
            node->left = new_node;
            return node;
        } else {
            new_node = tree_add_value(node->right, value);
            node->right = new_node;
            return node;
        }
    }
}

void tree_print_in_order(struct Node *node) {
    if (node->left != NULL) {
        tree_print_in_order(node->left);
    }

    printf("%d\n", node->value);

    if (node->right != NULL) {
        tree_print_in_order(node->right);
    }
}

int main() {
    struct Node *head;

    head = NULL;
    head = tree_add_value(head, 1);

    tree_add_value(head, 2);
    tree_add_value(head, 3);
    tree_add_value(head, 7);
    tree_add_value(head, 5);

    tree_print_in_order(head);

    return 0;
}
