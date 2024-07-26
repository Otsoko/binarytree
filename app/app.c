#include "binarytree.h"
#include <stdio.h>

#define DISTANCE 8

typedef struct data {
    int  number;
    char character;
} data_t;

void inorderTraversal(node_t *node);
void preorderTraversal(node_t *node);
void postorderTraversal(node_t *node);

void btPrintTraversal(node_t *node, int space);
void btPrint(node_t *root);

int main(void) {
    binary_tree_t bt;
    data_t        data;
    node_t       *node;

    bt_init(&bt, sizeof(data_t));

    data.number    = 1;
    data.character = 'h';

    node = bt_insert_root(&bt, &data);

    data.number    = 2;
    data.character = 'l';

    bt_insert_left(&bt, node, &data);

    data.number    = 3;
    data.character = 'r';

    node = bt_insert_right(&bt, node, &data);

    data.number    = 4;
    data.character = 'r';

    node = bt_insert_right(&bt, node, &data);

    data.number    = 5;
    data.character = 'r';

    bt_insert_right(&bt, node, &data);

    data.number    = 6;
    data.character = 'l';

    bt_insert_left(&bt, node, &data);
    printf("Size: %ld\n\n", bt.length);

    printf("Tree view\n");
    btPrint(bt.root);
    printf("\n");

    printf("Inorder\n");
    inorderTraversal(bt.root);
    printf("\n\nPreorder\n");
    preorderTraversal(bt.root);
    printf("\n\nPostorder\n");
    postorderTraversal(bt.root);
    printf("\n");

    bt_destroy(&bt);

    return 0;
}

void inorderTraversal(node_t *node) {
    if (node == NULL) {
        return;
    }
    inorderTraversal(node->left);
    data_t *data = node->data;
    printf("[%d, %c] ", data->number, data->character);
    inorderTraversal(node->right);
}

void preorderTraversal(node_t *node) {
    if (node == NULL) {
        return;
    }
    data_t *data = node->data;
    printf("[%d, %c] ", data->number, data->character);
    preorderTraversal(node->left);
    preorderTraversal(node->right);
}

void postorderTraversal(node_t *node) {
    if (node == NULL) {
        return;
    }
    postorderTraversal(node->left);
    postorderTraversal(node->right);
    data_t *data = node->data;
    printf("[%d, %c] ", data->number, data->character);
}

void btPrintTraversal(node_t *node, int space) {
    data_t *data = NULL;

    if (node == NULL)
        return;

    space += DISTANCE;

    btPrintTraversal(node->right, space);

    printf("\n");
    for (int i = DISTANCE; i < space; i++) {
        printf(" ");
    }
    data = node->data;
    printf("[%d, %c] ", data->number, data->character);

    btPrintTraversal(node->left, space);
}

void btPrint(node_t *root) {
    btPrintTraversal(root, 0);
}