#include  <iostream>

using namespace std;

void ps_int(int *, int);

void ps_char(int *, int);

int errCode(string, int);

int swap_(int *a, int *b);

#define SIZES 10
namespace sqlist_5_3 {

    typedef struct {
        int *data;
        int listsize, length;
    } SqList;

    int init(SqList *list) {
        list->data = (int *) malloc(sizeof(int) * SIZES);
        list->length = 0;
        list->listsize = SIZES;
    }

    int insert_1(SqList *list, int i, int e) {
        if (i < 0 || i > list->length + 1)
            return errCode("wrong position", 0);

        if (list->length == list->listsize) {
            list->data = (int *) realloc(list->data, sizeof(int) * SIZES);
            list->listsize += SIZES;
        }
        int *p = &list->data[i];
        for (int *j = &list->data[list->length - 1]; j > p; j++)
            *(j + 1) = *j;
        *p = e;

//        for (int j = list->length; j >= i; --j)
//            list->data[j + 1] = list->data[j];
//        list->data[i] = e;

        list->length++;
    }

    int del_1(SqList *list, int i, int *e) {
        if (i < 0 | i > list->length)
            return errCode("del at wrong position", 0);

        *e = list->data[i];

//        for (int j = i; j < list->length - 1; ++j)
//            list->data[j] = list->data[j + 1];

        for (int *j = &list->data[i]; j < &list->data[list->length - 1]; ++j)
            *j = *(j + 1);

        list->length--;
    }


    /*
     * 线性表元素逆序，要求空间复杂度O(1)
     */
    int reverse(SqList *list) {
        int t;
        for (int i = 0; i < list->length / 2; i++) {
            t = list->data[i];
            list->data[i] = list->data[list->length - i - 1];
            list->data[list->length - i - 1] = t;
        }
    }

    /*
     * 删除所有值为e的元素，时间O(n) 空间O(1)
     */
    int del_same_element(SqList *list, int e) {
        int k = 0;
        for (int i = 0; i < list->length; ++i) {
            if (list->data[i] != e) {
                list->data[k++] = list->data[i];
            }
        }
        list->length = k;
    }

    /*
     * 删除范围内的元素
     */
    int del_rank(SqList *list, int from, int to) {
        if (list->length == 0)
            return errCode("空表", 0);
        if (from > to)
            return errCode("删除范围不合理", 0);

        int k = 0;
        for (int i = 0; i < list->length; i++)
            if (!(list->data[i] > from && list->data[i] < to))
                list->data[k++] = list->data[i];
        list->length = k;
    }

    /*
     *  有序表中去重
     */
    int arr_distinct(SqList *list) {
        int k = 1;

        for (int i = 1; i < list->length; i++)
            if (list->data[k - 1] != list->data[i])
                list->data[k++] = list->data[i];
        list->length = k;
    }

    /*
     * 线性表升序排列，要求用最少时间找到x元素，
     * 找到后与后继交换位置，
     * 找不到则插入x，并保持升序排列
     */
    int ins_(SqList *list, int x) {
        int low = 0, high = list->length - 1, mid;
        while (low <= high) {
            mid = (low + high) / 2;
            if (x > list->data[mid])
                low = mid + 1;
            if (x < list->data[mid]) {
                high = mid - 1;
            }
            if (list->data[mid] == x) {
                swap_(&list->data[mid], &list->data[mid + 1]);
                break;
            }
        }
        if (low > high) {
            for (int i = list->length - 1; i > high; i--)
                list->data[i + 1] = list->data[i];
            list->data[high + 1] = x;
        }
    }

    /*
     * 将数组元素左移 p=2 位
     * 12345  -> 34512
     *time O(n-p)
     * space O(1)
     */
    int offset_(SqList *list, int p) {
//        int t;
        for (int i = 0; i < list->length - p; i++) {
            //计算位移后的位置
            int ni = (i + list->length - p) % list->length;
//            t = list->data[i];
//            list->data[i] = list->data[ni];
//            list->data[ni] = t;
            swap_(&list->data[i], &list->data[ni]);
        }
    }

    /*
     *time  O(p)+O(n-p)+O(p)=O(n)
     * space O(p)
     */
    int offset_1(SqList *list, int p) {
        int a[p];
        for (int i = 0; i < p; i++)
            a[i] = list->data[i];
        for (int j = 0; j < list->length - p; j++)
            list->data[j] = list->data[j + p];
        for (int j = 0; j < p; j++)
            list->data[list->length - p + j] = a[j];
    }

    /*
     * 寻找中位数
     * 升序序列，长度L,第L/2(向上取整)的元素为中位数
     * 两个序列的中位数为两个序列升序组合在一起的中位数
     */
    int mid(SqList *a, SqList *b) {
        int c[a->length + b->length];
        int i = 0, j = 0, k = 0;
        while (i < a->length && j < b->length) {
            if (a->data[i] < b->data[j]) {
                c[k++] = a->data[i];
                i++;
            } else {
                c[k++] = b->data[j];
                j++;
            }
        }
        if (i != a->length - 1) {
            for (int q = i; q < a->length; q++)
                c[k++] = a->data[q];
        }
        if (j != b->length - 1) {
            for (int q = j; q < b->length; q++)
                c[k++] = b->data[q];
        }
        ps_int(c, a->length + b->length);
        std::cout << (a->length + b->length + 1) / 2 << std::endl;
        std::cout << c[(a->length + b->length + 1) / 2 - 1] << std::endl;
    }

    void test() {
        SqList list, list2;
        init(&list);
        init(&list2);
//        int a[] = {21, 15, 7, 2, 13, 6, 8, 4, 45, 1};
//        int a[] = {1, 2, 3, 4, 6, 7, 8, 11};
        int a[] = {11, 13, 15, 17, 19};
//        int a2[] = {1, 2, 3, 3, 4, 5, 6, 6, 7, 7};
        int a2[] = {2, 4, 6, 8, 20};
        list.data = a, list.length = 5;
        list2.data = a2, list2.length = 5;

        ps_int(list.data, list.length);
//        ps_int(list2.data, list2.length);
//        del_same_element(&list, 13);
//        del_rank(&list, 1, 10);
//        ins_(&list, 5);
//        offset_(&list, 2);
        mid(&list, &list2);
//        offset_1(&list, 2);
//        arr_distinct(&list2);
//        ps_int(list2.data, list2.length);
        ps_int(list.data, list.length);
    }

    void test_1() {
        SqList list;
        init(&list);
        ps_int(list.data, list.length);
        for (int i = 1; i <= 8; ++i)
            insert_1(&list, i - 1, i);

        reverse(&list);
        ps_int(list.data, list.length);
    }
}

namespace linklist_5_3 {
    typedef struct node {
        int data;
        node *next;
    } node, *LinkList;
#define  newNode (LinkList) malloc(sizeof(node))

