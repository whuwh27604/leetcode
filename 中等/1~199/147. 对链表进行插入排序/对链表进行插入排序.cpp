/* 对链表进行插入排序.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
对链表进行插入排序。


插入排序的动画演示如上。从第一个元素开始，该链表可以被认为已经部分排序（用黑色表示）。
每次迭代时，从输入数据中移除一个元素（用红色表示），并原地将其插入到已排好序的链表中。

 

插入排序算法：

插入排序是迭代的，每次只移动一个元素，直到所有元素可以形成一个有序的输出列表。
每次迭代中，插入排序只从输入数据中移除一个待排序的元素，找到它在序列中适当的位置，并将其插入。
重复直到所有输入数据插入完为止。
 

示例 1：

输入: 4->2->1->3
输出: 1->2->3->4
示例 2：

输入: -1->5->3->4->0
输出: -1->0->3->4->5

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/insertion-sort-list
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <map>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    ListNode* insertionSortList(ListNode* head) {
        map<int, ListNode*> nodes;
        ListNode pseudoHead(INT_MIN);
        pseudoHead.next = head;
        ListNode* prev = &pseudoHead;
        ListNode* current = head;

        while (current != NULL) {
            ListNode* next = current->next;

            auto iter = nodes.lower_bound(current->val);  // iter >= current->val
            ListNode* insertAfter = (iter == nodes.begin()) ? &pseudoHead : insertAfter = (--iter)->second;  // iter--是小于current->val的第一个节点
            prev->next = next;  // 摘除current
            current->next = insertAfter->next;  // current插入到合适的位置
            insertAfter->next = current;
            nodes.insert({ current->val,current });  // 如果有相同元素，nodes中始终保存第一个node，所以用insert不要更新。链表中新来的节点插入到前面，保持第一个相同元素在最后。

            if (prev->next != next) {
                prev = prev->next;  // 更新prev
            }
            current = next;  // 更新current
        }

        return pseudoHead.next;
    }
};

int main()
{
    Solution o;
    CheckResult check;

    check.checkPoint(NULL, o.insertionSortList(NULL));

    ListNode node1(10);
    ListNode* actual = o.insertionSortList(&node1);
    check.checkInt(10, actual->val);
    check.checkPoint(NULL, o.insertionSortList(actual->next));

    ListNode node2(9);
    node1.next = &node2;
    actual = o.insertionSortList(&node1);
    check.checkInt(9, actual->val);
    check.checkInt(10, actual->next->val);
    check.checkPoint(NULL, o.insertionSortList(actual->next->next));

    node1.val = 9;
    node2.val = 10;
    node1.next = &node2;
    node2.next = NULL;
    actual = o.insertionSortList(&node1);
    check.checkInt(9, actual->val);
    check.checkInt(10, actual->next->val);
    check.checkPoint(NULL, o.insertionSortList(actual->next->next));

    ListNode node3(8);
    node1.val = 10;
    node2.val = 9;
    node1.next = &node2;
    node2.next = &node3;
    actual = o.insertionSortList(&node1);
    check.checkInt(8, actual->val);
    check.checkInt(9, actual->next->val);
    check.checkInt(10, actual->next->next->val);
    check.checkPoint(NULL, o.insertionSortList(actual->next->next->next));

    node1.val = 10;
    node2.val = 8;
    node3.val = 9;
    node1.next = &node2;
    node2.next = &node3;
    node3.next = NULL;
    actual = o.insertionSortList(&node1);
    check.checkInt(8, actual->val);
    check.checkInt(9, actual->next->val);
    check.checkInt(10, actual->next->next->val);
    check.checkPoint(NULL, o.insertionSortList(actual->next->next->next));

    node1.val = 9;
    node2.val = 8;
    node3.val = 10;
    node1.next = &node2;
    node2.next = &node3;
    node3.next = NULL;
    actual = o.insertionSortList(&node1);
    check.checkInt(8, actual->val);
    check.checkInt(9, actual->next->val);
    check.checkInt(10, actual->next->next->val);
    check.checkPoint(NULL, o.insertionSortList(actual->next->next->next));

    node1.val = 9;
    node2.val = 10;
    node3.val = 8;
    node1.next = &node2;
    node2.next = &node3;
    node3.next = NULL;
    actual = o.insertionSortList(&node1);
    check.checkInt(8, actual->val);
    check.checkInt(9, actual->next->val);
    check.checkInt(10, actual->next->next->val);
    check.checkPoint(NULL, o.insertionSortList(actual->next->next->next));

    node1.val = 8;
    node2.val = 9;
    node3.val = 10;
    node1.next = &node2;
    node2.next = &node3;
    node3.next = NULL;
    actual = o.insertionSortList(&node1);
    check.checkInt(8, actual->val);
    check.checkInt(9, actual->next->val);
    check.checkInt(10, actual->next->next->val);
    check.checkPoint(NULL, o.insertionSortList(actual->next->next->next));

    node1.val = 8;
    node2.val = 10;
    node3.val = 9;
    node1.next = &node2;
    node2.next = &node3;
    node3.next = NULL;
    actual = o.insertionSortList(&node1);
    check.checkInt(8, actual->val);
    check.checkInt(9, actual->next->val);
    check.checkInt(10, actual->next->next->val);
    check.checkPoint(NULL, o.insertionSortList(actual->next->next->next));

    ListNode node4(7);
    node1.next = &node2;
    node2.next = &node3;
    node3.next = &node4;
    actual = o.insertionSortList(&node1);
    check.checkInt(7, actual->val);
    check.checkInt(8, actual->next->val);
    check.checkInt(9, actual->next->next->val);
    check.checkInt(10, actual->next->next->next->val);
    check.checkPoint(NULL, o.insertionSortList(actual->next->next->next->next));

    ListNode node5(6);
    node1.next = &node2;
    node2.next = &node3;
    node3.next = &node4;
    node4.next = &node5;
    actual = o.insertionSortList(&node1);
    check.checkInt(6, actual->val);
    check.checkInt(7, actual->next->val);
    check.checkInt(8, actual->next->next->val);
    check.checkInt(9, actual->next->next->next->val);
    check.checkInt(10, actual->next->next->next->next->val);
    check.checkPoint(NULL, o.insertionSortList(actual->next->next->next->next->next));

    node1.val = 1;
    node2.val = 2;
    node3.val = 3;
    node4.val = 4;
    node5.val = 5;
    node1.next = &node2;
    node2.next = &node3;
    node3.next = &node4;
    node4.next = &node5;
    node5.next = NULL;
    actual = o.insertionSortList(&node1);
    check.checkInt(1, actual->val);
    check.checkInt(2, actual->next->val);
    check.checkInt(3, actual->next->next->val);
    check.checkInt(4, actual->next->next->next->val);
    check.checkInt(5, actual->next->next->next->next->val);
    check.checkPoint(NULL, o.insertionSortList(actual->next->next->next->next->next));

    node1.val = -1;
    node2.val = 5;
    node3.val = 3;
    node4.val = 4;
    node5.val = 0;
    node1.next = &node2;
    node2.next = &node3;
    node3.next = &node4;
    node4.next = &node5;
    node5.next = NULL;
    actual = o.insertionSortList(&node1);
    check.checkInt(-1, actual->val);
    check.checkInt(0, actual->next->val);
    check.checkInt(3, actual->next->next->val);
    check.checkInt(4, actual->next->next->next->val);
    check.checkInt(5, actual->next->next->next->next->val);
    check.checkPoint(NULL, o.insertionSortList(actual->next->next->next->next->next));

    node1.val = 4;
    node2.val = 2;
    node3.val = 1;
    node4.val = 3;
    node1.next = &node2;
    node2.next = &node3;
    node3.next = &node4;
    node4.next = NULL;
    actual = o.insertionSortList(&node1);
    check.checkInt(1, actual->val);
    check.checkInt(2, actual->next->val);
    check.checkInt(3, actual->next->next->val);
    check.checkInt(4, actual->next->next->next->val);
    check.checkPoint(NULL, o.insertionSortList(actual->next->next->next->next));

    node1.val = 4;
    node2.val = 2;
    node3.val = 1;
    node4.val = 3;
    node5.val = 4;
    ListNode node6(2);
    ListNode node7(1);
    ListNode node8(3);
    node1.next = &node2;
    node2.next = &node3;
    node3.next = &node4;
    node4.next = &node5;
    node5.next = &node6;
    node6.next = &node7;
    node7.next = &node8;
    node8.next = NULL;
    actual = o.insertionSortList(&node1);
    check.checkInt(1, actual->val);
    check.checkInt(1, actual->next->val);
    check.checkInt(2, actual->next->next->val);
    check.checkInt(2, actual->next->next->next->val);
    check.checkInt(3, actual->next->next->next->next->val);
    check.checkInt(3, actual->next->next->next->next->next->val);
    check.checkInt(4, actual->next->next->next->next->next->next->val);
    check.checkInt(4, actual->next->next->next->next->next->next->next->val);
    check.checkPoint(NULL, o.insertionSortList(actual->next->next->next->next->next->next->next->next));

    node1.val = INT_MIN;
    node1.next = NULL;
    actual = o.insertionSortList(&node1);
    check.checkPoint(&node1, actual);
    check.checkPoint(NULL, actual->next);

    node1.val = 1;
    node2.val = INT_MIN;
    node1.next = &node2;
    node2.next = NULL;
    actual = o.insertionSortList(&node1);
    check.checkInt(INT_MIN, actual->val);
    check.checkInt(1, actual->next->val);
    check.checkPoint(NULL, actual->next->next);

    node1.val = 1;
    node2.val = INT_MIN;
    node3.val = 1;
    node4.val = INT_MIN;
    node1.next = &node2;
    node2.next = &node3;
    node3.next = &node4;
    node4.next = NULL;
    actual = o.insertionSortList(&node1);
    check.checkInt(INT_MIN, actual->val);
    check.checkInt(INT_MIN, actual->next->val);
    check.checkInt(1, actual->next->next->val);
    check.checkInt(1, actual->next->next->next->val);
    check.checkPoint(NULL, actual->next->next->next->next);
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
