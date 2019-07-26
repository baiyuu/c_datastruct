
#include <iostream>

using namespace std;

void ps_int(int *, int);

void ps_char(int *, int);

int errCode(string, int);

#define  size_5 20
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
     * 算法补充 
     */
    /*
     * 两个栈共享一个数组空间
     */
    typedef struct two_node_5 {
        int *head;//
        int *tail;
        int listsize;
        int length_1;
        int length_2;
    } TwoStack;


    void test() {
//        coversion(10, 2);
//        char c[] = {'a', 's', '@', 'd'};
//        lineEdit(c, 4);
    }

}

namespace link_stack_5 {
    void test() {

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
#define  tree_size_5 100
#define  tree_node_5 (BTree)malloc(sizeof(tnode))

    /*
     * 操作
     * init destory clear create isEmpty depth root value parent left right insert delete traverse
     */
    typedef int Element;
    typedef struct tnode {
        Element data;
        struct tnode *left, *right;
    } tnode, *BTree;

    /*
     *   测试使用
     *   
     *  d f e b i g j k h c a
     *  f d e b i g j k h c a
        B-D-E-F-C-G-I-H-J-K-A-
     *             a
     *      b           c
     *   d    e       g     h
     *          f   i     j   k 
     */
    BTree tree() {
        BTree a, b, c, d, e, f, g, h, i, j, k;
        a = tree_node_5;
        a->data = 'A';
        b = tree_node_5;
        b->data = 'B';
        c = tree_node_5;
        c->data = 'C';
        d = tree_node_5;
        d->data = 'D';
        e = tree_node_5;
        e->data = 'E';
        f = tree_node_5;
        f->data = 'F';
        g = tree_node_5;
        g->data = 'G';
        h = tree_node_5;
        h->data = 'H';
        i = tree_node_5;
        i->data = 'I';
        j = tree_node_5;
        j->data = 'J';
        k = tree_node_5;
        k->data = 'K';

        a->left = b;
        a->right = c;
        b->left = d;
        b->right = e;
        d->left = h;
        d->right = nullptr;
        h->left = nullptr;
        h->right = k;
        k->left = nullptr;
        k->right = nullptr;
        e->left = nullptr;
        e->right = nullptr;
        c->left = f;
        c->right = g;
        f->left = i;
        f->right = nullptr;
        i->left = nullptr;
        i->right = nullptr;
        g->left = nullptr;
        g->right = j;
        j->left = nullptr;
        j->right = nullptr;
        return a;
    }


    int preOrderTraverse(BTree t) {
        if (t != nullptr) {
            printf("%c\t", t->data);
            preOrderTraverse(t->left);
            preOrderTraverse(t->right);
        }
    }

    int inOrderTraverse(BTree t) {
        if (t != nullptr) {
            inOrderTraverse(t->left);
            printf("%c\t", t->data);
            inOrderTraverse(t->right);
        }
    }

    int postOrderTraverse(BTree t) {
        if (t != nullptr) {
            postOrderTraverse(t->left);
            postOrderTraverse(t->right);
            printf("%c\t", t->data);
        }
    }

    /*
        计算叶结点数量
     */
    int leafCount_traverse(BTree t) {
        if (t == nullptr)
            return 0;
        if (t->right == nullptr && t->left == nullptr)
            return 1;
        return leafCount_traverse(t->left) + leafCount_traverse(t->right);
    }

    /*
     * 计算二叉树深度
     */
    int depth_traverse(BTree t) {
        int leftDepth, rightDepth;
        if (t == nullptr)
            return 0;
        else {
            leftDepth = depth_traverse(t->left);
            rightDepth = depth_traverse(t->right);
            if (leftDepth > rightDepth)
                return leftDepth + 1;
            else
                return rightDepth + 1;
        }
    }


    void visit(BTree t) {
        printf("%d\t", t->data);
    }

    /*
     * 中序遍历 非递归    (上左右)
     */
    int inOrder(BTree t) {
        BTree stack[size_5], p = t;
        int top = -1;
        if (t != nullptr) {
            do {
                while (p != nullptr) {
                    stack[++top] = p;
                    p = p->left;
                }
                p = stack[top--];
                visit(p);
                p = p->right;
            } while (top != -1 || p != nullptr);
        }
        puts("");
    }

    /*
     * 后序 遍历    (左右上)
     */
    int postOrder(BTree t) {
        BTree stack[size_5], p = t;
        int top = -1, f, flags[size_5];

        if (t != nullptr) {
            do {
                while (p != nullptr) {
                    stack[++top] = p;
                    flags[top] = 0;
                    p = p->left;
                }
                p = stack[top];
                f = flags[top--];
                if (f == 0) {  //没有被访问过
                    stack[++top] = p;
                    flags[top] = 1;
                    p = p->right;
                } else {
                    visit(p);
                    p = nullptr;
                }

            } while (top != -1 || p != nullptr);
        }
        puts("");
    }

    /*
     * 按层次遍历（二叉树的广度优先遍历）
     */
    int layerOrder(BTree t) {

        BTree queue[size_5], p = t;
        int rear, front;
        if (p != nullptr) {
            queue[0] = p;
            front = -1, rear = 0;
            while (front < rear) {
                p = queue[++front];
                visit(p);
                if (p->left != nullptr)
                    queue[++rear] = p->left;
                if (p->right != nullptr)
                    queue[++rear] = p->right;
            }
        } else {
            return errCode("按层次 空树", 0);
        }
        puts("");
    }


    /*
     * 遍历序列 恢复二叉树
     * 前序 a b c d e f g h i
     * 中序 b c a e d g h f i
     *              
     *              a                      a                     a                     a
     *          bc    edghfi           b      d              b       d             b        d
     *                                   c  e  ghfi            c   e   f             c    e    f 
     *                                                               gh  i                   g   i      
     *                                                                                         h                                                             
     */


    /*
     *二叉树相似与等价
     * 相似：结构一致
     * 等价：结构一致且每个结点的数据相同
     * 
     */

    int similar(BTree t1, BTree t2) {
        if (t1 == nullptr && t2 == nullptr)
            return 1;
        if (t1 != nullptr && t2 != nullptr
            && similar(t1->left, t2->left)
            && similar(t1->right, t2->right))
            return 1;
        return 0;
    }

    /*
     * 1、递归创建树
     */
    void buildTree(BTree &t) {
        /*
         * a b c _ _ d e _ _ f _ _ g _ _ _
         */
        char c;
        scanf("%c", &c);
        if (c == ' ') {
            t = nullptr;
        } else {
            t = tree_node_5;
            t->data = c;
            buildTree(t->left);
            buildTree(t->right);
        }
    }

    /*
     * 2、销毁树
     */
    void destory(BTree t) {
        if (t != nullptr) {
            destory(t->left);
            destory(t->right);
            free(t);
        }
    }

    /*
     * 3、树的复制
     */
    BTree copy(BTree t) {
        BTree tree;
        if (t == nullptr) {
            return nullptr;
        } else {
            tree = tree_node_5;
            tree->data = t->data;
            tree->left = copy(t->left);
            tree->right = copy(t->right);
        }
        return tree;
    }

    /*
     * 4、树是否等价
     */
    int equal(BTree t1, BTree t2) {
        if (t1 == nullptr && t2 == nullptr)
            return 1;
        if (t1 != nullptr && t2 != nullptr
            && t1->data == t2->data
            && equal(t1->left, t2->left)
            && equal(t1->right, t2->right))
            return 1;
        return 0;
    }

    /*
     * 5、二叉树深度 非递归
     */
    int depth_(BTree t) {
        BTree p = t, stack[size_5];
        int stack2[size_5], top = -1, maxDepth = 0, currentDepth;
        if (t != nullptr) {
            currentDepth = 1;
            do {
                while (p != nullptr) {
                    stack[++top] = p;
                    stack2[top] = currentDepth;
                    p = p->left;
                    currentDepth++;
                }
                p = stack[top];
                currentDepth = stack2[top--];
                if (p->left == nullptr && p->right == nullptr)
                    if (maxDepth < currentDepth)
                        maxDepth = currentDepth;

                p = p->right;
                currentDepth++;
            } while (top != -1 || p != nullptr);
        }
        return maxDepth;
    }

    /*
     * 6、某个节点的层次
     */
    int nodeDepth(BTree t, Element e) {
        BTree stack[size_5], p = t;
        int top = -1, f, flags[size_5];
        do {
            while (p != nullptr) {
                stack[++top] = p;
                flags[top] = 0;
                p = p->left;
            }
            p = stack[top];
            f = flags[top--];
            if (f == 0) {
                stack[++top] = p;
                flags[top] = 1;
                p = p->right;
            } else {
                if (p->data == e)
                    return top + 2;
                p = nullptr;
            }

        } while (p != nullptr || top != -1);
    }

    /*
     * 7、二叉树的删除
     *  删除指定结点及其子树
     * 
     */
    BTree del(BTree t, Element e) {
        BTree stack[22], p = t, q;
        int top = -1;
        if (t->data == e) {
            destory(t);
            return nullptr;
        } else {
            do {
                while (p != nullptr) {
                    if (p->data == e) {
                        if (q->left == p)
                            q->left == nullptr;
                        else
                            q->right = nullptr;
                        destory(p);
                        return t;
                    }

                    stack[++top] = p;
                    q = p;
                    p = p->left;
                }

                p = stack[top--];
                q = p;
                p = p->right;
            } while (p != nullptr || top != -1);
        }
    }

    /*
     * 8、交换左右结点
     */
    int exchange_l_r(BTree t) {
        BTree p = t, w, queue[22];
        int rear;
        int front;
        if (p != nullptr) {
            queue[0] = p;
            rear = 0;
            front = -1;
            while (front < rear) {
                p = queue[++front];
                w = p->left;
                p->left = p->right;
                p->right = w;
                if (p->left != nullptr)
                    queue[++rear] = p->left;
                if (p->right != nullptr)
                    queue[++rear] = p->right;
            }
        }


    }

    void test_() {
        BTree t = tree();
        BTree t2 = copy(t);

    }

    /*
     * 二叉排序树
     */

    /*
     * 二叉排序树插入节点 非递归
     */
    int insert_(BTree &t, Element e) {
        BTree p, q;
        p = tree_node_5;
        p->data = e;
        p->left = nullptr;
        p->right = nullptr;
        if (t == nullptr) {
            t = p;
        } else {
            q = t;
            while (1) {
                if (e <= q->data) {
                    if (q->left != nullptr) {
                        q = q->left;
                    } else {
                        q->left = p;
                        break;
                    }
                } else {
                    if (q->right != nullptr) {
                        q = q->right;
                    } else {
                        q->right = p;
                        break;
                    }
                }
            }
        }
    }

    /*
     * 二叉排序树插入数据 递归
     */
    int insert_t(BTree &t, Element e) {
        if (t == nullptr) {
            t = tree_node_5;
            t->data = e;
            t->left = nullptr;
            t->right = nullptr;
        } else {
            if (e <= t->data) {
                insert_t(t->left, e);
            } else {
                insert_t(t->right, e);
            }
        }
    }

    /*
     * 创建二叉排序树
     */
    BTree sortTree(int *a, int n) {
        BTree t = nullptr;
        for (int i = 0; i < n; i++)
//            insert_(t, a[i]);
            insert_t(t, a[i]);
        return t;
    }


    /*
     *  二叉排序树删除节点
     *    为叶结点
     *    有一个子节点(左或右)
     *    有两个子节点
     *    
     *    p  要删除的结点 
     *    q  p的双亲结点
     *    
     *    ****************问题代码
     */
    int del_(BTree &t, BTree p, BTree q) {
        BTree r, s;
        int f = 0;
        if (p->left == nullptr) {//无左节点
            if (p == t) {//要删除的为根节点
                t = p->right;
            } else {
                r = p->right;
                f = 1;
            }
        } else if (p->right == nullptr) {
            if (p == t) {
                t = p->left;
            } else {
                r = p->left;
                f = 1;
            }
        } else {
            s = p;
            r = s->right;
            while (r->left != nullptr) {
                s = r;
                r = r->left;
            }

            r->left = p->left;
            if (s != p) {
                s->left = r->right;
                r->right = p->right;
            }

            if (p == t) {
                t = r;
            } else {
                f = 1;
            }
        }


        if (f == 1) {
            if (p == q->left)
                q->left = r;
            else
                q->right = r;
        }
        free(p);
    }

    /*
     * 二叉排序树的查找 非递归
     */
    BTree find_1(const BTree t, const Element e) {
        BTree p = t;
        while (p != nullptr) {
            if (p->data == e)
                return p;
            if (e < p->data)
                p = p->left;
            else
                p = p->right;
        }
        return nullptr;
    }


    /*
     * 二叉树查找 递归
     */
    BTree find_1_traverse(const BTree t, const Element e) {

        if (t == nullptr)
            return nullptr;
        if (t->data == e)
            return t;
        if (e < t->data)
            return find_1_traverse(t->left, e);
        else
            return find_1_traverse(t->right, e);
    }


    void test_(BTree t) {

    }


    int test() {
//        int a[] = {1, 2, 3, 4, 5, 6};
//        BTree t = sortTree(a, 6);
//        layerOrder(t);
//        BTree t2 = find_1(t, 2);
//        BTree t2 = find_1_traverse(t, 3);
//        layerOrder(t2);

        BTree t = tree();
    }
}


namespace graph_5 {
#define  Infinity -1
    typedef enum {
        DG, DN, UDG, UDN
    } GraphType;

