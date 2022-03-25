/* 吃掉 N 个橘子的最少天数.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
厨房里总共有 n 个橘子，你决定每一天选择如下方式之一吃这些橘子：

吃掉一个橘子。
如果剩余橘子数 n 能被 2 整除，那么你可以吃掉 n/2 个橘子。
如果剩余橘子数 n 能被 3 整除，那么你可以吃掉 2*(n/3) 个橘子。
每天你只能从以上 3 种方案中选择一种方案。

请你返回吃掉所有 n 个橘子的最少天数。

 

示例 1：

输入：n = 10
输出：4
解释：你总共有 10 个橘子。
第 1 天：吃 1 个橘子，剩余橘子数 10 - 1 = 9。
第 2 天：吃 6 个橘子，剩余橘子数 9 - 2*(9/3) = 9 - 6 = 3。（9 可以被 3 整除）
第 3 天：吃 2 个橘子，剩余橘子数 3 - 2*(3/3) = 3 - 2 = 1。
第 4 天：吃掉最后 1 个橘子，剩余橘子数 1 - 1 = 0。
你需要至少 4 天吃掉 10 个橘子。
示例 2：

输入：n = 6
输出：3
解释：你总共有 6 个橘子。
第 1 天：吃 3 个橘子，剩余橘子数 6 - 6/2 = 6 - 3 = 3。（6 可以被 2 整除）
第 2 天：吃 2 个橘子，剩余橘子数 3 - 2*(3/3) = 3 - 2 = 1。（3 可以被 3 整除）
第 3 天：吃掉剩余 1 个橘子，剩余橘子数 1 - 1 = 0。
你至少需要 3 天吃掉 6 个橘子。
示例 3：

输入：n = 1
输出：1
示例 4：

输入：n = 56
输出：6
 

提示：

1 <= n <= 2*10^9

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/minimum-number-of-days-to-eat-n-oranges
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <unordered_map>
#include <algorithm>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int minDays(int n) {
        // 可以证明n / 2、n / 3操作总是比n - 1操作更优
        unordered_map<int, int> memo;

        return getMinDays(n, memo);
    }

    int getMinDays(int n, unordered_map<int, int>& memo) {
        if (n <= 1) {
            return n;
        }

        if (memo.count(n) != 0) {
            return memo[n];
        }

        return memo[n] = min(n % 2 + 1 + getMinDays(n / 2, memo), n % 3 + 1 + getMinDays(n / 3, memo));
    }
};

int main()
{
    CheckResult check;
    Solution o;

    check.checkInt(6, o.minDays(56));
    check.checkInt(1, o.minDays(1));
    check.checkInt(3, o.minDays(6));
    check.checkInt(4, o.minDays(10));
    check.checkInt(32, o.minDays(84806671));
    check.checkInt(31, o.minDays(662944437));
    check.checkInt(30, o.minDays(42403335));
    check.checkInt(30, o.minDays(14134445));
    check.checkInt(32, o.minDays(2000000000));
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
