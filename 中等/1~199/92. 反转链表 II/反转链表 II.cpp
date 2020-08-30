/* 反转链表 II.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
反转从位置 m 到 n 的链表。请使用一趟扫描完成反转。

说明:
1 ≤ m ≤ n ≤ 链表长度。

示例:

输入: 1->2->3->4->5->NULL, m = 2, n = 4
输出: 1->4->3->2->5->NULL

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/reverse-linked-list-ii
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        ListNode pseudo(0);
        pseudo.next = head;
        ListNode* current = &pseudo;
        ListNode* nodeBeforeM = current;
        int count = 0;

        while (count < m) {
            nodeBeforeM = current;
            current = current->next;
            count++;
        }

        ListNode* last = current;
        ListNode* prev = current;
        ListNode* next = current->next;

        while (count < n) {
            current = next;
            next = (next == NULL) ? NULL : next->next;
            current->next = prev;
            prev = current;
            count++;
        }

        last->next = next;
        nodeBeforeM->next = current;

        return pseudo.next;
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
    node5.next = NULL;
    ListNode* actual = o.reverseBetween(&node1, 2, 4);
    check.checkInt(1, actual->val);
    check.checkInt(4, actual->next->val);
    check.checkInt(3, actual->next->next->val);
    check.checkInt(2, actual->next->next->next->val);
    check.checkInt(5, actual->next->next->next->next->val);
    check.checkPoint(NULL, actual->next->next->next->next->next);

    node1.val = 1;
    node2.val = 2;
    node3.val = 3;
    node4.val = 4;
    node5.val = 5;
    node1.next = &node2;
    node2.next = &node3;
    node3.next = &node4;
    node4.next = &node5;
    node5.next = NULL;
    actual = o.reverseBetween(&node1, 1, 1);
    check.checkInt(1, actual->val);
    check.checkInt(2, actual->next->val);
    check.checkInt(3, actual->next->next->val);
    check.checkInt(4, actual->next->next->next->val);
    check.checkInt(5, actual->next->next->next->next->val);
    check.checkPoint(NULL, actual->next->next->next->next->next);

    node1.val = 1;
    node2.val = 2;
    node3.val = 3;
    node4.val = 4;
    node5.val = 5;
    node1.next = &node2;
    node2.next = &node3;
    node3.next = &node4;
    node4.next = &node5;
    node5.next = NULL;
    actual = o.reverseBetween(&node1, 5, 5);
    check.checkInt(1, actual->val);
    check.checkInt(2, actual->next->val);
    check.checkInt(3, actual->next->next->val);
    check.checkInt(4, actual->next->next->next->val);
    check.checkInt(5, actual->next->next->next->next->val);
    check.checkPoint(NULL, actual->next->next->next->next->next);

    node1.val = 1;
    node2.val = 2;
    node3.val = 3;
    node4.val = 4;
    node5.val = 5;
    node1.next = &node2;
    node2.next = &node3;
    node3.next = &node4;
    node4.next = &node5;
    node5.next = NULL;
    actual = o.reverseBetween(&node1, 1, 2);
    check.checkInt(2, actual->val);
    check.checkInt(1, actual->next->val);
    check.checkInt(3, actual->next->next->val);
    check.checkInt(4, actual->next->next->next->val);
    check.checkInt(5, actual->next->next->next->next->val);
    check.checkPoint(NULL, actual->next->next->next->next->next);

    node1.val = 1;
    node2.val = 2;
    node3.val = 3;
    node4.val = 4;
    node5.val = 5;
    node1.next = &node2;
    node2.next = &node3;
    node3.next = &node4;
    node4.next = &node5;
    node5.next = NULL;
    actual = o.reverseBetween(&node1, 3, 5);
    check.checkInt(1, actual->val);
    check.checkInt(2, actual->next->val);
    check.checkInt(5, actual->next->next->val);
    check.checkInt(4, actual->next->next->next->val);
    check.checkInt(3, actual->next->next->next->next->val);
    check.checkPoint(NULL, actual->next->next->next->next->next);

    node1.val = 1;
    node2.val = 2;
    node3.val = 3;
    node4.val = 4;
    node5.val = 5;
    node1.next = &node2;
    node2.next = &node3;
    node3.next = &node4;
    node4.next = &node5;
    node5.next = NULL;
    actual = o.reverseBetween(&node1, 1, 5);
    check.checkInt(5, actual->val);
    check.checkInt(4, actual->next->val);
    check.checkInt(3, actual->next->next->val);
    check.checkInt(2, actual->next->next->next->val);
    check.checkInt(1, actual->next->next->next->next->val);
    check.checkPoint(NULL, actual->next->next->next->next->next);

    node1.val = 1;
    node1.next = NULL;
    actual = o.reverseBetween(&node1, 1, 1);
    check.checkInt(1, actual->val);
    check.checkPoint(NULL, actual->next);

    node1.val = 1;
    node2.val = 2;
    node1.next = &node2;
    node2.next = NULL;
    actual = o.reverseBetween(&node1, 1, 2);
    check.checkInt(2, actual->val);
    check.checkInt(1, actual->next->val);
    check.checkPoint(NULL, actual->next->next);
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
