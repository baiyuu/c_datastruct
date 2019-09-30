#include  <iostream>

using namespace std;

void ps_int(int *, int);

void ps_char(int *, int);

int errCode(string, int);

int swap_(int *a, int *b);

#define SIZES 10
namespace sort_5_4 {

    void bubble_sort_1(int *a, int n) {
        int f = 1;
        for (int i = 0; i < n && f == 1; i++) {
            f = 0;
            for (int j = i; j < n; j++) {
                if (a[j] < a[i]) {
                    swap_(&a[j], &a[i]);
                    f = 1;
                }
            }
        }
    }

    int select_sort(int *a, int n) {
        int min;
        for (int i = 0; i < n; i++) {
            min = i;
            for (int j = i + 1; j < n; j++)
                if (a[j] < a[min])
                    min = j;
            if (min != i)
                swap_(&a[i], &a[min]);
        }
    }

    int insert_sort_1(int *a, int n) {
        int t, j;
        for (int i = 1; i < n; i++) {
            t = a[i];
            for (j = i - 1; j >= 0 && a[j] > t; j--)
                a[1 + j] = a[j];
            a[j + 1] = t;
        }
    }

    int insert_b_sort_2(int *a, int n) {
        int mid, low, high, t;
        for (int i = 0; i < n; i++) {
            t = a[i], low = 0, high = i - 1;
            while (low <= high) {
                mid = (low + high) / 2;
                if (t < a[mid])
                    high = mid - 1;
                else
                    low = mid + 1;
            }
            for (int j = i - 1; j >= low; j--)
                a[j + 1] = a[j];
            a[low] = t;
        }
    }

    int insert_b_sort_1(int *a, int n) {
        int mid, low, high, t;
        for (int i = 0; i < n; i++) {
            low = 0, high = i - 1, t = a[i];
            while (low <= high) {
                mid = (low + high) / 2;
//                if (t < a[mid])
//                    high = mid - 1;
//                else
//                    low = mid + 1;
                if (t < a[mid])
                    low = mid + 1;
                else
                    high = mid - 1;
            }

            for (int j = i - 1; j >= low; j--)
                a[j + 1] = a[j];
            a[low] = t;
        }
    }


    int shell_sort_1(int *a, int n, int gap = 2) {
        int g = n / gap, j, t;
        while (g > 0) {
            for (int i = g; i < n; i++) {
                t = a[i];
                for (j = i - g; j >= 0 && a[j] > t; j -= g) {
                    a[j + g] = a[j];
                }
                a[j + g] = t;
            }
            g /= gap;
        }
    }

    int partition_1(int *a, int left, int right) {
        int i = left, j = right;
        do {
            do i++; while (left < right && a[i] < a[left]);
            do j--; while (left < right && a[j] > a[left]);
            if (i < j) swap_(&a[i], &a[j]);
        } while (i < j);
        swap_(&a[j], &a[left]);
        return j;

    }

    int quick_sort_1(int *a, int low, int high) {
        if (low < high) {
            int p = partition_1(a, low, high);
            quick_sort_1(a, low, p - 1);
            quick_sort_1(a, p + 1, high);
        }
    }

    int adj_heap_2(int *a, int i, int n) {
        int t = a[i];
        for (int j = i * 2 + 1; j < n; j = j * 2 + 1) {
            if (j + 1 < n && a[j] < a[j + 1])
                j++;

            if (a[j] > t) {
                swap_(&a[j], &a[i]);
                i = j;
            } else
                break;
        }
    }

    int adj_heap_1(int *a, int i, int n) {
        int t = a[i];
        for (int j = i * 2 + 1; j < n; j = j * 2 + 1) {
            if (j + 1 < n && a[j] > a[j + 1])
                j++;
            if (a[j] < t) {
                swap_(&a[j], &a[i]);
                i = j;
            } else break;
        }
    }

    int heap_sort_1(int *a, int n) {
        for (int i = n / 2 - 1; i >= 0; i--)
            adj_heap_1(a, i, n);

        for (int j = n - 1; j >= 0; j--) {
            swap_(&a[j], &a[0]);
            adj_heap_1(a, 0, j);
        }
    }

    int merge_1(int *a, int mid, int low, int high) {
        int i = low, j = mid + 1, t[high - low];
        for (int k = low; k <= high; k++)
            t[k - low] = a[k];

        for (int k = low; k <= high; k++) {
            if (i > mid) {
                a[k] = t[j - low];
                j++;
            } else if (j > high) {
                a[k] = t[i - low];
                i++;
            } else if (t[i - low] > t[j - low]) {
                a[k] = t[j - low];
                j++;
            } else {
                a[k] = t[i - low];
                i++;
            }
        }

    }

    int merge_sort_1(int *a, int low, int high) {
        if (low < high) {
            int mid = (low + high) / 2;
            merge_sort_1(a, low, mid);
            merge_sort_1(a, mid + 1, high);
            merge_1(a, mid, low, high);
        }
    }

