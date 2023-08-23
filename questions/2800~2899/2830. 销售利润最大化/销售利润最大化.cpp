/* 销售利润最大化.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你一个整数 n 表示数轴上的房屋数量，编号从 0 到 n - 1 。

另给你一个二维整数数组 offers ，其中 offers[i] = [starti, endi, goldi] 表示第 i 个买家想要以 goldi 枚金币的价格购买从 starti 到 endi 的所有房屋。

作为一名销售，你需要有策略地选择并销售房屋使自己的收入最大化。

返回你可以赚取的金币的最大数目。

注意 同一所房屋不能卖给不同的买家，并且允许保留一些房屋不进行出售。



示例 1：

输入：n = 5, offers = [[0,0,1],[0,2,2],[1,3,2]]
输出：3
解释：
有 5 所房屋，编号从 0 到 4 ，共有 3 个购买要约。
将位于 [0,0] 范围内的房屋以 1 金币的价格出售给第 1 位买家，并将位于 [1,3] 范围内的房屋以 2 金币的价格出售给第 3 位买家。
可以证明我们最多只能获得 3 枚金币。
示例 2：

输入：n = 5, offers = [[0,0,1],[0,2,10],[1,3,2]]
输出：10
解释：有 5 所房屋，编号从 0 到 4 ，共有 3 个购买要约。
将位于 [0,2] 范围内的房屋以 10 金币的价格出售给第 2 位买家。
可以证明我们最多只能获得 10 枚金币。


提示：

1 <= n <= 105
1 <= offers.length <= 105
offers[i].length == 3
0 <= starti <= endi <= n - 1
1 <= goldi <= 103
*/

#include <iostream>
#include <algorithm>
#include "../check/CheckResult.h"

using namespace std;

bool vectorCompare(const vector<int>& v1, const vector<int>& v2) {
    return v1[1] < v2[1];  // 按照end排序
}

class Solution {
public:
    int maximizeTheProfit(int n, vector<vector<int>>& offers) {
        int size = offers.size(), index = 0;
        vector<int> dp(n + 1, 0);

        sort(offers.begin(), offers.end(), vectorCompare);

        for (int i = 1; i <= n; ++i) {
            dp[i] = dp[i - 1];

            while (index < size && offers[index][1] == i - 1) {
                dp[i] = max(dp[i], dp[offers[index][0]] + offers[index][2]);
                ++index;
            }
        }

        return dp[n];
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<vector<int>> offers = { {0,0,1},{0,2,2},{1,3,2} };
    check.checkInt(3, o.maximizeTheProfit(5, offers));

    offers = { {0,0,1},{0,2,10},{1,3,2} };
    check.checkInt(10, o.maximizeTheProfit(5, offers));
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
