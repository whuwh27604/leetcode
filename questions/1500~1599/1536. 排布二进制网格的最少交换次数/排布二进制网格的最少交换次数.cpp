/* 排布二进制网格的最少交换次数.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你一个 n x n 的二进制网格 grid，每一次操作中，你可以选择网格的 相邻两行 进行交换。

一个符合要求的网格需要满足主对角线以上的格子全部都是 0 。

请你返回使网格满足要求的最少操作次数，如果无法使网格符合要求，请你返回 -1 。

主对角线指的是从 (1, 1) 到 (n, n) 的这些格子。

 

示例 1：



输入：grid = [[0,0,1],[1,1,0],[1,0,0]]
输出：3
示例 2：



输入：grid = [[0,1,1,0],[0,1,1,0],[0,1,1,0],[0,1,1,0]]
输出：-1
解释：所有行都是一样的，交换相邻行无法使网格符合要求。
示例 3：



输入：grid = [[1,0,0],[1,1,0],[1,1,1]]
输出：0
 

提示：

n == grid.length
n == grid[i].length
1 <= n <= 200
grid[i][j] 要么是 0 要么是 1 。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/minimum-swaps-to-arrange-a-binary-grid
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int minSwaps(vector<vector<int>>& grid) {
        int i, j, n = grid.size(), swaps = 0;
        vector<int> zeros(n);

        for (i = 0; i < n; ++i) {
            for (j = n - 1; j >= 0 && grid[i][j] == 0; --j) {}
            zeros[i] = n - 1 - j;
        }

        for (i = 0; i < n; ++i) {
            int wanted = n - 1 - i;  // 第i行至少需要n - 1 - i个零
            if (zeros[i] >= wanted) {  // 已经满足要求
                continue;
            }

            for (j = i + 1; j < n && zeros[j] < wanted; ++j) {}  // 向下查找第一个满足要求的行
            if (j == n) {  // 没找到，无法满足要求
                return -1;
            }

            swaps += (j - i);
            for (; j > i; --j) {  // 把找到的这一行，上移到第i行
                swap(zeros[j - 1], zeros[j]);
            }
        }

        return swaps;
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<vector<int>> grid = { {0,0,1},{1,1,0},{1,0,0} };
    check.checkInt(3, o.minSwaps(grid));

    grid = { {0,1,1,0},{0,1,1,0},{0,1,1,0},{0,1,1,0} };
    check.checkInt(-1, o.minSwaps(grid));

    grid = { {1,0,0},{1,1,0},{1,1,1} };
    check.checkInt(0, o.minSwaps(grid));

    grid = { {1} };
    check.checkInt(0, o.minSwaps(grid));

    grid = { {1,1,1,1,1,1,0},{1,1,1,1,1,0,0},{1,1,1,1,0,0,0},{1,1,1,0,0,0,0},{1,1,0,0,0,0,0},{1,0,0,0,0,0,0},{0,0,0,0,0,0,0} };
    check.checkInt(15, o.minSwaps(grid));
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
