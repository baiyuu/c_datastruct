#include <stddef.h>
#include <malloc.h>

/**
 * 链式堆栈结构
 */

#define  newStackLink() (StackLink)malloc(sizeof(SNode));
typedef int StackType;

typedef struct node {
    StackType data;
    struct node *link;

} SNode, *StackLink;


runlinkstack() {

}

/**
 * 5. 删除
 * @param top 
 * @param data 
 * @return 
 */
int POP(StackLink top, StackType *data) {
    if (EMPTY(top)) {
        return -1;
    }
    StackLink p = top;
    data = top->data;
    top = top->link;
    free(p);
    return 1;
}

/**
 * 4. 插入元素
 * @param top 
 * @param data 
 * @return 
 */
int PUSH(StackLink top, StackType data) {
    StackLink p = newStackLink();
    p->data = data;
    p->link = top->link;
    top = p;
    return 1;
}

/**
 * 3. 取栈顶元素
 * @param top 
 * @param data 
 * @return 
 */
int POPFIRST(StackLink top, StackType *data) {
    if (EMPTY(top)) {
        return -1;

    }
    data = top->data;
    return 1;
}


/**
 * 2. 是否为空
 * @param top 
 * @return 
 */
int EMPTY(StackLink top) {
    return top == NULL;
}


/**
 * 1. 初始化
 * @param top 
 */
void INITLINKSTACK(StackLink *top) {
    top = NULL;
}

