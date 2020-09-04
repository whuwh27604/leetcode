/* 最大加号标志.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
在一个大小在 (0, 0) 到 (N-1, N-1) 的2D网格 grid 中，除了在 mines 中给出的单元为 0，其他每个单元都是 1。网格中包含 1 的最大的轴对齐加号标志是多少阶？返回加号标志的阶数。如果未找到加号标志，则返回 0。

一个 k" 阶由 1 组成的“轴对称”加号标志具有中心网格  grid[x][y] = 1 ，以及4个从中心向上、向下、向左、向右延伸，长度为 k-1，由 1 组成的臂。下面给出 k" 阶“轴对称”加号标志的示例。注意，只有加号标志的所有网格要求为 1，别的网格可能为 0 也可能为 1。

 

k 阶轴对称加号标志示例:

阶 1:
000
010
000

阶 2:
00000
00100
01110
00100
00000

阶 3:
0000000
0001000
0001000
0111110
0001000
0001000
0000000
 

示例 1：

输入: N = 5, mines = [[4, 2]]
输出: 2
解释:

11111
11111
11111
11111
11011

在上面的网格中，最大加号标志的阶只能是2。一个标志已在图中标出。
 

示例 2：

输入: N = 2, mines = []
输出: 1
解释:

11
11

没有 2 阶加号标志，有 1 阶加号标志。
 

示例 3：

输入: N = 1, mines = [[0, 0]]
输出: 0
解释:

0

没有加号标志，返回 0 。
 

提示：

整数N 的范围： [1, 500].
mines 的最大长度为 5000.
mines[i] 是长度为2的由2个 [0, N-1] 中的数组成.
(另外,使用 C, C++, 或者 C# 编程将以稍小的时间限制进行​​判断.)

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/largest-plus-sign
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <algorithm>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int orderOfLargestPlusSign(int N, vector<vector<int>>& mines) {
        vector<vector<int>> NGridMines(N + 1, vector<int>(N + 1, 1));
        placeMines(N, mines, NGridMines);

        int* arms = new int[N * N * 2]();
        createHorizontalArms(N, NGridMines, arms);
        createVerticalArms(N, NGridMines, arms);

        int i, j, longestArm = 0;
        for (i = 0; i < N; i++) {
            for (j = 0; j < N; j++) {
                longestArm = max(longestArm, min(arms[(i * N + j) * 2], arms[(i * N + j) * 2 + 1]));
            }
        }

        delete[] arms;
        return longestArm;
    }

    void placeMines(int N, vector<vector<int>>& mines, vector<vector<int>>& NGridMines) {
        for (vector<int>& mine : mines) {
            NGridMines[mine[0]][mine[1]] = 0;
        }

        for (int i = 0; i < N; i++) {
            NGridMines[i][N] = 0;  // 每行最右边添加0，便于边界处理
        }

        for (int j = 0; j < N; j++) {
            NGridMines[N][j] = 0;  // 每列最下边添加0，便于边界处理
        }
    }

    void createHorizontalArms(int N, vector<vector<int>>& NGridMines, int* arms) {
        for (int i = 0; i < N; i++) {
            int consecutiveOnes = 0;
            for (int j = 0; j <= N; j++) {
                if (NGridMines[i][j] == 1) {
                    consecutiveOnes++;
                    continue;
                }

                if (consecutiveOnes == 0) {
                    continue;
                }

                int arm = (consecutiveOnes + 1) / 2;
                int left = j - consecutiveOnes;
                for (int k = 1; k <= arm; k++) {  // 生成这段连续1中每个点的水平臂长
                    arms[(i * N + left + k - 1) * 2] = k;
                    arms[(i * N + j - k) * 2] = k;
                }

                consecutiveOnes = 0;
            }
        }
    }

    void createVerticalArms(int N, vector<vector<int>>& NGridMines, int* arms) {
        for (int j = 0; j < N; j++) {
            int consecutiveOnes = 0;
            for (int i = 0; i <= N; i++) {
                if (NGridMines[i][j] == 1) {
                    consecutiveOnes++;
                    continue;
                }

                if (consecutiveOnes == 0) {
                    continue;
                }

                int arm = (consecutiveOnes + 1) / 2;
                int up = i - consecutiveOnes;
                for (int k = 1; k <= arm; k++) {  // 生成这段连续1中每个点的垂直臂长
                    arms[((up + k - 1) * N + j) * 2 + 1] = k;
                    arms[((i - k) * N + j) * 2 + 1] = k;
                }

                consecutiveOnes = 0;
            }
        }
    }
};

int main()
{
    Solution o;
    CheckResult check;

    vector<vector<int>> mines = {};
    check.checkInt(1, o.orderOfLargestPlusSign(1, mines));
    check.checkInt(1, o.orderOfLargestPlusSign(2, mines));
    check.checkInt(2, o.orderOfLargestPlusSign(3, mines));
    check.checkInt(2, o.orderOfLargestPlusSign(4, mines));
    check.checkInt(3, o.orderOfLargestPlusSign(5, mines));
    check.checkInt(3, o.orderOfLargestPlusSign(6, mines));

    mines = { {4,2} };
    check.checkInt(2, o.orderOfLargestPlusSign(5, mines));

    mines = { {0,0} };
    check.checkInt(0, o.orderOfLargestPlusSign(1, mines));

    mines = { {3,0},{3,3} };
    check.checkInt(3, o.orderOfLargestPlusSign(5, mines));

    mines = { {1,1},{1,3},{2,2},{3,1},{3,3} };
    check.checkInt(1, o.orderOfLargestPlusSign(5, mines));
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
