
#include <iostream>

using namespace std;

void ps_int(int *, int);

void ps_char(int *, int);

int errCode(string, int);

#define  size_5 10
namespace sqList_5 {
#define sq_list_size 10
    typedef int Element;

    typedef struct {
        Element *data;
        int length;
        int listsize;
    } SqList;

    int init(SqList *list) {
        list->data = (Element *) malloc(sizeof(Element) * sq_list_size);
        list->length = 0;
        list->listsize = sq_list_size;
    }

    int swap(int *a, int *b) {
        int t = *a;
        *a = *b;
        *b = t;
    }

    int select_sort_1(int *a, int n) {
        int k, min;
        for (int i = 0; i < n; i++) {
            min = i;
            for (int j = i + 1; j < n; j++)
                if (a[j] < a[min])
                    min = j;

            if (min != i)
                swap(&a[min], &a[i]);
        }
    }

    int insert(SqList *list, int i, int e) {

        if (i < 1 || i > list->length + 1)
            return errCode("插入位置不合法", 0);

        //动态增加空间容量
        Element *newData;
        if (list->length >= list->listsize) {
            newData = (Element *) realloc(list->data, sizeof(Element) * (list->listsize + sq_list_size));
            list->data = newData;
            list->listsize += sq_list_size;
        }

        //下标添加
//        for (int j = list->length - 1; j >= i - 1; j--)
//            list->data[j + 1] = list->data[j];
//
//        list->data[i - 1] = e;

        //指针添加
        int *q = &(list->data[i - 1]);
        for (int *j = &(list->data[list->length - 1]); j >= q; j--)
            *(j + 1) = *j;
        *q = e;
        list->length++;
    }

    int del(SqList *list, int i, Element *e) {
        if (i < 0 || i > list->length)
            return errCode("位置错误，不能删除", 0);

        *e = list->data[i - 1];
        for (int *j = &(list->data[i - 1]); j < &(list->data[list->length - 1]); j++)
            *j = *(j + 1);

        list->length--;
    }

    int locate(SqList *list, Element key) {

        for (int i = 0; i < list->length; i++) {
            if (list->data[i] == key) {
                return errCode("查找成功，元素位置：", i + 1);
            }
        }

        return errCode("没有找到这个元素", 0);

    }

    int union_(SqList *sq_1, SqList *sq_2, SqList *list) {

        int *a1 = sq_1->data;
        int *a2 = sq_2->data;

        int n1 = sq_1->length;
        int n2 = sq_2->length;

//        select_sort_1(a1, n1);
//        select_sort_1(a2, n2);

        int *data = (Element *) malloc(sizeof(Element) * (n1 + n2));
        int i = 0, j = 0, k = 0;


        while (i < n1 && j < n2) {
            if (a1[i] < a2[j]) {
                data[k++] = a1[i];
                i++;
            } else {
                data[k++] = a2[j];
                j++;
            }
        }
        while (i < n1) data[k++] = a1[i++];
        while (j < n2) data[k++] = a2[j++];

        list->data = data;
        list->length = n1 + n2;
    }

    void test() {
        SqList sq_1, sq_2, list;
        init(&sq_1);
        init(&sq_2);
        init(&list);
        int j = 1, k = 1;
        for (int i = 1; i <= 10; i++)
            if (i % 2 == 0)
                insert(&sq_2, j++, i);
            else
                insert(&sq_1, k++, i);
//        sq_1.data = d1;
//        sq_1.length = 5;
//        sq_2.data = d2;
//        sq_2.length = 7;

        ps_int(sq_1.data, sq_1.length);
        ps_int(sq_2.data, sq_2.length);

        union_(&sq_1, &sq_2, &list);
        ps_int(list.data, list.length);

    }

    void test_1() {
        SqList list;
        init(&list);
        ps_int(list.data, list.length);

        for (int i = 0; i < 6; i++)
            insert(&list, i + 1, 10 + i);

        ps_int(list.data, list.length);
        int a;
        del(&list, 3, &a);
        ps_int(list.data, list.length);
        std::cout << "deleted:" << a << std::endl;

        std::cout << locate(&list, 15) << std::endl;

        insert(&list, locate(&list, 15), 100);
        ps_int(list.data, list.length);

    }
}

namespace dynamic_sq_link_list_5 {
#define new_linklist_node_5 (LinkedList) malloc(sizeof(LNode))
    typedef int Element;

    typedef struct Node {
        Element data;
        struct Node *next;
    } LNode, *LinkedList;


