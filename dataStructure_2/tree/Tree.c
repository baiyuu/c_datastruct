#include <stddef.h>
#include <malloc.h>
#include <stdio.h>


/*
 * 1.二叉树的遍历 
 *  前序 中序 后序 按层次
 * 2.二叉树的基本操作
 */


#define MAXSIZE 100
#define  newTree() (BTree)malloc(sizeof(BNode));
typedef char DataType;

typedef struct node {
    DataType data;
    struct node *left, *right;
} BNode, *BTree;


BTree create();

void visit(BTree t);

/*递归遍历*/
void preOrder(BTree t);

void midOrder(BTree t);

void postOrder(BTree t);

/* 非递归遍历*/

void preOrder2(BTree t);

void midOrder2(BTree t);

void postOrder2(BTree t);

void layerOrder(BTree t);

/* 二叉树的基本操作*/
void build(BTree t);

void clearBtree(BTree t);

BTree copyBtree(BTree t);

int equalTree(BTree t1, BTree t2);

int treeDepth1(BTree t);

int treeDepth2(BTree t);

/*
 *            a
 *      b           c
 *   d    e       g     h
 *          f   i    j    k 
 */
int pre(BTree t, DataType e);

void destoryBTree(BTree t);

BTree deleteBTree(BTree t, DataType e);

BTree exchange(BTree t);

BTree createSortTree();

void deleteSortTree2(BTree t, BTree p, BTree q);

void deleteSortTree(BTree *t, DataType d);

BTree sortTreefFind(BTree t, DataType d);

BTree sortTreefFind2(BTree t, DataType d);

treerun() {
    BTree t = createSortTree();
    BTree t1 = newTree();
    t1->data = 3;

    midOrder2(t);

}

/**
 * 二叉排序树
 *                      5
 *                  2      7
 *                 1 3    6 8
 *                    4      9   
 */

BTree sortTreefFind2(BTree t, DataType d) {
    if (t == NULL) {
        return NULL;
    }
    if (t->data == d) {
        return t;
    } else if (d < t->data) {
        return sortTreefFind2(t->left, d);
    } else {
        return sortTreefFind2(t->right, d);
    }

}

/**
 * 查找
 */
BTree sortTreefFindp(BTree t, DataType d) {

}

BTree sortTreefFind(BTree t, DataType d) {
    BTree p = t;
    if (p->data == d) {
        return p;
    }

    while (p != NULL) {
        if (p->data == d) {
            return p;
        }
        if (p->data > d) {
            p = p->left;
        } else {
            p = p->right;
        }
    }
    return NULL;
}

/**
 * 排序树删除
 * 1. 为叶子节点
 * 2. 删除节点没有左子树
 * 3. 删除节点没有右子树
 * 4. 删除节点有左右子树
 */
void deleteSortTree(BTree *t, DataType data) {


}

void deleteSortTree2(BTree t, BTree p, BTree q) {

}

/**
 * 教材案例 ？？
 * @param t 
 * @param p 
 * @param q 
 */
void deleteSortTree22(BTree t, BTree p, BTree q) {
    BTree r, s;
    int f = 0;
    if (p->left == NULL) {
        if (p == t) {
            t = p->right;
        } else {
            r = p->right;
            f = 1;
        }
    } else if (p->right == NULL) {
        if (p == t) {
            t = t->left;
        } else {
            r = p->left;
            f = 1;
        }
    } else {
        s = p;
        r = s->left;
        while (r->left != NULL) {
            s = r;  //循环结束时记录 p的左叶节点的父节点
            r = r->left;//循环结束时 记录的是p的左叶节点
        }
        r->left = p->left;
        if (s != p) {
            s->left = r->right;
            r->right = p->right;
        }
        if (p == t) {
            t = r;
        } else {
            f = 1;
        }

    }

    if (f == 1) {
        if (p == q->left) {
            q->left = r;
        } else {
            q->right = r;
        }
    }
    free(p);
    postOrder2(t);
}


