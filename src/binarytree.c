#include "binarytree.h"
#include <string.h>

void bt_init(binary_tree_t *tree, size_t element_size) {
    tree->root         = NULL;
    tree->length       = 0;
    tree->element_size = element_size;
}

void bt_destroy(binary_tree_t *tree) {
    bt_destroy_traversal(tree->root);
    tree->root         = NULL;
    tree->length       = 0;
    tree->element_size = 0;
}

void bt_destroy_traversal(node_t *node) {
    if (node == NULL) {
        return;
    }
    bt_destroy_traversal(node->left);
    bt_destroy_traversal(node->right);
    free(node->data);
    free(node);
}

node_t *bt_create_node(binary_tree_t *tree, void *data) {
    node_t *new = malloc(sizeof(node_t));

    if (!new) {
        return NULL;
    }

    new->data = malloc(tree->element_size);

    if (!new->data) {
        free(new);
        return NULL;
    }

    memcpy(new->data, data, tree->element_size);
    new->left  = NULL;
    new->right = NULL;

    return new;
}

node_t *bt_insert_root(binary_tree_t *tree, void *data) {
    tree->root = bt_create_node(tree, data);
    return tree->root;
}

node_t *bt_insert_left(binary_tree_t *tree, node_t *node, void *data) {
    node->left = bt_create_node(tree, data);
    return node->left;
}

node_t *bt_insert_right(binary_tree_t *tree, node_t *node, void *data) {
    node->right = bt_create_node(tree, data);
    return node->right;
}
