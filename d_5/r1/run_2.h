
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


    int layorOrder(Btree t) {
        Btree p = t, queue[20];
        int f, r;

        if (p != nullptr) {
            queue[0] = t;
            f = -1;
            r = 0;
            while (f < r) {
                p = queue[++f];
                printf("%c\t", p->data);
                if (p->left != nullptr)
                    queue[++r] = p->left;
                if (p->right != nullptr)
                    queue[++r] = p->right;
            }
        }

        std::cout << "" << std::endl;
    }

    int leafCount_traverse(Btree t) {
        if (t == nullptr)
            return 0;

        if (t->left == nullptr && t->right == nullptr)
            return 1;
        return leafCount_traverse(t->left) + leafCount_traverse(t->right);

    }


    int depth_traverse(Btree t) {
        if (t == nullptr)
            return 0;
        int leftCount, rightCount;
        leftCount = depth_traverse(t->left);
        rightCount = depth_traverse(t->right);
        if (leftCount > rightCount)
            return leftCount + 1;
        else
            return rightCount + 1;
    }


    int similar(Btree t1, Btree t2) {
        if (t1 == nullptr && t2 == nullptr)
            return 1;
        if (t1 != nullptr && t2 != nullptr
            && similar(t1->left, t2->left)
            && similar(t1->right, t2->right))
            return 1;
        return 0;
    }

    int equality(Btree t1, Btree t2) {
        if (t1 == nullptr && t2 == nullptr)
            return 1;
        if (t1 != nullptr && t2 != nullptr
            && t1->data == t2->data
            && equality(t1->left, t2->left)
            && equality(t1->right, t2->right))
            return 1;
        return 0;
    }


    int create(Btree &t) {
        char c;
        scanf("%c", &c);
        if (c = '\0')
            t = nullptr;
        else {
            t = treeNode;
            t->data = c;
            create(t->left);
            create(t->right);
        }
    }


    int destory(Btree &t) {
        if (t != nullptr) {
            destory(t->left);
            destory(t->right);
            free(t);
        }
    }

    Btree copy(Btree &t) {
        Btree b;
        if (t == nullptr)
            b = nullptr;
        else {
            b = treeNode;
            b->data = t->data;
            b->left = copy(t->left);
            b->right = copy(t->right);
        }
        return b;
    }


    int depth(Btree t) {
        Btree p = t, stack[20];
        int max = 0, d, top = -1, dps[20];

        if (t != nullptr) {
            d = 1;
            do {
                while (p != nullptr) {
                    stack[++top] = p;
                    dps[top] = d;
                    p = p->left;
                    d++;
                }
                p = stack[top];
                d = dps[top--];
                if (p->left == nullptr && p->right == nullptr)
                    if (d > max)
                        max = d;

                p = p->right;
                d++;
            } while (p != nullptr || top != -1);
        }
        return max;
    }


    int findNodeLayor(Btree t, char cc) {
        Btree p = t, s[20];
        int m = 0, c = 0, a = -1, ds[20];

        if (p != nullptr) {
            c = 1;
            do {
                while (p != nullptr) {
                    if (p->data == cc)
                        return c;
                    s[++a] = p;
                    ds[a] = c;
                    p = p->left;
                    c++;
                }

                p = s[a];
                c = ds[a--];
                if (p->data == cc)
                    return c;
                p = p->right;
                c++;
            } while (p != nullptr || a != -1);
        }

        return -1;
    }

    int exLeftAndRight(Btree t) {
        Btree p = t, q[20], a;
        int f, r;

        if (p != nullptr) {
            q[0] = p;
            f = -1;
            r = 0;
            while (f < r) {
                p = q[++f];

                a = p->left;
                p->left = p->right;
                p->right = a;

                if (p->left != nullptr)
                    q[++r] = p->left;

                if (p->right != nullptr)
                    q[++r] = p->right;
            }
        }
    }


    int insert(Btree &t, int e) {
        Btree w = treeNode, p, q;
        w->data = e;
        w->left = nullptr;
        w->right = nullptr;

        if (t == nullptr) {
            t = w;
        } else {
            p = t;
            while (1) {
                if (e < p->data)
                    if (p->left != nullptr)
                        p = p->left;
                    else {
                        p->left = w;
                        break;
                    }
                else {
                    if (p->right != nullptr)
                        p = p->right;
                    else {
                        p->right = w;
                        break;
                    }
                }

            }
        }
    }

    int insert_traverse(Btree t, int e) {
        if (t == nullptr) {
            t = treeNode;
            t->data = e;
            t->left = nullptr;
            t->right = nullptr;
        } else {
            if (e < t->data)
                insert_traverse(t->left, e);
            else {
                insert_traverse(t->right, e);
            }
        }
    }


    int del_(Btree &p) {
        Btree q, s;
        if (p->left == nullptr) {
            q = p;
            p = p->right;
            free(q);
        } else if (p->right == nullptr) {
            q = p;
            p = p->left;
            free(q);
        } else {
            q = p;
            s = p->left;
            while (s->right != nullptr) {
                q = s;
                s = s->right;
            }
            p->data = s->data;
            if (q != p)
                q->right = s->left;
            else
                q->left = s->left;
            free(s);
        }
        return 1;
    }

    int del(Btree &t, int e) {

        if (t == nullptr)
            return errCode("空树没有可删除数据", 0);

        if (t->data == e)
            return del_(t);
        if (t->data < e)
            return del(t->right, e);
        if (t->data > e)
            return del(t->left, e);
    }


    void test() {
        Btree t = tree();
        layorOrder(t);
//        exLeftAndRight(t);
//        layorOrder(t);
        del(t, 'B');
        layorOrder(t);
    }
}