void insertSortTree2(BTree t, DataType d) {
    if (t == NULL) {
        t = newTree();
        t->data = d;
        t->left = NULL;
        t->right = NULL;
    } else if (d < t->data) {
        insertSortTree2(t->left, d);
    } else {
        insertSortTree2(t->right, d);
    }


}

/**
 * 向排序树中插入数据
 * 1. if(t==null) t=newtree;
 * 2. while(1){
 *      if(t.data>data)
 *          turn left  
 *          while(t.left!=null){
 *           t=t.left
 *          }
 *          t.left=p;
 *      }else{
 *          turn right
 *      }
 *      
 * 
 * @param t 
 * @param data 
 */
void insertSortTree(BTree t, DataType data) {
    BTree p, q;
    p = newTree();
    p->data = data;
    p->left = NULL;
    p->right = NULL;

    if (t == NULL) {
        t = p;
    } else {
        q = t;
        while (1) {
            if (data >= q->data) {
                if (q->right != NULL) {
                    q = q->right;
                } else {
                    q->right = p;
                    break;
                }
            } else {
                if (q->left != NULL) {
                    q = q->left;
                } else {
                    q->left = p;
                    break;
                }
            }


        }
    }
}

/**
 *                      5
 *                  2      7
 *                 1 3    6 8
 *                    4      9           
 *                
 */
BTree createSortTree() {
    BTree t = newTree();
    t->data = 5;
    t->left = NULL;
    t->right = NULL;
    int a[] = {2, 7, 1, 3, 6, 8, 4, 9};
    for (int i = 0; i < 8; i++) {
        insertSortTree(t, a[i]);
    }
    return t;
}



/*
 *  2.二叉树的基本操作
 */

/**
 * 交换左右结点
 */
BTree exchange(BTree t) {

    BTree q[MAXSIZE], w, p = t;
    int f, r;
    if (t != NULL) {
        q[0] = t;
        f = -1;
        r = 0;
        while (f < r) {
            p = q[++f];
            w = p->left;
            p->left = p->right;
            p->right = w;
            if (p->left != NULL) {
                q[++r] = p->left;
            }
            if (p->right != NULL) {
                q[++r] = p->right;
            }
        }
    }
    return t;
}


/**
 * 删除
 */
BTree deleteBTree(BTree t, DataType e) {
    BTree stack[MAXSIZE], p = t, q;
    int a = -1;
    if (t->data == e) {
        destoryBTree(t);
        return NULL;
    } else {
        do {
            while (p != NULL) {
                if (p->data == e) {
                    if (q->left == p) {
                        q->left = NULL;
                    } else {
                        q->right = NULL;
                    }
                    destoryBTree(p);
                    return t;
                }
                stack[++a] = p;
                q = p;
                p = p->left;
            }
            p = stack[a--];
            q = p;
            p = p->right;
        } while (!(p == NULL && a == -1));
    }


}


/**
 * 查找 结点所在的层次
 */
int pre(BTree t, DataType e) {
    BTree stack[MAXSIZE], q = t;
    int fs[MAXSIZE], f, a = -1;
    if (t != NULL) {
        do {
            while (q != NULL) {
                stack[++a] = q;
                fs[a] = 0;
                q = q->left;
            }
            q = stack[a];
            f = fs[a--];
            if (f == 0) {
                stack[++a] = q;
                fs[a] = 1;
                q = q->right;
            } else {
                if (q->data == e) {
                    return a + 2;
                }
                q = NULL;
            }

        } while (!(q == NULL && a == -1));
    }
}

/**
 * 二叉树深度 非递归
 * @param t 
 * @return 
 */
