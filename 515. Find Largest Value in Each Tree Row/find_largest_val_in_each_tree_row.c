#include <stdio.h>
#include <stdlib.h>

typedef struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
} tree_node_t;

typedef struct list_node_s {
    tree_node_t *ptr;
    struct list_node_s *next;
} list_node_t;

typedef struct queue_s {
    list_node_t *head;
    list_node_t *tail;
} queue_t;

void push_fifo(queue_t *q, tree_node_t *ptr) {
    if (ptr != NULL) {
        list_node_t *new = (list_node_t *) malloc(sizeof(list_node_t));
        if (new != NULL) {
            new->next = NULL;
            new->ptr = ptr;
            if (q->head == NULL && q->tail == NULL) {
                q->head = new;
                q->tail = new;
            } else {
                q->tail->next = new;
                q->tail = new;
            }
        }
    }

    return ;
}

tree_node_t *pop_fifo(queue_t *q) {
    tree_node_t *ret_tn = NULL;
    list_node_t *rm = NULL;
    if (q->head != NULL) {
        rm = q->head;
        ret_tn = rm->ptr;
        q->head = q->head->next;
        if (q->head == NULL) {
            q->tail = NULL;
        }
        free(rm);
    }

    return ret_tn;
}

int max_depth(tree_node_t *root) {
    if (root == NULL) return 0;
    else {
        int l_d = max_depth(root->left) + 1;
        int r_d = max_depth(root->right) + 1;
        return (l_d > r_d)? l_d: r_d;
    }
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

int *largestValues(struct TreeNode *root, int *returnSize) {
    queue_t q = {NULL, NULL};
    *returnSize = max_depth(root);
    int *ret_arr = (int *) calloc(*returnSize, sizeof(int));

    *returnSize = 0;

    if (root == NULL) return NULL;
    else {
        tree_node_t *cur = NULL;
        int cur_level = 1, next_level = 0, cnt = 0;
        int pick_max = 0;

        push_fifo(&q, root);
        while (q.head != NULL) {
            cur = pop_fifo(&q);
            cnt++;
            if (cur != NULL) {
                if (cur->val > pick_max) {
                    pick_max = cur->val;
                }
                if (cur->left != NULL) {
                    push_fifo(&q, cur->left);
                    next_level++;
                }
                if (cur->right != NULL) {
                    push_fifo(&q, cur->right);
                    next_level++;
                }
            }

            if (cnt == cur_level) {
                cur_level = next_level;
                cnt = 0;
                next_level = 0;
                ret_arr[(*returnSize)++] = pick_max;
                pick_max = 0;
            }
        }
    }

    return ret_arr;
}

int main()
{
    int *int_array = NULL;
    int size = 0;
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

    int_array = largestValues(root, &size);
    for (int i = 0; i < size; i++) {
        printf("%d ", *(int_array + i));
    }
    printf("\n");

    return 0;
}
