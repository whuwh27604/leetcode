/* 每个人戴不同帽子的方案数.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
总共有 n 个人和 40 种不同的帽子，帽子编号从 1 到 40 。

给你一个整数列表的列表 hats ，其中 hats[i] 是第 i 个人所有喜欢帽子的列表。

请你给每个人安排一顶他喜欢的帽子，确保每个人戴的帽子跟别人都不一样，并返回方案数。

由于答案可能很大，请返回它对 10^9 + 7 取余后的结果。

 

示例 1：

输入：hats = [[3,4],[4,5],[5]]
输出：1
解释：给定条件下只有一种方法选择帽子。
第一个人选择帽子 3，第二个人选择帽子 4，最后一个人选择帽子 5。
示例 2：

输入：hats = [[3,5,1],[3,5]]
输出：4
解释：总共有 4 种安排帽子的方法：
(3,5)，(5,3)，(1,3) 和 (1,5)
示例 3：

输入：hats = [[1,2,3,4],[1,2,3,4],[1,2,3,4],[1,2,3,4]]
输出：24
解释：每个人都可以从编号为 1 到 4 的帽子中选。
(1,2,3,4) 4 个帽子的排列方案数为 24 。
示例 4：

输入：hats = [[1,2,3],[2,3,5,6],[1,3,7,9],[1,8,9],[2,5,7]]
输出：111
 

提示：

n == hats.length
1 <= n <= 10
1 <= hats[i].length <= 40
1 <= hats[i][j] <= 40
hats[i] 包含一个数字互不相同的整数列表。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/number-of-ways-to-wear-different-hats-to-each-other
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int numberWays(vector<vector<int>>& hats) {
        int people, hat, mask, n = hats.size();
        vector<vector<bool>> peopleHats(n, vector<bool>(41, false));
        vector<vector<int>> dp(41, vector<int>((1 << n), 0));
        dp[0][0] = 1;

        for (people = 0; people < n; ++people) {
            for (int hat : hats[people]) {
                peopleHats[people][hat] = true;
            }
        }

        for (hat = 1; hat <= 40; ++hat) {
            for (mask = 0; mask < (1 << n); ++mask) {
                dp[hat][mask] = dp[hat - 1][mask];  // 最后一顶帽子不给任何人

                for (people = 0; people < n; ++people) {
                    int bit = (1 << people);
                    if ((mask & bit) && peopleHats[people][hat]) {  // 最后一顶帽子可以给这个人
                        dp[hat][mask] = (dp[hat][mask] + dp[hat - 1][mask ^ bit]) % 1000000007;
                    }
                }
            }
        }

        return dp[40][(1 << n) - 1];
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<vector<int>> hats = {{3,4},{4,5},{5}};
    check.checkInt(1,o.numberWays(hats));

    hats = {{3,5,1},{3,5}};
    check.checkInt(4,o.numberWays(hats));

    hats = {{1,2,3,4},{1,2,3,4},{1,2,3,4},{1,2,3,4}};
    check.checkInt(24,o.numberWays(hats));

    hats = {{1,2,3},{2,3,5,6},{1,3,7,9},{1,8,9},{2,5,7}};
    check.checkInt(111,o.numberWays(hats));

    hats = { {1,2,4,6,7,8,9,11,12,13,14,15,16,18,19,20,23,24,25},{2,5,16},{1,4,5,6,7,8,9,12,15,16,17,19,21,22,24,25},{1,3,6,8,11,12,13,16,17,19,20,22,24,25},{11,12,14,16,18,24},{2,3,4,5,7,8,13,14,15,17,18,21,24},{1,2,6,7,10,11,13,14,16,18,19,21,23},{1,3,6,7,8,9,10,11,12,14,15,16,18,20,21,22,23,24,25},{2,3,4,6,7,10,12,14,15,16,17,21,22,23,24,25} };
    check.checkInt(778256459, o.numberWays(hats));
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
