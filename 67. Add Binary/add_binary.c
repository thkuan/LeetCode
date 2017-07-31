#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *addBinary(char *a, char *b) {
    int a_pos = strlen(a), b_pos = strlen(b);
    int ret_pos = (a_pos > b_pos)? a_pos + 2: b_pos + 2;
    int sum = 0, carry = 0;
    char *ret = calloc(ret_pos, sizeof(char));

    a_pos--, b_pos--;
    ret_pos -= 2;
    while (a_pos >= 0 || b_pos >= 0) {
        sum = carry + ((a_pos >= 0)? a[a_pos] - 48: 0) + ((b_pos >= 0)? b[b_pos] - 48: 0);
        carry = sum / 2;
        sum = sum % 2;
        ret[ret_pos--] = sum + 48;
        if (a_pos >= 0) a_pos--;
        if (b_pos >= 0) b_pos--;
    }

    if (carry > 0) {
        ret[ret_pos] = carry + 48;
    } else {
        ret += 1;
    }

    return ret;
}

int main()
{
    char *str1 = "1101";
    char *str2 = "101";
    char *sum_bin_str = addBinary(str1, str2);

    printf("%s + %s = %s\n", str1, str2, sum_bin_str);
    
    return 0;
}
