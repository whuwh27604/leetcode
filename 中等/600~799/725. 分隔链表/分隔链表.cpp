/* 分隔链表.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给定一个头结点为 root 的链表, 编写一个函数以将链表分隔为 k 个连续的部分。

每部分的长度应该尽可能的相等: 任意两部分的长度差距不能超过 1，也就是说可能有些部分为 null。

这k个部分应该按照在链表中出现的顺序进行输出，并且排在前面的部分的长度应该大于或等于后面的长度。

返回一个符合上述规则的链表的列表。

举例： 1->2->3->4, k = 5 // 5 结果 [ [1], [2], [3], [4], null ]

示例 1：

输入:
root = [1, 2, 3], k = 5
输出: [[1],[2],[3],[],[]]
解释:
输入输出各部分都应该是链表，而不是数组。
例如, 输入的结点 root 的 val= 1, root.next.val = 2, \root.next.next.val = 3, 且 root.next.next.next = null。
第一个输出 output[0] 是 output[0].val = 1, output[0].next = null。
最后一个元素 output[4] 为 null, 它代表了最后一个部分为空链表。
示例 2：

输入:
root = [1, 2, 3, 4, 5, 6, 7, 8, 9, 10], k = 3
输出: [[1, 2, 3, 4], [5, 6, 7], [8, 9, 10]]
解释:
输入被分成了几个连续的部分，并且每部分的长度相差不超过1.前面部分的长度大于等于后面部分的长度。
 

提示:

root 的长度范围： [0, 1000].
输入的每个节点的大小范围：[0, 999].
k 的取值范围： [1, 50].

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/split-linked-list-in-parts
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    vector<ListNode*> splitListToParts(ListNode* root, int k) {
        int size = listSize(root);
        int partSize = size / k, remainder = size % k;
        int i, count = 1;
        ListNode* head = root;
        ListNode* node;
        vector<ListNode*> parts;

        for (i = 0; i < remainder; i++) {
            parts.push_back(head);
            node = head;
            count = 1;

            while (count++ < partSize + 1) {
                node = node->next;
            }

            if (node == NULL) {
                head = NULL;
            }
            else {
                head = node->next;
                node->next = NULL;
            }
        }

        for (i = remainder; i < k; i++) {
            parts.push_back(head);
            node = head;
            count = 1;

            while (count++ < partSize) {
                node = node->next;
            }

            if (node == NULL) {
                head = NULL;
            }
            else {
                head = node->next;
                node->next = NULL;
            }
        }

        return parts;
    }

    int listSize(ListNode* root) {
        int size = 0;
        ListNode* node = root;

        while (node != NULL) {
            node = node->next;
            size++;
        }

        return size;
    }
};

int main()
{
    Solution o;
    CheckResult check;

    ListNode node1(1);
    ListNode node2(2);
    ListNode node3(3);
    ListNode node4(4);
    ListNode node5(5);
    ListNode node6(6);
    ListNode node7(7);
    ListNode node8(8);
    ListNode node9(9);
    ListNode node10(10);
    node1.next = &node2;
    node2.next = &node3;
    node3.next = &node4;
    node4.next = &node5;
    node5.next = &node6;
    node6.next = &node7;
    node7.next = &node8;
    node8.next = &node9;
    node9.next = &node10;
    vector<ListNode*> actual = o.splitListToParts(&node1, 3);
    check.checkInt(3, actual.size());
    check.checkInt(1, actual[0]->val);
    check.checkPoint(NULL, actual[0]->next->next->next->next);
    check.checkInt(5, actual[1]->val);
    check.checkPoint(NULL, actual[1]->next->next->next);
    check.checkInt(8, actual[2]->val);
    check.checkPoint(NULL, actual[2]->next->next->next);

    node1.next = &node2;
    node2.next = &node3;
    node3.next = &node4;
    node4.next = &node5;
    node5.next = &node6;
    node6.next = &node7;
    node7.next = &node8;
    node8.next = NULL;
    actual = o.splitListToParts(&node1, 3);
    check.checkInt(3, actual.size());
    check.checkInt(1, actual[0]->val);
    check.checkPoint(NULL, actual[0]->next->next->next);
    check.checkInt(4, actual[1]->val);
    check.checkPoint(NULL, actual[1]->next->next->next);
    check.checkInt(7, actual[2]->val);
    check.checkPoint(NULL, actual[2]->next->next);

    node1.next = &node2;
    node2.next = &node3;
    node3.next = &node4;
    node4.next = NULL;
    actual = o.splitListToParts(&node1, 5);
    check.checkInt(5, actual.size());
    check.checkInt(1, actual[0]->val);
    check.checkPoint(NULL, actual[0]->next);
    check.checkInt(2, actual[1]->val);
    check.checkPoint(NULL, actual[1]->next);
    check.checkInt(3, actual[2]->val);
    check.checkPoint(NULL, actual[2]->next);
    check.checkInt(4, actual[3]->val);
    check.checkPoint(NULL, actual[3]->next);
    check.checkPoint(NULL, actual[4]);

    node1.next = &node2;
    node2.next = &node3;
    node3.next = NULL;
    actual = o.splitListToParts(&node1, 5);
    check.checkInt(5, actual.size());
    check.checkInt(1, actual[0]->val);
    check.checkPoint(NULL, actual[0]->next);
    check.checkInt(2, actual[1]->val);
    check.checkPoint(NULL, actual[1]->next);
    check.checkInt(3, actual[2]->val);
    check.checkPoint(NULL, actual[2]->next);
    check.checkPoint(NULL, actual[3]);
    check.checkPoint(NULL, actual[4]);

    node1.next = &node2;
    node2.next = &node3;
    node3.next = NULL;
    actual = o.splitListToParts(&node1, 1);
    check.checkInt(1, actual.size());
    check.checkInt(1, actual[0]->val);
    check.checkInt(2, actual[0]->next->val);
    check.checkInt(3, actual[0]->next->next->val);
    check.checkPoint(NULL, actual[0]->next->next->next);

    node1.next = &node2;
    node2.next = NULL;
    actual = o.splitListToParts(&node1, 2);
    check.checkInt(2, actual.size());
    check.checkInt(1, actual[0]->val);
    check.checkPoint(NULL, actual[0]->next);
    check.checkInt(2, actual[1]->val);
    check.checkPoint(NULL, actual[1]->next);
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
