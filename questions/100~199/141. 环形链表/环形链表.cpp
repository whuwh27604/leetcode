/* 环形链表.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给定一个链表，判断链表中是否有环。

为了表示给定链表中的环，我们使用整数 pos 来表示链表尾连接到链表中的位置（索引从 0 开始）。 如果 pos 是 -1，则在该链表中没有环。

 

示例 1：

输入：head = [3,2,0,-4], pos = 1
输出：true
解释：链表中有一个环，其尾部连接到第二个节点。


示例 2：

输入：head = [1,2], pos = 0
输出：true
解释：链表中有一个环，其尾部连接到第一个节点。


示例 3：

输入：head = [1], pos = -1
输出：false
解释：链表中没有环。


 

进阶：

你能用 O(1)（即，常量）内存解决此问题吗？

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/linked-list-cycle
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    bool hasCycle(ListNode* head) {
        ListNode* slow = head;
        if (slow == NULL) {
            return false;
        }
        ListNode* fast = head->next;
        if (fast == NULL) {
            return false;
        }

        while (fast != slow) {
            slow = slow->next;
            fast = fast->next;
            if (fast == NULL) {
                return false;
            }
            fast = fast->next;
            if (fast == NULL) {
                return false;
            }
        }

        return true;
    }
};

int main()
{
    Solution o;
    CheckResult check;

    ListNode node4(-4);
    ListNode node3(0);
    node3.next = &node4;
    ListNode node2(2);
    node2.next = &node3;
    ListNode node1(3);
    node1.next = &node2;
    node4.next = &node2;
    check.checkBool(true, o.hasCycle(&node1));

    node2.next = &node1;
    check.checkBool(true, o.hasCycle(&node1));

    node2.next = NULL;
    check.checkBool(false, o.hasCycle(&node1));

    node1.next = NULL;
    check.checkBool(false, o.hasCycle(&node1));

    node1.next = &node1;
    check.checkBool(true, o.hasCycle(&node1));
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
