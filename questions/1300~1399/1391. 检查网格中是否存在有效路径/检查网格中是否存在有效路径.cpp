/* 检查网格中是否存在有效路径.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你一个 m x n 的网格 grid。网格里的每个单元都代表一条街道。grid[i][j] 的街道可以是：

1 表示连接左单元格和右单元格的街道。
2 表示连接上单元格和下单元格的街道。
3 表示连接左单元格和下单元格的街道。
4 表示连接右单元格和下单元格的街道。
5 表示连接左单元格和上单元格的街道。
6 表示连接右单元格和上单元格的街道。


你最开始从左上角的单元格 (0,0) 开始出发，网格中的「有效路径」是指从左上方的单元格 (0,0) 开始、一直到右下方的 (m-1,n-1) 结束的路径。该路径必须只沿着街道走。

注意：你 不能 变更街道。

如果网格中存在有效的路径，则返回 true，否则返回 false 。

 

示例 1：



输入：grid = [[2,4,3],[6,5,2]]
输出：true
解释：如图所示，你可以从 (0, 0) 开始，访问网格中的所有单元格并到达 (m - 1, n - 1) 。
示例 2：



输入：grid = [[1,2,1],[1,2,1]]
输出：false
解释：如图所示，单元格 (0, 0) 上的街道没有与任何其他单元格上的街道相连，你只会停在 (0, 0) 处。
示例 3：

输入：grid = [[1,1,2]]
输出：false
解释：你会停在 (0, 1)，而且无法到达 (0, 2) 。
示例 4：

输入：grid = [[1,1,1,1,1,1,3]]
输出：true
示例 5：

输入：grid = [[2],[2],[2],[2],[2],[2],[6]]
输出：true
 

提示：

m == grid.length
n == grid[i].length
1 <= m, n <= 300
1 <= grid[i][j] <= 6

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/check-if-there-is-a-valid-path-in-a-grid
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    Solution() {
        out2InDirection = { 2,3,0,1 };
        outDirection = { {},{-1,3,-1,1},{2,-1,0,-1},{-1,-1,3,2},{-1,2,1,-1},{3,-1,-1,0},{1,0,-1,-1} };
        originalDirection = { -1,3,0,3,1,3,0 };  // 只有street4有两个方向，其它最多只有一个方向可走
        deltaRow = { {},{0,0,0,0},{1,0,-1,0},{0,0,0,1},{0,1,0,0},{0,0,0,-1},{0,-1,0,0} };
        deltaColumn = { {},{0,-1,0,1},{0,0,0,0},{0,0,-1,0},{0,0,1,0},{-1,0,0,0},{1,0,0,0} };
    }

    bool hasValidPath(vector<vector<int>>& grid) {
        int street = grid[0][0];

        if (hasPath(grid, originalDirection[street])) {
            return true;
        }

        if (street == 4) {
            resetGrid(grid);
            return hasPath(grid, 2);
        }
        else {
            return false;
        }
    }

    bool hasPath(vector<vector<int>>& grid, int direction) {
        int r = 0, c = 0, row = grid.size(), column = grid[0].size();

        while (r != row - 1 || c != column - 1) {
            int& street = grid[r][c];  // 当前street
            int nextInDir = out2InDirection[outDirection[street][direction]];  // 进入nextStreet的方向

            r += deltaRow[street][direction];
            c += deltaColumn[street][direction];

            if (r < 0 || r >= row || c < 0 || c >= column || grid[r][c] < 0) {  // 超出范围或者形成环路
                return false;
            }

            if (outDirection[grid[r][c]][nextInDir] == -1) {  // nextStreet和当前street不连通
                return false;
            }

            street = -street;  // 设置当前street已经访问过，避免环路
            direction = nextInDir;
        }

        return true;
    }

    void resetGrid(vector<vector<int>>& grid) {
        for (auto& row : grid) {
            for (auto& street : row) {
                if (street < 0) {
                    street = -street;
                }
            }
        }
    }

private:
    vector<int> out2InDirection;
    vector<vector<int>> outDirection;
    vector<int> originalDirection;
    vector<vector<int>> deltaRow;
    vector<vector<int>> deltaColumn;
};

int main()
{
    CheckResult check;
    Solution o;

    vector<vector<int>> grid = { {2,4,3},{6,5,2} };
    check.checkBool(true, o.hasValidPath(grid));

    grid = { {1,2,1},{1,2,1} };
    check.checkBool(false, o.hasValidPath(grid));

    grid = { {1,1,2} };
    check.checkBool(false, o.hasValidPath(grid));

    grid = { {1,1,1,1,1,1,3} };
    check.checkBool(true, o.hasValidPath(grid));

    grid = { {2},{2},{2},{2},{2},{2},{6} };
    check.checkBool(true, o.hasValidPath(grid));

    grid = { {4,1},{6,1} };
    check.checkBool(true, o.hasValidPath(grid));

    grid = { {5} };
    check.checkBool(true, o.hasValidPath(grid));

    grid = { {4,3},{6,5} };
    check.checkBool(true, o.hasValidPath(grid));

    grid = { {4,3,3},{6,5,5} };
    check.checkBool(false, o.hasValidPath(grid));
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
