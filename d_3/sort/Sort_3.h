
#include <iostream>

using namespace std;

int errCode(string, int);

void ps_int(int *, int);

namespace sort_3 {

    int a[] = {22, 3, 556, 5, 12, 8, 235, 9, 46, 90};
    int b[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    void swap(int *a, int *b) {
        int t = *a;
        *a = *b;
        *b = t;
    }

    /*
     * 折半查找
     */
    int bsearch_3(int *a, int n, int k) {
        int low = 0, high = n, mid;
        while (low <= high) {
            mid = (low + high) / 2;
            if (a[mid] == k)
                return errCode("查找成功", mid);
            if (a[mid] > k) {
                high = mid - 1;
            }
            if (a[mid] < k) {
                low = mid + 1;
            }
        }
        return errCode("元素不存在", -1);
    }

    /*
     * 递归折半查找
     */
    int bsearch_traverse_3(int *a, int k, int low, int high) {
        if (low <= high) {
            int mid = (low + high) / 2;
            if (a[mid] == k)
                return errCode("查找成功", mid);
            if (a[mid] < k)
                return bsearch_traverse_3(a, k, mid + 1, high);
            if (a[mid] > k)
                return bsearch_traverse_3(a, k, low, mid - 1);
        }
    }


    int insert_sort_3_1(int *a, int n) {
        int j, t;
        for (int i = 1; i < n; i++) {
            if (a[i] < a[i - 1]) {
                t = a[i];
                for (j = i - 1; j >= 0 && a[j] > t; j--) {
                    a[j + 1] = a[j];
                }
                a[j + 1] = t;
            }
        }
    }

    int insert_sort_3_2(int *a, int n) {
        int j, t;
        for (int i = 1; i < n; i++) {
            t = a[i];
            j = i - 1;
            while (a[i] < a[i - 1]) {
                a[j + 1] = a[j];
                j--;
                if (j < 0)break;
            }
            a[j + 1] = t;
        }
    }

    void select_sort_3_1(int *a, int n) {
        int min;
        for (int i = 0; i < n; i++) {
            min = i;
            for (int j = i + 1; j < n; j++)
                if (a[j] < a[min])
                    min = j;

            if (i != min)
                swap(&a[i], &a[min]);

        }
    }

    void bubble_sort_3_1(int *a, int n) {
        for (int i = 0; i < n; i++)
            for (int j = i + 1; j < n; j++)
                if (a[j] < a[i])
                    swap(&a[j], &a[i]);
    }


    void shell_sort_3_1(int *a, int n, int gap) {
        int t, j, g = n / gap;
        while (g >= 1) {
            for (int i = g; i < n; i++) {
                t = a[i];
                for (j = i - g; j >= 0 && a[j] > t; j -= g) {
                    a[j + g] = a[j];
                }
                a[g + j] = t;
            }
            g /= gap;
        }
    }

    void shell_sort_3_2(int *a, int n, int gap) {
        int t, j, g = n / gap;
        while (g >= 1) {
            for (int i = g; i < n; i++) {
                t = a[i];
                j = i - g;
                while (j >= 0 && a[j] > t) {
                    a[j + 1] = a[j];
                    j -= g;
                }
                a[j + g] = t;
            }
            g /= gap;
        }
    }


    int partition_3_1(int *a, int left, int right) {
        int low = left, high = right + 1;
        do {
            do low++; while (left < right && a[low] < a[left]);
            do high--; while (left < right && a[high] > a[left]);
            if (low < high) swap(&a[low], &a[high]);
        } while (low < high);
        swap(&a[left], &a[high]);
        return high;
    }

    void quick_sort_3_1(int *a, int left, int right) {

        if (left < right) {
            int pivot = partition_3_1(a, left, right);
            quick_sort_3_1(a, left, pivot - 1);
            quick_sort_3_1(a, pivot + 1, right);
        }

    }


    void test() {
//        int r1 = bsearch_3(b, 10, 83);
//        int r1 = bsearch_traverse_3(b, 3, 0, 10);
//        std::cout << r1 << std::endl;
        ps_int(a, 10);

//        insert_sort_3_2(a, 10);
//        select_sort_3_1(a, 10);
//        bubble_sort_3_1(a, 10);
//        shell_sort_3_2(a, 10, 3);
        quick_sort_3_1(a, 0, 9);

        ps_int(a, 10);

    }
}