    void test() {
        int a[] = {12, 4, 16, 34, 6, 5, 8, 11, 38, 25};
        ps_int(a, 10);
//        bubble_sort_1(a, 10);
//        select_sort(a, 10);
//        insert_sort_1(a, 10);
//        insert_b_sort_1(a, 10);
//        shell_sort_1(a, 10);
//        quick_sort_1(a, 0, 10);
//        heap_sort_1(a, 10);
        merge_sort_1(a, 0, 9);
        ps_int(a, 10);
    }
}

namespace graph_5_4 {
    typedef struct {
        int arc[SIZES][SIZES];
        int vexs[SIZES];
        int vnum, anum;
    } m_graph;
    int visited[SIZES];

    int bfs_1(m_graph g) {
//        for (int i = 0; i < g.vnum; i++)
//            visited[i] = 0;
//        //InitQueue(Q);
//        for (int i = 0; i < g.vnum; i++) {
//            if (visited[i] == 0) {
//                visited[i] = 1;
//                //visit;
////                EnQueue(Q,i);
//                while (!isEmpty(Q)) {
//                    DnQueue(Q, i);
//                    for (int j = 0; j < g.vnum; j++) {
//                        if (visited[j] == 0 && g.arc[i][j] == 1) {
//                            visited[i]==1;
//                            visit;
//                            EnQueue(Q,i);
//                        }
//                    }
//                }
//            }
//        }
    }

    int bfs_2(m_graph g) {
        for (int i = 0; i < g.vnum; i++)
            visited[i] = 0;
//        InitQueue(Q);
//        for (int j = 0; j < g.vnum; j++) {
//            if (visited[j] == 0) {
//                visited[j] = 1;
//                visit;
//                EnQueue(Q, j);
//                while (!isEmptyQueue(Q)) {
//                    DeQueue(Q, j);
//                    for (int i = 0; i < g.vnum; i++) {
//                        if (visited[i] == 0 && g.arc[j][i] == 1) {
//                            visited[i] = 1;
//                            visit;
//                            EnQueu(Q, i);
//                        }
//                    }
//                }
//            }
//        }
    }

    int dfs(m_graph g, int v) {
        visited[v] = 1;
//        visit
        for (int i = 0; i < g.vnum; i++)
            if (visited[i] == 0)
                dfs(g, i);
    }

    int dfs_traverse(m_graph g) {
        for (int i = 0; i < g.vnum; i++)
            visited[i] = 0;

        for (int j = 0; j < g.vnum; j++) {
            if (visited[j] == 0)
                dfs(g, j);
        }
    }


    int prim_3(m_graph g) {
        int adjvex[g.vnum], dis[g.vnum], min, j, k;
        adjvex[0] = 0;
        dis[0] = 0;
        for (int i = 1; i < g.vnum; i++) {
            adjvex[i] = 0;
            dis[i] = g.arc[0][i];
        }

        for (int i = 1; i < g.vnum; i++) {
            min = INTMAX_MAX, j = 1, k = 0;
            while (j < g.vnum) {
                if (dis[j] != 0 && dis[j] < min) {
                    min = dis[j];
                    k = j;
                }
                j++;
//                visit(k);
                dis[k] = 0;
                for (int p = 1; p < g.vnum; p++) {
                    if (dis[p] != 0 && g.arc[k][p] < dis[p]) {
                        dis[p] = g.arc[k][p];
                        adjvex[p] = k;
                    }
                }
            }
        }
    }

    int prim_1(m_graph g) {
        int adjvex[g.vnum], dis[g.vnum], min, j, k;
        adjvex[0] = 0;
        dis[0] = 0;
        for (int i = 1; i < g.vnum; i++) {
            dis[i] = g.arc[0][i];
            adjvex[i] = 0;
        }
        for (int i = 0; i < g.vnum; i++) {
            min = INTMAX_MAX, j = 1, k = 0;
            while (j < g.vnum) {
                if (dis[j] != 0 && dis[j] < min) {
                    min = dis[j];
                    k = j;
                }
                j++;
                //visit (k);
                dis[k] = 0;
                for (int p = 1; p < g.vnum; p++) {
                    if (dis[p] != 0 && g.arc[k][p] < dis[p]) {
                        dis[p] = g.arc[k][p];
                        adjvex[p] = k;
                    }
                }
            }
        }
    }

    int prim_2(m_graph g) {
        int adjvex[g.vnum], dis[g.vnum], min, j, k;
        adjvex[0] = 0;
        dis[0] = 0;
        for (int i = 1; i < g.vnum; i++) {
            adjvex[i] = 0;
            dis[i] = g.arc[0][i];
        }
        for (int i = 1; i < g.vnum; i++) {
            min = INTMAX_MAX, j = 1, k = 0;
            while (j < g.vnum) {
                if (dis[j] != 0 && dis[j] < min) {
                    min = dis[j];
                    k = j;
                }
                j++;
                //do sth to adjvex[k]
                dis[k] = 0;
                for (int i = 1; i < g.vnum; i++) {
                    if (dis[i] != 0 && g.arc[k][i] < dis[i]) {
                        dis[i] = g.arc[k][i];
                        adjvex[i] = k;
                    }
                }
            }
        }
    }

