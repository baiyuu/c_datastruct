

/*
 * 邻接矩阵
 * 一个一维数组  vertex[n]   表示元素
 * 二维数组  arr[n][n] 表示 两个元素之间是否有 度
 *  无向图是一个n阶矩阵 ，内容为对角矩阵 
 *  有向图是一个稀疏图    
 */


#include <limits.h>
#include <stdio.h>

#define MAXVALUE INT_MAX
#define MAXVNUM 100

int main() {

    return 0;
}
/**
 * 
 * @param a  
 * @param n 阶矩阵
 * @param e 表示边的顶点偶对  多少对
 */
void createAdjGraph(int a[][MAXVNUM], int n, int e) {
    int i, j, k, weight;
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            a[i][j]=MAXVALUE;
        }
    }
    
    for (k = 0; k <e ; k++) {
        scanf("i=%d,j=%d,weight=%d",&i,&j,&weight);//输入顶点偶对  权值
        a[i][j]=weight;
        a[j][i]=weight;
    }
    
}