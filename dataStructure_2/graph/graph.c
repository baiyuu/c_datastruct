
/**
 * 图
 */



#include <stdio.h>
#include <malloc.h>

typedef int Vertex;
typedef struct edge {
    int weight;
    int adj;//终止节点指向
    struct edge *next;
} Elink;

typedef struct ver {
    Vertex vertex;
    Elink *elink;
} VLink;


/**
 * 在 n 个顶点的图中删除 数据信息为 item的顶点
 * @param v 
 * @param n 
 * @param item 
 */
void deleteAdjLink(VLink v[], int n, Vertex item) {

    int k = -1;//找出要删除顶点在 顶点数组 中的位置

    for (int i = 0; i < n; i++) {
        if (v[i].vertex = item) {
            k = i;
            break;
        }
    }

    /*
     * 0.删除 该顶点的所有边
     * 1 顶点数组 向前移动
     * 2 有被删除边的 边节点需要断开
     * 
     */
    Elink *p, *q, *r;
    if (k != -1) {
        //顶点数组向前移动一位
        p = v[k].elink;
        for (int i = k + 1; i < n; i++) {
            v[i - 1].elink = v[i].elink;
            v[i - 1].vertex = v[i].vertex;
        }
        n--;//顶点数组长度 -1

        //释放该节点的边
        while (p != NULL) {
            r = p;
            p = p->next;
            free(r);
        }

        //释放 与 被删除节点 有关系的 边
        for (int j = 0; j < n; j++) {
            p = v[j].elink;
            while (p != NULL) {
                if (p->adj == k) { //与删除结点之间 有 边
                    if (v[j].elink == p) {//如果当前节点的第一条边 就是与 删除节点相连的
                        v[j].elink = p->next;//直接指向下一个
                    } else {
                        q->next = p->next;//q是指向p 上一个节点的指针， 把p跳过
                    }
                    r = p;
                    p = p->next;
                    free(r);
                } else {
                    if (p->adj > k) {
                        p->adj--;//顶点数组向前移动了一位
                    }
                    q = p;//
                    p = p->next;
                }
            }
        }
    }
}

/**
 * 带权有向图 n个顶点  e条边     
 * @param v 
 * @param n 
 * @param e 
 */
void createAdjLink(VLink v[], int n, int e) {
    //建立 n 个邻接顶点
    for (int i = 0; i < n; i++) {
        v[i].vertex = i + 1;
        v[i].elink = NULL;
    }
    int a, b, w;
    Elink *p, *q;
    for (int j = 0; j < e; j++) {
        scanf("%d %d %d", &a, &b, &w);
        p = (Elink *) malloc(sizeof(Elink));
        p->adj = b - 1; //指向哪条边 
        p->weight = w;
        p->next = NULL;
        if (!v[a - 1].elink) { //从哪条边出发
            v[a - 1].elink = p;
        } else {
            q = v[a - 1].elink;
            while (q->next) {
                q = q->next;
            }
            q->next = p;
        }


    }

}

#define MAXVALUE 1000
#define MAXV 1000

/**
 * 创建一个邻接矩阵 的图
 * @param v 
 * @param n 
 * @param e 
 */
void createsAdj(int v[][MAXV], int n, int e) {
    //对矩阵中每一个分量进行 初始化
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            v[i][j] = MAXVALUE;
        }
    }
    //为每一个 顶点的边赋 权值
    int a, b, w;
    for (int k = 0; k < e; k++) {
        scanf("%d %d %d", &a, &b, &w);
        v[a][b] = w;
        v[b][a] = w;
    }

}

/*
 * 图的遍历
 */

void visitAdj(int v) {

}

int firstAjd(VLink v[], int n) {

}

int nextAjd(VLink v[], int n) {

}

int visited[MAXVALUE];//标记数组


/**
 * dfs 算法
 * @param v 
 * @param n 访问的邻接顶点的索引 
 */
void dfs(VLink v[], int n) {
    int w;
    visitAdj(n);
    visited[n] = 1;//以访问
    w = firstAjd(v, n);
    while (w != -1)
        if (visited[w] == 0) {
            dfs(v, w);
            w = nextAjd(v, n);
        }
}

/**
 * 深度优先遍历 主要方法 
 * @param v 
 * @param visite 
 * @param n 
 */
void travel_dfs(VLink v[], int visite[], int n) {
    for (int i = 0; i < n; i++)
        visite[i] = 0;
    for (int j = 0; j < n; j++)
        if (visite[j] == 0)
            dfs(v, j);
}


/*
 *广度 优先遍历 
 */
typedef int Queue;

void adjQueue(Queue q, int n) {

}

int emptyAdgQueue(Queue q) {

}

int delQ(Queue q) {

}

Queue q;

void bfs(VLink v[], int n) {
    int w;
    visitAdj(n);
    visited[n] = 1;
    adjQueue(q, n);
    while (!emptyAdgQueue(q)) {
        n = delQ(q);
        w = firstAjd(v, n);
        while (w != -1) {
            if (visited[w] == 0) {
                visitAdj(w);
                adjQueue(q, w);
                visited[w] = 1;
            }
            w = nextAjd(v, n);
        }
    }
}

void tarvel_bfs(VLink v[], int visite[], int n) {
    for (int i = 0; i < n; i++) {
        visite[i] = 0;
    }
    for (int j = 0; j < n; j++) {
        if (visite[j] == 0) {
            bfs(v, j);
        }
    }

}

rungg() {

}

