
#include <iostream>

using namespace std;

int errMsg(string msg, int code = -1, int sort = 1) {
    std::cout << msg << std::endl;
    return code;
}

#define size 10//要排序数组的长度
typedef struct {
    int arr[size + 1];
    int len;
} *Array;
int a[] = {12, 67, 56, 16, 25, 37, 22, 15, 47, 34};


/*
 * 排序过程中交换数组中的数据
 */
void swap(Array a, int i, int j) {
    int t = a->arr[i];
    a->arr[i] = a->arr[j];
    a->arr[j] = t;
}

void swap(int *a, int *b) {
    int t = *a;
    *a = *b;
    *b = t;
}

void ps(int *a) {
    for (int i = 0; i < 10; i++)
        printf("%d\t", a[i]);
    puts("");
}

namespace BubbleSort {
    void sort_1(int *a) {
        for (int i = 0; i < 10; i++)//从0开始，每循环一遍，都会把最小的元素换到前面去
            for (int j = i + 1; j < 10; j++)//从第i个元素后面开始，a[j]都是排在a[i]后面的元素
                if (a[i] > a[j]) //外大于内，说明前面的元素大，需要交换
                    swap(&a[j], &a[i]);
    }

    void sort_2() {
        
    }

    void test() {
        ps(a);
        sort_1(a);
        ps(a);
    }
}

namespace Sort {

    void run() {
        BubbleSort::test();
    }
}
