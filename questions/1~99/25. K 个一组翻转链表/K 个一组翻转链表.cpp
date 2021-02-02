/* K 个一组翻转链表.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你一个链表，每 k 个节点一组进行翻转，请你返回翻转后的链表。

k 是一个正整数，它的值小于或等于链表的长度。

如果节点总数不是 k 的整数倍，那么请将最后剩余的节点保持原有顺序。

 

示例：

给你这个链表：1->2->3->4->5

当 k = 2 时，应当返回: 2->1->4->3->5

当 k = 3 时，应当返回: 3->2->1->4->5

 

说明：

你的算法只能使用常数的额外空间。
你不能只是单纯的改变节点内部的值，而是需要实际进行节点交换。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/reverse-nodes-in-k-group
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        int count = 0;
        ListNode* node = head;
        ListNode* segmentHead = head;
        ListNode* segmentTail;
        ListNode* prevSegmentTail = NULL;
        ListNode* newHead = NULL;

        while (node != NULL) {
            segmentTail = node;
            node = node->next;

            if (++count < k) {
                continue;
            }
            
            reverseList(segmentHead, segmentTail);

            if (newHead == NULL) {
                newHead = segmentTail;
            }

            if (prevSegmentTail != NULL) {
                prevSegmentTail->next = segmentTail;
            }

            prevSegmentTail = segmentHead;
            segmentHead = node;
            count = 0;
        }

        if (prevSegmentTail != NULL) {
            prevSegmentTail->next = segmentHead;
        }
        
        return newHead;
    }

    void reverseList(ListNode* head, ListNode* tail) {
        ListNode* prev = NULL;
        ListNode* current = head;
        tail->next = NULL;

        while (current != NULL) {
            ListNode* next = current->next;
            current->next = prev;
            prev = current;
            current = next;
        }
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<int> values = { 1,2,3,4,5 };
    ListNode* head = createList(values);
    values = { 2,1,4,3,5 };
    check.checkSingleList(createList(values), o.reverseKGroup(head, 2));

    values = { 1,2,3,4,5 };
    head = createList(values);
    values = { 3,2,1,4,5 };
    check.checkSingleList(createList(values), o.reverseKGroup(head, 3));

    values = { 1,2,3,4,5 };
    head = createList(values);
    values = { 1,2,3,4,5 };
    check.checkSingleList(createList(values), o.reverseKGroup(head, 1));

    values = { 1,2,3,4,5 };
    head = createList(values);
    values = { 4,3,2,1,5 };
    check.checkSingleList(createList(values), o.reverseKGroup(head, 4));

    values = { 1,2,3,4,5 };
    head = createList(values);
    values = { 5,4,3,2,1 };
    check.checkSingleList(createList(values), o.reverseKGroup(head, 5));

    values = {  };
    head = createList(values);
    values = {  };
    check.checkSingleList(createList(values), o.reverseKGroup(head, 5));

    values = { 1 };
    head = createList(values);
    values = { 1 };
    check.checkSingleList(createList(values), o.reverseKGroup(head, 1));

    values = { 1,5 };
    head = createList(values);
    values = { 5,1 };
    check.checkSingleList(createList(values), o.reverseKGroup(head, 2));
}

// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门使用技巧: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件
