
#include <stddef.h>
#include <malloc.h>
#include <stdio.h>

typedef int ElemType;
typedef struct Node {
    ElemType data;
    struct Node *link;
} LNode, *LinkList;

LinkList create();

LinkList create2();

int size(LinkList list);

int isEmpty(LinkList list);

LinkList find(LinkList list, ElemType e);

void insertHead(LinkList *list, ElemType e);

LinkList copyList(LinkList list);

int main() {
    testMethod();
    return 0;
}


testMethod() {
    LinkList k = create();

    LinkList k2 = create2();
    k2->link = k2;
//    insertByOrder(k, 6);
//    insertAfterNum(k, 99999, 2);
//    insertPosition(k, 555, 1);
//    insertTail(k, 32);
//    insertHead(k, 999);
//    printf("%d\n", size(k));

//        LinkList p;
//    p = (LinkList) malloc(sizeof(LNode));
//    p->data = 2;
//    deleteAllSameEle(k, 5);
//    destoryLinkedList(k);
//    reversal(k);
//    attatchList(k, k2);
//    attatchListByOrder(k, k2);
//    LinkList k3 = copyList(k2);
    print(k2);
//    sortList(k2);

}

void print(LinkList k3) {
    while (k3 != NULL) {
        printf("%d\t", k3->data);
        k3 = k3->link;
    }
}

testCreateLinkList() {
    LinkList k = create();
    LinkList next = k;
    while (next != NULL) {
        printf("%d\t", next->data);
        next = next->link;
    }
    printf("\n");

}

testFind() {
    LinkList k = create();
    LinkList d = find(k, 223);
    if (d != NULL) {
        printf("%d\n", d->data);
    } else {
        puts("ele not exist");
    }
}

LinkList create() {
    LinkList p, r, list = NULL;
    ElemType a[] = {1, 2, 3, 5, 5, 5, 7, 9};
    for (int i = 0; i < sizeof(a) / sizeof(a[0]); i++) {
        p = (LinkList) malloc(sizeof(LNode));
        p->data = a[i];
        p->link = NULL;
        if (list == NULL) {
            list = p;
        } else {
            r->link = p;
        }
        r = p;
    }
    return list;
}

LinkList create2() {
    LinkList p, r, list = NULL;
    ElemType a[] = {3, 15, 8, 5, 6, 4, 2, 9, 1};
    for (int i = 0; i < sizeof(a) / sizeof(a[0]); i++) {
        p = (LinkList) malloc(sizeof(LNode));
        p->data = a[i];
        p->link = NULL;
        if (list == NULL) {
            list = p;
        } else {
            r->link = p;
        }
        r = p;
    }
    return list;
}

/**
 * 循环方式计算链表长度
 * @param list 
 * @return 
 */
int size2(LinkList list) {
    LinkList p = list;
    int n = 0;
    while (p != NULL) {
        n++;
        p = p->link;
    }
    return n;
}

/**
 * 递归方式计算链表长度
 * @param list 
 * @return 
 */
int size(LinkList list) {
    if (list != NULL) {
        return 1 + size(list->link);
    } else {
        return 0;
    }
}

/**
 * is null
 * @param list 
 * @return 
 */
int isEmpty(LinkList list) {
    return list->link == NULL;
}

LinkList find(LinkList list, ElemType e) {
    if (isEmpty(list)) {
        return NULL;
    }
    LinkList p = list;
    while (p != NULL) {
        if (p->data == e) {
            return p;
        }
        p = p->link;
    }
}

/**
 * 在第一个位置插入数据
 * @param list 
 * @param e 
 */
void insertHead(LinkList *list, ElemType e) {
    LinkList head;
    head = (LinkList) malloc(sizeof(LNode));
    head->data = e;
    head->link = *list;
    list = head;
    printf("%d :\n", *list);
}