    int ps_link_list(LinkList list) {
        if (list == nullptr)
            return errCode("empty linklist", 0);
        LinkList p = list;
        while (p != nullptr) {
            printf("%d\t", p->data);
            p = p->next;
        }
        puts("");
    }

    LinkList create(int *a, int code = 1, int n = 10) {
        LinkList list = nullptr;
        LinkList p, r;
        for (int i = 0; i < n; i++) {
            p = newNode;
//            scanf("%d", &p->data);
            if (code == 1) {
                p->data = 2 * a[i] + 1;
            } else if (code == 2) {
                p->data = 2 * a[i];
            } else if (code == 3)
                p->data = a[i];

            p->next = nullptr;
            if (list == nullptr)
                list = p;
            else {
                r->next = p;
            };
            r = p;
        }
        return list;
    }

    LinkList find(LinkList list, int e) {
        LinkList p = list;
        while (p != nullptr && p->data != e)
            p = p->next;
        return p;
    }

    int insert(LinkList &list, int i, int e) {
        LinkList p = list, s;
        s = newNode;
        s->data = e;
        while (p != nullptr && i-- > 1)
            p = p->next;

        if (p != nullptr) {
            /*
             * 插入到第i个元素后面直接插入即可，
             * 若插到第i个元素前面，只需交换下两个节点的数据域即可，不需要改变指针
             */
            s->next = p->next;
            p->next = s;
//            swap_(&s->data, &p->data);
        } else
            return errCode("插入位置有误", 0);
    }

    int del_(LinkList &list, int i, int *e) {
        if (list == nullptr)
            return errCode("empty del fail", 0);
        LinkList p = list, r;
        while (p != nullptr && i-- > 1)
            p = p->next;

        if (p != nullptr) {
            r = p->next;
            *e = r->data;
            p->next = r->next;
            free(r);
        } else
            return errCode("del fail,wrong position", 0);
    }

    typedef struct dnode {
        int data;
        dnode *prior, *next;
        int freq;
    } dnode, *DLinkList;

    int d_insert_(DLinkList s, DLinkList q) {
        /*
         * 把s插入到q的后面
         */
        s->next = q->next;
        s->prior = q;
        q->next->prior = s;
        q->next = s;
    }

    int d_del_(DLinkList q, DLinkList w) {
        /*
         * 删除q的后继w
         */
        q->next = w->next;
        w->next->prior = q;
        free(w);
    }


    /*
     * 递归删除单链表中相同元素
     */
    int del_same_element(LinkList &a, int e) {
        if (a == nullptr)
            return 0;
        if (a->data == e) {
            LinkList p = a;
            a = a->next;
            free(p);
            del_same_element(a, e);
        } else
            del_same_element(a->next, e);
    }

    /*
     * 带头单链表删除所有值为x的节点，值为x的节点不唯一，
     */
    int del_same_(LinkList &a, int x) {
        LinkList p = a, q = a->next, w;
        while (q != nullptr) {
            if (q->data == x) {
                w = q;
                q = q->next;
                p->next = q;
                free(w);
            } else {
                p = q;
                q = q->next;
            }
        }
    }

    /*
     * 带头单链表，反序输出
     */
    int reverse_order(LinkList &a) {
        if (a->next != nullptr)
            reverse_order(a->next);
        printf("%d\t", a->data);
    }

    /*
     * 带头单链中删除最小值
     */
    int del_min_(LinkList &a) {
        LinkList p = a, q = a->next;
        int min = INTMAX_MAX;
        while (q != nullptr) {
            if (min < q->data)
                min = q->data;
            p = q;
            q = q->next;
        }
        p->next = q->next;
        free(q);
    }

    /*
     * 带头单链逆转
     * space O(1)
     */
    int reverse(LinkList &a) {
        LinkList q, w;
        q = a->next;
        a->next = nullptr;
        while (q != nullptr) {
            w = q->next;
            q->next = a->next;
            a->next = q;
            q = w;
        }
    }

    /*
     * 升序排列
     */
    int sort_asc(LinkList &L) {
        LinkList p = L->next, pre;
        LinkList r = p->next;
        p->next = nullptr;
        p = r;
        while (p != nullptr) {
            r = p->next;
            pre = L;
            while (pre->next != nullptr && pre->next->data < p->data)
                pre = pre->next;
            p->next = pre->next;
            pre->next = p;
            p = r;
        }
    }

    int sort_desc(LinkList &a) {
        LinkList p, q, r;
        p = a->next;
        while (p != nullptr) {
            q = p->next;
            while (q != nullptr) {
                if (p->data < q->data)
                    swap_(&p->data, &q->data);
                q = q->next;
            }
            p = p->next;
        }
    }

    /*
     * 删除范围内的节点
     */
    int del_rank_(LinkList &a, int f, int t) {
        if (f > t)
            return 0;
        LinkList p = a->next, r = a;
        while (p != nullptr) {
            if (p->data > f && p->data < t) {
                r->next = p->next;
                free(p);
                p = r->next;
            } else {
                r = p;
                p = p->next;
            }
        }
    }


    /*
     * 按递增顺序输出，并释放节点
     */
    int select_order(LinkList &a) {
        LinkList p, q;
        p = a->next;
        while (p != nullptr) {
            q = p->next;
            while (q != nullptr) {
                if (p->data < q->data)
                    swap_(&p->data, &q->data);
                q = q->next;
            }
            printf("%d\t", p->data);
            q = p->next;
//            free(p);
            p = q;
            //            p = p->next;
        }
    }


    LinkList create_head(int *a, int n = 10) {
        LinkList list = newNode, p;
        list->next = nullptr;
        for (int i = 0; i < n; i++) {
            p = newNode;
            p->data = a[i];
            p->next = list->next;
            list->next = p;
        }
        return list;
    }

    int create_tail(LinkList &list, int *a, int n = 10) {
        LinkList q = newNode, p;
        q->next = nullptr;
        for (int i = 0; i < n; i++) {
            p = newNode;
            p->data = a[i];
            q->next = p;
            q = p;
        }
        ps_link_list(q);
    }

    LinkList split_3(LinkList &a) {
        LinkList b = newNode;
        b->next = NULL;  //B 表的初始化
        LinkList aa = a, bb = b, p = a->next, q;
        a->next = nullptr;
        while (p != nullptr) {

            if (p->data % 2 == 0) {
                bb->next = p;
                bb = p;
            } else {
                aa->next = p;
                aa = p;
            }
            p = p->next;
        }
        aa->next = nullptr;
        bb->next = nullptr;
        return b;
    }

    /*
     * 升序链表中去重
     */
    int distinct_(LinkList &a) {
        LinkList p = a->next, q = a, w;
        while (p != nullptr) {
            if (q->data == p->data) {
                w = p;
                p = p->next;
                q->next = p;
                free(w);
            } else {
                q = p;
                p = p->next;
            }
        }
    }

