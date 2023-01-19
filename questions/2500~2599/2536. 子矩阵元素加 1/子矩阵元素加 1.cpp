/* 子矩阵元素加 1.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你一个正整数 n ，表示最初有一个 n x n 、下标从 0 开始的整数矩阵 mat ，矩阵中填满了 0 。

另给你一个二维整数数组 query 。针对每个查询 query[i] = [row1i, col1i, row2i, col2i] ，请你执行下述操作：

找出 左上角 为 (row1i, col1i) 且 右下角 为 (row2i, col2i) 的子矩阵，将子矩阵中的 每个元素 加 1 。也就是给所有满足 row1i <= x <= row2i 和 col1i <= y <= col2i 的 mat[x][y] 加 1 。
返回执行完所有操作后得到的矩阵 mat 。



示例 1：



输入：n = 3, queries = [[1,1,2,2],[0,0,1,1]]
输出：[[1,1,0],[1,2,1],[0,1,1]]
解释：上图所展示的分别是：初始矩阵、执行完第一个操作后的矩阵、执行完第二个操作后的矩阵。
- 第一个操作：将左上角为 (1, 1) 且右下角为 (2, 2) 的子矩阵中的每个元素加 1 。
- 第二个操作：将左上角为 (0, 0) 且右下角为 (1, 1) 的子矩阵中的每个元素加 1 。
示例 2：



输入：n = 2, queries = [[0,0,1,1]]
输出：[[1,1],[1,1]]
解释：上图所展示的分别是：初始矩阵、执行完第一个操作后的矩阵。
- 第一个操作：将矩阵中的每个元素加 1 。


提示：

1 <= n <= 500
1 <= queries.length <= 104
0 <= row1i <= row2i < n
0 <= col1i <= col2i < n
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    vector<vector<int>> rangeAddQueries(int n, vector<vector<int>>& queries) {
        vector<vector<int>> diffs(n, vector<int>(n, 0));

        for (auto& query : queries) {
            int r1 = query[0], c1 = query[1], r2 = query[2], c2 = query[3];
            ++diffs[r1][c1];
            if (c2 != n - 1) {
                --diffs[r1][c2 + 1];
            }
            if (r2 != n - 1) {
                --diffs[r2 + 1][c1];
            }
            if (r2 != n - 1 && c2 != n - 1) {
                ++diffs[r2 + 1][c2 + 1];
            }
        }

        for (int r = 0; r < n; ++r) {
            for (int c = 1; c < n; ++c) {
                diffs[r][c] += diffs[r][c - 1];
            }
        }

        for (int r = 1; r < n; ++r) {
            for (int c = 0; c < n; ++c) {
                diffs[r][c] += diffs[r - 1][c];
            }
        }

        return diffs;
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<vector<int>> queries = { {1,1,2,2},{0,0,1,1} };
    vector<vector<int>> actual = o.rangeAddQueries(3, queries);
    vector<vector<int>> expected = { {1,1,0},{1,2,1},{0,1,1} };
    check.checkIntVectorVector(expected, actual);

    queries = { {0,0,1,1} };
    actual = o.rangeAddQueries(2, queries);
    expected = { {1,1},{1,1} };
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
