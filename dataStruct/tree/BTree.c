
#include <stddef.h>
#include <stdio.h>
#include <malloc.h>

typedef char DataType;

typedef struct Node {
    DataType data;
    struct Node *left, *right;
} BNode, *BTree;
#define  MAXSIZE 100

BTree lsToBt();

int main() {
    test();
    return 0;
}

test() {
//    lsToBt();
    BTree b1, b2, b3, b4;
    b1 = (BTree) malloc(sizeof(BNode));
    b2 = (BTree) malloc(sizeof(BNode));
    b3 = (BTree) malloc(sizeof(BNode));
    b4 = (BTree) malloc(sizeof(BNode));
//    b1->left = b2;
//    b1->right = b3;
//    b2->left = b4;
//    b2->data = 'aa';
//    b3->data = 'bb';
//    b4->data = 'cc';
    int f = countLeaf(&b1);
    printf("%d", f);
}


//计算二叉树中子叶的数量
int countLeaf(BTree *bTree) {
    BTree tree = bTree;
    if (tree == NULL) {
        return 0;
    }
    if (tree->left == NULL || tree->right == NULL) {
        return 1;
    }
    return countLeaf(&tree->left) + countLeaf(&tree->right);

}

//将广义表   （A,B(D,E(G)),C(F(,H))）  转为二叉链表
BTree lsToBt() {
    BTree stack[MAXSIZE], p, T = NULL;
    char ch;
    int flag = -1;//1左节点 2右节点 
    int top = -1;//保存双亲节点地址的 栈
    while (1) {
        scanf("%c", &ch);
        switch (ch) {
            case '@'://广义表结束
                return (T);
            case '('://遇到左节点
                stack[top++] = p;
                flag = 1;
                break;
            case ')'://一个元素结束
                top--;
                break;
            case ','://遇到右节点
                flag = 2;
                break;
            default://取到字母
                p = (BTree) malloc(sizeof(BNode));
                p->data = ch;
                p->left = NULL;
                p->right = NULL;
                if (T == NULL) {
                    T = p;
                } else if (flag == 1) {
                    stack[top]->left = p;
                } else {
                    stack[top]->right = p;
                }
                break;
        }
    }
}

//计算二叉树的深度
int depth(BTree tree) {
    int left, right;
    if (tree == NULL) {
        return 0;
    } else {
        left = depth(tree->left); //递归计算
        right = depth(tree->right);
        return left > right ? left + 1 : right + 1;
    }
}