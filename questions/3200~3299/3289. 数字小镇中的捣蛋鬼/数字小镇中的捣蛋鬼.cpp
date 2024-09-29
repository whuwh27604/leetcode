/* 数字小镇中的捣蛋鬼.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
数字小镇 Digitville 中，存在一个数字列表 nums，其中包含从 0 到 n - 1 的整数。每个数字本应 只出现一次，然而，有 两个 顽皮的数字额外多出现了一次，使得列表变得比正常情况下更长。

为了恢复 Digitville 的和平，作为小镇中的名侦探，请你找出这两个顽皮的数字。

返回一个长度为 2 的数组，包含这两个数字（顺序任意）。



示例 1：

输入： nums = [0,1,1,0]

输出： [0,1]

解释：

数字 0 和 1 分别在数组中出现了两次。

示例 2：

输入： nums = [0,3,2,1,3,2]

输出： [2,3]

解释:

数字 2 和 3 分别在数组中出现了两次。

示例 3：

输入： nums = [7,1,5,4,3,4,6,0,9,5,8,2]

输出： [4,5]

解释:

数字 4 和 5 分别在数组中出现了两次。



提示：

2 <= n <= 100
nums.length == n + 2
0 <= nums[i] < n
输入保证 nums 中 恰好 包含两个重复的元素。
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    vector<int> getSneakyNumbers(vector<int>& nums) {
        int n = (int)nums.size() - 2;
        vector<bool> exist(n, false);
        vector<int> ans;

        for (int num : nums) {
            if (exist[num]) {
                ans.push_back(num);
            }
            else {
                exist[num] = true;
            }
        }

        return ans;
    }
};

int main()
{
    Solution o;
    CheckResult check;

    vector<int> nums = { 0,1,1,0 };
    vector<int> actual = o.getSneakyNumbers(nums);
    vector<int> expected = { 0,1 };
    check.checkIntVectorRandomOrder(expected, actual);

    nums = { 0,3,2,1,3,2 };
    actual = o.getSneakyNumbers(nums);
    expected = { 2,3 };
    check.checkIntVectorRandomOrder(expected, actual);

    nums = { 7,1,5,4,3,4,6,0,9,5,8,2 };
    actual = o.getSneakyNumbers(nums);
    expected = { 4,5 };
    check.checkIntVectorRandomOrder(expected, actual);
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
