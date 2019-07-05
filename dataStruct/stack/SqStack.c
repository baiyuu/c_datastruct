#include <stdio.h>

#define  M 1000
typedef int StackEle;
StackEle stacks[M];
int top;
typedef struct {
    StackEle *base;
    StackEle *top;
    int stackSize;
} SqStack;

int main() {
    test();
    return 0;
}

test() {
    initStack(&top);
    printf("%d", top);
}

void initStack(int *top) {
    *top = -1;
}

int isEmpty(int *top) {
    return *top == -1;
}

int isFull(int *top) {
    return *top == M - 1;
}

int getTopEle(StackEle stacks[], int top, StackEle *item) {
    if (isEmpty(top)) {
        return 0;
    } else {
        item = stacks[top];
        return 1;
    }
}

int push(StackEle stacks[], int top, StackEle *item) {
    if (isFull(top)) {
        return 0;
    } else {
        stacks[++top] = item;
        return 1;
    }
}

int pop(StackEle stacks[], int top, StackEle *item) {
    if (isEmpty(top)) {
        return 0;
    } else {
        item = stacks[top--];
        return 1;
    }
}

/* 多个堆栈共享连续的空间*/

/**
    * 将 2 个堆栈映射到一片大小为M的存储空间上 
    * top[0] = top[1]-1 满栈
    *   top[0] 0-1-2-3-4-5-6-7-8-9 top[1]
        top[0] = 4  top[1]=5  此时满了  top[0]=top[1]-1
 * @param stackEle  
 * @param top  每个 堆栈的位置
 * @param i     插入到第几个堆栈中
 * @param item  插入的元素
 * @return 
 */
int push2(StackEle stackEle[], int top[], int i, StackEle item) {
    if (top[0] = top[1] - 1) {
        return 0;
    } else {
        if (i == 1) {
            top[0]++;
        } else {
            top[1]--;
        }
        stackEle[top[i - 1]] = item;
        return 1;
    }

}

int pop2(StackEle arr[], int top[], int i, StackEle item) {
    if (i == 1) {
        if (top[0] == -1) {
            return 0;
        } else {
            item = arr[top[0]--];
            return 1;
        }
    } else {
        if (top[1] == M) {
            return 0;
        } else {
            item = arr[top[1]++];
            return 1;
        }
    }

}