void insertTail(LinkList list, ElemType e) {
    LinkList tail, r, a;
    r = list;

    while (r->link != NULL) {
        r = r->link;
    }
    tail = (LinkList) malloc(sizeof(LNode));
    tail->data = e;
    tail->link = NULL;
    r->link = tail;

    while (a != NULL) {
        printf(":%d\n", a->data);
        a = a->link;
    }
}

/**
 * 在某一个节点后面插入数据
 * @param list 
 * @param e 
 * @param condition 
 */
void insertPosition(LinkList list, ElemType e, ElemType condition) {
    LinkList ele, p, temp, r;
    ele = (LinkList) malloc(sizeof(LNode));
    temp = (LinkList) malloc(sizeof(LNode));
    ele->data = e;

    if (list == NULL) {
        list = ele;
        list->link = NULL;
        puts("list null");
    } else {
        puts("list not null");
        p = list;
        while (p != NULL) {
            if (p->data == condition) {
                temp->link = p->link;
                p->link = ele;
                ele->link = temp->link;
                free(temp);
                break;
            }
            p = p->link;
        }
        while (p != NULL) {
            printf("%d\t", p->data);
            p = p->link;
        }
    }
}

/**
 * 在序号后面插入一个元素
 * @param list 
 * @param e 
 * @param num 
 */
void insertAfterNum(LinkList list, ElemType e, int n) {
    puts("");
    LinkList p, q = list;
    int j = 1;
    while (j < n && q != NULL) {
        q = q->link;
        j++;
    }
    if (j != n || q == NULL) {
        puts("insert error ");
        exit(1);
    }
    p = (LinkList) malloc(sizeof(LNode));
    p->data = e;
    p->link = q->link;
    q->link = p;
    while (list != NULL) {
        printf("%d\t", list->data);
        list = list->link;
    }
}

/**
 * 在有序列表中插入数据，插入后排序方式不变
 * 书中方法
 * @param list 
 * @param e 
 */
void insertByOrder2(LinkList list, ElemType e) {
    LinkList p, q, r;
    p = (LinkList) malloc(sizeof(LNode));
    p->data = e;
    if (list == NULL || list->data > e) {
        p = list->link;
        list = p;
    } else {
        q = list;
        while (q != NULL && e > list->data) {
            r = q;
            q = q->link;
        }
        p->link = q;
        r->link = p;
    }
    while (list != NULL) {
        printf("%d\t", list->data);
        list = list->link;
    }
}

/**
 * 在有序列表中插入数据，插入后排序方式不变
 * 自己方法
 * @param list 
 * @param e 
 */
void insertByOrder(LinkList list, ElemType e) {
    LinkList p, q;
    p = (LinkList) malloc(sizeof(LNode));
    p->data = e;
    q = list;
    while (q != NULL && q->data < e) {
        q = q->link;
        if (q->link->data > e)break;
    }
    p->link = q->link;
    q->link = p;
    while (list != NULL) {
        printf("%d\t", list->data);
        list = list->link;
    }

}

void deleteEle2(LinkList list, LinkList delEle) {
    if (list == delEle) {
        list->link = delEle->link;
        free(delEle);
    } else {
        LinkList r;
        r = list;
        while (r->link != delEle && r->link != NULL) {
            r = r->link;
        }
        if (r->link != NULL) {
            r->link = delEle->link;
            free(delEle);
        }
    }
    while (list != NULL) {
        printf("%d\t", list->data);
        list = list->link;
    }
}

/**
 * 删除某个元素
 * @param list 
 * @param e 
 */
void deleteEle(LinkList list, ElemType e) {
    LinkList p, q;
    p = list;
    while (p != NULL) {
        if (p->link->data == e) {
            q = p->link->link;
            break;
        }
        p = p->link;
    }
    p->link = q;
    puts("");
    while (list != NULL) {
        printf("%d\t", list->data);
        list = list->link;
    }
}

/**
 * 销毁一个链表
 * @param list 
 */
void destoryLinkedList(LinkList list) {
    LinkList p = list;
    while (list != NULL) {
        list = p->link;
        free(p);
        p = list;
    }
    printf("%d", size(list));
    puts("");

    while (list != NULL) {
        printf("%d\t", list->data);
        list = list->link;
    }
}

