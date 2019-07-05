

#include <stddef.h>

typedef int DataType;

typedef struct Node {
    DataType data;
    struct Node *left, *right;
} BNode, *BTree;
#define  MAXSIZE 100

/**
 * 二叉树遍历
 * @return 
 */
int main2() {
    return 0;
}

/*
    递归 遍历
 */

//前序遍历
void preOrder(BTree tree) {
    if (tree != NULL) {
        //调用 访问 p 的方法
        preOrder(tree->left);
        preOrder(tree->right);
    }
}
//中序遍历
void midOrder(BTree tree) {
    if (tree != NULL) {
        preOrder(tree->left);
        //调用 访问 p 的方法
        preOrder(tree->right);
    }
}
//后续遍历
void backOrder(BTree tree) {
    if (tree != NULL) {
        preOrder(tree->left);
        preOrder(tree->right);
        //调用 访问 p 的方法
    }
}


/*
  非递归 遍历
 */

// 中序遍历
void inorder(BTree tree) {
    BTree stack[MAXSIZE];
    BTree p = tree;
    int top = -1;
    if (tree != NULL) {
        do {
            while (p != NULL) {
                stack[++top] = p;
                p = p->left;
            }
            p = stack[top--];
            //访问 p 的方法
            p = p->right;
        } while (p != NULL && top != -1);
    }
}

//后序遍历
void postOrder(BTree tree) {
    BTree stack[MAXSIZE], p = tree;
    int top, flag = -1;
    int stackFlag[MAXSIZE];
    if (tree != NULL) {
        do {
            while (p != NULL) {
                stack[++top] == p;
                stackFlag[0] = 0;
                p = p->left;
            }
            p = stack[top];
            flag = stackFlag[top--];
            if (flag == 0) {
                stack[++top] = p;
                stackFlag[top] = 1;
                p = p->right;
            } else {
                //访问 p 的方法 
                p = NULL;
            }

        } while (p != NULL && top != -1);
    }
}

//按层次遍历
void layerorder(BTree tree) {
    BTree queue[MAXSIZE], p = tree;
    int frong, rear;
    if (tree != NULL) {
        queue[0] = tree;
        frong = -1;
        rear = 0;
        while (frong < rear) {
            p = queue[++frong];
            //调用 访问 p 的方法
            if (p->left != NULL) {
                queue[++rear] = p->left;
            }
            if (p->right != NULL) {
                queue[++rear] = p->right;
            }
        }
    }
}

//判断两颗二叉树是否相似 或这等价  1相似 0不相似
int isSimilar(BTree t1, BTree t2) {
    //空树
    if (!t1 && !t2)
        return 1;
    if (t1 && t2
        && isSimilar(t1->left, t2->left)
        && isSimilar(t1->right, t2->right))
        return 1;
    return 0;
}

