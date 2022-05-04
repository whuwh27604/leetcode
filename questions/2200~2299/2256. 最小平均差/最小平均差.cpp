/* 最小平均差.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你一个下标从 0 开始长度为 n 的整数数组 nums 。

下标 i 处的 平均差 指的是 nums 中 前 i + 1 个元素平均值和 后 n - i - 1 个元素平均值的 绝对差 。两个平均值都需要 向下取整 到最近的整数。

请你返回产生 最小平均差 的下标。如果有多个下标最小平均差相等，请你返回 最小 的一个下标。

注意：

两个数的 绝对差 是两者差的绝对值。
 n 个元素的平均值是 n 个元素之 和 除以（整数除法） n 。
0 个元素的平均值视为 0 。
 

示例 1：

输入：nums = [2,5,3,9,5,3]
输出：3
解释：
- 下标 0 处的平均差为：|2 / 1 - (5 + 3 + 9 + 5 + 3) / 5| = |2 / 1 - 25 / 5| = |2 - 5| = 3 。
- 下标 1 处的平均差为：|(2 + 5) / 2 - (3 + 9 + 5 + 3) / 4| = |7 / 2 - 20 / 4| = |3 - 5| = 2 。
- 下标 2 处的平均差为：|(2 + 5 + 3) / 3 - (9 + 5 + 3) / 3| = |10 / 3 - 17 / 3| = |3 - 5| = 2 。
- 下标 3 处的平均差为：|(2 + 5 + 3 + 9) / 4 - (5 + 3) / 2| = |19 / 4 - 8 / 2| = |4 - 4| = 0 。
- 下标 4 处的平均差为：|(2 + 5 + 3 + 9 + 5) / 5 - 3 / 1| = |24 / 5 - 3 / 1| = |4 - 3| = 1 。
- 下标 5 处的平均差为：|(2 + 5 + 3 + 9 + 5 + 3) / 6 - 0| = |27 / 6 - 0| = |4 - 0| = 4 。
下标 3 处的平均差为最小平均差，所以返回 3 。
示例 2：

输入：nums = [0]
输出：0
解释：
唯一的下标是 0 ，所以我们返回 0 。
下标 0 处的平均差为：|0 / 1 - 0| = |0 - 0| = 0 。
 

提示：

1 <= nums.length <= 105
0 <= nums[i] <= 105

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/minimum-average-difference
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <numeric>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int minimumAverageDifference(vector<int>& nums) {
        int i, size = nums.size(), index = 0;
        long long left = 0, right = accumulate(nums.begin(), nums.end(), (long long)0);
        long long diff, minDiff = LLONG_MAX;

        for (i = 0; i < size; ++i) {
            left += nums[i];
            right -= nums[i];
            diff = abs(left / ((long long)i + 1) - (i == size - 1 ? 0 : right / ((long long)size - i - 1)));

            if (diff < minDiff) {
                minDiff = diff;
                index = i;
            }
        }

        return index;
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<int> nums = { 2,5,3,9,5,3 };
    check.checkInt(3, o.minimumAverageDifference(nums));

    nums = { 0 };
    check.checkInt(0, o.minimumAverageDifference(nums));

    nums = { 5,4,3,2,1 };
    check.checkInt(1, o.minimumAverageDifference(nums));

    nums = { 0,0,0,0 };
    check.checkInt(0, o.minimumAverageDifference(nums));
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
