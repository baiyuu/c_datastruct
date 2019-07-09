
#include <iostream>

using namespace std;

int errMsg(string msg, int code = -1) {
    std::cout << msg << std::endl;
    return code;
}

/*
 * 顺序查找  数组下标从1开始顺序查找  数组下标从1开始
 */
namespace SeqSearch {
    int sequential_search(int *a, int n, int k) {
        for (int i = 1; i <= n; i++) {
            if (a[i] == k) {
                return i;
            }
        }
        return 0;
    }

    int sequential_search_2(int *a, int n, int k) {
        a[0] = k;//设置为‘哨兵’，即如果查找元素不存在会在n=0处返回位置。
        while (a[n] != k) {
            n--;
        }
        return n;
    }


    void testSeqSearch() {
        int a[] = {0, 1, 2, 3, 4, 5, 6};
//        int v = sequential_search(a, 6, 5);
        int v = sequential_search_2(a, 6, 5);
        std::cout << "position=" << v << std::endl;

    }

}
/*
 * 二分查找
 */
namespace BinarySearch {

    int binary_search(int *a, int n, int k) {

        int low = 1;
        int high = n;
        int mid;
        while (low <= high) {
            mid = (low + high) / 2;
            if (k < a[mid]) {
                high = mid - 1;
            } else if (k > a[mid]) {
                low = mid + 1;
            } else {
                return mid;
            }
        }

        return errMsg("没有找到");
    }


    int binary_seasrch_traverse(int *a, int n, int k, int low, int high) {
        int mid = (low + high) / 2;
        if (k > a[mid]) {
            return binary_seasrch_traverse(a, n, k, mid + 1, high);
        }
        if (k < a[mid]) {
            return binary_seasrch_traverse(a, n, k, low, mid - 1);
        }
        return mid;
    }

    void testBsearch() {
        int a[] = {1, 2, 3, 4, 5, 6, 7, 8};
        int result;
        //        result = binary_search(a, 8, 7);
        result = binary_seasrch_traverse(a, 8, 5, 0, 8);
        std::cout << "result=" << result << std::endl;
    }


}

/*
 * 插值查找 ***问题代码
 */
namespace InterpolationSearch {
    int IPsearch(int n, int k) {
        int *a = new int[1000];
        for (int i = 0; i < 1000; i++) {
            a[i] = i + 1;
        }
        int low = 1;
        int high = n;
        int mid;
        while (low <= high) {
            mid = (low + high) / 2;
//            mid = low + (high - low) / 2;
            mid = low + (high - low) * (k - a[low]) / (a[high] - a[low]);
            if (k < a[mid]) {
                high = mid - 1;
            } else if (k > a[mid]) {
                low = mid + 1;
            } else {
                return mid;
            }
        }

        return errMsg("没有找到");
    }

    void test() {
        int r = IPsearch(100000, 2);
        std::cout << "result=" << r << std::endl;
    }
}

namespace FibonacciSearch {

    int fibonacci_search(int *a, int n, int k) {
    }
}

namespace BOrderTree {
#define newTree() (BTree) malloc(sizeof(BNode))
    typedef char Element;
    typedef struct BNode {
        Element data;
        struct BNode *left, *right;
    } BNode, *BTree;


/**
 * 
  *   d f e b i g j k h c a
 *  f d e b i g j k h c a
    B-D-E-F-C-G-I-H-J-K-A-
 *             a
 *      b           c
 *   d    e       g     h
 *          f   i      j    k 
 */
    BTree create() {
        BTree a, b, c, d, e, f, g, h, i, j, k;
        a = newTree();
        a->data = 'A';
        b = newTree();
        b->data = 'B';
        c = newTree();
        c->data = 'C';
        d = newTree();
        d->data = 'D';
        e = newTree();
        e->data = 'E';
        f = newTree();
        f->data = 'F';
        g = newTree();
        g->data = 'G';
        h = newTree();
        h->data = 'H';
        i = newTree();
        i->data = 'I';
        j = newTree();
        j->data = 'J';
        k = newTree();
        k->data = 'K';

        a->left = b;
        a->right = c;
        b->left = d;
        b->right = e;
        d->left = h;
        d->right = nullptr;
        h->left = nullptr;
        h->right = k;
        k->left = nullptr;
        k->right = nullptr;
        e->left = nullptr;
        e->right = nullptr;
        c->left = f;
        c->right = g;
        f->left = i;
        f->right = nullptr;
        i->left = nullptr;
        i->right = nullptr;
        g->left = nullptr;
        g->right = j;
        j->left = nullptr;
        j->right = nullptr;
        return a;
    }

    void preOrderTraverse(BTree t) {
        if (t != nullptr) {
            printf("%c\t", t->data);
            preOrderTraverse(t->left);
            preOrderTraverse(t->right);
        }
    }

    int btree_search(BTree t, Element k, BTree *result) {
        if (t == nullptr)
            return errMsg("空树");

        if (k == t->data) {
            *result = t;
            return errMsg("查找到了", 1);
        }
        if (k > t->data) {
            return btree_search(t->right, k, result);
        }
        if (k < t->data) {
            return btree_search(t->left, k, result);
        }
    }

