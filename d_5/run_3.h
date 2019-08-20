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
        LinkList q = newNode, p;
        q->next = nullptr;
        for (int i = 0; i < n; i++) {
            p = newNode;
            p->data = a[i];
            p->next = q->next;
            q->next = p;
        }
        return q;
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


    void test() {
        int aa[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
        int aa2[] = {7, 10, 10, 21, 30, 42, 42, 42, 51, 70};
        int a3[] = {1, 2, 3, 4, 5, 7, 9};
        int a4[] = {2, 3, 4, 6, 7, 8, 9, 10, 12, 14};
        LinkList list = create(aa2, 3);
        LinkList list2 = create(a3, 3, 7);
        LinkList list3 = create(a4, 3, 10);
        LinkList a = newNode;
        a->next = list2;
        LinkList b = newNode;
        b->next = list3;
        //        ps_link_list(list2);

        //        LinkList b = split(a);
//        LinkList b = split_3(a);
//        ps_link_list(b);
//        distinct_(list);
//        merge_(list2, list3);
//        get_common_arr(a3, 7, a4, 10);
        get_common_2(a, b);

        //        ps_link_list(list2);
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
     * 带头单链表，找出最小值，输出后删除，重复执行至链表为空，再删除头节点
     */
    int del_min_1(LinkList &a) {
        LinkList aa = a->next, p=a;
        int min = aa->data;
        while (aa != nullptr) {

            if (aa->data < min)
                min = aa->data;

            

        }
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

namespace run_3 {

    void test() {
        linklist_5_3::test();
//        sqlist_5_3::test();
    }
}