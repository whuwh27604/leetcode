/* 包含所有 1 的最小矩形面积 II.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你一个二维 二进制 数组 grid。你需要找到 3 个 不重叠、面积 非零 、边在水平方向和竖直方向上的矩形，并且满足 grid 中所有的 1 都在这些矩形的内部。

返回这些矩形面积之和的 最小 可能值。

注意，这些矩形可以相接。



示例 1：

输入： grid = [[1,0,1],[1,1,1]]

输出： 5

解释：



位于 (0, 0) 和 (1, 0) 的 1 被一个面积为 2 的矩形覆盖。
位于 (0, 2) 和 (1, 2) 的 1 被一个面积为 2 的矩形覆盖。
位于 (1, 1) 的 1 被一个面积为 1 的矩形覆盖。
示例 2：

输入： grid = [[1,0,1,0],[0,1,0,1]]

输出： 5

解释：



位于 (0, 0) 和 (0, 2) 的 1 被一个面积为 3 的矩形覆盖。
位于 (1, 1) 的 1 被一个面积为 1 的矩形覆盖。
位于 (1, 3) 的 1 被一个面积为 1 的矩形覆盖。


提示：

1 <= grid.length, grid[i].length <= 30
grid[i][j] 是 0 或 1。
输入保证 grid 中至少有三个 1 。
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Node {
public:
    int minR;
    int maxR;
    int minC;
    int maxC;

    Node(int r, int c) : minR(r), maxR(-1), minC(c), maxC(-1) {}

    void insert(int r, int c) {
        minR = min(minR, r), maxR = max(maxR, r);
        minC = min(minC, c), maxC = max(maxC, c);
    }
};

class Solution {
public:
    int minimumSum(vector<vector<int>>& grid) {
        int minRectangles = getMinRectangles(grid);
        vector<vector<int>> rotated = rotate(grid);
        minRectangles = min(minRectangles, getMinRectangles(rotated));

        return minRectangles;
    }

    int getMinRectangles(vector<vector<int>>& grid) {
        row = (int)grid.size(), column = (int)grid[0].size();

        vector<int> minCs(row, column), maxCs(row, -1);
        getRowBorder(grid, minCs, maxCs);

        vector<int> up(row, inf);
        getUpMinRectangles(minCs, maxCs, up);

        vector<int> down(row, inf);
        getDownMinRectangles(minCs, maxCs, down);

        vector<vector<int>> middle(row, vector<int>(row, inf));
        getMiddleMinRectangles(minCs, maxCs, middle);

        vector<vector<int>> leftup(row, vector<int>(column, inf));
        getLeftupMinRectangles(grid, leftup);

        vector<vector<int>> rightup(row, vector<int>(column, inf));
        getRightupMinRectangles(grid, rightup);

        vector<vector<int>> leftdown(row, vector<int>(column, inf));
        getLeftdownMinRectangles(grid, leftdown);

        vector<vector<int>> rightdown(row, vector<int>(column, inf));
        getRightdownMinRectangles(grid, rightdown);

        int minRectangles = getMinRectangles(up, down, middle);
        minRectangles = min(minRectangles, getMinRectangles(up, down, leftup, rightup, leftdown, rightdown));

        return minRectangles;
    }

    int getMinRectangles(vector<int>& up, vector<int>& down, vector<vector<int>>& middle) {
        int minRectangles = inf;

        for (int r1 = 1; r1 < row - 1; ++r1) {
            for (int r2 = r1 + 1; r2 < row; ++r2) {
                minRectangles = min(minRectangles, up[r1 - 1] + down[r2] + middle[r1][r2 - 1]);
            }
        }

        return minRectangles;
    }

    int getMinRectangles(vector<int>& up, vector<int>& down, vector<vector<int>>& leftup,
        vector<vector<int>>& rightup, vector<vector<int>>& leftdown, vector<vector<int>>& rightdown) {
        int minRectangles = inf;

        for (int r = 1; r < row; ++r) {
            for (int c = 1; c < column; ++c) {
                minRectangles = min(minRectangles, up[r - 1] + leftdown[r][c - 1] + rightdown[r][c]);
                minRectangles = min(minRectangles, down[r] + leftup[r - 1][c - 1] + rightup[r - 1][c]);
            }
        }

        return minRectangles;
    }

    void getRowBorder(vector<vector<int>>& grid, vector<int>& minCs, vector<int>& maxCs) {
        for (int r = 0; r < row; ++r) {
            for (int c = 0; c < column; ++c) {
                if (grid[r][c] == 1) {
                    minCs[r] = min(minCs[r], c);
                    maxCs[r] = max(maxCs[r], c);
                }
            }
        }
    }

    void getUpMinRectangles(vector<int>& minCs, vector<int>& maxCs, vector<int>& up) {
        int minR = row, maxR = -1, minC = column, maxC = -1;

        for (int r = 0; r < row; ++r) {
            if (maxCs[r] != -1) {
                minR = min(minR, r), maxR = max(maxR, r);
                minC = min(minC, minCs[r]), maxC = max(maxC, maxCs[r]);
            }

            if (maxR != -1) {
                up[r] = (maxR - minR + 1) * (maxC - minC + 1);
            }
        }
    }

    void getDownMinRectangles(vector<int>& minCs, vector<int>& maxCs, vector<int>& down) {
        int minR = row, maxR = -1, minC = column, maxC = -1;

        for (int r = row - 1; r >= 0; --r) {
            if (maxCs[r] != -1) {
                minR = min(minR, r), maxR = max(maxR, r);
                minC = min(minC, minCs[r]), maxC = max(maxC, maxCs[r]);
            }

            if (maxR != -1) {
                down[r] = (maxR - minR + 1) * (maxC - minC + 1);
            }
        }
    }

    void getMiddleMinRectangles(vector<int>& minCs, vector<int>& maxCs, vector<vector<int>>& middle) {
        for (int r1 = 1; r1 < row - 1; ++r1) {
            int minR = row, maxR = -1, minC = column, maxC = -1;

            for (int r2 = r1; r2 < row - 1; ++r2) {
                if (maxCs[r2] != -1) {
                    minR = min(minR, r2), maxR = max(maxR, r2);
                    minC = min(minC, minCs[r2]), maxC = max(maxC, maxCs[r2]);
                }

                if (maxR != -1) {
                    middle[r1][r2] = (maxR - minR + 1) * (maxC - minC + 1);
                }
            }
        }
    }

    void getLeftupMinRectangles(vector<vector<int>>& grid, vector<vector<int>>& leftup) {
        vector<Node> nodes(column, Node(row, column));

        for (int r = 0; r < row; ++r) {
            int minR = row, maxR = -1, minC = column, maxC = -1;

            for (int c = 0; c < column; ++c) {
                if (grid[r][c] == 1) {
                    nodes[c].insert(r, c);
                }

                if (nodes[c].maxC != -1) {
                    minR = min(minR, nodes[c].minR), maxR = max(maxR, nodes[c].maxR);
                    minC = min(minC, nodes[c].minC), maxC = max(maxC, nodes[c].maxC);
                }

                if (maxR != -1) {
                    leftup[r][c] = (maxR - minR + 1) * (maxC - minC + 1);
                }
            }
        }
    }

    void getRightupMinRectangles(vector<vector<int>>& grid, vector<vector<int>>& rightup) {
        vector<Node> nodes(column, Node(row, column));

        for (int r = 0; r < row; ++r) {
            int minR = row, maxR = -1, minC = column, maxC = -1;

            for (int c = column - 1; c >= 0; --c) {
                if (grid[r][c] == 1) {
                    nodes[c].insert(r, c);
                }

                if (nodes[c].maxC != -1) {
                    minR = min(minR, nodes[c].minR), maxR = max(maxR, nodes[c].maxR);
                    minC = min(minC, nodes[c].minC), maxC = max(maxC, nodes[c].maxC);
                }

                if (maxR != -1) {
                    rightup[r][c] = (maxR - minR + 1) * (maxC - minC + 1);
                }
            }
        }
    }

    void getLeftdownMinRectangles(vector<vector<int>>& grid, vector<vector<int>>& leftdown) {
        vector<Node> nodes(column, Node(row, column));

        for (int r = row - 1; r >= 0; --r) {
            int minR = row, maxR = -1, minC = column, maxC = -1;

            for (int c = 0; c < column; ++c) {
                if (grid[r][c] == 1) {
                    nodes[c].insert(r, c);
                }

                if (nodes[c].maxC != -1) {
                    minR = min(minR, nodes[c].minR), maxR = max(maxR, nodes[c].maxR);
                    minC = min(minC, nodes[c].minC), maxC = max(maxC, nodes[c].maxC);
                }

                if (maxR != -1) {
                    leftdown[r][c] = (maxR - minR + 1) * (maxC - minC + 1);
                }
            }
        }
    }

    void getRightdownMinRectangles(vector<vector<int>>& grid, vector<vector<int>>& rightdown) {
        vector<Node> nodes(column, Node(row, column));

        for (int r = row - 1; r >= 0; --r) {
            int minR = row, maxR = -1, minC = column, maxC = -1;

            for (int c = column - 1; c >= 0; --c) {
                if (grid[r][c] == 1) {
                    nodes[c].insert(r, c);
                }

                if (nodes[c].maxC != -1) {
                    minR = min(minR, nodes[c].minR), maxR = max(maxR, nodes[c].maxR);
                    minC = min(minC, nodes[c].minC), maxC = max(maxC, nodes[c].maxC);
                }

                if (maxR != -1) {
                    rightdown[r][c] = (maxR - minR + 1) * (maxC - minC + 1);
                }
            }
        }
    }

    vector<vector<int>> rotate(vector<vector<int>>& grid) {
        vector<vector<int>> rotated(column, vector<int>(row));

        for (int r = 0; r < row; ++r) {
            for (int c = 0; c < column; ++c) {
                rotated[c][r] = grid[r][c];
            }
        }

        return rotated;
    }

    int row = 0;
    int column = 0;
    int inf = INT_MAX / 3;
};

int main()
{
    Solution o;
    CheckResult check;

    vector<vector<int>> grid = { {1,0,1},{1,1,1} };
    check.checkInt(5, o.minimumSum(grid));

    grid = { {1,0,1,0},{0,1,0,1} };
    check.checkInt(5, o.minimumSum(grid));

    grid = { {0,0,0},{0,0,0},{0,0,1},{1,1,0} };
    check.checkInt(3, o.minimumSum(grid));

    grid = { {0,0,0},{0,0,0},{1,1,1},{0,0,0} };
    check.checkInt(3, o.minimumSum(grid));

    grid = { {0,0,0,0},{0,0,0,0},{0,1,1,1} };
    check.checkInt(3, o.minimumSum(grid));
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
