
#include <iostream>
#include "../header/ListNode.h"

using namespace std;

ListNode* createList(vector<int>& values) {
	ListNode pseudoHead(0);
	ListNode* tail = &pseudoHead;

	for (int value : values) {
		ListNode* node = new ListNode(value);
		tail->next = node;
		tail = node;
	}

	return pseudoHead.next;
}