    typedef int Vertex;
    typedef int Arc;
    typedef int Weight;

    /*邻接矩阵构造*/
    typedef struct {
        Vertex vertexes[size_5];
        int vnum, anum;
        Arc arcs[size_5][size_5];
        GraphType type;
    } m_graph;


    /*十字链表构造*/
    typedef struct o_arc_box {
        int tailvex, headvex;
        struct o_arc_box *tail, *head;
        int w;
    } o_arc_box;

    typedef struct o_vnode {
        Vertex v;
        o_arc_box *first_in, *first_out;
    } o_vnode;

    typedef struct {
        o_vnode vlist[size_5];
        int vnum, anum;
    } o_graph;

    /*邻接多重链表*/
    typedef struct mutli_arc_node {
        int w;
        int i, j;
        mutli_arc_node *inode, *jnode;
        int flag;
    } mutli_arc_node;

    typedef struct mutli_vnode {
        Vertex v;
        mutli_arc_node *firstEdge;
    } mutli_vnode;

    typedef struct {
        mutli_vnode vlist[size_5];
        int vnum, anum;
    } mutli_graph;


    /*
     * 创建邻接矩阵
     */
    int m_create(m_graph &g) {
        for (int i = 0; i < g.vnum; i++)
            scanf("%d", &g.vertexes[i]);

        for (int j = 0; j < g.vnum; j++)
            for (int i = 0; i < g.vnum; i++)
                g.arcs[j][i] = Infinity;

        int w, row, col;

        for (int k = 0; k < g.vnum; k++) {
            scanf("%d %d %d", &w, &row, &col);
            g.arcs[col][row] = w;
            g.arcs[row][col] = w;
        }
    }

