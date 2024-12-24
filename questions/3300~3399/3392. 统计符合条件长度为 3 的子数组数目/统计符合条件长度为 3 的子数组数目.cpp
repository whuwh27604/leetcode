/* 统计符合条件长度为 3 的子数组数目.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你一个整数数组 nums ，请你返回长度为 3 的子数组，满足第一个数和第三个数的和恰好为第二个数的一半。

子数组 指的是一个数组中连续 非空 的元素序列。



示例 1：

输入：nums = [1,2,1,4,1]

输出：1

解释：

只有子数组 [1,4,1] 包含 3 个元素且第一个和第三个数字之和是中间数字的一半。number.

示例 2：

输入：nums = [1,1,1]

输出：0

解释：

[1,1,1] 是唯一长度为 3 的子数组，但第一个数和第三个数的和不是第二个数的一半。



提示：

3 <= nums.length <= 100
-100 <= nums[i] <= 100
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int countSubarrays(vector<int>& nums) {
        int size = (int)nums.size(), cnt = 0;

        for (int i = 0; i < size - 2; ++i) {
            if ((nums[i] + nums[i + 2]) * 2 == nums[i + 1]) {
                ++cnt;
            }
        }

        return cnt;
    }
};

int main()
{
    Solution o;
    CheckResult check;

    vector<int> nums = { 1,2,1,4,1 };
    check.checkInt(1, o.countSubarrays(nums));

    nums = { 1,1,1 };
    check.checkInt(0, o.countSubarrays(nums));
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
