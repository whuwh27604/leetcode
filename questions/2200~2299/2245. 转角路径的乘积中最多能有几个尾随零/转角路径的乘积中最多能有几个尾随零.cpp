// 转角路径的乘积中最多能有几个尾随零.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <algorithm>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int maxTrailingZeros(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> factors2(m, vector<int>(n, 0)), factors5(m, vector<int>(n, 0));
        vector<vector<int>> rowPresums2(m, vector<int>(n, 0)), columnPresums2(m, vector<int>(n, 0)), rowPresums5(m, vector<int>(n, 0)), columnPresums5(m, vector<int>(n, 0));

        getFactors(grid, factors2, factors5);
        getRowPresums(factors2, rowPresums2);
        getRowPresums(factors5, rowPresums5);
        getColumnPresums(factors2, columnPresums2);
        getColumnPresums(factors5, columnPresums5);

        return getMaxZeros(rowPresums2, columnPresums2, rowPresums5, columnPresums5);
    }

    void getFactors(vector<vector<int>>& grid, vector<vector<int>>& factors2, vector<vector<int>>& factors5) {
        int r, c, m = grid.size(), n = grid[0].size();

        for (r = 0; r < m; ++r) {
            for (c = 0; c < n; ++c) {
                factors2[r][c] = countFactor(grid[r][c], 2);
                factors5[r][c] = countFactor(grid[r][c], 5);
            }
        }
    }

    int countFactor(int num, int factor) {
        int count = 0;

        while (num != 0 && num % factor == 0) {
            count += 1;
            num /= factor;
        }

        return count;
    }

    void getRowPresums(vector<vector<int>>& factors, vector<vector<int>>& presums) {
        int r, c, m = factors.size(), n = factors[0].size();

        for (r = 0; r < m; ++r) {
            presums[r][0] = factors[r][0];

            for (c = 1; c < n; ++c) {
                presums[r][c] = factors[r][c] + presums[r][c - 1];
            }
        }
    }

    void getColumnPresums(vector<vector<int>>& factors, vector<vector<int>>& presums) {
        int r, c, m = factors.size(), n = factors[0].size();

        for (c = 0; c < n; ++c) {
            presums[0][c] = factors[0][c];

            for (r = 1; r < m; ++r) {
                presums[r][c] = factors[r][c] + presums[r - 1][c];
            }
        }
    }

    int getMaxZeros(vector<vector<int>>& rowPresums2, vector<vector<int>>& columnPresums2, vector<vector<int>>& rowPresums5, vector<vector<int>>& columnPresums5) {
        int r, c, m = rowPresums2.size(), n = rowPresums2[0].size(), maxZeros = 0;

        for (r = 0; r < m; ++r) {
            for (c = 0; c < n; ++c) {
                int f2Row1 = rowPresums2[r][c], f2Row2 = (c == 0 ? rowPresums2[r][n - 1] : rowPresums2[r][n - 1] - rowPresums2[r][c - 1]);
                int f2Column1 = r == 0 ? 0 : columnPresums2[r - 1][c], f2Column2 = columnPresums2[m - 1][c] - columnPresums2[r][c];
                int f5Row1 = rowPresums5[r][c], f5Row2 = (c == 0 ? rowPresums5[r][n - 1] : rowPresums5[r][n - 1] - rowPresums5[r][c - 1]);
                int f5Column1 = r == 0 ? 0 : columnPresums5[r - 1][c], f5Column2 = columnPresums5[m - 1][c] - columnPresums5[r][c];
                maxZeros = max(maxZeros, min(f2Row1 + f2Column1, f5Row1 + f5Column1));
                maxZeros = max(maxZeros, min(f2Row1 + f2Column2, f5Row1 + f5Column2));
                maxZeros = max(maxZeros, min(f2Row2 + f2Column1, f5Row2 + f5Column1));
                maxZeros = max(maxZeros, min(f2Row2 + f2Column2, f5Row2 + f5Column2));
            }
        }

        return maxZeros;
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<vector<int>> grid = { {23,17,15,3,20},{8,1,20,27,11},{9,4,6,2,21},{40,9,1,10,6},{22,7,4,5,3} };
    check.checkInt(3, o.maxTrailingZeros(grid));

    grid = { {4,3,2},{7,6,1},{8,8,8} };
    check.checkInt(0, o.maxTrailingZeros(grid));

    grid = { {1,5,2,4,25} };
    check.checkInt(3, o.maxTrailingZeros(grid));

    grid = { {10} };
    check.checkInt(1, o.maxTrailingZeros(grid));

    grid = { {824,709,193,413,701,836,727},{135,844,599,211,140,933,205},{329,68,285,282,301,387,231},{293,210,478,352,946,902,137},{806,900,290,636,589,522,611},{450,568,990,592,992,128,92},{780,653,795,457,980,942,927},{849,901,604,906,912,866,688} };
    check.checkInt(6, o.maxTrailingZeros(grid));
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
