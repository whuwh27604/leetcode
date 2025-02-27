/* 提取至多 K 个元素的最大总和.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你一个大小为 n x m 的二维矩阵 grid ，以及一个长度为 n 的整数数组 limits ，和一个整数 k 。你的目标是从矩阵 grid 中提取出 至多 k 个元素，并计算这些元素的最大总和，提取时需满足以下限制：

从 grid 的第 i 行提取的元素数量不超过 limits[i] 。

返回最大总和。



示例 1：

输入：grid = [[1,2],[3,4]], limits = [1,2], k = 2

输出：7

解释：

从第 2 行提取至多 2 个元素，取出 4 和 3 。
至多提取 2 个元素时的最大总和 4 + 3 = 7 。
示例 2：

输入：grid = [[5,3,7],[8,2,6]], limits = [2,2], k = 3

输出：21

解释：

从第 1 行提取至多 2 个元素，取出 7 。
从第 2 行提取至多 2 个元素，取出 8 和 6 。
至多提取 3 个元素时的最大总和 7 + 8 + 6 = 21 。


提示：

n == grid.length == limits.length
m == grid[i].length
1 <= n, m <= 500
0 <= grid[i][j] <= 105
0 <= limits[i] <= m
0 <= k <= min(n * m, sum(limits))
*/

#include <iostream>
#include <algorithm>
#include <queue>
#include "../check/CheckResult.h"

using namespace std;

class Node {
public:
    int v;
    int r;
    int c;

    Node() : v(0), r(0), c(0) {}
    Node(int v_, int r_, int c_) : v(v_), r(r_), c(c_) {}

    bool operator<(const Node& o) const {
        return v < o.v;
    }
};

class Solution {
public:
    long long maxSum(vector<vector<int>>& grid, vector<int>& limits, int k) {
        int n = (int)grid.size(), m = (int)grid[0].size();
        priority_queue<Node> nodes;
        long long sum = 0;

        for (int i = 0; i < n; ++i) {
            sort(grid[i].begin(), grid[i].end());

            if (limits[i] != 0) {
                nodes.push(Node(grid[i][m - 1], i, m - 1));
            }
        }

        for (int i = 0; i < k; ++i) {
            int val = nodes.top().v, r = nodes.top().r, c = nodes.top().c;
            nodes.pop();
            sum += val;

            if (--limits[r] != 0) {
                nodes.push(Node(grid[r][c - 1], r, c - 1));
            }
        }

        return sum;
    }
};

int main()
{
    Solution o;
    CheckResult check;

    vector<vector<int>> grid = { {1,2},{3,4} };
    vector<int> limits = { 1,2 };
    check.checkLongLong(7, o.maxSum(grid, limits, 2));

    grid = { {5,3,7},{8,2,6} };
    limits = { 2,2 };
    check.checkLongLong(21, o.maxSum(grid, limits, 3));
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
