/* 回文链表.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
请判断一个链表是否为回文链表。

示例 1:

输入: 1->2
输出: false
示例 2:

输入: 1->2->2->1
输出: true
进阶：
你能否用 O(n) 时间复杂度和 O(1) 空间复杂度解决此题？

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/palindrome-linked-list
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    bool isPalindrome(ListNode* head) {
        if (head == NULL) {
            return true;
        }

        // 找到中间节点的后一个
        ListNode* nodeAfterMiddle = findMiddleNode(head);

        // 反转后一半链表
        ListNode* reversedNode = reverseList(nodeAfterMiddle);

        // 判断是否回文
        bool result = judgePalindrome(head, reversedNode);

        // 恢复后一半链表，非必需
        (void)reverseList(reversedNode);

        return result;
    }

    ListNode* findMiddleNode(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head->next;
        int count = 0;

        while (fast != NULL) {
            fast = fast->next;
            count++;
            if ((count % 2) == 0) {
                slow = slow->next;
            }
        }

        return slow->next;
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

    bool judgePalindrome(ListNode* firstHalf, ListNode* reversedSecondHalf) {
        while (reversedSecondHalf != NULL) {
            if (firstHalf->val != reversedSecondHalf->val) {
                return false;
            }
            firstHalf = firstHalf->next;
            reversedSecondHalf = reversedSecondHalf->next;
        }

        return true;
    }
};

int main()
{
    Solution o;
    CheckResult check;

    ListNode node1(1);
    ListNode node2(2);
    ListNode node3(2);
    ListNode node4(1);
    node1.next = &node2;
    node2.next = &node3;
    node3.next = &node4;
    check.checkBool(true, o.isPalindrome(&node1));

    ListNode node5(3);
    node4.next = &node5;
    check.checkBool(false, o.isPalindrome(&node1));

    node2.next = &node5;
    node5.next = &node3;
    node3.next = &node4;
    node4.next = NULL;
    check.checkBool(true, o.isPalindrome(&node1));
    check.checkInt(1, node1.val);
    check.checkInt(2, node1.next->val);
    check.checkInt(3, node1.next->next->val);
    check.checkInt(2, node1.next->next->next->val);
    check.checkInt(1, node1.next->next->next->next->val);

    node1.next = NULL;
    check.checkBool(true, o.isPalindrome(&node1));

    node1.next = &node2;
    node2.next = NULL;
    check.checkBool(false, o.isPalindrome(&node1));

    node1.next = &node4;
    node4.next = NULL;
    check.checkBool(true, o.isPalindrome(&node1));

    node1.next = &node2;
    node2.next = &node4;
    node4.next = NULL;
    check.checkBool(true, o.isPalindrome(&node1));

    node1.next = &node2;
    node2.next = &node3;
    node3.next = NULL;
    check.checkBool(false, o.isPalindrome(&node1));

    check.checkBool(true, o.isPalindrome(NULL));
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
