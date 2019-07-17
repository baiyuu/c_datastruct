
#include <iostream>

using namespace std;


int errCode(string, int);

void ps_int(int *, int);

namespace seq_3 {

#define MAX 100

//    typedef struct list_node {
//        int data;
//    } List;

    typedef int Element;

    typedef struct list {
        Element *list;
        int length;
        int listsize;
    } SqList;


    void init(SqList *sq) {
        std::cout << "init start--------------" << std::endl;
        sq->list = (int *) malloc(sizeof(int) * MAX);

        sq->length = 0;
        sq->listsize = MAX;
        for (int i = 0; i < sq->listsize; i++)
            sq->list[i] = 0;

        std::cout << "init end--------------" << std::endl;
    }


    int insert(SqList *sq, int i, Element e) {
        std::cout << "insert start---------------" << std::endl;
        if (sq->length > MAX || sq->length < 0)
            return errCode("表的长度不正确", -1);

//        Element *newList;
        //需要扩容
        if (sq->length > sq->listsize) {
            sq->list = (int *) realloc(sq->list, (sq->listsize + 10) * sizeof(Element));
            sq->listsize += 10;
        }

        int *ip = &(sq->list[i]);

        for (int *j = &(sq->list[sq->length - 1]); j >= ip; j--)
            *(j + 1) = *j;

        *ip = e;
        sq->length++;

        std::cout << "insert end---------------length=" << sq->length << std::endl;
    }

    void ins() {
        int a[] = {1, 2, 3, 4, 5};
        for (int *i = &(a[4]); i >= &(a[0]); i--)
            printf("%d\t", *i);
        std::cout << "" << std::endl;
        for (int *j = a; j <= &(a[4]); j++)
            printf("%d\t", *j);
    }

    int del(SqList *sq, int i, Element *deleted) {
        if (i > sq->length || i < 0)
            return errCode("删除位置不合法！", -1);

        *deleted = sq->list[i];
        for (int *j = &(sq->list[i]); j < &(sq->list[sq->length - 1]); j++)
            *j = *(j + 1);

        sq->length--;

    }

    void test_() {
        SqList sq;
        init(&sq);
        ps_int(sq.list, sq.length);
        for (int i = 0; i < 14; i++)
            insert(&sq, i, 1 + i);
        ps_int(sq.list, sq.length);
        int p;
        del(&sq, 3, &p);
        ps_int(sq.list, sq.length);
        std::cout << "deleted=" << p << std::endl;
    }

    /**********顺序表实例分析*****************
     *  创建一个静态顺序表存整数，大小10
     *  1、输入6个整数，打印内容，显示表中剩余的空间个数
     *  2、在表中第3个位置插入100，打印表，显示剩余空间个数
     *  3、试图向第11个位置插入元素，显示警告内容
     *  4、删除第6个元素，打印表，显示剩余空间个数
     * 
     */
#define size_example_1 10
    typedef struct {
        Element *list;
        int len;
        int listsize;
    } StaticList;

    void init_1(StaticList *s) {
        s->list = (int *) malloc(sizeof(int) * size_example_1);
        s->len = 0;
        s->listsize = size_example_1;
        for (int i = 0; i < s->listsize; i++)
            s->list[i] = 0;
    }

    int insert_1(StaticList *s, int i, Element e) {

        if (i < 0 || i > s->listsize)
            return errCode("插入位置非法", -1);

        int *ip = &(s->list[i]);
        for (int *j = &(s->list[s->len - 1]); j >= ip; j--)
            *(j + 1) = *j;

        s->list[i] = e;
        s->len++;
    }

    void example_1() {
        StaticList s;
        init_1(&s);
        std::cout << "please input a number:" << std::endl;
        int n, f;
        cin >> n;
        std::cout << "please input -" << n << "-number" << std::endl;
        for (int i = 0; i < n; i++) {
            cin >> f;
            insert_1(&s, i, f);
        }
        ps_int(s.list, s.len);
        std::cout << "空余位置个数=" << s.listsize - s.len << std::endl;

    }

    void test() {
        example_1();
    }
}


namespace seq_list_3 {

    int run() {
        seq_3::test();
    }
}