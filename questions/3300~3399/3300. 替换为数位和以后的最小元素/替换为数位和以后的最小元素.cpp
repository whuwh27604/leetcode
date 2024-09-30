/* 替换为数位和以后的最小元素.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你一个整数数组 nums 。

请你将 nums 中每一个元素都替换为它的各个数位之 和 。

请你返回替换所有元素以后 nums 中的 最小 元素。



示例 1：

输入：nums = [10,12,13,14]

输出：1

解释：

nums 替换后变为 [1, 3, 4, 5] ，最小元素为 1 。

示例 2：

输入：nums = [1,2,3,4]

输出：1

解释：

nums 替换后变为 [1, 2, 3, 4] ，最小元素为 1 。

示例 3：

输入：nums = [999,19,199]

输出：10

解释：

nums 替换后变为 [27, 10, 19] ，最小元素为 10 。



提示：

1 <= nums.length <= 100
1 <= nums[i] <= 104
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int minElement(vector<int>& nums) {
        int minSum = INT_MAX;

        for (int num : nums) {
            int sum = 0;

            while (num != 0) {
                sum += num % 10;
                num /= 10;
            }

            minSum = min(minSum, sum);
        }

        return minSum;
    }
};

int main()
{
    Solution o;
    CheckResult check;

    vector<int> nums = { 10,12,13,14 };
    check.checkInt(1, o.minElement(nums));

    nums = { 1,2,3,4 };
    check.checkInt(1, o.minElement(nums));

    nums = { 999,19,199 };
    check.checkInt(10, o.minElement(nums));
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
