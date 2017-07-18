**[Reference]**:
1. [https://leetcode.com/](https://leetcode.com/)
2. [https://github.com/soulmachine/leetcode](https://github.com/soulmachine/leetcode)
3. [https://github.com/lennylxx/leetcode](https://github.com/lennylxx/leetcode)

## C Coding Style
1. Include files should protect against multiple inclusion through the use of macros that "guard" the files.
``` C
#ifndef MY_SOCKET_H
#define MY_SOCKET_H  /* NOT _MY_SOKCET_H_ */
...
#endif
```
2. Indent with 4 spaces instead of tabs

3. Put #define and macros in all upper using '_' separators
4. Wrap the expression in macros with parenthesis to avoid potential communitive operation abiguity.
``` C
#define TRUE (1)
#define FALSE (0)
#define ADD(x,y) ((x) + (y))
```
5. Use "do { ... } while (0)" if the macro is more than a single statement, so that a trailing semicolon works.
``` C
#define TRUE (1)
#define FALSE (0)
#define DBG_PRINT(fmt, ...)        \
do {                               \
    printf(fmt, ##__VA_ARGS__);    \
} while(0)
```
6. Use all lower case letters and '_' separators for variable names
7. Prefix g_ to a global variable name
8. Place the * close to the variable name not pointer type
``` C
int g_cnt = 0;
void func() {
    int left_idx = 0;
    char *c_ptr = NULL;
    int **ptr = NULL;
}
```
9. Declare structure names with a suffix '_s' and define its type by a suffix '_t'
``` C
struct node_s {
    int value;
    struct node_s * ext;
};
typedef struct node_s node_t;
```

10. Follow K&R style, the else/else if part of an if-else statement and the while part of a do-while statement should appear on the same line as the close brace
``` C
if (condition) {
    ...
} else {
^^^^^^
    ...
}
```
11. Put a space between braces and keywords of if-else/while/do statements, and condition
``` C
if (condition) {
              ^
    ...
} else {
 ^    ^
    ...
}
```
``` C
do {
  ^
    ...
} while (1);
 ^
```
12. Put a space between conditions and keywords of if-else/for/while/do statements
``` C
if (condition) {
  ^
    ...
}
```
13. All if-else/for/while/do statements must either have braces or be on a sigle line if only one single statement
``` C
if (condition) {
    ret_val = 100;
}
// or
if (condition) ret_val = 100;
```
14. Put spaces inside a condition of each expression except the start and end of parenthesis, and at the end of semicolons 
``` C
if (TRUE == val && FALSE == val2) {
   ^    ^  ^   ^  ^     ^  ^    ^
    ...
}
```
``` C
for (int i = 0; i < size; i++) {
    ^   ^ ^ ^ ^^ ^ ^    ^^   ^
    ...
}
```
15. DO NOT put spaces inside brackets
``` C
int arr[] = {1, 2, 3, 4, 5, 6};
int sum = 0;
for (int i = 0; i < 3; i++) {
    sum = arr[2*i];
              ^^^
    ...
}
```
16. Sugget to put the constant on the left hand side of an equality/inequality comparison.
17. MUST document Null Statements
``` C
while (*dest++ = *src++) {
    ;
} 
// or
while (*dest++ = *src++) ;
```


**[Reference]**:
1. https://users.ece.cmu.edu/~eno/coding/CCodingStandard.html
2. http://ieng9.ucsd.edu/~cs30x/indhill-cstyle.html
