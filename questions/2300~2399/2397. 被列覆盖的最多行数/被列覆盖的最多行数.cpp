/* 被列覆盖的最多行数.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你一个下标从 0 开始的 m x n 二进制矩阵 mat 和一个整数 cols ，表示你需要选出的列数。

如果一行中，所有的 1 都被你选中的列所覆盖，那么我们称这一行 被覆盖 了。

请你返回在选择 cols 列的情况下，被覆盖 的行数 最大 为多少。

 

示例 1：



输入：mat = [[0,0,0],[1,0,1],[0,1,1],[0,0,1]], cols = 2
输出：3
解释：
如上图所示，覆盖 3 行的一种可行办法是选择第 0 和第 2 列。
可以看出，不存在大于 3 行被覆盖的方案，所以我们返回 3 。
示例 2：



输入：mat = [[1],[0]], cols = 1
输出：2
解释：
选择唯一的一列，两行都被覆盖了，原因是整个矩阵都被覆盖了。
所以我们返回 2 。
 

提示：

m == mat.length
n == mat[i].length
1 <= m, n <= 12
mat[i][j] 要么是 0 要么是 1 。
1 <= cols <= n

来源：力扣（LeetCode）
链接：https://leetcode.cn/problems/maximum-rows-covered-by-columns
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <algorithm>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int maximumRows(vector<vector<int>>& mat, int cols) {
        int row = mat.size(), column = mat[0].size();
        vector<int> rows(row, 0);

        getRows(mat, rows);

        return GospersHack(column, cols, rows);
    }

    void getRows(vector<vector<int>>& mat, vector<int>& rows) {
        int row = mat.size(), column = mat[0].size();

        for (int i = 0; i < row; ++i) {
            int num = 0;

            for (int j = 0, bit = (1 << (column - 1)); j < column; ++j, bit >>= 1) {
                if (mat[i][j] == 1) {
                    num |= bit;
                }
            }

            rows[i] = num;
        }
    }

    int getCovered(vector<int>& rows, int columns) {
        int count = 0;

        for (int num : rows) {
            if ((num & columns) == num) {
                ++count;
            }
        }

        return count;
    }

    int GospersHack(int n, int k, vector<int>& rows) {  // 枚举所有n位数里面有k个1的情况
        int current = (1 << k) - 1, limit = (1 << n);
        int maxCovered = 0;

        while (current < limit) {
            maxCovered = max(maxCovered, getCovered(rows, current));

            int lowbit = current & -current;
            int r = current + lowbit;
            current = (((r ^ current) >> 2) / lowbit) | r;
        }

        return maxCovered;
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<vector<int>> mat = { {0,0,0},{1,0,1},{0,1,1},{0,0,1} };
    check.checkInt(3, o.maximumRows(mat, 2));

    mat = { {1},{0} };
    check.checkInt(2, o.maximumRows(mat, 1));

    mat = { {0,0,0,0,0,0,0,0,0,0,0,0},{1,0,1,1,0,1,1,0,1,1,0,1},{0,1,1,0,1,1,0,1,1,0,1,1},{0,0,1,0,0,1,0,0,1,0,0,1},
    {0,0,0,0,0,0,0,0,0,0,0,0},{1,0,1,1,0,1,1,0,1,1,0,1},{0,1,1,0,1,1,0,1,1,0,1,1},{0,0,1,0,0,1,0,0,1,0,0,1},
    {0,0,0,0,0,0,0,0,0,0,0,0},{1,0,1,1,0,1,1,0,1,1,0,1},{0,1,1,0,1,1,0,1,1,0,1,1},{0,0,1,0,0,1,0,0,1,0,0,1} };
    check.checkInt(9, o.maximumRows(mat, 8));

    mat = { {0,0,0,0,0,0,0,0,0,0,0,0},{1,0,1,1,0,1,1,0,1,1,0,1},{0,1,1,0,1,1,0,1,1,0,1,1},{0,0,1,0,0,1,0,0,1,0,0,1},
    {0,0,0,0,0,0,0,0,0,0,0,0},{1,0,1,1,0,1,1,0,1,1,0,1},{0,1,1,0,1,1,0,1,1,0,1,1},{0,0,1,0,0,1,0,0,1,0,0,1},
    {0,0,0,0,0,0,0,0,0,0,0,0},{1,0,1,1,0,1,1,0,1,1,0,1},{0,1,1,0,1,1,0,1,1,0,1,1},{0,0,1,0,0,1,0,0,1,0,0,1} };
    check.checkInt(12, o.maximumRows(mat, 12));
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
