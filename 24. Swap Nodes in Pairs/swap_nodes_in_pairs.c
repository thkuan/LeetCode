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
        new->val = val;
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

list_node_t *swapPairs(list_node_t *head) {
    list_node_t *ret = NULL;
    list_node_t *prev = NULL, *cur = NULL;
    list_node_t *concatenate = NULL;

    if (head != NULL && head->next != NULL) {
        /* Reuse link by indexing return list head */
        ret = head->next;

        /* Indexing for swap */
        prev = head;
        cur = head->next;
        while (prev != NULL && cur != NULL) {
            /* */
            head = head->next->next;
            /* Swap nodes in pair by reconnection */
            prev->next = cur->next;
            cur->next = prev;

            if (concatenate == NULL) {
                /* Initialize */
                concatenate = prev;
            } else {
                /* Reconnect last pair to current pair */
                concatenate->next = cur;
                concatenate = concatenate->next->next;
            }

            /* Indexing for swap */
            if (head != NULL && head->next != NULL) {
                /* Indexing for swap */
                prev = head;
                cur = head->next;
            } else {
                break;
            }
        }
    }

    return ret;
}

int main()
{
    list_node_t *root = NULL;
    insert_node(&root, 100);
    insert_node(&root, 1);
    insert_node(&root, 10);
    insert_node(&root, 90);
    insert_node(&root, 80);
    insert_node(&root, 6);
    insert_node(&root, 70);
    traversal(root);
    traversal(swapPairs(root));

    return 0;
}
