/* 转化为全零矩阵的最少反转次数.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你一个 m x n 的二进制矩阵 mat。

每一步，你可以选择一个单元格并将它反转（反转表示 0 变 1 ，1 变 0 ）。如果存在和它相邻的单元格，那么这些相邻的单元格也会被反转。（注：相邻的两个单元格共享同一条边。）

请你返回将矩阵 mat 转化为全零矩阵的最少反转次数，如果无法转化为全零矩阵，请返回 -1 。

二进制矩阵的每一个格子要么是 0 要么是 1 。

全零矩阵是所有格子都为 0 的矩阵。

 

示例 1：



输入：mat = [[0,0],[0,1]]
输出：3
解释：一个可能的解是反转 (1, 0)，然后 (0, 1) ，最后是 (1, 1) 。
示例 2：

输入：mat = [[0]]
输出：0
解释：给出的矩阵是全零矩阵，所以你不需要改变它。
示例 3：

输入：mat = [[1,1,1],[1,0,1],[0,0,0]]
输出：6
示例 4：

输入：mat = [[1,0,0],[1,0,0]]
输出：-1
解释：该矩阵无法转变成全零矩阵
 

提示：

m == mat.length
n == mat[0].length
1 <= m <= 3
1 <= n <= 3
mat[i][j] 是 0 或 1 。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/minimum-number-of-flips-to-convert-binary-matrix-to-zero-matrix
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <queue>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int minFlips(vector<vector<int>>& mat) {
        int m = mat.size(), n = mat[0].size(), all = m * n, flips = 0;

        vector<vector<int>> adjs(all);
        getAdjs(m, n, adjs);

        int node = init(m, n, mat);
        queue<int> bfs;
        bfs.push(node);

        vector<bool> visited(1 << all, false);
        visited[node] = true;

        while (!bfs.empty()) {
            int i, size = bfs.size();

            for (i = 0; i < size; ++i) {
                node = bfs.front();
                bfs.pop();

                if (node == 0) {
                    return flips;
                }

                for (int index = 0, bit = 1; index < all; ++index, bit <<= 1) {  // 尝试所有位置
                    int next = node;
                    next ^= bit;  // 翻转该位置

                    for (int adj : adjs[index]) {
                        next ^= adj;  // 同时翻转和该位置邻接的位置
                    }

                    if (!visited[next]) {
                        visited[next] = true;
                        bfs.push(next);
                    }
                }
            }
            
            ++flips;
        }

        return -1;
    }

    int init(int m, int n, vector<vector<int>>& mat) {
        int i, j, bit = 1, node = 0;

        for (i = 0; i < m; ++i) {
            for (j = 0; j < n; ++j) {
                if (mat[i][j] == 1) {
                    node |= bit;
                }

                bit <<= 1;
            }
        }

        return node;
    }

    void getAdjs(int m, int n, vector<vector<int>>& adjs) {
        int i, j, k, index = 0;
        int dr[4] = { 0,1,0,-1 }, dc[4] = { 1,0,-1,0 };

        for (i = 0; i < m; ++i) {
            for (j = 0; j < n; ++j) {
                for (k = 0; k < 4; ++k) {
                    int r = i + dr[k], c = j + dc[k];

                    if (r >= 0 && r < m && c >= 0 && c < n) {
                        adjs[index].push_back(1 << (r * n + c));
                    }
                }

                ++index;
            }
        }
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<vector<int>> mat = { {0,0},{0,1} };
    check.checkInt(3, o.minFlips(mat));

    mat = { {0} };
    check.checkInt(0, o.minFlips(mat));

    mat = { {1} };
    check.checkInt(1, o.minFlips(mat));

    mat = { {1,1,1},{1,0,1},{0,0,0} };
    check.checkInt(6, o.minFlips(mat));

    mat = { {1,0,0},{1,0,0} };
    check.checkInt(-1, o.minFlips(mat));
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
