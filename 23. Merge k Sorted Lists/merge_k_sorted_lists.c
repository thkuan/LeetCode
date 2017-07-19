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


list_node_t *mergeKLists(list_node_t **lists, int listsSize) {
    for (int i = 1; i < listsSize; i++) {
        lists[0] = mergeTwoLists(lists[0], lists[i]);
    }

    return lists[0];
}

int main()
{
    list_node_t *list_root[3] = {NULL};
    list_node_t **lists = &list_root[0];
    list_node_t *merged_list = NULL;

    insert_node(&list_root[0], 5);
    insert_node(&list_root[0], 7);
    insert_node(&list_root[0], 100);
    for (list_node_t *cur = list_root[0]; cur != NULL; cur = cur->next) {
        printf("%d->", cur->val);
    }
    printf("NULL\n");

    insert_node(&list_root[1], 2);
    insert_node(&list_root[1], 99);
    insert_node(&list_root[1], 50);
    insert_node(&list_root[1], 70);
    insert_node(&list_root[1], 101);
    for (list_node_t *cur = list_root[1]; cur != NULL; cur = cur->next) {
        printf("%d->", cur->val);
    }
    printf("NULL\n");

    
    insert_node(&list_root[2], 1);
    for (list_node_t *cur = list_root[2]; cur != NULL; cur = cur->next) {
        printf("%d->", cur->val);
    }
    printf("NULL\n");

    /* Merge K sorted lists */
    merged_list = mergeKLists(lists, 3);
    for (list_node_t *cur = merged_list; cur != NULL; cur = cur->next) {
        printf("%d->", cur->val);
    }
    printf("NULL\n");

    return 0;
}
