#pragma once

#include <stdlib.h>

typedef struct node {
    void        *data;
    struct node *left;
    struct node *right;
} node_t;

typedef struct {
    node_t *root;
    size_t  length;
    size_t  element_size;
} binary_tree_t;

void    bt_init(binary_tree_t *tree, size_t element_size);
void    bt_destroy(binary_tree_t *tree);
void    bt_destroy_traversal(node_t *node);
node_t *bt_create_node(binary_tree_t *tree, void *data);
node_t *bt_insert_root(binary_tree_t *tree, void *data);
node_t *bt_insert_left(binary_tree_t *tree, node_t *node, void *data);
node_t *bt_insert_right(binary_tree_t *tree, node_t *node, void *data);
