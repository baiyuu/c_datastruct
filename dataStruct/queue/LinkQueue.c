


#include <stddef.h>
#include <malloc.h>
#include <stdio.h>
#include <stdbool.h>

typedef int QEletype;
typedef struct Node {
    QEletype data;
    struct Node *link;
} Qnode, *Qlink;


bool isEmpty(Qlink front);

int main() {
    test();
    return 0;
}

test() {

    Qlink q, q3;
    initLinkQueue(q, q3);
    q = (Qlink) malloc(sizeof(Qnode));
    q->data = 12;
    q->link = q3;
    QEletype e = 0;
    getHeadData(&q, &e);
    printf("get head :%d\n", e);

    insertData(&q, &q3, 45);
    getHeadData(&q, &e);
    printf("insert getHead%d\n", e);


    deleteData(&q, &e);
    printf("delete %d\n", e);
    
    getHeadData(&q, &e);
    printf("delet gethead %d\n", e);


}

void initLinkQueue(Qlink *front, Qnode *rear) {
    front = rear = NULL;
}

bool isEmpty(Qlink front) {
    return front == NULL;
}

int getHeadData(Qlink *front, QEletype *ele) {
    Qlink q = *front;
    if (isEmpty(front)) {
        return 0;
    } else {
        *ele = q->data;
        return 1;
    }
}

int insertData(Qlink *front, Qlink *rear, QEletype ele) {
    Qlink q, f = *front, r = *rear;
    q = (Qlink) malloc(sizeof(Qnode));
    q->data = ele;
    q->link = NULL;
    if (f == NULL) {
        f = q;
    } else {
        q->link = f;
    }
    *front = q;
    return 1;
}

int deleteData(Qlink *front, QEletype *ele) {
    if (isEmpty(front)) {
        return 0;
    }
    Qlink q;
    q = *front;
    *ele = q->data;
    q = q->link;
    *front = q;
    free(q);
    return 1;
}

