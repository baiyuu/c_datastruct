

#include <stddef.h>
#include <malloc.h>

/*
 * 二叉排序树
 */

typedef int DataType;

typedef struct node {
    DataType data;
    struct BSortNode *left, *right;
} BSortNode, *SortTree;


void insertTree(SortTree, DataType);

int main() {

    return 0;
}

/**
 * 创建二叉排序树
 * @param datas     数组
 * @param n         数组长度
 */
SortTree create(DataType datas[], int n) {
    SortTree tree = NULL;
    int i = 0;
    for (i = 0; i < n; i++) {
        insertTree(tree, datas[i]);
    }
    return tree;
}

/*
 * 插入元素 ，非递归方式 ，比较繁琐
 */
void insertTree(SortTree tree, DataType data) {
    SortTree q, p;
    p = (SortTree) malloc(sizeof(BSortNode));
    p->data = data;
    p->left = NULL;
    p->right = NULL;

    if (tree == NULL) {
        tree = p;
    } else {
        q = tree;
        while (1) {
            if (tree->data > data) {
                if (q->left != NULL) {
                    q = q->left;
                } else {
                    q->left = p;
                    break;
                }
            } else {
                if (q->right != NULL) {
                    q = q->right;
                } else {
                    q->right = p;
                    break;
                }
            }
        }
    }
}

/**
 * 插入元素 递归方式
 */
void insert2(SortTree tree, DataType data) {
    if (tree == NULL) {
        tree = (SortTree) malloc(sizeof(BSortNode));
        tree->data = data;
        tree->left = NULL;
        tree->right = NULL;
    } else {
        if (tree->data > data) {
            insert2(tree->left, data);
        } else {
            insert2(tree->right, data);
        }
    }
}

/**
 * 
 * @param tree  
 * @param p     被删除节点
 * @param q     被删除节点的父节点
 */
void delete(SortTree tree, SortTree p, SortTree q) {
    SortTree r, s;
    int flag = 0;
    if (p->left == NULL) {
        if (p == tree) {
            tree = p->right;
        } else {
            r = p->right;
            flag = 1;
        }
    } else if (p->right == NULL) {
        if (p == tree) {
            tree = p->left;
        } else {
            r = p->left;
            flag = 1;
        }
    } else {
        s = p;
        r = s->right;
        while (r->left != NULL) {
            s = r;
            r = r->left;
        }
        r->left = p->left;
        if (s != p) {
            s->left = r->right;
            r->right = p->right;
        }
        if (p == tree) {
            tree = r;
        } else {
            flag = 1;
        }
    }
    if (flag == 1) {
        if (p = q->left) {
            q->left = r;
        } else {
            q->right = r;
        }
    }
    free(p);
}

/*
 * 二叉排序树的查找
 */
//非递归查找
SortTree find(SortTree t, DataType e) {
    SortTree p;
    while (p != NULL) {
        if (p->data == e) {
            return p;
        } else if (p->data > e) {
            p = p->left;
        } else {
            p = p->right;
        }
    }
    return NULL;
}

//递归查找
SortTree findResurion(SortTree t, DataType e) {
    if (t == NULL) {
        return NULL;
    }
    if (t->data == e) {
        return t;
    } else if (t->data > e) {
        return findResurion(t->left, e);
    } else {
        return findResurion(t->right, e);
    }
}

