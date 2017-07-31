#include <stdio.h>
#include <stdlib.h>

typedef struct list_node_s {
    int val;
    struct list_node_s *next;
} list_node_t;

void insert_node(list_node_t **root, int val) {
    list_node_t *cur = *root;
    list_node_t *new = (list_node_t *) malloc(sizeof(list_node_t));
    if (new != NULL) {
        new->next = NULL;
        new->val = val % 10;
    }
    if (cur == NULL) { 
        *root = new;
    } else {
        while (cur->next != NULL) {
            cur = cur->next;
        }
        cur->next = new;
    }

    return ;
}

void traversal(list_node_t *root) {
    while (root != NULL) {
        printf("%d->", root->val);
        root = root->next;
    }
    printf("NULL\n");

    return ;
}

list_node_t *addTwoNumbers(list_node_t *l1, list_node_t *l2) {
    int carry = 0;
    int sum = 0;
    list_node_t ret = {0, NULL};
    list_node_t *cur = &ret, *new = NULL;

    if (l1 == NULL) {
        return l2;
    }
    if (l2 == NULL) {
        return l1;
    }

    while (l1 != NULL || l2 != NULL) {
        sum = carry + ((l1 != NULL)? l1->val: 0) +  ((l2 != NULL)? l2->val: 0); 
        carry = sum / 10;
        sum = sum % 10;
        new = (list_node_t *) malloc(sizeof(list_node_t));
        if (new != NULL) {
            new->val = sum;
            new->next = NULL;
        }
        cur->next = new;
        cur = cur->next;

        if (l1 != NULL) {
            l1 = l1->next;
        }
        if (l2 != NULL) {
            l2 = l2->next;
        }
    }

    if (carry != 0) {
        new = (list_node_t *) malloc(sizeof(list_node_t));
        if (new != NULL) {
            new->val = carry;
            new->next = NULL;
        }
        cur->next = new;
        cur = cur->next;
    }

    return ret.next;
}

int main()
{
    list_node_t *root = NULL;
    list_node_t *root2 = NULL;
    list_node_t *sum_root = NULL;
    insert_node(&root, 2);
    insert_node(&root, 4);
    insert_node(&root, 3);
    insert_node(&root, 9);
    insert_node(&root2, 5);
    insert_node(&root2, 6);
    insert_node(&root2, 6);
    traversal(root);
    traversal(root2);

    sum_root = addTwoNumbers(root, root2);
    traversal(sum_root);

    return 0;
}
