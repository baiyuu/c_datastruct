
#include <stdio.h>

#define M 1000;

typedef int SqQueue;

SqQueue queue[1000];
int front, rear;

int isFull(int front, int rear);

SqQueue getHeadData(SqQueue *queues, int head, int tail);

int insertQueue(SqQueue queues[], int head, int tail, SqQueue ele);

int delQ(SqQueue *queues, int head, int tail, SqQueue sqQueue);

int main() {
    test();
    return 0;
}

void test() {
    initQueue();
    printf("%d %d\n", front, rear);
    int siFull = isFull(front, rear);
    printf("%d\n", siFull);


    SqQueue s[100] = {2, 3, 4, 5};
    SqQueue s2 = getHeadData(s, -1, 3);
    printf("%d\n", s2);
//    insertQueue(s, -1, 3, 88);
    delQ(s, -1, 3, 85);
//    SqQueue s3 = getHeadData(s, -1, 3);
//    printf("%d\n", s3);


}

void initQueue() {
    front = rear = -1;
}

int isFull(int front, int rear) {
    return front == rear;
}

SqQueue getHeadData(SqQueue *queues, int head, int tail) {
    SqQueue qd;
    if (isFull(head, tail)) {
        return NULL;
    } else {
        qd = queues[++head];
        return qd;
    }
}

int insertQueue(SqQueue queues[], int head, int tail, SqQueue ele) {
    if (tail == 99) {
        return 0;
    } else {
        queues[++tail] = ele;
        return 1;
    }
}

int delQ(SqQueue *queues, int head, int tail, SqQueue sqQueue) {
    puts("");
    head++;
}

 