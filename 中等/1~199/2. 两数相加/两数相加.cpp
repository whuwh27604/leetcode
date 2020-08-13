/* 两数相加.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给出两个 非空 的链表用来表示两个非负的整数。其中，它们各自的位数是按照 逆序 的方式存储的，并且它们的每个节点只能存储 一位 数字。

如果，我们将这两个数相加起来，则会返回一个新的链表来表示它们的和。

您可以假设除了数字 0 之外，这两个数都不会以 0 开头。

示例：

输入：(2 -> 4 -> 3) + (5 -> 6 -> 4)
输出：7 -> 0 -> 8
原因：342 + 465 = 807

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/add-two-numbers
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include "../header/ListNode.h"
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int carrier = 0, num;
        ListNode* head = l1;
        ListNode* tail = NULL;

        while ((l1 != NULL) && (l2 != NULL)) {
            num = l1->val + l2->val + carrier;
            l1->val = num % 10;
            carrier = num / 10;
            tail = l1;

            l1 = l1->next;
            l2 = l2->next;
        }

        while (l1 != NULL) {
            num = l1->val + carrier;
            l1->val = num % 10;
            carrier = num / 10;
            tail = l1;

            l1 = l1->next;
        }

        while (l2 != NULL) {
            num = l2->val + carrier;
            l2->val = num % 10;
            carrier = num / 10;
            tail->next = l2;
            tail = l2;

            l2 = l2->next;
        }

        if (carrier == 1) {
            ListNode* node = new ListNode(1);
            tail->next = node;
        }

        return head;
    }
};

int main()
{
    Solution o;
    CheckResult check;

    ListNode node1(2);
    ListNode node2(4);
    ListNode node3(3);
    ListNode node4(5);
    ListNode node5(6);
    ListNode node6(4);
    node1.next = &node2;
    node2.next = &node3;
    node4.next = &node5;
    node5.next = &node6;
    ListNode* actual = o.addTwoNumbers(&node1, &node4);
    check.checkInt(7, actual->val);
    check.checkInt(0, actual->next->val);
    check.checkInt(8, actual->next->next->val);
    check.checkPoint(NULL, actual->next->next->next);

    node1.val = 2;
    node2.val = 4;
    node3.val = 9;
    node4.val = 5;
    node5.val = 6;
    node1.next = &node2;
    node2.next = &node3;
    node4.next = &node5;
    node3.next = NULL;
    node5.next = NULL;
    actual = o.addTwoNumbers(&node1, &node4);
    check.checkInt(7, actual->val);
    check.checkInt(0, actual->next->val);
    check.checkInt(0, actual->next->next->val);
    check.checkInt(1, actual->next->next->next->val);
    check.checkPoint(NULL, actual->next->next->next->next);

    node1.val = 2;
    node2.val = 4;
    node3.val = 9;
    node4.val = 5;
    node5.val = 6;
    node1.next = &node2;
    node2.next = &node3;
    node4.next = &node5;
    node3.next = NULL;
    node5.next = NULL;
    actual = o.addTwoNumbers(&node4, &node1);
    check.checkInt(7, actual->val);
    check.checkInt(0, actual->next->val);
    check.checkInt(0, actual->next->next->val);
    check.checkInt(1, actual->next->next->next->val);
    check.checkPoint(NULL, actual->next->next->next->next);

    node1.val = 1;
    node2.val = 2;
    node3.val = 0;
    node1.next = &node2;
    node2.next = NULL;
    node3.next = NULL;
    actual = o.addTwoNumbers(&node1, &node3);
    check.checkInt(1, actual->val);
    check.checkInt(2, actual->next->val);
    check.checkPoint(NULL, actual->next->next);

    node1.val = 1;
    node2.val = 2;
    node3.val = 0;
    node1.next = &node2;
    node2.next = NULL;
    node3.next = NULL;
    actual = o.addTwoNumbers(&node3, &node1);
    check.checkInt(1, actual->val);
    check.checkInt(2, actual->next->val);
    check.checkPoint(NULL, actual->next->next);

    node1.val = 9;
    node2.val = 9;
    node3.val = 3;
    node1.next = &node2;
    node2.next = NULL;
    node3.next = NULL;
    actual = o.addTwoNumbers(&node1, &node3);
    check.checkInt(2, actual->val);
    check.checkInt(0, actual->next->val);
    check.checkInt(1, actual->next->next->val);
    check.checkPoint(NULL, actual->next->next->next);

    node1.val = 9;
    node2.val = 9;
    node3.val = 3;
    node1.next = &node2;
    node2.next = NULL;
    node3.next = NULL;
    actual = o.addTwoNumbers(&node3, &node1);
    check.checkInt(2, actual->val);
    check.checkInt(0, actual->next->val);
    check.checkInt(1, actual->next->next->val);
    check.checkPoint(NULL, actual->next->next->next);

    node1.val = 0;
    node2.val = 0;
    node1.next = NULL;
    node2.next = NULL;
    actual = o.addTwoNumbers(&node1, &node2);
    check.checkInt(0, actual->val);
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
