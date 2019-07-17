
#include <iostream>

using namespace std;


namespace BTree_3 {
    typedef int Element;
    typedef struct node {
        Element data;
        struct node *left, *right;
    } bnode, *BTree;

#define newNode (BTree) malloc(sizeof(node))

    void visit(Element e) {

    }

    int preorderTraverse(BTree t) {
        if (t) {
            visit(t->data);
            preorderTraverse(t->left);
            preorderTraverse(t->right);
        }
    }

    int inOrderTraverse(BTree t) {
        if (t) {
            inOrderTraverse(t->left);
            visit(t->data);
            inOrderTraverse(t->right);
        }
    }

    int postorderTraverse(BTree t) {
        if (t) {
            postorderTraverse(t->left);
            postorderTraverse(t->right);
            visit(t->data);
        }
    }


    void create(BTree t) {
        char c;
        scanf("%c", &c);
        if (c != '!') {
            t = newNode;
            t->data = c;
            create(t->left);
            create(t->right);
        }
    }
    

}

namespace tree_3 {

    void test() {

    }
}