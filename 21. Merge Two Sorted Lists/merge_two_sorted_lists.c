#include <stdio.h>
#include <stdlib.h>

typedef struct ListNode {
    int val;
    struct ListNode *next;
} list_node_t;

void insert_node(list_node_t **root, int val) {
    list_node_t *cur = *root;
    list_node_t *prev = NULL;
    list_node_t *new = (list_node_t *) malloc(sizeof(list_node_t));
    if (new) {
        new->next = NULL;
        new->val = val;
        if (cur == NULL) {
            *root = new;
        } else {
            while (cur != NULL && val > cur->val) {
                prev = cur;
                cur = cur->next;
            }
            if (prev == NULL) {
                new->next = *root;
                *root = new;
            } else {
                prev->next = new;
                new->next = cur;
            }
        }
    }

    return ;
}

list_node_t *mergeTwoLists(list_node_t *l1, list_node_t *l2) {
    list_node_t *head = NULL;
    list_node_t *cur = NULL;
    if (l1 == NULL) return l2;
    if (l2 == NULL) return l1;

    /* Reuse allocated space */
    if (l1->val < l2->val) {
        head = l1;
        l1 = l1->next;
    } else {
        head = l2;
        l2 = l2->next;

    }
    /* Relink by cur pointer */
    cur = head;

    while (l1 != NULL && l2 != NULL) {
        if (l1->val < l2->val) {
            cur->next = l1;
            cur = l1;
            l1 = l1->next;
        } else {
            cur->next = l2;
            cur = l2;
            l2 = l2->next;
        }
    }
    cur->next = (l1 != NULL)? l1: l2;
    
    return head;
}

int main()
{
    list_node_t *root = NULL;
    list_node_t *root2 = NULL;

    insert_node(&root, 5);
    insert_node(&root, 1);
    insert_node(&root, 100);

    for (list_node_t *cur = root; cur != NULL; cur = cur->next) {
        printf("%d->", cur->val);
    }
    printf("NULL\n");

    insert_node(&root2, 2);
    insert_node(&root2, 99);
    insert_node(&root2, 50);
    insert_node(&root2, 70);
    insert_node(&root2, 101);
    for (list_node_t *cur = root2; cur != NULL; cur = cur->next) {
        printf("%d->", cur->val);
    }
    printf("NULL\n");

    list_node_t *merged_root = mergeTwoLists(root, root2);
    for (list_node_t *cur = merged_root; cur != NULL; cur = cur->next) {
        printf("%d->", cur->val);
    }
    printf("NULL\n");
    return 0;
}
