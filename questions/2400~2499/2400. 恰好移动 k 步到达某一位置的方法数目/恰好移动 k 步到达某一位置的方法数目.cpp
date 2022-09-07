/* 恰好移动 k 步到达某一位置的方法数目.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你两个 正 整数 startPos 和 endPos 。最初，你站在 无限 数轴上位置 startPos 处。在一步移动中，你可以向左或者向右移动一个位置。

给你一个正整数 k ，返回从 startPos 出发、恰好 移动 k 步并到达 endPos 的 不同 方法数目。由于答案可能会很大，返回对 109 + 7 取余 的结果。

如果所执行移动的顺序不完全相同，则认为两种方法不同。

注意：数轴包含负整数。

 

示例 1：

输入：startPos = 1, endPos = 2, k = 3
输出：3
解释：存在 3 种从 1 到 2 且恰好移动 3 步的方法：
- 1 -> 2 -> 3 -> 2.
- 1 -> 2 -> 1 -> 2.
- 1 -> 0 -> 1 -> 2.
可以证明不存在其他方法，所以返回 3 。
示例 2：

输入：startPos = 2, endPos = 5, k = 10
输出：0
解释：不存在从 2 到 5 且恰好移动 10 步的方法。
 

提示：

1 <= startPos, endPos, k <= 1000

来源：力扣（LeetCode）
链接：https://leetcode.cn/problems/number-of-ways-to-reach-a-position-after-exactly-k-steps
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int numberOfWays(int startPos, int endPos, int k) {
        if (endPos > startPos + k || endPos < startPos - k) {
            return 0;
        }

        vector<vector<int>> dp(k + 1, vector<int>(2 * k + 3, 0));
        dp[0][k + 1] = 1;

        for (int step = 1; step <= k; ++step) {
            for (int pos = 1; pos < 2 * k + 2; ++pos) {
                dp[step][pos] = (dp[step - 1][pos - 1] + dp[step - 1][pos + 1]) % 1000000007;
            }
        }

        return dp[k][k + 1 + endPos - startPos];
    }
};

int main()
{
    CheckResult check;
    Solution o;

    check.checkInt(3, o.numberOfWays(1, 2, 3));
    check.checkInt(0, o.numberOfWays(2, 5, 10));
    check.checkInt(330642053, o.numberOfWays(499, 891, 1000));
    check.checkInt(934081896, o.numberOfWays(989, 1000, 99));
    check.checkInt(934081896, o.numberOfWays(1000, 989, 99));
    check.checkInt(0, o.numberOfWays(1, 5, 3));
    check.checkInt(1, o.numberOfWays(1, 4, 3));
    check.checkInt(0, o.numberOfWays(5, 1, 3));
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
