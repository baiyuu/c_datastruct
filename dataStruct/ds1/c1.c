

#include <stdio.h>

int c2(int m, int n);

int main() {
    c2(7, 10);
    return 0;
}

/*
 * 公鸡5元一只，母鸡3元一只，小鸡1元3只
 * 100元买几只鸡
 */
c1() {
    int z;
    for (int i = 1; i <= 20; i++) {
        for (int j = 1; j <= 33; j++) {
            z = 100 - j - i;
            if (5 * i + j * 3 + z / 3 == 100) {
                printf("gong:%d mu:%d xioa:%d\n", i, j, z);
            }
        }
    }
}

/*
 * m n 的最大公因子  
 */
int c2(int m, int n) {
    int r = 0;
    for (;;) {
        r = m % n;
        if (r == 0) {
            printf("gongyin zi :%d", n);
            return n;
        }

        m = n;
        n = r;
    }
}

 