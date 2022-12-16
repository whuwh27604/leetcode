/* 矩阵查询可获得的最大分数.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你一个大小为 m x n 的整数矩阵 grid 和一个大小为 k 的数组 queries 。

找出一个大小为 k 的数组 answer ，且满足对于每个整数 queres[i] ，你从矩阵 左上角 单元格开始，重复以下过程：

如果 queries[i] 严格 大于你当前所处位置单元格，如果该单元格是第一次访问，则获得 1 分，并且你可以移动到所有 4 个方向（上、下、左、右）上任一 相邻 单元格。
否则，你不能获得任何分，并且结束这一过程。
在过程结束后，answer[i] 是你可以获得的最大分数。注意，对于每个查询，你可以访问同一个单元格 多次 。

返回结果数组 answer 。



示例 1：


输入：grid = [[1,2,3],[2,5,7],[3,5,1]], queries = [5,6,2]
输出：[5,8,1]
解释：上图展示了每个查询中访问并获得分数的单元格。
示例 2：


输入：grid = [[5,2,1],[1,1,2]], queries = [3]
输出：[0]
解释：无法获得分数，因为左上角单元格的值大于等于 3 。


提示：

m == grid.length
n == grid[i].length
2 <= m, n <= 1000
4 <= m * n <= 105
k == queries.length
1 <= k <= 104
1 <= grid[i][j], queries[i] <= 106
*/

#include <iostream>
#include <algorithm>
#include <set>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    vector<int> maxPoints(vector<vector<int>>& grid, vector<int>& queries) {
        int row = grid.size(), column = grid[0].size(), k = queries.size(), count = 0;
        vector<int> ans(k);
        int dr[4] = { 0,1,0,-1 }, dc[4] = { 1,0,-1,0 };

        vector<pair<int, int>> sortedQueries;
        sortQueries(queries, sortedQueries);

        set<long long> nodes;
        nodes.insert((long long)grid[0][0] << 32);
        grid[0][0] = 0;

        for (auto& query : sortedQueries) {
            while (!nodes.empty() && (*nodes.begin() >> 32) < query.first) {
                ++count;
                int r = (int)(*nodes.begin()) >> 16, c = (int)(*nodes.begin()) & 0xffff;
                nodes.erase(nodes.begin());

                for (int i = 0; i < 4; ++i) {
                    int nr = r + dr[i], nc = c + dc[i];
                    if (nr >= 0 && nr < row && nc >= 0 && nc < column && grid[nr][nc] != 0) {
                        nodes.insert(((long long)grid[nr][nc] << 32) | ((long long)nr << 16) | nc);
                        grid[nr][nc] = 0;
                    }
                }
            }

            ans[query.second] = count;
        }

        return ans;
    }

    void sortQueries(vector<int>& queries, vector<pair<int, int>>& sortedQueries) {
        int index = 0;

        for (int query : queries) {
            sortedQueries.push_back({ query,index++ });
        }

        sort(sortedQueries.begin(), sortedQueries.end());
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<vector<int>> grid = { {1,2,3},{2,5,7},{3,5,1} };
    vector<int> queries = { 5,6,2 };
    vector<int> actual = o.maxPoints(grid, queries);
    vector<int> expected = { 5,8,1 };
    check.checkIntVector(expected, actual);

    grid = { {5,2,1},{1,1,2} };
    queries = { 3 };
    actual = o.maxPoints(grid, queries);
    expected = { 0 };
    check.checkIntVector(expected, actual);

    grid = { {5,2,1},{1,1,2},{1,2,3},{2,5,7},{3,5,1},{5,2,1},{1,1,2},{1,2,3},{2,5,7},{3,5,1} };
    queries = { 8,7,6,5,4,3,2,1 };
    actual = o.maxPoints(grid, queries);
    expected = { 30,28,28,0,0,0,0,0 };
    check.checkIntVector(expected, actual);

    grid = { {1,2,1},{1,1,2},{1,2,3},{2,5,7},{3,5,1},{5,2,1},{1,1,2},{1,2,3},{2,5,7},{3,5,1} };
    queries = { 8,7,6,5,4,3,2,1 };
    actual = o.maxPoints(grid, queries);
    expected = { 30,28,28,11,11,9,4,0 };
    check.checkIntVector(expected, actual);
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
