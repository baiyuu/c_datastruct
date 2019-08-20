#include  <iostream>

using namespace std;

void ps_int(int *, int);

void ps_char(int *, int);

int errCode(string, int);

namespace sort_5_2 {
    int a[] = {12, 3, 41, 4, 1, 7, 15, 88, 66, 25};

    int swap(int *a, int *b) {
        int q = *a;
        *a = *b;
        *b = q;
    }

    int bubble_sort_1(int *a, int n) {
        int f = 1;
        for (int i = 0; i < n && f == 1; ++i) {
            f = 0;
            for (int j = i + 1; j < n; ++j) {
                if (a[j] < a[i]) {
                    swap(&a[j], &a[i]);
                    f = 1;
                }
            }
        }
    }

    int insert_sort_1(int *a, int n) {
        int j, t;
        for (int i = 1; i < n; ++i) {
            t = a[i];
            for (j = i - 1; a[j] > t && j >= 0; j--) {
                a[j + 1] = a[j];
            }
            a[j + 1] = t;
        }
    }

    int select_sort_1(int *a, int n) {
        int m;
        for (int i = 0; i < n; ++i) {
            m = i;
            for (int j = i + 1; j < n; j++)
                if (a[j] < a[m])
                    m = j;

            if (m != i)
                swap(&a[m], &a[i]);
        }
    }

    int shell_sort_1(int *a, int n, int gap = 2) {
        int g = n / gap, t, j;
        while (g > 0) {
            for (int i = g; i < n; i++) {
                t = a[i];
                for (j = i - g; j >= 0 && a[j] > t; j -= g) {
                    a[g + j] = a[j];
                }
                a[g + j] = t;
            }
            g /= gap;
        }
    }

    int partition_1(int *a, int left, int right) {
        int i = left, j = right + 1;
        do {
            do i++; while (left < right && a[i] < a[left]);
            do j--; while (left < right && a[j] > a[left]);
            if (i < j) swap(&a[i], &a[j]);
        } while (i < j);
        swap(&a[left], &a[j]);
        return j;
    }

    int quick_sort_1(int *a, int i, int j) {
        if (i < j) {
            int p = partition_1(a, i, j);
            quick_sort_1(a, i, p - 1);
            quick_sort_1(a, p + 1, j);
        }
    }

    int insert_b_sort_1(int *a, int n) {
        int t, low, high, mid;
        for (int i = 0; i < n; ++i) {
            t = a[i], low = 0, high = i - 1;
            while (low <= high) {
                mid = (low + high) / 2;
                if (t > a[mid])
                    low = mid + 1;
                else
                    high = mid - 1;
            }
            for (int j = i - 1; j >= low; j--)
                a[j + 1] = a[j];
            a[low] = t;
        }
    }

    int adj_heap_1(int *a, int i, int n) {
        int t = a[i];
        for (int j = i * 2 + 1; j < n; j = j * 2 + 1) {
            if (j + 1 < n && a[j] < a[j + 1])
                j++;
            if (a[j] > t) {
                swap(&a[i], &a[j]);
                i = j;
            } else break;
        }
    }

    int heap_sort_1(int *a, int n) {
        for (int i = n / 2 - 1; i >= 0; i--)
            adj_heap_1(a, i, n);

        for (int j = n - 1; j >= 0; j--) {
            swap(&a[0], &a[j]);
            adj_heap_1(a, 0, j);
        }
    }

    int merge_1(int *a, int left, int right, int mid) {
        int t[right - left + 1], i = left, j = mid + 1;
        for (int k = left; k <= right; ++k)
            t[k - left] = a[k];

        for (int k = left; k <= right; ++k) {
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

    int merge_sort_1(int *a, int low, int high) {
        if (low < high) {
            int m = (low + high) / 2;
            merge_sort_1(a, low, m);
            merge_sort_1(a, m + 1, high);
            merge_1(a, low, high, m);
        }
    }

    int radix_max_1(int *a, int n) {
        int m = 0;
        for (int i = 0; i < n; ++i)
            if (a[i] > m)
                m = a[i];
        int j = 1, k = 10;
        while (k <= m) {
            k *= 10;
            j++;
        }
        return j;
    }


    int radix_sort_1(int *a, int n) {
        int d = radix_max_1(a, n);//最大数的位数
        int temp[n];
        int count[10];//桶中的计数器
        int radix = 1;
        int k;
        for (int i = 1; i <= d; ++i) { //循环d次进行排序
            //每次排序前清空计数器
            for (int j = 0; j < 10; ++j)
                count[j] = 0;

            //记录每个桶中的记录数
            for (int j = 0; j < 10; ++j) {
                k = (a[j] / radix) % 10;
                count[k]++;
            }

            //
            for (int j = 1; j < 10; ++j)
                count[j] = count[j - 1] + count[j];
            //将桶中的记录放到temp中
            for (int j = n - 1; j >= 0; j--) {
                k = (a[j] / radix) % 10;
                temp[count[k] - 1] = a[j];
                count[k]--;
            }

            //将temp中的数据放回原数组中
            for (int j = 0; j < n; ++j)
                a[j] = temp[j];
            radix *= 10;
        }

    }

    void test() {
        ps_int(a, 10);
//        bubble_sort_1(a, 10);
//        insert_sort_1(a, 10);
//        select_sort_1(a, 10);
//        shell_sort_1(a, 10);
//        quick_sort_1(a, 0, 10);
//        insert_b_sort_1(a, 10);
//        heap_sort_1(a, 10);
//        merge_sort_1(a, 0, 9);
        radix_sort_1(a, 10);
        ps_int(a, 10);
    }
}
