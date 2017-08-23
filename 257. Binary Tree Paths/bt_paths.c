#include <stdio.h>
#include <stdlib.h>

typedef struct tree_node_s {
    int val;
    struct tree_node_s *left;
    struct tree_node_s *right;
} tree_node_t;

void print_paths_recursive(tree_node_t *root, int path[], int len, int *ret_sizes, char **ret_arrays) {
    if (root == NULL) return ;
    path[len++] = root->val;

    if (root->left == NULL && root->right == NULL) {
        int c_idx = 0;
        ret_arrays[*ret_sizes] = (char *) calloc(1024, sizeof(char));
        for (int i = 0; i < len; i++) {
            if ((len - 1) == i) {
                c_idx += sprintf(ret_arrays[*ret_sizes] + c_idx, "%d", path[i]);
            } else {
                c_idx += sprintf(ret_arrays[*ret_sizes] + c_idx, "%d->", path[i]);
            }
        }
        (*ret_sizes)++;
    } else {
        print_paths_recursive(root->left, path, len, ret_sizes, ret_arrays);
        print_paths_recursive(root->right, path, len, ret_sizes, ret_arrays);
    }

    return ;
}

char **binaryTreePaths(tree_node_t *root, int *returnSize) {
    int path[1024] = {0};
    int len = 0;
    char **ret_arrays = (char **) calloc(1024, sizeof(char *));

    *returnSize = 0;

    print_paths_recursive(root, path, len, returnSize, ret_arrays);

    return ret_arrays;
}

/* BST recusive insertion */
void insert_node(tree_node_t **root, int val) {

    if (*root == NULL) {
        tree_node_t *new = (tree_node_t *) malloc(sizeof(tree_node_t));
        if (new) {
            new->left = NULL;
            new->right = NULL;
            new->val = val;
        }
        *root = new;
    } else {
        // Search & Insert
        if (val < (*root)->val) {
            insert_node(&(*root)->left, val);
        } else {
            insert_node(&(*root)->right, val);
        }
    }

    return ;
}

int main()
{
    char **arrays = NULL;
    int row_size = 0;
    tree_node_t *root = NULL;
    insert_node(&root, 3);
    insert_node(&root, 1);
    insert_node(&root, 2);
    insert_node(&root, 6);
    insert_node(&root, 4);
    insert_node(&root, 5);
    insert_node(&root, 7);

    arrays = binaryTreePaths(root, &row_size);
    for (int i = 0; i < row_size; i++) {
        printf("%s\n", arrays[i]);
    }

    return 0;
}
