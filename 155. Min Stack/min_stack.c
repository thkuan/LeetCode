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
    }

    return ;
}

void minStackPop(min_stack_t *obj) {
    if (obj != NULL) {
        if (obj->head_ptr == NULL) {
            return ;
        } else if (obj->head_ptr == obj->stack) {
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
    printf("%d\n", minStackTop(stack));

    minStackPush(stack, 1);
    printf("%d\n", minStackTop(stack));

    minStackPush(stack, 5);
    printf("%d\n", minStackTop(stack));
    minStackPop(stack);
    minStackPop(stack);
    minStackPop(stack);

    minStackFree(stack);

    return 0;
}
