#include <stdio.h>
#include <stdlib.h>

int reverse(int x) {
    int new = 0, left = 0;
    while (x != 0) {
        left = x % 10;
        new = new * 10 + left;
        x = x / 10;
    }
    return new;
}

int main()
{
    int test = -198765;
    
    printf("%d -> %d\n", test, reverse(test));

    return 0;
}