    int insert(BTree t, Element e) {
        BTree s, p;
        p = newTree();
        p->data = e;
        p->left = nullptr;
        p->right = nullptr;
        if (t == nullptr) {
            t = p;
        } else {
            s = t;
            while (1) {
                if (t->data >= e) {
                    if (s->left != nullptr) {
                        s = s->left;
                    } else {
                        s->left = p;
                        break;
                    }
                } else {
                    if (s->right != nullptr) {
                        s = s->right;
                    } else {
                        s->right = p;
                        break;
                    }
                }
            }
        }
    }

    int insertByTraverse(BTree t, Element e) {
        if (t == nullptr) {
            t = newTree();
            t->data = e;
            t->left = nullptr;
            t->right = nullptr;
        } else {
            if (t->data > e)
                insertByTraverse(t->left, e);
            else
                insertByTraverse(t->right, e);
        }
    }

    int del(BTree t, Element e, Element *deled) {
//        BTree p = t, q, s;

    }

    void test() {
        BTree t = create();
        preOrderTraverse(t);
        puts("");
//        BTree e = newTree();
//        int r = btree_search(t, 'C', &e);
//        std::cout << "result=" << e->data << std::endl;
//        insert(t, 'A');
        insertByTraverse(t, 'P');

        preOrderTraverse(t);

    }

}

namespace AVL_Tree {
#define  LH 1   //左高
#define  EH 0   //等高
#define  RH -1  //右高
#define  newAvlTree() (AVL_Tree) malloc(sizeof(Node))

    typedef struct Node {
        int data;
        int bf;
        struct Node *left, *right;
    } AVL_Node, *AVL_Tree;

    /**
     * 右旋操作     a               b
     *          b    bright      c  a 
     *         c                     bright
     */
    void right_rotate(AVL_Tree *t) {
        AVL_Tree p;
        p = (*t)->left;
        (*t)->left = p->right;
        p->right = (*t);
        *t = p;
    }

    /*
     *左旋操作      a                pb
     *              b          *ta    c
     *                c           p_l
     * 
     */
    void left_rotate(AVL_Tree *t) {
        AVL_Tree p;
        p = (*t)->right;
        (*t)->right = p->left;
        p->left = (*t);
        *t = p;
    }

    void left_balance(AVL_Tree *t) {
        AVL_Tree L, Lr;
        L = (*t)->left;
        switch (L->bf) {
            case LH:  //新节点插在t的左节点的左子树上，要进行右旋
                (*t)->bf = L->bf = EH;
                right_rotate(t);
                break;
            case EH:

                break;
            case RH://新节点在t的左节点的右子树，进行双旋处理
                Lr = L->right;//指向t的左节点的右子树根
                switch (Lr->bf) {//修改t及左节点的bf值
                    case LH:
                        (*t)->bf = RH;
                        L->bf = EH;
                        break;
                    case EH:
                        (*t)->bf = L->bf = EH;
                        break;
                    case RH:
                        (*t)->bf = EH;
                        L->bf = LH;
                        break;
                }
                Lr->bf = EH;
                left_rotate(&(*t)->left);   //对t的左子树左旋
                right_rotate(t);            //对t进行右旋
                break;
        }
    }

    /**
     * 插入操作
     * 有相同数据则不插入
     * @param taller 反映树是否长高 
     * @return 
     */
    int insert(AVL_Tree *t, int data, bool *taller) {
        if (!*t) {//树为空的情况下
            (*t) = newAvlTree();
            (*t)->data = data;
            (*t)->left = (*t)->right = nullptr;
            (*t)->bf = EH;
            *taller = true;
        } else {//树不为空的情况
            if ((*t)->data == data) {
                *taller = false;
                return errMsg("have same data.");
            }

            if ((*t)->data > data) {//在t的左子树上操作
                if (!insert(&(*t)->left, data, taller)) { //未插入
                    return errMsg("not insert data in left.");
                }
                if (taller) {//已经插入到左子树，且左子树变高
                    switch ((*t)->bf) {//检查平衡因子
                        case LH://原来左比右高，需要左平衡处理
                            left_balance(t);
                            *taller = false;
                            break;
                        case EH://原来左右等高，现在左子树增加节点后变高
                            (*t)->bf = LH;
                            *taller = true;
                            break;
                        case RH://原来右子树比左子树高，左子树插入后，现在左右等高
                            (*t)->bf = EH;
                            *taller = false;
                            break;
                    }
                }
            } else {//在t的右子树上操作
                if (!insert(&(*t)->right, data, taller)) {
                    return errMsg("not insert data in right");
                }

                if (taller) {//已经插入到右子树，且右子树变高
                    switch ((*t)->bf) {
                        case LH://原来左比右高，现在右插入后等高
                            (*t)->bf = EH;
                            *taller = false;
                            break;
                        case EH://原来左右等高，现在右插入后，右变高
                            (*t)->bf = RH;
                            *taller = true;
                            break;
                        case RH://原来右高，又在右插入后需要右旋处理
                            right_rotate(t);
                            *taller = false;
                            break;
                    }
                }

            }

        }
        return errMsg("insert success!");
    }

    AVL_Tree create() {
        int a[] = {3, 2, 1, 4, 5, 6, 7, 10, 9, 8};
        AVL_Tree t = nullptr;
        bool taller;
        for (int i = 0; i < 10; i++) {
            insert(&t, a[i], &taller);
        }

        return t;
    }

    void test() {
        AVL_Tree t = create();
    }
}

namespace Search {

    void run() {
//        SeqSearch::testSeqSearch();
//        BinarySearch::testBsearch();
//        InterpolationSearch::test();
//        BOrderTree::test();
        AVL_Tree::test();
    }
}