/* 移除链表元素.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
删除链表中等于给定值 val 的所有节点。

示例:

输入: 1->2->6->3->4->5->6, val = 6
输出: 1->2->3->4->5
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        ListNode pseudoHead(0);
        pseudoHead.next = head;
        ListNode* prev = &pseudoHead;
        ListNode* current = head;
        while (current != NULL) {
            if (current->val == val) {
                prev->next = current->next;
            }
            else {
                prev = current;
            }
            current = current->next;
        }

        return pseudoHead.next;
    }
};

int main()
{
    Solution o;
    CheckResult check;

    ListNode node4(4);
    ListNode node3(3);
    ListNode node2(2);
    ListNode node1(1);
    node1.next = &node2;
    node2.next = &node3;
    node3.next = &node4;
    ListNode* actual = o.removeElements(&node1, 1);
    check.checkSingleList(&node2, actual);

    node1.next = &node2;
    actual = o.removeElements(&node1, 2);
    check.checkSingleList(&node1, actual);

    node1.next = &node2;
    node2.next = &node3;
    node3.next = &node4;
    actual = o.removeElements(&node1, 3);
    check.checkSingleList(&node1, actual);

    node1.next = &node2;
    node2.next = &node3;
    node3.next = &node4;
    actual = o.removeElements(&node1, 4);
    check.checkSingleList(&node1, actual);

    node3.val = 6;
    node4.val = 3;
    ListNode node5(4);
    ListNode node6(5);
    ListNode node7(6);
    node1.next = &node2;
    node2.next = &node3;
    node3.next = &node4;
    node4.next = &node5;
    node5.next = &node6;
    node6.next = &node7;
    actual = o.removeElements(&node1, 6);
    check.checkSingleList(&node1, actual);

    actual = o.removeElements(NULL, 6);
    check.checkSingleList(NULL, actual);
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
