#include <stdio.h>
#include <stdlib.h>

typedef struct tree_node_s {
    struct tree_node_s *left;
    struct tree_node_s *right;
    int value;
} tree_node_t;

typedef struct stack_node_s {
    struct stack_node_s *next;
    tree_node_t *ptr_val;
} stack_node_t;

void push_stack(stack_node_t **head, tree_node_t *ptr_val) {
    stack_node_t *new = (stack_node_t *) malloc(sizeof(stack_node_t));
    if (new) {
        new->ptr_val = ptr_val;
        new->next = NULL;

        if (*head == NULL) {
            *head = new;
        } else {
            new->next = *head;
            *head = new;
        }
    }

    return ;
}

tree_node_t *pop_stack(stack_node_t **head) {
    stack_node_t *rm = NULL;
    tree_node_t *ret_ptr = 0;
    if (*head != NULL) {
        rm = *head;
        *head = (*head)->next;
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

int *preorder_traversal(tree_node_t *root, int *size) {
    tree_node_t *cur = root;
    stack_node_t *s = NULL;
    int *ret = (int *) calloc(1024, sizeof(int));
    int pos = 0;
    
    push_stack(&s, root);
    while (s != NULL) {
        cur = pop_stack(&s);
        if (cur != NULL) {
            ret[pos++] = cur->value;
            if (cur->right) {
                push_stack(&s, cur->right);
            }
            if (cur->left) {
                push_stack(&s, cur->left);
            }
        }
    }

    return ret;
}

int main()
{
    int *ptr = NULL;
    int size = 0;
    tree_node_t *root = NULL;
    insert_node(&root, 3);
    insert_node(&root, 1);
    insert_node(&root, 2);
    insert_node(&root, 4);
    insert_node(&root, 5);

    ptr = preorder_traversal(root, &size);

    while (*ptr != 0) {
        printf("%d", *ptr);
        ptr++;
    }
    printf("\n");

    return 0;
}
