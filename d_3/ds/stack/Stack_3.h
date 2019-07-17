
#include <iostream>

using namespace std;

void ps_int(int *, int);

namespace sq_stack_3 {
#define SQ_STACK_SIZE 10
    typedef int Element;
    typedef struct {
        Element *data;
        int top;
        int length;
        int capicity;
    } SqStack;

    SqStack create() {
        int data[] = {11, 22, 33, 44, 55, 66};
        SqStack s = {
                data,
                5,
                6,
                10,
        };
        return s;
    }

    void init(SqStack *s) {
        s->data = (Element *) malloc(sizeof(Element) * SQ_STACK_SIZE);
        s->top = -1;
        s->length = 0;
        s->capicity = SQ_STACK_SIZE;
        for (int i = 0; i < s->capicity; i++)
            s->data[i] = 0;
    }

    int push(SqStack *s, Element e, bool autoAdd = false) {
        if (autoAdd) {
            //满了追加空间
            if (s->length == s->capicity) {
//                s->data = (Element *) realloc(s->data, sizeof(Element) * (s->capicity + 10));
                s->data = (int *) realloc(s->data, (s->capicity + 10) * sizeof(int));
            }
        } else {
            if (s->top == s->capicity - 1)
                return errCode("满了，放不下了", -1);
        }
        s->top++;
        s->data[s->top] = e;
        s->length++;
        return 1;
    }

    int pop(SqStack *s, Element *poped) {

        if (s->length <= 0)
            return errCode("栈空，没有数据", -1);

        *poped = s->data[s->top--];
        s->length--;
    }



    void test() {
        SqStack s;
        init(&s);

        ps_int(s.data, s.length);
        push(&s, 23);
        push(&s, 25);
        push(&s, 24);
        ps_int(s.data, s.length);

        int p;
        pop(&s, &p);
        ps_int(s.data, s.length);
        std::cout << "get data:=" << p << std::endl;
    }
}


namespace Stack_3 {


    void test() {
        sq_stack_3::test();
    }
}