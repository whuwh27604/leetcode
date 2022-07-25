/* 相等行列对.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你一个下标从 0 开始、大小为 n x n 的整数矩阵 grid ，返回满足 Ri 行和 Cj 列相等的行列对 (Ri, Cj) 的数目。

如果行和列以相同的顺序包含相同的元素（即相等的数组），则认为二者是相等的。

 

示例 1：



输入：grid = [[3,2,1],[1,7,6],[2,7,7]]
输出：1
解释：存在一对相等行列对：
- (第 2 行，第 1 列)：[2,7,7]
示例 2：



输入：grid = [[3,1,2,2],[1,4,4,5],[2,4,2,2],[2,4,2,2]]
输出：3
解释：存在三对相等行列对：
- (第 0 行，第 0 列)：[3,1,2,2]
- (第 2 行, 第 2 列)：[2,4,2,2]
- (第 3 行, 第 2 列)：[2,4,2,2]
 

提示：

n == grid.length == grid[i].length
1 <= n <= 200
1 <= grid[i][j] <= 105

来源：力扣（LeetCode）
链接：https://leetcode.cn/problems/equal-row-and-column-pairs
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <unordered_map>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int equalPairs(vector<vector<int>>& grid) {
        int n = grid.size();
        unordered_map<int, vector<int>> rowSums, columnSums;

        getRowSums(n, grid, rowSums);
        getColumnSums(n, grid, columnSums);

        return getEqualPairs(n, grid, rowSums, columnSums);
    }

    void getRowSums(int n, vector<vector<int>>& grid, unordered_map<int, vector<int>>& rowSums) {
        for (int i = 0; i < n; ++i) {
            int sum = 0;

            for (int j = 0; j < n; ++j) {
                sum += grid[i][j];
            }

            rowSums[sum].push_back(i);
        }
    }

    void getColumnSums(int n, vector<vector<int>>& grid, unordered_map<int, vector<int>>& columnSums) {
        for (int j = 0; j < n; ++j) {
            int sum = 0;

            for (int i = 0; i < n; ++i) {
                sum += grid[i][j];
            }

            columnSums[sum].push_back(j);
        }
    }

    int getEqualPairs(int n, vector<vector<int>>& grid, unordered_map<int, vector<int>>& rowSums, unordered_map<int, vector<int>>& columnSums) {
        int pairs = 0;

        for (auto& kv : rowSums) {
            for (int row : kv.second) {
                for (int column : columnSums[kv.first]) {
                    if (equal(n, grid, row, column)) {
                        ++pairs;
                    }
                }
            }
        }

        return pairs;
    }

    bool equal(int n, vector<vector<int>>& grid, int row, int column) {
        for (int i = 0; i < n; ++i) {
            if (grid[row][i] != grid[i][column]) {
                return false;
            }
        }

        return true;
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<vector<int>> grid = { {3,2,1},{1,7,6},{2,7,7} };
    check.checkInt(1, o.equalPairs(grid));

    grid = { {3,1,2,2},{1,4,4,5},{2,4,2,2},{2,4,2,2} };
    check.checkInt(3, o.equalPairs(grid));

    grid = { {3} };
    check.checkInt(1, o.equalPairs(grid));

    grid = { {3,3},{3,3} };
    check.checkInt(4, o.equalPairs(grid));
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
