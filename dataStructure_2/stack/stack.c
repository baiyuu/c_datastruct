/**
 * 线性表 堆栈结构
 */

#define MAXSIZE 1000

runStack() {


}

/**
 * 8. 堆栈的共享空间删除元素
 * @param stack 
 * @param top 
 * @param i 
 * @return 
 */
int POP2(int stack[], int top[], int i) {
    if (i == 0) {
        if (top[0] == -1) {
            return 0;
        }
        top[0]--;
    } else {
        if (top[1] == (MAXSIZE - 1)) {
            return 0;
        }
        top[1]++;
    }
    return 1;
}

/**
 * 7. 堆栈的共享空间插入元素
 * @param sstack 
 * @param top 
 * @param item 
 * @return 
 */
int PUSH2(int stack[], int top[], int i, int item) {

    if (top[0] == top[1] - 1) {
        return -1;
    }

    if (i == 0) {
        top[0]++;
    } else {
        top[1]--;
    }

    stack[top[i]] == item;
    return 1;

}


/**
 * 6. 取栈顶元素
 * @param stack 
 * @param top 
 * @param item 
 * @return 
 */
int POPFIRSTSTACK(int stack[], int top, int *item) {
    if (STACKEMPTY(top)) {
        return -1;
    }
    *item = stack[top];
    return 1;
}

/**
 * 5. 出栈
 * @param stack 
 * @param top 
 * @return 
 */
int POSTACKP(int stack[], int top) {
    if (STACKEMPTY(top)) {
        return -1;
    }

    top--;
    return 1;

}

/**
 * 4. 进栈
 * @param stack 
 * @param top 
 * @param item 
 * @return 
 */
int PUSHSTACK(int stack[], int top, int item) {

    if (FULL(top)) {
        return -1;
    }

    stack[top++] = item;
    return 1;
}

/**
 * 3. 是否满栈
 * @param top 
 * @return 
 */
int FULL(int top) {
    return top == MAXSIZE;
}

/**
 * 2. 是否为空
 * @param top 
 * @return 
 */
int STACKEMPTY(int top) {
    return top == -1;
}

/**
 * 1. 初始化堆栈
 * @param top 
 */
void INITSTACK(int *top) {
    *top = -1;
}
