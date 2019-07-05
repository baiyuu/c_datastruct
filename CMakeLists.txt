cmake_minimum_required(VERSION 3.12)
project(ds_2)

set(CMAKE_CXX_STANDARD 14)

add_executable(ds_2 main.cpp d_1/sqList/SqList.h
        d_1/sqList/SqLinkedList.h
        d_1/sqList/CircularLinkedList.h
        d_1/run.h d_1/stack/SqStack.h d_1/stack/LinkStack.h d_1/queue/SqQueue.h d_1/queue/LinkQueue.h d_1/string/String.h d_1/tree/BTree.h d_1/graph/Graph.h d_1/search/Search.h)