#include <stdio.h>
#include <stdlib.h>

typedef int bool;
#define NIL 0

typedef struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
} tree_node_t;

typedef struct ListNode {
    tree_node_t *p_tn;
    struct ListNode *next;
} list_node_t;

typedef struct Queue {
    list_node_t *head;
    list_node_t *tail;
} queue_t;


void push_fifo(queue_t *p_q, tree_node_t *p_tn) {
    list_node_t *new = (list_node_t *) malloc(sizeof(list_node_t));
    if (new) {
        new->p_tn = p_tn;
        new->next = NULL;
        if (p_q->head == NULL && p_q->tail == NULL) {
            p_q->head = new;
            p_q->tail = new;
        } else {
            p_q->tail->next = new;
            p_q->tail = new;
        }
    }
    
    return ;
}

tree_node_t *pop_fifo(queue_t *p_q) {
    tree_node_t *p_ret_tn = NULL;
    list_node_t *p_rm_ln = NULL;
    if (p_q->head != NULL) {
        p_rm_ln = p_q->head;
        p_ret_tn = p_q->head->p_tn;
        p_q->head = p_q->head->next;
        if (p_q->head == NULL) {
            p_q->tail == NULL;
        }
        free(p_rm_ln);
    }
    return p_ret_tn;
}

tree_node_t *g_p_tn = NULL;
void insert_node(queue_t *q, tree_node_t **root, int val) {
    tree_node_t *cur = NULL;
    tree_node_t *new = (tree_node_t *) malloc(sizeof(tree_node_t));
    if (new != NULL) {
        new->val = val;
        new->left = NULL;
        new->right = NULL;
        if (*root == NULL) {
            *root = new;
            push_fifo(q, new);
        } else {
            if (g_p_tn == NULL) {
                cur = pop_fifo(q);
                g_p_tn = cur;
            } else {
                cur = g_p_tn;
            }

            if (cur != NULL) {
                if (cur->left == NULL) {
                    cur->left = new;
                    push_fifo(q, cur->left);
                } else if (cur->right == NULL) {
                    cur->right = new;
                    push_fifo(q, cur->right);
                    g_p_tn = NULL;
                }
            }
        }
    }

    return ;
}

bool isSameTree(struct TreeNode *p, struct TreeNode *q) {
    if (p == NULL && q == NULL) return 1;
    if (p == NULL || q == NULL) return 0;
    
    if (p->val != q->val) {
        return 0;
    } else {
        return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
    }
}

int main()
{

    tree_node_t *root = NULL;
    tree_node_t *root2 = NULL;
    queue_t q = {NULL, NULL};
    queue_t q2 = {NULL, NULL};
    insert_node(&q, &root, 5);
    insert_node(&q, &root, 2);
    insert_node(&q, &root, 2);
    insert_node(&q, &root, 1);
    insert_node(&q, &root, 3);
    insert_node(&q, &root, 3);
    insert_node(&q, &root, 4);

    insert_node(&q2, &root2, 5);
    insert_node(&q2, &root2, 2);
    insert_node(&q2, &root2, 2);
    insert_node(&q2, &root2, 1);
    insert_node(&q2, &root2, 3);
    insert_node(&q2, &root2, 3);
    insert_node(&q2, &root2, 4);

    printf("isSameTree(root, root2)? %s\n", isSameTree(root, root2)? "TRUE": "FALSE");

    return 0;
}