    typedef struct enode {
        int ver;
        int weight;
        enode *link;
    } enode, Edge;

    typedef struct vnode {
        Edge *edge;
        Vertex data;
    } vnode, vlist[size_5];

    typedef struct {
        int vnum, anum;
        vlist vers;
        int GraphType;
    } graph;


    int visited[size_5];

    void m_dfs(m_graph &g, int v) {
        visited[v] = 1;
        printf("%d 邻接矩阵顶点信息", g.vertexes[v]);

        for (int i = 0; i < g.vnum; i++)
            if (visited[i] == 0)
                m_dfs(g, i);
    }

    void m_dfs_traverse(m_graph &g) {
        for (int i = 0; i < g.vnum; i++)
            visited[i] = 0;

        for (int j = 0; j < g.vnum; j++)
            if (visited[j] == 0)
                m_dfs(g, j);
    }


    void dfs(graph &g, int v) {
        visited[v] = 1;
        printf("%d 邻接表顶点信息", g.vers[v].data);
        Edge *e = g.vers[v].edge;
        while (e != nullptr) {
            if (visited[e->ver] == 0)
                dfs(g, e->ver);
            e = e->link;
        }
    }

    void dfs_traverse(graph &g) {
        for (int i = 0; i < g.vnum; i++)
            visited[i] = 0;

        for (int j = 0; j < g.vnum; j++)
            if (visited[j] == 0)
                dfs(g, j);
    }


