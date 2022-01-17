/* 解决智力问题.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你一个下标从 0 开始的二维整数数组 questions ，其中 questions[i] = [pointsi, brainpoweri] 。

这个数组表示一场考试里的一系列题目，你需要 按顺序 （也就是从问题 0 开始依次解决），针对每个问题选择 解决 或者 跳过 操作。解决问题 i 将让你 获得  pointsi 的分数，但是你将 无法 解决接下来的 brainpoweri 个问题（即只能跳过接下来的 brainpoweri 个问题）。如果你跳过问题 i ，你可以对下一个问题决定使用哪种操作。

比方说，给你 questions = [[3, 2], [4, 3], [4, 4], [2, 5]] ：
如果问题 0 被解决了， 那么你可以获得 3 分，但你不能解决问题 1 和 2 。
如果你跳过问题 0 ，且解决问题 1 ，你将获得 4 分但是不能解决问题 2 和 3 。
请你返回这场考试里你能获得的 最高 分数。

 

示例 1：

输入：questions = [[3,2],[4,3],[4,4],[2,5]]
输出：5
解释：解决问题 0 和 3 得到最高分。
- 解决问题 0 ：获得 3 分，但接下来 2 个问题都不能解决。
- 不能解决问题 1 和 2
- 解决问题 3 ：获得 2 分
总得分为：3 + 2 = 5 。没有别的办法获得 5 分或者多于 5 分。
示例 2：

输入：questions = [[1,1],[2,2],[3,3],[4,4],[5,5]]
输出：7
解释：解决问题 1 和 4 得到最高分。
- 跳过问题 0
- 解决问题 1 ：获得 2 分，但接下来 2 个问题都不能解决。
- 不能解决问题 2 和 3
- 解决问题 4 ：获得 5 分
总得分为：2 + 5 = 7 。没有别的办法获得 7 分或者多于 7 分。
 

提示：

1 <= questions.length <= 105
questions[i].length == 2
1 <= pointsi, brainpoweri <= 105

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/solving-questions-with-brainpower
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <algorithm>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    long long mostPoints(vector<vector<int>>& questions) {
        int i, size = questions.size();
        vector<long long> dp(size, 0);
        dp[size - 1] = questions[size - 1][0];

        for (i = size - 2; i >= 0; --i) {
            int next = i + questions[i][1] + 1;
            dp[i] = max(questions[i][0] + (next >= size ? 0 : dp[next]), dp[i + 1]);
        }

        return dp[0];
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<vector<int>> questions = { {3,2},{4,3},{4,4},{2,5} };
    check.checkLongLong(5, o.mostPoints(questions));

    questions = { {1,1},{2,2},{3,3},{4,4},{5,5} };
    check.checkLongLong(7, o.mostPoints(questions));

    questions = { {1,1} };
    check.checkLongLong(1, o.mostPoints(questions));
    
    questions = { {21,5},{92,3},{74,2},{39,4},{58,2},{5,5},{49,4},{65,3} };
    check.checkLongLong(157, o.mostPoints(questions));

    questions = { {21,2},{1,2},{12,5},{7,2},{35,3},{32,2},{80,2},{91,5},{92,3},{27,3},{19,1},{37,3},{85,2},{33,4},{25,1},{91,4},{44,3},{93,3},{65,4},{82,3},{85,5},{81,3},{29,2},{25,1},{74,2},{58,1},{85,1},{84,2},{27,2},{47,5},{48,4},{3,2},{44,3},{60,5},{19,2},{9,4},{29,5},{15,3},{1,3},{60,2},{63,3},{79,3},{19,1},{7,1},{35,1},{55,4},{1,4},{41,1},{58,5} };
    check.checkLongLong(781, o.mostPoints(questions));
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
