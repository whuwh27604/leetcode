/* 统计参与通信的服务器.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
这里有一幅服务器分布图，服务器的位置标识在 m * n 的整数矩阵网格 grid 中，1 表示单元格上有服务器，0 表示没有。

如果两台服务器位于同一行或者同一列，我们就认为它们之间可以进行通信。

请你统计并返回能够与至少一台其他服务器进行通信的服务器的数量。

 

示例 1：



输入：grid = [[1,0],[0,1]]
输出：0
解释：没有一台服务器能与其他服务器进行通信。
示例 2：



输入：grid = [[1,0],[1,1]]
输出：3
解释：所有这些服务器都至少可以与一台别的服务器进行通信。
示例 3：



输入：grid = [[1,1,0,0],[0,0,1,0],[0,0,1,0],[0,0,0,1]]
输出：4
解释：第一行的两台服务器互相通信，第三列的两台服务器互相通信，但右下角的服务器无法与其他服务器通信。
 

提示：

m == grid.length
n == grid[i].length
1 <= m <= 250
1 <= n <= 250
grid[i][j] == 0 or 1

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/count-servers-that-communicate
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <unordered_map>
#include "../check/CheckResult.h"

using namespace std;

class DSU {
public:
    DSU(int _size) {
        size = _size;
        parents = new int[size];

        for (int i = 0; i < size; ++i) {
            parents[i] = i;
        }
    }

    ~DSU() {
        delete[] parents;
    }

    int find(int x) {
        if (parents[x] != x) {
            parents[x] = find(parents[x]);
        }

        return parents[x];
    }

    void merge(int x, int y) {
        parents[find(x)] = find(y);
    }

private:
    int* parents;
    int size;
};

class Solution {
public:
    int countServers(vector<vector<int>>& grid) {
        DSU dsu((grid.size() + 1) * (grid[0].size() + 1));

        mergeServers(grid, dsu);

        return countCommunicatingServers(grid, dsu);
    }

    void mergeServers(vector<vector<int>>& grid, DSU& dsu) {
        int i, j, row = grid.size(), column = grid[0].size(), size = row * column;

        for (i = 0; i < row; ++i) {
            for (j = 0; j < column; ++j) {
                if (grid[i][j] == 1) {
                    dsu.merge(i * column + j, size + i);
                    dsu.merge(i * column + j, size + row + j);
                }
            }
        }
    }

    int countCommunicatingServers(vector<vector<int>>& grid, DSU& dsu) {
        int i, j, row = grid.size(), column = grid[0].size(), servers = 0;
        unordered_map<int, int> sets;

        for (i = 0; i < row; ++i) {
            for (j = 0; j < column; ++j) {
                if (grid[i][j] == 1) {
                    int index = dsu.find(i * column + j);
                    if (sets.count(index) == 0) {
                        sets[index] = 1;
                    }
                    else if (sets[index] == 1) {
                        sets[index] = 2;
                        servers += 2;
                    }
                    else {
                        ++servers;
                    }
                }
            }
        }

        return servers;
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<vector<int>> grid = { {1,0},{0,1} };
    check.checkInt(0, o.countServers(grid));

    grid = { {1,0},{1,1} };
    check.checkInt(3, o.countServers(grid));

    grid = { {1,1,0,0},{0,0,1,0},{0,0,1,0},{0,0,0,1} };
    check.checkInt(4, o.countServers(grid));

    grid = { {0,1,0,0},{0,0,0,1},{1,0,0,0},{0,0,1,0} };
    check.checkInt(0, o.countServers(grid));

    grid = { {1} };
    check.checkInt(0, o.countServers(grid));

    grid = { {1,0,1,0,1},{0,1,0,1,0},{1,0,1,0,1},{0,1,0,1,0},{1,0,1,0,1} };
    check.checkInt(13, o.countServers(grid));
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
