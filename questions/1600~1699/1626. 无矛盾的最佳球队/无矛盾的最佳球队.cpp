/* 无矛盾的最佳球队.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
假设你是球队的经理。对于即将到来的锦标赛，你想组合一支总体得分最高的球队。球队的得分是球队中所有球员的分数 总和 。

然而，球队中的矛盾会限制球员的发挥，所以必须选出一支 没有矛盾 的球队。如果一名年龄较小球员的分数 严格大于 一名年龄较大的球员，则存在矛盾。同龄球员之间不会发生矛盾。

给你两个列表 scores 和 ages，其中每组 scores[i] 和 ages[i] 表示第 i 名球员的分数和年龄。请你返回 所有可能的无矛盾球队中得分最高那支的分数 。

 

示例 1：

输入：scores = [1,3,5,10,15], ages = [1,2,3,4,5]
输出：34
解释：你可以选中所有球员。
示例 2：

输入：scores = [4,5,6,5], ages = [2,1,2,1]
输出：16
解释：最佳的选择是后 3 名球员。注意，你可以选中多个同龄球员。
示例 3：

输入：scores = [1,2,3,5], ages = [8,9,10,1]
输出：6
解释：最佳的选择是前 3 名球员。
 

提示：

1 <= scores.length, ages.length <= 1000
scores.length == ages.length
1 <= scores[i] <= 106
1 <= ages[i] <= 1000

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/best-team-with-no-conflicts
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <algorithm>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int bestTeamScore(vector<int>& scores, vector<int>& ages) {
        int i, j, size = ages.size(), maxScore;

        vector<pair<int, int>> ageScores(size);
        sortAgeScores(scores, ages, ageScores);

        vector<int> dp(size, 0);
        dp[0] = maxScore = ageScores[0].second;

        for (i = 1; i < size; ++i) {
            for (j = 0; j < i; ++j) {
                if (ageScores[j].second <= ageScores[i].second) {
                    dp[i] = max(dp[i], dp[j]);
                }
            }

            dp[i] += ageScores[i].second;
            maxScore = max(maxScore, dp[i]);
        }

        return maxScore;
    }

    void sortAgeScores(vector<int>& scores, vector<int>& ages, vector<pair<int, int>>& ageScores) {
        for (unsigned int i = 0; i < ages.size(); ++i) {
            ageScores[i] = { ages[i], scores[i] };
        }

        sort(ageScores.begin(), ageScores.end());
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<int> scores = { 1,3,5,10,15 };
    vector<int> ages = { 1,2,3,4,5 };
    check.checkInt(34, o.bestTeamScore(scores, ages));

    scores = { 4,5,6,5 };
    ages = { 2,1,2,1 };
    check.checkInt(16, o.bestTeamScore(scores, ages));

    scores = { 1,2,3,5 };
    ages = { 8,9,10,1 };
    check.checkInt(6, o.bestTeamScore(scores, ages));

    scores = { 100,2,3,5 };
    ages = { 1,2,3,4 };
    check.checkInt(100, o.bestTeamScore(scores, ages));
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
