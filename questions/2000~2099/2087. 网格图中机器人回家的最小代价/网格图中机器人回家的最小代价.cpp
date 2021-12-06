﻿/* 网格图中机器人回家的最小代价.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你一个 m x n 的网格图，其中 (0, 0) 是最左上角的格子，(m - 1, n - 1) 是最右下角的格子。给你一个整数数组 startPos ，startPos = [startrow, startcol] 表示 初始 有一个 机器人 在格子 (startrow, startcol) 处。同时给你一个整数数组 homePos ，homePos = [homerow, homecol] 表示机器人的 家 在格子 (homerow, homecol) 处。

机器人需要回家。每一步它可以往四个方向移动：上，下，左，右，同时机器人不能移出边界。每一步移动都有一定代价。再给你两个下标从 0 开始的额整数数组：长度为 m 的数组 rowCosts  和长度为 n 的数组 colCosts 。

如果机器人往 上 或者往 下 移动到第 r 行 的格子，那么代价为 rowCosts[r] 。
如果机器人往 左 或者往 右 移动到第 c 列 的格子，那么代价为 colCosts[c] 。
请你返回机器人回家需要的 最小总代价 。

 

示例 1：



输入：startPos = [1, 0], homePos = [2, 3], rowCosts = [5, 4, 3], colCosts = [8, 2, 6, 7]
输出：18
解释：一个最优路径为：
从 (1, 0) 开始
-> 往下走到 (2, 0) 。代价为 rowCosts[2] = 3 。
-> 往右走到 (2, 1) 。代价为 colCosts[1] = 2 。
-> 往右走到 (2, 2) 。代价为 colCosts[2] = 6 。
-> 往右走到 (2, 3) 。代价为 colCosts[3] = 7 。
总代价为 3 + 2 + 6 + 7 = 18
示例 2：

输入：startPos = [0, 0], homePos = [0, 0], rowCosts = [5], colCosts = [26]
输出：0
解释：机器人已经在家了，所以不需要移动。总代价为 0 。
 

提示：

m == rowCosts.length
n == colCosts.length
1 <= m, n <= 105
0 <= rowCosts[r], colCosts[c] <= 104
startPos.length == 2
homePos.length == 2
0 <= startrow, homerow < m
0 <= startcol, homecol < n

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/minimum-cost-homecoming-of-a-robot-in-a-grid
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <algorithm>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int minCost(vector<int>& startPos, vector<int>& homePos, vector<int>& rowCosts, vector<int>& colCosts) {
        return getCost(startPos[0], homePos[0], rowCosts) + getCost(startPos[1], homePos[1], colCosts);
    }

    int getCost(int start, int end, vector<int>& costs) {
        int i, cost = 0;

        if (start == end) {
            return 0;
        }
        else if (start < end) {
            for (i = start + 1; i <= end; ++i) {
                cost += costs[i];
            }
        }
        else {
            for (i = start - 1; i >= end; --i) {
                cost += costs[i];
            }
        }

        return cost;
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<int> startPos = { 1,0 };
    vector<int> homePos = { 2,3 };
    vector<int> rowCosts = { 5,4,3 };
    vector<int> colCosts = { 8,2,6,7 };
    check.checkInt(18, o.minCost(startPos, homePos, rowCosts, colCosts));

    startPos = { 0,0 };
    homePos = { 0,0 };
    rowCosts = { 5 };
    colCosts = { 26 };
    check.checkInt(0, o.minCost(startPos, homePos, rowCosts, colCosts));

    startPos = { 5,5 };
    homePos = { 5,2 };
    rowCosts = { 7,1,3,3,5,3,22,10,23 };
    colCosts = { 5,5,6,2,0,16 };
    check.checkInt(8, o.minCost(startPos, homePos, rowCosts, colCosts));
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
