/* 价格范围内最高排名的 K 样物品.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你一个下标从 0 开始的二维整数数组 grid ，它的大小为 m x n ，表示一个商店中物品的分布图。数组中的整数含义为：

0 表示无法穿越的一堵墙。
1 表示可以自由通过的一个空格子。
所有其他正整数表示该格子内的一样物品的价格。你可以自由经过这些格子。
从一个格子走到上下左右相邻格子花费 1 步。

同时给你一个整数数组 pricing 和 start ，其中 pricing = [low, high] 且 start = [row, col] ，表示你开始位置为 (row, col) ，同时你只对物品价格在 闭区间 [low, high] 之内的物品感兴趣。同时给你一个整数 k 。

你想知道给定范围 内 且 排名最高 的 k 件物品的 位置 。排名按照优先级从高到低的以下规则制定：

距离：定义为从 start 到一件物品的最短路径需要的步数（较近 距离的排名更高）。
价格：较低 价格的物品有更高优先级，但只考虑在给定范围之内的价格。
行坐标：较小 行坐标的有更高优先级。
列坐标：较小 列坐标的有更高优先级。
请你返回给定价格内排名最高的 k 件物品的坐标，将它们按照排名排序后返回。如果给定价格内少于 k 件物品，那么请将它们的坐标 全部 返回。

 

示例 1：



输入：grid = [[1,2,0,1],[1,3,0,1],[0,2,5,1]], pricing = [2,5], start = [0,0], k = 3
输出：[[0,1],[1,1],[2,1]]
解释：起点为 (0,0) 。
价格范围为 [2,5] ，我们可以选择的物品坐标为 (0,1)，(1,1)，(2,1) 和 (2,2) 。
这些物品的排名为：
- (0,1) 距离为 1
- (1,1) 距离为 2
- (2,1) 距离为 3
- (2,2) 距离为 4
所以，给定价格范围内排名最高的 3 件物品的坐标为 (0,1)，(1,1) 和 (2,1) 。
示例 2：



输入：grid = [[1,2,0,1],[1,3,3,1],[0,2,5,1]], pricing = [2,3], start = [2,3], k = 2
输出：[[2,1],[1,2]]
解释：起点为 (2,3) 。
价格范围为 [2,3] ，我们可以选择的物品坐标为 (0,1)，(1,1)，(1,2) 和 (2,1) 。
这些物品的排名为：
- (2,1) 距离为 2 ，价格为 2
- (1,2) 距离为 2 ，价格为 3
- (1,1) 距离为 3
- (0,1) 距离为 4
所以，给定价格范围内排名最高的 2 件物品的坐标为 (2,1) 和 (1,2) 。
示例 3：



输入：grid = [[1,1,1],[0,0,1],[2,3,4]], pricing = [2,3], start = [0,0], k = 3
输出：[[2,1],[2,0]]
解释：起点为 (0,0) 。
价格范围为 [2,3] ，我们可以选择的物品坐标为 (2,0) 和 (2,1) 。
这些物品的排名为：
- (2,1) 距离为 5
- (2,0) 距离为 6
所以，给定价格范围内排名最高的 2 件物品的坐标为 (2,1) 和 (2,0) 。
注意，k = 3 但给定价格范围内只有 2 件物品。
 

提示：

m == grid.length
n == grid[i].length
1 <= m, n <= 105
1 <= m * n <= 105
0 <= grid[i][j] <= 105
pricing.length == 2
2 <= low <= high <= 105
start.length == 2
0 <= row <= m - 1
0 <= col <= n - 1
grid[row][col] > 0
1 <= k <= m * n

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/k-highest-ranked-items-within-a-price-range
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <queue>
#include "../check/CheckResult.h"

using namespace std;

class Item {
public:
    int distance;
    int price;
    int row;
    int column;

    Item(int _dis, int _price, int _r, int _c) : distance(_dis), price(_price), row(_r), column(_c) {}

    bool operator<(const Item& o) const {
        if (distance != o.distance) {
            return distance > o.distance;
        }

        if (price != o.price) {
            return price > o.price;
        }

        if (row != o.row) {
            return row > o.row;
        }

        return column > o.column;
    }
};

class Solution {
public:
    vector<vector<int>> highestRankedKItems(vector<vector<int>>& grid, vector<int>& pricing, vector<int>& start, int k) {
        int row = grid.size(), column = grid[0].size(), r = start[0], c = start[1], low = pricing[0], high = pricing[1], distance = 0;
        int dr[4] = { 0,1,0,-1 }, dc[4] = { 1,0,-1,0 };
        vector<vector<int>> ans;
        priority_queue<Item> bfs;

        bfs.push(Item(0, grid[r][c], r, c));
        grid[r][c] = -grid[r][c];

        while (!bfs.empty()) {
            int i, size = bfs.size();
            ++distance;

            for (i = 0; i < size; ++i) {
                Item item = bfs.top();
                bfs.pop();

                if (item.price >= low && item.price <= high) {
                    ans.push_back({ item.row,item.column });

                    if (--k == 0) {
                        return ans;
                    }
                }

                for (int j = 0; j < 4; ++j) {
                    int nr = item.row + dr[j], nc = item.column + dc[j];

                    if (nr >= 0 && nr < row && nc >= 0 && nc < column && grid[nr][nc] > 0) {
                        bfs.push(Item(distance, grid[nr][nc], nr, nc));
                        grid[nr][nc] = -grid[nr][nc];
                    }
                }
            }
        }

        return ans;
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<vector<int>> grid = { {1,2,0,1},{1,3,0,1},{0,2,5,1} };
    vector<int> pricing = { 2,5 };
    vector<int> start = { 0,0 };
    vector<vector<int>> actual = o.highestRankedKItems(grid, pricing, start, 3);
    vector<vector<int>> expected = { {0,1},{1,1},{2,1} };
    check.checkIntVectorVector(expected, actual);

    grid = { {1,2,0,1},{1,3,3,1},{0,2,5,1} };
    pricing = { 2,3 };
    start = { 2,3 };
    actual = o.highestRankedKItems(grid, pricing, start, 2);
    expected = { {2,1},{1,2} };
    check.checkIntVectorVector(expected, actual);

    grid = { {1,1,1},{0,0,1},{2,3,4} };
    pricing = { 2,3 };
    start = { 0,0 };
    actual = o.highestRankedKItems(grid, pricing, start, 3);
    expected = { {2,1},{2,0} };
    check.checkIntVectorVector(expected, actual);

    grid = { {1} };
    pricing = { 2,3 };
    start = { 0,0 };
    actual = o.highestRankedKItems(grid, pricing, start, 3);
    expected = {  };
    check.checkIntVectorVector(expected, actual);

    grid = { {2} };
    pricing = { 2,3 };
    start = { 0,0 };
    actual = o.highestRankedKItems(grid, pricing, start, 3);
    expected = { {0,0} };
    check.checkIntVectorVector(expected, actual);
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
