/* 被围绕的区域.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给定一个二维的矩阵，包含 'X' 和 'O'（字母 O）。

找到所有被 'X' 围绕的区域，并将这些区域里所有的 'O' 用 'X' 填充。

示例:

X X X X
X O O X
X X O X
X O X X
运行你的函数后，矩阵变为：

X X X X
X X X X
X X X X
X O X X
解释:

被围绕的区间不会存在于边界上，换句话说，任何边界上的 'O' 都不会被填充为 'X'。 任何不在边界上，或不与边界上的 'O' 相连的 'O' 最终都会被填充为 'X'。如果两个元素在水平或垂直方向相邻，则称它们是“相连”的。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/surrounded-regions
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <queue>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    void solve(vector<vector<char>>& board) {
        if (board.empty() || board[0].empty()) {
            return;
        }

        int i, j, row = board.size(), column = board[0].size();

        for (j = 0; j < column; j++) {
            if (board[0][j] == 'O') {
                BFS(board, { 0, j });
            }
            if (board[row - 1][j] == 'O') {
                BFS(board, { row - 1, j });
            }
        }

        for (i = 1; i < row - 1; i++) {
            if (board[i][0] == 'O') {
                BFS(board, { i, 0 });
            }
            if (board[i][column - 1] == 'O') {
                BFS(board, { i, column - 1 });
            }
        }

        for (i = 0; i < row; i++) {
            for (j = 0; j < column; j++) {
                if (board[i][j] == 'O') {
                    board[i][j] = 'X';
                }
                else if (board[i][j] == 'P') {
                    board[i][j] = 'O';
                }
            }
        }
    }

    void BFS(vector<vector<char>>& board, pair<int, int> original) {
        int dx[4] = { 0,1,0,-1 }, dy[4] = { 1,0,-1,0 };
        int row = board.size(), column = board[0].size();
        queue<pair<int, int>> points;
        board[original.first][original.second] = 'P';
        points.push(original);

        while (!points.empty()) {
            pair<int, int> point = points.front();
            points.pop();

            for (int i = 0; i < 4; i++) {
                pair<int, int> next = { point.first + dx[i], point.second + dy[i] };
                if ((next.first >= 0) && (next.first < row) && (next.second >= 0) && (next.second < column) && (board[next.first][next.second] == 'O')) {
                    board[next.first][next.second] = 'P';
                    points.push(next);
                }
            }
        }
    }
};

int main()
{
    Solution o;
    CheckResult check;

    vector<vector<char>> board = {};
    o.solve(board);
    vector<vector<char>> expected = {};
    check.checkCharVectorVector(expected, board);

    board = { {} };
    o.solve(board);
    expected = { {} };
    check.checkCharVectorVector(expected, board);

    board = { {'X'} };
    o.solve(board);
    expected = { {'X'} };
    check.checkCharVectorVector(expected, board);

    board = { {'O'} };
    o.solve(board);
    expected = { {'O'} };
    check.checkCharVectorVector(expected, board);

    board = { {'X','O','X'} };
    o.solve(board);
    expected = { {'X','O','X'} };
    check.checkCharVectorVector(expected, board);

    board = { {'X','X','X','X'},{'X','O','O','X'},{'X','X','O','X'},{'X','O','X','X'} };
    o.solve(board);
    expected = { {'X','X','X','X'},{'X','X','X','X'},{'X','X','X','X'},{'X','O','X','X'} };
    check.checkCharVectorVector(expected, board);

    board = { {'X','X','X','X','X'},{'X','O','O','X','O'},{'O','X','O','X','X'},{'X','O','X','X','X'} };
    o.solve(board);
    expected = { {'X','X','X','X','X'},{'X','X','X','X','O'},{'O','X','X','X','X'},{'X','O','X','X','X'} };
    check.checkCharVectorVector(expected, board);

    board = { {'O','O','O'},{'O','O','O'},{'O','O','O'} };
    o.solve(board);
    expected = { {'O','O','O'},{'O','O','O'},{'O','O','O'} };
    check.checkCharVectorVector(expected, board);
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
