#include <stddef.h>
#include <malloc.h>

/**
 * 链式队列结构
 */

typedef struct node {
    int data;
    struct node *link;
} QNode, *QueueLink;

int emptyLinkQueue(QueueLink f);

runLinkedQueue() {

}


int destoryLinkQueue(QueueLink f) {
    QueueLink p;
    while (p != NULL) {
        p = f->link;
        free(f);
        f = p;
    }
}


/**
 * 5. 删除
 * @param f 
 * @param data 
 * @return 
 */
int deleteLinkQueue(QueueLink f, int *data) {
    if (emptyLinkQueue(f)) {
        return -1;
    }

    QueueLink r;
    *data = f->data;
    r = f; //
    f = r->link; //一句就可以，上下两句是为了释放空间
    free(r);
    return 1;

}


/**
 * 4.插入
 * @param f 
 * @param r 
 * @param data 
 * @return 
 */
int popLinkQueue(QueueLink f, QueueLink r, int data) {
    QueueLink p = (QueueLink) malloc(sizeof(QNode));
    p->data = data;
    p->link = NULL;
    if (f == NULL) {
        f = p;
    } else {
        r->link = p;
    }
    r = p;
    return 1;

}

/**
 * 3. 取第一个元素
 * @param f 
 * @param data 
 * @return 
 */
int popLinkQueueFirst(QueueLink f, int data) {
    if (emptyLinkQueue(f)) {
        return -1;
    }
    data = f->data;
    return 1;
}


/**
 * 2. 测试非空
 * @param f 
 * @return 
 */
int emptyLinkQueue(QueueLink f) {
    return f == NULL;
}

/**
 * 1. 初始化
 * @param f 
 * @param r 
 */
void initLinkQueue(QueueLink f, QueueLink r) {
    f = r = NULL;
}



