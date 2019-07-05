
#include <stddef.h>
#include <malloc.h>
#include <stdio.h>

typedef int ElemType;
typedef struct Node {
    ElemType data;
    struct Node *link;
} CNode, *CricularList;

CricularList create(int n);

int main() {
    searchKey();
    return 0;
}

void searchKey() {

    int k = 3, m = 4, n = 8;
    CricularList p, r, list = NULL;
    for (int i = 1; i <= n; i++) {
        p = (CricularList) malloc(sizeof(CNode));
        p->data = i;
        if (list == NULL) {
            list = p;
        } else {
            r->link = p;
        }
        r = p;
    }
    p->link = list;
    p = list;
    for (int i = 0; i < k; i++) {
        r = p;
        p = p->link;
    }
    while (p->link != p) {
        for (int i = 0; i < m; i++) {
            r = p;
            p = p->link;
        }
        r->link = p->link;
        printf("%4d", p->data);
        free(p);
        p = r->link;
    }
    printf("\n%d", p->data);
}


CricularList create(int n) {
    CricularList p, r, list = NULL;
    for (int i = 0; i < n; i++) {
        p = (CricularList) malloc(sizeof(CNode));
        p->data = i;
        if (list == NULL) {
            list = p;
        } else {
            r->link = p;
        }
        r = p;
    }
    p->link = list;
    p = list;
//    print(p);
    return p;
}


void print(CricularList k3) {
    CricularList p;
    p = k3->link;

    while (p != k3) {
        if (p->data == k3->data) {
            break;
        }
        printf("%d\t", p->data);
        p = p->link;
    }
}

 