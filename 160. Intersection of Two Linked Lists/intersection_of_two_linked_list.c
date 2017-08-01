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

    return ;
}

list_node_t *getIntersectionNode(list_node_t *headA, list_node_t *headB) {
    /* No intersection between two lists if either one is NULL */
    if (headA == NULL || headB == NULL) return NULL;

    list_node_t *fast = NULL;
    list_node_t *slow = NULL;
    list_node_t *headA_end = headA;

    /* Scan one list to reach its end to concatenate headB */
    while (headA_end->next != NULL) {
        headA_end = headA_end->next;
    }
    headA_end->next = headB;

    fast = headA;
    slow = headA;
    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
        /* There must be a cycle if an intersection exists */
        if (fast == slow) {
            slow = headA;
            /* Find the intersection */
            while (slow != fast) {
                slow = slow->next;
                fast = fast->next;
            }
            /* Recover headA list */
            headA_end->next = NULL;
            return slow;
        }
    }

    /* Recover headA list */
    headA_end->next = NULL;

    return NULL;
}

int main()
{
    list_node_t *root = NULL;
    list_node_t *root2 = NULL;
    list_node_t *cur = NULL;
    list_node_t *intersect = NULL;
    insert_node(&root, 100);
    insert_node(&root, 2);
    insert_node(&root, 1);
    insert_node(&root, 5);
    insert_node(&root, 101);
    insert_node(&root, 9);
    traversal(root);
    insert_node(&root2, 4);
    insert_node(&root2, 3);
    insert_node(&root2, 6);
    traversal(root2);
    intersect = getIntersectionNode(root, root2);
    printf("getIntersectionNode(root, root2)? %s, intersect node has val = %d\n", \
            (intersect != NULL)? "TRUE": "FALSE", \
            (intersect != NULL)? intersect->val: -1);

    /* Create scenario */
    cur = root2;
    while (cur->next != NULL) {
        cur = cur->next;
    }
    cur->next = root->next;
    traversal(root);
    traversal(root2);
    intersect = getIntersectionNode(root, root2);
    printf("getIntersectionNode(root, root2)? %s, intersect node has val = %d\n", \
            (intersect != NULL)? "TRUE": "FALSE", \
            (intersect != NULL)? intersect->val: -1);

    return 0;
}
