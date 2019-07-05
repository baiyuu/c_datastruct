
#include <iostream>

using namespace std;

/*
 * create
 * destory
 * locateVex
 * getVex
 * putVex
 * firstAdjVex
 * nextAdjVex
 * insertVex
 * deleteVex
 * insertArc
 * deleteArc
 * dfs 深度优先遍历
 * hfs 广度优先遍历
 */

namespace Graph {

#define MAX 100
#define INIT -1
#define newEdge (EdgeNode *) malloc(sizeof(ENode))
    typedef char Vertex;
    typedef int Edge;


    int errMsg(string msg, int code = -1) {
        std::cout << msg << std::endl;
        return code;
    }

    typedef struct {
        Vertex vexs[MAX];
        Edge arc[MAX][MAX];
        int vNum, eNum;
    } m_graph;

    /*
     * 创建图
     * O(n+n^2+eNum)
     * 其中初始化边 O(n^2)
     * 
     */
    void createM_Graph(m_graph *g) {
        //初始化顶点的信息
        for (int i = 0; i < g->vNum; i++) {
//            scanf(&g->vexs[i]);
            g->vexs[i] = i + 65;
        }
        //初始化边的信息
        for (int j = 0; j < g->eNum; j++)
            for (int i = 0; i < g->eNum; i++)
                g->arc[j][i] = INIT;

        //设置边的信息
        int col, row, w;
        for (int k = 0; k < g->eNum; k++) {
            //此处设置行列 和权值
            scanf("%d %d %d", &col, &row, &w);
            g->arc[col][row] = w;
            g->arc[row][col] = w;

        }
    }


    typedef struct ENode {
        int adj;//属于哪一个顶点
        Edge weight;//权值
        struct ENode *link;//下一条边
    } EdgeNode;


    typedef struct VNode {
        Vertex data;//顶点的数据
        EdgeNode *elink;//顶点的第一条边
    } VertexNode, AdjList[MAX];

    typedef struct {
        AdjList adjList;
        int vNum, eNum;
    } graph;


    void create(graph *g) {
        //输入顶点数和边数
        scanf("%d %d", &g->vNum, &g->eNum);
        //建立顶点表
        for (int i = 0; i < g->vNum; i++) {
            scanf("%d", &g->adjList[i].data);
            g->adjList[i].elink = nullptr;
        }

        //建立边表
        int col, row, w;
        EdgeNode *e;
        for (int j = 0; j < g->eNum; j++) {
            scanf("%d %d %d", &col, &row, &w);
            //无向图的头插法，每条边对应两个顶点
            e = newEdge;

            e->adj = row;
            e->link = g->adjList[col].elink;
            g->adjList[col].elink = e;

            e = newEdge;
            e->adj = col;
            e->link = g->adjList[row].elink;
            g->adjList[row].elink = e;

        }
    }

    int visited[MAX];


    /*
     * 邻阶矩阵 depth_first_search
     *      将对应顶点 标记数组置为已访问，对这个顶点做一些操作，
     *      循环顶点数组，如果这个顶点的边存在且未被访问过，执行dfs
     */
    void m_dfs(m_graph g, int i) {
        visited[i] = 1;
        printf("打印顶点信息 :%d", g.vexs[i]);

        for (int j = 0; j < g.vNum; j++)
            //边上顶点存在且 未被访问过
            if (g.arc[i][j] == 1 && visited[j] == 0)
                m_dfs(g, j);

    }

    void m_dfsTraverse(m_graph g) {
        //初始化标记数组
        for (int i = 0; i < g.vNum; i++)
            visited[i] = 0;

        //遍历
        for (int j = 0; j < g.vNum; j++)
            if (visited[j] == 0)
                m_dfs(g, j);
    }

    void bfs2(graph g, int i) {
        visited[i] = 1;
//        printf("%d", g.vexs[i]);
//        for (int j = 0; j < g.vNum; j++)
//            if (g.arc[i][j == 1 && visited[j] == 0])
//                bfs2(g, j);

        EdgeNode *e;
        printf("%d", g.adjList[i].data);
        e = g.adjList[i].elink;
        while (e) {
            for (int j = 0; j < g.vNum; j++) {
                if (visited[j] == 0) {
                    bfs2(g, e->adj);
                }
            }
        }

    }