namespace graph_5_1 {

    typedef struct arcnode {
        int ver;
        int w;
    } arcnode, arcs[CAPICITY][CAPICITY];

    typedef struct {
        int vexs[CAPICITY];
        arcs arc;
        int vnum, anum;
    } m_graph;

    int m_create(m_graph &g) {
        //初始化边
        for (int i = 0; i < g.anum; i++)
            for (int j = 0; j < g.anum; j++)
                g.arc[i][j].ver = -1;

        //顶点赋值
        for (int k = 0; k < g.vnum; k++)
            scanf("%d", &g.vexs[k]);
        int row, col, w;

        //边赋值
        for (int j = 0; j < g.anum; j++) {
            scanf("%d %d %d", &row, &col, &w);
            g.arc[row][col].ver = w;
            g.arc[col][row].ver = w;
        }

    }

    typedef struct enode {
        int ver;
        int w;
        enode *next;
    } enode, *elink;

    typedef struct vnode {
        int vdata;
        enode *edge;
    } vnode;

    typedef struct {
        int vnum, anum;
        vnode vertex[11];
    } graph;


    int create(graph &g) {
        //录入顶点
        for (int i = 0; i < g.vnum; i++) {
            scanf("%d", &g.vertex[i].vdata);
            g.vertex[i].edge = nullptr;
        }

        elink e;
        int c, r, w;
        for (int j = 0; j < g.anum; j++) {
            scanf("%d %d %d", &c, &r, &w);
            e = (elink) malloc(sizeof(enode));
            e->ver = c;
            e->next = g.vertex[j].edge;
            g.vertex[j].edge = e;

            e = (elink) malloc(sizeof(enode));
            e->ver = r;
            e->next = g.vertex[j].edge;
            g.vertex[j].edge = e;
        }
    }

    int visited[11];


    int visit(int data) {

    }

    int m_dfs(m_graph g, int v) {
        visited[v] = 1;
        visit(g.vexs[v]);
        for (int i = 0; i < g.vnum; i++)
            if (visited[i] == 0)
                m_dfs(g, i);
    }