    /*
     * 两个有序链表合并，合并后倒序
     */
    int merge_(LinkList &a, LinkList &b) {
        LinkList aa = a, bb = b, p;
        a->next = nullptr;
        while (aa != nullptr && bb != nullptr) {
            if (aa->data <= bb->data) {
                p = aa->next;
                aa->next = a->next;
                a->next = aa;
                aa = p;
            } else {
                p = bb->next;
                bb->next = a->next;
                a->next = bb;
                bb = p;
            }
        }

        if (aa != nullptr)
            bb = aa;

        while (bb != nullptr) {
            p = bb->next;
            bb->next = a->next;
            a->next = bb;
            bb = p;
        }
        ps_link_list(a);
        free(b);
    }

    /*
     * 带头有序链表，提出公共本分到c链表
     */
    int get_common(LinkList &a, LinkList &b) {
        LinkList aa = a->next, bb = b->next, c = newNode, p, cc;
        c->next = nullptr;
        cc = c;
        while (aa != nullptr && bb != nullptr) {
            if (aa->data == bb->data) {
                p = newNode;
                p->data = aa->data;
                cc->next = p;
                cc = p;

//                p->next = cc->next;
//                cc->next = p;
                aa = aa->next;
                bb = bb->next;
            } else if (aa->data < bb->data) {
                aa = aa->next;
            } else {
                bb = bb->next;
            }
        }
        ps_link_list(c);
    }

    int get_common_arr(int *a, int n1, int *b, int n2) {
        int i = 0, j = 0;
        LinkList list = newNode, p, q;
        list->next = nullptr;
        q = list;
        while (i < n1 && j < n2) {
            if (a[i] == b[j]) {
                p = newNode;
                p->data = a[i];
//                q->next = p;
//                q = p;
                p->next = q->next;
                q->next = p;
                i++;
                j++;
            } else if (a[i] < b[j]) {
                i++;
            } else {
                j++;
            }
        }
        ps_link_list(list);
        ps_link_list(q);
    }

    /*
     *  a b 两个链表元素递增，求交集放入a
     */
    int get_common_2(LinkList &a, LinkList &b) {
        LinkList aa = a->next, bb = b->next, p, cc = a;
        while (aa != nullptr && bb != nullptr) {
            if (aa->data == bb->data) {
                cc->next = aa;
                cc = aa;
                aa = aa->next;
                p = bb;
                bb = bb->next;
                free(p);
            } else if (aa->data < bb->data) {
                p = aa;
                aa = aa->next;
                free(p);
            } else {
                p = bb;
                bb = bb->next;
                free(p);
            }
        }

        while (aa != nullptr) {
            p = aa;
            aa = aa->next;
            free(p);
        }
        while (bb != nullptr) {
            p = bb;
            bb = bb->next;
            free(p);
        }
        cc->next = nullptr;
        free(b);

        ps_link_list(a->next);
    }


    /*
     * 判断双循环链表是否对称
     */
    int symmetry(DLinkList &a) {
        DLinkList f = a->prior, r = a->next;
        while (f != r && r->next != f) {
            if (f->data == r->data) {
                f = f->next;
                r = r->prior;
            } else {
                return 0;
            }
        }
        return 1;
    }

    /*
     * 两个循环单链表，将b链接到a后，保持循环 单链表
     */
    int merge_c_1(LinkList &a, LinkList &b) {
        LinkList aa = a, bb = b;
        while (aa->next != a)
            aa = aa->next;

        while (bb->next != b)
            bb = bb->next;
        aa->next = b;
        bb->next = a;
    }

    /*
     * 带头循环单链表，找出最小值，输出后删除，重复执行至链表为空，再删除头节点
     */
    int del_min_1(LinkList &L) {
        LinkList p, pre, minp, minpre;
        while (L->next != L) {
            p = L->next;
            pre = L;
            minp = p;
            minpre = pre; //minp 指向最小值结点
            while (p != L) {
                if (p->data < minp->data) {
                    minp = p;
                    minpre = pre;
                }
                pre = p;
                p = p->next;
            }
            printf("%d\t", minp->data);
            minpre->next = minp->next;
            free(minp);
        }
        free(L);
    }

    /*
     *
     */
    DLinkList locate_d_1(DLinkList &a, int x) {
        DLinkList p = a->next, q;
        while (p != nullptr && p->data != x)
            p = p->next;

        if (p == nullptr)
            return 0;
        else {
            p->freq++;
            p->next->prior = p->prior;
            p->prior->next = p->next;
            q = p->prior;
            while (q != a && q->freq <= p->freq)
                q = q->prior;

            p->next = q->prior;
            q->next->prior = p;
            p->prior = q;
            q->next = p;
        }
        return p;
    }

    /*
     * 带头单链表中查找倒数第 i 个元素
     */
    int locate_2(LinkList &a, int i) {
        LinkList p = a->next, q = a->next;
        int c = 0;
        while (p != nullptr) {
            if (c < i)
                c++;
            else
                q = q->next;
            p = p->next;
        }
        if (c < i)
            return errCode("没有找到", 0);
        else {
            return errCode("找到了", q->data);
        }
    }

    /*
     * 找到两个链表的公共部分的节点
     */
    int len(LinkList &a) {
        LinkList p = a;
        int len = 0;
        while (p != nullptr) {
            len++;
            p = p->next;
        }
        return len;
    }

    /*
     * 找相同后缀的节点
     */
    int get_common_suffix(LinkList &a, LinkList &b) {
        int len_a = len(a), len_b = len(b);
        LinkList p, q;
        for (p = a; len_a > len_b; len_a--)
            p = p->next;
        for (q = b; len_b > len_a; len_b--)
            q = q->next;

        while (p->next != nullptr && q->next->data != p->next->data) {
            p = p->next;
            q = q->next;
        }
        ps_link_list(p->next);
    }

    /*
     * 链表去重，对于绝对值相同的只保留第一次出现的位置
     */
    int distinct_abs_(LinkList &a, int n) {
        LinkList p = a, q;
        int aa[n + 1], m;
        for (int i = 0; i < n + 1; i++)
            aa[i] = 0;

        ps_link_list(a);

        while (p->next != nullptr) {
            m = p->next->data > 0 ? p->next->data : -p->next->data;
            if (aa[m] == 0) {
                aa[m] = 1;
                p = p->next;
            } else {
                q = p->next;
                p->next = q->next;
                free(q);
            }
            ps_int(aa, 11);
        }
        free(aa);
        ps_link_list(a);
    }


