
#include <iostream>

using namespace std;

typedef int Element;
#define  newNode (LinkStack) malloc(sizeof(Node))


namespace LinkStack {
    int errMsg(string msg, int code = -1) {
        std::cout << msg << std::endl;
        return code;
    }

    typedef struct Node {
        Element data;
        Node *link;
    } Node, *LinkStack;

    typedef struct StackNode {
        LinkStack top;
        int count;
    } Stack;

//    typedef struct Node {
//        StackElement data;
//        struct Node *link;
//    } StackNode, *LinkStack;
    Stack create() {
        LinkStack s = (LinkStack) malloc(sizeof(Node));
        s->link = nullptr;
        Stack ss = {
                s, 0
        };
        return ss;
    }

    void ps(Stack *s) {
        printf("\n");
        LinkStack p = s->top;
        while (p != nullptr) {
            std::cout << p->data << "\t";
            p = p->link;
        }
        printf("\n");
    }

    int push(Stack *s, Element e) {
        LinkStack n = newNode;
        n->data = e;
        n->link = s->top;
        s->top = n;
        s->count++;
        return 1;
    }

    int pop(Stack *s, Element *e) {
        *e = s->top->data;
        LinkStack p = s->top;
        s->top = s->top->link;
        s->count--;
        free(p);
        return 1;
    }

    void testPush() {
        int a;
        Stack s = create();
        ps(&s);
        push(&s, 345);
        push(&s, 123);
        pop(&s, &a);
        push(&s, 32325);
        ps(&s);

        std::cout << "取到的元素为：" << a << std::endl;
    }


    void run() {
        testPush();
    }


}