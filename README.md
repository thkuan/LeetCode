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

7. Follow K&R style, the else/else if part of an if-else statement and the while part of a do-while statement should appear on the same line as the close brace
8. Put a space between braces and a condition, all if-else/while/do statements
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
9. All if-else/while/do statements must either have braces or be on a sigle line if only one single statement
```
[Example]:
if (TRUE == val) ret_val = 100;
```
```
[Example]:
if (TRUE == val) {
    ret_val = 100;
}
```


##Reference:
1. https://users.ece.cmu.edu/~eno/coding/CCodingStandard.html
2. http://ieng9.ucsd.edu/~cs30x/indhill-cstyle.html