    /**
     * 邻接表 dfs
     *      将标记数组置为已访问，对这个顶点做一些操作
     *      之后看这个顶点的下一条边，如果边结点存在且未被访问，执行dfs
     */
    void dfs(graph g, int i) {
        EdgeNode *e;
        visited[i] = 1;
        printf("%d", g.adjList[i].data);
        e = g.adjList[i].elink;
        while (e) {
            if (visited[e->adj] == 0)
                dfs(g, e->adj);

            e = e->link;
        }
    }

    void dfsTreverse(graph g) {
        //初始化标记数组
        for (int i = 0; i < g.vNum; i++)
            visited[i] = 0;

        for (int j = 0; j < g.vNum; j++)
            if (visited[j] == 0)
                dfs(g, j);

    }

    /*
     * breadth_first_search
     */
    void m_bfs(m_graph g) {
        //重置标记数组
        for (int i = 0; i < g.vNum; i++)
            visited[i] = 0;

        SqQueue::SqQueue q;
        SqQueue::init(&q);

        for (int j = 0; j < g.vNum; j++) {
            if (visited[j] == 0) {
                visited[j] = 1;//标记为 已访问
                printf("%d", g.vexs[j]);//对顶点执行操作
                SqQueue::insert(&q, j);
                while (SqQueue::size(q) > 0) {//队列不为空
                    SqQueue::get(&q, &j);
                    for (int i = 0; i < g.vNum; i++) {
                        if (g.arc[j][i] == 1 && visited[i] == 0) {
                            visited[i] = 1;
                            printf("%d", g.vexs[i]);//对顶点执行操作
                            SqQueue::insert(&q, i);
                        }
                    }
                }
            }
        }
    }


    void bfs(graph g) {
        EdgeNode *e;
        SqQueue::SqQueue q;
        SqQueue::init(&q);
        for (int i = 0; i < g.vNum; i++)
            visited[i] = 0;

        for (int i = 0; i < g.vNum; i++) {
            if (visited[i] == 0) {
                visited[i] = 1;
                printf("%d", g.adjList[i].data);
                SqQueue::insert(&q, i);
                while (SqQueue::size(q) > 0) {//队列不为空
                    SqQueue::get(&q, &i);
                    e = g.adjList[i].elink;
                    while (e) {
                        if (visited[e->adj] == 0) {
                            visited[e->adj] == 1;
                            printf("%d", g.adjList[e->adj].data);
                            SqQueue::insert(&q, e->adj);
                        }
                        e = e->link;
                    }
                }
            }
        }


    }

    /***************************最短路径*******************************/
    typedef int Pathmatirx[MAX];        //存储最短路径的前驱结点下标
    typedef int ShortPathTable[MAX];    //存储当前顶点到各点最短路径的权值

    /**
     * 迪杰斯拉 
     * @param g 
     */
    void shortestPath_Dijkstra(m_graph g, int v0, Pathmatirx *p, ShortPathTable *d) {
        int min, k, v, w;

        int final[MAX]; //final[w]=1,表示v_0到v_w的最短路径 ，标记顶点是否参与过比较

        for (v = 0; v < g.vNum; v++) {
            final[v] = 0;//全部顶点初始化为未知
            (*d)[v] = g.arc[v0][v];//将与v0有连线的顶点加上权值
            (*p)[v] = 0;//初始化路径数组置为0
        }

        (*d)[v0] = 0;// v0到v0的路径为0
        final[v0] = 1;//v0到v0不计算路径
        for (v = 1; v < g.vNum; v++) {
            min = MAX;
            for (w = 0; w < g.vNum; w++) {
                //if (final[w]==0 && (*d)[w] < min) {
                if (!final[w] && (*d)[w] < min) {
                    k = w;
                    min = (*d)[w];
                }
            }
            final[k] = 1;
            for (w = 0; w < g.vNum; w++) {//修正当前最短路径
                //如果经过v顶点的路径比现在这条路径的长度短的话
                if (!final[w] && (min + g.arc[k][w]) < (*d)[w]) {
                    //修改table[w]和p[w]
                    (*d)[w] = min + g.arc[k][w];//修改当前路径长度
                    (*p)[w] = k;
                }
            }
        }

    }


    void run() {

    }
}
