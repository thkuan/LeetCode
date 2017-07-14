int longestValidParentheses(char* s) {
    int result = 0, compared_result = 0;
    int pos = 0;
    char stack[strlen(s)];
    for (int i = 0; i < strlen(s); i++) {
        if (s[i] == '(') {
            /* Push to stack */
            stack[pos++] = s[i];
        } else if (s[i] == ')') {
            if (pos > 0 && stack[pos-1] == '(') {
                /* Pop from stack, and count correct legth (i.e., pairs * 2) */
                result += 2;
                pos--;

            } else {
                /* If pop out process is terminated, recount correct length, and compare with old record */
                if (result > compared_result) {
                    compared_result = result;
                    result = 0;
                }
            }
        } else {
            // Avoid other chars
            break;
        }
    }
    
    return (result > compared_result)? result : compared_result;
}
