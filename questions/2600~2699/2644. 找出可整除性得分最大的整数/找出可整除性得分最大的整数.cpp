/* 找出可整除性得分最大的整数.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你两个下标从 0 开始的整数数组 nums 和 divisors 。

divisors[i] 的 可整除性得分 等于满足 nums[j] 能被 divisors[i] 整除的下标 j 的数量。

返回 可整除性得分 最大的整数 divisors[i] 。如果有多个整数具有最大得分，则返回数值最小的一个。



示例 1：

输入：nums = [4,7,9,3,9], divisors = [5,2,3]
输出：3
解释：divisors 中每个元素的可整除性得分为：
divisors[0] 的可整除性得分为 0 ，因为 nums 中没有任何数字能被 5 整除。
divisors[1] 的可整除性得分为 1 ，因为 nums[0] 能被 2 整除。
divisors[2] 的可整除性得分为 3 ，因为 nums[2]、nums[3] 和 nums[4] 都能被 3 整除。
因此，返回 divisors[2] ，它的可整除性得分最大。
示例 2：

输入：nums = [20,14,21,10], divisors = [5,7,5]
输出：5
解释：divisors 中每个元素的可整除性得分为：
divisors[0] 的可整除性得分为 2 ，因为 nums[0] 和 nums[3] 都能被 5 整除。
divisors[1] 的可整除性得分为 2 ，因为 nums[1] 和 nums[2] 都能被 7 整除。
divisors[2] 的可整除性得分为 2 ，因为 nums[0] 和 nums[3] 都能被5整除。
由于 divisors[0]、divisors[1] 和 divisors[2] 的可整除性得分都是最大的，因此，我们返回数值最小的一个，即 divisors[2] 。
示例 3：

输入：nums = [12], divisors = [10,16]
输出：10
解释：divisors 中每个元素的可整除性得分为：
divisors[0] 的可整除性得分为 0 ，因为 nums 中没有任何数字能被 10 整除。
divisors[1] 的可整除性得分为 0 ，因为 nums 中没有任何数字能被 16 整除。
由于 divisors[0] 和 divisors[1] 的可整除性得分都是最大的，因此，我们返回数值最小的一个，即 divisors[0] 。


提示：

1 <= nums.length, divisors.length <= 1000
1 <= nums[i], divisors[i] <= 109
*/

#include <iostream>
#include <algorithm>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int maxDivScore(vector<int>& nums, vector<int>& divisors) {
        int value = INT_MAX, maxScore = 0;

        for (int divisor : divisors) {
            int score = 0;

            for (int num : nums) {
                if (num % divisor == 0) {
                    ++score;
                }
            }

            if (score > maxScore) {
                maxScore = score;
                value = divisor;
            }
            else if (score == maxScore) {
                value = min(value, divisor);
            }
        }

        return value;
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<int> nums = { 4,7,9,3,9 };
    vector<int> divisors = { 5,2,3 };
    check.checkInt(3, o.maxDivScore(nums, divisors));

    nums = { 20,14,21,10 };
    divisors = { 5,7,5 };
    check.checkInt(5, o.maxDivScore(nums, divisors));

    nums = { 12 };
    divisors = { 10,16 };
    check.checkInt(10, o.maxDivScore(nums, divisors));
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
