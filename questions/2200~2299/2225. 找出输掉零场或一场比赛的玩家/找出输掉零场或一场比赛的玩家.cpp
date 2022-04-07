/* 找出输掉零场或一场比赛的玩家.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你一个整数数组 matches 其中 matches[i] = [winneri, loseri] 表示在一场比赛中 winneri 击败了 loseri 。

返回一个长度为 2 的列表 answer ：

answer[0] 是所有 没有 输掉任何比赛的玩家列表。
answer[1] 是所有恰好输掉 一场 比赛的玩家列表。
两个列表中的值都应该按 递增 顺序返回。

注意：

只考虑那些参与 至少一场 比赛的玩家。
生成的测试用例保证 不存在 两场比赛结果 相同 。
 

示例 1：

输入：matches = [[1,3],[2,3],[3,6],[5,6],[5,7],[4,5],[4,8],[4,9],[10,4],[10,9]]
输出：[[1,2,10],[4,5,7,8]]
解释：
玩家 1、2 和 10 都没有输掉任何比赛。
玩家 4、5、7 和 8 每个都输掉一场比赛。
玩家 3、6 和 9 每个都输掉两场比赛。
因此，answer[0] = [1,2,10] 和 answer[1] = [4,5,7,8] 。
示例 2：

输入：matches = [[2,3],[1,3],[5,4],[6,4]]
输出：[[1,2,5,6],[]]
解释：
玩家 1、2、5 和 6 都没有输掉任何比赛。
玩家 3 和 4 每个都输掉两场比赛。
因此，answer[0] = [1,2,5,6] 和 answer[1] = [] 。
 

提示：

1 <= matches.length <= 105
matches[i].length == 2
1 <= winneri, loseri <= 105
winneri != loseri
所有 matches[i] 互不相同

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/find-players-with-zero-or-one-losses
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <unordered_map>
#include <algorithm>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        unordered_map<int, int> winners, losers;
        vector<vector<int>> ans(2);

        for (auto& match : matches) {
            ++winners[match[0]];
            ++losers[match[1]];
        }

        for (auto& winner : winners) {
            if (losers.count(winner.first) == 0) {
                ans[0].push_back(winner.first);
            }
        }

        for (auto& loser : losers) {
            if (loser.second == 1) {
                ans[1].push_back(loser.first);
            }
        }

        sort(ans[0].begin(), ans[0].end());
        sort(ans[1].begin(), ans[1].end());

        return ans;
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<vector<int>> matches = {{1,3},{2,3},{3,6},{5,6},{5,7},{4,5},{4,8},{4,9},{10,4},{10,9}};
    vector<vector<int>> actual = o.findWinners(matches);
    vector<vector<int>> expected = {{1,2,10},{4,5,7,8}};
    check.checkIntVectorVector(expected,actual);

    matches = {{2,3},{1,3},{5,4},{6,4}};
    actual = o.findWinners(matches);
    expected = {{1,2,5,6},{}};
    check.checkIntVectorVector(expected,actual);
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
