#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct tree_node_s {
    int val;
    struct tree_node_s *left;
    struct tree_node_s *right;
} tree_node_t;

void insert_tree_node(tree_node_t **root, int val) {
    if (*root == NULL) {
        tree_node_t *new = (tree_node_t *) malloc(sizeof(tree_node_t));
        if (new != NULL) {
            new->val = val;
            new->left = NULL;
            new->right = NULL;
        }
        *root = new;
    } else {
        if (val < (*root)->val) insert_tree_node(&(*root)->left, val);
        else insert_tree_node(&(*root)->right, val);
    }

    return ;
}

void preorder_traversal(tree_node_t *root) {
    if (root != NULL) {
        printf("%d ", root->val);
        preorder_traversal(root->left);
        preorder_traversal(root->right);
    }
}

int get_tree_depth(tree_node_t *root) {
    if (root == NULL) {
        return 0;
    } else {
        int l_tree_depth = get_tree_depth(root->left) + 1;
        int r_tree_depth = get_tree_depth(root->right) + 1;
        return (l_tree_depth > r_tree_depth)? l_tree_depth: r_tree_depth;
    }
}

typedef int bool;
bool isBalanced(tree_node_t *root) {
    if (root == NULL) {
        return 1;
    } else {
        return (abs(get_tree_depth(root->left) - get_tree_depth(root->right)) <= 1) &&
            isBalanced(root->left) && isBalanced(root->right);
    }
}

int main()
{
    tree_node_t *root = NULL;
    insert_tree_node(&root, 100);
    insert_tree_node(&root, 1);
    insert_tree_node(&root, 2);
    insert_tree_node(&root, 101);
    insert_tree_node(&root, 3);
    preorder_traversal(root);
    printf("\n");

    printf("Is the tree height-balanced under the condition of the two subtrees of every node never differ by more than 1? %s\n", isBalanced(root)? "TRUE": "FALSE");

    return 0;
}
