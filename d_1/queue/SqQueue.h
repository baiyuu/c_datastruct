
#include <iostream>

#define SIZE 4
using namespace std;
typedef int Element;
/*
 * INIT 
 * destory
 * clear
 * isEmpty
 * getHead
 * insert
 * delete
 * length
 */
namespace SqQueue {

    int errMsg(string msg, int code = -1) {
        std::cout << msg << std::endl;
        return code;
    }

    //队列长度 (rear-front+size)%size

    typedef struct {
        Element data[SIZE];
        int front;
        int rear;
    } SqQueue;

    int init(SqQueue *s) {
        s->front = 0;
        s->rear = 0;
        return 1;
    }

    int size(SqQueue s) {
        return (s.rear - s.front + SIZE) % SIZE;
    }

    void ps(SqQueue s) {
        printf("\n");
        for (int i = s.front; i < s.rear; i++)
            printf("%d\t", s.data[i]);
    }

    int insert(SqQueue *s, Element e) {
        if ((s->rear + 1) % SIZE == s->front)
            return errMsg("队列满了");

        s->data[s->rear] = e;
        s->rear = (s->rear + 1) % SIZE;
        return 1;
    }

    int get(SqQueue *s, Element *e) {
        if (s->rear == 0 && s->front == 0)
            return errMsg("空队列，没有元素");

        *e = s->data[s->front++];
        s->front = (s->front + 1) % SIZE;
        return 1;
    }

    void testInsert() {
        SqQueue sq;
        int a = -1;
        init(&sq);
        ps(sq);
        get(&sq, &a);
        std::cout << "get data=" << a << std::endl;
        insert(&sq, 123);
        insert(&sq, 245);
        get(&sq, &a);
        std::cout << "get data=" << a << std::endl;
        get(&sq, &a);
        std::cout << "get data=" << a << std::endl;
        insert(&sq, 346);
        get(&sq, &a);
        std::cout << "get data=" << a << std::endl;
        ps(sq);
    }

    void run() {
        testInsert();
    }
}