#ifndef __LIST_NODE_WITH_RANDOM_H__
#define __LIST_NODE_WITH_RANDOM_H__

#include <iostream>

using namespace std;

class Node {
public:
	int val;
	Node* next;
	Node* random;

	Node(int _val) {
		val = _val;
		next = NULL;
		random = NULL;
	}
};

#endif
