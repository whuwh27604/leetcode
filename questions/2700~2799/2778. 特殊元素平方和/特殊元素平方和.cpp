/* 特殊元素平方和.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你一个下标从 1 开始、长度为 n 的整数数组 nums 。

对 nums 中的元素 nums[i] 而言，如果 n 能够被 i 整除，即 n % i == 0 ，则认为 num[i] 是一个 特殊元素 。

返回 nums 中所有 特殊元素 的 平方和 。



示例 1：

输入：nums = [1,2,3,4]
输出：21
解释：nums 中共有 3 个特殊元素：nums[1] ，因为 4 被 1 整除；nums[2] ，因为 4 被 2 整除；以及 nums[4] ，因为 4 被 4 整除。
因此，nums 中所有元素的平方和等于 nums[1] * nums[1] + nums[2] * nums[2] + nums[4] * nums[4] = 1 * 1 + 2 * 2 + 4 * 4 = 21 。
示例 2：

输入：nums = [2,7,1,19,18,3]
输出：63
解释：nums 中共有 4 个特殊元素：nums[1] ，因为 6 被 1 整除；nums[2] ，因为 6 被 2 整除；nums[3] ，因为 6 被 3 整除；以及 nums[6] ，因为 6 被 6 整除。
因此，nums 中所有元素的平方和等于 nums[1] * nums[1] + nums[2] * nums[2] + nums[3] * nums[3] + nums[6] * nums[6] = 2 * 2 + 7 * 7 + 1 * 1 + 3 * 3 = 63 。


提示：

1 <= nums.length == n <= 50
1 <= nums[i] <= 50
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int sumOfSquares(vector<int>& nums) {
        int sum = 0, n = nums.size();

        for (int i = 0; i < n; ++i) {
            if (n % (i + 1) == 0) {
                sum += (nums[i] * nums[i]);
            }
        }

        return sum;
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<int> nums = { 1,2,3,4 };
    check.checkInt(21, o.sumOfSquares(nums));

    nums = { 2,7,1,19,18,3 };
    check.checkInt(63, o.sumOfSquares(nums));
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
