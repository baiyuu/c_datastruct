/**
 * 堆栈的应用
 */

#include <stdio.h>

#define  MAXSIZE 1000

runstacapply() {
//    char c[] = {'{', 's', 'a', ')', '('};
//    strCheck(c, 4);
    conversion(391, 8);
}


/**
 * 2. 数值转换
 * @param num 
 * @return 
 */
int conversion(int num, int b) {
    int stack[MAXSIZE], top = -1;

    do {

        stack[++top] = num % b;
        num /= b;

    } while (num);

    while (top > -1) {
        printf("%d", stack[top--]);
    }

}

/**
 * 1. 简单符号匹配检查
 * @param c 
 * @param n 
 * @return 
 */
int strCheck(char c[], int n) {
    int i = 0, top = -1;

    char stack[MAXSIZE];
    while (i < n) {
        if (c[i] == '{' || c[i] == '(') {
            stack[++top] = c[i];
        }

        printf("%d \t", top);
        if (c[i] == ')') {
            if (stack[top--] != '(') {
                printf("illegeal input! ");
                return -1;
            }
        }
        if (c[i] == '}') {
            if (stack[top--] != '{') {
                printf("illegeal input!");
                return -1;
            }
        }
        i++;
    }


    if (top != -1) {
        printf("illegeal input!");
        return -1;
    }

    printf("ok!");
    return 1;
}
