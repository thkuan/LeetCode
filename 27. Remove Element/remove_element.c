#include <stdio.h>
#include <stdlib.h>

void swap(int *e1, int *e2) {
    int tmp = *e1;
    *e1 = *e2;
    *e2 = tmp;
    return ;
}

int removeElement(int *nums, int numsSize, int val) {
    int ret_len = numsSize;
    int i = 0;
    while (i < ret_len) {
        if (nums[i] == val) {
            swap(&nums[--ret_len], &nums[i]);
        } else {
            i++;
        }
    }

    return ret_len;
}

int main()
{
    int arr[10] = {3, 2, 3, 3, 4, 7, 6, 8, 3, 3};
    int rm_val = 3;
    int remnants_size = 0;
    
    printf("%d remnants\n", remnants_size = removeElement(&arr[0], 10, rm_val));
    printf("{");
    for (int i = 0; i < remnants_size; i++)
        printf("%d,", arr[i]);
    printf("}\n");

    return 0;
}
