/* 3n 块披萨.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你一个披萨，它由 3n 块不同大小的部分组成，现在你和你的朋友们需要按照如下规则来分披萨：

你挑选 任意 一块披萨。
Alice 将会挑选你所选择的披萨逆时针方向的下一块披萨。
Bob 将会挑选你所选择的披萨顺时针方向的下一块披萨。
重复上述过程直到没有披萨剩下。
每一块披萨的大小按顺时针方向由循环数组 slices 表示。

请你返回你可以获得的披萨大小总和的最大值。

 

示例 1：



输入：slices = [1,2,3,4,5,6]
输出：10
解释：选择大小为 4 的披萨，Alice 和 Bob 分别挑选大小为 3 和 5 的披萨。然后你选择大小为 6 的披萨，Alice 和 Bob 分别挑选大小为 2 和 1 的披萨。你获得的披萨总大小为 4 + 6 = 10 。
示例 2：



输入：slices = [8,9,8,6,1,1]
输出：16
解释：两轮都选大小为 8 的披萨。如果你选择大小为 9 的披萨，你的朋友们就会选择大小为 8 的披萨，这种情况下你的总和不是最大的。
示例 3：

输入：slices = [4,1,2,5,8,3,1,9,7]
输出：21
示例 4：

输入：slices = [3,1,2]
输出：3
 

提示：

1 <= slices.length <= 500
slices.length % 3 == 0
1 <= slices[i] <= 1000

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/pizza-with-3n-slices
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <algorithm>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int maxSizeSlices(vector<int>& slices) {
        /* 问题等价于在3n个数中选择n个不相邻的数。因为：
           必定存在一个被选的数x，它至少有一侧连续2个数没有被选。否则将出现...a0x0b...，那么x被选走后ab相邻了。
           所以至少存在..00x0...，那么选择x后问题退化为3(n-1)个数里面选择(n-1)个数并能够保证不相邻 */
        int size = slices.size(), maxLen = size - 1, n = size / 3;

        // 循环数组，尝试选第1个，不选最后一个；或者不选第1个，选最后一个。取两者大的。
        return max(getMaxSizeSlices(slices, 0, maxLen, n), getMaxSizeSlices(slices, 1, maxLen, n));
    }

    int getMaxSizeSlices(vector<int>& slices, int start, int maxLen, int n) {
        int count, len;
        vector<vector<int>> dp(n + 1, vector<int>(maxLen + 1, 0));  // 从slices的前len个数选择count个不相邻的数取得的最大值

        for (len = 1; len <= maxLen; ++len) {
            dp[1][len] = max(dp[1][len - 1], slices[start + len - 1]);  // 只选一个，那么就是最大值
        }

        for (count = 2; count <= n; ++count) {
            for (len = 2 * count - 1; len <= maxLen; ++len) {
                // 选择最后一个数，那么还要从前面len-2里面选择count-1个；或者不选最后一个数，那么还要从len-1里面选择count个
                dp[count][len] = max(slices[start + len - 1] + dp[count - 1][len - 2], dp[count][len - 1]);
            }
        }

        return dp[n][maxLen];
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<int> slices = { 1,2,3,4,5,6 };
    check.checkInt(10, o.maxSizeSlices(slices));

    slices = { 8,9,8,6,1,1 };
    check.checkInt(16, o.maxSizeSlices(slices));

    slices = { 4,1,2,5,8,3,1,9,7 };
    check.checkInt(21, o.maxSizeSlices(slices));

    slices = { 3,1,2 };
    check.checkInt(3, o.maxSizeSlices(slices));

    slices = { 1,2,3,4,5,6,7,8,9,10,10,9,8,7,6,5,4,3,2,1,1,2,3,4,5,6,7,8,9,10,10,9,8,7,6,5,4,3,2,1,1,2,3,4,5,6,7,8,9,10,10,9,8,7,6,5,4,3,2,1 };
    check.checkInt(143, o.maxSizeSlices(slices));
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
