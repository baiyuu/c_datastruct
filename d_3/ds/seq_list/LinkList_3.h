
#include <iostream>

using namespace std;

int errCode(string, int);

void ps_int(int *, int);


namespace link_list_3 {

#define newNode (LinkedList) malloc(sizeof(LNode))

    typedef int Element;
    typedef struct Node {
        Element data;
        struct Node *next;
    } LNode, *LinkedList;


    int ps_linklist(LinkedList list) {
        if (list == nullptr)
            return errCode("表为空！", 1);
        LinkedList p = list;
        while (p != nullptr) {
            printf("%d\t", p->data);
            p = p->next;
        }
        puts("");
    }


    LinkedList create(int n) {
        LinkedList list = nullptr, p, r;
        for (int i = 0; i < n; i++) {
            p = newNode;
            p->data = i + 1;
            p->next = nullptr;
            if (list == nullptr) {
                list = p;
            } else {
                r->next = p;
            }
            r = p;
        }
        return list;
    }

    void insert(LinkedList list, int afterNum, Element e) {
        LinkedList p = newNode;
        p->data = e;

        LinkedList q = list, r;
        while (q->next != nullptr && q->data != afterNum)
            q = q->next;

        r = q->next;
        q->next = p;
        p->next = r;
    }

    int del(LinkedList list, int i, Element *deleted) {


        LinkedList p = list, f;
        if (i < 0)
            return errCode("删除位置有误", -1);
        if (i == 1) {

        }
        int j = 1;
        while (j < i && p != nullptr) {
            f = p;
            p = p->next;
            j++;
        }

        if (j != i)
            return errCode("删除失败，元素不存在", -1);

        *deleted = p->data;
        f->next = p->next;
        free(p);
    }


    int destory(LinkedList list) {
        LinkedList p = list;
        while (list != nullptr) {
            list = p->next;
            free(p);
            p = list;
        }
    }


    void test() {
        LinkedList list = create(10);
        ps_linklist(list);
        insert(list, 4, 33);
        ps_linklist(list);
        int deleted;
        del(list, 7, &deleted);
        ps_linklist(list);
        std::cout << "deleted=" << deleted << std::endl;
        destory(list);
    }


}

namespace LinkList_3 {
    void test() {
        link_list_3::test();
    }
}