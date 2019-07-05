


#include <stdio.h>
#include <malloc.h>

typedef int DataType;
typedef struct node {
    DataType data;
    struct node *link;
} LNode, *LinkedList;

LinkedList *init(DataType d[], int n);

LinkedList find(LinkedList list, DataType e);

LinkedList insertFirst(LinkedList *list, DataType e);

LinkedList insertEnd(LinkedList *list, DataType e);

LinkedList insertAfterPointer(LinkedList *list, LinkedList q, DataType e);

LinkedList copy(LinkedList list);

void runLinkedList() {
    DataType d[] = {1, 2, 4, 5, 6};
//    DataType d[] = {1, 2, 3, 4, 3, 3, 9, 45, 7, 2, 6, 3, 4};
    int n = sizeof(d) / sizeof(DataType);
    LinkedList *list = init(d, n);
//    print(list);
//    printf("%d", size(list));
    LinkedList a = find(list, 1);
//    LinkedList a5 = insertFirst(&list, 89);
//    LinkedList a6 = insertEnd(&list, 123);
//    insertAfterPointer(list, a, 777);

//    insertAfterOrder(list, 666, 0);
    insertByOrder(list,3 );
        print(list);
//    delete(list, a);
//    deleteAllSameItem(list, 3);
//    destory(list);
//    reversal(list);
//    linkTwo(list, a);
//    LinkedList c = copy(list);
//    print(c);
    sortByLinkedList();
}
/**
 * todo 错误代码
 * 17 . 使用链表排序
 */
void sortByLinkedList() {
    puts("");

    DataType d[] = {1, 3, 2, 6, 4, 5};
    int n = sizeof(d) / sizeof(DataType);
    LinkedList p, list = NULL;
    for (int i = 0; i < n; ++i) {
        insertByOrder(&list, d[i]);
    }
    p = list;
    int k = 0;
    while (p != NULL) {
        d[k++] = p->data;
        p = p->link;
    }
    for (int j = 0; j < n; ++j) {
        printf("%d\t",d[j]);
    }
    puts("");
    print(list);
}

/**
 * 16. 复制
 * @param list
 * @return
 */
LinkedList copy(LinkedList p) {
    LinkedList c;
    if (p == NULL) {
        return NULL;
    } else {
        c = (LinkedList) malloc(sizeof(LNode));
        c->data = p->data;
        c->link = copy(p->link);
    }
    return c;
}

/**
 * 15.两个值有序合并之后还是值有序
 * @param a
 * @param b
 */
void merge(LinkedList a, LinkedList b) {

}

/**
 * todo 有问题代码
 * 14. 两个链表 合并
 * @param a
 * @param b
 */
void linkTwo(LinkedList a, LinkedList b) {
    LinkedList p;
//    for (p = a; p->link; p = p->link) {
//        p->link = b;
//    }
    while (p->link != NULL) {
        p = p->link;
    }
    p->link = b;

    print(a);
}

/**
 * 13. 反转链表
 * @param list
 */
void reversal(LinkedList list) {
    LinkedList p, q, r;
    p = list;
    q = NULL;
//    1 2 3 4
    /*
     * r    null            list->null      1->null         2->1->null      3->2->1->null
     * q    list->null      1->null         2-->1->null     3->2->1->null      4->3->2->1->null
     * p    1               2               3               4               null
     */
    while (p != NULL) {
        r = q;//取最后一串元素
        q = p;//取倒数第二个元素
        p = p->link;//
        q->link = r;//把倒数第二个 连在 最后一串元素前面
    }
    list = q;
    print(list);
}

/**
 * 12. 删除线性表中 所有数据信息为item的节点
 * @param list
 * @param item
 */
void deleteAllSameItem(LinkedList list, DataType item) {
    LinkedList p = list->link, r, q = list;
    while (p != NULL) {
        if (p->data == item) {
            q->link = p->link;
            free(p);
            p = q->link;
        } else {
            q = p;
            p = p->link;
        }
    }

    if (list->data == item) {
        q = list;
        list = list->link;
        free(q);
    }
    print(list);
}

/**
 * 11. 销毁线性表
 * @param list
 */
void destory(LinkedList list) {
    LinkedList p = list;
    while (p != NULL) {
        list = p->link;
        free(p);
        p = list;
    }
    print(list);
}

