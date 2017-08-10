#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct tree_node_s {
    int val;
    struct tree_node_s *left;
    struct tree_node_s *right;
} tree_node_t;

void insert_tree(tree_node_t **root, int val) {
    if (*root == NULL) {
        tree_node_t *new = (tree_node_t *) malloc(sizeof(tree_node_t));
        if (new) {
            new->val = val;
            new->left = NULL;
            new->right = NULL;
        }
        *root = new;
    } else {
        if (val < (*root)->val) {
            insert_tree(&((*root)->left), val);
        } else {
            insert_tree(&((*root)->right), val);
        }
    }

    return ;
}

void inorder_traversal(tree_node_t *root) {
    if (root != NULL) {
        inorder_traversal(root->left);
        printf("%d ", root->val);
        inorder_traversal(root->right);
    }

    return ;
}

void pathCheckRecursive(tree_node_t *root, int path[], int len, int sum, int **ret_arrays, int **columnSizes, int *returnSize) {
    if (root == NULL) return ;

    // DFS seach by storing value in the buffer
    path[len++] = root->val;

    if (root->left == NULL && root->right == NULL) {
        /* Reach a path end, check summation */
        for (int i = 0; i < len; i++) {
            sum -= path[i];
        }
        if (sum == 0) {
            int *ptr_buf = NULL;
            //(*columnSizes)[*returnSize] = len;
            *(*columnSizes + (*returnSize)) = len;
            printf("%d\n", (*columnSizes)[*returnSize]);
            ptr_buf = (int *) malloc(len * sizeof(int));
            memcpy(ptr_buf, &path[0], len * sizeof(int));
            ret_arrays[*returnSize] = ptr_buf;
            for (int i = 0; i < len; i++) {
                printf("%d ", *(ret_arrays[*returnSize] + i));
            }
            printf("\n");
            (*returnSize)++;
        }
    } else {
        pathCheckRecursive(root->left, path, len, sum, ret_arrays, columnSizes, returnSize);
        pathCheckRecursive(root->right, path, len, sum, ret_arrays, columnSizes, returnSize);
    }

    return ;
}

int **pathSum(tree_node_t *root, int sum, int **columnSizes, int *returnSize) {
    int path[1024] = {0};
    int len = 0;
    /* A pointer array*/
    int **ret_arrays = (int **) calloc(1024, sizeof(int *));
    *returnSize = 0;
    if (*columnSizes == NULL) {
        /* A pointer to an array*/
        *columnSizes = (int *) calloc(1024, sizeof(int));
    }
    pathCheckRecursive(root, path, len, sum, ret_arrays, columnSizes, returnSize);

    return ret_arrays;
}

int main()
{
    tree_node_t *root = NULL;

    insert_tree(&root, 5);
    insert_tree(&root, 2);
    insert_tree(&root, 1);
    insert_tree(&root, 3);
    insert_tree(&root, 4);
    insert_tree(&root, 9);

    inorder_traversal(root);
    printf("\n");

    int row_size = 0;
    int *columnSizes = NULL;
    int **ret_arrays = pathSum(root, 14, &columnSizes, &row_size);

    for (int i = 0; i < row_size; i++) {
        printf("path %d: ", i + 1);
        for (int j = 0; j < *(columnSizes + i); j++) {
            printf("%d ", *(ret_arrays[i] + j));
        }
        printf("\n");
    }

    return 0;
}
