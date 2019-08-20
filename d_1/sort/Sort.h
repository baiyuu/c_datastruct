
#include <iostream>

using namespace std;
#define size 10//要排序数组的长度

int errMsg(string msg, int code = -1, int sort = 1) {
    std::cout << msg << std::endl;
    return code;
}

typedef struct {
    int arr[size + 1];
    int len;
} *Array;
int a[] = {12, 67, 56, 16, 25, 37, 22, 15, 47, 34};


/*
 * 排序过程中交换数组中的数据
 */
void swap_1(Array a, int i, int j) {
    int t = a->arr[i];
    a->arr[i] = a->arr[j];
    a->arr[j] = t;
}

void swap_1(int *a, int *b) {
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
                    swap_1(&a[j], &a[i]);
    }


    void sort_2(int *a) {
        for (int i = 0; i < 10; i++)
            for (int j = 9; j >= i; j--)
                if (a[j] > a[j + 1])
                    swap_1(&a[j], &a[j + 1]);
    }


    void sort_3(int *a) {
        bool flag = true;
        for (int i = 0; i < 10 && flag; i++) {
            flag = false;
            for (int j = 9; j >= i; j--) {
                if (a[j] > a[j + 1]) {
                    swap_1(&a[j], &a[j + 1]);
                    flag = true;
                }
            }
        }
    }

    void test() {
        ps(a);
//        sort_1(a);
//        sort_2(a);
//        sort_3(a);
        ps(a);
    }
}

namespace SelectSort {
    void sort_1(int *a, int n) {
        int min;
        for (int i = 0; i < n; i++) {
            min = i;
            for (int j = i + 1; j < n; j++)
                if (a[j] < a[min])
                    min = j;

            if (i != min)
                swap_1(&a[i], &a[min]);
        }
    }

    void test() {
        ps(a);
        sort_1(a, 10);
        ps(a);
    }
}

namespace InsertSort {
    void sort_1(int *a, int n) {
        int flag, j;
        // 5 7 3 4 6 2
        for (int i = 1; i < n; i++) {
            if (a[i] < a[i - 1]) {
                flag = a[i];
                for (j = i - 1; a[j] > flag; j--) {
                    a[j + 1] = a[j];
                }
                a[j + 1] = flag;
            }
        }
    }

    void sort_2(int *a, int n) {
        int f, j;
        for (int i = 1; i < n; i++) {
            if (a[i] < a[i - 1]) {
                f = a[i];
                for (j = i - 1; a[j] > f; j--) {
                    a[j + 1] = a[j];
                }
                a[j + 1] = f;
            }
        }
    }

    void test() {
        ps(a);
//        sort_1(a, 10);
        sort_2(a, 10);
        ps(a);
    }
}


namespace ShellSort {
    //代码有问题，只支持gap=2
    void sort_2(int a[], int n) {
        int j, f, g = n, t;
        while (g > 1) {
            g /= 4 + 1;
            do {
                f = 0;
                for (int i = 0; i < n - g; i++) {
                    j = i + g;
                    if (a[i] > a[j]) {
                        swap_1(&a[i], &a[j]);
                        f = 1;
                    }
                }
            } while (f != 0);
        }
    }

    //正确算法
    void sort_1(int *a, int n) {
        //12	67	56	16	25	37	22	15	47	34
        int i, j, g = n, f;
        do {
            g = g / 2 + 1;
            for (i = g + 1; i < n; i++) {//把前gap个元素留下
                if (a[i] < a[i - g]) {  //如果后面的元素比前面的小，如a[g+0]<a[0]的话 需要交换操作
                    f = a[i];
                    for (j = i - g; j > 0 && f < a[j]; j -= g) {
                        a[j + g] = a[j];
                    }
                    a[j + g] = f;
                }
            }
        } while (g > 1);
    }


    void test() {
        ps(a);
        sort_2(a, 10);
        ps(a);
    }
}

//问题代码
namespace HeapSort {

    void test() {
        ps(a);
        ps(a);
    }
}


int b[] = {16, 7, 13, 10, 9, 15, 3, 2, 5, 8, 12, 1, 11, 4, 6, 14}; //16

namespace MergeSort {


    void test() {
        ps(b);
        ps(b);
    }
}

