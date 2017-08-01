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
    }

    return ;
}

void traversal(list_node_t *root) {
    while (root != NULL) {
        printf("%d->", root->val);
        root = root->next;
    }
    printf("NULL\n");
}

list_node_t *reverseBetween(list_node_t *head, int m, int n) {
    if (head == NULL || m == n) return head;

    int list_len = 0;
    list_node_t dummy_node = {0, head};
    list_node_t *start = &dummy_node;
    list_node_t *cur = &dummy_node;
    list_node_t *tmp = NULL;

    /*
     * Initialize beginning pointers:
     *   - current pointer -> node m and,
     *   - start pointer -> node m-1
     */
    for (list_len = 0; list_len < m && cur->next != NULL; list_len++) {
        start = cur;
        cur = cur->next;
    }
    /*
     * [Illustration] Swap procedure:
     *      start   cur
     *        1  ->  2  ->  3  ->  NULL
     *                     tmp          // tmp = cur->next
     *                             ^
     *               |_____________|    // cur->next = tmp->next
     *                  <-              // tmp->next = start->next
     *                      ^
     *        |_____________|           // start->next = tmp
     *
     *                _____________
     *               |             |
     *               |             v
     *        1      2  <-  3      NULL
     *                      ^
     *        |_____________|
     *
     */
    for (int i = m; i < n; i++) {
        tmp = cur->next;
        cur->next = tmp->next;
        tmp->next = start->next;
        start->next = tmp;
    }

    return dummy_node.next;
}

int main()
{
    list_node_t *root = NULL;
    insert_node(&root, 100);
    insert_node(&root, 2);
    insert_node(&root, 1);
    insert_node(&root, 10);
    insert_node(&root, 9);
    insert_node(&root, 50);
    traversal(root);

    printf("Reverse list range from 2 to 6\n");
    root = reverseBetween(root, 2, 6);
    traversal(root);

    printf("Reverse list range from 2 to 6\n");
    root = reverseBetween(root, 2, 6);
    traversal(root);

    return 0;
}
