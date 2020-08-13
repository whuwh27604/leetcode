#ifndef __LISTNODE_H__
#define __LISTNODE_H__

struct ListNode {
	int val;
	ListNode* next;
	ListNode(int x) : val(x), next(NULL) {}
};

#endif