int treeDepth2(BTree t) {
    BTree stack[MAXSIZE], q = t;
    int arr[MAXSIZE], currentDepth = 0, maxDepth = 0, top = -1;
    if (t == NULL)return 0;
    if (t != NULL) {
        currentDepth = 1;
        do {
            while (q != NULL) {
                stack[++top] = q;
                arr[top] = currentDepth;
                q = q->left;
                currentDepth++;
            }
            q = stack[top];
            currentDepth = arr[top--];
            if (q->left == NULL && q->right == NULL) {
                if (currentDepth > maxDepth) {
                    maxDepth = currentDepth;
                }
            }
            q = q->right;
            currentDepth++;
        } while (!(q == NULL && top == -1));
    }
    return maxDepth;
}

/**
 * 二叉树深度 递归算法
 */
int treeDepth1(BTree t) {
    int left, right;
    if (t == NULL) {
        return 0;
    } else {
        left = treeDepth1(t->left);
        right = treeDepth1(t->right);
        if (left > right) {
            return left + 1;
        } else {
            return right + 1;
        }
    }
}


/**
 * 两颗树是否相等
 */
int equalTree(BTree t1, BTree t2) {
    if (t1 == NULL && t2 == NULL) {
        return 1;
    }

    if (t1 != NULL && t2 != NULL
        && t1->data == t2->data
        && equalTree(t1->left, t2->left)
        && equalTree(t1->right, t2->right)) {
        return 1;
    }
    return 0;

}

/**
 * 二叉树的复制
 * @param t 
 * @return 
 */
BTree copyBtree(BTree t) {
    BTree t2;
    if (t == NULL) {
        return NULL;
    } else {
        t2 = newTree();
        t2->data = t->data;
        t2->left = copyBtree(t->left);
        t2->right = copyBtree(t->right);
    }
    return t2;
}

/**
 * 二叉树的销毁
 * @param t 
 */
void destoryBTree(BTree t) {
    if (t != NULL) {
        destoryBTree(t->left);
        destoryBTree(t->right);
        free(t);
    }
}

void clearBtree(BTree t) {
    destoryBTree(t);
    t = NULL;
}

/**
 * 创建二叉树
 * @param t 
 */
void build(BTree t) {
    char c;
    scanf("%c", &c);
    if (c == ' ') {
        t = NULL;
    } else {
        t = newTree();
        t->data = c;
        build(t->left);
        build(t->right);
    }
}


/*
 *  1.二叉树的遍历 
 */

/**
 * 按层次遍历
 * @param t 
 */
void layerOrder(BTree t) {
    BTree q[MAXSIZE], w;
    int front, rear;
    if (t != NULL) {
        q[0] = t;
        front = -1;
        rear = 0;
        while (front < rear) {
            w = q[++front];
            visit(w);
            if (w->left != NULL) {
                q[++rear] = w->left;
            }
            if (w->right != NULL) {
                q[++rear] = w->right;
            }
        }
    }
}

/**
 * D-F-E-B-I-G-J-K-H-C-A-
 * 非 递归后序遍历
 */
void postOrder2(BTree t) {
    BTree stack[MAXSIZE], q = t;
    //fs 为标记数组, 0可以访问/1不可以访问
    int fs[MAXSIZE], f, top = -1;
    if (t != NULL) {
        do {
            while (q != NULL) {
                stack[++top] = q;
                fs[top] = 0;
                q = q->left; //沿着左边走到头
            }

            q = stack[top];//先取出最左边的结点
            f = fs[top--];
            if (f == 0) {//继续遍历 右结点
                /*
                 *如果没右结点,相当于进栈 就 出栈;
                 * 有右结点 ,走到最后一个右结点
                 */
                stack[++top] = q;
                fs[top] = 1;
                q = q->right;
            } else {
                //q 此时是最下边的一个结点,因为访问过的都赋值 null 了
                visit(q);
                q = NULL;//是为了从栈中再取出一个元素进行访问
            }


        } while (!(q == NULL && top == -1));
    }
}


/**
 * 非递归 前序遍历
 * A-B-D-E-F-C-G-I-H-J-K-
 */
