
#include <iostream>

using namespace std;

int errCode(string, int);

int a2[] = {63, 157, 189, 51, 101, 47, 141, 121, 157, 156, 194, 117, 98, 139, 67, 133, 181, 13, 28, 109};
int a2_size = 20;
namespace BucketSort_2 {

    void bucket_sort_1(int *a, int n) {
        int book[200];
        for (int i = 0; i < 200; i++)
            book[i] = 0;

        for (int j = 0; j < a2_size; j++)
            book[a2[j]]++;

        for (int k = 0; k < 200; k++)
            for (int i = 0; i < book[k]; i++)
                printf("%d\t", k);

    }

    void bucket_sort_2(int *a, int n) {
        int book[1001];
        for (int i = 0; i <= 200; i++)
            book[i] = 0;

        for (int i = 0; i < n; i++)//循环读入n个数，并进行桶排序
        {
            book[a[i]]++; //进行计数，对编号为t的桶放一个小旗子
//            printf("%d\t%d\t\n", a[i], book[a[i]]);
        }
        for (int i = 200; i >= 0; i--) //依次判断编号1000~0的桶
            for (int j = 0; j < book[i]; j++) //出现了几次就将桶的编号打印几次
                printf("%d \t", i);

    }

    void test() {

        bucket_sort_1(a, 20);
//        bucket_sort_2(a2, 20);
    };

}

namespace Sort_2 {

    void run() {
        BucketSort_2::test();
    }
}
