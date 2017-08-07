#include <stdio.h>
#include <stdlib.h>

typedef struct min_list_s {
    int *ptr;
    struct min_list_s *next;
} min_list_t;

typedef struct min_stack_s {
    int size;
    int head_idx;
    min_list_t *min_ptr;
    int *head_ptr;
    int *stack;
} min_stack_t;

void linkedlist_push(min_list_t **root, int *ptr) {
    min_list_t *cur = *root;
    min_list_t *new = (min_list_t *) malloc(sizeof(min_list_t));
    if (new != NULL) {
        new->ptr = ptr;
        new->next = NULL;
        if (cur == NULL) {
            *root = new;
        } else {
            if (*(cur->ptr) > *ptr) {
                new->next = *root;
                *root = new;
            } else {
                while (cur->next != NULL && *(cur->next->ptr) < *ptr) {
                    cur = cur->next;
                }
                new->next = cur->next;
                cur->next = new;
            }
        }
    }

    return ;
}

void linkedlist_pop(min_list_t **root, int *ptr) {
    min_list_t *prev = NULL;
    min_list_t *cur = *root;
    if (cur != NULL) {
        while (cur != NULL && ptr != cur->ptr) {
            prev = cur;
            cur = cur->next;
        }

        if (prev == NULL) {
            *root = cur->next;
            free (cur);
        } else if (cur != NULL) {
            prev->next = cur->next;
            free (cur);
        } else if (cur == NULL) {
            printf("Fucking Error\n");
        }
    }

    return ;
}

void traversal(min_list_t *root) {
    min_list_t *cur = root;
    while (cur != NULL) {
        printf("%d->", *(cur->ptr));
        cur = cur->next;
    }
    printf("NULL\n");

    return ;
}

min_stack_t* minStackCreate(int maxSize) {
    min_stack_t *new = (min_stack_t *) malloc(sizeof(min_stack_t));
    if (new) {
        new->size = maxSize;
        new->head_idx = -1;
        new->min_ptr = NULL;
        new->head_ptr = NULL;
        new->stack = (int *) malloc(maxSize * sizeof(int));
        if (new->stack == NULL) {
            /* free new structure if failed on allocating stack buffer */
            free(new);
            new = NULL;
        }
    }

    return new;
}

void minStackPush(min_stack_t *obj, int x) {
    if (obj != NULL) {
        if (obj->head_ptr == NULL) {
            obj->head_ptr = obj->stack;
        } else {
            obj->head_ptr++;
        }
        *(obj->head_ptr) = x;
        linkedlist_push(&obj->min_ptr, obj->head_ptr);
    }

    return ;
}

void minStackPop(min_stack_t *obj) {
    if (obj != NULL) {
        if (obj->head_ptr == NULL) {
            return ;
        }
        linkedlist_pop(&obj->min_ptr, obj->head_ptr);
        if (obj->head_ptr == obj->stack) {
            obj->head_ptr = NULL;
        } else {
            obj->head_ptr--;
        }
    }

    return ;
}

int minStackTop(min_stack_t *obj) {
    if (obj != NULL && obj->head_ptr != NULL) {
        return *(obj->head_ptr);
    } else {
        return 0;
    }
}

int minStackGetMin(min_stack_t *obj) {
    if (obj != NULL) {
        if (obj->min_ptr != NULL) {
            return *(obj->min_ptr->ptr);
        }
    }

    return 0;
}

void minStackFree(min_stack_t *obj) {
    if (obj != NULL) {
        if (obj->stack != NULL) {
            free(obj->stack);
        }
        free(obj);
    }

    return ;
}

int main()
{
    min_stack_t *stack = minStackCreate(10);
    minStackPush(stack, 10);
    printf("Top of Stack = %d\n", minStackTop(stack));
    traversal(stack->min_ptr);
    printf("Min = %d\n", minStackGetMin(stack));

    minStackPush(stack, 1);
    printf("Top of Stack = %d\n", minStackTop(stack));
    traversal(stack->min_ptr);
    printf("Min = %d\n", minStackGetMin(stack));

    minStackPush(stack, 5);
    printf("Top of Stack = %d\n", minStackTop(stack));
    traversal(stack->min_ptr);
    printf("Min = %d\n", minStackGetMin(stack));

    minStackPop(stack);
    minStackPop(stack);
    minStackPop(stack);

    minStackFree(stack);

    return 0;
}
