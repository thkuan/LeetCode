/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
typedef struct TreeNode tree_node_t;
typedef struct list_node_s {
    struct TreeNode *ptr;
    struct list_node_s *next;
} list_node_t;

void push(list_node_t **stack, tree_node_t *ptr) {
    if (ptr != NULL) {
        list_node_t *new = (list_node_t *) malloc(sizeof(list_node_t));
        if (new != NULL) {
            new->ptr = ptr;
            new->next = NULL;
            if (*stack == NULL) {
                *stack = new;
            } else {
                new->next = *stack;
                *stack = new;
            }
        }
    }
    
    return ;
}

tree_node_t *pop(list_node_t **stack) {
    tree_node_t *ret = NULL;
    if (*stack != NULL) {
        list_node_t *rm = *stack;
        *stack = (*stack)->next;
        ret = rm->ptr;
        free(rm);
    }
    
    return ret;
}

void flatten(struct TreeNode* root) {
    list_node_t *stack = NULL;
    tree_node_t *cur = NULL;
    tree_node_t *tmp = root;
    
    push(&stack, root);
    while (stack != NULL) {
        cur = pop(&stack);
        if (cur != NULL) {
            if (tmp != cur) {
                tmp->left = NULL;
                tmp->right = cur;
                tmp = cur;
            }
            if (cur->right != NULL) {
                push(&stack, cur->right);
            }
            if (cur->left != NULL) {
                push(&stack, cur->left);
            }
        }
    }
    return root;
}
