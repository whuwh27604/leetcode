/* 出租车的最大盈利.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
你驾驶出租车行驶在一条有 n 个地点的路上。这 n 个地点从近到远编号为 1 到 n ，你想要从 1 开到 n ，通过接乘客订单盈利。你只能沿着编号递增的方向前进，不能改变方向。

乘客信息用一个下标从 0 开始的二维数组 rides 表示，其中 rides[i] = [starti, endi, tipi] 表示第 i 位乘客需要从地点 starti 前往 endi ，愿意支付 tipi 元的小费。

每一位 你选择接单的乘客 i ，你可以 盈利 endi - starti + tipi 元。你同时 最多 只能接一个订单。

给你 n 和 rides ，请你返回在最优接单方案下，你能盈利 最多 多少元。

注意：你可以在一个地点放下一位乘客，并在同一个地点接上另一位乘客。

 

示例 1：

输入：n = 5, rides = [[2,5,4],[1,5,1]]
输出：7
解释：我们可以接乘客 0 的订单，获得 5 - 2 + 4 = 7 元。
示例 2：

输入：n = 20, rides = [[1,6,1],[3,10,2],[10,12,3],[11,12,2],[12,15,2],[13,18,1]]
输出：20
解释：我们可以接以下乘客的订单：
- 将乘客 1 从地点 3 送往地点 10 ，获得 10 - 3 + 2 = 9 元。
- 将乘客 2 从地点 10 送往地点 12 ，获得 12 - 10 + 3 = 5 元。
- 将乘客 5 从地点 13 送往地点 18 ，获得 18 - 13 + 1 = 6 元。
我们总共获得 9 + 5 + 6 = 20 元。
 

提示：

1 <= n <= 105
1 <= rides.length <= 3 * 104
rides[i].length == 3
1 <= starti < endi <= n
1 <= tipi <= 105

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/maximum-earnings-from-taxi
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <algorithm>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    long long maxTaxiEarnings(int n, vector<vector<int>>& rides) {
        vector<vector<pair<int, int>>> sortedRides(n + 1);
        vector<long long> dp(n + 1, 0);  // dp[i]表示从位置i出发，可以获得的最大收益

        for (auto& ride : rides) {
            sortedRides[ride[0]].push_back({ ride[1], ride[2] });
        }

        for (int i = n - 1; i > 0; --i) {
            long long maxEarnings = dp[i + 1];

            for (auto& p : sortedRides[i]) {
                maxEarnings = max(maxEarnings, dp[p.first] + p.first - i + p.second);
            }

            dp[i] = maxEarnings;
        }

        return dp[1];
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<vector<int>> rides = { {2,5,4},{1,5,1} };
    check.checkLongLong(7, o.maxTaxiEarnings(5, rides));

    rides = { {1,6,1},{3,10,2},{10,12,3},{11,12,2},{12,15,2},{13,18,1} };
    check.checkLongLong(20, o.maxTaxiEarnings(20, rides));
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
