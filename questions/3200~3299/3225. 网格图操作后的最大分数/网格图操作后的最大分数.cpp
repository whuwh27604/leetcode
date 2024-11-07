/* 网格图操作后的最大分数.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你一个大小为 n x n 的二维矩阵 grid ，一开始所有格子都是白色的。一次操作中，你可以选择任意下标为 (i, j) 的格子，并将第 j 列中从最上面到第 i 行所有格子改成黑色。

如果格子 (i, j) 为白色，且左边或者右边的格子至少一个格子为黑色，那么我们将 grid[i][j] 加到最后网格图的总分中去。

请你返回执行任意次操作以后，最终网格图的 最大 总分数。



示例 1：

输入：grid = [[0,0,0,0,0],[0,0,3,0,0],[0,1,0,0,0],[5,0,0,3,0],[0,0,0,0,2]]

输出：11

解释：


第一次操作中，我们将第 1 列中，最上面的格子到第 3 行的格子染成黑色。第二次操作中，我们将第 4 列中，最上面的格子到最后一行的格子染成黑色。最后网格图总分为 grid[3][0] + grid[1][2] + grid[3][3] 等于 11 。

示例 2：

输入：grid = [[10,9,0,0,15],[7,1,0,8,0],[5,20,0,11,0],[0,0,0,1,2],[8,12,1,10,3]]

输出：94

解释：


我们对第 1 ，2 ，3 列分别从上往下染黑色到第 1 ，4， 0 行。最后网格图总分为 grid[0][0] + grid[1][0] + grid[2][1] + grid[4][1] + grid[1][3] + grid[2][3] + grid[3][3] + grid[4][3] + grid[0][4] 等于 94 。



提示：

1 <= n == grid.length <= 100
n == grid[i].length
0 <= grid[i][j] <= 109
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

typedef long long LL;

class Solution {
public:
    long long maximumScore(vector<vector<int>>& grid) {
        int n = (int)grid.size();
        if (n == 1) {
            return 0;
        }

        vector<vector<LL>> presum(n, vector<LL>(n + 1, 0));
        getPresum(n, grid, presum);

        return getMaxScore(n, presum);
    }

    void getPresum(int n, vector<vector<int>>& grid, vector<vector<LL>>& presum) {
        for (int c = 0; c < n; ++c) {
            for (int r = 0; r < n; ++r) {
                presum[c][r + 1] = presum[c][r] + grid[r][c];
            }
        }
    }

    LL getMaxScore(int n, vector<vector<LL>>& presum) {
        vector<vector<LL>> maxScore(n + 1, vector<LL>(n + 1, 0));  // maxScore[col][cr][pr]表示递推到col列时，当前列高度为cr，前一列高度为pr的最大得分
        vector<LL> preMax(n + 1, 0), sufMax(n + 1, 0);

        for (int col = 1; col < n; ++col) {
            vector<vector<LL>> tmp(n + 1, vector<LL>(n + 1, 0));  // 滚动数组

            for (int cr = 0; cr <= n; ++cr) {  // 枚举当前列高度
                for (int ppr = 0; ppr <= n; ++ppr) {  // 前一列高度为0时，不知道前一列已经有多少个数计入了答案，枚举所有情况
                    if (ppr < cr) {  // [ppr + 1, cr]部分计入答案
                        tmp[cr][0] = max(tmp[cr][0], maxScore[0][ppr] + presum[col - 1][cr] - presum[col - 1][ppr]);
                    }
                    else {  // 所有数都已经计入答案
                        tmp[cr][0] = max(tmp[cr][0], maxScore[0][ppr]);
                    }
                }

                for (int pr = 1; pr <= n; ++pr) {  // 枚举前一列高度
                    if (pr > cr) {  // 下降阶段，当前列[cr + 1, pr]计入答案
                        tmp[cr][pr] = sufMax[pr] + presum[col][pr] - presum[col][cr];

                        if (pr == n) {  // 山形结构只需要计算中间是n的情况
                            tmp[cr][pr] = max(tmp[cr][pr], preMax[pr] + presum[col][pr] - presum[col][cr]);
                        }
                    }
                    else {  // 上升阶段，前一列[pr + 1, cr]计入答案
                        tmp[cr][pr] = preMax[pr] + presum[col - 1][cr] - presum[col - 1][pr];
                    }
                }
            }

            maxScore = tmp;
            getPreMax(n, maxScore, preMax);
            getSufMax(n, maxScore, sufMax);
        }

        return getAns(n, maxScore);
    }

    void getPreMax(int n, vector<vector<LL>>& maxScore, vector<LL>& preMax) {
        preMax.clear();
        preMax.resize(n + 1, 0);

        for (int cc = 0; cc <= n; ++cc) {
            for (int pc = 0; pc <= cc; ++pc) {
                preMax[cc] = max(preMax[cc], maxScore[cc][pc]);
            }
        }
    }

    void getSufMax(int n, vector<vector<LL>>& maxScore, vector<LL>& sufMax) {
        sufMax.clear();
        sufMax.resize(n + 1, 0);

        for (int cc = 0; cc <= n; ++cc) {
            for (int pc = n; pc >= cc; --pc) {
                sufMax[cc] = max(sufMax[cc], maxScore[cc][pc]);
            }
        }
    }

    LL getAns(int n, vector<vector<LL>>& maxScore) {
        LL ans = 0;

        for (int cr = 0; cr <= n; ++cr) {
            for (int pr = 0; pr <= n; ++pr) {
                ans = max(ans, maxScore[cr][pr]);
            }
        }

        return ans;
    }
};

int main()
{
    Solution o;
    CheckResult check;

    vector<vector<int>> grid = { {0,0,0,0,0},{0,0,3,0,0},{0,1,0,0,0},{5,0,0,3,0},{0,0,0,0,2} };
    check.checkLongLong(11, o.maximumScore(grid));

    grid = { {10,9,0,0,15},{7,1,0,8,0},{5,20,0,11,0},{0,0,0,1,2},{8,12,1,10,3} };
    check.checkLongLong(94, o.maximumScore(grid));

    grid = { {10} };
    check.checkLongLong(0, o.maximumScore(grid));
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
