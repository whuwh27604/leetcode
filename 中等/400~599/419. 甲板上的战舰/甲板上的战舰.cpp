/*给定一个二维的甲板， 请计算其中有多少艘战舰。 战舰用 'X'表示，空位用 '.'表示。 你需要遵守以下规则：

给你一个有效的甲板，仅由战舰或者空位组成。
战舰只能水平或者垂直放置。换句话说,战舰只能由 1xN (1 行, N 列)组成，或者 Nx1 (N 行, 1 列)组成，其中N可以是任意大小。
两艘战舰之间至少有一个水平或垂直的空位分隔 - 即没有相邻的战舰。
示例 :

X..X
...X
...X
在上面的甲板中有2艘战舰。

无效样例 :

...X
XXXX
...X
你不会收到这样的无效甲板 - 因为战舰之间至少会有一个空位将它们分开。

进阶:

你可以用一次扫描算法，只使用O(1)额外空间，并且不修改甲板的值来解决这个问题吗？

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/battleships-in-a-board
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。 甲板上的战舰.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int countBattleships(vector<vector<char>>& board) {
        if ((board.empty()) || board[0].empty()) {
            return 0;
        }

        int i, j, row = board.size(), column = board[0].size(), count = 0;

        for (i = 0; i < row; i++) {
            for (j = 0; j < column; j++) {
                if (board[i][j] == '.') {
                    continue;
                }

                if (((j == column - 1) || (board[i][j + 1] == '.')) && ((i == row - 1) || (board[i + 1][j] == '.'))) {
                    count++;
                }
            }
        }

        return count;
    }
};

int main()
{
    Solution o;
    CheckResult check;

    vector<vector<char>> board = {};
    check.checkInt(0, o.countBattleships(board));

    board = { {} };
    check.checkInt(0, o.countBattleships(board));

    board = { {'X','.','.','X'},{'.','.','.','X'},{'.','.','.','X'} };
    check.checkInt(2, o.countBattleships(board));

    board = { {'X'} };
    check.checkInt(1, o.countBattleships(board));

    board = { {'.','X','.'} };
    check.checkInt(1, o.countBattleships(board));

    board = { {'X','X','X','X'} };
    check.checkInt(1, o.countBattleships(board));

    board = { {'.','X'},{'.','X'},{'.','X'} };
    check.checkInt(1, o.countBattleships(board));

    board = { {'X'},{'X'},{'X'} };
    check.checkInt(1, o.countBattleships(board));

    board = { {'X','X','X','.','X','.','.','.','.','X'},
              {'.','.','.','.','X','.','X','X','.','X'}, 
              {'.','.','X','.','.','X','.','.','.','X'}, 
              {'.','.','X','.','.','X','.','X','.','.'}, 
              {'X','.','X','.','.','.','.','.','X','X'}, };
    check.checkInt(9, o.countBattleships(board));
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
