/* 奇数值单元格的数目.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你一个 n 行 m 列的矩阵，最开始的时候，每个单元格中的值都是 0。

另有一个索引数组 indices，indices[i] = [ri, ci] 中的 ri 和 ci 分别表示指定的行和列（从 0 开始编号）。

你需要将每对 [ri, ci] 指定的行和列上的所有单元格的值加 1。

请你在执行完所有 indices 指定的增量操作后，返回矩阵中 「奇数值单元格」 的数目。

 

示例 1：



输入：n = 2, m = 3, indices = [[0,1],[1,1]]
输出：6
解释：最开始的矩阵是 [[0,0,0],[0,0,0]]。
第一次增量操作后得到 [[1,2,1],[0,1,0]]。
最后的矩阵是 [[1,3,1],[1,3,1]]，里面有 6 个奇数。
示例 2：



输入：n = 2, m = 2, indices = [[1,1],[0,0]]
输出：0
解释：最后的矩阵是 [[2,2],[2,2]]，里面没有奇数。
 

提示：

1 <= n <= 50
1 <= m <= 50
1 <= indices.length <= 100
0 <= indices[i][0] < n
0 <= indices[i][1] < m

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/cells-with-odd-values-in-a-matrix
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int oddCells(int n, int m, vector<vector<int>>& indices) {
        int sumOddRows = 0, sumOddColumns = 0;
        vector<int> rowIndex(n, 0), columnIndex(m, 0);


        for (auto& index : indices) {
            ++rowIndex[index[0]];
            ++columnIndex[index[1]];
        }

        for (int i = 0; i < n; ++i) {
            if ((rowIndex[i] % 2) == 1) {
                ++sumOddRows;
            }
        }

        for (int i = 0; i < m; ++i) {
            if ((columnIndex[i] % 2) == 1) {
                ++sumOddColumns;
            }
        }

        return (sumOddRows * m + sumOddColumns * n - sumOddRows * sumOddColumns * 2);
    }
};

int main()
{
    Solution o;
    CheckResult check;

    vector<vector<int>> indices = { {0,1},{1,1} };
    check.checkInt(6, o.oddCells(2, 3, indices));

    indices = { {1,1},{0,0} };
    check.checkInt(0, o.oddCells(2, 2, indices));

    indices = { {0,0} };
    check.checkInt(0, o.oddCells(1, 1, indices));

    indices = { {0,0},{0,0},{0,0},{0,0},{0,0},{0,0} };
    check.checkInt(0, o.oddCells(1, 1, indices));

    indices = { {0,0} };
    check.checkInt(4, o.oddCells(5, 1, indices));

    indices = { {0,0},{1,0} };
    check.checkInt(2, o.oddCells(5, 1, indices));

    indices = { {0,0} };
    check.checkInt(4, o.oddCells(1, 5, indices));

    indices = { {0,0},{0,1} };
    check.checkInt(2, o.oddCells(1, 5, indices));

    indices = { {1,1},{2,2},{3,3} };
    check.checkInt(12, o.oddCells(5, 5, indices));
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
