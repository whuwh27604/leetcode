/* 统计有序矩阵中的负数.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你一个 m * n 的矩阵 grid，矩阵中的元素无论是按行还是按列，都以非递增顺序排列。 

请你统计并返回 grid 中 负数 的数目。

 

示例 1：

输入：grid = [[4,3,2,-1],[3,2,1,-1],[1,1,-1,-2],[-1,-1,-2,-3]]
输出：8
解释：矩阵中共有 8 个负数。
示例 2：

输入：grid = [[3,2],[1,0]]
输出：0
示例 3：

输入：grid = [[1,-1],[-1,-1]]
输出：3
示例 4：

输入：grid = [[-1]]
输出：1
 

提示：

m == grid.length
n == grid[i].length
1 <= m, n <= 100
-100 <= grid[i][j] <= 100

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/count-negative-numbers-in-a-sorted-matrix
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int i, m = grid.size(), n = grid[0].size(), right = n - 1;
        int oneRowNegatives = 0, allNegatives = 0;

        for (i = 0; i < m; i++) {
            oneRowNegatives += binarySearchNegatives(grid[i], right + 1, 0, right);
            right = n - 1 - oneRowNegatives;
            allNegatives += oneRowNegatives;

            if (oneRowNegatives == n) {
                break;
            }
        }

        if (i != m) {
            allNegatives += (m - 1 - i) * n;
        }

        return allNegatives;
    }

    int binarySearchNegatives(vector<int>& row, int column, int left, int right) {
        int middle = (left + right) / 2;
        if (row[middle] >= 0) {
            if (middle == right) {
                return 0;
            }
            else if (row[middle + 1] < 0) {
                return column - middle - 1;
            }
            else {
                return binarySearchNegatives(row, column, middle + 1, right);
            }
        }
        else {
            if (middle == left) {
                return column;
            }
            else if (row[middle - 1] >= 0) {
                return column - middle;
            }
            else {
                return binarySearchNegatives(row, column, left, middle - 1);
            }
        }
    }
};

int main()
{
    Solution o;
    CheckResult check;

    vector<int> row(100, 0);
    check.checkInt(0, o.binarySearchNegatives(row, 100, 0, 99));
    for (int i = 0; i < 100; i++) {
        row[99 - i] = -1;
        check.checkInt(i + 1, o.binarySearchNegatives(row, 100, 0, 99));
    }

    vector<vector<int>> grid = { {4,3,2,-1},{3,2,1,-1},{1,1,-1,-2},{-1,-1,-2,-3} };
    check.checkInt(8, o.countNegatives(grid));

    grid = { {3,2},{1,0} };
    check.checkInt(0, o.countNegatives(grid));

    grid = { {1,-1},{-1,-1} };
    check.checkInt(3, o.countNegatives(grid));

    grid = { {-1} };
    check.checkInt(1, o.countNegatives(grid));

    grid = { {5} };
    check.checkInt(0, o.countNegatives(grid));

    grid = { {5,5,5} };
    check.checkInt(0, o.countNegatives(grid));

    grid = { {-1,-1,-1} };
    check.checkInt(3, o.countNegatives(grid));

    grid = { {5,5,5,0,-1,-1,-1} };
    check.checkInt(3, o.countNegatives(grid));
    
    grid = { {4,3,2,-1},{3,2,1,-1},{1,1,-1,-2} };
    check.checkInt(4, o.countNegatives(grid));

    grid = { {4,3,2,-1},{3,2,1,-1},{1,1,-1,-2},{-1,-1,-2,-3},{-1,-1,-2,-3} };
    check.checkInt(12, o.countNegatives(grid));
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