    int prim_4(m_graph g) {
        int adjvex[g.vnum], dis[g.vnum], min, j, k;
        adjvex[0] = 0;
        dis[0] = 0;
        for (int i = 1; i < g.vnum; i++) {
            adjvex[i] = 0;
            dis[i] = g.arc[0][i];
        }
        for (int i = 1; i < g.vnum; i++) {
            min = INTMAX_MAX, j = 1, k = 0;
            while (j < g.vnum) {
                if (dis[j] != 0 && dis[j] < min) {
                    min = j;
                    k = j;
                }
//                visit(k);
                j++;
                dis[k] = 0;
                for (int p = 1; p < g.vnum; p++) {
                    if (dis[p] != 0 && dis[p] < g.arc[k][p]) {
                        dis[p] = g.arc[k][p];
                        adjvex[p] = k;
                    }
                }
            }
        }
    }


    int prim_5(m_graph g) {
        int dis[g.vnum], adjvex[g.vnum], min, j, k;
        for (int i = 1; i < g.vnum; i++) {
            dis[i] = g.arc[0][i];
            adjvex[i] = 0;
        }
        dis[0] = 0;
        adjvex[0] = 0;

        for (int i = 1; i < g.vnum; i++) {
            min = INTMAX_MAX, j = 1, k = 0;
            while (j < g.vnum) {
                if (dis[i] != 0 && dis[j] < min) {
                    min = dis[j];
                    k = j;
                }
                //visit(k);
                j++;
                dis[k] = 0;
                for (int p = 1; p < g.vnum; p++) {
                    if (dis[p] != 0 && dis[p] < g.arc[k][p]) {
                        dis[p] = g.arc[k][p];
                        adjvex[p] = k;
                    }
                }
            }
        }
    }

    int dijkstra_3(m_graph g, int v) {
        int min, k, dis[g.vnum], adjvex[g.vnum], flags[g.vnum];
        for (int i = 0; i < g.vnum; i++) {
            flags[i] = 0;
            dis[i] = g.arc[v][i];
            adjvex[i] = 0;
        }
        flags[0] = 1;
        dis[0] = 0;

        for (int i = 1; i < g.vnum; i++) {
            min = INTMAX_MAX;
            for (int j = 0; j < g.vnum; j++) {
                if (flags[j] == 0 && dis[j] < min) {
                    min = dis[j];
                    k = j;
                }
//                adjvex[k]=i;
                flags[k] = 1;
                for (int j = 0; j < g.vnum; j++) {
                    if (flags[j] == 0 && g.arc[k][j] + min < dis[j]) {
                        dis[j] = min + g.arc[k][i];
                        adjvex[j] = k;
                    }
                }
            }
        }
    }

    int dijkstra_2(m_graph g, int v) {
        int min, k, adjvex[g.vnum], dis[g.vnum], flags[g.vnum];
        for (int i = 0; i < g.vnum; i++) {
            dis[i] = g.arc[v][i];
            flags[i] = 0;
            adjvex[i] = 0;
        }
        flags[0] = 1;
        dis[0] = 0;
        for (int j = 1; j < g.vnum; j++) {
            min = INTMAX_MAX;
            for (int i = 0; i < g.vnum; i++) {
                if (flags[i] == 0 && dis[i] < min) {
                    min = dis[i];
                    k = i;
                }
            }
            flags[k] = 1;
            for (int i = 0; i < g.vnum; i++) {
                if (flags[i] == 0 && min + g.arc[k][i] < dis[i]) {
                    dis[i] = g.arc[k][i];
                    adjvex[i] = k;
                }
            }
        }
    }

    int dijkstra_1(m_graph g, int v) {
        int min, k;
        int ver[g.vnum];
        int dis[g.vnum];
        int flag[g.vnum];
        for (int i = 0; i < g.vnum; i++) {
            dis[i] = g.arc[v][i];
            flag[i] = 0;
            ver[i] = 0;
        }
        flag[0] = 1;//自己一个点不用求
        dis[0] = 0;//自己到自己距离0
        for (int i = 1; i < g.vnum; i++) {
            min = INTMAX_MAX;
            for (int j = 0; j < g.vnum; j++) {
                if (flag[j] == 0 && dis[j] < min) {
                    min = dis[j];
                    k = j;
                }
            }
            flag[k] = 1;
            for (int j = 0; j < g.vnum; j++) {
                if (flag[j] == 0 && min + g.arc[k][j] < dis[j]) {
                    dis[j] = min + g.arc[k][j];
                    ver[j] = k;
                }
            }
        }
    }

    int prim_6() {

    }
}

namespace r4 {
    void test() {
        sort_5_4::test();
    }
}