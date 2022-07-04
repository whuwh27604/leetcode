/* 网格图中递增路径的数目.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你一个 m x n 的整数网格图 grid ，你可以从一个格子移动到 4 个方向相邻的任意一个格子。

请你返回在网格图中从 任意 格子出发，达到 任意 格子，且路径中的数字是 严格递增 的路径数目。由于答案可能会很大，请将结果对 109 + 7 取余 后返回。

如果两条路径中访问过的格子不是完全相同的，那么它们视为两条不同的路径。

 

示例 1：



输入：grid = [[1,1],[3,4]]
输出：8
解释：严格递增路径包括：
- 长度为 1 的路径：[1]，[1]，[3]，[4] 。
- 长度为 2 的路径：[1 -> 3]，[1 -> 4]，[3 -> 4] 。
- 长度为 3 的路径：[1 -> 3 -> 4] 。
路径数目为 4 + 3 + 1 = 8 。
示例 2：

输入：grid = [[1],[2]]
输出：3
解释：严格递增路径包括：
- 长度为 1 的路径：[1]，[2] 。
- 长度为 2 的路径：[1 -> 2] 。
路径数目为 2 + 1 = 3 。
 

提示：

m == grid.length
n == grid[i].length
1 <= m, n <= 1000
1 <= m * n <= 105
1 <= grid[i][j] <= 105

来源：力扣（LeetCode）
链接：https://leetcode.cn/problems/number-of-increasing-paths-in-a-grid
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <algorithm>
#include "../check/CheckResult.h"

using namespace std;

class Node {
public:
    int value;
    int r;
    int c;

    Node(int _v, int _r, int _c) : value(_v), r(_r), c(_c) {}

    bool operator<(const Node& node) const {
        return value > node.value;
    }
};

class Solution {
public:
    int countPaths(vector<vector<int>>& grid) {
        vector<Node> nodes;

        getNodes(grid, nodes);
        sort(nodes.begin(), nodes.end());

        return getAllPaths(grid, nodes);
    }

    void getNodes(vector<vector<int>>& grid, vector<Node>& nodes) {
        for (int r = 0; r < (int)grid.size(); ++r) {
            for (int c = 0; c < (int)grid[0].size(); ++c) {
                nodes.push_back(Node(grid[r][c], r, c));
            }
        }
    }

    int getAllPaths(vector<vector<int>>& grid, vector<Node>& nodes) {
        int row = grid.size(), column = grid[0].size(), allPaths = 0, mod = 1000000007;
        vector<vector<int>> paths(row, vector<int>(column, 0));
        int dr[4] = { 0,1,0,-1 }, dc[4] = { 1,0,-1,0 };

        for (Node& node : nodes) {
            int r = node.r, c = node.c;
            paths[r][c] = 1;

            for (int i = 0; i < 4; ++i) {
                int nr = r + dr[i], nc = c + dc[i];

                if (nr >= 0 && nr < row && nc >= 0 && nc < column && grid[nr][nc] > grid[r][c]) {
                    paths[r][c] = (paths[r][c] + paths[nr][nc]) % mod;
                }
            }

            allPaths = (allPaths + paths[r][c]) % mod;
        }

        return allPaths;
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<vector<int>> grid = { {1,1},{3,4} };
    check.checkInt(8, o.countPaths(grid));

    grid = { {1},{2} };
    check.checkInt(3, o.countPaths(grid));

    grid = { {1,2,3},{4,5,6},{7,8,9} };
    check.checkInt(53, o.countPaths(grid));

    grid = { {1,2,3,1,2,3},{4,5,6,4,5,6},{7,8,9,7,8,9} };
    check.checkInt(116, o.countPaths(grid));
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
