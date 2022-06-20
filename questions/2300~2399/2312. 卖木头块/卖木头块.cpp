/* 卖木头块.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你两个整数 m 和 n ，分别表示一块矩形木块的高和宽。同时给你一个二维整数数组 prices ，其中 prices[i] = [hi, wi, pricei] 表示你可以以 pricei 元的价格卖一块高为 hi 宽为 wi 的矩形木块。

每一次操作中，你必须按下述方式之一执行切割操作，以得到两块更小的矩形木块：

沿垂直方向按高度 完全 切割木块，或
沿水平方向按宽度 完全 切割木块
在将一块木块切成若干小木块后，你可以根据 prices 卖木块。你可以卖多块同样尺寸的木块。你不需要将所有小木块都卖出去。你 不能 旋转切好后木块的高和宽。

请你返回切割一块大小为 m x n 的木块后，能得到的 最多 钱数。

注意你可以切割木块任意次。

 

示例 1：



输入：m = 3, n = 5, prices = [[1,4,2],[2,2,7],[2,1,3]]
输出：19
解释：上图展示了一个可行的方案。包括：
- 2 块 2 x 2 的小木块，售出 2 * 7 = 14 元。
- 1 块 2 x 1 的小木块，售出 1 * 3 = 3 元。
- 1 块 1 x 4 的小木块，售出 1 * 2 = 2 元。
总共售出 14 + 3 + 2 = 19 元。
19 元是最多能得到的钱数。
示例 2：



输入：m = 4, n = 6, prices = [[3,2,10],[1,4,2],[4,1,3]]
输出：32
解释：上图展示了一个可行的方案。包括：
- 3 块 3 x 2 的小木块，售出 3 * 10 = 30 元。
- 1 块 1 x 4 的小木块，售出 1 * 2 = 2 元。
总共售出 30 + 2 = 32 元。
32 元是最多能得到的钱数。
注意我们不能旋转 1 x 4 的木块来得到 4 x 1 的木块。
 

提示：

1 <= m, n <= 200
1 <= prices.length <= 2 * 104
prices[i].length == 3
1 <= hi <= m
1 <= wi <= n
1 <= pricei <= 106
所有 (hi, wi) 互不相同 。

来源：力扣（LeetCode）
链接：https://leetcode.cn/problems/selling-pieces-of-wood
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <algorithm>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    long long sellingWood(int m, int n, vector<vector<int>>& prices) {
        vector<vector<int>> woodPrices(m + 1, vector<int>(n + 1, 0));
        vector<vector<long long>> dp(m + 1, vector<long long>(n + 1, 0));

        getWoodPrice(prices, woodPrices);

        for (int i = 1; i <= m; ++i) {
            for (int j = 1; j <= n; ++j) {
                dp[i][j] = woodPrices[i][j];  // 不切割，作为一个整体直接卖

                for (int r = 1; r < i; ++r) {  // 遍历所有横向切割点
                    dp[i][j] = max(dp[i][j], dp[r][j] + dp[i - r][j]);
                }

                for (int c = 1; c < j; ++c) {  // 遍历所有纵向切割点
                    dp[i][j] = max(dp[i][j], dp[i][c] + dp[i][j - c]);
                }
            }
        }

        return dp[m][n];
    }

    void getWoodPrice(vector<vector<int>>& prices, vector<vector<int>>& woodPrices) {
        for (auto& price : prices) {
            woodPrices[price[0]][price[1]] = price[2];
        }
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<vector<int>> prices = { {1,4,2},{2,2,7},{2,1,3} };
    check.checkLongLong(19, o.sellingWood(3, 5, prices));

    prices = { {3,2,10},{1,4,2},{4,1,3} };
    check.checkLongLong(32, o.sellingWood(4, 6, prices));
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
