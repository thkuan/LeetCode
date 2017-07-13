#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int swap(char *a, char *b) {
    static int cnt = 0;
    char tmp = *a;
    *a = *b;
    *b = tmp;
    cnt++;
    return cnt;
}

void permute(char *arr, int l, int r) {
    if (l == r) {
        printf("%s\n", arr);
    } else {
#if 1
        /* Scan the tree leaves from left to right */
        for (int i = l; i <= r; i++) {
            swap(&arr[l], &arr[i]);
            permute(arr, l+1, r);
            swap(&arr[l], &arr[i]);
#else
        /* Scan the tree leaves from right to left */
        for (int i = r; i >= l; i--) {
            swap(&arr[l], &arr[i]);
            permute(arr, l+1, r);
            swap(&arr[l], &arr[i]);
#endif
        }
    }
}

int main() 
{
    //char arr[] = {'A', 'B', 'C', '\0'};
    char arr[] = "ABC";
    int len = (int) strlen(arr);
    permute(arr, 0, len-1);

    return 0;
}

