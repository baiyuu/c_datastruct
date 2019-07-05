
#include <stdio.h>

typedef int ElementType;
#define MAXSIZE 1000

void print(ElementType e[], int n);

void runOrderList() {
    ElementType a[] = {7, 6, 5, 4, 3, 2, 1, 2, 1};
    int n = 9;
//    insert(a, n, 3, 15);
//    delete(a, n, 3);
//    printf("%d", find(a, 6, 6));
//    deleteRepeat(a, n);
//    sort(a, n);
//    deleteItem(a, n, 2);
//    deleteM(a, n);
}


/**
 * 问题方法
 * 2.2 长度为n，的线性表元素按大小非递减排序，删除表中相同数值的多余元素，时间复杂度为O(n)
 * @param a 
 * @param n 
 */
void deleteM(ElementType a[], int n) {
    print(a, n);
    int k = 0;
    if (n > 1) {
        for (int i = 0; i < n; i++) {
            if (a[i] != a[k]) {
                a[++k] = a[i];
            }
        }
        n + k + 1;
    }
    print(a, n);
}

/**
 * 2.1已知长度为n的线性表，删除数据为item的元素
 */
int deleteItem(ElementType a[], int n, ElementType item) {

    int k = -1;
    for (int i = 0; i < n; i++) {
        if (a[i] == item) {
            k++;
        } else {
            //如果前面有符合的，就把后面的元素向前移动了k+1位，
            //如果前面没有符合的，相当于执行了 a[i]=a[i];
            a[i - k - 1] = a[i];
        }
    }
    n = n - k - 1;//同上
    print(a, n);
}

int deleteItem2(ElementType a[], int n, ElementType item) {

    for (int i = 0; i < n; i++) {
        if (a[i] == item) {
            for (int j = i; j < n; j++) {
                a[j] = a[j + 1];
            }
        }
    }
    n--;
    print(a, n);
}


/**
 * 5. 排序
 * @param a 
 * @param n 
 */
void sort(ElementType a[], int n) {
    /*
     * 选择排序
     */
    int d;
    ElementType t;
    for (int k = 0; k < n; k++) {
        d = k;
        for (int i = k + 1; i < n; i++) {
//            if (a[i] < a[d]) {//正序
            if (a[i] > a[d]) { //逆序
                d = i;
            }
        }
        if (d != k) {
            t = a[d];
            a[d] = a[k];
            a[k] = t;
        }
    }

    /*
     * 冒泡排序
     */
//    int t;
//    //正序
//    for (int j = 0; j < n; j++) {
//        for (int i = 0; i < n; i++) {
//            if (a[i] > a[i + 1]) {
//                t = a[i + 1];
//                a[i + 1] = a[i];
//                a[i] = t;
//            }
//        }
//    }
//    //逆序
//    for (int i = 0; i < n; i++) {//外层循环控制排序趟数
//        for (int j = 0; j < n - i; j++) {//内层循环控制每一趟排序多少次
//            if (a[j] > a[j - 1]) {
//                t = a[j - 1];
//                a[j - 1] = a[j];
//                a[j] = t;
//            }
//        }
//    }
    print(a, n);
}

/**
 * 4. 删除表中重复的数据元素
 * @param a 
 * @param n 
 * @return 
 */
int deleteRepeat(ElementType a[], int n) {
    int i = 0;
    for (int j = 0; j < n; j++) {
        for (int k = j + 1; k < n; k++) {
            if (a[j] == a[k]) {
//                delete(a, n, j);
//                a[j] == 0;
                printf("%d\t%d\n", a[j], j);
            }
        }
    }
    print(a, n);
}

/**
 * 3. 确定元素e在线性表中的位置
 * @param a 
 * @param n 
 * @param e 
 * @return 
 */
int find(ElementType a[], int n, ElementType e) {
    for (int i = 0; i < n; i++) {
        if (a[i] == e) {
            return i;
        }
    }
    return -1;
}


/**
 * 2. 删除长度为n的线性表中第i个元素
 * @param a 
 * @param n 
 * @param i 
 * @return 
 */
int delete(ElementType a[], int n, int i) {
    if (i < 1 || i > n) {
        return -1;
    }
    for (int j = i; j < n; j++) {
        a[j - 1] = a[j];//删除的是第 i 个元素
//        a[j] = a[j +1];//删除的是索引为 i  的元素
    }
    n--;
//    print(a, n);
    return 1;
}


/**
 * 1.在长度为n的线性表中的第 i 个位置中插入一个元素
 * @param a 
 * @param n 
 * @param i 
 * @param e 
 */
int insert(ElementType a[], int n, int i, ElementType e) {

    if (i < 1 || i > n || n == MAXSIZE) {
        return -1;
    }

    for (int j = n - 1; j > i; j--) {
        a[j + 1] = a[j];
    }

    a[i - 1] = e;
    n++;
    print(a, n);
    return 1;
}


void print(ElementType e[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d\t", e[i]);
    }
    puts("");
};