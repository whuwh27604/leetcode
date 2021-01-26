/* 交换链表中的节点.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你链表的头节点 head 和一个整数 k 。

交换 链表正数第 k 个节点和倒数第 k 个节点的值后，返回链表的头节点（链表 从 1 开始索引）。

 

示例 1：


输入：head = [1,2,3,4,5], k = 2
输出：[1,4,3,2,5]
示例 2：

输入：head = [7,9,6,6,7,8,3,0,9,5], k = 5
输出：[7,9,6,6,8,7,3,0,9,5]
示例 3：

输入：head = [1], k = 1
输出：[1]
示例 4：

输入：head = [1,2], k = 1
输出：[2,1]
示例 5：

输入：head = [1,2,3], k = 2
输出：[1,2,3]
 

提示：

链表中节点的数目是 n
1 <= k <= n <= 105
0 <= Node.val <= 100

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/swapping-nodes-in-a-linked-list
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    ListNode* swapNodes(ListNode* head, int k) {
        ListNode* node = head;

        for (int i = 1; i < k; ++i) {
            node = node->next;
        }

        ListNode* forwardKth = node;
        ListNode* backwardKth = head;
        node = node->next;

        while (node != NULL) {
            node = node->next;
            backwardKth = backwardKth->next;
        }

        swap(forwardKth->val, backwardKth->val);

        return head;
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<int> values = { 1,2,3,4,5 };
    ListNode* actual = o.swapNodes(createList(values), 2);
    values = { 1,4,3,2,5 };
    check.checkSingleList(createList(values), actual);

    values = { 1,2,3,4,5 };
    actual = o.swapNodes(createList(values), 1);
    values = { 5,2,3,4,1 };
    check.checkSingleList(createList(values), actual);

    values = { 1,2,3,4,5 };
    actual = o.swapNodes(createList(values), 5);
    values = { 5,2,3,4,1 };
    check.checkSingleList(createList(values), actual);

    values = { 1,2,3,4,5 };
    actual = o.swapNodes(createList(values), 3);
    values = { 1,2,3,4,5 };
    check.checkSingleList(createList(values), actual);

    values = { 7,9,6,6,7,8,3,0,9,5 };
    actual = o.swapNodes(createList(values), 5);
    values = { 7,9,6,6,8,7,3,0,9,5 };
    check.checkSingleList(createList(values), actual);

    values = { 1 };
    actual = o.swapNodes(createList(values), 1);
    values = { 1 };
    check.checkSingleList(createList(values), actual);

    values = { 1,2 };
    actual = o.swapNodes(createList(values), 1);
    values = { 2,1 };
    check.checkSingleList(createList(values), actual);

    values = { 1,2,3 };
    actual = o.swapNodes(createList(values), 2);
    values = { 1,2,3 };
    check.checkSingleList(createList(values), actual);
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
