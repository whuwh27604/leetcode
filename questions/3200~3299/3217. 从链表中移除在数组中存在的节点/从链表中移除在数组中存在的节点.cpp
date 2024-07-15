/* 从链表中移除在数组中存在的节点.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你一个整数数组 nums 和一个链表的头节点 head。从链表中移除所有存在于 nums 中的节点后，返回修改后的链表的头节点。



示例 1：

输入： nums = [1,2,3], head = [1,2,3,4,5]

输出： [4,5]

解释：



移除数值为 1, 2 和 3 的节点。

示例 2：

输入： nums = [1], head = [1,2,1,2,1,2]

输出： [2,2,2]

解释：



移除数值为 1 的节点。

示例 3：

输入： nums = [5], head = [1,2,3,4]

输出： [1,2,3,4]

解释：



链表中不存在值为 5 的节点。



提示：

1 <= nums.length <= 105
1 <= nums[i] <= 105
nums 中的所有元素都是唯一的。
链表中的节点数在 [1, 105] 的范围内。
1 <= Node.val <= 105
输入保证链表中至少有一个值没有在 nums 中出现过。
*/

#include <iostream>
#include <unordered_set>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        unordered_set<int> numbers;

        for (int num : nums) {
            numbers.insert(num);
        }

        ListNode* prev = head;
        ListNode* node = head;

        while (node != NULL) {
            if (numbers.count(node->val) != 0) {
                if (node == head) {
                    head = node->next;
                }
                else {
                    prev->next = node->next;
                }
            }
            else {
                prev = node;
            }

            node = node->next;
        }

        return head;
    }
};

int main()
{
    Solution o;
    CheckResult check;

    vector<int> nums = { 1,2,3 };
    vector<int> values = { 1,2,3,4,5 };
    ListNode* actual = o.modifiedList(nums, createList(values));
    values = { 4,5 };
    ListNode* expected = createList(values);
    check.checkSingleList(expected, actual);

    nums = { 1 };
    values = { 1,2,1,2,1,2 };
    actual = o.modifiedList(nums, createList(values));
    values = { 2,2,2 };
    expected = createList(values);
    check.checkSingleList(expected, actual);

    nums = { 5 };
    values = { 1,2,3,4 };
    actual = o.modifiedList(nums, createList(values));
    values = { 1,2,3,4 };
    expected = createList(values);
    check.checkSingleList(expected, actual);
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
