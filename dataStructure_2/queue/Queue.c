


#include <stdio.h>

#define MAXSIZE 1000
int queue[MAXSIZE];
int front, rear;

runqueue() {
    INITQUEUE(&front, &rear);
    printf("%d %d", front, rear);
}


int deleteCircularQueue(int q[], int f, int r, int *item) {

    if (f == r) {
        return -1;
    }

    f = (f + 1) % MAXSIZE;
    *item = q[f];
    return 1;

}

/**
 * 6. 循环队列的插入
 * @param q 
 * @param f 
 * @param r 
 * @param item 
 * @return 
 */
int insertCircularQueue(int q[], int f, int r, int item) {

    if ((r + 1) % MAXSIZE == f) {
        return -1;
    }

    q[(++r) % MAXSIZE] = item;
    return 1;
}


/**
 * 5. 队列删除
 * @param f 
 * @param r 
 * @param item 
 * @return 
 */
int deleteQueue(int f, int r, int *item) {

    if (EMPTYQUEUE(f, r)) {
        return -1;
    }
    item = queue[++f];
    return 1;
}


/**
 * 4. 进队
 * @param rear 
 * @param data 
 * @return 
 */
int pushQueue(int rear, int data) {
    if (rear = MAXSIZE - 1) {
        return -1;
    }
    queue[++rear] = data;
    return 1;

}

/**
 * 3. 取队列第一个元素
 * @param front 
 * @param rear 
 * @param item 
 * @return 
 */
int popQueueFirst(int front, int rear, int item) {
    if (EMPTYQUEUE(front, rear))
        return -1;
    item == queue[++front];
    return 1;
}


/**
 * 2. 是否为空
 * @param front 
 * @param rear 
 * @return 
 */
int EMPTYQUEUE(int front, int rear) {
    return front == rear;
}

/**
 * 1. 初始化
 * @param front 
 * @param real 
 */
void INITQUEUE(int *front, int *rear) {
    *front = -1;
    *rear = -1;
}

