#include <stdio.h>
#include <limits.h>
#include <malloc.h>

#define MAXVALUE INT_MAX
#define MAXVNUM 100
/*
 * 邻接表存储方法
 */

typedef int Vertex;
//边的数据结构
typedef struct Edge {
    int adjvex;  //这条边的终止顶点在顶点节点中的位置
    int weight;//边的权值
    struct Edge *next;//指向的下一个边节点
} ELink;

//顶点的数据信息
typedef struct ver {
    Vertex vertex;//顶点的数据信息
    ELink *link;//指向第一条边节点
} VLink;

int main() {
    test();
    return 0;
}

test() {

}

/*
 * 依次输入带权有向图的n个顶点，
 * i 表示第 i 个顶点，e 表示边的顶点偶对
 * 创建邻接表
 */
void create(VLink v[], int n, int e) {
    int k, vi, vj, weight;
    ELink *p, *q;
    //创建 n 个顶点
    for (k = 0; k < n; k++) {
        v[k].vertex = k + 1;
        v[k].link = NULL;
    }

    for (k = 0; k < n; k++) {
        scanf("i=%d,j=%d,weight=%d", &vi, &vj, &weight);//输入顶点偶对  权值
//        (vi,vj)表示一个顶点偶对  比如顶点1和顶点4，
        p = (ELink *) malloc(sizeof(ELink)); //创建一个边节点
        p->adjvex = vj - 1;//边节点终止的顶点在顶点数组中的索引
        p->weight = weight;
        p->next = NULL;

        if (!v[vi - 1].link) {//如果只有头结点，没有边节点，这几个节点就是边节点
            v[vi - 1].link = p;
        } else {//找到最后一个边节点，
            q = v[vi - 1].link;
            while (q->next) {
                q = q->next;
            }
            q->next = p;//把新添加的p节点挂在后面
        }
    }
}

/**
 * 删除邻接表中 数据信息为 item 的顶点
 * @param v 邻接表数组 
 * @param n 邻接表数组长度 
 * @param item  需要删除的数据顶点
 */
void delete(VLink v[], int n, Vertex item) {
    ELink *p, *q, *r;
    int i, k = -1;
    for (i = 0; i < n; i++) {
        if (v[i].vertex == item) {
            k = i;  //满足条件的顶点在数组中的位置
            break;
        }
    }
    //删除该顶点 以及 与之相关的边 并修改相关边节点的adjvex的值
    if (k != -1) {
        p = v[k].link;
        for (i = k + 1; i < n; i++) {
            v[i - 1].vertex = v[i].vertex;  //将删除节点的内容向前移动一位
            v[i - 1].link = v[i].link;
        }
        //此时数组中 v[n-1] v[n-2]的节点中内容相容 ，删除最后一个v[n-1]
        n--;  //将数组长度减少 1

        //释放p
        while (p != NULL) {
            r = p;
            p = p->next;
            free(r);
        }
        for (i = 0; i < n; i++) {
            p = v[i].link;
            while (p != NULL) {
                if (p->adjvex == k) {  //如果边节点中 有顶点为k（被删除的节点）的边节点，将其释放
                    if (v[i].link == p) {
                        v[i].link = p->next;//删除 p 所指的边节点
                    } else {
                        q->next = p->next;//删除 p 所指的边节点
                    }
                    r = p;
                    p = p->next;
                    free(r);//释放 p
                } else {
                    if (p->adjvex > k) {  //被删除节点之后的顶点的边节点，将其顶点索引向前移动一位
                        p->adjvex--;
                    }
                    q = p;
                    p = p->next;
                }
            }
        }
    }
}

/**
 *  图的深度优先搜索 start 
 *      
 *      创建一个标记数组，记录图中的某个顶点是否被访问过
 *      从一个未访问的节点出发，依次访问这个节点上未被访问过的的邻接顶点，访问并标记
 *      完成一次后，若还有未访问的，则从一个未访问的节点出发，再次进行
 *      
 *  时间复杂度 O（n*n） n 为邻接矩阵的阶数 
 *  时间复杂度 O（e） e为邻接表的边数 
 */
int visited[];

//搜索方法
void travel_dfs(VLink v[], int n) {
    int i;
    for (int i = 0; i < n; i++)
        visited[i] = 0;//标记数组初始化

    for (i = 0; i < n; i++)
        if (visited[i] == 0)
            dfs(v, i);
}

//深度优先搜索的递归方式遍历
void dfs(VLink v[], int n) {
    int w; //邻接表中某个顶点的边节点的顶点索引
    visit(n);
    visited[n] = 1;
    w = firstAdj(v, n);
    while (w != -1) {
        if (visited[w] == 0) {// 有没有被访问过
            dfs(v, w);
        }
        w = nextAdj(v, n);//顶点数组中某一个顶点
    }
}

//求v的第一个邻接点 ，没有返回-1
int firstAdj(VLink v[], int n) {
    return -1;
}

//求v的下一个邻接点 ，没有返回-1
int nextAdj(VLink v[], int n) {
    return -1;
}

//访问边节点的方法
void visit(int v) {

}

/**
 *  图的深度优先搜索 end 
 */
//------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
/**
 *  图的广度优先搜索 start 
 *  
 *  
 *  从指定顶点出发，依次访问未被访问过的邻接顶点，
 *  然后在从这些邻接顶点出发，依次访问未被访问过的邻接顶点
 *  直到图中的所有节点都被访问过；
 *  若一条线走完还存在未访问过的节点，
 *  选择一个未访问节点重复上述操作
 *  
 *  从一个顶点出发，访问这个顶点的邻接点，在从这个顶点的邻接点出发重复执行
 *  
 */
VLink stack[];

void travel_bfs(VLink v[], int n) {
    for (int i = 0; i < n; i++)
        visited[i] = 0;
    
    for (int j = 0; j < n; j++)
        if (visited[j] == 0)
            bfs(v, j);
    
}

void bfs(VLink v[], int n) {
    int w;
    visit(n);//访问顶点
    visited[n] = 1;//标记
    addq(stack, n);//入队
    while (!emptyStack(stack)) {
        n = delq(stack);//出队
        w = firstAdj(v, n);//访问第一个邻接点
        while (w != -1) {
            if (visited[w] == 0) {//未访问过的节点
                visit(w);
                addq(stack, w);
                visited[w] = 1;
            }
            w = nextAdj(v, n);
        }
    }

}

int addq(VLink stack[], int n) {
    return 1;
}

int delq(VLink stack[]) {
    return 1;
}

int emptyStack(VLink stack[]) {
    return 1;
}

/**
 *  图的广度优先搜索 end 
 */