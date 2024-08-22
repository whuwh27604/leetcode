/* 放三个车的价值之和最大 I.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你一个 m x n 的二维整数数组 board ，它表示一个国际象棋棋盘，其中 board[i][j] 表示格子 (i, j) 的 价值 。

处于 同一行 或者 同一列 车会互相 攻击 。你需要在棋盘上放三个车，确保它们两两之间都 无法互相攻击 。

请你返回满足上述条件下，三个车所在格子 值 之和 最大 为多少。



示例 1：

输入：board = [[-3,1,1,1],[-3,1,-3,1],[-3,2,1,1]]

输出：4

解释：



我们可以将车分别放在格子 (0, 2) ，(1, 3) 和 (2, 1) 处，价值之和为 1 + 1 + 2 = 4 。

示例 2：

输入：board = [[1,2,3],[4,5,6],[7,8,9]]

输出：15

解释：

我们可以将车分别放在格子 (0, 0) ，(1, 1) 和 (2, 2) 处，价值之和为 1 + 5 + 9 = 15 。

示例 3：

输入：board = [[1,1,1],[1,1,1],[1,1,1]]

输出：3

解释：

我们可以将车分别放在格子 (0, 2) ，(1, 1) 和 (2, 0) 处，价值之和为 1 + 1 + 1 = 3 。



提示：

3 <= m == board.length <= 100
3 <= n == board[i].length <= 100
-109 <= board[i][j] <= 109
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    long long maximumValueSum(vector<vector<int>>& board) {
        int row = (int)board.size(), column = (int)board[0].size();
        vector<vector<pair<int, int>>> prefix(row), suffix(row);

        getPrefix(board, row, column, prefix);
        getsuffix(board, row, column, suffix);

        return getMaxValue(board, row, column, prefix, suffix);
    }

    void insert(vector<pair<int, int>>& max3, int val, int c) {
        bool find = false;

        for (int i = 0; i < 3; ++i) {
            if (max3[i].second == c) {
                if (val > max3[i].first) {
                    max3[i].first = val;

                    if (max3[2].first > max3[1].first) {
                        swap(max3[1], max3[2]);
                    }
                    if (max3[1].first > max3[0].first) {
                        swap(max3[0], max3[1]);
                    }
                }

                find = true;
                break;
            }
        }

        if (!find) {
            if (val > max3[0].first) {
                max3[2] = max3[1];
                max3[1] = max3[0];
                max3[0] = { val,c };
            }
            else if (val > max3[1].first) {
                max3[2] = max3[1];
                max3[1] = { val,c };
            }
            else if (val > max3[2].first) {
                max3[2] = { val,c };
            }
        }
    }

    void getPrefix(vector<vector<int>>& board, int row, int column, vector<vector<pair<int, int>>>& prefix) {
        vector<pair<int, int>> max3(3, { INT_MIN,-1 });

        for (int r = 0; r < row; ++r) {
            for (int c = 0; c < column; ++c) {
                insert(max3, board[r][c], c);
            }

            prefix[r] = max3;
        }
    }

    void getsuffix(vector<vector<int>>& board, int row, int column, vector<vector<pair<int, int>>>& suffix) {
        vector<pair<int, int>> max3(3, { INT_MIN,-1 });

        for (int r = row - 1; r >= 0; --r) {
            for (int c = 0; c < column; ++c) {
                insert(max3, board[r][c], c);
            }

            suffix[r] = max3;
        }
    }

    long long getMaxValue(vector<vector<int>>& board, int row, int column,
        vector<vector<pair<int, int>>>& prefix, vector<vector<pair<int, int>>>& suffix) {
        long long maxValue = LLONG_MIN;

        for (int r = 1; r < row - 1; ++r) {  // 枚举中间一行的车
            for (int c = 0; c < column; ++c) {
                for (int i = 0; i < 3; ++i) {
                    for (int j = 0; j < 3; ++j) {
                        if (prefix[r - 1][i].second != c && suffix[r + 1][j].second != c && prefix[r - 1][i].second != suffix[r + 1][j].second) {
                            maxValue = max(maxValue, (long long)board[r][c] + prefix[r - 1][i].first + suffix[r + 1][j].first);
                        }
                    }
                }
            }
        }

        return maxValue;
    }
};

int main()
{
    Solution o;
    CheckResult check;

    vector<vector<int>> board = { {-3,1,1,1},{-3,1,-3,1},{-3,2,1,1} };
    check.checkLongLong(4, o.maximumValueSum(board));

    board = { {1,2,3},{4,5,6},{7,8,9} };
    check.checkLongLong(15, o.maximumValueSum(board));

    board = { {1,1,1},{1,1,1},{1,1,1} };
    check.checkLongLong(3, o.maximumValueSum(board));
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