    int firstAdg(m_graph g, int v) {
        return 1;
    }

    int nextAdg(m_graph g, int v) {
        return 1;
    }

    void m_bfs(m_graph &g, int v) {
        visited[v] = 1;
        printf("%d 邻接矩阵顶点信息", g.vertexes[v]);
        link_queue_5::Queue q;
        link_queue_5::init(&q);
        link_queue_5::enQueue(&q, v);
        while (q.front != q.rear) {
            link_queue_5::deQueue(&q, &v);
            int w = firstAdg(g, v);
            while (w != -1) {
                if (visited[w] == 0) {
                    visited[w] = 1;
                    printf("%d 邻接矩阵顶点信息", g.vertexes[w]);
                    link_queue_5::enQueue(&q, w);
                }
                w = nextAdg(g, v);
            }

        }


    }


    void m_bfs_traverse(m_graph &g) {
        for (int i = 0; i < g.vnum; i++)
            visited[i] = 0;

        for (int j = 0; j < g.vnum; j++)
            if (visited[j] == 0)
                m_bfs(g, j);
    }

}

namespace sort_5 {
    int swap(int *a, int *b) {
        int t = *a;
        *a = *b;
        *b = t;
    }

    int insert_sort_1(int *a, int n) {
        int f, j;
        for (int i = 1; i < n; i++) {
            f = a[i];

            for (j = i - 1; a[j] > f && j >= 0; j--) {
                a[j + 1] = a[j];
            }
            a[j + 1] = f;
        }
    }

