#include <stdio.h>
#include <stdlib.h>

typedef struct tree_node_s {
    struct tree_node_s *left;
    struct tree_node_s *right;
    int value;
} tree_node_t;

typedef struct fifo_node_s {
    struct fifo_node_s *next;
    tree_node_t *ptr_val;
} fifo_node_t;

void push_fifo(fifo_node_t **head, fifo_node_t **tail, tree_node_t *ptr_val) {
    fifo_node_t *new = (fifo_node_t *) malloc(sizeof(fifo_node_t));
    if (new) {
        new->ptr_val = ptr_val;
        new->next = NULL;

        if (*head == NULL && *tail == NULL) {
            *head = new;
            *tail = new;
        } else {
            (*tail)->next = new;
            *tail = new;
        }
    }

    return ;
}

tree_node_t *pop_fifo(fifo_node_t **head, fifo_node_t **tail) {
    fifo_node_t *rm = NULL;
    tree_node_t *ret_ptr = 0;
    if (*head != NULL) {
        rm = *head;
        *head = (*head)->next;
        if (*head == NULL) {
            *tail = NULL;
        }
        ret_ptr = rm->ptr_val;
        free(rm);
    }
    return ret_ptr;
}

/* BST recusive insertion */
void insert_node(tree_node_t **root, int val) {

    if (*root == NULL) {
        tree_node_t *new = (tree_node_t *) malloc(sizeof(tree_node_t));
        if (new) {
            new->left = NULL;
            new->right = NULL;
            new->value = val;
        }
        *root = new;
    } else {
        // Search & Insert
        if (val < (*root)->value) {
            insert_node(&(*root)->left, val);
        } else {
            insert_node(&(*root)->right, val);
        }
    }

    return ;
}

int maxDepth(tree_node_t *root) {
    if (root == NULL) {
        return 0;
    }
    int left_val = maxDepth(root->left) + 1;
    int right_val = maxDepth(root->right) + 1;
    return (left_val > right_val)? left_val: right_val;
}

int main()
{
    tree_node_t *root = NULL;
    insert_node(&root, 3);
    insert_node(&root, 1);
    insert_node(&root, 2);
    insert_node(&root, 6);
    insert_node(&root, 4);
    insert_node(&root, 5);
    insert_node(&root, 7);

    printf("maxDepth(root) = %d\n", maxDepth(root));

    return 0;
}