void preOrder2(BTree t) {
    BTree stack[MAXSIZE], q = t;
    int top = -1;
    if (t != NULL) {
        do {
            while (q != NULL) {
                stack[++top] = q;
                visit(q);
                q = q->left;
            }
            q = stack[top--];
            q = q->right;
        } while (!(q == NULL && top == -1));
    }
}


/**
 * 
 * D-B-E-F-A-I-G-C-J-H-K-
 * D-B-E-F-A-I-G-C-J-H-K-
 *  非递归 中序遍历   
 */
void midOrder2(BTree t) {
    BTree stack[MAXSIZE], q = t;
    int top = -1;
    if (t != NULL) {
        do {
            while (q != NULL) {
                stack[++top] = q;
                q = q->left;
            }
            q = stack[top--];//这个结点的左结点 是null
            visit(q);
            q = q->right;//再看右结点
        } while (!(q == NULL && top == -1));
    }

}


/**
 *  d f e b i g j k h c a
 *  D-F-E-B-I-G-J-K-H-C-A-
 * 后序遍历
 * @param t 
 */
void postOrder(BTree t) {
    if (t != NULL) {
        postOrder(t->left);
        postOrder(t->right);
        visit(t);
    }
}


/**
 *  d b e f a i g c j h k
 *  D-B-E-F-A-I-G-C-J-H-K-
 * 中序遍历
 * @param t 
 */
void midOrder(BTree t) {
    if (t != NULL) {
        midOrder(t->left);
        visit(t);
        midOrder(t->right);
    }
}

/**
 * a b d e f c g i h j k 
 * A-B-D-E-F-C-G-I-H-J-K-
 * 前序遍历
 * @param t 
 */
void preOrder(BTree t) {
    if (t != NULL) {
        visit(t);
        preOrder(t->left);
        preOrder(t->right);
    }

}


void visit(BTree t) {
    printf("%d - ", t->data);
}


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
    puts("s1");
    BTree t = NULL, p, a, b, f;
        
    t = newTree();
    t->data = 'A';
    a = newTree();
    a->data = 'B';
    a->left = NULL;
    a->right = NULL;
    b = newTree();
    b->data = 'C';
    b->left = NULL;
    b->right = NULL;

    t->left = a;
    t->right = b;

    p = newTree();
    p->data = 'D';
    p->left = NULL;
    p->right = NULL;
    b = newTree();
    b->data = 'E';
    b->left = NULL;

    f = newTree();
    f->left = NULL;
    f->right = NULL;
    f->data = 'F';
    b->right = f;

    a->left = p;
    a->right = b;
    p = t->right;
    a = newTree();
    a->data = 'G';
    a->left = NULL;
    a->right = NULL;

    b = newTree();
    b->data = 'H';
    b->left = NULL;
    b->right = NULL;

    p->left = a;
    p->right = b;

    p = b;

    b = newTree();
    b->data = 'I';
    b->left = NULL;
    b->right = NULL;


    a->left = b;

    a = newTree();
    a->data = 'J';
    a->left = NULL;
    a->right = NULL;
    b = newTree();
    b->left = NULL;
    b->right = NULL;

    b->data = 'K';
    p->left = a;
    p->right = b;
    return t;
}


/*
 * 广义表输入，错误代码
 * （A,(B(D,E(,G)),C(,F(H)))）
 */
BTree create_1() {
    BTree stack[MAXSIZE], q, t = NULL;
    char c;
    int f, top = -1;
    while (1) {
        scanf("%c", &c);
        if (c == '\0' || c == 10) {
            continue;
        }
        switch (c) {
            case '@':
                return (t);
            case '(':
                stack[++top] = q;
                f = 1;
                break;
            case ')':
                top--;
                break;
            case ',':
                f = 2;
                break;
            default:
                q = newTree();
                q->data = c;
                q->left = NULL;
                q->right = NULL;

                if (t == NULL) {
                    t = q;
                } else if (f == 1) {
                    stack[top]->left = q;
                } else {
                    stack[top]->right = q;

                }
        }
    }

}



