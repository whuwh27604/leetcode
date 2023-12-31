/* 找到最大周长的多边形.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你一个长度为 n 的 正 整数数组 nums 。

多边形 指的是一个至少有 3 条边的封闭二维图形。多边形的 最长边 一定 小于 所有其他边长度之和。

如果你有 k （k >= 3）个 正 数 a1，a2，a3, ...，ak 满足 a1 <= a2 <= a3 <= ... <= ak 且 a1 + a2 + a3 + ... + ak-1 > ak ，那么 一定 存在一个 k 条边的多边形，每条边的长度分别为 a1 ，a2 ，a3 ， ...，ak 。

一个多边形的 周长 指的是它所有边之和。

请你返回从 nums 中可以构造的 多边形 的 最大周长 。如果不能构造出任何多边形，请你返回 -1 。



示例 1：

输入：nums = [5,5,5]
输出：15
解释：nums 中唯一可以构造的多边形为三角形，每条边的长度分别为 5 ，5 和 5 ，周长为 5 + 5 + 5 = 15 。
示例 2：

输入：nums = [1,12,1,2,5,50,3]
输出：12
解释：最大周长多边形为五边形，每条边的长度分别为 1 ，1 ，2 ，3 和 5 ，周长为 1 + 1 + 2 + 3 + 5 = 12 。
我们无法构造一个包含变长为 12 或者 50 的多边形，因为其他边之和没法大于两者中的任何一个。
所以最大周长为 12 。
示例 3：

输入：nums = [5,5,50]
输出：-1
解释：无法构造任何多边形，因为多边形至少要有 3 条边且 50 > 5 + 5 。


提示：

3 <= n <= 105
1 <= nums[i] <= 109
*/

#include <iostream>
#include <algorithm>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    long long largestPerimeter(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        int size = nums.size(), j = 2;
        long long perimeter = -1, sum = nums[0];

        for (int i = 1; i < size; ++i) {
            sum += nums[i];

            for (j = max(j, i + 1); j < size && sum > nums[j]; ++j) {
                perimeter = sum + nums[j++];
            }

            --j;
        }

        return perimeter;
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<int> nums = { 5,5,5 };
    check.checkLongLong(15, o.largestPerimeter(nums));

    nums = { 1,12,1,2,5,50,3 };
    check.checkLongLong(12, o.largestPerimeter(nums));

    nums = { 5,5,50 };
    check.checkLongLong(-1, o.largestPerimeter(nums));

    nums = { 2,5,4,5 };
    check.checkLongLong(16, o.largestPerimeter(nums));

    nums = { 2,1,1 };
    check.checkLongLong(-1, o.largestPerimeter(nums));
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
