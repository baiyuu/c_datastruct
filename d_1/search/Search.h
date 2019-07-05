
#include <iostream>

using namespace std;

namespace Search {

    int errMsg(string msg, int code = -1) {
        std::cout << msg << std::endl;
        return code;
    }

    /*
     * 顺序查找  数组下标从1开始
     */
    int sequential_search(int *a, int n, int k) {
        for (int i = 1; i <= n; i++) {
            if (a[i] == k) {
                return i;
            }
        }
        return 0;
    }

    int sequential_search_2(int *a, int n, int k) {
        a[0] = k;//设置为‘哨兵’，即如果查找元素不存在会在n=0处返回位置。
        while (a[n] != k) {
            n--;
        }
        return n;
    }


    void testSeqSearch() {
        int a[] = {0, 1, 2, 3, 4, 5, 6};
//        int v = sequential_search(a, 6, 5);
        int v = sequential_search_2(a, 6, 5);
        std::cout << "position=" << v << std::endl;

    }

    void run() {
        testSeqSearch();
    }
}