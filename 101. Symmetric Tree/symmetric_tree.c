#include <stdio.h>
#include <stdlib.h>

typedef int bool;

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

bool mirror(tree_node_t *l_tree, tree_node_t *r_tree) {
    /* if both of compared nodes are null, return TRUE */
    if (l_tree == NULL && r_tree == NULL) return 1;
    /* if one of compared nodes is null, it's not symmetric */
    if (l_tree == NULL || r_tree == NULL) return 0;
    return (l_tree->val == r_tree->val) &&
        mirror(l_tree->left, r_tree->right) &&
        mirror(l_tree->right, r_tree->left);
}

bool isSymmetric(tree_node_t *root) {
    return (root == NULL)? 1: mirror(root->left, root->right);
}

void push_fifo(queue_t *q, tree_node_t *p_tn) {
    list_node_t *new = (list_node_t *) malloc(sizeof(list_node_t));
    if (new != NULL) {
        new->p_tn = p_tn;
        new->next = NULL;
        if (q->head == NULL && q->tail == NULL) {
            q->head = new;
            q->tail = new;
        } else {
            q->tail->next = new;
            q->tail = new;
        }
    }

    return ;
}

tree_node_t *pop_fifo(queue_t *q) {
    tree_node_t *p_tn = NULL;
    list_node_t *rm = NULL;

    if (q->head != NULL) {
        rm = q->head;
        p_tn = rm->p_tn;
        q->head = q->head->next;
        if (q->head == NULL) {
            q->tail = NULL;
        }
        free(rm);
    }
    return p_tn;
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

void traversal(tree_node_t *root) {
    if (root != NULL) {
        traversal(root->left);
        printf("%d ", root->val);
        traversal(root->right);
    }
    return ;
}

int main()
{
    tree_node_t *root = NULL;
    queue_t q;
    q.head = NULL;
    q.tail = NULL;

    insert_node(&q, &root, 5);
    insert_node(&q, &root, 2);
    insert_node(&q, &root, 2);
    insert_node(&q, &root, 1);
    insert_node(&q, &root, 3);
    insert_node(&q, &root, 3);
    insert_node(&q, &root, 4);
    traversal(root);printf("\n");

    printf("isSymmetric(root)? %s\n", isSymmetric(root)? "TRUE": "FALSE");
    
    return 0;
}
