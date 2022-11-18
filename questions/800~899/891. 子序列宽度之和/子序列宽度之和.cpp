/* 子序列宽度之和.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
一个序列的 宽度 定义为该序列中最大元素和最小元素的差值。

给你一个整数数组 nums ，返回 nums 的所有非空 子序列 的 宽度之和 。由于答案可能非常大，请返回对 109 + 7 取余 后的结果。

子序列 定义为从一个数组里删除一些（或者不删除）元素，但不改变剩下元素的顺序得到的数组。例如，[3,6,2,7] 就是数组 [0,3,1,6,2,2,7] 的一个子序列。



示例 1：

输入：nums = [2,1,3]
输出：6
解释：子序列为 [1], [2], [3], [2,1], [2,3], [1,3], [2,1,3] 。
相应的宽度是 0, 0, 0, 1, 1, 2, 2 。
宽度之和是 6 。
示例 2：

输入：nums = [2]
输出：0


提示：

1 <= nums.length <= 105
1 <= nums[i] <= 105
*/

#include <iostream>
#include <algorithm>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int sumSubseqWidths(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        int size = nums.size();
        long long sum = nums[0], pow = 1, mod = 1000000007;

        for (int i = 1; i < size; ++i) {
            pow = pow * 2 % mod;
            sum = (sum + pow * nums[i]) % mod;
        }

        sum -= nums.back();
        pow = 1;

        for (int i = size - 2; i >= 0; --i) {
            pow = pow * 2 % mod;
            sum = (sum + mod - pow * nums[i] % mod) % mod;
        }

        return (int)sum;
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<int> nums = { 2,1,3 };
    check.checkInt(6, o.sumSubseqWidths(nums));

    nums = { 2 };
    check.checkInt(0, o.sumSubseqWidths(nums));

    nums = { 1,1,3 };
    check.checkInt(6, o.sumSubseqWidths(nums));

    nums = { 1,1,1 };
    check.checkInt(0, o.sumSubseqWidths(nums));

    nums = { 1,2,1,1 };
    check.checkInt(7, o.sumSubseqWidths(nums));

    nums = { 2,1,3,2,1,1,3 };
    check.checkInt(198, o.sumSubseqWidths(nums));

    nums = { 5,69,89,92,31,16,25,45,63,40,16,56,24,40,75,82,40,12,50,62,92,44,67,38,92,22,91,24,26,21,100,42,23,56,64,43,95,76,84,79,89,4,16,94,16,77,92,9,30,13 };
    check.checkInt(857876214, o.sumSubseqWidths(nums));
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
