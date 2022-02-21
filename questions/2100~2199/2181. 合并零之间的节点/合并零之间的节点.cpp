/* 合并零之间的节点.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你一个链表的头节点 head ，该链表包含由 0 分隔开的一连串整数。链表的 开端 和 末尾 的节点都满足 Node.val == 0 。

对于每两个相邻的 0 ，请你将它们之间的所有节点合并成一个节点，其值是所有已合并节点的值之和。然后将所有 0 移除，修改后的链表不应该含有任何 0 。

 返回修改后链表的头节点 head 。

 

示例 1：


输入：head = [0,3,1,0,4,5,2,0]
输出：[4,11]
解释：
上图表示输入的链表。修改后的链表包含：
- 标记为绿色的节点之和：3 + 1 = 4
- 标记为红色的节点之和：4 + 5 + 2 = 11
示例 2：


输入：head = [0,1,0,3,0,2,2,0]
输出：[1,3,4]
解释：
上图表示输入的链表。修改后的链表包含：
- 标记为绿色的节点之和：1 = 1
- 标记为红色的节点之和：3 = 3
- 标记为黄色的节点之和：2 + 2 = 4
 

提示：

列表中的节点数目在范围 [3, 2 * 105] 内
0 <= Node.val <= 1000
不 存在连续两个 Node.val == 0 的节点
链表的 开端 和 末尾 节点都满足 Node.val == 0

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/merge-nodes-in-between-zeros
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    ListNode* mergeNodes(ListNode* head) {
        ListNode merged(0);
        ListNode* tail = &merged;
        ListNode* node = head->next;
        int sum = 0;

        while (node != NULL) {
            if (node->val == 0) {
                ListNode* newNode = new ListNode(sum);
                tail->next = newNode;
                tail = newNode;
                sum = 0;
            }
            else {
                sum += node->val;
            }

            node = node->next;
        }

        return merged.next;
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<int> values = { 0,3,1,0,4,5,2,0 };
    ListNode* head = createList(values);
    values = { 4,11 };
    check.checkSingleList(createList(values), o.mergeNodes(head));

    values = { 0,1,0,3,0,2,2,0 };
    head = createList(values);
    values = { 1,3,4 };
    check.checkSingleList(createList(values), o.mergeNodes(head));
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
