#include <stdio.h>
#include <stdlib.h>

typedef int EleType;
typedef struct node {
    EleType data;
    struct node *pre, *next;
} DNode, *DLinkList;

int main() {
    return 0;
}

/**
 * 在双向链表的 元素为x的节点后插入一个新节点 e
 */
void insert(DLinkList list, EleType x, EleType e) {
    DLinkList q, p;
    q = list->pre;
    while (q != list && q->data != x) {
        q = q->next;
    }
    if (q == list) {
        puts("no match");
        exit(1);
    }
    p = (DLinkList) malloc(sizeof(DNode));
    p->data = e;
    p->pre = q;
    p->next = q->next;
    q->next->pre = p;
    q->pre = p;
    puts("222222");
}

