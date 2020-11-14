/* 扫雷游戏.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
让我们一起来玩扫雷游戏！

给定一个代表游戏板的二维字符矩阵。 'M' 代表一个未挖出的地雷，'E' 代表一个未挖出的空方块，'B' 代表没有相邻（上，下，左，右，和所有4个对角线）地雷的已挖出的空白方块，数字（'1' 到 '8'）表示有多少地雷与这块已挖出的方块相邻，'X' 则表示一个已挖出的地雷。

现在给出在所有未挖出的方块中（'M'或者'E'）的下一个点击位置（行和列索引），根据以下规则，返回相应位置被点击后对应的面板：

如果一个地雷（'M'）被挖出，游戏就结束了- 把它改为 'X'。
如果一个没有相邻地雷的空方块（'E'）被挖出，修改它为（'B'），并且所有和其相邻的未挖出方块都应该被递归地揭露。
如果一个至少与一个地雷相邻的空方块（'E'）被挖出，修改它为数字（'1'到'8'），表示相邻地雷的数量。
如果在此次点击中，若无更多方块可被揭露，则返回面板。
 

示例 1：

输入:

[['E', 'E', 'E', 'E', 'E'],
 ['E', 'E', 'M', 'E', 'E'],
 ['E', 'E', 'E', 'E', 'E'],
 ['E', 'E', 'E', 'E', 'E']]

Click : [3,0]

输出:

[['B', '1', 'E', '1', 'B'],
 ['B', '1', 'M', '1', 'B'],
 ['B', '1', '1', '1', 'B'],
 ['B', 'B', 'B', 'B', 'B']]

解释:

示例 2：

输入:

[['B', '1', 'E', '1', 'B'],
 ['B', '1', 'M', '1', 'B'],
 ['B', '1', '1', '1', 'B'],
 ['B', 'B', 'B', 'B', 'B']]

Click : [1,2]

输出:

[['B', '1', 'E', '1', 'B'],
 ['B', '1', 'X', '1', 'B'],
 ['B', '1', '1', '1', 'B'],
 ['B', 'B', 'B', 'B', 'B']]

解释:

 

注意：

输入矩阵的宽和高的范围为 [1,50]。
点击的位置只能是未被挖出的方块 ('M' 或者 'E')，这也意味着面板至少包含一个可点击的方块。
输入面板不会是游戏结束的状态（即有地雷已被挖出）。
简单起见，未提及的规则在这个问题中可被忽略。例如，当游戏结束时你不需要挖出所有地雷，考虑所有你可能赢得游戏或标记方块的情况。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/minesweeper
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    vector<vector<char>> updateBoard(vector<vector<char>>& board, vector<int>& click) {
        if (board[click[0]][click[1]] == 'M') {
            board[click[0]][click[1]] = 'X';
        }
        else if (board[click[0]][click[1]] == 'E') {
            clickEmptySquare(board, click[0], click[1]);
        }

        return board;
    }

    void clickEmptySquare(vector<vector<char>>& board, int row, int column) {
        int dr[8] = { 0,1,1,1,0,-1,-1,-1 }, dc[8] = { 1,1,0,-1,-1,-1,0,1 };
        int i, r, c, sizeR = board.size(), sizeC = board[0].size(), countM = 0;

        for (i = 0; i < 8; i++) {
            r = row + dr[i];
            c = column + dc[i];

            if ((r >= 0) && (r < sizeR) && (c >= 0) && (c < sizeC) && (board[r][c] == 'M')) {
                countM++;
            }
        }

        if (countM != 0) {
            board[row][column] = countM + '0';
            return;
        }

        board[row][column] = 'B';
        for (i = 0; i < 8; i++) {
            r = row + dr[i];
            c = column + dc[i];

            if ((r >= 0) && (r < sizeR) && (c >= 0) && (c < sizeC) && (board[r][c] == 'E')) {
                clickEmptySquare(board, r, c);
            }
        }
    }
};

int main()
{
    Solution o;
    CheckResult check;

    vector<vector<char>> board = { {'E','E','E','E','E'},{'E','E','M','E','E'},{'E','E','E','E','E'},{'E','E','E','E','E'} };
    vector<int> click = { 3,0 };
    vector<vector<char>> actual = o.updateBoard(board, click);
    vector<vector<char>> expected = { {'B','1','E','1','B'},{'B','1','M','1','B'},{'B','1','1','1','B'},{'B','B','B','B','B'} };
    check.checkCharVectorVector(expected, actual);

    board = { {'B','1','E','1','B'},{'B','1','M','1','B'},{'B','1','1','1','B'},{'B','B','B','B','B'} };
    click = { 1,2 };
    actual = o.updateBoard(board, click);
    expected = { {'B','1','E','1','B'},{'B','1','X','1','B'},{'B','1','1','1','B'},{'B','B','B','B','B'} };
    check.checkCharVectorVector(expected, actual);

    board = { {'M','E','E','E'},{'E','E','E','E'},{'E','E','E','E'},{'E','E','E','M'} };
    click = { 3,0 };
    actual = o.updateBoard(board, click);
    expected = { {'M','1','B','B'},{'1','1','B','B'},{'B','B','1','1'},{'B','B','1','M'} };
    check.checkCharVectorVector(expected, actual);
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