    void test() {
        int aa[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
        int aa2[] = {7, 10, 10, 21, 30, 42, 42, 42, 51, 70};
        int a3[] = {1, 2, 3, 4, 5, 7, 9};
        int a4[] = {1, 2, 2, -7, 9, 5, 7, 9};
        LinkList list = create(a4, 10);
        LinkList list2 = create(a3, 3, 7);
        LinkList list3 = create(a4, 3, 8);
        LinkList a = newNode;
        a->next = list2;
        LinkList b = newNode;
        b->next = list3;
//        ps_link_list(a);
//        get_common_suffix(a, b);
        distinct_abs_(b, 10);
        //        LinkList b = split(a);
//        LinkList b = split_3(a);
//        ps_link_list(b);
//        distinct_(list);
//        merge_(list2, list3);
//        get_common_arr(a3, 7, a4, 10);
//        get_common_2(a, b);
//        del_min_1(a);
//        ps_link_list(a);
//        std::cout << locate_2(a, 5) << std::endl;
    }

    void test_1() {
        LinkList list;
        auto a = newNode;
        a->data = 0;
        a->next = list;
        ps_link_list(list);
//        insert(list, 3, 12);
//        int e;
//        del_(list, 4, &e);
//        reverse_order(list);
//        reverse(a);
//        ps_link_list(a);
//        sort_asc(a);
//        sort_desc(a);
//        del_rank_(a, 2, 8);
        select_order(a);
        ps_link_list(a);
    }
}


namespace stack_5_3 {
    typedef struct {
        int *data;
        int top;
        int len;
        int ssize;
    } sq_stack;

    int init(sq_stack &s) {
        s.data = (int *) malloc(sizeof(int) * SIZES);
        s.len = 0;
        s.top = -1;
        s.ssize = SIZES;
    }

    int isEmpty(sq_stack &s) {
        return s.top == -1;
    }

    int push(sq_stack &s, int e) {
        if (s.len == s.ssize) {
            s.data = (int *) realloc(s.data, sizeof(int) * s.ssize + SIZES);
            s.ssize += SIZES;
        }
        s.data[++s.top] = e;
        s.len++;
        return 1;
    }

    int pop(sq_stack &s, int &e) {
        if (s.top == -1)
            return errCode("空", 0);
        e = s.data[s.top--];
        s.len--;
        return 1;
    }

    int getTop(sq_stack &s, int &e) {
        if (s.top == -1)
            return errCode("空", 0);
        e = s.data[s.top];
        return 1;
    }

    typedef struct node {
        int data;
        node *next;
    } node, stack;

    int test_stack() {
        sq_stack s;
        init(s);
        for (int i = 0; i < 6; i++) {
            s.data[++s.top] = i;
        }
        for (int j = 0; j < 6; j++) {
            printf("%d \t", s.data[s.top--]);
        }

    }

    /*
     * 判断栈中n个字符是否中心对称
     */
    int semmetry(linklist_5_3::LinkList &list, int n) {
        int a = n / 2, e;
        sq_stack s;
        init(s);
        linklist_5_3::LinkList p = list->next;
        while (p != nullptr && a > 0) {
            push(s, p->data);
            p = p->next;
            a--;
        }
        if (n % 2 != 0)
            p = p->next;

        pop(s, e);
        while (p != nullptr && e == p->data) {
            p = p->next;
            pop(s, e);
        }

        if (s.len == 0 && p == nullptr)
            return errCode("对称", 1);
        else
            return errCode("not 对称", 0);
    }

    void test() {
        linklist_5_3::LinkList list;
        int aa[] = {1, 2, 3, 2, 1};
        list = linklist_5_3::create(aa, 3, 5);
        linklist_5_3::LinkList a = (linklist_5_3::LinkList) malloc(sizeof(linklist_5_3::node));
        a->next = list;
        semmetry(a, 5);

    }
}

namespace queue_5_3 {
    typedef struct {
        int *data;
        int front, rear;
        int ssize;
        int len;
    } sq_queue;

    int init_sq(sq_queue &q) {
        q.data = (int *) malloc(sizeof(int) * SIZES);
        q.len = 0;
        q.ssize = SIZES;
        q.front = -1;
        q.rear = -1;
    }

    /*
     * 循环队列中
     * 头指针位置： f=(f+1)%size;
     *  尾指针位置 r=(r+1)%size;
     *  长度：（r-f+size）%size;
     *  空队
     *       1、f==r
     *       2、队列结构中增加长度字段，则q.size==0可判定，
     *  满队
     *      1、f=(r+1)%size
     *  元素个数：
     *      1、（r-f+size）%size
     *      2、队列中增加长度字段
     */

    int init_cq(sq_queue &q) {
        q.front = 0;
        q.rear = 0;
    }

    int isEmpty(sq_queue &q) {
        return q.front == q.rear;
    }

    int enQueue(sq_queue &q, int e) {
        if (q.front == (q.rear + 1) % q.ssize)
            return errCode("满队", 0);
        q.data[q.rear] = e;
        q.rear = (q.rear + 1) % q.ssize;
        return 1;
    }

    int deQueue(sq_queue &q, int &e) {
        if (q.front == q.rear)
            return errCode("空队", 0);

        e = q.data[q.front];
        q.front = (q.front + 1) % q.ssize;
        return 1;
    }

    typedef struct qnode {
        int data;
        struct qnode *next;
    } qnode;
    typedef struct {
        qnode *front, *rear;
    } *queue;

    int init(queue &q) {
        qnode *qq = (qnode *) malloc(sizeof(qnode));
        q->front = qq;
        q->rear = qq;
    }

    int isEmpty(queue &q) {
        return q->front == q->rear;
    }

    int enQueue(queue &q, int e) {
        qnode *qq = (qnode *) malloc(sizeof(qnode));
        qq->data = e;
        q->rear->next = qq;
        q->rear = qq;
    }

    int deQueue(queue &q, int &e) {
        if (q->front == q->rear)
            return errCode("空队", 0);
        qnode *qq = q->front;
        e = qq->data;
        q->front = qq->next;
        if (q->rear == qq)
            q->rear = q->front;
        free(qq);
    }

    int bracket_match(char *c) {
        int i = 0;
        int s;
        stack_5_3::sq_stack stack;
        stack_5_3::init(stack);

        while (c[i] != '\0') {
            switch (c[i]) {
                case '(':
                    stack_5_3::push(stack, '(');
                    break;
                case '[':
                    stack_5_3::push(stack, '[');
                    break;
                case '{':
                    stack_5_3::push(stack, ']');
                    break;
                case ')':
                    stack_5_3::pop(stack, s);
                    if (s != '(')
                        return 0;
                case ']':
                    stack_5_3::pop(stack, s);
                    if (s != '[')
                        return 0;
                case '}':
                    stack_5_3::pop(stack, s);
                    if (s != '{')
                        return 0;
            }
            i++;
        }
        return stack_5_3::isEmpty(stack);
    }

    void test() {
        /*
         *   a/b+(c*d-e*f)/g
         *   ab/cd*ef*-g/+
         */
    }
}

namespace tree_5_3 {
#define   newNode (Btree)malloc(sizeof(node))
    typedef struct node {
        struct node *left, *right;
        int data, rtag, ltag;
    } node, *Btree;

