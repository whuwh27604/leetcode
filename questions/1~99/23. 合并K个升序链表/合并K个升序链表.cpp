/* 合并K个升序链表.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你一个链表数组，每个链表都已经按升序排列。

请你将所有链表合并到一个升序链表中，返回合并后的链表。

 

示例 1：

输入：lists = [[1,4,5],[1,3,4],[2,6]]
输出：[1,1,2,3,4,4,5,6]
解释：链表数组如下：
[
  1->4->5,
  1->3->4,
  2->6
]
将它们合并到一个有序链表中得到。
1->1->2->3->4->4->5->6
示例 2：

输入：lists = []
输出：[]
示例 3：

输入：lists = [[]]
输出：[]
 

提示：

k == lists.length
0 <= k <= 10^4
0 <= lists[i].length <= 500
-10^4 <= lists[i][j] <= 10^4
lists[i] 按 升序 排列
lists[i].length 的总和不超过 10^4

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/merge-k-sorted-lists
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <queue>
#include "../check/CheckResult.h"

using namespace std;

struct listNodeCompare {
    bool operator()(const ListNode* node1, const ListNode* node2) const {
        return node1->val > node2->val;
    }
};

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode pseudoHead(0);
        ListNode* tail = &pseudoHead;
        priority_queue<ListNode*, vector<ListNode*>, listNodeCompare> nodes;

        for (ListNode* node : lists) {
            if (node != NULL) {
                nodes.push(node);
            }
        }

        while (!nodes.empty()) {
            tail->next = nodes.top();
            tail = nodes.top();
            nodes.pop();

            if (tail->next != NULL) {
                nodes.push(tail->next);
            }
        }

        return pseudoHead.next;
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<ListNode*> lists;
    vector<int> values = { 1,4,5 };
    lists.push_back(createList(values));
    values = { 1,3,4 };
    lists.push_back(createList(values));
    values = { 2,6 };
    lists.push_back(createList(values));
    values = { 1,1,2,3,4,4,5,6 };
    check.checkSingleList(createList(values), o.mergeKLists(lists));

    lists = {};
    values = {  };
    check.checkSingleList(createList(values), o.mergeKLists(lists));

    lists = {};
    values = {  };
    lists.push_back(createList(values));
    values = {  };
    check.checkSingleList(createList(values), o.mergeKLists(lists));

    lists = {};
    values = { 1,2,3 };
    lists.push_back(createList(values));
    values = { 4,5,6 };
    lists.push_back(createList(values));
    values = {  };
    lists.push_back(createList(values));
    values = { 7,8,9 };
    lists.push_back(createList(values));
    values = { 1,2,3,4,5,6,7,8,9 };
    check.checkSingleList(createList(values), o.mergeKLists(lists));
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