/**
 * 10. 删除 w 所指的链节点
 * @param list
 * @param w
 * @return
 */
int DELETELINKSTACK(LinkedList list, LinkedList w) {
    LinkedList r;
    if (w == list) {
        list = w->link;
        free(w);
    } else {
        r = list;
        while (r->link != w && r->link != NULL) {
            r = r->link;
        }
        if (r->link != NULL) {
            r->link = w->link;
            free(w);
        }
    }
    print(list);
}

/**
 * 9. 在有序链表中插入一个数据，保持有序
 * @param list
 * @param e
 * @return
 */
int insertByOrder(LinkedList *list, DataType e) {
    LinkedList q, p = (LinkedList) malloc(sizeof(LNode)), r,f=list;
    p->data = e;
    if (list == NULL || f->data > e) {
        p->link = f;
        f= p;
    } else {
        r = f;
        while (r != NULL && r->data <= e) {
            q = r;//当下一次循环后，r->data >e 的时候，q 记录着 e的前一个元素的位置，q是恰好<=e的元素节点
            r = r->link;
        }
        p->link = r;//把比 e 大的元素连在p后面
        q->link = p;
    }
//    print(list);
}

/**
 * 8. 在线性表第 i 个 元素后面插入一个元素
 * @param list
 * @param e
 * @param i
 * @return
 */
int insertAfterOrder(LinkedList list, DataType e, int i) {
    int c = 0;
    LinkedList r, p = list, q = (LinkedList) malloc(sizeof(LNode));
    q->data = e;
    while (p != NULL && c < i) {
        p = p->link;
        c++;
    }
    q->link = p->link;
    p->link = q;
    print(list);
    return 1;
}

/**
 * 7. 在链表中 的指针q 的后面插入一个节点。
 * @param list
 * @param q
 * @param e
 * @return
 */
LinkedList insertAfterPointer(LinkedList *list, LinkedList q, DataType e) {
    LinkedList r = (LinkedList) malloc(sizeof(LNode));
    r->data = e;
    if (list == NULL) {
        list = r;
        r->link = NULL;
    } else {
        r->link = q->link;
        q->link = r;
    };
}

/**
 * 6. 在链表的末尾插入一个元素
 * @param list
 * @param e
 * @return
 */
LinkedList insertEnd(LinkedList *list, DataType e) {
    LinkedList p = *list, r = (LinkedList) malloc(sizeof(LNode));
    r->data = e;
    r->link = NULL;
    while (p->link != NULL) {
        p = p->link;
    }
    p->link = r;
    return *list;
}

/**
 * 5. 在线性表中第一个位置上插入一个元素
 * @param list
 * @param e
 * @return
 */
LinkedList insertFirst(LinkedList *list, DataType e) {
    LinkedList p = (LinkedList) malloc(sizeof(LNode));
    p->data = e;
    p->link = *list;
    *list = p;
    return *list;
}

/**
 * 4. 查找item在线性表中的位置
 * @param list
 * @param e
 * @return
 */
LinkedList find(LinkedList list, DataType e) {
    LinkedList p = list;
    while (p != NULL && p->data != e) {
        p = p->link;
    }
    return p;
}

/**
 * 3. 测试线性表是否为空
 * @param list
 * @return
 */
int isEmpty(LinkedList list) {
    return list == NULL;
}

/**
 * 2.求线性链表的长度
 * @param list
 * @return
 */
int size(LinkedList list) {
    if (list != NULL) {
        return 1 + size(list->link);
    } else {
        return 0;
    }
}

int size2(LinkedList list) {
    int c = 0;
    LinkedList p = list;
    while (p != NULL) {
        c++;
        p = p->link;
    }
    return c;
}


/**
 * 1. 创建一个链表
 * @param d
 * @param n
 */
LinkedList *init(DataType d[], int n) {

    LinkedList list, p, r;
    list = (LinkedList) malloc(sizeof(LNode));
    list->data = d[0];
    list->link = NULL;
    for (int i = 1; i < n; ++i) {
        r = list;
        p = (LinkedList) malloc(sizeof(LNode));
        p->data = d[i];
        while (r->link != NULL) {
            r = r->link;
        }
        p->link = r->link;
        r->link = p;
    }
//    print(list);
    return list;
}


void print(LinkedList list) {
    while (list != NULL) {
        printf("%d\t", list->data);
        list = list->link;
    }
}

