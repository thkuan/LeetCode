#include <stdio.h>
#include <stdlib.h>

typedef struct tree_node_s {
    int val;
    struct tree_node_s *left;
    struct tree_node_s *right;
} tree_node_t;

typedef struct list_node_s {
    tree_node_t *ptr;
    struct list_node_s *next;
} list_node_t;

typedef struct fifo_s {
    list_node_t *head;
    list_node_t *tail;
} fifo_t;

void push_fifo(fifo_t *fifo, tree_node_t *ptr) {
    if (ptr != NULL) {
        list_node_t *new = (list_node_t *) malloc(sizeof(list_node_t));
        new->ptr = ptr;
        new->next = NULL;

        if (fifo->tail == NULL) {
            fifo->tail = new;
            fifo->head = new;
        } else {
            fifo->tail->next = new;
            fifo->tail = new;
        }
    }

    return ;
}

tree_node_t *pop_fifo(fifo_t *fifo) {
    tree_node_t *ret_ptr = NULL;
    list_node_t *rm = NULL;
    if (fifo->head != NULL) {
        rm = fifo->head;
        ret_ptr = rm->ptr;
        fifo->head = fifo->head->next;
        if (fifo->head == NULL) {
            fifo->tail = NULL;
        }
        free(rm);
    }

    return ret_ptr;
}

void insert_bst(tree_node_t **root, int val) {
    if (*root == NULL) {
        tree_node_t *new = (tree_node_t *) malloc(sizeof(tree_node_t));
        if (new != NULL) {
            new->val = val;
            new->left = NULL;
            new->right = NULL;
        }
        *root = new;
    } else {
        if (val < (*root)->val) insert_bst(&(*root)->left, val);
        else insert_bst(&(*root)->right, val);
    }

    return ;
}

void levelorder_traversal(tree_node_t *root) {
    fifo_t fifo = {NULL, NULL};
    int cnt = 0, num_tn_cur_level = 0, num_tn_next_level = 0;
    tree_node_t *cur = NULL;
    if (root != NULL) {
        push_fifo(&fifo, root);
        num_tn_cur_level = 1;
        while (fifo.head != NULL) {
            cur = pop_fifo(&fifo);
            if (cur != NULL) {
                printf("%d ", cur->val);
                cnt++;
                if (cur->left != NULL) {
                    push_fifo(&fifo, cur->left);
                    num_tn_next_level++;
                }
                if (cur->right != NULL) {
                    push_fifo(&fifo, cur->right);
                    num_tn_next_level++;
                }
            }
            if (cnt == num_tn_cur_level) {
                printf("\n");
                num_tn_cur_level = num_tn_next_level;
                cnt = 0;
                num_tn_next_level = 0;
            }
        }
    }

    return ;
}

void preorder_traversal(tree_node_t *root) {
    if (root != NULL) {
        printf("%d ", root->val);
        preorder_traversal(root->left);
        preorder_traversal(root->right);
    }

    return ;
}

int *rightSideView(tree_node_t *root, int *returnSize) {
    fifo_t fifo = {NULL, NULL};
    int cnt = 0, num_tn_cur_level = 0, num_tn_next_level = 0;
    tree_node_t *cur = NULL;
    *returnSize = 0;
    int *ret_buf = NULL;

    if (root != NULL) {
        push_fifo(&fifo, root);
        num_tn_cur_level = 1;
        while (fifo.head != NULL) {
            cur = pop_fifo(&fifo);
            if (cur != NULL) {
                cnt++;
                if (cur->left != NULL) {
                    push_fifo(&fifo, cur->left);
                    num_tn_next_level++;
                }
                if (cur->right != NULL) {
                    push_fifo(&fifo, cur->right);
                    num_tn_next_level++;
                }
            }
            if (cnt == num_tn_cur_level) {
                (*returnSize)++;
                ret_buf = (int *) realloc(ret_buf, (*returnSize) * sizeof(int));
                ret_buf[(*returnSize) - 1] = cur->val;
                num_tn_cur_level = num_tn_next_level;
                cnt = 0;
                num_tn_next_level = 0;
            }
        }
    }

    return ret_buf;
}

int main()
{
    int num = 0, *ptr = NULL;
    tree_node_t *root = NULL;
    insert_bst(&root, 10);
    insert_bst(&root, 8);
    insert_bst(&root, 1);
    insert_bst(&root, 2);
    insert_bst(&root, 3);
    insert_bst(&root, 12);
    insert_bst(&root, 11);

    preorder_traversal(root);
    printf("\n");
    levelorder_traversal(root);

    ptr = rightSideView(root, &num);
    for (int i = 0; i < num; i++) {
        printf("%d ", *(ptr + i));
    }
    printf("\n");

    return 0;
}
