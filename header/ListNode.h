#ifndef __LISTNODE_H__
#define __LISTNODE_H__

#include <vector>

using namespace std;

struct ListNode {
	int val;
	ListNode* next;
	ListNode(int x) : val(x), next(NULL) {}
};

extern ListNode* createList(vector<int>& values);

#endif