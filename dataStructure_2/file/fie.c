


#include <stdio.h>

int binarySearch_2(int a[], int low, int high, int k) {

    if (low > high) {
        return -1;
    }

    int mid = (low + high) / 2;
    if (a[mid] == k) {
        return mid;
    }
    if (a[mid] < k) {
        return binarySearch_2(a, mid + 1, high, k);
    } else {
        return binarySearch_2(a, low, mid - 1, k);
    }


}

int binarySearch_1(int a[], int n, int k) {
    int low = 1, high = n, mid;

    while (low <= high) {
        mid = (low + high) / 2;
        if (a[mid] == k) {
            return mid;
        }
        if (a[mid] < k) {
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    return -1;

}

runff() {
    int a[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int s = binarySearch_1(a, 10, 6);
    int s2 = binarySearch_2(a, 0, 9, 6);
    printf("%d --%d\n", s, a[s]);
    printf("%d --%d", s2, a[s2]);
}

