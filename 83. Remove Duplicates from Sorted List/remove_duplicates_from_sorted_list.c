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
        new->val = val;
        new->next = NULL;
    } else {
        printf("Failed to allocate the memory of node_t: %d not inserted\n", val);
    }

    if (cur == NULL) {
        *root = new;
    } else {
        if (val <= cur->val) {
            new->next = *root;
            *root = new;
        } else {
            while (cur->next != NULL && val > cur->next->val) {
                cur = cur->next;
            }
            new->next = cur->next;
            cur->next = new;
        }
    }

    return ;
}

void traverse(list_node_t *root) {
    list_node_t *scan = root;
    while (scan != NULL) {
        printf("%d->", scan->val);
        scan = scan->next;
    }
    printf("NULL\n");

    return ;
}

list_node_t *delete_duplicates(list_node_t *head) {
    list_node_t *prev = NULL;
    list_node_t *cur = head;
    list_node_t *rm = NULL;

    if (cur != NULL) {
        prev = cur;
        cur = cur->next;
    }
    while (cur != NULL) {
        if (prev->val == cur->val) {
            prev->next = cur->next;
            rm = cur;
            cur = cur->next;
            free(rm);
        } else {
            prev = cur;
            cur = cur->next;
        }
    }

    return head;
}

int main()
{
    list_node_t *root = NULL;
#if 1
    insert_node(&root, 100);
    insert_node(&root, 1000);
    insert_node(&root, 1000);
    insert_node(&root, 1000);
    insert_node(&root, 10);
    insert_node(&root, 10);
    insert_node(&root, 9);
    insert_node(&root, 8);
    insert_node(&root, 9);
    insert_node(&root, 1);
    insert_node(&root, 1);
    insert_node(&root, 1);
    insert_node(&root, 1);
#else
    insert_node(&root, 1);
    insert_node(&root, 1);
    insert_node(&root, 2);

#endif
    traverse(root);

    traverse(delete_duplicates(root));

    return 0;
}
