#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define bool int

bool is_valid(char *s) {
    bool ret = 0;
    char stack[strlen(s)];
    int pos = 0;

    for (int i = 0; i < strlen(s); i++) {
        if (s[i] == '[' || s[i] == '(' || s[i] == '{') {
            // Push to stack
            stack[pos++] = s[i];
        } else if (s[i] == ']' || s[i] == ')' || s[i] == '}') {
            // Pop out the stack
                if (s[i] == ']' && stack[pos-1] == '[') pos--;
                else if (s[i] == ')' && stack[pos-1] == '(') pos--;
                else if (s[i] == '}' && stack[pos-1] == '{') pos--;
                else break;
        } else {
            // Avoid other chars
            break;
        }
    }
    if (pos == 0) ret = 1;
    return ret;
}

int main()
{
    char *s = "({[](){[[]]}})";
    //char *s = "(]";
    //char *s = "([)]";
    printf("%s is valid? %s\n", s, (is_valid(s) == 1)? "True": "False");
    return 0;
}
