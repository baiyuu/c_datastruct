
#include <iostream>

using namespace std;
typedef int Element;
#define  newTree() (BTree)malloc(sizeof(BNode));
namespace BTree {
    int errMsg(string msg, int code = -1) {
        std::cout << msg << std::endl;
        return code;
    }

    typedef struct Node {
        Element data;
        Node *left;
        Node *right;
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

    /*
                        A
                    B       C
                 D    E   F   G 
              H          I     J 
                K       
     */

    /*
     * ABDHKECFIGJ
     */
    int preOrderTraverse(BTree t) {
        if (t != nullptr) {
            printf("%c\t", t->data);
            preOrderTraverse(t->left);
            preOrderTraverse(t->right);
        }
    }


    /*
     * HKDBEAIFCGJ
     */
    int inOrderTraverse(BTree t) {
        if (t != nullptr) {

            inOrderTraverse(t->left);
            printf("%c\t", t->data);
            inOrderTraverse(t->right);
        }
    }

    /*
     * KHDEBIFJGCA
     */
    int postOrderTraverse(BTree t) {
        if (t != nullptr) {
            postOrderTraverse(t->left);
            postOrderTraverse(t->right);
            printf("%c\t", t->data);
        }
    }

    /*****************************************************
     * 前序 ABCDEF
     * 中序 CBAEDF
     *  则 后序为 
     * 
     *              a
     *           b    d
     *         c     e  f
     *  cb efd a 
     * 
     ******************************************************/

    void testTraverse() {
        preOrderTraverse(create());
        printf("\n");
        inOrderTraverse(create());
        printf("\n");
        postOrderTraverse(create());
    }


    void run() {
        testTraverse();
    }
}