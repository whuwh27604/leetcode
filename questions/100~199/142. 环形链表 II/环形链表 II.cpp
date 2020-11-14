/* 环形链表 II.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给定一个链表，返回链表开始入环的第一个节点。 如果链表无环，则返回 null。

为了表示给定链表中的环，我们使用整数 pos 来表示链表尾连接到链表中的位置（索引从 0 开始）。 如果 pos 是 -1，则在该链表中没有环。

说明：不允许修改给定的链表。

 

示例 1：

输入：head = [3,2,0,-4], pos = 1
输出：tail connects to node index 1
解释：链表中有一个环，其尾部连接到第二个节点。


示例 2：

输入：head = [1,2], pos = 0
输出：tail connects to node index 0
解释：链表中有一个环，其尾部连接到第一个节点。


示例 3：

输入：head = [1], pos = -1
输出：no cycle
解释：链表中没有环。


 

进阶：
你是否可以不用额外空间解决此题？

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/linked-list-cycle-ii
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    ListNode* detectCycle(ListNode* head) {
        if (head == NULL) {
            return NULL;
        }

        ListNode* fast = head;
        ListNode* slow = head;

        // 找到快慢指针重合的节点
        do {
            slow = slow->next;
            fast = fast->next;
            if (fast != NULL) {
                fast = fast->next;
            }
        } while ((fast != slow) && (fast != NULL));

        if (fast == NULL) {
            return NULL;
        }

        // 从重合节点到圈首正好等于从首节点到圈首
        ListNode* cycleFirst = head;
        while (cycleFirst != slow) {
            cycleFirst = cycleFirst->next;
            slow = slow->next;
        }

        return cycleFirst;
    }
};

int main()
{
    Solution o;
    CheckResult check;

    ListNode node1(3);
    ListNode node2(2);
    ListNode node3(0);
    ListNode node4(-4);
    node1.next = &node2;
    node2.next = &node3;
    node3.next = &node4;
    node4.next = &node2;
    check.checkInt(node2.val, o.detectCycle(&node1)->val);

    node1.val = 1;
    node2.val = 2;
    node1.next = &node2;
    node2.next = &node1;
    check.checkInt(node1.val, o.detectCycle(&node1)->val);

    node1.next = &node2;
    node2.next = &node2;
    check.checkInt(node2.val, o.detectCycle(&node1)->val);

    node1.next = &node2;
    node2.next = NULL;
    check.checkPoint(NULL, o.detectCycle(&node1));

    check.checkPoint(NULL, o.detectCycle(NULL));

    node1.next = NULL;
    check.checkPoint(NULL, o.detectCycle(&node1));

    node1.val = 1;
    node2.val = 2;
    node3.val = 3;
    node1.next = &node2;
    node2.next = &node3;
    node3.next = &node1;
    check.checkInt(node1.val, o.detectCycle(&node1)->val);

    node1.next = &node2;
    node2.next = &node3;
    node3.next = &node2;
    check.checkInt(node2.val, o.detectCycle(&node1)->val);

    node1.next = &node2;
    node2.next = &node3;
    node3.next = &node3;
    check.checkInt(node3.val, o.detectCycle(&node1)->val);

    node1.val = 1;
    node2.val = 2;
    node3.val = 3;
    node4.val = 4;
    node1.next = &node2;
    node2.next = &node3;
    node3.next = &node4;
    node4.next = &node1;
    check.checkInt(node1.val, o.detectCycle(&node1)->val);

    node1.next = &node2;
    node2.next = &node3;
    node3.next = &node4;
    node4.next = &node2;
    check.checkInt(node2.val, o.detectCycle(&node1)->val);

    node1.next = &node2;
    node2.next = &node3;
    node3.next = &node4;
    node4.next = &node3;
    check.checkInt(node3.val, o.detectCycle(&node1)->val);

    node1.next = &node2;
    node2.next = &node3;
    node3.next = &node4;
    node4.next = &node4;
    check.checkInt(node4.val, o.detectCycle(&node1)->val);

    node1.val = 1;
    node2.val = 2;
    node3.val = 3;
    node4.val = 4;
    ListNode node5(5);
    node1.next = &node2;
    node2.next = &node3;
    node3.next = &node4;
    node4.next = &node5;
    node5.next = &node1;
    check.checkInt(node1.val, o.detectCycle(&node1)->val);

    node1.next = &node2;
    node2.next = &node3;
    node3.next = &node4;
    node4.next = &node5;
    node5.next = &node2;
    check.checkInt(node2.val, o.detectCycle(&node1)->val);

    node1.next = &node2;
    node2.next = &node3;
    node3.next = &node4;
    node4.next = &node5;
    node5.next = &node3;
    check.checkInt(node3.val, o.detectCycle(&node1)->val);

    node1.next = &node2;
    node2.next = &node3;
    node3.next = &node4;
    node4.next = &node5;
    node5.next = &node4;
    check.checkInt(node4.val, o.detectCycle(&node1)->val);

    node1.next = &node2;
    node2.next = &node3;
    node3.next = &node4;
    node4.next = &node5;
    node5.next = &node5;
    check.checkInt(node5.val, o.detectCycle(&node1)->val);
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
