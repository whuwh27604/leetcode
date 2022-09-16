/* 回文链表.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给定一个链表的头结点 head，判断链表删除一个节点后是否可以成为「回文链表」。
若可以，则返回 true；否则返回 false

注意：

输入用例均保证链表长度 大于等于 3
示例 1：

输入：head = [1,2,2,3,1]

输出：true

解释：如下图所示，蓝色结点为删除的结点
删除该节点后，链表为「回文链表」 [1,2,2,1]，返回 true
image.png

示例 2：

输入：head = [5,1,8,8,1,5]

输出：true

解释： 删除节点值为 8 的节点

示例 3：

输入：head = [1,2,3,4]

输出：false

提示：

链表中节点数目在范围 [3, 10^5]
0 <= Node.val <= 10
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    bool isPalindrome(ListNode* head) {
        vector<int> nums;
        list2Vector(head, nums);

        int left, right, size = nums.size();

        for (left = 0, right = size - 1; left < right && nums[left] == nums[right]; ++left, --right) {}

        return isPalindrome(nums, left + 1, right) || isPalindrome(nums, left, right - 1);
    }

    void list2Vector(ListNode* head, vector<int>& nums) {
        ListNode* node = head;

        while (node != NULL) {
            nums.push_back(node->val);
            node = node->next;
        }
    }

    bool isPalindrome(vector<int>& nums, int left, int right) {
        for (; left < right && nums[left] == nums[right]; ++left, --right) {}

        return left >= right;
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<int> values = { 1,2,2,3,1 };
    check.checkBool(true, o.isPalindrome(createList(values)));

    values = { 5,1,8,8,1,5 };
    check.checkBool(true, o.isPalindrome(createList(values)));

    values = { 5,1,8,1,5 };
    check.checkBool(true, o.isPalindrome(createList(values)));

    values = { 1,2,3,4 };
    check.checkBool(false, o.isPalindrome(createList(values)));
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