    int m_dfs_traverse(m_graph g) {
        for (int i = 0; i < g.vnum; i++)
            visited[i] = 0;
        for (int j = 0; j < g.vnum; j++)
            if (visited[j] == 0)
                m_dfs(g, j);
    }


    int dfs(graph g, int v) {
        visited[v] = 1;
        visit(g.vertex[v].vdata);
        enode *e = g.vertex[v].edge;
        while (e != nullptr) {
            if (visited[e->ver] == 0)
                dfs(g, e->ver);
            e = e->next;
        }
    }

    int dfs_traverse(graph g) {
        for (int i = 0; i < g.vnum; i++)
            visited[i] = 0;

        for (int j = 0; j < g.vnum; j++)
            if (visited[j] == 0)
                dfs(g, j);
    }


    int m_bfs(m_graph g) {
        for (int i = 0; i < g.vnum; i++)
            visited[i] = 0;


        int queue[11];
        int front = 0, rear = 0;
        int a;
        for (int j = 0; j < g.vnum; j++) {
            if (visited[j] == 0) {
                visited[j] = 1;

                visit(g.vexs[j]);

                queue[rear++] = j;

                while (rear != front) {
                    a = queue[front++];
                    for (int i = 0; i < g.vnum; i++) {
                        //g.arc[a][i].ver == 1  判断当前边上是否有顶点
                        if (g.arc[a][i].ver == 1 && visited[i] == 0) {
                            visited[i] = 1;
                            visit(g.vexs[i]);
                            queue[rear++] = i;
                        }
                    }
                }
            }
        }
    }

    int bfs(graph g) {
        for (int i = 0; i < g.vnum; i++)
            visited[i] = 0;

        enode *e;
        int f = 0, r = 0, q[11];

        for (int j = 0; j < g.vnum; j++) {
            if (visited[j] == 0) {
                visited[j] = 1;
                visit(g.vertex[j].vdata);
                q[r++] = j;
                while (f != r) {
                    j = q[f++];
                    e = g.vertex[j].edge;
                    while (e != nullptr) {
                        if (visited[e->ver] == 0) {
                            visited[e->ver] = 1;
                            visit(g.vertex[e->ver].vdata);
                            q[r++] = e->ver;
                        }
                        e = e->next;
                    }
                }
            }
        }
    }


    void test() {

    }
}

namespace sort_5_1 {
/*
 * 冒泡 选择 插入 希尔 快排 堆积 归并 基数
 */
    int a[] = {12, 3, 41, 4, 1, 7, 15, 88, 66, 25};


    int swap(int *a, int *b) {
        int q = *a;
        *a = *b;
        *b = q;
    }


    int partition_1(int *a, int low, int high) {
        int i = low, j = high + 1, k = a[low];
        do {
            do i++; while (low < high && a[i] < k);
            do j--; while (low < high && a[j] > k);
            if (i < j) swap(&a[i], &a[j]);
        } while (i < j);
        swap(&a[low], &a[j]);
        return j;
    }

    int quick_sort_1(int *a, int low, int high) {
        if (low < high) {
            int p = partition_1(a, low, high);
            quick_sort_1(a, low, p - 1);
            quick_sort_1(a, p + 1, high);
        }
    }

    int bubble_sort_1(int *a, int n) {
        int f = 1;
        for (int i = 0; i < n && f > 0; i++) {
            f = 0;
            for (int j = i + 1; j < n; j++) {
                if (a[j] < a[i]) {
                    swap(&a[j], &a[i]);
                    f = 1;
                }
            }
        }
    }

    int insert_sort_1(int *a, int n) {
        int t, j;
        for (int i = 1; i < n; i++) {
            if (a[i] < a[i - 1]) {
                t = a[i];
                for (j = i - 1; t < a[j] && j >= 0; j--) {
                    a[j + 1] = a[j];
                }
                a[j + 1] = t;
            }
        }
    }

