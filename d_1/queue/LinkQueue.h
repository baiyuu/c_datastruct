
#include <iostream>

#define newNode (LinkQueue) malloc(sizeof(Node))
using namespace std;
typedef int Element;

namespace LinkQueue {
    int errMsg(string msg, int code = -1) {
        std::cout << msg << std::endl;
        return code;
    }


    typedef struct Node {
        Element data;
        Node *link;
    } Node, *LinkQueue;

    typedef struct {
        LinkQueue front, rear;
    } Queue;

    Queue create() {
        Queue q = {
                nullptr, nullptr
        };
        return q;
    }

    void ps(Queue q) {
        printf("print start :");
        Queue s = q;
        while (s.front != nullptr) {
            printf("%d\t", s.front->data);
            s.front = s.front->link;
        }
        printf("\n");
    }

    int insert(Queue *q, Element e) {
        LinkQueue qq = newNode;
        qq->data = e;
        qq->link = nullptr;
        if (q->front == nullptr) {
            q->front = qq;
        }
        if (q->rear == nullptr) {
            q->rear = qq;
        } else {
            q->rear->link = qq;
            q->rear = qq;
        }
        return 1;
    }

    int get(Queue *q, Element *e) {
        if (q->front == nullptr) {
            return errMsg("空队列，没有元素");
        }

        LinkQueue p = q->front;
        *e = p->data;
        q->front = p->link;
        free(p);
        return 1;
    }

    void testInsert() {

        Queue q = create();
        ps(q);
        insert(&q, 12);
        insert(&q, 122);
        int a, b, c, d;
        get(&q, &a);
        std::cout << "get 1 data=" << a << std::endl;
        get(&q, &b);
        std::cout << "get 2 data=" << b << std::endl;
        get(&q, &c);
        std::cout << "get 3 data=" << c << std::endl;
        insert(&q, 1244);
        get(&q, &d);
        std::cout << "get 4 data=" << d << std::endl;
        ps(q);

    }

    void run() {
        testInsert();
    }
}
