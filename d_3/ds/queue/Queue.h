
#include <iostream>

using namespace std;

int errCode(string, int);

namespace queue_link_3 {
#define q_size_3 10
#define newNode (QueuePtr) malloc(sizeof(qnode))
    typedef int Element;

    typedef struct qnode {
        Element data;
        struct qnode *next;
    } qnode, *QueuePtr;


    typedef struct {
        QueuePtr front;
        QueuePtr rear;
    } Queue;

    int ps_queue(Queue *q) {
        if (q->front == q->rear)
            return errCode("空队列", -1);
        QueuePtr p = q->front;
        while (p != nullptr && p != q->rear) {
            printf("%d\t", p->data);
            p = p->next;
        }
        puts("");
    }


    void init(Queue *q) {
        q->front = nullptr;
        q->rear = nullptr;
    }


    void inQueue(Queue *q, Element e) {
        QueuePtr p = newNode;
        p->data = e;
        p->next = nullptr;
        if (q->front == nullptr) {
            q->front = p;
        }

        if (q->rear == nullptr) {
            q->rear = p;
        } else {
            q->rear->next = p;
            q->rear = p;
        }
    }

    int outQueue(Queue *q, Element *e) {
        if (q->front == nullptr)
            return errCode("空队列，没有元素", 0);

        QueuePtr p = q->front;
        *e = p->data;
        q->front = p->next;
        free(p);
        return 1;
    }


    void destrory(Queue *q) {
        while (q->front) {
            q->rear = q->front->next;
            free(q->front);
            q->front = q->rear;
        }
    }

    void test_1() {
        Queue q;
        init(&q);
        ps_queue(&q);
        inQueue(&q, 14);
        inQueue(&q, 11);
        inQueue(&q, 12);
        ps_queue(&q);
        int p;
        outQueue(&q, &p);
        ps_queue(&q);

        std::cout << "out data=" << p << std::endl;
        if (outQueue(&q, &p))
            std::cout << "out data=" << p << std::endl;
        ps_queue(&q);
        destrory(&q);
        ps_queue(&q);
    }
}

namespace cycleQueue_3 {
#define cq_size_3 10
    typedef int Element;
    typedef struct {
        Element *data;
        int front;
        int rear;
    } CycleQueue;

    void init(CycleQueue *q) {
        q->data = (Element *) malloc(sizeof(Element) * cq_size_3);
        q->front = q->rear = 0;
    }

    int inQueue(CycleQueue *q, Element e) {
        if ((q->rear + 1) & cq_size_3 == q->front)
            return errCode("队列满了", 0);

        q->data[q->rear++] = e;
    }

    int outQueue(CycleQueue *q, Element *e) {
        if (q->rear = q->front)
            return errCode("队列为空", 0);

        *e = q->data[q->front--];
    }
}

namespace queue_3 {
    void test() {
        queue_link_3::test_1();
    }
}