    int select_sort_1(int *a, int n) {
        int min;
        for (int i = 0; i < n; i++) {
            min = i;
            for (int j = i + 1; j < n; j++) {
                if (a[j] < a[min])
                    min = j;
            }

            if (min != i)
                swap(&a[i], &a[min]);
        }
    }


    int shell_sort_1(int *a, int n, int gap = 2) {
        int t, g = n / gap, j;
        while (g > 0) {
            for (int i = g; i < n; i++) {
                t = a[i];
                for (j = i - g; a[j] > t && j >= 0; j -= g) {
                    a[j + g] = a[j];
                }
                a[j + g] = t;
            }
            g /= gap;
        }
    }

    int insert_b_sort_1(int *a, int n) {
        int t, low, high, mid;
        for (int i = 0; i < n; i++) {
            t = a[i], low = 0, high = i - 1;
            while (low <= high) {
                mid = (low + high) / 2;
                if (a[mid] > t) {
                    high = mid - 1;
                } else {
                    low = mid + 1;
                }
            }

            for (int j = i - 1; j >= low; j--)
                a[j + 1] = a[j];

            a[low] = t;
        }
    }


    int bubble_sort_2(int *a, int n) {
        int f = 1;
        for (int i = 0; i < n && f > 0; i++) {
            f = 0;
            for (int j = i + 1; j < n; j++) {
                if (a[j] < a[i]) {
                    swap(&a[j], &a[i]);
                    f = 1;
                }
            }
        }
    }

    int select_sort_2(int *a, int n) {
        int m;
        for (int i = 0; i < n; i++) {
            m = i;
            for (int j = i + 1; j < n; j++) {
                if (a[j] < a[m]) {
                    m = j;
                }
            }

            if (m != i)
                swap(&a[m], &a[i]);
        }
    }

    int insert_sort_2(int *a, int n) {
        int t, j;
        for (int i = 1; i < n; i++) {
            t = a[i];
            for (j = i - 1; a[j] > t && j >= 0; j--) {
                a[j + 1] = a[j];
            }
            a[j + 1] = t;
        }
    }

    int insert_b_sort_2(int *a, int n) {
        int t, low, high, mid;
        for (int i = 1; i < n; i++) {
            t = a[i], low = 0, high = i - 1;
            while (low <= high) {
                mid = (low + high) / 2;
                if (t < a[mid])
                    high = mid - 1;
                else
                    low = mid + 1;
            }

            for (int j = i - 1; j >= low; j--)
                a[j + 1] = a[j];
            a[low] = t;
        }
    }


    int shell_sort_2(int *a, int n, int gap = 2) {
        int t, g = n / gap, j;

        while (g > 0) {
            for (int i = g; i < n; i++) {
                t = a[i];
                for (j = i - g; a[j] > t && j >= 0; j -= g) {
                    a[j + g] = a[j];
                }
                a[j + g] = t;
            }
            g /= gap;
        }
    };


    int partition_2(int *a, int low, int high) {
        int i = low, j = high + 1, k = a[low];
        do {
            do i++; while (low < high && a[i] < k);
            do j--; while (low < high && a[j] > k);
            if (i < j) swap(&a[i], &a[j]);
        } while (i < j);

        swap(&a[low], &a[j]);
        return j;
    }

    int quick_sort_2(int *a, int low, int high) {
        if (low < high) {
            int p = partition_2(a, low, high);
            quick_sort_2(a, low, p - 1);
            quick_sort_2(a, p + 1, high);
        }
    }


    int adj_heap_1(int *a, int i, int len) {
        //取出当前’根‘元素
        int t = a[i];
        for (int j = 2 * i + 1; j < len; j = j * 2 + 1) {
            //比较左右节点大小
            if (j + 1 < len && a[j] < a[j + 1])
                j++;
            //子节点   大于（对大顶）/小于（对小顶）  根节点
            if (a[j] > t) {
                swap(&a[i], &a[j]);
                i = j;//将子节点设为当前‘根’节点
            } else
                break;//不需要调整
        }
    }

