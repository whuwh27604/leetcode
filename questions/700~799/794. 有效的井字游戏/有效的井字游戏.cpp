/* 有效的井字游戏.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
用字符串数组作为井字游戏的游戏板 board。当且仅当在井字游戏过程中，玩家有可能将字符放置成游戏板所显示的状态时，才返回 true。

该游戏板是一个 3 x 3 数组，由字符 " "，"X" 和 "O" 组成。字符 " " 代表一个空位。

以下是井字游戏的规则：

玩家轮流将字符放入空位（" "）中。
第一个玩家总是放字符 “X”，且第二个玩家总是放字符 “O”。
“X” 和 “O” 只允许放置在空位中，不允许对已放有字符的位置进行填充。
当有 3 个相同（且非空）的字符填充任何行、列或对角线时，游戏结束。
当所有位置非空时，也算为游戏结束。
如果游戏结束，玩家不允许再放置字符。
示例 1:
输入: board = ["O  ", "   ", "   "]
输出: false
解释: 第一个玩家总是放置“X”。

示例 2:
输入: board = ["XOX", " X ", "   "]
输出: false
解释: 玩家应该是轮流放置的。

示例 3:
输入: board = ["XXX", "   ", "OOO"]
输出: false

示例 4:
输入: board = ["XOX", "O O", "XOX"]
输出: true
说明:

游戏板 board 是长度为 3 的字符串数组，其中每个字符串 board[i] 的长度为 3。
 board[i][j] 是集合 {" ", "X", "O"} 中的一个字符。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/valid-tic-tac-toe-state
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    bool validTicTacToe(vector<string>& board) {
        int xCount = countLetters(board, 'X'), oCount = countLetters(board, 'O');
        int xLines = countLines(board, 'X'), oLines = countLines(board, 'O');

        return (((xCount == oCount) && (xLines == 0)) || ((xCount == oCount + 1) && (oLines == 0)));
    }

    int countLetters(vector<string>& board, char letter) {
        int i, j, count = 0;

        for (i = 0; i < 3; i++) {
            for (j = 0; j < 3; j++) {
                if (board[i][j] == letter) {
                    count++;
                }
            }
        }

        return count;
    }

    int countLines(vector<string>& board, char letter) {
        int i, count = 0;

        for (i = 0; i < 3; i++) {
            if ((board[i][0] == letter) && (board[i][1] == letter) && (board[i][2] == letter)) {
                count++;
            }

            if ((board[0][i] == letter) && (board[1][i] == letter) && (board[2][i] == letter)) {
                count++;
            }
        }

        if ((board[0][0] == letter) && (board[1][1] == letter) && (board[2][2] == letter)) {
            count++;
        }

        if ((board[0][2] == letter) && (board[1][1] == letter) && (board[2][0] == letter)) {
            count++;
        }

        return count;
    }
};

int main()
{
    Solution o;
    CheckResult check;

    vector<string> board = { "O  ","   ","   " };
    check.checkBool(false, o.validTicTacToe(board));

    board = { "XOX"," X ","   " };
    check.checkBool(false, o.validTicTacToe(board));

    board = { "XXX","   ","OOO" };
    check.checkBool(false, o.validTicTacToe(board));

    board = { "XOX","O O","XOX" };
    check.checkBool(true, o.validTicTacToe(board));
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
