/* 掷骰子的N种方法.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
这里有 d 个一样的骰子，每个骰子上都有 f 个面，分别标号为 1, 2, ..., f。

我们约定：掷骰子的得到总点数为各骰子面朝上的数字的总和。

如果需要掷出的总点数为 target，请你计算出有多少种不同的组合情况（所有的组合情况总共有 f^d 种），模 10^9 + 7 后返回。

 

示例 1：

输入：d = 1, f = 6, target = 3
输出：1
示例 2：

输入：d = 2, f = 6, target = 7
输出：6
示例 3：

输入：d = 2, f = 5, target = 10
输出：1
示例 4：

输入：d = 1, f = 2, target = 3
输出：0
示例 5：

输入：d = 30, f = 30, target = 500
输出：222616187
 

提示：

1 <= d, f <= 30
1 <= target <= 1000

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/number-of-dice-rolls-with-target-sum
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <algorithm>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int numRollsToTarget(int d, int f, int target) {
        int dice, tar, point, maxPoint = min(f, target), mod = 1000000007;
        vector<vector<int>> dp(d + 1, vector<int>(target + 1, 0));  // dp[dice][tar]表示dice个骰子，sum为tar有多少种方法

        for (tar = 1; tar <= maxPoint; ++tar) {
            dp[1][tar] = 1;  // 一个骰子[1,f]各有一种方法
        }

        for (dice = 2; dice <= d; ++dice) {
            int minTarget = dice, maxTarget = min(target, dice * f);
            for (tar = minTarget; tar <= maxTarget; ++tar) {
                maxPoint = min(f, tar - 1);
                for (point = 1; point <= maxPoint; ++point) {
                    dp[dice][tar] = (dp[dice][tar] + dp[dice - 1][tar - point]) % mod;  // dp[dice][tar]=sum(dp[dice-1][tar-f]...dp[dice-1][tar-1])
                }
            }
        }

        return dp[d][target];
    }
};

int main()
{
    CheckResult check;
    Solution o;

    check.checkInt(1, o.numRollsToTarget(1, 6, 3));
    check.checkInt(6, o.numRollsToTarget(2, 6, 7));
    check.checkInt(3, o.numRollsToTarget(2, 6, 4));
    check.checkInt(1, o.numRollsToTarget(2, 5, 10));
    check.checkInt(0, o.numRollsToTarget(1, 2, 3));
    check.checkInt(6, o.numRollsToTarget(3, 3, 7));
    check.checkInt(222616187, o.numRollsToTarget(30, 30, 500));
    check.checkInt(1, o.numRollsToTarget(30, 30, 900));
    check.checkInt(0, o.numRollsToTarget(30, 30, 1000));
    check.checkInt(1, o.numRollsToTarget(1, 1, 1));
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
