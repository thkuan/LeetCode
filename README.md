Continuing practice is the way to keep thinking

## C/C++ Coding Style
1. Indent with 4 spaces instead of tabs

2. Put #defines and macros in all upper using '_' separators
3. Use "do { ... } while (0)" if the macro is more than a single statement, so that a trailing semicolon works.
```
[Example]:
#define TRUE (1)
#define FALSE (0)
#define DBG_PRINT(fmt, ...)        \
do {                               \
    printf(fmt, ##__VA_ARGS__);    \
} while(0)
```
4. Use all lower case letters and '_' separators for variable names
5. Prefix g_ to a global variable name
6. Place the * close to the variable name not pointer type
```
[Example]:
int g_cnt = 0;
void func() {
    int left_idx = 0;
    char *c_ptr = NULL;
    int **ptr = NULL;
}
```
7. Put a space between parenthes and a condition, all if-else/while/do statements, or braces
```
[Example]:
if (condition) {
    ...
} else if {
    ...
}
```
```
[Example2]:
do {
    ...
} while(1);
```

8. All if-else/while/do statements require braces even if there is only a single statement within the braces.
```
[Example]:
if (TRUE == val) ret_val = 100;
```

##Reference:
1. https://users.ece.cmu.edu/~eno/coding/CCodingStandard.html
2. http://ieng9.ucsd.edu/~cs30x/indhill-cstyle.html
