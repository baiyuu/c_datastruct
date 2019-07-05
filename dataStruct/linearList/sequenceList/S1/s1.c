#include <stdio.h>

#define  MAXSIZE 1000;
typedef int Element;
Element a[1000];
int n;

void insert(int *a, int size, int ele, int index);

int *delete(int *a, int size, int i);

int locate(int *a, int size, int ele);

void removeRepeat(int *a, int size);

void selectSort(int *a, int size);

void insertMid(int *a, int size, int e);

printArr(int *a, int size);

#include<stdio.h>
#include <mem.h>
#include <malloc.h>
#include <stdbool.h>


int main() {
    int a[20] = {1, 2, 3, 4, 6, 7, 8};
    printArr(&a, sizeof(a) / sizeof(a[0]));
//    insert(&a, sizeof(a) / sizeof(a[0]), 333, 2);
//    int *p2 = delete(&a, sizeof(a) / sizeof(a[0]), 4);
//    printArr(p2, 6);
//    int find = locate(&a, sizeof(a) / sizeof(a[0]), 13);
//    printf("%d", find);
//    removeRepeat(&a, sizeof(a) / sizeof(a[0]));
//    selectSort(&a, sizeof(a) / sizeof(a[0]));
    insertMid(&a, sizeof(a) / sizeof(a[0]), 5);

    printArr(&a, sizeof(a) / sizeof(a[0]));
    return 0;
}


/**
 * 1.是否超出数组最大范围
 * 2.插入位置是否正确 <0 >size
 * 3.插入元素
 * 4.之后的元素后移一位
 * @param a 
 * @param size 
 * @param ele 
 * @param index 
 */
void insert(Element a[], int size, Element ele, int index) {
    if (index < 0 || index > size - 1) {
        puts("index error insert fail");
    }
    //从数组的最后一个开始，到插入元素的位置，每一个元素向后移动一位
    for (int i = size - 1; i > index - 1; i--) {
        a[i + 1] = a[i];
    }
    a[index - 1] = ele;
}


int *delete(int *a, int size, int i) {
    if (i < 0 || i > size - 1) {
        puts("delete error delete fail");
    }
    a[i] = 0;
    for (int j = i; j < size - 1; j++) {
        a[j] = a[j + 1];
    }
    a[size - 1] = NULL;
    int s = --size;
    int *a2;
    a2 = (int *) malloc(sizeof(int) * s);
    for (int k = 0; k < s; k++) {
        a2[k] = *(a + k);
    }
    return a2;
}

int locate(int *a, int size, int ele) {
    for (int i = 0; i < size; i++) {
        if (a[i] == ele) {
            return i;
        }
    }
    return -1;
}


void removeRepeat(int *a, int size) {
    for (int i = 0; i < size; ++i) {
        for (int j = i + 1; j < size; ++j) {
            if (a[i] == a[j]) {
                delete(a, size, j);
            }
        }
    }
}

void selectSort(int *a, int size) {
    Element e;
    int d;
    for (int i = 0; i < size; i++) {
        d = i;
        for (int j = i + 1; j < size; j++) {
            if (a[d] > a[j]) {
                d = j;
            }

            if (d != i) {
                e = a[d];
                a[d] = a[i];
                a[i] = e;
            }

        }

    }
}

void insertMid(int *a, int size, int e) {


    if (e > a[size - 1]) {
        a[size - 1] = e;
    }

    for (int i = 0; i < size; i++) {
        if (a[i] < e && a[i + 1] > e) {
            a[i + 1] = e;
        }

    }
}

printArr(int *a, int size) {
    for (int i = 0; i < size; ++i) {
        printf("%d\t", a[i]);
    }
    printf("\n");
}

    


