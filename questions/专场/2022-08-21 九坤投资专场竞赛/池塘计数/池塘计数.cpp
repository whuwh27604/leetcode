/* 池塘计数.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
最近的降雨，使田地中的一些地方出现了积水，field[i][j] 表示田地第 i 行 j 列的位置有：

若为 W, 表示该位置为积水；
若为 ., 表示该位置为旱地。
已知一些相邻的积水形成了若干个池塘，若以 W 为中心的八个方向相邻积水视为同一片池塘。

请返回田地中池塘的数量。

示例 1：

输入: field = [".....W",".W..W.","....W.",".W....","W.WWW.",".W...."]

输出：3

解释：如下图所示，共有 3 个池塘：
image.png

示例 2：

输入: field = ["W....W",".W..W.","..W.W.","W..W..","W.W...",".W...."]

输出：1

解释：如下图所示，共有 1 个池塘：
image.png

提示：

1 <= field.length, field[i].length <= 100
field 中仅包含 W 和 .
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int lakeCount(vector<string>& field) {
        int row = field.size(), column = field[0].size(), lakes = 0;
        vector<vector<bool>> visited(row, vector<bool>(column, false));

        for (int r = 0; r < row; ++r) {
            for (int c = 0; c < column; ++c) {
                if (field[r][c] == 'W' && !visited[r][c]) {
                    ++lakes;
                    DFS(r, c, field, visited);
                }
            }
        }

        return lakes;
    }

    void DFS(int r, int c, vector<string>& field, vector<vector<bool>>& visited) {
        int row = field.size(), column = field[0].size();
        int dr[8] = { 0,1,1,1,0,-1,-1,-1 }, dc[8] = { 1,1,0,-1,-1,-1,0,1 };
        visited[r][c] = true;

        for (int i = 0; i < 8; ++i) {
            int nr = r + dr[i], nc = c + dc[i];

            if (nr >= 0 && nr < row && nc >= 0 && nc < column && field[nr][nc] == 'W' && !visited[nr][nc]) {
                DFS(nr, nc, field, visited);
            }
        }
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<string> field = { ".....W",".W..W.","....W.",".W....","W.WWW.",".W...." };
    check.checkInt(3, o.lakeCount(field));

    field = { "W....W",".W..W.","..W.W.","W..W..","W.W...",".W...." };
    check.checkInt(1, o.lakeCount(field));
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
