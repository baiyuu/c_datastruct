#include <iostream>
#include "d_1/run.h"
#include "d_2/run.h"
#include "d_3/run_3.h"


int errCode(string msg, int code = -1) {
    std::cout << msg << std::endl;
    return code;
}

void ps_int(int *a, int n) {
    for (int i = 0; i < n; i++)
        printf("%d\t", a[i]);
    puts("");
}

int main() {
//    ds_1::run();//大话数据结构
//    ds_22::run();//啊哈！算法
    ds_3::run();//妙趣横生的算法
    return 0;
}