    int ps_(LinkedList list) {
        if (list == nullptr)
            return errCode("链表为空", 0);
        LinkedList p = list;
        while (p != nullptr) {
            printf("%d\t", p->data);
            p = p->next;
        }
        puts("");
    }

    LinkedList create(int n = 5) {
        LinkedList list = nullptr, p, r;
        for (int i = 0; i < n; i++) {
            p = new_linklist_node_5;
            p->data = i + 1;
            if (list == nullptr) {
                list = p;
            } else {
                r->next = p;
            }
            r = p;
        }
        return list;
    }


    int get(LinkedList list, int i, Element *e) {
        LinkedList p = list;
        while (i > 0 && p != nullptr) {
            i--;
            p = p->next;
        }

        if (p == nullptr)
            return errCode("元素不存在", 0);

        *e = p->data;
        return errCode("查找成功", 0);
    }

    /*
     * 在第i个元素前插入
     */
    int insertBeforeIndex(LinkedList &list, int i, Element e) {
        LinkedList p = list, q, r;
        int j = 1;
        q = new_linklist_node_5;
        q->data = e;

        if (i == 1) {
            q->next = list;
            list = q;
            return errCode("在第一个位置插入成功！", 1);
        }


        while (j < i - 1 && p != nullptr) {
            j++;
            p = p->next;
        }
        q->next = p->next;
        p->next = q;
    }


    int del(LinkedList &list, int i, Element *e) {
        if (list == nullptr)
            return errCode("空表没有数据可以删除", 0);

        LinkedList p = list, r, q;

        if (i == 1) {
            *e = p->data;
            list = p->next;
            free(p);
            return 1;
        }

        while (i - 1 > 0 && p != nullptr) {
            r = p;
            p = p->next;
            i--;
        }

        if (p == nullptr || i < 0)
            return errCode("删除位置不合理", 0);

        r->next = p->next;
        *e = p->data;
        free(p);
    }


    LinkedList create(int *a, int n) {
        LinkedList list = new_linklist_node_5, p;
        list->next = nullptr;
        list->data = a[n - 1];
        for (int i = 0; i < n - 1; i++) {
            p = new_linklist_node_5;
            p->data = a[i];
            p->next = list->next;
            list->next = p;
        }
        return list;
    }


    void insert_element(LinkedList &list, Element e) {
        LinkedList p = list, r = new_linklist_node_5;
        r->data = e;
        r->next = nullptr;
        if (list == nullptr) {
            list = r;
        } else {
            while (p->next != nullptr)
                p = p->next;
            p->next = r;
        }
    }

    void insert_list(LinkedList &list, LinkedList a) {
        if (list == nullptr) {
            list = a;
        } else {
            LinkedList p = list;
            while (p->next != nullptr)
                p = p->next;
            p->next = a;
        }
    }

    LinkedList union_(LinkedList a1, LinkedList a2) {
        LinkedList list = nullptr, r, p = a1, q = a2;
        while (p && q) {
            if (p->data >= q->data) {
                insert_element(list, p->data);
                p = p->next;
            } else {
                insert_element(list, q->data);
                q = q->next;
            }
        }

        if (q != NULL)
            insert_list(list, q);

        if (p != NULL)
            insert_list(list, p);

        return list;
    }


    void union_2(LinkedList a, LinkedList b, LinkedList &c) {
        LinkedList p = a->next, q = b->next, w;
        w = c = b;
        while (p && q) {
            if (p->data > q->data) {
                w->next = p;
                w = p;
                p = p->next;
            } else {
                w->next = q;
                w = q;
                q = q->next;
            }
        }

        w->next = p ? p : q;
        free(a);
    }


    void test_union() {
        int a[] = {11, 33, 22, 55, 44};
        int a2[] = {1, 1, 1, 3, 5, 7, 9};
        int a3[] = {2, 4, 6, 8, 10};
        LinkedList list_1 = create(a2, 7);
        LinkedList list_2 = create(a3, 5);
//        LinkedList list = union_(list_1, list_2);
        LinkedList list;

        union_2(list_1, list_2, list);
        ps_(list);
    }

    void test() {
        test_union();
    }

    void test_crud() {
        LinkedList list = create();
        ps_(list);
        int a;
        get(list, 0, &a);
        insertBeforeIndex(list, 4, 12);
        ps_(list);
        del(list, 1, &a);
        std::cout << "delete element:" << a << std::endl;
        ps_(list);
    }
}

namespace static_sq_link_list_5 {
#define size 10
    typedef struct {
        int data;
        int cursor;
    } component, staticLinkList[size];

}