    int insert_b_sort_1(int *a, int n) {
        int f, low, high, mid;
        for (int i = 1; i < n; i++) {
            f = a[i], low = 0, high = i - 1;

            while (low <= high) {
                mid = (low + high) / 2;
                if (a[mid] > f)
                    high = mid - 1;
                else
                    low = mid + 1;
            }

            for (int j = i - 1; j >= low; j--)
                a[j + 1] = a[j];
            a[low] = f;
        }
    }

    int insert_b_sort_2(int *a, int n) {
        int f, low, high, mid;
        for (int i = 1; i < n; i++) {
            f = a[i], low = 0, high = i - 1;

            while (low <= high) {
                mid = (low + high) / 2;
                if (a[mid] > f)
                    high = mid - 1;
                else
                    low = mid + 1;
            }

            for (int j = i - 1; j >= low; j--)
                a[j + 1] = a[j];

            a[low] = f;
        }
    }


    void insert_b_sort_3(int *a, int n) {
        int mid, low, high, f;
        for (int i = 1; i < n; i++) {
            f = a[i];
            low = 0;
            high = i - 1;

            while (low <= high) {
                mid = (low + high) / 2;
                if (f < a[mid])
                    high = mid - 1;
                else
                    low = mid + 1;
            }

            for (int j = i - 1; j >= low; j--)
                a[j + 1] = a[j];

            a[low] = f;
        }
    }

    int shell_sort_1(int *a, int n, int gap) {
        int g = n / gap, t, j;
        while (g >= 1) {
            for (int i = g + 1; i < n; i++) {
                t = a[i];
                for (j = i - g; a[j] > t && j >= 0; j -= g)
                    a[j + g] = a[j];
                a[j + g] = t;
            }
            g /= gap;
        }
    }

    void shell_sort_2(int *a, int n, int gap) {
        int f, g, j;
        for (int i = gap + 1; i < n; i++) {
            f = a[i];
            for (j = i - gap; j > 0 && a[j] > f; j -= gap) {
                a[j + gap] = a[j];
            }

            a[j + gap] = f;

        }
    }

    void shell_sort_3(int *a, int n, int gap) {
        int g = n, t, f, j;

        while (g > 1) {
            g /= gap;
            do {
                f = 0;
                for (int i = 0; i < n - g; i++) {
                    j = i + g;
                    if (a[i] > a[j]) {
                        swap(&a[i], &a[j]);
                        f = 1;
                    }
                }
            } while (f != 0);
        }
    }

    int partition_4(int *a, int low, int high) {
        int left = low, right = high + 1;
        do {
            do left++; while (low < high && a[left] < a[low]);
            do right--; while (low < high && a[right] > a[low]);
            if (left < right) swap(&a[left], &a[right]);
        } while (left < right);
        swap(&a[low], &a[right]);
        return right;
    }

