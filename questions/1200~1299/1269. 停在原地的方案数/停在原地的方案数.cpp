/* 停在原地的方案数.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
有一个长度为 arrLen 的数组，开始有一个指针在索引 0 处。

每一步操作中，你可以将指针向左或向右移动 1 步，或者停在原地（指针不能被移动到数组范围外）。

给你两个整数 steps 和 arrLen ，请你计算并返回：在恰好执行 steps 次操作以后，指针仍然指向索引 0 处的方案数。

由于答案可能会很大，请返回方案数 模 10^9 + 7 后的结果。

 

示例 1：

输入：steps = 3, arrLen = 2
输出：4
解释：3 步后，总共有 4 种不同的方法可以停在索引 0 处。
向右，向左，不动
不动，向右，向左
向右，不动，向左
不动，不动，不动
示例  2：

输入：steps = 2, arrLen = 4
输出：2
解释：2 步后，总共有 2 种不同的方法可以停在索引 0 处。
向右，向左
不动，不动
示例 3：

输入：steps = 4, arrLen = 2
输出：8
 

提示：

1 <= steps <= 500
1 <= arrLen <= 10^6

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/number-of-ways-to-stay-in-the-same-place-after-some-steps
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <algorithm>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int numWays(int steps, int arrLen) {
        if (arrLen == 1) {
            return 1;
        }

        int i, size = min(steps + 1, arrLen), mod = 1000000007;
        vector<long long> ways(size, 0);
        ways[0] = ways[1] = 1;

        for (int step = 2; step <= steps; ++step) {
            vector<long long> tmp(size, 0);
            tmp[0] = (ways[0] + ways[1]) % mod;

            for (i = 1; i < size - 1; ++i) {
                tmp[i] = (ways[i - 1] + ways[i] + ways[i + 1]) % mod;
            }

            tmp[i] = (ways[i - 1] + ways[i]) % mod;
            ways = tmp;
        }

        return (int)ways[0];
    }
};

int main()
{
    CheckResult check;
    Solution o;

    check.checkInt(4, o.numWays(3, 2));
    check.checkInt(2, o.numWays(2, 4));
    check.checkInt(8, o.numWays(4, 2));
    check.checkInt(1, o.numWays(3, 1));
    check.checkInt(21, o.numWays(5, 1000000));
    check.checkInt(1, o.numWays(1, 3));
    check.checkInt(310572, o.numWays(15, 15));
    check.checkInt(483475137, o.numWays(438, 315977));
    check.checkInt(459871446, o.numWays(500, 100));
    check.checkInt(374847123, o.numWays(500, 1000000));
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
