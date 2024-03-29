#include <iostream>
//#include "d_1/run.h"
//#include "d_2/run.h"
//#include "d_3/run_3.h"
//#include "d_4/run.h"
//#include "d_5/r1/run.h"
//#include "d_5/r1/run_2.h"
//#include "d_5/r1/sort_5_2.h"
#include "d_5/r1/run_3.h"
#include "d_5/r4.h"


int errCode(string msg, int code = -1) {
    std::cout << msg << std::endl;
    return code;
}

void ps_int(int *a, int n) {
    if (n == 0)
        errCode("空数字表，无法遍历", 0);
    for (int i = 0; i < n; i++)
        printf("%d\t", a[i]);
    puts("");
}

int swap_(int *a, int *b) {
    int t = *a;
    *a = *b;
    *b = t;
}

void ps_char(int *a, int n) {
    if (n == 0)
        errCode("空字符表，无法遍历", 0);
    for (int i = 0; i < n; i++)
        printf("%c\t", a[i]);
    puts("");
}

int main() {
    try {
        //    ds_1::run();//大话数据结构
//    ds_22::run();//啊哈！算法
//    ds_3::run();//妙趣横生的算法
//    ds_4::test();//数据结构与算法分析
//    ds_5::test();//数据结构 one
//    ds_5_1::test();//数据结构 two
//    sort_5_2::test();
//        run_3::test();
        r4::test();
        return 0;
    } catch (...) {
        std::cout << "catch (...)" << std::endl;

    }

}