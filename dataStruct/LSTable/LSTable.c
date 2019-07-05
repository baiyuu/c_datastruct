

#include <stddef.h>

typedef int DataType;

typedef struct Node {
    int flag;
    union {
        DataType data;
        struct Node *pointer;
    };
    struct Node *link;
} LSNode, *LSLinkList;

int main() {

    return 0;
}

int length_(LSLinkList list) {
    LSLinkList p;
    p = list->pointer;
    int n = 0;
    while (p != NULL) {
        n++;
        p = p->link;
    }
}