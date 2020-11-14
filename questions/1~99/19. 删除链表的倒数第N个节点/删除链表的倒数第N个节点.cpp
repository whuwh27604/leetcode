/* 删除链表的倒数第N个节点.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给定一个链表，删除链表的倒数第 n 个节点，并且返回链表的头结点。

示例：

给定一个链表: 1->2->3->4->5, 和 n = 2.

当删除了倒数第二个节点后，链表变为 1->2->3->5.
说明：

给定的 n 保证是有效的。

进阶：

你能尝试使用一趟扫描实现吗？

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/remove-nth-node-from-end-of-list
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include "../header/ListNode.h"
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int count = 0;
        ListNode* current = head;
        ListNode* NthFromEnd = head;

        if (n == 0) {
            return head;
        }

        while (current != NULL) {
            current = current->next;
            count++;
            if (count == n) {
                NthFromEnd = head;
                break;
            }
        }

        if (current == NULL) {
            return head->next;
        }

        current = current->next;
        while (current != NULL) {
            current = current->next;
            NthFromEnd = NthFromEnd->next;
        }

        NthFromEnd->next = NthFromEnd->next->next;
        return head;
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
    ListNode node5(5);
    node1.next = &node2;
    node2.next = &node3;
    node3.next = &node4;
    node4.next = &node5;
    ListNode* actual = o.removeNthFromEnd(&node1, 2);
    check.checkInt(1, actual->val);
    check.checkInt(2, actual->next->val);
    check.checkInt(3, actual->next->next->val);
    check.checkInt(5, actual->next->next->next->val);
    check.checkPoint(NULL, actual->next->next->next->next);

    node1.next = &node2;
    node2.next = &node3;
    node3.next = &node4;
    node4.next = &node5;
    actual = o.removeNthFromEnd(&node1, 3);
    check.checkInt(1, actual->val);
    check.checkInt(2, actual->next->val);
    check.checkInt(4, actual->next->next->val);
    check.checkInt(5, actual->next->next->next->val);
    check.checkPoint(NULL, actual->next->next->next->next);

    node1.next = &node2;
    node2.next = &node3;
    node3.next = &node4;
    node4.next = &node5;
    actual = o.removeNthFromEnd(&node1, 1);
    check.checkInt(1, actual->val);
    check.checkInt(2, actual->next->val);
    check.checkInt(3, actual->next->next->val);
    check.checkInt(4, actual->next->next->next->val);
    check.checkPoint(NULL, actual->next->next->next->next);

    node1.next = &node2;
    node2.next = &node3;
    node3.next = &node4;
    node4.next = &node5;
    actual = o.removeNthFromEnd(&node1, 5);
    check.checkInt(2, actual->val);
    check.checkInt(3, actual->next->val);
    check.checkInt(4, actual->next->next->val);
    check.checkInt(5, actual->next->next->next->val);
    check.checkPoint(NULL, actual->next->next->next->next);

    node1.next = &node2;
    node2.next = &node3;
    node3.next = &node4;
    node4.next = &node5;
    check.checkPoint(&node1, o.removeNthFromEnd(&node1, 0));

    check.checkPoint(NULL, o.removeNthFromEnd(&node5, 1));

    node4.next = &node5;
    actual = o.removeNthFromEnd(&node4, 1);
    check.checkInt(4, actual->val);
    check.checkPoint(NULL, actual->next);

    node4.next = &node5;
    actual = o.removeNthFromEnd(&node4, 2);
    check.checkInt(5, actual->val);
    check.checkPoint(NULL, actual->next);
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
