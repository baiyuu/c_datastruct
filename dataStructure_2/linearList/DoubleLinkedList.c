
#include <malloc.h>

typedef int DataType;

typedef struct noded {
    DataType data;
    struct noded *head, *tail;
} DNode, *DLinkList;

/**
 * 2. 删除 第一个数据为 e 的结点
 * @param list 
 * @param e 
 * @return 
 */
int delete(DLinkList list, DataType e) {
    DLinkList q, p;
    p = list->tail;
    while (p != list && p->data != e) {
        p = p->tail;
    }

    if (p == list) {
        return -1;
    }
    p->head->tail = p->tail;
    p->tail->head = p->head;
    free(p);
    return 1;
}

drun() {

}

/**
 * 1. 在双向链表中 信息为 x 的节点右边插入 信息为e的节点
 * @param list 
 * @param x 
 * @param e 
 */
int insert(DLinkList list, DataType x, DataType e) {
    DLinkList q, p;
    q = list->tail; //从第一个的下一个开始，当走到头节点时表明循环了一遍
    while (q != list && q->data != x) {
        q = q->tail;
    }

    if (q == list) { //表示没有符合条件的结点
        return -1;
    }
    p = (DLinkList) malloc(sizeof(DNode));
    p->data = e;
    p->head = q;//p 挂在 q后面
    p->tail = q->tail;
    q->tail = p;
    return 1;
}




