/* 设计相邻元素求和服务.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你一个 n x n 的二维数组 grid，它包含范围 [0, n2 - 1] 内的不重复元素。

实现 neighborSum 类：

neighborSum(int [][]grid) 初始化对象。
int adjacentSum(int value) 返回在 grid 中与 value 相邻的元素之和，相邻指的是与 value 在上、左、右或下的元素。
int diagonalSum(int value) 返回在 grid 中与 value 对角线相邻的元素之和，对角线相邻指的是与 value 在左上、右上、左下或右下的元素。




示例 1：

输入：

["neighborSum", "adjacentSum", "adjacentSum", "diagonalSum", "diagonalSum"]

[[[[0, 1, 2], [3, 4, 5], [6, 7, 8]]], [1], [4], [4], [8]]

输出： [null, 6, 16, 16, 4]

解释：



1 的相邻元素是 0、2 和 4。
4 的相邻元素是 1、3、5 和 7。
4 的对角线相邻元素是 0、2、6 和 8。
8 的对角线相邻元素是 4。
示例 2：

输入：

["neighborSum", "adjacentSum", "diagonalSum"]

[[[[1, 2, 0, 3], [4, 7, 15, 6], [8, 9, 10, 11], [12, 13, 14, 5]]], [15], [9]]

输出： [null, 23, 45]

解释：



15 的相邻元素是 0、10、7 和 6。
9 的对角线相邻元素是 4、12、14 和 15。


提示：

3 <= n == grid.length == grid[0].length <= 10
0 <= grid[i][j] <= n2 - 1
所有 grid[i][j] 值均不重复。
adjacentSum 和 diagonalSum 中的 value 均在范围 [0, n2 - 1] 内。
最多会调用 adjacentSum 和 diagonalSum 总共 2 * n2 次。
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class NeighborSum {
public:
    NeighborSum(vector<vector<int>>& grid) {
        int n = (int)grid.size();
        adjSum.resize(n * n, 0);
        diagSum.resize(n * n, 0);

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                int value = grid[i][j];
                if (i != 0) {
                    adjSum[value] += grid[i - 1][j];
                }
                if (i != n - 1) {
                    adjSum[value] += grid[i + 1][j];
                }
                if (j != 0) {
                    adjSum[value] += grid[i][j - 1];
                }
                if (j != n - 1) {
                    adjSum[value] += grid[i][j + 1];
                }

                if (i != 0 && j != 0) {
                    diagSum[value] += grid[i - 1][j - 1];
                }
                if (i != 0 && j != n - 1) {
                    diagSum[value] += grid[i - 1][j + 1];
                }
                if (i != n - 1 && j != 0) {
                    diagSum[value] += grid[i + 1][j - 1];
                }
                if (i != n - 1 && j != n - 1) {
                    diagSum[value] += grid[i + 1][j + 1];
                }
            }
        }
    }

    int adjacentSum(int value) {
        return adjSum[value];
    }

    int diagonalSum(int value) {
        return diagSum[value];
    }

    vector<int> adjSum;
    vector<int> diagSum;
};

int main()
{
    CheckResult check;

    vector<vector<int>> grid = { {0,1,2},{3,4,5},{6,7,8} };
    NeighborSum o1(grid);
    check.checkInt(6, o1.adjacentSum(1));
    check.checkInt(16, o1.adjacentSum(4));
    check.checkInt(16, o1.diagonalSum(4));
    check.checkInt(4, o1.diagonalSum(8));

    grid = { {1,2,0,3},{4,7,15,6},{8,9,10,11},{12,13,14,5} };
    NeighborSum o2(grid);
    check.checkInt(23, o2.adjacentSum(15));
    check.checkInt(45, o2.diagonalSum(9));
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
