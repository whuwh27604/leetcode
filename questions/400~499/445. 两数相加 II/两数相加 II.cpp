/* 两数相加 II.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你两个 非空 链表来代表两个非负整数。数字最高位位于链表开始位置。它们的每个节点只存储一位数字。将这两数相加会返回一个新的链表。

你可以假设除了数字 0 之外，这两个数字都不会以零开头。

 

进阶：

如果输入链表不能修改该如何处理？换句话说，你不能对列表中的节点进行翻转。

 

示例：

输入：(7 -> 2 -> 4 -> 3) + (5 -> 6 -> 4)
输出：7 -> 8 -> 0 -> 7

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/add-two-numbers-ii
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <stack>
#include "../header/ListNode.h"
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        stack<int> s1, s2;

        ListNode* node = l1;
        while (node != NULL) {
            s1.push(node->val);
            node = node->next;
        }

        node = l2;
        while (node != NULL) {
            s2.push(node->val);
            node = node->next;
        }

        int num, carrier = 0;
        ListNode* next = NULL;
        while (!s1.empty() && !s2.empty()) {
            num = s1.top() + s2.top() + carrier;
            s1.pop();
            s2.pop();
            carrier = num / 10;
            num %= 10;
            node = new ListNode(num);
            node->next = next;
            next = node;
        }

        while (!s1.empty()) {
            num = s1.top() + carrier;
            s1.pop();
            carrier = num / 10;
            num %= 10;
            node = new ListNode(num);
            node->next = next;
            next = node;
        }

        while (!s2.empty()) {
            num = s2.top() + carrier;
            s2.pop();
            carrier = num / 10;
            num %= 10;
            node = new ListNode(num);
            node->next = next;
            next = node;
        }

        if (carrier != 0) {
            node = new ListNode(carrier);
            node->next = next;
        }

        return node;
    }
};

int main()
{
    Solution o;
    CheckResult check;

    ListNode node1(7);
    ListNode node2(2);
    ListNode node3(4);
    ListNode node4(3);
    ListNode node5(5);
    ListNode node6(6);
    ListNode node7(4);
    node1.next = &node2;
    node2.next = &node3;
    node3.next = &node4;
    node5.next = &node6;
    node6.next = &node7;
    ListNode* actual = o.addTwoNumbers(&node1, &node5);
    check.checkInt(7, actual->val);
    check.checkInt(8, actual->next->val);
    check.checkInt(0, actual->next->next->val);
    check.checkInt(7, actual->next->next->next->val);
    check.checkPoint(NULL, actual->next->next->next->next);

    node1.val = 1;
    node2.val = 2;
    node1.next = &node2;
    node2.next = NULL;
    node3.val = 0;
    node3.next = NULL;
    actual = o.addTwoNumbers(&node1, &node3);
    check.checkInt(1, actual->val);
    check.checkInt(2, actual->next->val);
    check.checkPoint(NULL, actual->next->next);

    node1.val = 1;
    node1.next = NULL;
    node2.val = 9;
    node3.val = 9;
    node2.next = &node3;
    node3.next = NULL;
    actual = o.addTwoNumbers(&node1, &node2);
    check.checkInt(1, actual->val);
    check.checkInt(0, actual->next->val);
    check.checkInt(0, actual->next->next->val);
    check.checkPoint(NULL, actual->next->next->next);

    node1.val = 7;
    node1.next = NULL;
    node2.val = 5;
    node2.next = NULL;
    actual = o.addTwoNumbers(&node1, &node2);
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
