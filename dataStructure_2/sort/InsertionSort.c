


#include <stdio.h>

void syso(int a[], int n) {
    puts("");
    for (int i = 0; i < n; i++) {
        printf("%d\t", a[i]);
    }
    puts("");
}

void sort(int a[], int n) {
    syso(a, n);
    int t;
    for (int i = 1; i < n; i++) {
        for (int j = 0; j < i; j++) {
            if (a[j] > a[i]) {
                t = a[i];
                a[i] = a[j];
                a[j] = t;
            }
        }
    }
    syso(a, n);

}


void insertSort_binarySearch_4(int a[], int n) {
    for (int i = 1; i < n; i++) {
        int t = a[i];
        int low = 0;
        int h = i - 1;
        while (low <= h) {
            int mid = (low + h) / 2;
            if (a[mid] > t)
                h = mid - 1;
            else
                low = mid + 1;
        }

        for (int j = i - 1; j >= low; j--)
            a[j + 1] = a[j];
        a[low] = t;

    }
    syso(a, n);
}

void insertSort_binarySearch_3(int a[], int n) {

    int i, j, t, low, high, mid;
    for (i = 1; i < n; i++) {
        t = a[i];
        low = 0;
        high = i - 1;
        while (low <= high) {
            mid = (low + high) / 2;
            if (t < a[mid]) {
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        for (j = i - 1; j >= low; j--) {
            a[j + 1] = a[j];
        }
        a[low] = t;
    }
    syso(a, n);
}

void insertSort_2(int a[], int n) {
    for (int i = 1; i < n; i++) {
        int t = a[i];
        int j = i - 1;
        for (; j >= 0 && a[j] > t; j--) {
            a[j + 1] = a[j];
        }
        a[j + 1] = t;
    }

    syso(a, n);
}

void insertSort_1(int a[], int n) {

    for (int i = 1; i < n; i++) {
        int j = i - 1;
        int t = a[i];
        while (j >= 0 && a[j] < t) {
            a[j + 1] = a[j--];
        }
        a[j + 1] = t;
    }
    syso(a, n);
}

void selectSort_1(int a[], int n) {
    int d, t;
    for (int i = 0; i < n; i++) {
        d = i;

        for (int j = i + 1; j < n; j++)
            if (a[d] < a[j])
                d = j;

        if (d != i) {
            t = a[i];
            a[i] = a[d];
            a[d] = t;
        }

    }
    syso(a, n);
}

void bubbleSort_1(int a[], int n) {
    int t;
    for (int i = 1; i < n; i++) {
        for (int j = 0; j < i; j++) {
            if (a[j] > a[i]) {
                t = a[i];
                a[i] = a[j];
                a[j] = t;
            }
        }
    }
    syso(a, n);
}

//二版书中 问题代码
void bubbleSort_2(int a[], int n) {
    int i, j, f, t;
    i = n - 1;
    while (i > 0 && f == 1) {
        f = 0;
        for (j = 1; j <= i; j++) {
            if (a[j] > a[j + 1]) {
                t = a[j];
                a[j] = a[j + 1];
                a[j + 1] = t;
                f = 1;
            }
        }
        i--;
    }
    syso(a, n);
}

void shellSort_1(int a[], int n) {
    int j, f, g = n, t;
    while (g > 1) {
        g /= 2;
        do {
            f = 0;
            for (int i = 0; i < n - g; i++) {
                j = i + g;
                if (a[i] > a[j]) {
                    t = a[i];
                    a[i] = a[j];
                    a[j] = t;
                    f = 1;
                }
            }
        } while (f != 0);
    }
    syso(a, n);
}

void shellSort_2(int a[], int n) {
    int f, g = n, t, j;
    while (g > 1) {
        g /= 2;
        do {
            f = 0;
            for (int i = 0; i < n - g; i++) {
                j = i + g; //6 7 8 9 10
                if (a[i] > a[j]) { //
                    t = a[i];
                    a[i] = a[j];
                    a[j] = t;
                    f = 1;
                }
            }
        } while (f == 1);
    }
    syso(a, n);
}

void sort_1(int a[], int n) {
    int t;
    int d;
    for (int i = 1; i < n; i++) {
        t = a[i];
        int j = i - 1;
        while (j >= 0 && a[j] > t) {
            a[j + 1] = a[j--];
        }
        a[j + 1] = t;
    }
    syso(a, n);
}


qqq() {
    int a = 4;
    if (a == 1) {
        a == 4;
        puts("aaaaa");
    } else if (a == 4) {
        a == 5;
        puts("sssss");
    }
}

run456465() {
    int a[] = {52, 7, 1, 23, 55, 3, 34, 66, 24, 87};
    int n = sizeof(a) / sizeof(int);
//    syso(a, n);
//    bubbleSort_1(a, n);
    qqq();
}



/*
 * 1. 冒泡排序
 *      循环两次，外层循环从 1--i  开始 正常循环，内层循环从 0 -- i，比较第 i 个元素的前面i-1个元素是否都是比第 i 个 小 
 *      for(int i = 1;i<n;i++){
 *          for(int j =0; j  <i ;j++){
 *              if(a[j]>a[i]){
 *                  第 i 个元素 前面有比它大的，需要进行交换
 *              }
 *          }
 *      }
 * 2. 选择排序
 *     两层循环，外层循环从0开始正常循环 ，定义变量d记录当前索引
 *      内层循环从 i+1 开始循环，找到第 i 个元素后面最小的一个元素，将最小值的索引赋值给d
 *      比较d 是不是i 如果是，表示a[i]=a[d] 是当前最小的元素，不用交换，
 *                  如果不是，表示 a[d] 比 a[i]小，a[i]后面有比它小的元素，此时需要交换
 *      int d;
 *      for(int i=0;i<ni++){
 *          d=i;
 *          for(int j = i+1;j<n;j++){
                if(a[j]<a[d]){
                    d=j; //找i后面最小的元素
                }
 *          }
 *          if(i!=d){
 *              //交换
 *          }
 *      }
 *      
 * 3. 插入排序
 *     两层循环，外层循环从 1 
 *     定义 t记录a[i], 
 *     j = i-1; 记录当前变量的前一个变量
 *     如果 j>0&&t<a[j] 当前变量比它前面的某个变量小，此时需要将它前面的变量向后移动一位 a[j+1]=a[j--]
 *     a[j+1]=t //j始终为i前面一个元素
 *     
 *     for(int i =1;i<ni++){
 *          int t = a[i];
 *          int j=i-1;
 *          while(j>0&&a[j]>t){
                a[j+1]=a[j--];
 *          }
 *          a[j+1]=t;
 *     }
 *     
 *     最少次数n-1,最多n(n-1)/2    O(n^2)
 *     
 *     折半插入排序
 *     定义  low high mid 
 *     两层循环
 *     外层循环从1开始
 *     low=0;high=i;
 *     当low<=high时，还未完成排序，mid=（low+high）/2
 *     
 *     
 *     
 *     
 */