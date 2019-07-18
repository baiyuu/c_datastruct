
#include <iostream>

using namespace std;

void ps_int(int *, int);

int errCode(string, int);

namespace insert_sort_4 {

    int insert_sort_4_1(int *a, int n) {
        int t, j;
        for (int i = 1; i < n; i++) {
            t = a[i];
            for (j = i - 1; j >= 0 && a[j] > t; j--)
                a[j + 1] = a[j];
            a[j + 1] = t;
        }
    }


    void test(int *a, int n) {
        insert_sort_4_1(a, n);
    }
}
namespace merge_sort_4 {
    /**
     * 合并两个数组
     * @param a 待排序数组
     * @param p 第一组起始位置
     * @param q 第一组终止位置  也是第二组+1 的起始位置
     * @param r 第二组终止位置
     * @return 
     */
    int merge_4_1(int *a, int p, int q, int r) {
        int n1 = q - p;
        int n2 = r - q;

        int *a1 = (int *) malloc(sizeof(int) * n1);
        int *a2 = (int *) malloc(sizeof(int) * n2);

        for (int i = 0; i < n1; i++)
            a1[i] = a[i];


        for (int i = q; i < r; i++)
            a2[i] = a[i];


        ps_int(a1, n1);
        ps_int(a2, n2);


        int m = 0, n = 0;
        for (int j = p; j < r && m > 0 && n > 0; j++) {
            if (a1[m] <= a2[n]) {
                a[j] = a1[m];
                m += 1;
            } else {
                a[j] = a2[n];
                j += 1;
            };
        }

    }

    int merge_sort_4_1(int *a, int s, int n) {
        if (s < n) {
            int q = (s + n) / 2;
//            merge_sort_4_1(a, s, q);
//            merge_sort_4_1(a, q + 1, n);
            merge_4_1(a, s, q, n);
        }
    }

    void test(int *a, int n) {
        merge_sort_4_1(a, 0, n);
    }
}
namespace sort_4 {
    int a[] = {12, 2, 45, 18, 41, 4, 6, 85, 9, 1};

    void test() {
        ps_int(a, 10);
//        insert_sort_4::test(a, 10);
        merge_sort_4::test(a, 10);
        ps_int(a, 10);
    }
}