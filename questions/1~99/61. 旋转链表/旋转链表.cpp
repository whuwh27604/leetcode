/* 旋转链表.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给定一个链表，旋转链表，将链表每个节点向右移动 k 个位置，其中 k 是非负数。

示例 1:

输入: 1->2->3->4->5->NULL, k = 2
输出: 4->5->1->2->3->NULL
解释:
向右旋转 1 步: 5->1->2->3->4->NULL
向右旋转 2 步: 4->5->1->2->3->NULL
示例 2:

输入: 0->1->2->NULL, k = 4
输出: 2->0->1->NULL
解释:
向右旋转 1 步: 2->0->1->NULL
向右旋转 2 步: 1->2->0->NULL
向右旋转 3 步: 0->1->2->NULL
向右旋转 4 步: 2->0->1->NULL

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/rotate-list
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if (head == NULL) {
            return NULL;
        }

        int nodeCount = 1;
        ListNode* tail = head;

        while (tail->next != NULL) {
            tail = tail->next;
            nodeCount++;
        }

        int steps = k % nodeCount;
        if (steps == 0) {
            return head;
        }

        steps = nodeCount - steps - 1;
        ListNode* node = head;
        while (steps-- > 0) {
            node = node->next;
        }

        ListNode* newHead = node->next;
        node->next = NULL;
        tail->next = head;

        return newHead;
    }
};

int main()
{
    Solution o;
    CheckResult check;

    ListNode* actual = o.rotateRight(NULL, 1);
    ListNode* expected = NULL;
    check.checkPoint(expected, actual);

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
    actual = o.rotateRight(&node1, 2);
    check.checkInt(4, actual->val);
    check.checkInt(5, actual->next->val);
    check.checkInt(1, actual->next->next->val);
    check.checkInt(2, actual->next->next->next->val);
    check.checkInt(3, actual->next->next->next->next->val);
    check.checkPoint(NULL, actual->next->next->next->next->next);

    node1.next = &node2;
    node2.next = &node3;
    node3.next = &node4;
    node4.next = &node5;
    node5.next = NULL;
    actual = o.rotateRight(&node1, 0);
    check.checkInt(1, actual->val);
    check.checkInt(2, actual->next->val);
    check.checkInt(3, actual->next->next->val);
    check.checkInt(4, actual->next->next->next->val);
    check.checkInt(5, actual->next->next->next->next->val);
    check.checkPoint(NULL, actual->next->next->next->next->next);

    node1.next = &node2;
    node2.next = &node3;
    node3.next = &node4;
    node4.next = &node5;
    node5.next = NULL;
    actual = o.rotateRight(&node1, 1);
    check.checkInt(5, actual->val);
    check.checkInt(1, actual->next->val);
    check.checkInt(2, actual->next->next->val);
    check.checkInt(3, actual->next->next->next->val);
    check.checkInt(4, actual->next->next->next->next->val);
    check.checkPoint(NULL, actual->next->next->next->next->next);

    node1.next = &node2;
    node2.next = &node3;
    node3.next = &node4;
    node4.next = &node5;
    node5.next = NULL;
    actual = o.rotateRight(&node1, 4);
    check.checkInt(2, actual->val);
    check.checkInt(3, actual->next->val);
    check.checkInt(4, actual->next->next->val);
    check.checkInt(5, actual->next->next->next->val);
    check.checkInt(1, actual->next->next->next->next->val);
    check.checkPoint(NULL, actual->next->next->next->next->next);

    node1.next = &node2;
    node2.next = &node3;
    node3.next = &node4;
    node4.next = &node5;
    node5.next = NULL;
    actual = o.rotateRight(&node1, 5);
    check.checkInt(1, actual->val);
    check.checkInt(2, actual->next->val);
    check.checkInt(3, actual->next->next->val);
    check.checkInt(4, actual->next->next->next->val);
    check.checkInt(5, actual->next->next->next->next->val);
    check.checkPoint(NULL, actual->next->next->next->next->next);

    node1.next = NULL;
    actual = o.rotateRight(&node1, 1);
    check.checkInt(1, actual->val);
    check.checkPoint(NULL, actual->next);

    node1.next = NULL;
    actual = o.rotateRight(&node1, 2);
    check.checkInt(1, actual->val);
    check.checkPoint(NULL, actual->next);

    node1.next = &node2;
    node2.next = NULL;
    actual = o.rotateRight(&node1, 1);
    check.checkInt(2, actual->val);
    check.checkInt(1, actual->next->val);
    check.checkPoint(NULL, actual->next->next);

    node1.next = &node2;
    node2.next = NULL;
    actual = o.rotateRight(&node1, 2);
    check.checkInt(1, actual->val);
    check.checkInt(2, actual->next->val);
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
