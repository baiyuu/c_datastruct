
#include <iostream>

using namespace std;

typedef int Element;
#define MaxSize 10


namespace SqStack {
    int errMsg(string msg, int code = -1) {
        std::cout << msg << std::endl;
        return code;
    }

    /* operation
     *  INIT
     *  destory
     *  clear
     *  isEmpty
     *  pop
     *  push
     *  length
     * 
     * */
    typedef struct {
        Element data[MaxSize];
        int top;
    } SqStack;

    SqStack create(int n = 6) {
        SqStack s = {
                {11, 22, 33, 44, 55, 66},
                5
        };
        return s;
    }

    void ps(SqStack s) {
        printf("\n");
        for (int i = 0; i <= s.top; i++) {
            std::cout << s.data[i] << "\t";
        }
        printf("\n");
    }

    int push(SqStack *s, Element e) {
        if (s->top == MaxSize - 1) {
            return errMsg("栈满了");
        }
        s->top++;
        s->data[s->top] = e;
        return 1;
    }

    int pop(SqStack *s, Element *e) {
        if (s->top == -1) {
            return errMsg("空栈，没有元素");
        }
        *e = s->data[s->top];
        s->top--;
        return 1;
    }

    SqStack s = create();

    void testPush() {
        push(&s, 276);
    }

    void testPop() {
//        SqStack s = create();
        int a = 1;
        pop(&s, &a);
        std::cout << "取到的元素为：" << a << std::endl;
    }

    void run() {
        ps(s);
//        testPush();
        testPop();
        ps(s);
    }
}

namespace DoubleStack {
    typedef struct {
        Element data[20];
        int top_1;
        int top_2;
    } DoubleStack;

    DoubleStack d = {
            {1, 2, 3, 4, 0, 0, 0, 0, 0, 0, 25, 6, 7, 8, 9, 10},
            3,
            10
    };

    void ps() {
        printf("\n");
        for (int i = 0; i < 16; i++) {
            std::cout << d.data[i] << "\t";
        }
        printf("\n");
    }

    int push(DoubleStack *ds, Element e, int flag) {
        if (ds->top_1 + 1 == ds->top_2) {
            return SqStack::errMsg("栈满了");
        }
        if (flag == 1) {
            ds->data[++ds->top_1] = e;
        }
        if (flag == 2) {
            ds->data[--ds->top_2] = e;
        }

        return 1;

    }

    void testPush() {
        push(&d, 12, 1);
        push(&d, 33, 2);
        push(&d, 33, 2);
    }

    int pop(DoubleStack *ds, Element *e, int flag) {
        if (flag == 1)
            if (ds->top_1 == -1) {
                return SqStack::errMsg("这个栈是空的");
            } else {
                *e = ds->data[ds->top_1--];
            }
        if (flag == 2)
            if (ds->top_2 == MaxSize) {
                return SqStack::errMsg("这个栈是空的");
            } else {
                *e = ds->data[ds->top_2++];
            }
        return 1;
    }

    void testPop() {
        int a, b;
        pop(&d, &a, 2);
        std::cout << "取出的元素为：" << a << "--" << std::endl;
    }

    void run() {
        ps();
//        testPush();
        testPop();
        ps();
    }

}
