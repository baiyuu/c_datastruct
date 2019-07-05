


#include <stddef.h>
#include <stdio.h>
#include <malloc.h>

typedef char DataType;

typedef struct Node {
    DataType data;
    struct Node *left, *right;
} BNode, *BTree;

void createBTree(BTree tree);

int main() {
    test();
    return 0;
}

void test() {
    BTree t;
    createBTree(t);
    printf("%c", t->data);
}

//创建
void createBTree(BTree tree) {
    char ch;
    scanf("%c", &ch);
    if (ch == '#') {
        return;
    }
    if (ch == ' ') {
        tree = NULL;
    } else {
        tree = (BTree) malloc(sizeof(BNode));
        tree->data = ch;
        createBTree(tree->left);
        createBTree(tree->right);
    }
}

//销毁
void clearTree(BTree tree) {
    destoryTree(tree);
    tree = NULL;
}

//释放空间
void destoryTree(BTree tree) {
    if (tree != NULL) {
        destoryTree(tree->left);
        destoryTree(tree->right);
        free(tree);
    }
}

//复制
BTree copyTree(BTree t1) {
    BTree t2;
    if (t1 == NULL) return NULL;
    else {
        t2 = (BTree) malloc(sizeof(BNode));
        t2->data = t1->data;
        t2->left = copyTree(t1->left);
        t2->right = copyTree(t1->right);
    }
    return t2;
}

//判断两棵树是否等价
int isTreeEqual(BTree t1, BTree t2) {
    if (t1 == NULL && t2 == NULL) {
        return 1;
    }
    if (t1 != NULL && t2 != NULL
        && t1->data == t2->data
        && isTreeEqual(t1->left, t2->left)
        && isTreeEqual(t1->right, t2->right)) {
        return 1;
    }
    return 0;
}

//求二叉树的深度 递归计算
int depthTree(BTree t1) {
    if (t1 == NULL) {
        return 0;
    }
    if (t1->left == NULL && t1->right == NULL) {
        return 1;
    }

    int left, right;
    left = depthTree(t1->left);
    right = depthTree(t1->right);

    return left > right ? left + 1 : right + 1;
}

//求二叉树的深度 非递归计算
int depth(BTree t1) {
    int max, current = 0, top = -1;
    BTree stack[MAX_PATH], p = t1;
    int layers[MAX_PATH];
    if (t1 != NULL) {
        current = 1;
        do {
            while (p != NULL) {
                stack[top++] = p;
                layers[top++] = current;
                p = p->left;
                current++;
            }
            p = stack[top];
            current = layers[top--];
            if (p->left == NULL && p->right == NULL) {
                if (current > max) {
                    max = current;
                }
            }
            p = p->right;
            current++;

        } while (p != NULL && top != -1);
    }
}

//查找某个元素所在的层次
int sthDepth(BTree t1, DataType data) {
    BTree stack[MAX_PATH], p = t1;
    int layers[MAX_PATH], flag = 0, top = -1;
    do {
        while (p != NULL) {
            stack[++top] = p->left;
            layers[top] = 0;
            p = p->left;
        }
        p = stack[top];
        flag = layers[top--];
        if (flag == 0) {
            stack[++top] = p->right;
            layers[top] = 1;
            p = p->right;
        } else {
            if (p->data == data) {
                return top + 2;
            }
            p = NULL;
        }
    } while (p != NULL && top != -1);
}

//删除某个元素及其子元素
void deleteData(BTree t1, DataType data) {
    //q 递归节点的父节点 p在递归的节点
    BTree stack[MAX_PATH], q, p = t1;
    int top = -1;
    if (t1->data == data) {
        destoryTree(t1);
        return;
    } else {
        //查找这个元素
        do {
            while (p != NULL) {
                if (p->data == data) {
                    if (q->left == p) {
                        q->left = NULL;
                    } else {
                        q->right = NULL;
                    }
                    destoryTree(p);
                    return;
                }
                stack[++top] = p;
                q = p;
                p = p->left;
            }
            p = stack[top--];
            q = p;
            p = p->right;
        } while (p != NULL && top != -1);
    }
}

//交换左右节点的位置
void exchaneTree(BTree t) {
    BTree queue[MAX_PATH], temp, p = t;
    int front, rear;
    if (t != NULL) {
        queue[0] = t;
        front = -1;
        rear = 0;
        while (front < rear) {
            p = queue[++front];
            temp = p->left;
            p->left = p->right;
            p->right = temp;
            if (p->left != NULL) {
                queue[++rear] = p->left;
            }
            if (p->right != NULL) {
                queue[++rear] = p->right;
            }
        }
    }


}