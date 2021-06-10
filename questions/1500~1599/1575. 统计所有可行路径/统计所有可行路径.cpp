/* 统计所有可行路径.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你一个 互不相同 的整数数组，其中 locations[i] 表示第 i 个城市的位置。同时给你 start，finish 和 fuel 分别表示出发城市、目的地城市和你初始拥有的汽油总量

每一步中，如果你在城市 i ，你可以选择任意一个城市 j ，满足  j != i 且 0 <= j < locations.length ，并移动到城市 j 。从城市 i 移动到 j 消耗的汽油量为 |locations[i] - locations[j]|，|x| 表示 x 的绝对值。

请注意， fuel 任何时刻都 不能 为负，且你 可以 经过任意城市超过一次（包括 start 和 finish ）。

请你返回从 start 到 finish 所有可能路径的数目。

由于答案可能很大， 请将它对 10^9 + 7 取余后返回。

 

示例 1：

输入：locations = [2,3,6,8,4], start = 1, finish = 3, fuel = 5
输出：4
解释：以下为所有可能路径，每一条都用了 5 单位的汽油：
1 -> 3
1 -> 2 -> 3
1 -> 4 -> 3
1 -> 4 -> 2 -> 3
示例 2：

输入：locations = [4,3,1], start = 1, finish = 0, fuel = 6
输出：5
解释：以下为所有可能的路径：
1 -> 0，使用汽油量为 fuel = 1
1 -> 2 -> 0，使用汽油量为 fuel = 5
1 -> 2 -> 1 -> 0，使用汽油量为 fuel = 5
1 -> 0 -> 1 -> 0，使用汽油量为 fuel = 3
1 -> 0 -> 1 -> 0 -> 1 -> 0，使用汽油量为 fuel = 5
示例 3：

输入：locations = [5,2,1], start = 0, finish = 2, fuel = 3
输出：0
解释：没有办法只用 3 单位的汽油从 0 到达 2 。因为最短路径需要 4 单位的汽油。
示例 4 ：

输入：locations = [2,1,5], start = 0, finish = 0, fuel = 3
输出：2
解释：总共有两条可行路径，0 和 0 -> 1 -> 0 。
示例 5：

输入：locations = [1,2,3], start = 0, finish = 2, fuel = 40
输出：615088286
解释：路径总数为 2615088300 。将结果对 10^9 + 7 取余，得到 615088286 。
 

提示：

2 <= locations.length <= 100
1 <= locations[i] <= 10^9
所有 locations 中的整数 互不相同 。
0 <= start, finish < locations.length
1 <= fuel <= 200

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/count-all-possible-routes
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int countRoutes(vector<int>& locations, int start, int finish, int fuel) {
        int i, j, f, size = locations.size(), routes = 0, mod = 1000000007;
        vector<vector<int>> dp(fuel + 1, vector<int>(size, 0));
        dp[fuel][start] = 1;

        for (f = fuel; f >= 0; --f) {
            for (i = 0; i < size; ++i) {
                for (j = 0; j < size; ++j) {
                    if (i == j) {
                        continue;
                    }

                    int cost = abs(locations[i] - locations[j]);
                    if (f + cost <= fuel) {
                        dp[f][i] = (dp[f][i] + dp[f + cost][j]) % mod;
                    }
                }
            }
        }

        for (f = fuel; f >= 0; --f) {
            routes = (routes + dp[f][finish]) % mod;
        }

        return routes;
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<int> locations = { 2,3,6,8,4 };
    check.checkInt(4, o.countRoutes(locations, 1, 3, 5));

    locations = { 4,3,1 };
    check.checkInt(5, o.countRoutes(locations, 1, 0, 6));

    locations = { 5,2,1 };
    check.checkInt(0, o.countRoutes(locations, 0, 2, 3));

    locations = { 2,1,5 };
    check.checkInt(2, o.countRoutes(locations, 0, 0, 3));

    locations = { 1,2,3 };
    check.checkInt(615088286, o.countRoutes(locations, 0, 2, 40));
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
