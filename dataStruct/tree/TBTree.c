

/*
 * 线索二叉树
 */

typedef int DataType;
typedef struct node {
    DataType data;
    struct node *left, *right;
    int leftFlag, rightFlag;
} TBNode, *TBTree;


int main() {

    return 0;
}

//在中序线索二叉树中 查找地址为 x节点的直接前驱节点
TBTree find(TBTree x) {
    TBTree s;
    s = x->left;
    if (x->leftFlag == 1) {
        while (s->rightFlag == 1) {
            s = s->right;
        }
    }
    return s;
}
