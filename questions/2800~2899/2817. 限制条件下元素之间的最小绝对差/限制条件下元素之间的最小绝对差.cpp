/* 限制条件下元素之间的最小绝对差.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你一个下标从 0 开始的整数数组 nums 和一个整数 x 。

请你找到数组中下标距离至少为 x 的两个元素的 差值绝对值 的 最小值 。

换言之，请你找到两个下标 i 和 j ，满足 abs(i - j) >= x 且 abs(nums[i] - nums[j]) 的值最小。

请你返回一个整数，表示下标距离至少为 x 的两个元素之间的差值绝对值的 最小值 。



示例 1：

输入：nums = [4,3,2,4], x = 2
输出：0
解释：我们选择 nums[0] = 4 和 nums[3] = 4 。
它们下标距离满足至少为 2 ，差值绝对值为最小值 0 。
0 是最优解。
示例 2：

输入：nums = [5,3,2,10,15], x = 1
输出：1
解释：我们选择 nums[1] = 3 和 nums[2] = 2 。
它们下标距离满足至少为 1 ，差值绝对值为最小值 1 。
1 是最优解。
示例 3：

输入：nums = [1,2,3,4], x = 3
输出：3
解释：我们选择 nums[0] = 1 和 nums[3] = 4 。
它们下标距离满足至少为 3 ，差值绝对值为最小值 3 。
3 是最优解。


提示：

1 <= nums.length <= 105
1 <= nums[i] <= 109
0 <= x < nums.length
*/

#include <iostream>
#include <map>
#include <algorithm>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int minAbsoluteDifference(vector<int>& nums, int x) {
        if (x == 0) {
            return 0;
        }

        int size = nums.size(), minDiff = INT_MAX;
        map<int, int> mp;  // mp维护可以和nums[i]比较的数

        for (int i = x; i < size; ++i) {  // 将右侧可以和nums[0]比较的数加入mp
            ++mp[nums[i]];
        }

        for (int i = 0; i < size; ++i) {  // 遍历nums[i]
            int num = nums[i];

            if (i - x >= 0) {  // 将左侧可以比较的数加入mp
                ++mp[nums[i - x]];
            }

            auto iter = mp.lower_bound(num);  // 找到第一个大于等于nums[i]的数
            if (iter != mp.end()) {
                minDiff = min(minDiff, iter->first - num);
            }
            if (iter != mp.begin()) {
                --iter;  // 第一个小于nums[i]的数
                minDiff = min(minDiff, num - iter->first);
            }

            if (i + x < size) {  // 将右侧落入窗口的数移除（abs(i - j) < x）
                if (--mp[nums[i + x]] == 0) {
                    mp.erase(nums[i + x]);
                }
            }
        }

        return minDiff;
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<int> nums = { 4,3,2,4 };
    check.checkInt(0, o.minAbsoluteDifference(nums, 2));

    nums = { 5,3,2,10,15 };
    check.checkInt(1, o.minAbsoluteDifference(nums, 1));

    nums = { 1,2,3,4 };
    check.checkInt(3, o.minAbsoluteDifference(nums, 3));
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
