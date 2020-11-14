/* 两两交换链表中的节点.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给定一个链表，两两交换其中相邻的节点，并返回交换后的链表。

你不能只是单纯的改变节点内部的值，而是需要实际的进行节点交换。

 

示例:

给定 1->2->3->4, 你应该返回 2->1->4->3.

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/swap-nodes-in-pairs
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include "../header/ListNode.h"
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if (head == NULL) {
            return NULL;
        }

        ListNode* first = head;
        ListNode* second = head->next;
        ListNode* newHead = (second == NULL) ? head : second;

        while (second != NULL) {
            ListNode* third = second->next;
            ListNode* fourth = (third == NULL) ? NULL : third->next;
            first->next = (fourth == NULL) ? third : fourth;
            second->next = first;

            first = third;
            second = fourth;
        }

        return newHead;
    }
};

int main()
{
    Solution o;
    CheckResult check;

    ListNode node1(1);
    ListNode node2(2);
    ListNode node3(3);
    ListNode node4(4);
    node1.next = &node2;
    node2.next = &node3;
    node3.next = &node4;
    ListNode* actual = o.swapPairs(&node1);
    check.checkInt(2, actual->val);
    check.checkInt(1, actual->next->val);
    check.checkInt(4, actual->next->next->val);
    check.checkInt(3, actual->next->next->next->val);
    check.checkPoint(NULL, o.swapPairs(actual->next->next->next->next));

    check.checkPoint(NULL, o.swapPairs(NULL));

    node1.next = NULL;
    actual = o.swapPairs(&node1);
    check.checkInt(1, actual->val);
    check.checkPoint(NULL, o.swapPairs(actual->next));

    node1.next = &node2;
    node2.next = NULL;
    actual = o.swapPairs(&node1);
    check.checkInt(2, actual->val);
    check.checkInt(1, actual->next->val);
    check.checkPoint(NULL, o.swapPairs(actual->next->next));

    node1.next = &node2;
    node2.next = &node3;
    node3.next = NULL;
    actual = o.swapPairs(&node1);
    check.checkInt(2, actual->val);
    check.checkInt(1, actual->next->val);
    check.checkInt(3, actual->next->next->val);
    check.checkPoint(NULL, o.swapPairs(actual->next->next->next));

    ListNode node5(5);
    node1.next = &node2;
    node2.next = &node3;
    node3.next = &node4;
    node4.next = &node5;
    node5.next = NULL;
    actual = o.swapPairs(&node1);
    check.checkInt(2, actual->val);
    check.checkInt(1, actual->next->val);
    check.checkInt(4, actual->next->next->val);
    check.checkInt(3, actual->next->next->next->val);
    check.checkInt(5, actual->next->next->next->next->val);
    check.checkPoint(NULL, o.swapPairs(actual->next->next->next->next->next));

    ListNode node6(6);
    node1.next = &node2;
    node2.next = &node3;
    node3.next = &node4;
    node4.next = &node5;
    node5.next = &node6;
    node6.next = NULL;
    actual = o.swapPairs(&node1);
    check.checkInt(2, actual->val);
    check.checkInt(1, actual->next->val);
    check.checkInt(4, actual->next->next->val);
    check.checkInt(3, actual->next->next->next->val);
    check.checkInt(6, actual->next->next->next->next->val);
    check.checkInt(5, actual->next->next->next->next->next->val);
    check.checkPoint(NULL, o.swapPairs(actual->next->next->next->next->next->next));
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
