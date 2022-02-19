/* 使陆地分离的最少天数.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你一个由若干 0 和 1 组成的二维网格 grid ，其中 0 表示水，而 1 表示陆地。岛屿由水平方向或竖直方向上相邻的 1 （陆地）连接形成。

如果 恰好只有一座岛屿 ，则认为陆地是 连通的 ；否则，陆地就是 分离的 。

一天内，可以将任何单个陆地单元（1）更改为水单元（0）。

返回使陆地分离的最少天数。

 

示例 1：



输入：grid = [[0,1,1,0],[0,1,1,0],[0,0,0,0]]
输出：2
解释：至少需要 2 天才能得到分离的陆地。
将陆地 grid[1][1] 和 grid[0][2] 更改为水，得到两个分离的岛屿。
示例 2：

输入：grid = [[1,1]]
输出：2
解释：如果网格中都是水，也认为是分离的 ([[1,1]] -> [[0,0]])，0 岛屿。
示例 3：

输入：grid = [[1,0,1,0]]
输出：0
示例 4：

输入：grid = [[1,1,0,1,1],
             [1,1,1,1,1],
             [1,1,0,1,1],
             [1,1,0,1,1]]
输出：1
示例 5：

输入：grid = [[1,1,0,1,1],
             [1,1,1,1,1],
             [1,1,0,1,1],
             [1,1,1,1,1]]
输出：2
 

提示：

1 <= grid.length, grid[i].length <= 30
grid[i][j] 为 0 或 1

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/minimum-number-of-days-to-disconnect-island
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <algorithm>
#include "../check/CheckResult.h"

using namespace std;

class Tarjan {
public:
    Tarjan(int n_, const vector<vector<int>>& adjs_) : \
        n(n_), adjs(adjs_), low(n_, -1), dfn(n_, -1), ts(-1), connected(0) {}

    void getAllCuttingVertexes(vector<int>& cuttingVertexes) {
        for (int i = 0; i < n; ++i) {
            if (dfn[i] == -1) {
                ++connected;
                getCuttingVertexes(i, -1, cuttingVertexes);
            }
        }
    }

    void getCuttingVertexes(int vertex, int parentId, vector<int>& cuttingVertexes) {
        int child = 0;
        bool isCutting = false;
        low[vertex] = dfn[vertex] = ++ts;

        for (int peer : adjs[vertex]) {
            if (dfn[peer] == -1) {
                ++child;
                getCuttingVertexes(peer, vertex, cuttingVertexes);
                low[vertex] = min(low[vertex], low[peer]);

                if (parentId != -1 && !isCutting && low[peer] >= dfn[vertex]) {  // 非根节点，并且不要重复加入答案
                    isCutting = true;
                    cuttingVertexes.push_back(vertex);
                }
            }
            else if (peer != parentId) {
                low[vertex] = min(low[vertex], dfn[peer]);
            }
        }

        if (parentId == -1 && child > 1) {  // 是根节点，并且有多个children，那么根节点肯定是割点
            cuttingVertexes.push_back(vertex);
        }
    }

    int getConnectedComponent() {
        return connected;
    }

private:
    const vector<vector<int>>& adjs;
    vector<int> low;
    vector<int> dfn;
    int n;
    int ts;
    int connected;
};

class Solution {
public:
    int minDays(vector<vector<int>>& grid) {
        vector<vector<int>> landIds(grid.size(), vector<int>(grid[0].size()));
        int landCount = assignLandId(grid, landIds);
        if (landCount == 0) {
            return 0;  // 没有land，直接返回0
        }
        else if (landCount == 1) {
            return 1;  // 只有一个land，改变它就可以了
        }

        vector<vector<int>> adjs(landCount);
        createGraph(grid, landIds, adjs);

        vector<int> cuttingVertexes;
        Tarjan tarjan(landCount, adjs);
        tarjan.getAllCuttingVertexes(cuttingVertexes);
        int connectedComponent = tarjan.getConnectedComponent();

        if (connectedComponent > 1) {
            return 0;  // 有多个连通分量，说明已经是land分离状态
        }

        return cuttingVertexes.empty() ? 2 : 1;  // 存在割点，那么改变割点就可以使land分离；不存在割点，那么最多改变两个点就可以分离出一个land
    }

    int assignLandId(vector<vector<int>>& grid, vector<vector<int>>& landIds) {
        int i, j, row = grid.size(), column = grid[0].size(), id = 0;

        for (i = 0; i < row; ++i) {
            for (j = 0; j < column; ++j) {
                if (grid[i][j] == 1) {
                    landIds[i][j] = id++;
                }
            }
        }

        return id;
    }

    void createGraph(vector<vector<int>>& grid, vector<vector<int>>& landIds, vector<vector<int>>& adjs) {
        int i, j, row = grid.size(), column = grid[0].size();

        for (i = 0; i < row; ++i) {
            for (j = 0; j < column; ++j) {
                if (grid[i][j] == 0) {
                    continue;
                }

                if (i != 0 && grid[i - 1][j] == 1) {
                    adjs[landIds[i][j]].push_back(landIds[i - 1][j]);
                    adjs[landIds[i - 1][j]].push_back(landIds[i][j]);
                }

                if (j != 0 && grid[i][j - 1] == 1) {
                    adjs[landIds[i][j]].push_back(landIds[i][j - 1]);
                    adjs[landIds[i][j - 1]].push_back(landIds[i][j]);
                }
            }
        }
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<vector<int>> grid = {{0,1,1,0},{0,1,1,0},{0,0,0,0}};
    check.checkInt(2,o.minDays(grid));

    grid = {{1,1}};
    check.checkInt(2,o.minDays(grid));

    grid = { {0} };
    check.checkInt(0, o.minDays(grid));

    grid = { {1} };
    check.checkInt(1, o.minDays(grid));

    grid = {{1,0,1,0}};
    check.checkInt(0,o.minDays(grid));

    grid = {{1,1,0,1,1},
        {1,1,1,1,1},
        {1,1,0,1,1},
        {1,1,0,1,1}};
    check.checkInt(1,o.minDays(grid));

    grid = {{1,1,0,1,1},
        {1,1,1,1,1},
        {1,1,0,1,1},
        {1,1,1,1,1}};
    check.checkInt(2, o.minDays(grid));

    grid = { {0,1,0,1,1},{1,1,1,1,1},{1,1,1,1,1},{1,1,1,1,0} };
    check.checkInt(1, o.minDays(grid));
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
