/* 奇偶链表.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给定一个单链表，把所有的奇数节点和偶数节点分别排在一起。请注意，这里的奇数节点和偶数节点指的是节点编号的奇偶性，而不是节点的值的奇偶性。

请尝试使用原地算法完成。你的算法的空间复杂度应为 O(1)，时间复杂度应为 O(nodes)，nodes 为节点总数。

示例 1:

输入: 1->2->3->4->5->NULL
输出: 1->3->5->2->4->NULL
示例 2:

输入: 2->1->3->5->6->4->7->NULL
输出: 2->3->6->7->1->5->4->NULL
说明:

应当保持奇数节点和偶数节点的相对顺序。
链表的第一个节点视为奇数节点，第二个节点视为偶数节点，以此类推。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/odd-even-linked-list
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        if ((head == NULL) || (head->next == NULL)) {
            return head;
        }

        ListNode* oddTail = head;
        ListNode* evenHead = head->next;
        ListNode* evenTail = head->next;
        ListNode* next = evenTail->next;

        while (next != NULL) {
            oddTail->next = next;
            oddTail = next;
            next = next->next;
            if (next == NULL) {
                break;
            }

            evenTail->next = next;
            evenTail = next;
            next = next->next;
        }

        oddTail->next = evenHead;
        if (evenTail != NULL) {
            evenTail->next = NULL;
        }

        return head;
    }
};

int main()
{
    Solution o;
    CheckResult check;

    check.checkPoint(NULL, o.oddEvenList(NULL));

    ListNode node1(1);
    ListNode* actual = o.oddEvenList(&node1);
    check.checkInt(1, actual->val);
    check.checkPoint(NULL, actual->next);

    ListNode node2(2);
    node1.next = &node2;
    actual = o.oddEvenList(&node1);
    check.checkInt(1, actual->val);
    check.checkInt(2, actual->next->val);
    check.checkPoint(NULL, actual->next->next);

    ListNode node3(3);
    node1.next = &node2;
    node2.next = &node3;
    actual = o.oddEvenList(&node1);
    check.checkInt(1, actual->val);
    check.checkInt(3, actual->next->val);
    check.checkInt(2, actual->next->next->val);
    check.checkPoint(NULL, actual->next->next->next);

    ListNode node4(4);
    node1.next = &node2;
    node2.next = &node3;
    node3.next = &node4;
    actual = o.oddEvenList(&node1);
    check.checkInt(1, actual->val);
    check.checkInt(3, actual->next->val);
    check.checkInt(2, actual->next->next->val);
    check.checkInt(4, actual->next->next->next->val);
    check.checkPoint(NULL, actual->next->next->next->next);

    ListNode node5(5);
    node1.next = &node2;
    node2.next = &node3;
    node3.next = &node4;
    node4.next = &node5;
    actual = o.oddEvenList(&node1);
    check.checkInt(1, actual->val);
    check.checkInt(3, actual->next->val);
    check.checkInt(5, actual->next->next->val);
    check.checkInt(2, actual->next->next->next->val);
    check.checkInt(4, actual->next->next->next->next->val);
    check.checkPoint(NULL, actual->next->next->next->next->next);

    ListNode node6(6);
    node1.next = &node2;
    node2.next = &node3;
    node3.next = &node4;
    node4.next = &node5;
    node5.next = &node6;
    actual = o.oddEvenList(&node1);
    check.checkInt(1, actual->val);
    check.checkInt(3, actual->next->val);
    check.checkInt(5, actual->next->next->val);
    check.checkInt(2, actual->next->next->next->val);
    check.checkInt(4, actual->next->next->next->next->val);
    check.checkInt(6, actual->next->next->next->next->next->val);
    check.checkPoint(NULL, actual->next->next->next->next->next->next);
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