    int heap_sort_1(int *a, int n) {
        /*
         * 利用完全二叉树的性质，最后一个非叶子节点为 n/2-1
         * 从最后一个非叶子节点开始构造
         */
        for (int i = n / 2 - 1; i >= 0; i--)
            adj_heap_1(a, i, n);

        for (int j = n - 1; j >= 0; j--) {
            //把大顶堆的根元素放到最后形成部分有序序列
            swap(&a[0], &a[j]);
            //剩下的元素重新调整
            adj_heap_1(a, 0, j);
        }

    };

    int merge_1(int *a, int left, int right, int mid) {
        int t[right - left + 1], i = left, j = mid + 1;
        //从左到右复制到临时数组中；
        for (int k = left; k <= right; k++)
            t[k - left] = a[k];
        for (int k = left; k <= right; k++) {
            if (i > mid) {//左边越界处理
                a[k] = t[j - left];
                j++;
            } else if (j > right) {//右边越界处理
                a[k] = t[i - left];
                i++;
            }
                //左右两部分比较大小
            else if (t[i - left] > t[j - left]) {
                //右边的小，补到原数组中，同时右游标后移
                a[k] = t[j - left];
                j++;
            } else {
                //左边的小，左边的元素补到原数组中，同时左游标后移
                a[k] = t[i - left];
                i++;
            }
        }
    }

    /*
     * https://blog.csdn.net/k_koris/article/details/80508543
     */
    int merge_sort_1(int *a, int left, int right) {
        if (left < right) {
            int mid = (left + right) / 2;
            merge_sort_1(a, left, mid);
            merge_sort_1(a, mid + 1, right);
            merge_1(a, left, right, mid);
        }
    }

    int merge_2(int *a, int left, int right, int mid) {
        int t[right - left + 1], i = left, j = mid + 1;

        for (int k = left; k <= right; ++k)
            t[k - left] = a[k];

        for (int k = left; k <= right; k++) {
            if (i > mid) {
                a[k] = t[j - left];
                j++;
            } else if (j > right) {
                a[k] = t[i - left];
                i++;
            } else if (t[i - left] > t[j - left]) {
                a[k] = t[j - left];
                j++;
            } else {
                a[k] = t[i - left];
                i++;
            }
        }
    }

    int merge_sort_2(int *a, int left, int right) {
        if (left < right) {
            int mid = (left + right) / 2;
            merge_sort_2(a, left, mid);
            merge_sort_2(a, mid + 1, right);
            merge_2(a, left, right, mid);
        }
    }


    int adj_heap_2(int *a, int i, int n) {
        int t = a[i];
        for (int j = 2 * i + 1; j < n; j = j * 2 + 1) {
            if (j + 1 < n && a[j] > a[j + 1])
                j++;
            if (a[j] < t) {
                swap(&a[i], &a[j]);
                i = j;
            } else break;
        }
    }

    int heap_sort_2(int *a, int n) {
        for (int i = n / 2 - 1; i >= 0; i--)
            adj_heap_2(a, i, n);

        for (int j = n - 1; j >= 0; j--) {
            swap(&a[j], &a[0]);
            adj_heap_2(a, 0, j);
        }
    }

    void test() {
        ps_int(a, 10);
//        bubble_sort_2(a, 10);
//        insert_sort_2(a, 10);
//        insert_b_sort_2(a, 10);
//        select_sort_2(a, 10);
//        shell_sort_2(a, 10);
//        quick_sort_2(a, 0, 10);
//        merge_sort_2(a, 0, 10 - 1);
        heap_sort_2(a, 10);
        ps_int(a, 10);
    }


}

namespace ds_5_1 {

    void test() {
//        queue_5_1::test();
//        strint_5_1::test();
//        btree_5_1::test();
//        graph_5_1::test();
        sort_5_1::test();
    }
}