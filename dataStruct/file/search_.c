


#include <stdio.h>

typedef int DataType;

/*
 * 连续顺序文件查找
 */
int main() {
    test();
    return 0;
}

test() {
    DataType dt[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
//    int i = binarySearch(dt, 9, 8);
    int i = binarySearch_2(dt, 1, 9, 5);
    printf("%d", i);
}

int binarySearch(DataType dt[], int n, DataType data) {
// 1 2 3 4 5  6 7 8 9
    int start = 1, end = n, mid = 0;
    while (start <= end) {
        mid = (start + end) / 2;
        if (dt[mid] == data) {
            return mid;
        }
        if (dt[mid] < data) {
            start = mid + 1;
        } else {
            end = mid - 1;
        }
    }
    return 0;
}

/**
 * 递归 （折半）二分查找
 * @param dt 
 * @param low 
 * @param high 
 * @param data 
 * @return 
 */
int binarySearch_2(DataType dt[], int low, int high, DataType data) {
    int mid = 0;
    if (low > high) {
        return 0;
    } else {
        mid = (low + high) / 2;
        if (dt[mid] == data) {
            return mid;
        }
        if (dt[mid] > data) {
            return binarySearch_2(dt, low, mid - 1, data);
        } else {
            return binarySearch_2(dt, mid + 1, high, data);
        }
    }
}


