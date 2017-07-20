#include <stdio.h>
#include <stdlib.h>

typedef int bool;

typedef struct ListNode {
    int val;
    struct ListNode *next;
} list_node_t;

bool hasCycle(struct ListNode *head) {
    list_node_t *fast = head;
    list_node_t *slow = head;

    while (fast != NULL && fast->next != NULL) {
        fast = fast->next->next;
        slow = slow->next;
        if (slow == fast) {
            return 1;
        }
    }
    return 0;
}

void insert_node(list_node_t **root, int val) {
    list_node_t *cur = *root;
    list_node_t *new = (list_node_t *) malloc(sizeof(list_node_t));
    
    if (new != NULL) {
        new->val = val;
        new-> next = NULL;
    }
    if (cur == NULL) {
        *root = new;
    } else {
        while (cur->next != NULL && val > cur->next->val) {
            cur = cur->next;
        }
        if (cur == *root) {
            if (val < cur->val) {
                new->next = *root;
                *root = new;
            } else {
                new->next = cur->next;
                cur->next = new;
            }
        } else {
            new->next = cur->next;
            cur->next = new;
        }
    }

    return ;
}

void print_list(list_node_t *root) {
    while (root != NULL) {
        printf("%d->", root->val);
        root = root->next;
    }
    printf("NULL\n");
    
    return ;
}

int main()
{
    list_node_t *root = NULL;
    list_node_t *root2 = NULL;
    list_node_t *cur = NULL;

    insert_node(&root, 3);
    insert_node(&root, 1);
    insert_node(&root, 2);
    insert_node(&root, 6);
    insert_node(&root, 0);
    print_list(root);
    cur = root;
    while (cur->next != NULL) {
        cur = cur->next;
    }
    cur->next = root->next;

    insert_node(&root2, 3);
    print_list(root2);
    root2->next = root2;
    /*insert_node(&root2, 1);
    insert_node(&root2, 2);
    insert_node(&root2, 6);
    insert_node(&root2, 0);*/

    printf("hasCycle(root)? %s\n", hasCycle(root)? "TRUE": "FALSE");
    printf("hasCycle(root2)? %s\n", hasCycle(root2)? "TRUE": "FALSE");

    return 0;
}
