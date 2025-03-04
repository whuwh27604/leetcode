/* 找出最大的几近缺失整数.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你一个整数数组 nums 和一个整数 k 。

如果整数 x 恰好仅出现在 nums 中的一个大小为 k 的子数组中，则认为 x 是 nums 中的几近缺失（almost missing）整数。

返回 nums 中 最大的几近缺失 整数，如果不存在这样的整数，返回 -1 。

子数组 是数组中的一个连续元素序列。


示例 1：

输入：nums = [3,9,2,1,7], k = 3

输出：7

解释：

1 出现在两个大小为 3 的子数组中：[9, 2, 1]、[2, 1, 7]
2 出现在三个大小为 3 的子数组中：[3, 9, 2]、[9, 2, 1]、[2, 1, 7]
3 出现在一个大小为 3 的子数组中：[3, 9, 2]
7 出现在一个大小为 3 的子数组中：[2, 1, 7]
9 出现在两个大小为 3 的子数组中：[3, 9, 2]、[9, 2, 1]
返回 7 ，因为它满足题意的所有整数中最大的那个。

示例 2：

输入：nums = [3,9,7,2,1,7], k = 4

输出：3

解释：

1 出现在两个大小为 3 的子数组中：[9, 7, 2, 1]、[7, 2, 1, 7]
2 出现在三个大小为 3 的子数组中：[3, 9, 7, 2]、[9, 7, 2, 1]、[7, 2, 1, 7]
3 出现在一个大小为 3 的子数组中：[3, 9, 7, 2]
7 出现在三个大小为 3 的子数组中：[3, 9, 7, 2]、[9, 7, 2, 1]、[7, 2, 1, 7]
9 出现在两个大小为 3 的子数组中：[3, 9, 7, 2]、[9, 7, 2, 1]
返回 3 ，因为它满足题意的所有整数中最大的那个。

示例 3：

输入：nums = [0,0], k = 1

输出：-1

解释：

不存在满足题意的整数。



提示：

1 <= nums.length <= 50
0 <= nums[i] <= 50
1 <= k <= nums.length
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        int n = (int)nums.size();

        return k == n ? getAMn(nums) : (k == 1 ? getAM1(nums) : getAMk(nums));
    }

    int getAMn(vector<int>& nums) {  // 只有一个子数组，返回最大的数即可
        return *max_element(nums.begin(), nums.end());
    }

    int getAM1(vector<int>& nums) {  // 子数组长度为1，返回只出现一次的最大数
        vector<int> cnt(51, 0);

        for (int num : nums) {
            ++cnt[num];
        }

        for (int num = 50; num >= 0; --num) {
            if (cnt[num] == 1) {
                return num;
            }
        }

        return -1;
    }

    int getAMk(vector<int>& nums) {  // 中间数都会出现在多个子数组中，答案只可能是首尾两个数
        int a = min(nums[0], nums.back()), b = max(nums[0], nums.back());
        int cntA = 0, cntB = 0;

        for (int num : nums) {
            if (num == a) {
                ++cntA;
            }

            if (num == b) {
                ++cntB;
            }
        }

        return cntB == 1 ? b : (cntA == 1 ? a : -1);
    }
};

int main()
{
    Solution o;
    CheckResult check;

    vector<int> nums = { 3,9,2,1,7 };
    check.checkInt(7, o.largestInteger(nums, 3));

    nums = { 3,9,7,2,1,7 };
    check.checkInt(3, o.largestInteger(nums, 4));

    nums = { 0,0 };
    check.checkInt(-1, o.largestInteger(nums, 1));
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