int c[] = {5, 1, 9, 3, 7, 4, 8, 6, 2};

namespace QuickSort {

    void quick_sort_1(int *c, int n) {

    }

    void test() {
        ps(c);
        quick_sort_1(c, 9);
        ps(c);
    }
}

namespace Test_sort {
    void insert_sort_1(int *a, int n) {
        int k, j;
        for (int i = 1; i < n; i++) {
            for (j = i - 1; j > 0; j--)
                if (a[j] < a[i])
                    break;

            if (j != i - 1) {
                int t = a[i];
                for (k = i - 1; k > j; k--) {
                    a[k + 1] = a[k];
                }
                a[k + 1] = t;
            }

        }
    }

    void insert_sort_2(int *a, int n) {
        int f, j;
        for (int i = 1; i < n; i++) {
            if (a[i] < a[i - 1]) {
                f = a[i];
                for (j = i - 1; j >= 0 && a[j] > f; j--) {
                    a[j + 1] = a[j];
                }
                a[j + 1] = f;
            }
        }
    }

    void insert_sort_3(int *a, int n) {
        int f, j;

        for (int i = 1; i < n; i++) {
            f = a[i];
            j = i - 1;
            while (f < a[j]) {
                a[j + 1] = a[j];
                j--;
                if (j < 0)break;
            }
            a[j + 1] = f;
        }

    }


    void shell_sort_1(int *a, int n, int gap) {
        int f, j, g = n / gap;
        while (g >= 1) {
            for (int i = g; i < n; i++) {
                f = a[i];
                for (j = i - g; j >= 0 && a[j] > f; j -= g) {
                    a[j + g] = a[j];
                }
                a[j + g] = f;
            }
            g /= gap;
        }
    }

    void shell_sort_2(int *a, int n, int gap) {
        int f, j, g = n / gap;
        while (g >= 1) {
            for (int i = g; i < n; i++) {
                f = a[i];
                j = i - g;
                while (j >= 0 && a[j] > f) {
                    a[j + g] = a[j];
                    j -= g;
                }
                a[j + g] = f;
            }
            g /= gap;
        }
    }


    int partition_1(int *a, int low, int high) {
        int k = a[low];
        while (low < high) {

            while (low < high && a[high] >= k)
                high--;

            a[low] = a[high];

            while (low < high && a[low] <= k)
                low++;

            a[high] = a[low];

        }
        a[low] = k;
        return low;
    }

    void quick_sort_1(int *a, int low, int high) {
        int pivot = 0;
        if (low < high) {
            pivot = partition_1(a, low, high);
            quick_sort_1(a, low, pivot - 1);
            quick_sort_1(a, pivot + 1, high);
        }

    }

    void Swap_1(int &a, int &b) {
        int temp = a;
        a = b;
        b = temp;
    }

    int partition_3(int left, int right) {
        int i = left, j = right + 1;
        do {
            do i++; while (a[i] < a[left]);
            do j--; while (a[j] > a[left]);
            if (i < j) Swap_1(a[i], a[j]);
        } while (i < j);
        Swap_1(a[left], a[j]);
        return j;
    }

    void quick_sort_3(int left, int right) {
        if (left < right) {
            int j = partition_3(left, right);
            quick_sort_3(left, j - 1);
            quick_sort_3(j + 1, right);
        }
    }


    int partition_4(int *a, int low, int high) {
        int left = low, right = high + 1;
        do {
            do left++; while (low < high && a[left] < a[low]);
            do right--; while (low < high && a[right] > a[low]);
            if (left < right) swap_1(&a[left], &a[right]);
        } while (left < right);
        swap_1(&a[low], &a[right]);
        return right;
    }

    void quick_sort_4(int *a, int low, int high) {
        if (low < high) {
            int p = partition_4(a, low, high);
            quick_sort_4(a, low, p - 1);
            quick_sort_4(a, p + 1, high);
        }
    }


    void test() {
        ps(a);
        quick_sort_1(a, 0, 10);
//        quick_sort_2(0, 10);
        ps(a);
    }
}

namespace Sort {

    void run() {
//        BubbleSort::test();
//        SelectSort::test();
//        InsertSort::test();
//        ShellSort::test();
//        HeapSort::test();
//        MergeSort::test();
//        QuickSort::test();
        Test_sort::test();
    }
}
