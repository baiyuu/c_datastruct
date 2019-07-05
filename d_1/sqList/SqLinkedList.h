
#include <iostream>
#include <cstring>

using namespace std;


namespace LinkedList {
#define newNode (LinkedList)malloc(sizeof(LNode));
    typedef int Element;
    typedef struct Node {
        Element data;
        Node *link;
    } LNode, *LinkedList;

    int errMsg(string msg, int code = -1) {
        std::cout << msg << std::endl;
        return code;
    }

    /**
     * 创建一个链表
     * @param n 
     * @return 
     */
    LinkedList create(int n = 5) {
        LinkedList list = nullptr, q, w;
        for (int i = n; i > 0; i--) {
            q = newNode;
            q->data = i;
            q->link = nullptr;
            if (list == nullptr) {
                list = q;
            } else {
                w->link = q;
            }
            w = q;
        }
        return list;
    }

    /**
     * 遍历链表
     * @param list 
     */
    void ps(LinkedList list, string note = "--") {
        std::cout << note;
        while (list != nullptr) {
            std::cout << list->data << "\t";
            list = list->link;
        }
        std::cout << "" << std::endl;
    }

    /**
     * 获取链表中第 i 个元素，并赋值个e
     * @param list 
     * @param i 
     * @param e 
     */
    void get(LinkedList list, int i, Element *e) {
        LinkedList p = list;
        if (list == nullptr) {
            std::cout << "空表，没有数据" << std::endl;
            return;
        }
        int j = 0;
        while (j < i - 1 && p != nullptr) {
            p = p->link;
            j++;
        }
        if (j > i || p == nullptr) {
            std::cout << "当前位置没有数据！" << std::endl;
            return;
        }
        *e = p->data;
    }

    void testGet() {
        LinkedList list = create();
        Element a = 0;
        Element *e = &a;
        get(list, 22, e);
        std::cout << *e << std::endl;
    }

    /**
     * 在指定位置插入元素
     * @param list 
     * @param i 
     * @param e 
     * @return 
     */
    int insertOnDesignatedSpot(LinkedList list, int i, Element e) {
        LinkedList q, r, p = list;
        int j = 0;
        while (j < i && p != nullptr) {
            r = p;
            p = p->link;
            j++;
        }

        if (j > i || p == nullptr)
            return errMsg("插入数据异常", -1);
        q = newNode;
        q->data = e;
        q->link = p;
        r->link = q;
        return errMsg("success", 1);
    }

    LinkedList list = create();

    /**
     * 在指定元素后插入元素 
     * @param list 
     * @param cursor 
     * @param e 
     * @return 
     */
    int insertAfterElement(LinkedList list, const Element cursor, const Element e) {
        LinkedList p = list, q, r;
        q = newNode;
        r = newNode;
        r->data = e;
        while (p != nullptr) {
            if (p->data == cursor) {
                q->link = p->link;
                p->link = r;
                r->link = q->link;
                free(q);
                break;
            }
            p = p->link;
        }
        if (p == nullptr) {
            return errMsg("指定元素不存在！", -1);
        }
        return errMsg("在指定元素前后插入成功", 1);
    }


    void testInsert() {
        LinkedList list = create();
        ps(list);
//        insertOnDesignatedSpot(list, 1, 123);
        insertAfterElement(list, 4, 33);
        ps(list);
    }

    /**
     * 删除链表中的第 i 个结点
     * @param list 
     * @param i 
     * @param e 
     */
    int del(LinkedList list, int i, Element *e) {
        int j = 1;
        LinkedList p = list, q;
        while (p->link != nullptr && j < i) {
            ++j;
            p = p->link;
        }

        if (p == nullptr || j > i)
            return errMsg("需要删除的数据不存在", -1);

        q = p->link;
        printf("q:");
        ps(q);
        printf("P1:");
        ps(p);
        p->link = q->link;
        printf("P2:");
        ps(p);
        *e = p->data;
        free(q);
        ps(list);

        return errMsg("删除成功");
    }

    void deleteEle(LinkedList list, Element e) {
        LinkedList p, q;
        p = list;
        while (p != NULL) {
            if (p->link->data == e) {
                q = p->link->link;
                break;
            }
            p = p->link;
        }
        p->link = q;
        free(q);
    }

    void testDel() {
        int a = 0, *p = &a;
//        del(list, 3, p);
//        deleteEle(list, 3);
        ps(list);
        std::cout << "删除的：" << *p << std::endl;
    }

    /**
     * 清除 链表
     * @param list 
     * @return 
     */
    int destory(LinkedList list) {
        LinkedList p = list;
        while (list != nullptr) {
            list = p->link;
            free(p);
            p = list;
        }
        ps(list);

    }


    void run() {
//        ps(list);
//        testGet();
        testInsert();
        //testDel();

    }

}