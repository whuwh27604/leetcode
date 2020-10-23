/* 飞地的数量.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给出一个二维数组 A，每个单元格为 0（代表海）或 1（代表陆地）。

移动是指在陆地上从一个地方走到另一个地方（朝四个方向之一）或离开网格的边界。

返回网格中无法在任意次数的移动中离开网格边界的陆地单元格的数量。

 

示例 1：

输入：[[0,0,0,0],[1,0,1,0],[0,1,1,0],[0,0,0,0]]
输出：3
解释：
有三个 1 被 0 包围。一个 1 没有被包围，因为它在边界上。
示例 2：

输入：[[0,1,1,0],[0,0,1,0],[0,0,1,0],[0,0,0,0]]
输出：0
解释：
所有 1 都在边界上或可以到达边界。
 

提示：

1 <= A.length <= 500
1 <= A[i].length <= 500
0 <= A[i][j] <= 1
所有行的大小都相同

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/number-of-enclaves
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int numEnclaves(vector<vector<int>>& A) {
        int i, j, row = A.size(), column = A[0].size();

        for (i = 0; i < row; ++i) {
            if (A[i][0] == 1) {
                DFS(A, i, 0);
            }

            if (A[i][column - 1] == 1) {
                DFS(A, i, column - 1);
            }
        }

        for (j = 0; j < column; ++j) {
            if (A[0][j] == 1) {
                DFS(A, 0, j);
            }

            if (A[row - 1][j] == 1) {
                DFS(A, row - 1, j);
            }
        }

        return countLands(A);
    }

    void DFS(vector<vector<int>>& A, int landr, int landc) {
        int row = A.size(), column = A[0].size();
        int dr[4] = { 0,1,0,-1 }, dc[4] = { 1,0,-1,0 };
        
        A[landr][landc] = -1;

        for (int i = 0; i < 4; ++i) {
            int r = landr + dr[i], c = landc + dc[i];
            if (r >= 0 && r < row && c >= 0 && c < column && A[r][c] == 1) {
                DFS(A, r, c);
            }
        }
    }

    int countLands(vector<vector<int>>& A) {
        int i, j, row = A.size(), column = A[0].size(), lands = 0;

        for (i = 0; i < row; ++i) {
            for (j = 0; j < column; ++j) {
                if (A[i][j] == 1) {
                    ++lands;
                }
            }
        }

        return lands;
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<vector<int>> A = { {0,0,0,0},{1,0,1,0},{0,1,1,0},{0,0,0,0} };
    check.checkInt(3, o.numEnclaves(A));

    A = { {0,1,1,0},{0,0,1,0},{0,0,1,0},{0,0,0,0} };
    check.checkInt(0, o.numEnclaves(A));

    A = { {0} };
    check.checkInt(0, o.numEnclaves(A));

    A = { {1} };
    check.checkInt(0, o.numEnclaves(A));

    A = { {0,1,1,1,0},{1,1,0,1,1},{1,0,1,0,1},{1,1,0,1,1},{0,1,1,1,0} };
    check.checkInt(1, o.numEnclaves(A));
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
