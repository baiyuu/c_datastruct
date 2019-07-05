
#include <stddef.h>
#include <stdio.h>
#include <malloc.h>

#define  M 1000
typedef int StackElement;
typedef struct Node {
    StackElement data;
    struct Node *link;
} StackNode, *LinkStack;

int getTop(LinkStack stack, StackElement e);

int push(LinkStack *stack, StackElement e);

void initStack(LinkStack *stack);

int pop(LinkStack *stack, StackElement e);

int main() {
    test2();
    return 0;
}


#define N 1000
int matrix[N][N];

 

test2() {
    convert8To10_sqStack(391);
    puts("");
    convert8To10_linkStack(391);
}

test() {
    LinkStack stack;
    initStack(&stack);
    stack = (LinkStack) malloc(sizeof(StackNode));
    stack->data = 1;
    push(&stack, 444);
    StackElement *e;
    getTop(stack, e);
    pop(&stack, e);
    getTop(stack, e);

}


void initStack(LinkStack *stack) {
    *stack = NULL;
}

int isEmpty(LinkStack stack) {
    return stack == NULL;
}

//get top elemetn
int getTop(LinkStack stack, StackElement e) {
    if (isEmpty(stack)) {
        return 0;
    } else {
        e = stack->data;
        printf("top: %d\n", e);
        return 1;
    }
}

// add a element
int push(LinkStack *stack, StackElement e) {
    LinkStack p;
    if (!(p = (LinkStack) malloc(sizeof(StackNode)))) {
        return 0;
    } else {
        p->data = e;
        p->link = *stack;
        *stack = p;
        return 1;
    }
}

// delete a element return the deleted element  
int pop(LinkStack *stack, StackElement e) {
    LinkStack p;
    if (isEmpty(*stack)) {
        return 0;
    } else {
        p = *stack;
        e = p->data;
        *stack = p->link;
        return 1;
    }
}

/*
 * stack example 
*/

/**
 * 十进制转八进制 顺序堆栈实现
 */
void convert8To10_sqStack(int num) {
    int Stack[M], top = -1;
    do {
        Stack[++top] = num % 8;
        num = num / 8;
    } while (num != 0);

    while (top >= 0) {
        printf("%d", Stack[top--]);
    }

}

/*
* 十进制转八进制 链式堆栈实现
*/
void convert8To10_linkStack(int num) {
    LinkStack p, top = NULL;
    do {
        p = (LinkStack) malloc(sizeof(StackNode));
        p->data = num % 8;
        p->link = top;
        top = p;
        num = num / 8;
    } while (num != 0);

    while (top != NULL) {
        p = top;
        printf("%d", p->data);
        top = top->link;
        free(p);
    }
}

