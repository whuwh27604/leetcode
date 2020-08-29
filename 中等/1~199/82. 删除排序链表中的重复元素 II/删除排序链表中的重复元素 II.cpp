/* 删除排序链表中的重复元素 II.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给定一个排序链表，删除所有含有重复数字的节点，只保留原始链表中 没有重复出现 的数字。

示例 1:

输入: 1->2->3->3->4->4->5
输出: 1->2->5
示例 2:

输入: 1->1->1->2->3
输出: 2->3

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/remove-duplicates-from-sorted-list-ii
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* prevTwo = head;
        ListNode* prev = (prevTwo == NULL) ? NULL : prevTwo->next;
        ListNode* current;
        ListNode* next;

        while ((prevTwo != NULL) && (prev != NULL) && (prevTwo->val == prev->val)) {
            current = prev->next;
            while ((current != NULL) && (current->val == prev->val)) {
                current = current->next;
            }

            head = current;
            prevTwo = head;
            prev = (prevTwo == NULL) ? NULL : prevTwo->next;
        }

        if (prev == NULL) {
            return head;
        }

        current = prev->next;
        while (current != NULL) {
            if (current->val != prev->val) {
                prevTwo = prev;
                prev = current;
                current = current->next;
                continue;
            }

            next = current->next;
            while ((next != NULL) && (next->val == current->val)) {
                next = next->next;
            }

            prevTwo->next = next;
            prev = next;
            current = (next == NULL) ? NULL : next->next;
        }

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
    ListNode node4(3);
    ListNode node5(4);
    ListNode node6(4);
    ListNode node7(5);
    node1.next = &node2;
    node2.next = &node3;
    node3.next = &node4;
    node4.next = &node5;
    node5.next = &node6;
    node6.next = &node7;
    node7.next = NULL;
    ListNode* actual = o.deleteDuplicates(&node1);
    check.checkInt(1, actual->val);
    check.checkInt(2, actual->next->val);
    check.checkInt(5, actual->next->next->val);
    check.checkPoint(NULL, actual->next->next->next);

    node7.val = 4;
    node1.next = &node2;
    node2.next = &node3;
    node3.next = &node4;
    node4.next = &node5;
    node5.next = &node6;
    node6.next = &node7;
    node7.next = NULL;
    actual = o.deleteDuplicates(&node1);
    check.checkInt(1, actual->val);
    check.checkInt(2, actual->next->val);
    check.checkPoint(NULL, actual->next->next);

    node1.val = 1;
    node2.val = 1;
    node3.val = 1;
    node4.val = 2;
    node5.val = 2;
    node6.val = 3;
    node7.val = 3;
    node1.next = &node2;
    node2.next = &node3;
    node3.next = &node4;
    node4.next = &node5;
    node5.next = &node6;
    node6.next = &node7;
    node7.next = NULL;
    actual = o.deleteDuplicates(&node1);
    check.checkPoint(NULL, actual);

    node1.val = 1;
    node2.val = 1;
    node3.val = 1;
    node4.val = 2;
    node5.val = 3;
    node1.next = &node2;
    node2.next = &node3;
    node3.next = &node4;
    node4.next = &node5;
    node5.next = NULL;
    actual = o.deleteDuplicates(&node1);
    check.checkInt(2, actual->val);
    check.checkInt(3, actual->next->val);
    check.checkPoint(NULL, actual->next->next);

    actual = o.deleteDuplicates(NULL);
    check.checkPoint(NULL, actual);

    node1.val = 1;
    node1.next = NULL;
    actual = o.deleteDuplicates(&node1);
    check.checkInt(1, actual->val);
    check.checkPoint(NULL, actual->next);

    node1.val = 1;
    node2.val = 1;
    node1.next = &node2;
    node2.next = NULL;
    actual = o.deleteDuplicates(&node1);
    check.checkPoint(NULL, actual);

    node1.val = 1;
    node2.val = 2;
    node1.next = &node2;
    node2.next = NULL;
    actual = o.deleteDuplicates(&node1);
    check.checkInt(1, actual->val);
    check.checkInt(2, actual->next->val);
    check.checkPoint(NULL, actual->next->next);

    node1.val = 1;
    node2.val = 2;
    node3.val = 3;
    node1.next = &node2;
    node2.next = &node3;
    node3.next = NULL;
    actual = o.deleteDuplicates(&node1);
    check.checkInt(1, actual->val);
    check.checkInt(2, actual->next->val);
    check.checkInt(3, actual->next->next->val);
    check.checkPoint(NULL, actual->next->next->next);

    node1.val = 1;
    node2.val = 1;
    node3.val = 3;
    node1.next = &node2;
    node2.next = &node3;
    node3.next = NULL;
    actual = o.deleteDuplicates(&node1);
    check.checkInt(3, actual->val);
    check.checkPoint(NULL, actual->next);

    node1.val = 1;
    node2.val = 3;
    node3.val = 3;
    node1.next = &node2;
    node2.next = &node3;
    node3.next = NULL;
    actual = o.deleteDuplicates(&node1);
    check.checkInt(1, actual->val);
    check.checkPoint(NULL, actual->next);

    node1.val = 2;
    node2.val = 2;
    node3.val = 2;
    node1.next = &node2;
    node2.next = &node3;
    node3.next = NULL;
    actual = o.deleteDuplicates(&node1);
    check.checkPoint(NULL, actual);
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