    Btree tree() {
        Btree a, b, c, d, e, f, g, h, i, j, k;
        a = newNode;
        a->data = 'A';
        b = newNode;
        b->data = 'B';
        c = newNode;
        c->data = 'C';
        d = newNode;
        d->data = 'D';
        e = newNode;
        e->data = 'E';
        f = newNode;
        f->data = 'F';
        g = newNode;
        g->data = 'G';
        h = newNode;
        h->data = 'H';
        i = newNode;
        i->data = 'I';
        j = newNode;
        j->data = 'J';
        k = newNode;
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


    int preOrder(Btree t) {
        Btree p = t, stack[22];
        int top = -1;
        do {
            while (p != nullptr) {
                stack[++top] = p;
                p = p->left;
            }
            p = stack[top--];
            printf("%c\t", p->data);
            p = p->right;
        } while (top != -1 || p != nullptr);
        puts("");
    }


    int postOrder(Btree t) {
        Btree p = t, s[22];
        int a = -1, fs[22], f;
        do {
            while (p != nullptr) {
                s[++a] = p;
                fs[a] = 0;
                p = p->left;
            }
            p = s[a];
            f = fs[a--];
            if (f == 0) {
                f = 1;
                s[++a] = p;
                fs[a] = 1;
                p = p->right;
            } else {
                printf("%c\t", p->data);
                p = nullptr;
            }
        } while (a != -1 || p != nullptr);
        puts("");
    }

    int layorOrder(Btree t) {
        Btree p = t, q[22];
        int f, r;
        if (p != nullptr) {
            q[0] = p;
            f = -1;
            r = 0;
            while (f < r) {
                p = q[++f];
                printf("%c\t", p->data);
                if (p->left != nullptr)
                    q[++r] = p->left;
                if (p->right != nullptr)
                    q[++r] = p->right;
            }
        }
        std::cout << "" << std::endl;
    }

    int toThread(Btree t, Btree pre) {
        if (t != nullptr) {
            toThread(t->left, pre);
            if (t->left == nullptr) {
                t->left = pre;
                t->ltag = 1;
            }
            if (pre != nullptr && pre->right == nullptr) {
                pre->right = t;
                pre->rtag = 1;
            }
            pre = t;
            toThread(t->right, pre);
        }
    }

    int threadTree(Btree t) {
        Btree pre = nullptr;
        if (t != nullptr) {
            toThread(t, pre);
            pre->left = nullptr;
            t->rtag = 1;
        }
    }

    int preOrderTraverse(Btree t) {
        if (t != nullptr) {
            printf("%c\t", t->data);
            preOrderTraverse(t->left);
            preOrderTraverse(t->right);
        }
    }

    int inOrderTraverse(Btree t) {
        if (t != nullptr) {
            inOrderTraverse(t->left);
            printf("%c\t", t->data);
            inOrderTraverse(t->right);
        }
    }

    int postOrderTraverse(Btree t) {
        if (t != nullptr) {
            postOrderTraverse(t->left);
            postOrderTraverse(t->right);
            printf("%c\t", t->data);
        }
    }


    Btree search_(Btree t, int e) {
        if (t != nullptr) {
            if (t->data == e)
                return t;
            if (t->data > e)
                return search_(t->left, e);
            if (t->data < e)
                return search_(t->right, e);
        }
        return nullptr;
    }

    Btree search_2(Btree t, int e) {
        Btree p = t;
        while (p != nullptr && p->data != e) {
            if (e < p->data)
                p = p->left;
            else
                p = p->right;
        }
        return p;
    }

    int insert(Btree t, int e) {
        if (t == nullptr) {
            t = newNode;
            t->data = e;
            t->right = nullptr;
            t->left = nullptr;
            return 1;
        } else {
            if (e < t->data) {
                return insert(t->left, e);
            } else {
                return insert(t->right, e);
            }
        }
    }

    int insert_(Btree t, int e) {
        Btree p = t, q = newNode;
        q->data = e;
        q->left = nullptr;
        q->right = nullptr;
        while (1) {
            if (e < p->data) {
                if (p->left != nullptr)
                    p = p->left;
                else {
                    p->left = q;
                    break;
                }
            } else {
                if (p->right != nullptr)
                    p = p->right;
                else {
                    p->right = q;
                    break;
                }
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

    int del__(Btree p) {
        Btree q, s;
        if (p->left == nullptr) {
            q = p;
            p = p->right;
            free(q);
        } else if (q->right == nullptr) {
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

    int del(Btree t, int e) {
        if (t == nullptr)
            return 0;
        if (t->data == e)
            return del_(t);
        else if (e < t->data)
            return del(t->left, e);
        else
            return del(t->right, e);
    }


    /*
     * pre  abdehcfimgjkL
     * in   dbheaimfcgkLj
     * post
     *
     *34 23 15 98 115 28 107
     *
     *
     *
     */
    void test() {
        Btree t = tree();
//        preOrder(t);
        preOrderTraverse(t);
        puts("");
        inOrderTraverse(t);
        puts("");
        postOrderTraverse(t);
        puts("");
//        postOrder(t);
//        layorOrder(t);

    }
}
namespace grapg_5_3 {

    typedef struct tnode {
        int data;
        struct tnode *left, *right;
    } tnode, *Btree;

    typedef struct {
        int arc[SIZES][SIZES];
        int vexs[SIZES];
        int vnum, anum;
    } m_graph;


    typedef struct enode {
        int adjvex;
        enode *next;
    } enode;

    typedef struct vnode {
        int data;
        enode *edge;
    } vnode;
    typedef struct {
        vnode vexs[SIZES];
        int anum, vnum;
    } graph;

    int visited[SIZES];

    int m_bfs(m_graph g, int v) {
        visited[v] = 1;
        //visit;
        int q[g.vnum];
        int f = -1, r = 0;
        for (int i = 0; i < g.vnum; i++) {
            if (visited[i] == 0) {
                visited[i] = 1;
                q[r++] = i;
                while (f < r) {
                    i = q[++f];
                    for (int j = 0; j < g.vnum; j++) {
                        if (g.arc[i][j] == 1 && visited[j] == 0) {
                            visited[j] = 1;
                            //visit
                            q[r++] = j;
                        }
                    }
                }
            }
        }
    }

/*
    int m_bfs_(m_graph g) {
        for (int i = 0; i < g.vnum; i++)
            visited[i] = 0;
        Queue q;
        InitQueue(&q);
        for (int j = 0; j < g.vnum; j++) {
            if (visited[j] == 0) {
                visited[j] = 1;
                visit(j);
                EnQueue(&q, j);
                while (!isEmpty(Q)) {
                    DeQueue(&q, &j);
                    for (int i = 0; i < g.vnum; i++) {
                        if (g.arc[j][i] == 1 && visited[i] == 0) {
                            visited[i]==1;
                            visit(i);
                            EnQueue(&q,i);
                        }
                    }
                }
            }
        }
    }
*/

    int D[SIZES];

/*
    //广度优先遍历 求单源最短路径
    int bfs_min_distance(m_graph g, int v) {
        for (int i = 0; i < g.vnum; i++)
            D[i] = -1;
        visited[v] = 1;
        D[v] = 0;
        EnQueue(Q, v);
        while (!isEmpty(Q)) {
            DeQueue(Q, v);
            for (int i = 0; i < g.vnum; i++) {
                if (g.arc[v][i] == 1 && visited[i] == 0) {
                    visited[i]=1;
                    D[i]=D[v]+1;
                    EuQueue(Q,i);
                }
            }
        }
    }
*/

    int m_dfs(m_graph g, int v) {
        visited[v] = 1;
        //visit
        for (int i = 0; i < g.vnum; i++)
            if (visited[i] == 0)
                m_dfs(g, i);
    }

    int m_dfs_traverse(m_graph &g) {
        for (int i = 0; i < g.vnum; i++)
            visited[i] = 0;
        for (int j = 0; j < g.vnum; j++)
            if (visited[j] == 0)
                m_dfs(g, j);

    }

    int dfs(graph g, int v) {
        visited[v] = 1;
        //visit;
        enode *e = g.vexs[v].edge;
        while (e != nullptr) {
            if (visited[e->adjvex] == 0)
                dfs(g, e->adjvex);
            e = e->next;
        }
    }

/*
    int bfs(graph g) {
        for (int i = 0; i < g.vnum; i++)
            visited[i] = 0;
        enode *e;
        for (int j = 0; j < g.vnum; j++) {
            if (visited[j] == 0) {
                visited[j] = 1;
                //visit
                EnQueue(Q, j);
                while (!isEmpty(Q)) {
                    DeQueue(Q, j);
                    e = g.vexs[j].edge;
                    while (e != nullptr) {
                        if (visited[e->adjvex] == 0) {
                            visited[e->adjvex] = 1;
                            visit(e->adjvex);
                            EnQueue(Q, e->adjvex);
                        }
                        e = e->next;
                    }

                }
            }
        }
    }
*/



    int prim(m_graph g) {
        int min, j, k;;
        int adjvex[SIZES];//保存相关顶点下标
        int lowcost[SIZES];//保存相关顶点的权值
        lowcost[0] = 0;
        adjvex[0] = 0;

        for (int i = 1; i < g.vnum; i++) {
            lowcost[i] = g.arc[0][i];//与v0顶点有关的权值存入数组
            adjvex[i] = 0;
        }
        for (int i = 1; i < g.vnum; i++) {
            min = 9999999999;
            j = 1, k = 0;
            while (j < g.vnum) {
                if (lowcost[j] != 0 && lowcost[j] < min) {
                    min = lowcost[j];
                    k = j; //保存当前最小值
                }
                j++;
            }

            printf("%d %d", adjvex[k], k);//打印当前顶点中权值最小边
            lowcost[k] = 0;//将当前顶点的权值设为0，表示已经访问过
            for (int i = 1; i < g.vnum; i++) {
                if (lowcost[i] != 0 && g.arc[k][i] < lowcost[i]) {
                    lowcost[i] = g.arc[k][i];
                    adjvex[i] = k;
                }
            }
        }
    }

    typedef struct {
        int begin;
        int end;
        int weight;
    } Edge;

    //查找连线顶点的尾部下标
    int find(int *parent, int f) {
        while (parent[f] > 0)
            f = parent[f];
        return f;
    }

    int kruskal(m_graph g) {
        Edge edges[g.vnum];//边集数组
        int parent[g.vnum];//用于判断是否形成回路
        for (int i = 0; i < g.vnum; i++)
            parent[i] = 0;

        int m, n;
        for (int j = 0; j < g.anum; j++) {//循环边
            m = find(parent, edges[j].begin);
            n = find(parent, edges[j].end);
            if (m != n) {//如果m!=n， 说明此边没有与现有的边生成回路
                parent[n] = m;//把此边的尾顶点放入下标为起点的parent中，表示此点已在生成树的集合中
                printf("%d %d %d", edges[j].begin, edges[j].end, edges[j].weight);
            }
        }
    }


    int prim_3(m_graph g) {
        int adj[g.vnum], dis[g.vnum], min, j, k;
        adj[0] = 0;
        dis[0] = 0;
        for (int i = 1; i < g.vnum; i++) {
            dis[i] = g.arc[0][i];
            adj[i] = 0;
        }

        for (int i = 0; i < g.vnum; i++) {
            j = 1;
            k = 0;
            min = INTMAX_MAX;
            while (j < g.vnum) {
                if (dis[j] == 0 && dis[j] < min) {
                    k = j;
                    min = dis[j];
                }
                j++;
            }
            //do sth for adj[k]
            dis[k] = 0;
            for (int j = 1; j < g.vnum; j++) {
                if (dis[j] != 0 && g.arc[k][j] < dis[j]) {
                    dis[j] = g.arc[k][j];
                    adj[j] = k;
                }
            }
        }
    }


    int prim_2(m_graph g) {
        int adjvex[g.vnum], dis[g.vnum], min, j, k;
        adjvex[0] = 0;
        dis[0] = 0;
        for (int i = 1; i < g.vnum; i++) {
            adjvex[i] = 0;
            dis[i] = g.arc[0][i];
        }
        for (int i = 1; i < g.vnum; i++) {
            min = INTMAX_MAX, j = 1, k = 0;
            while (j < g.vnum) {
                if (dis[j] != 0 && dis[j] < min) {
                    min = dis[j];
                    k = j;
                }
                j++;
                //do sth to adjvex[k]
                dis[k] = 0;
                for (int i = 1; i < g.vnum; i++) {
                    if (dis[i] != 0 && g.arc[k][i] < dis[i]) {
                        dis[i] = g.arc[k][i];
                        adjvex[i] = k;
                    }
                }
            }
        }
    }

    int dijkstra_2(m_graph g, int v) {
        int min, k, ver[g.vnum], dis[g.vnum], flag[g.vnum];
        for (int i = 0; i < g.vnum; i++) {
            ver[i] = 0;
            dis[i] = g.arc[v][i];
            flag[i] = 0;
        }
        flag[0] = 1;
        dis[0] = 0;
        for (int j = 1; j < g.vnum; j++) {
            min = INTMAX_MAX;
            for (int w = 0; w < g.vnum; w++) {
                if (flag[w] == 0 && dis[w] < min) {
                    min = dis[w];
                    k = w;
                }
            }
            flag[k] = 1;
            for (int w = 0; w < g.vnum; w++) {
                if (flag[w] == 0 && min + g.arc[k][w] < dis[w]) {
                    dis[w] = min + g.arc[k][w];
                    ver[w] = k;
                }
            }
        }
    }


    int dijkstra_1(m_graph g, int v) {
        int min, k;
        int ver[g.vnum];
        int dis[g.vnum];
        int flag[g.vnum];
        for (int i = 0; i < g.vnum; i++) {
            dis[i] = g.arc[v][i];
            flag[i] = 0;
            ver[i] = 0;
        }
        flag[0] = 1;//自己一个点不用求
        dis[0] = 0;//自己到自己距离0
        for (int i = 1; i < g.vnum; i++) {
            min = INTMAX_MAX;
            for (int j = 0; j < g.vnum; j++) {
                if (flag[j] == 0 && dis[j] < min) {
                    min = dis[j];
                    k = j;
                }
            }
            flag[k] = 1;
            for (int j = 0; j < g.vnum; j++) {
                if (flag[j] == 0 && min + g.arc[k][j] < dis[j]) {
                    dis[j] = min + g.arc[k][j];
                    ver[j] = k;
                }
            }
        }
    }

    /*
     *
     *
     *
     *
     *
     *
     *
     *
     *
     *
     *
     */
    void test() {

    }
}
namespace search_5_3 {
    /*
     *  1
     *  2
     *  4
     *  8
     *  16
     *  32
     *  64
     *  128
     *  256
     *  512
     *  1024
     *  2048  12
     *  4096
     *
     *
     */

    int s(char *s, char *t) {
        int i = 1, j = 1;
        while (i < s[0] && j < t[0]) {
            if (s[i] == t[j]) {
                i++;
                j++;
            } else {
                i = i - j + 2;
                j = 1;
            }
        };
        if (j > t[0])
            return i - t[0];
        return 0;
    }

    int next(char *t, int *a) {
        int i = 1, j = 0;
        a[1] = 0;
        while (i < t[0]) {
            if (j == 0 || t[i] == t[j]) {
                i++;
                j++;
                a[i] = j;
            } else {
                j = a[j];
            }
        }
    }

    int nextval(char *t, int *a) {
        int i = 1, j = 0;
        a[1] = 0;
        while (i < t[0]) {
            if (j == 0 || t[i] == t[j]) {
                i++;
                j++;
                if (t[i] != t[j]) {
                    a[i] = j;
                } else {
                    a[i] = a[j];
                }
            } else {
                j = a[j];
            }
        }
    }

    int index(char *s, char *t, int p = 0) {
        int i = p, j = 1;
        int *a;
        next(t, a);
        while (i < s[0] && j < t[0]) {
            if (s[i] == t[j]) {
                i++, j++;
            } else {
                j = a[j];
            }
        }
        if (j > t[0])
            return i - t[0];
        return 0;
    }


    void test() {

    }
}

namespace sort_5_3 {

    int select_sort_1(int *a, int n) {
        int min;
        for (int i = 0; i < n; i++) {
            min = i;
            for (int j = i; j < n; j++)
                if (a[j] < a[min])
                    min = j;
            if (min != i)
                swap_(&a[i], &a[min]);
        }
    }

    /*
     * 8    9   10  4   5   6   20  1   2
     *
     * 1    8   9   10  4   5   6   20  2
     * 1    2   8   9   10  4   5   6   20
     * 1    2   4   8   9   10  5   6   20
     * 1    2   4   5   8   9   10  6   20
     * 1    2   4   5   6   8   9   10  20
     *
     *
     *
     */
    int bubble_sort_1(int *a, int n) {
        int f = 1;
        for (int i = 0; i < n && f == 1; i++) {
            f = 0;
            for (int j = i + 1; j < n; j++) {
                if (a[j] < a[i]) {
                    swap_(&a[i], &a[j]);
                    f = 1;
                }
            }
        }
    }

    /*
     * 4 5 1 2 6 3
     *
     * 451263
     * 145263
     * 124563
     * 124563
     * 123456
     *
     */
    int insert_sort_1(int *a, int n) {
        int t, j;
        for (int i = 1; i < n; i++) {
            t = a[i];
            for (j = i - 1; j >= 0 && a[j] > t; j--) {
                a[j + 1] = a[j];
            }
            a[j + 1] = t;
        }
    }

    int insert_sort_b_2(int *a, int n) {
        int mid, low, high, t;
        for (int i = 0; i < n; i++) {
            t = a[i], low = 0, high = i - 1;
            while (low <= high) {
                mid = (low + high) / 2;
                if (a[mid] < t)
                    low = mid + 1;
                else
                    high = mid - 1;
            }

            for (int j = i - 1; j >= low; j--)
                a[j + 1] = a[j];
            a[low] = t;
        }
    }

    int insert_sort_b_1(int *a, int n) {
        int mid, low, high, t;
        for (int i = 0; i < n; i++) {
            low = 0, high = i - 1, t = a[i];
            while (low <= high) {
                mid = (low + high) / 2;
                if (a[mid] < t) {
                    low = mid + 1;
                } else
                    high = mid - 1;
            }

            for (int j = i - 1; j >= low; j--) {
                a[j + 1] = a[j];
            }
            a[low] = t;
        }
    }


    /*
     *50    26  38  80  70  90  8   30  40  20
     *
     *      ----gap=5--------
     * 50                    90
     *      26                  8
     *          38                  30
     *              80                  40
     *                  70                  20
     *-----------gap=3-------------
     * 50    8   30  40  20  90  26  38  80  70
     * 50           40          26          70
     *      8           20          38
     *          30          90          80
     * 26   8   30  40  20  80  50  38  90  70
     *
     */
    int shell_sort_1(int *a, int n, int gap = 2) {
        int j, g = n / gap, t;
        while (g > 0) {
            for (int i = g; i < n; i++) {
                t = a[i];
                for (j = i - g; j >= 0 && a[j] > t; j -= g) {
                    a[j + g] = a[j];
                }
                a[j + g] = t;
            }
            g /= gap;
        }
    }

    int partition_1(int *a, int left, int right) {
        int i = left, j = right + 1;
        do {
            do i++; while (left < right && a[i] < a[left]);
            do j--; while (left < right && a[j] > a[left]);
            if (i < j) swap_(&a[i], &a[j]);
        } while (i < j);
        swap_(&a[left], &a[j]);
        return j;
    }

    /*
     *  92  96  100 110 42  35  30  88
     *t=92
     *  L                           R
     *  88                          92
     *      L92                     R96
     *      L30                 R92
     *          L92             R100
     *          L35          R92
     *             L92       R110
     *                 L42R92
     *
     *  66  13  51  76  81  26  57  69  21
     *  L                               R
     *  23  L                           R66
     *              L66                 R76
     *              L57         R66
     *                  L66     R81
     *                  26 R66
     *
     *
     *
     *
     *
     */
    int quick_sort_1(int *a, int low, int high) {
        if (low < high) {
            int p = partition_1(a, low, high);
            quick_sort_1(a, low, p - 1);
            quick_sort_1(a, p + 1, high);
        }
    }


    int partition_2(int *a, int left, int right) {
        int i = left, j = right + 1;
        do {
            do i++; while (left < right && a[i] < a[left]);
            do j--; while (left < right && a[j] > a[left]);
            if (i < j) swap_(&a[i], &a[j]);
        } while (i < j);
        swap_(&a[left], &a[j]);
        return j;
    }

    int quick_sort_2(int *a, int low, int high) {
        if (low < high) {
            int p = partition_2(a, low, high);
            quick_sort_2(a, low, p - 1);
            quick_sort_2(a, p + 1, high);
        }
    }

    /*
     *  5   8   12  19  28  20  15  22
     *
     *
     */
    int adjheap_1(int *a, int i, int n) {
        int t = a[i];
        for (int j = 2 * i + 1; j < n; j = j * 2 + 1) {
            if (j + 1 < n && a[j] < a[j + 1])
                j++;

            if (a[j] > t) {
                swap_(&a[j], &a[i]);
                i = j;
            } else
                break;
        }
    }

    /*
     *  8   15  10  21  34  16  12
     *
     *                  10
     *          15              12
     *      21      34      16
     *
     */
    int adjheap_4(int *a, int i, int n) {
        int t = a[i];
        for (int j = i * 2 + 1; j < n; j = j * 2 + 1) {
            if (j + 1 < n && a[j] < a[j + 1])
                j++;
            if (a[j] > t) {
                swap_(&a[j], &a[i]);
                i = j;
            } else break;
        }

    }

    int heap_sort_4(int *a, int n) {
        for (int i = n / 2 - 1; i >= 0; i--)
            adjheap_4(a, i, n);

        for (int j = n - 1; j >= 0; j--) {
            swap_(&a[0], &a[j]);
            adjheap_4(a, 0, j);
        }
    }

    int heap_sort_1(int *a, int n) {
        for (int i = n / 2 - 1; i >= 0; i--)
            adjheap_1(a, i, n);

        for (int j = n - 1; j >= 0; j--) {
            swap_(&a[j], &a[0]);
            adjheap_1(a, 0, j);
        }
    }


    int merge_1(int *a, int low, int high, int mid) {
        int t[high - low + 1], i = low, j = mid + 1;
        for (int k = low; k <= high; k++)
            t[k - low] = a[k];

        for (int k = low; k <= high; k++) {
            if (i > mid) {
                a[k] = t[j - low];
                j++;
            } else if (j > high) {
                a[k] = t[i - low];
                i++;
            } else if (t[i - low] > t[j - low]) {
                a[k] = t[j - low];
                j++;
            } else {
                a[k] = t[i - low];
                i++;
            }
        }
    }

    /*
     *  12  2   16  30  28  10  16_  20  6   18
     *
     *  10  20  30  12  2   16  16_  6  28  18
     *  2   6   10  12  16  16_ 18  20  28  30
     *
     *
     *
     */
    int merge_sort_1(int *a, int low, int high) {
        if (low < high) {
            int m = (low + high) / 2;
            merge_sort_1(a, low, m);
            merge_sort_1(a, m + 1, high);
            merge_1(a, low, high, m);
        }
    };

    int merge_2(int *a, int left, int right, int mid) {
        int t[right - left + 1], i = left, j = mid + 1;
        for (int k = left; k <= right; k++)
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

    int merge_sort_2(int *a, int low, int high) {
        if (low < high) {
            int m = (low + high) / 2;
            merge_sort_2(a, low, m);
            merge_sort_2(a, m + 1, high);
            merge_2(a, low, high, m);
        }
    }


    int adjheap_3(int *a, int i, int n) {
        int t = a[i];
        for (int j = i * 2 + 1; j < n; j = j * 2 + 1) {
            if (j + 1 < n && a[j] < a[j + 1])
                j++;
            if (a[j] > t) {
                swap_(&a[j], &a[i]);
                i = j;
            } else
                break;
        }
    }


    int heap_sort_3(int *a, int n) {
        for (int i = n / 2 - 1; i >= 0; i--)
            adjheap_3(a, i, n);

        for (int j = n - 1; j >= 0; j--) {
            swap_(&a[0], &a[j]);
            adjheap_3(a, 0, j);
        }

    }

    int merge_5(int *a, int left, int right, int mid) {
        int t[right - left + 1], i = left, j = mid + 1;

        for (int k = left; k <= right; k++) {
            t[k - left] = a[k];
        }

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

    int merge_sort_5(int *a, int low, int high) {
        if (low < high) {
            int m = (low + high) / 2;
            merge_sort_5(a, low, m);
            merge_sort_5(a, m + 1, high);
            merge_5(a, low, high, m);
        }
    }


    int merge_4(int *a, int left, int right, int mid) {
        int t[right - left + 1], i = left, j = mid + 1;
        for (int k = left; k <= right; k++)
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

    int merge_sort_4(int *a, int low, int high) {
        if (low < high) {
            int m = (low + high) / 2;
            merge_sort_4(a, low, m);
            merge_sort_4(a, m + 1, high);
            merge_4(a, low, high, m);
        }
    }

    /*
     *  9,1,4,13,7,8,20,23,15
     *
     *
     */
    void test() {
        int a1[] = {12, 4, 67, 5, 88, 15, 34, 26, 33, 19};
        ps_int(a1, 10);
//        select_sort_1(a1, 10);
//        bubble_sort_1(a1, 10);
//        insert_sort_1(a1, 10);
//        insert_sort_b_1(a1, 10);
//        shell_sort_1(a1, 10);
//        quick_sort_2(a1, 0, 9);
//        heap_sort_4(a1, 10);
        merge_sort_4(a1, 0, 9);
        ps_int(a1, 10);
    }

}

namespace test_5_3_1 {

    /*
     *
     *
     *
     *
     *
     *
     */


    int del_hash(int *h, int k, int n) {
        int i = k % 7;
        if (h[i] == INTMAX_MAX)
            return errCode("没有这个关键字", 0);
        if (h[i] == k) {
            h[i] == INTMAX_MAX;
            return errCode("删除成功", 1);
        } else {
            int j = i;
            for (int d = 1; d <= n - 1; d++) {
                i = (j + d) % 7;
                if (h[i] == INTMAX_MAX)
                    return 0;
                if (h[i] == k) {
                    h[i] = INTMAX_MAX;
                    return 1;
                }
            }
            return errCode("没有这个关键字", 0);
        }
    }
}

namespace run_3 {

    void test() {
        sort_5_3::test();
//        search_5_3::test();
//        grapg_5_3::test();
//        tree_5_3::test();
//        queue_5_3::test();
//        stack_5_3::test();
//        linklist_5_3::test();
//        sqlist_5_3::test();
    }
}