    int partition_1(int *a, int low, int high) {
        int left = low, right = high + 1, k = a[low];
        do {
            do left++; while (low < high && a[left] < k);
            do right--; while (low < high && a[right] > k);
            if (left < right) swap(&a[left], &a[right]);
        } while (left < right);
        swap(&a[low], &a[right]);
        return right;
    }


    void quick_sort_1(int *a, int left, int right) {
        if (left < right) {
            int p = partition_1(a, left, right);
            quick_sort_1(a, left, p - 1);
            quick_sort_1(a, p + 1, right);
        }
    }


    void select_sort_1(int *a, int n) {
        int min, t;
        for (int i = 0; i < n; i++) {
            min = i;
            for (int j = i + 1; j < n; j++)
                if (a[j] < a[min])
                    min = j;

            if (min != i)
                swap(&a[i], &a[min]);

        }
    }

    int heapAdjust_1(int *a, int i, int n) {
        int t = a[i];
        for (int j = 2 * i + 1; j < n; j = 2 * j + 1) {
            if (j + 1 < n && a[j] < a[j + 1])
                j++;
            if (a[j] > t) {
                swap(&a[i], &a[j]);
                i = j;
            } else {
                break;
            }
        }
//        ps_int(a, n);
    }

    int heap_sort_1(int *a, int n) {
        for (int i = n / 2 - 1; i >= 0; i--)
            heapAdjust_1(a, i, n);

        for (int j = n - 1; j >= 0; j--) {
            swap(&a[0], &a[j]);
            heapAdjust_1(a, 0, j);
        }
    }

    void test() {
        int a[] = {21, 13, 51, 2, 3, 6, 8, 4, 45, 1};
        ps_int(a, 10);
//        insert_b_sort_3(a, 10);
//        quick_sort_1(a, 0, 9);
        heap_sort_1(a, 10);
        ps_int(a, 10);
    }
}

namespace string_5 {
    int index_1(char c1[], char c2[], int pos) {

        int i = pos;
        int j = 0;
        int i1 = strlen(c1);
        int j1 = strlen(c2);

        while (i <= i1 && j <= j1) {
            if (c1[i] == c2[j]) {
                i++;
                j++;
            } else {
                i = i - j + 1;
                j = 0;
            }
        }
        if (j > j1)
            return i - j;
        else
            return -1;
    }


    int get_next_1(char c1[], int *next) {
        int i = 1, j = 0;
        next[1] = 0;
        int len = strlen(c1);
        while (i < len) {
            if (j == 0 || c1[i - 1] == c1[j - 1]) {
                i++;
                j++;
//                next[i] = j;

                if (c1[i] != c1[j]) {
                    next[i] = j;
                } else {
                    next[i] = next[j];
                }
            } else {
                j = next[j];
            }
        }
    }

    int kmp_index_1(char c1[], char c2[], int pos) {
        int i = pos, j = 0, len_1 = strlen(c1), len_2 = strlen(c2);
        int len = len_1 >= len_2 ? len_1 : len_2;
        int next[len];
        get_next_1(c2, next);

        ps_int(next, len_2 + 1);

        while (i <= len_1 && j <= len_2) {
            if (j == 0 || c1[i] == c2[j]) {
                i++;
                j++;
            } else {
                j = next[j];
            }
        }

        if (j > len_2) {
            return i - len_2;
        } else {
            return -1;
        }

    }


    int next_3(char c[], int a[]) {
        int i = 1, j = 0;
        a[0] = -1;
        a[1] = 0;
        int len = strlen(c);
        while (i < len) {
            if (j == 0 || c[i] == c[j]) {
                ++i;
                ++j;

                // a[i] = j;

                /*
                 * next改进
                 */
                if (c[i] != c[j])
                    a[i] = j;
                else
                    a[i] = a[j];

            } else {
                j = a[j];
            }
        }
        ps_int(a, len + 1);
    }


    int kmp_index_3(char s[], char t[], int pos = 0) {
        int i = pos;
        int j = 0;
        int s_len = strlen(s);
        int t_len = strlen(t);
        int next[s_len];
        next_3(t, next);

        while (i <= s_len && j <= t_len) {
            if (j == 0 || s[i] == t[j]) {
                ++i;
                ++j;
            } else {
                j = next[j];
            }
        }

        if (j >= t_len) {
            return i - t_len;
        } else {
            return -1;
        }

    }

