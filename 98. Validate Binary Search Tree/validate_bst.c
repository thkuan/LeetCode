#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

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

int start = 1;

bool isValidSubBST(struct TreeNode* root, int min, int max) {
    /* True if node is NULL */
    if (root == NULL) return 1;
    /* False if node->val is out of bound */
    if (start == 1) {
        start = 0;
        if (root->val < min || max < root->val) return 0;
    } else {
        if (root->val <= min || max <= root->val) return 0;
    }
    /* Search sub-trees on the left and right */
    return isValidSubBST(root->left, min, root->val) &&
        isValidSubBST(root->right, root->val, max);
}

bool isValidBST(struct TreeNode* root) {
    return isValidSubBST(root, INT_MIN, INT_MAX);
}

/* Common error, think of it:
 *        10 
 *       /  \
 *      5   15
 *         /  \
 *        6    20
 */
//bool isValidBST(struct TreeNode* root) {
//    int result = 1;
//    /* Continue checking left child until left == NULL */
//    if (root->left != NULL) {
//        if (root->left->val < root->val) {
//            result &= isValidBST(root->left);
//        } else {
//            /* Interrupt checking once violation BST rule */
//            return 0;
//        }
//    }
//    /* Continue checking right child until right == NULL */
//    if (root->right != NULL) {
//        if (root->val < root->right->val) {
//            result &= isValidBST(root->right);
//        } else {
//            /* Interrupt checking once violation BST rule */
//            return 0;
//        }
//    }
//    
//    return result;
//}

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


int main()
{
    tree_node_t *root = NULL;
    queue_t q;
    q.head = NULL;
    q.tail = NULL;

    insert_node(&q, &root, 5);
    insert_node(&q, &root, 2);
    insert_node(&q, &root, 7);
    insert_node(&q, &root, 1);
    insert_node(&q, &root, 3);
    insert_node(&q, &root, 6);
    insert_node(&q, &root, 8);

    printf("isValidBST(root)? %s\n", isValidBST(root)? "TRUE": "FALSE");
    
    return 0;
}
