/* 水域大小.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
你有一个用于表示一片土地的整数矩阵land，该矩阵中每个点的值代表对应地点的海拔高度。若值为0则表示水域。由垂直、水平或对角连接的水域为池塘。池塘的大小是指相连接的水域的个数。编写一个方法来计算矩阵中所有池塘的大小，返回值需要从小到大排序。

示例：

输入：
[
  [0,2,1,0],
  [0,1,0,1],
  [1,1,0,1],
  [0,1,0,1]
]
输出： [1,2,4]
提示：

0 < len(land) <= 1000
0 < len(land[i]) <= 1000
*/

#include <iostream>
#include <algorithm>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    vector<int> pondSizes(vector<vector<int>>& land) {
        int row = land.size(), column = land[0].size();
        vector<int> sizes;

        for (int r = 0; r < row; ++r) {
            for (int c = 0; c < column; ++c) {
                if (land[r][c] == 0) {
                    sizes.push_back(DFS(land, r, c));
                }
            }
        }

        sort(sizes.begin(), sizes.end());

        return sizes;
    }

    int DFS(vector<vector<int>>& land, int r, int c) {
        int row = land.size(), column = land[0].size();
        int size = 1;
        land[r][c] = 1;

        for (int i = 0; i < 8; ++i) {
            int nr = r + dr[i], nc = c + dc[i];
            if (nr >= 0 && nr < row && nc >= 0 && nc < column && land[nr][nc] == 0) {
                size += DFS(land, nr, nc);
            }
        }

        return size;
    }

    int dr[8] = { 0,1,1,1,0,-1,-1,-1 };
    int dc[8] = { 1,1,0,-1,-1,-1,0,1 };
};

int main()
{
    CheckResult check;
    Solution o;

    vector<vector<int>> land = { {0,2,1,0},{0,1,0,1},{1,1,0,1},{0,1,0,1} };
    vector<int> actual = o.pondSizes(land);
    vector<int> expected = { 1,2,4 };
    check.checkIntVector(expected, actual);
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
