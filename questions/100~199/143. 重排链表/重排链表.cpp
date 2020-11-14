/* 重排链表.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给定一个单链表 L：L0→L1→…→Ln-1→Ln ，
将其重新排列后变为： L0→Ln→L1→Ln-1→L2→Ln-2→…

你不能只是单纯的改变节点内部的值，而是需要实际的进行节点交换。

示例 1:

给定链表 1->2->3->4, 重新排列为 1->4->2->3.
示例 2:

给定链表 1->2->3->4->5, 重新排列为 1->5->2->4->3.

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/reorder-list
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    void reorderList(ListNode* head) {
        if ((head == NULL) || (head->next == NULL)) {
            return;
        }

        ListNode* firstHalfTail = findFirstHalfTail(head);
        ListNode* secondHalf = reverseList(firstHalfTail->next);  // 翻转后半部分
        firstHalfTail->next = NULL;  // 断开前后部分
        reorder(head, secondHalf);
    }

    ListNode* findFirstHalfTail(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head->next;

        while (fast != NULL) {
            fast = fast->next;
            if (fast == NULL) {
                break;
            }

            slow = slow->next;
            fast = fast->next;
        }

        return slow;
    }

    ListNode* reverseList(ListNode* head) {
        ListNode* prev = NULL;
        ListNode* current = head;
        while (current != NULL) {
            ListNode* next = current->next;
            current->next = prev;
            prev = current;
            current = next;
        }

        return prev;
    }

    void reorder(ListNode* firstHalf, ListNode* secondHalf) {
        while (secondHalf != NULL) {
            ListNode* tmp = secondHalf->next;
            secondHalf->next = firstHalf->next;
            firstHalf->next = secondHalf;

            firstHalf = secondHalf->next;
            secondHalf = tmp;
        }
    }
};

int main()
{
    Solution o;
    CheckResult check;

    o.reorderList(NULL);

    ListNode node1(1);
    o.reorderList(&node1);
    check.checkInt(1, node1.val);
    check.checkPoint(NULL, node1.next);

    ListNode node2(2);
    node1.next = &node2;
    o.reorderList(&node1);
    check.checkInt(1, node1.val);
    check.checkInt(2, node1.next->val);
    check.checkPoint(NULL, node1.next->next);

    ListNode node3(3);
    node1.next = &node2;
    node2.next = &node3;
    o.reorderList(&node1);
    check.checkInt(1, node1.val);
    check.checkInt(3, node1.next->val);
    check.checkInt(2, node1.next->next->val);
    check.checkPoint(NULL, node1.next->next->next);

    ListNode node4(4);
    node1.next = &node2;
    node2.next = &node3;
    node3.next = &node4;
    o.reorderList(&node1);
    check.checkInt(1, node1.val);
    check.checkInt(4, node1.next->val);
    check.checkInt(2, node1.next->next->val);
    check.checkInt(3, node1.next->next->next->val);
    check.checkPoint(NULL, node1.next->next->next->next);

    ListNode node5(5);
    node1.next = &node2;
    node2.next = &node3;
    node3.next = &node4;
    node4.next = &node5;
    o.reorderList(&node1);
    check.checkInt(1, node1.val);
    check.checkInt(5, node1.next->val);
    check.checkInt(2, node1.next->next->val);
    check.checkInt(4, node1.next->next->next->val);
    check.checkInt(3, node1.next->next->next->next->val);
    check.checkPoint(NULL, node1.next->next->next->next->next);

    ListNode node6(6);
    node1.next = &node2;
    node2.next = &node3;
    node3.next = &node4;
    node4.next = &node5;
    node5.next = &node6;
    o.reorderList(&node1);
    check.checkInt(1, node1.val);
    check.checkInt(6, node1.next->val);
    check.checkInt(2, node1.next->next->val);
    check.checkInt(5, node1.next->next->next->val);
    check.checkInt(3, node1.next->next->next->next->val);
    check.checkInt(4, node1.next->next->next->next->next->val);
    check.checkPoint(NULL, node1.next->next->next->next->next->next);
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
