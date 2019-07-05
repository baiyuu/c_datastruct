
#include <iostream>
#include <iostream>
#include <cstring>

typedef int Element;
using namespace std;
namespace SingleCircular {

    void run() {
        std::cout << "单向循环" << std::endl;
    }
}
namespace DoubleCircular {
    typedef struct Node {
        Element data;
        Node *front;
        Node *rear;
    } Dnode, *LinkedList;

    int insert() {
        
    }

    void run() {
        std::cout << "双向循环" << std::endl;
    }
}