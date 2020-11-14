/* 分隔链表.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给定一个链表和一个特定值 x，对链表进行分隔，使得所有小于 x 的节点都在大于或等于 x 的节点之前。

你应当保留两个分区中每个节点的初始相对位置。

示例:

输入: head = 1->4->3->2->5->2, x = 3
输出: 1->2->2->4->3->5

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/partition-list
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        ListNode pseudo(0);
        pseudo.next = head;
        ListNode* insertPosition = &pseudo;
        ListNode* prev = &pseudo;
        ListNode* current = prev->next;
        bool needAdjust = false;

        while (current != NULL) {
            if (current->val < x) {
                if (needAdjust) {
                    prev->next = current->next;  // 摘除要调整的节点
                    current->next = insertPosition->next;  // 插入到最后一个小于x的位置
                    insertPosition->next = current;
                    insertPosition = current;  // 调整下一个小于x的节点要插入的位置
                    current = prev;  // 因当前节点被摘除，调整当前节点到前一个
                }
                else {
                    insertPosition = current;
                }
            }
            else {
                needAdjust = true;
            }

            prev = current;
            current = current->next;
        }

        return pseudo.next;
    }
};

int main()
{
    Solution o;
    CheckResult check;

    ListNode node1(1);
    ListNode node2(4);
    ListNode node3(3);
    ListNode node4(2);
    ListNode node5(5);
    ListNode node6(2);
    node1.next = &node2;
    node2.next = &node3;
    node3.next = &node4;
    node4.next = &node5;
    node5.next = &node6;
    node6.next = NULL;
    ListNode* actual = o.partition(&node1, 3);
    check.checkInt(1, actual->val);
    check.checkInt(2, actual->next->val);
    check.checkInt(2, actual->next->next->val);
    check.checkInt(4, actual->next->next->next->val);
    check.checkInt(3, actual->next->next->next->next->val);
    check.checkInt(5, actual->next->next->next->next->next->val);
    check.checkPoint(NULL, actual->next->next->next->next->next->next);

    check.checkPoint(NULL, o.partition(NULL, 3));

    node1.val = 1;
    node1.next = NULL;
    actual = o.partition(&node1, 3);
    check.checkInt(1, actual->val);
    check.checkPoint(NULL, actual->next);

    node1.val = 3;
    node1.next = NULL;
    actual = o.partition(&node1, 3);
    check.checkInt(3, actual->val);
    check.checkPoint(NULL, actual->next);

    node1.val = 1;
    node2.val = 3;
    node1.next = &node2;
    node2.next = NULL;
    actual = o.partition(&node1, 3);
    check.checkInt(1, actual->val);
    check.checkInt(3, actual->next->val);
    check.checkPoint(NULL, actual->next->next);

    node1.val = 3;
    node2.val = 1;
    node1.next = &node2;
    node2.next = NULL;
    actual = o.partition(&node1, 3);
    check.checkInt(1, actual->val);
    check.checkInt(3, actual->next->val);
    check.checkPoint(NULL, actual->next->next);

    node1.val = 3;
    node2.val = 2;
    node3.val = 1;
    node1.next = &node2;
    node2.next = &node3;
    node3.next = NULL;
    actual = o.partition(&node1, 3);
    check.checkInt(2, actual->val);
    check.checkInt(1, actual->next->val);
    check.checkInt(3, actual->next->next->val);
    check.checkPoint(NULL, actual->next->next->next);

    node1.val = 1;
    node2.val = 4;
    node3.val = 3;
    node4.val = 2;
    node5.val = 5;
    node6.val = 2;
    node1.next = &node2;
    node2.next = &node3;
    node3.next = &node4;
    node4.next = &node5;
    node5.next = &node6;
    node6.next = NULL;
    actual = o.partition(&node1, 1);
    check.checkInt(1, actual->val);
    check.checkInt(4, actual->next->val);
    check.checkInt(3, actual->next->next->val);
    check.checkInt(2, actual->next->next->next->val);
    check.checkInt(5, actual->next->next->next->next->val);
    check.checkInt(2, actual->next->next->next->next->next->val);
    check.checkPoint(NULL, actual->next->next->next->next->next->next);

    node1.val = 1;
    node2.val = 4;
    node3.val = 3;
    node4.val = 2;
    node5.val = 5;
    node6.val = 2;
    node1.next = &node2;
    node2.next = &node3;
    node3.next = &node4;
    node4.next = &node5;
    node5.next = &node6;
    node6.next = NULL;
    actual = o.partition(&node1, 2);
    check.checkInt(1, actual->val);
    check.checkInt(4, actual->next->val);
    check.checkInt(3, actual->next->next->val);
    check.checkInt(2, actual->next->next->next->val);
    check.checkInt(5, actual->next->next->next->next->val);
    check.checkInt(2, actual->next->next->next->next->next->val);
    check.checkPoint(NULL, actual->next->next->next->next->next->next);

    node1.val = 1;
    node2.val = 4;
    node3.val = 3;
    node4.val = 2;
    node5.val = 5;
    node6.val = 2;
    node1.next = &node2;
    node2.next = &node3;
    node3.next = &node4;
    node4.next = &node5;
    node5.next = &node6;
    node6.next = NULL;
    actual = o.partition(&node1, 4);
    check.checkInt(1, actual->val);
    check.checkInt(3, actual->next->val);
    check.checkInt(2, actual->next->next->val);
    check.checkInt(2, actual->next->next->next->val);
    check.checkInt(4, actual->next->next->next->next->val);
    check.checkInt(5, actual->next->next->next->next->next->val);
    check.checkPoint(NULL, actual->next->next->next->next->next->next);

    node1.val = 1;
    node2.val = 4;
    node3.val = 3;
    node4.val = 2;
    node5.val = 5;
    node6.val = 2;
    node1.next = &node2;
    node2.next = &node3;
    node3.next = &node4;
    node4.next = &node5;
    node5.next = &node6;
    node6.next = NULL;
    actual = o.partition(&node1, 5);
    check.checkInt(1, actual->val);
    check.checkInt(4, actual->next->val);
    check.checkInt(3, actual->next->next->val);
    check.checkInt(2, actual->next->next->next->val);
    check.checkInt(2, actual->next->next->next->next->val);
    check.checkInt(5, actual->next->next->next->next->next->val);
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
