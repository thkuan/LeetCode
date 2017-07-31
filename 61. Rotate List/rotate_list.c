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
    }
    if (cur == NULL) {
        *root = new;
    } else {
        if (val < cur->val) {
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

void traversal(list_node_t *root) {
    while(root != NULL) {
        printf("%d->", root->val);
        root = root->next;
    }
    printf("NULL\n");

    return ;
}

list_node_t *rotateRight(list_node_t *head, int k) {
    /*
     * 1->2->3->4->5->NULL and k = 2
     * => 4->5->1->2->3->NULL
     */
    int list_len = 1;
    list_node_t *cur = head;
    if (head == NULL || k == 0) return head;

    /* Traverse list first */
    while (cur->next != NULL) {
        cur = cur->next;
        list_len++;
    }
    /* How many shifts? */
    k = list_len - k % list_len;

    /* Make it a circular list */
    cur->next = head;
    /* Rotate to retreive head */
    while (k-- > 0) {
        cur = cur->next;
    }
    head = cur->next;
    cur->next = NULL;

    return head;
}

int main()
{
    list_node_t *root = NULL;
    insert_node(&root, 100);
    insert_node(&root, 2);
    insert_node(&root, 1);
    insert_node(&root, 10);
    insert_node(&root, 101);
    traversal(root);

    root = rotateRight(root, 3);
    traversal(root);

    return 0;
}
