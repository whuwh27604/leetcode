/* 从链表中移除节点.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你一个链表的头节点 head 。

对于列表中的每个节点 node ，如果其右侧存在一个具有 严格更大 值的节点，则移除 node 。

返回修改后链表的头节点 head 。



示例 1：



输入：head = [5,2,13,3,8]
输出：[13,8]
解释：需要移除的节点是 5 ，2 和 3 。
- 节点 13 在节点 5 右侧。
- 节点 13 在节点 2 右侧。
- 节点 8 在节点 3 右侧。
示例 2：

输入：head = [1,1,1,1]
输出：[1,1,1,1]
解释：每个节点的值都是 1 ，所以没有需要移除的节点。


提示：

给定列表中的节点数目在范围 [1, 105] 内
1 <= Node.val <= 105
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    ListNode* removeNodes(ListNode* head) {
        vector<int> nums;

        getNums(head, nums);
        deleteNums(nums);

        return getList(nums);
    }

    void getNums(ListNode* head, vector<int>& nums) {
        ListNode* node = head;

        while (node != NULL) {
            nums.push_back(node->val);
            node = node->next;
        }
    }

    void deleteNums(vector<int>& nums) {
        int largest = 0;

        for (int i = nums.size() - 1; i >= 0; --i) {
            if (nums[i] < largest) {
                nums[i] = 0;
            }
            else {
                largest = nums[i];
            }
        }
    }

    ListNode* getList(vector<int>& nums) {
        ListNode* head = NULL;
        ListNode* tail = NULL;

        for (int num : nums) {
            if (num != 0) {
                ListNode* node = new ListNode(num);
                if (head == NULL) {
                    head = node;
                    tail = node;
                }
                else {
                    tail->next = node;
                    tail = node;
                }
            }
        }

        return head;
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<int> values = { 5,2,13,3,8 };
    ListNode* actual = o.removeNodes(createList(values));
    values = { 13,8 };
    check.checkSingleList(createList(values), actual);

    values = { 1,1,1,1 };
    actual = o.removeNodes(createList(values));
    values = { 1,1,1,1 };
    check.checkSingleList(createList(values), actual);

    values = { 5 };
    actual = o.removeNodes(createList(values));
    values = { 5 };
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