namespace double_link_list_5 {
#define newDouble_link_list_5 (DoubleLinkedList)malloc(sizeof(dnode))
    typedef int Element;
    typedef struct dnode {
        Element data;
        struct dnode *prior, *next;
    } dnode, *DoubleLinkedList;


    int insert(DoubleLinkedList list, int i, Element e) {
        DoubleLinkedList p = list, r;

        r = newDouble_link_list_5;
        r->data = e;

        while (i > 0 && p != nullptr) {
            i--;
            p = p->next;
        }

        r->next = p->next;
        r->prior = p;
        p->next->prior = r;
        p->next = r;
        return 1;
    }

    int del(DoubleLinkedList list, int i, Element *e) {
        DoubleLinkedList p = list, r;

        while (i > 0 && p != nullptr) {
            i--;
            p = p->next;
        }

        *e = p->data;
        p->next->prior = p->prior;
        p->prior->next = p->next;
        free(p);
    }


    void test() {

    }


    /*
     * 带头尾节点的链表
     */
    typedef struct node {
        Element data;
        struct node *next;
    } *Link, *Position;

    typedef struct {
        Link head, tail;
        int length;
    } List;


}

//lifo
namespace sq_stack_5 {
#define  sq_stack_init_size_5 10

    typedef int Element;
    typedef struct {
        //栈底指针，为null表示栈结构不存在，
        Element *base;
        //栈顶指针，初值指向栈底，top==base可标记为空栈，push时top+1，pop时top-1
        //栈顶指针始终指向栈顶元素的下一个位置
        Element *top;
        //栈的容量
        int stacksize;
        //长度
        int length;
    } SqStack;

    /*
     * 基本操作
     * init destory clear isEmpty isFull length push pop traverse
     */

    int init(SqStack *s) {
        s->base = (Element *) malloc(sizeof(Element) * sq_stack_init_size_5);
        if (!s->base)
            return errCode("初始化栈失败", 0);
        s->top = s->base;
        s->stacksize = sq_stack_init_size_5;
        s->length = 0;
    }


    int pop(SqStack *s, Element *e, int isPop = 1) {
        if (s->top == s->base)
            return errCode("栈空无数据", 0);

        if (isPop) {
            //出栈
            *e = *(--s->top);
            s->length--;
        } else {
            //获取栈顶元素
            *e = *(s->top - 1);
        }

    }

    int push(SqStack *s, Element e) {
        if (s->top - s->base >= s->stacksize) {
            s->base = (Element *) realloc(s->base, sizeof(Element) * (s->stacksize + sq_stack_init_size_5));
            s->top = s->base + s->stacksize;
            s->stacksize += sq_stack_init_size_5;
        }
        *s->top++ = e;
        s->length++;
        return errCode("插入成功", 1);
    }

    int clear(SqStack *s) {
        s->length = 0;
        s->top = s->base;
    }

    void test_1() {
        SqStack s;
        init(&s);
        ps_int(s.base, s.length);
        push(&s, 12);
        push(&s, 13);
        push(&s, 14);
        ps_int(s.base, s.length);
        int e;

        pop(&s, &e);
        ps_int(s.base, s.length);
        std::cout << "poped=" << e << std::endl;

        pop(&s, &e);
        ps_int(s.base, s.length);
        std::cout << "poped=" << e << std::endl;
    }

    /*
     * 斩的应用举例
     */

    /**
     * 1、数值进制转换
     * @param a 数组模拟数字
     * @param n 数组长度
     * @param o 几进制
     * @return 
     */
    int coversion(int num, int o = 2) {
        SqStack s;
        init(&s);

        while (num > 0) {
            push(&s, num % o);
            num /= o;
        }

        int e;
        while (s.length > 0) {
            pop(&s, &e);
            printf("%d", e);
        }
    }


    /**
     * 行编辑操作
     * # 表示退格
     * @ 表示推行
     */
    void lineEdit(char *c, int n) {
        SqStack s;
        init(&s);
        int a;
        for (int i = 0; i < n; i++) {
            switch (c[i]) {
                case '#':
                    pop(&s, &a);
                    break;
                case '@':
                    clear(&s);
                    break;
                default:
                    push(&s, c[i]);
                    break;
            }
        }

        ps_char(s.base, s.length);
    }

    /*
     * 
     * 
     * 
     */
    void test() {
//        coversion(10, 2);
//        char c[] = {'a', 's', '@', 'd'};
//        lineEdit(c, 4);
    }

}

