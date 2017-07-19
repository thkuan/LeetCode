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

/*
 * Return an array of arrays of size in int *return_size
 * The sizes of the arrays are returned as int **column_sizes
 */
int **levelorder_traversal(tree_node_t *root, int **column_sizes, int *return_size) {
    int **ret = NULL;
    fifo_node_t *head = NULL;
    fifo_node_t *tail = NULL;
    tree_node_t *cur = NULL;
    /*
     * Start with root and count all children on each level.
     * 1. count++ of each pop operation to meet the number of children 
     *    on specified level
     * 2. num_child_next_level++ of each push operation until reaching
     *    next level
     */
    int num_child_cur_level = 1, num_child_next_level = 0, count = 0;

    *return_size = 0;
    if (root != NULL) {
        /* Malloc int **columnSizes */
        if (*column_sizes == NULL) {
            *column_sizes = (int *) calloc(1024, sizeof(int));
        }
        /* Malloc int **ret */
        if (ret == NULL) {
            ret = (int **) calloc(1024, sizeof(int *));
            ret[0] = (int *) calloc(num_child_cur_level, sizeof(int)); 
        }
        /* Push root if not NULL to FIFO */
        push_fifo(&head, &tail, root); 
        while (head != NULL) {
            cur = pop_fifo(&head, &tail);
            if (cur != NULL) {
                ret[*return_size][count] = cur->value;
                count++;
                if (cur->left != NULL) {
                    push_fifo(&head, &tail, cur->left);
                    num_child_next_level++;
                }
                if (cur->right != NULL) {
                    push_fifo(&head, &tail, cur->right);
                    num_child_next_level++;
                }
            }
            /* Already dequeue the amount of children in current level */
            if (num_child_cur_level == count) {
                /* Update column size */
                (*column_sizes)[*return_size] = num_child_cur_level;
                /* Update row size */
                (*return_size)++;
                ret[*return_size] = (int *) calloc(num_child_next_level, sizeof(int)); 
                num_child_cur_level = num_child_next_level;
                count = 0;
                num_child_next_level = 0;
            }
        }
    }

    return ret;
}

int main()
{
    int **ptr = NULL;
    int *column_sizes = NULL;
    int row_size = 0;
    tree_node_t *root = NULL;
    insert_node(&root, 3);
    insert_node(&root, 1);
    insert_node(&root, 2);
    insert_node(&root, 6);
    insert_node(&root, 4);
    insert_node(&root, 5);
    insert_node(&root, 7);

    ptr = levelorder_traversal(root, &column_sizes, &row_size);
    
    for (int i = 0; i < row_size; i++) {
        printf("[");
        for (int j = 0; j < column_sizes[i]; j++) {
            if (j == (column_sizes[i] - 1)) {
                printf("%2d", ptr[i][j]);
            } else {
                printf("%2d, ", ptr[i][j]);
            }
        }
        printf("]\n");
    }

    return 0;
}
