
#include <iostream>

using namespace std;

void ps_int(int *, int);

void ps_char(int *, int);

int errCode(string, int);

#define CAPICITY 40
namespace stack_5_1 {
    typedef struct snode {
        int *base;
        int *top;
        int stacksize;
    } stack;

    int init(stack &s) {
        s.base = (int *) malloc(sizeof(int) * CAPICITY);
        s.top = s.base;
        s.stacksize = CAPICITY;
    }

    int getTop(stack s, int &e) {
        if (s.top == s.base)
            return errCode("空栈没有数据", 0);
        e = *(s.top - 1);
        return 1;
    }

    int push(stack &s, int e) {

        if ((s.top - s.base) >= s.stacksize) {
            s.base = (int *) realloc(s.base, sizeof(int) * CAPICITY);
            s.top = s.base + CAPICITY;
            s.stacksize += CAPICITY;
        }
        *s.top++ = e;
        return 1;
    }

    int pop(stack &s, int &e) {
        if (s.top == s.base)
            return errCode("空栈没有数据", 0);
        e = *--s.top;
        return 1;
    }

    void test_1() {
        stack s;
        init(s);
        for (int i = 0; i < 7; i++)
            push(s, i + 1);

        ps_int(s.base, s.stacksize);
        int e;
        getTop(s, e);
        std::cout << e << std::endl;
    }

    /*
     * 进制转换
     */

    int ex_(int num, int n) {

        stack s;
        init(s);

        while (num > 0) {
            push(s, num % n);
            num /= n;
        }
        int e;
        for (int i = 0; i < s.stacksize; i++) {
            pop(s, e);
            std::cout << e << "\t";
        }
    }

    void test() {
        ex_(10, 2);
    }


}

namespace queue_5_1 {
#define  newNode (qpointer) malloc(sizeof(qnode))


    typedef struct qnode {
        int data;
        qnode *next;
    } qnode, *qpointer;

    typedef struct {
        qpointer front, rear;
    } queue;

    int ps_queue(queue *q) {
        if (q->front == q->rear)
            return errCode("空队列", -1);
        qpointer p = q->front;
//        while (p != nullptr && p != q->rear) {
        while (p != nullptr) {
            printf("%d\t", p->data);
            p = p->next;
        }
        puts("");
    }

    int init(queue &q) {
        q.front = nullptr;
        q.rear = nullptr;
    }

    int enQueue(queue &q, int e) {
        qpointer p = newNode;

        p->data = e;
        p->next = nullptr;

        if (q.front == nullptr)
            q.front = p;

        if (q.rear == nullptr) {
            q.rear = p;
        } else {
            q.rear->next = p;
            q.rear = p;
        }
    }

    int deQueue(queue &q, int &e) {

        if (q.front == nullptr)
            return errCode("empty queue", 0);

        qpointer p = q.front;
        e = p->data;
        q.front = p->next;
        free(p);
    }

    void test_1() {
        queue q;
        init(q);

        for (int i = 0; i < 8; i++)
            enQueue(q, i + 1);

        ps_queue(&q);
        int e;
        for (int j = 0; j < 8; j++) {
            deQueue(q, e);
            std::cout << e << "\t";
        }
    }

    typedef struct cqnode {
        int *data;
        int front;
        int rear;
    } cqnode, cqueue;


    int init(cqueue &q) {
        q.data = (int *) malloc(sizeof(int) * CAPICITY);
        q.rear = 0;
        q.front = 0;
    }

    int length(cqueue q) {
        return (q.rear - q.front + CAPICITY) % CAPICITY;
    }

    int encqueue(cqueue &q, int e) {
        if ((q.rear + 1) % CAPICITY == q.front)
            return errCode("full ", 0);

        q.data[q.rear] = e;
        q.rear = (q.rear + 1) % CAPICITY;
        return errCode("inqueue success", 1);
    }

    int decqueue(cqueue &q, int &e) {
        if (q.rear == q.front)
            return errCode("empty queue", 0);

        e = q.data[q.front];
        q.front = (q.front + 1) % CAPICITY;
    }

    void test() {

    }

}


namespace strint_5_1 {
    typedef char *cstring;

    int index_1(cstring s, cstring t, int pos = 0) {
        int s_len = strlen(s);
        int t_len = strlen(t);
        int i = pos;
        int j = 1;
        while (i <= s_len && j <= t_len) {
            if (s[i] == t[j]) {
                i++;
                j++;
            } else {
                j = 1;
                i = i - j + 2;
            }
        }
        if (j > t_len)
            return i - j;
        else
            return -1;
    }


    int next_1(cstring t, int *a) {
        int len = strlen(t);
        int i = 1, j = 0;
        a[1] = 0;

        while (i < len)
            if (j == 0 || t[i] == t[j]) {
                i++;
                j++;
                a[i] = j;
            } else
                j = a[j];

    }

