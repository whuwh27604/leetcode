/* 相交链表.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
编写一个程序，找到两个单链表相交的起始节点。

如下面的两个链表：



在节点 c1 开始相交。

 

示例 1：



输入：intersectVal = 8, listA = [4,1,8,4,5], listB = [5,0,1,8,4,5], skipA = 2, skipB = 3
输出：Reference of the node with value = 8
输入解释：相交节点的值为 8 （注意，如果两个列表相交则不能为 0）。从各自的表头开始算起，链表 A 为 [4,1,8,4,5]，链表 B 为 [5,0,1,8,4,5]。在 A 中，相交节点前有 2 个节点；在 B 中，相交节点前有 3 个节点。
 

示例 2：



输入：intersectVal = 2, listA = [0,9,1,2,4], listB = [3,2,4], skipA = 3, skipB = 1
输出：Reference of the node with value = 2
输入解释：相交节点的值为 2 （注意，如果两个列表相交则不能为 0）。从各自的表头开始算起，链表 A 为 [0,9,1,2,4]，链表 B 为 [3,2,4]。在 A 中，相交节点前有 3 个节点；在 B 中，相交节点前有 1 个节点。
 

示例 3：



输入：intersectVal = 0, listA = [2,6,4], listB = [1,5], skipA = 3, skipB = 2
输出：null
输入解释：从各自的表头开始算起，链表 A 为 [2,6,4]，链表 B 为 [1,5]。由于这两个链表不相交，所以 intersectVal 必须为 0，而 skipA 和 skipB 可以是任意值。
解释：这两个链表不相交，因此返回 null。
 

注意：

如果两个链表没有交点，返回 null.
在返回结果后，两个链表仍须保持原有的结构。
可假定整个链表结构中没有循环。
程序尽量满足 O(n) 时间复杂度，且仅用 O(1) 内存。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/intersection-of-two-linked-lists
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    ListNode* getIntersectionNode(ListNode* headA, ListNode* headB) {
        /*
        1、
        a[0].a[i]c[0].....c[k]b[0]...b[j]c[0].....c[k]
        b[0]...b[j]c[0].....c[k]a[0].a[i]c[0].....c[k]
        分别a加在b后面和b加在a后面，可以看到，如果相交，最后的c应该完全重合
        2、a的尾结点指向b的头结点，如果相交必成环
        */
        if ((headA == NULL) || (headB == NULL)) {
            return NULL;
        }

        ListNode* nodeA = headA;
        ListNode* nodeB = headB;
        bool finishAB = false;
        bool finishBA = false;

        while (nodeA != nodeB) {
            nodeA = nodeA->next;
            if (nodeA == NULL) {
                if (finishAB) {
                    return NULL;
                }

                nodeA = headB;
                finishAB = true;
            }

            nodeB = nodeB->next;
            if (nodeB == NULL) {
                if (finishBA) {
                    return NULL;
                }

                nodeB = headA;
                finishBA = true;
            }
        }

        return nodeA;
    }

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

    ListNode nodeC3(5);
    ListNode nodeC2(4);
    nodeC2.next = &nodeC3;
    ListNode nodeC1(8);
    nodeC1.next = &nodeC2;
    ListNode nodeA2(1);
    nodeA2.next = &nodeC1;
    ListNode nodeA1(4);
    nodeA1.next = &nodeA2;
    ListNode nodeB3(1);
    nodeB3.next = &nodeC1;
    ListNode nodeB2(0);
    nodeB2.next = &nodeB3;
    ListNode nodeB1(5);
    nodeB1.next = &nodeB2;
    check.checkInt((int)(&nodeC1), (int)o.getIntersectionNode(&nodeA1, &nodeB1));
    nodeC3.next = &nodeB1;
    check.checkBool(true, o.hasCycle(&nodeA1));

    ListNode nodeA3(1);
    nodeA1.next = &nodeA2;
    nodeA2.next = &nodeA3;
    nodeA3.next = &nodeC1;
    nodeB1.next = &nodeC1;
    nodeC1.next = &nodeC2;
    nodeC2.next = NULL;
    check.checkInt((int)(&nodeC1), (int)o.getIntersectionNode(&nodeA1, &nodeB1));
    nodeC2.next = &nodeB1;
    check.checkBool(true, o.hasCycle(&nodeA1));

    nodeA3.next = NULL;
    nodeB1.next = &nodeB2;
    nodeB2.next = NULL;
    check.checkInt((int)(NULL), (int)o.getIntersectionNode(&nodeA1, &nodeB1));
    nodeA3.next = &nodeB1;
    check.checkBool(false, o.hasCycle(&nodeA1));

    nodeA1.next = NULL;
    nodeB1.next = NULL;
    check.checkInt((int)(NULL), (int)o.getIntersectionNode(&nodeA1, &nodeB1));

    check.checkInt((int)(&nodeA1), (int)o.getIntersectionNode(&nodeA1, &nodeA1));
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
