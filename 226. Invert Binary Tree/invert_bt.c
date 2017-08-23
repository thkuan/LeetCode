#include <stdio.h>
#include <stdlib.h>

typedef struct tree_node_s {
    int val;
    struct tree_node_s *left;
    struct tree_node_s *right;
} tree_node_t;

tree_node_t *invertTree(tree_node_t *root) {
    if (root == NULL) return NULL;
    else {
        invertTree(root->left);
        invertTree(root->right);

        tree_node_t *tmp = root->left;
        root->left = root->right;
        root->right = tmp;
    }

    return root;
}

void insert_tree(tree_node_t **root, int val) {
    if (*root == NULL) {
        tree_node_t *new = (tree_node_t *) malloc(sizeof(tree_node_t));
        if (new != NULL) {
            new->val = val;
            new->left = NULL;
            new->right = NULL;
        }
        *root = new;
    } else {
        if ((*root)->val > val) {
            insert_tree(&(*root)->left, val);
        } else {
            insert_tree(&(*root)->right, val);
        }
    }

    return ;
}

void print_inorder(tree_node_t *root) {
    if (root != NULL) {
        print_inorder(root->left);
        printf("%d", root->val);
        print_inorder(root->right);
    }

    return ;
}

int main()
{
    tree_node_t *root = NULL;
    insert_tree(&root, 6);
    insert_tree(&root, 4);
    insert_tree(&root, 5);
    insert_tree(&root, 3);
    insert_tree(&root, 8);
    insert_tree(&root, 7);
    insert_tree(&root, 9);

    print_inorder(root);
    printf("\n");
    root = invertTree(root);
    print_inorder(root);
    printf("\n");

    return 0;
}