/**
 * 删除列表中 值为 e 的所有节点
 * @param list 
 * @param e 
 */
void deleteAllSameEle2(LinkList list, ElemType e) {
    LinkList p = list;
    while (p != NULL) {
        if (p->data == e) {
            deleteEle(list, e);
        }
        p = p->link;
    }
    while (list != NULL) {
        printf("%d\t", list->data);
        list = list->link;
    }
}

void deleteAllSameEleEOOR(LinkList list, ElemType e) {
    LinkList p, q = list;
    p = list->link;

    while (p != NULL) {
        if (p->data == e) {
            q->link = p->link;
            free(q);
            p = q->link;
        } else {
            q = p;
            p = p->link;
        }
    }

    if (list->data == e) {
        q = list;
        list = list->link;
        free(q);
    }
    while (list != NULL) {
        printf("%d\t", list->data);
        list = list->link;
    }
}

void deleteAllSameEle(LinkList list, ElemType e) {
    LinkList p, r;
    p = list;
    while (p->link != NULL) {
        if (p->link->data == e) {
            r = p->link;
            if (r->link == NULL) {
                p->link = NULL;
                break;
            }
            p->link = r->link;
        } else {
            p = p->link;
        }
    }
    if (list->data == e) {
        list = list->link;
    }
    while (list != NULL) {
        printf("%d\t", list->data);
        list = list->link;
    }
}

/**
 * 反转链表
 * @param list 
 */
void reversal(LinkList list) {
    LinkList p, q, r;
    p = list;
    q = NULL;
    while (p != NULL) {
        r = q;  //r 始终指向最后的元素链
        q = p;  //q为当前循环到的元素
        p = p->link;
        q->link = r;//当前元素的link指向 最后的元素链
        /*  
            初始状态
            r null;  
            q=p=1;
            p=p.link=2;
            q.link=null 
            
             r:null
             q:1->null
             p:2->3->4->...
            一次循环
            r=p         r:1->null
            q=p         q:2->3->4->...
            p=p.link    p:3->->4->...
            q.link=r    q:2->1->null
            .
            .
            .
         */
    }
    list = q;
    while (list != NULL) {
        printf("%d\t", list->data);
        list = list->link;
    }
}

/**
 * 将两个链表连在一起
 */
void attatchList(LinkList a, LinkList b) {
    LinkList p;
    p = a;
    while (100) {
        if (p->link == NULL) {
            p->link = b;
            break;
        }
        p = p->link;
    }

//    while (a != NULL) {
//        printf("%d\t", a->data);
//        a = a->link;
//    }
}

void attatchListByOrder(LinkList a, LinkList b) {
    LinkList c, q, r, p;
    if (a->data <= b->data) {
        c = a;
        r = a;
        p = a->link;
    } else {
        c = b;
        r = b;
        q = b->link;
    }
    while (p != NULL && q != NULL) {
        if (p->data <= q->data) {
            r->link = p;
            r = p;
            p = p->link;
        } else {
            r->link = q;
            r = q;
            q = q->link;
        }
    }
    r->link = p ? p : q;

    while (c != NULL) {
        printf("%d\t", c->data);
        c = c->link;
    }
}


LinkList copyList(LinkList list) {
    LinkList b;
    if (list == NULL) {
        return NULL;
    } else {
        b = (LinkList) malloc(sizeof(LNode));
        b->data = list->data;
        b->link = copyList(list->link);
    }
    return b;
}

/**
 * 把最大值放到最后面
 */
void sortList2(LinkList list) {
    LinkList q = list, r = list, p = list->link, s;
    while (p != NULL) {
        if (p->data > q->data) {
            s = r;
            q = p;
        }
        r = p;
        p = p->link;
    }
    if (q != r) {
        if (q == list) {
            list = list->link;
        } else {
            s->link = q->link;
        }
        r->link = q;
        q->link = NULL;
    }
    print(list);
}

void sortList(LinkList list) {

}