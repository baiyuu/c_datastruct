#include <iostream>

namespace sqList {
#define CAPACITY 100
    typedef int Element;


    typedef struct {
        Element data[4];
        int length;
    } SqList;

    void ps(int a[], int n) {
        printf("遍历数组:\n");
        for (int i = 0; i < n; i++) {
            printf("%d\t", a[i]);
        }
        printf("\n");
    }

    int get(SqList *sq, int n, int *b) {
        *b = sq->data[n];
    }


    void testGet() {
        SqList s = {
                {1, 2, 3, 4},
                4
        };

        int b = 0;
        int *c = &b;
        get(&s, 2, c);
        printf("线性表中获取元素：b=%d", b);
    }


    int insert(SqList *sq, int i, Element e) {

        if (sq->length == CAPACITY) {
            printf("线性表已经满了，不能插入");
            return -1;
        }

        if (i < 0 || i > sq->length + 1) {
            printf("插入位置错误");
            return -1;
        }

        if (i < sq->length) {
            for (int j = sq->length - 1; j >= i - 1; j--) {
                sq->data[j + 1] = sq->data[j];
            }
            sq->data[i - 1] = e;
            sq->length++;
        }
        return 1;
    }

    void testInsert() {
        SqList s = {
                {1, 2, 3, 4},
                4
        };
        ps(s.data, s.length);
        insert(&s, 2, 233);
        ps(s.data, s.length);
    }

    int delete2(SqList *sq, int i, Element *e) {
        if (sq->length == 0) {
            return -1;
            printf("空表没有数据可删除");
        }
        if (i < 1 || i > sq->length) {
            printf("删除位置错误");
            return -1;
        }

        for (int j = i; j < sq->length; j++) {
            sq->data[j - 1] = sq->data[j];
        }
        sq->length--;
        *e = sq->data[i - 1];
        return 1;
    }

    void testDelete() {
        SqList s = {
                {1, 2, 3, 4},
                4
        };
        int a = 0;
        int *p = &a;
        ps(s.data, s.length);
        delete2(&s, 11, p);
        ps(s.data, s.length);
        printf("\n 删除的元素=%d", *p);
    }


    void run() {
        testInsert();
//    testDelete();
    }
}
