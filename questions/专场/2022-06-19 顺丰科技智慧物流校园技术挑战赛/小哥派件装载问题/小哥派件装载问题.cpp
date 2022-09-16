/* 小哥派件装载问题.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
问题

快递小哥每天都需要揽件并骑电瓶车派送快递，假设电瓶车快递箱容量为V，小哥需要派送n个快递，每个快递都有一定的体积大小。
要求在需要派送的n个快递中，任取若干个快递装放入快递箱，不能溢出，使快递箱的剩余空间最小。

输入：

n个快递的体积数组:N[]，
电瓶车快递箱容量:V
返回：

尽量装满快递后，快递箱剩余的最小容量
示例1

输入：N = [8, 1, 12, 7, 9, 7], V = 11
输出：1
解释：快递箱容量V为11，物品体积数组N为[8, 1, 12, 7, 9, 7],最优解为取体积为
1的快递和体积为9的快递,即快递箱剩余最小空间为 11-(1+9)=1

示例2

输入：N = [8, 2, 12, 7, 9, 7], V = 11
输出：0
解释：11-(2+9) = 0

示例3

输入：N = [8, 2, 12, 7, 9, 7], V = 100
输出：55
解释：100-(8+2+12+7+9+7) = 55

示例4

输入：N = [8, 19, 18,23,16,20], V = 5
输出：5
解释：由于快递箱不能溢出，没有体积小于5的快递，所以快递箱剩余最小空间为5

提示

0 < N.length ≤ 30
0 < N[i] < 2000
V为整数：0 ≤ V ≤ 2000
*/

#include <iostream>
#include <algorithm>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int minRemainingSpace(vector<int>& N, int V) {
        int i, j, size = N.size();
        vector<vector<int>> dp(size, vector<int>(V + 1, 0));

        for (j = N[0]; j <= V; ++j) {
            dp[0][j] = N[0];
        }

        for (i = 1; i < size; ++i) {
            for (j = 0; j <= V; ++j) {
                dp[i][j] = dp[i - 1][j];  // 不选N[i]

                if (j >= N[i]) {
                    dp[i][j] = max(dp[i][j], dp[i - 1][j - N[i]] + N[i]);  // 选择N[i]，那么占用了N[i]的空间，还剩j - N[i]
                }
            }
        }

        return V - dp[size - 1][V];
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<int> N = { 8,1,12,7,9,7 };
    check.checkInt(1, o.minRemainingSpace(N, 11));

    N = { 8,2,12,7,9,7 };
    check.checkInt(0, o.minRemainingSpace(N, 11));

    N = { 8,2,12,7,9,7 };
    check.checkInt(55, o.minRemainingSpace(N, 100));

    N = { 8,19,18,23,16,20 };
    check.checkInt(5, o.minRemainingSpace(N, 5));

    N = { 1,2,3 };
    check.checkInt(0, o.minRemainingSpace(N, 0));
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
