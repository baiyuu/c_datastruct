
#include <iostream>

using namespace std;

namespace g_3 {
#define  g_size_3 10

    typedef struct arcNode {
        struct arcNode *next;
        int weight;
        int vertex;
    } arc;

    typedef struct VNode {
        int data;
        arc *arc;
    } graph;

//    VNode g[g_size_3];

    int create(int n, graph *g) {
        arc a1, a2;

        //初始化顶点
        for (int i = 0; i < n; i++) {
            g[i].data = i;
            g[i].arc = nullptr;
        }

        int col, row;
//        scanf("%d %d", &col, &row);
        for (int i = 0; i < n; i++) {

        }
    }

    int visited[g_size_3];

    void dfs(graph *g, int v) {
        visited[v] = 1;
        printf("%d", g[v].data);
        for (int i = 0; i < g_size_3; i++)
            if (!visited[i])
                dfs(g, i);
    }

    void dfs_traverse(graph *g) {
        for (int i = 0; i < g_size_3; i++)
            visited[i] = 0;

        for (int j = 0; j < g_size_3; j++)
            if (!visited[j])
                dfs(g, j);
    }


    void bfs(graph *g, int v) {
        visited[v] = 1;
        arc *a;

        a = g[v].arc;
        while (a)
            for (int i = 0; i < g_size_3; i++)
                if (!visited[i])
                    bfs(g, a->vertex);

                
    }

    
    
    

}

namespace graph_3 {

    void test() {

    }
}