#include <stdio.h>
#include <stdlib.h>

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

void printPathsRecursive(tree_node_t *root, int path[], int len) {
    if (root == NULL) return ;
    path[len++] = root->val;

    if (root->left == NULL && root->right == NULL) {
        for (int i = 0; i < len; i++) {
            printf("%d ", path[i]);
        }
        printf("\n");
    } else {
        printPathsRecursive(root->left, path, len);
        printPathsRecursive(root->right, path, len);
    }

    return ;
}

void printPaths(tree_node_t *root) {
    int path[1024] = {0};
    int len = 0;
    printPathsRecursive(root, path, len);

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

typedef int bool;
bool hasPathSum(tree_node_t *root, int sum) {
    if (root == NULL) return 0;
    else {
        sum -= root->val;
        if (root->left == NULL && root->right == NULL) {
            return (sum == 0);
        } else {
            return hasPathSum(root->left, sum) || hasPathSum(root->right, sum);
        }
    }
}

int main()
{
    tree_node_t *root = NULL;

    insert_tree(&root, 5);
    insert_tree(&root, 2);
    insert_tree(&root, 1);
    insert_tree(&root, 4);
    insert_tree(&root, 8);
    insert_tree(&root, 6);

    inorder_traversal(root);
    printf("\n");

    printf("Paths:\n");
    printPaths(root);

    printf ("Is the tree hasPathSum(root, 7)? %s\n", hasPathSum(root, 7)? "TRUE": "FALSE");
    printf ("Is the tree hasPathSum(root, 8)? %s\n", hasPathSum(root, 8)? "TRUE": "FALSE");

    return 0;
}
