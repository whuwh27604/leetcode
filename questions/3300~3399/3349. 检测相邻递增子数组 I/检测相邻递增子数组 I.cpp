/* 检测相邻递增子数组 I.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你一个由 n 个整数组成的数组 nums 和一个整数 k，请你确定是否存在 两个 相邻 且长度为 k 的 严格递增 子数组。具体来说，需要检查是否存在从下标 a 和 b (a < b) 开始的 两个 子数组，并满足下述全部条件：

这两个子数组 nums[a..a + k - 1] 和 nums[b..b + k - 1] 都是 严格递增 的。
这两个子数组必须是 相邻的，即 b = a + k。
如果可以找到这样的 两个 子数组，请返回 true；否则返回 false。

子数组 是数组中的一个连续 非空 的元素序列。



示例 1：

输入：nums = [2,5,7,8,9,2,3,4,3,1], k = 3

输出：true

解释：

从下标 2 开始的子数组为 [7, 8, 9]，它是严格递增的。
从下标 5 开始的子数组为 [2, 3, 4]，它也是严格递增的。
两个子数组是相邻的，因此结果为 true。
示例 2：

输入：nums = [1,2,3,4,4,4,4,5,6,7], k = 5

输出：false



提示：

2 <= nums.length <= 100
1 <= 2 * k <= nums.length
-1000 <= nums[i] <= 1000
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    bool hasIncreasingSubarrays(vector<int>& nums, int k) {
        nums.push_back(INT_MIN);
        int len1 = -1, len2 = -1, start = 0;

        for (int i = 1; i < (int)nums.size(); ++i) {
            if (nums[i] <= nums[i - 1]) {
                len1 = len2;
                len2 = i - start;
                start = i;

                if (len2 >= 2 * k || (len1 >= k && len2 >= k)) {
                    return true;
                }
            }
        }

        return false;
    }
};

int main()
{
    Solution o;
    CheckResult check;

    vector<int> nums = { 2,5,7,8,9,2,3,4,3,1 };
    check.checkBool(true, o.hasIncreasingSubarrays(nums, 3));

    nums = { 1,2,3,4,5,6 };
    check.checkBool(true, o.hasIncreasingSubarrays(nums, 3));

    nums = { 1,2,3,4,4,4,4,5,6,7 };
    check.checkBool(false, o.hasIncreasingSubarrays(nums, 5));
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