    int nextval_1(cstring t, int *a) {
        int len = strlen(t);
        int i = 1, j = 0;
        a[1] = 0;
        while (i < len)
            if (j == 0 || t[i] == t[j]) {
                i++;
                j++;
                if (t[i] != t[j])
                    a[i] = j;
                else
                    a[i] = a[j];
            } else
                j = a[j];
    }


    int kmp_index_1(cstring s, cstring t, int pos = 0) {
        int s_len = strlen(s);
        int t_len = strlen(t);
        int a[t_len];
        next_1(t, a);
        ps_int(a, t_len);
        int i = pos, j = 0;
        while (i <= s_len && j <= t_len) {
            if (j == 0 || s[i] == t[j]) {
                i++;
                j++;
            } else {
                j = a[j];
            }
        }

        if (j > t_len)
            return i - j;
        else
            return -1;

    }


    void test_kmp() {
        cstring s = "_abcdef";
        cstring t = "_cde";
//        int p = index_1(s, t);
        int p = kmp_index_1(s, t);
        std::cout << "位置=" << p << std::endl;
    }

    typedef struct {
        char *str;
        int length;
    } hstring;

    int insert_hstring(hstring &s, hstring t, int pos = 0) {

        if (pos < 0 || pos > s.length + 1)
            return errCode("插入位置有误", 0);
        if (t.length > 0) {
            s.str = (char *) realloc(s.str, sizeof(char) * (s.length + t.length));

            for (int i = s.length - 1; i >= pos - 1; i--)
                s.str[i + 1] = s.str[i];


            for (int j = pos; j < t.length; j++)
                s.str[j] = t.str[j - pos];

            s.length += t.length;
        }

    }


    int compare(hstring s, hstring t) {
        for (int i = 0; i < s.length && i < t.length; i++)
            if (s.str[i] != t.str[i])
                return s.str[i] - t.str[i];

        return s.length - t.length;
    }


    void test() {
        char *c1 = "aaa";
        char *c2 = "22";
        hstring h1 = {
                c1,
                3
        };
        hstring h2 = {
                c2, 2
        };

        insert_hstring(h1, h2, 0);
        std::cout << c1 << std::endl;

    }
}

/*
 * init destory  
 * create clear isempth depth root value assign parent 
 * left right insert delete 
 * preOrderTraverse inOrderTraverse postOrderTraverse levelOrderTraverse
 * 
 */
namespace btree_5_1 {
#define treeNode (Btree)malloc(sizeof(node))
    typedef struct node {
        int data;
        struct node *left, *right;
    } node, *Btree;

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
    Btree tree() {
        Btree a, b, c, d, e, f, g, h, i, j, k;
        a = treeNode;
        a->data = 'A';
        b = treeNode;
        b->data = 'B';
        c = treeNode;
        c->data = 'C';
        d = treeNode;
        d->data = 'D';
        e = treeNode;
        e->data = 'E';
        f = treeNode;
        f->data = 'F';
        g = treeNode;
        g->data = 'G';
        h = treeNode;
        h->data = 'H';
        i = treeNode;
        i->data = 'I';
        j = treeNode;
        j->data = 'J';
        k = treeNode;
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

    int preOderTraverse(Btree t) {
        if (t != nullptr) {
            printf("%c\t", t->data);
            preOderTraverse(t->left);
            preOderTraverse(t->right);
        }
    }

    int inOderTraverse(Btree t) {
        if (t != nullptr) {
            inOderTraverse(t->left);
            printf("%c\t", t->data);
            inOderTraverse(t->right);
        }
    }

    int postOderTraverse(Btree t) {
        if (t != nullptr) {
            postOderTraverse(t->left);
            postOderTraverse(t->right);
            printf("%c\t", t->data);
        }
    }

    void test_orderTraverse() {
        Btree t = tree();
        puts("");
        preOderTraverse(t);
        inOderTraverse(t);
        puts("");
        postOderTraverse(t);
    }


    int preOrInOrder(Btree t, int pre = 2) {
        Btree p = t, stack[CAPICITY];
        int top = -1;
        do {
            while (p != nullptr) {
                if (pre == 1)
                    printf("%c\t", p->data);
                stack[++top] = p;
                p = p->left;
            }
            p = stack[top--];
            if (pre == 2)
                printf("%c\t", p->data);
            p = p->right;

        } while (top != -1 || p != nullptr);
        std::cout << "" << std::endl;
    }


    int postOrder(Btree t) {
        Btree p = t, stack[CAPICITY];
        int f, top = -1, flags[CAPICITY];

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
                printf("%c\t", p->data);
                p = nullptr;
            }
        } while (top != -1 || p != nullptr);
        puts("");
    }

    
    
    

    void test() {
        Btree t = tree();
        
        
        
    }
}

namespace ds_5_1 {

    void test() {
//        queue_5_1::test();
//        strint_5_1::test();
        btree_5_1::test();
    }
}