    void test() {
        char *s = "abcababcabx";
        char *t = "abcabx";
        int p = kmp_index_3(s, t, 0);
        std::cout << p << std::endl;
    }


}

namespace sq_list_5_1 {
#define CAPICITY 10

    typedef struct {
        int *data;
        int length;
        int lisesize;
    } SqList;


    int merge(SqList a, SqList b, SqList &c) {
        int len_a = a.length;
        int len_b = b.length;
        int i = 0, j = 0, k = 0;

        while (i < len_a && j < len_b)
            if (a.data[i] <= b.data[j])
                c.data[k++] = a.data[i++];
            else
                c.data[k++] = b.data[j++];

        while (i < len_a)
            c.data[k++] = a.data[i++];
        while (j < len_b)
            c.data[k++] = b.data[j++];

        c.length = k;

    }

    void testMerge() {
        int aa[4] = {1, 3, 5, 7};
        int bb[6] = {2, 4, 6, 8, 10, 12};
        int cc[10];
        SqList a = {
                aa,
                4
        };

        SqList b = {
                bb,
                6
        };
        SqList c = {
                cc,
                0
        };

        merge(a, b, c);
        ps_int(c.data, c.length);
    }


    int init(SqList &list) {
        list.data = (int *) malloc(sizeof(int) * CAPICITY);
        list.length = 0;
        list.lisesize = CAPICITY;
    }

    int insert(SqList &list, int p, int e) {
        if (p < 1 || p > list.length + 1)
            return errCode("插入位置不合法！", 0);

        if (list.length >= list.lisesize) {
            list.data = (int *) realloc(list.data, sizeof(int) * (list.lisesize + CAPICITY));
            list.lisesize += CAPICITY;
        }

        int *a = &list.data[p - 1];//插入位置
        for (int *j = &list.data[list.length - 1]; j >= a; j--)
            *(j + 1) = *j;
        *a = e;


//        for (int i = list.length - 1; i >= p; i++) 
//            list.data[i + 1] = list.data[i];
//        list.data[p-1]=e;

        list.length++;
    }


    int del(SqList &list, int p) {
        if (p < 1 || p > list.length)
            return errCode("删除位置不合法", 0);

        int *a = &list.data[p - 1];
        int *b = &list.data[list.length - 1];
        for (int *i = a; i < b; i++)
            *i = *(i + 1);

        list.length--;

        free(a);

    }

    void testInsert() {
        SqList list;
        init(list);
        for (int i = 0; i < 11; i++)
            insert(list, i + 1, i * 3);
        ps_int(list.data, list.length);

        del(list, 3);

        ps_int(list.data, list.length);
    }

    typedef struct node {
        int data;
        struct node *next;
    } node, *LinkList;
#define newNode (LinkList) malloc(sizeof(node))

    int ps_link_list(LinkList list) {
        if (list == nullptr)
            return errCode("empty linklist", 0);
        LinkList p = list;
        while (p != nullptr) {
            printf("%d\t", p->data);
            p = p->next;
        }
    }


    LinkList create(int n = 5) {
        LinkList list = nullptr, p, r;
        for (int i = 0; i < n; i++) {
            p = newNode;
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


    int get(LinkList list, int i, int *e) {
        LinkList p = list;
        while (i-- > 1 && p != nullptr)
            p = p->next;

        if (p == nullptr)
            return errCode("指定位置元素不存在", i);
        *e = p->data;
        return errCode("search successful!", 1);
    }


    int insert(LinkList &list, int i, int e) {
        LinkList p = list;
        while (i-- > 1 && p != nullptr) 
            p = p->next;
        
        
        
    }


    void testLinkList() {
        LinkList list = create();
        ps_link_list(list);
        int a;
        get(list, 2, &a);
        std::cout << a << std::endl;

    }


    void test() {
//        testInsert();
        testLinkList();
    }

}


namespace ds_5 {

    void test() {
//        dynamic_sq_link_list_5::test();
//        sqList_5::test();
//        sq_stack_5::test();
//        link_queue_5::test();
//        cycle_queue_5::test();
//        tree_5::test();
//        sort_5::test();
//        string_5::test();
        sq_list_5_1::test();

    }
}