//fifo
namespace link_queue_5 {
#define  new_qnode_5 (qPointer) malloc(sizeof(qnode))
    typedef int Element;
    typedef struct qnode {
        Element data;
        qnode *link;
    } qnode, *qPointer;

    typedef struct {
        qPointer front;
        qPointer rear;
    } Queue;

    /*
     * 基本操作
     * init destory clear isEmpty size getHead enQueue dequeue traverse 
     */

    int ps_queue(Queue *q) {
        if (q->front == q->rear)
            return errCode("空队列", 0);
        qPointer p = q->front->link;
        while (p != nullptr) {
            printf("%d\t", p->data);
            p = p->link;
        }
        puts("");
    }


    int init(Queue *q) {
        qPointer qp = new_qnode_5;
        if (!qp)
            return errCode("初始化队列失败，内存空间不足", 0);

        q->front = q->rear = qp;
        q->front->link = nullptr;
    }


    int destory(Queue *q) {
        while (q->front) {
            q->rear = q->front->link;
            free(q->front);
            q->front = q->rear;
        }
        return errCode("删除成功", 1);
    }


    int enQueue(Queue *q, Element e) {
        qPointer p = new_qnode_5;
        p->data = e;
        p->link = nullptr;
        q->rear->link = p;
        q->rear = p;
//        return errCode("入队成功", 1);
    }

    int deQueue(Queue *q, Element *e) {

        if (q->front == q->rear)
            return errCode("空队列", 0);

        qPointer p = q->front->link;
        *e = p->data;
        q->front->link = p->link;
        if (q->rear == p)
            q->rear = q->front;
        free(p);
    }

    void test() {
        Queue q;
        init(&q);
        ps_queue(&q);
        enQueue(&q, 12);
        enQueue(&q, 13);
        enQueue(&q, 14);
        ps_queue(&q);
        int a;
        deQueue(&q, &a);
        std::cout << "out:" << a << std::endl;
        ps_queue(&q);
    }

}

namespace cycle_queue_5 {
#define cycle_queue_5_size 12
    typedef int Element;

    typedef struct {
        Element *base;
        int rear;
        int front;
    } CycleQueue;

    int init(CycleQueue &q) {
        q.base = (Element *) malloc(sizeof(Element));
        q.rear = q.front = 0;
    }

    int length(CycleQueue &q) {
        return (q.rear - q.front + cycle_queue_5_size) % cycle_queue_5_size;
    }

    int enQueue(CycleQueue &q, Element e) {
        if ((q.rear + 1) % cycle_queue_5_size == q.front)
            return errCode("队列满了，不能入队", 0);

        q.base[q.rear] = e;
        q.rear = (q.rear + 1) % cycle_queue_5_size;
        return errCode("插入成功", 1);
    }

    int deQueue(CycleQueue &q, Element &e) {
        if (q.rear == q.front)
            return errCode("队空没数据", 0);
        e = q.base[q.front];
        q.front = (q.front + 1) % cycle_queue_5_size;
    }

    void test() {
        CycleQueue q;
        init(q);
        std::cout << "length=" << length(q) << std::endl;
        enQueue(q, 12);
        enQueue(q, 14);
        std::cout << "length=" << length(q) << std::endl;
        int a;
        deQueue(q, a);
        std::cout << "out data=" << a << std::endl;
    }

}

namespace string_5 {
#define str_size_5 10
    typedef unsigned char Str[str_size_5];

    int concat_(Str &r, Str s1, Str s2) {

    }


}

namespace tree_5 {

    /*
     * 操作
     * init destory clear create isEmpty depth root value parent left right insert delete traverse
     */
    typedef int Element;
#define  tree_size_5 100
    typedef struct tnode {
        Element data;
        struct tnode *left, *right;
    } tnode, *BTree;


    int preOrderTraverse(BTree t) {
        if (t != nullptr) {
            printf("%d\t", t->data);
            preOrderTraverse(t->left);
            preOrderTraverse(t->right);
        }
    }

    int inOrderTraverse(BTree t) {
        if (t != nullptr) {
            inOrderTraverse(t->left);
            printf("%d\t", t->data);
            inOrderTraverse(t->right);
        }
    }

    int postOrderTraverse(BTree t) {
        if (t != nullptr) {
            postOrderTraverse(t->left);
            postOrderTraverse(t->right);
            printf("%d\t", t->data);
        }
    }

    
    

    void test(BTree t) {

    }
}


namespace ds_5 {

    void test() {
//        dynamic_sq_link_list_5::test();
//        sqList_5::test();
//        sq_stack_5::test();
//        link_queue_5::test();
        cycle_queue_5::test();

    }
}