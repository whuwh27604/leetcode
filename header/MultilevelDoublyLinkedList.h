#ifndef __MULTILEVEL_DOUBLY_LINKED_LIST_H__
#define __MULTILEVEL_DOUBLY_LINKED_LIST_H__

class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;

    Node(int _val) : val(_val), prev(NULL), next(NULL), child(NULL) {}
};

#endif