/* 美丽塔 I.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你一个长度为 n 下标从 0 开始的整数数组 maxHeights 。

你的任务是在坐标轴上建 n 座塔。第 i 座塔的下标为 i ，高度为 heights[i] 。

如果以下条件满足，我们称这些塔是 美丽 的：

1 <= heights[i] <= maxHeights[i]
heights 是一个 山状 数组。
如果存在下标 i 满足以下条件，那么我们称数组 heights 是一个 山状 数组：

对于所有 0 < j <= i ，都有 heights[j - 1] <= heights[j]
对于所有 i <= k < n - 1 ，都有 heights[k + 1] <= heights[k]
请你返回满足 美丽塔 要求的方案中，高度和的最大值 。



示例 1：

输入：maxHeights = [5,3,4,1,1]
输出：13
解释：和最大的美丽塔方案为 heights = [5,3,3,1,1] ，这是一个美丽塔方案，因为：
- 1 <= heights[i] <= maxHeights[i]
- heights 是个山状数组，峰值在 i = 0 处。
13 是所有美丽塔方案中的最大高度和。
示例 2：

输入：maxHeights = [6,5,3,9,2,7]
输出：22
解释： 和最大的美丽塔方案为 heights = [3,3,3,9,2,2] ，这是一个美丽塔方案，因为：
- 1 <= heights[i] <= maxHeights[i]
- heights 是个山状数组，峰值在 i = 3 处。
22 是所有美丽塔方案中的最大高度和。
示例 3：

输入：maxHeights = [3,2,5,5,2,3]
输出：18
解释：和最大的美丽塔方案为 heights = [2,2,5,5,2,2] ，这是一个美丽塔方案，因为：
- 1 <= heights[i] <= maxHeights[i]
- heights 是个山状数组，最大值在 i = 2 处。
注意，在这个方案中，i = 3 也是一个峰值。
18 是所有美丽塔方案中的最大高度和。


提示：

1 <= n == maxHeights <= 103
1 <= maxHeights[i] <= 109
*/

#include <iostream>
#include <algorithm>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    long long maximumSumOfHeights(vector<int>& maxHeights) {
        int n = maxHeights.size();
        long long maxSum = 0;

        for (int i = 0; i < n; ++i) {
            maxSum = max(maxSum, getSum(n, i, maxHeights));
        }

        return maxSum;
    }

    long long getSum(int n, int peak, vector<int>& maxHeights) {
        int current = maxHeights[peak];
        long long sum = current;

        for (int i = peak - 1; i >= 0; --i) {
            current = min(current, maxHeights[i]);
            sum += current;
        }

        current = maxHeights[peak];
        for (int i = peak + 1; i < n; ++i) {
            current = min(current, maxHeights[i]);
            sum += current;
        }

        return sum;
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<int> maxHeights = { 5,3,4,1,1 };
    check.checkLongLong(13, o.maximumSumOfHeights(maxHeights));

    maxHeights = { 6,5,3,9,2,7 };
    check.checkLongLong(22, o.maximumSumOfHeights(maxHeights));

    maxHeights = { 3,2,5,5,2,3 };
    check.checkLongLong(18, o.maximumSumOfHeights(maxHeights));

    maxHeights = { 1,5,2,5,6,4,6,3,4,5 };
    check.checkLongLong(33, o.maximumSumOfHeights(maxHeights));
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
