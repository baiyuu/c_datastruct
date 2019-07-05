

#include <stddef.h>

typedef int DataType;

struct HNode {
    DataType key;
    struct HNode *link;
};
#define HASHMAXLEMGTH 100;

typedef struct HNode *HashList[100];

int main() {

    return 0;
}

//插入
int insert(HashList list, DataType data) {
    int i, d;
    i = hash(data);
    while (list[d] != NULL && list[d] != data) {
        d = (d + 1) % HASHMAXLEMGTH;
        if (d == i) {
            return -1;
        }

        if (list[d] != data) {
            list[d] = data;
            return d;
        }

    }

}

int hash(DataType k) {
    return 0;
}

int reHash(DataType k) {
    return 0;
}

