/* 判断单词是否能放入填字游戏内.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你一个 m x n 的矩阵 board ，它代表一个填字游戏 当前 的状态。填字游戏格子中包含小写英文字母（已填入的单词），表示 空 格的 ' ' 和表示 障碍 格子的 '#' 。

如果满足以下条件，那么我们可以 水平 （从左到右 或者 从右到左）或 竖直 （从上到下 或者 从下到上）填入一个单词：

该单词不占据任何 '#' 对应的格子。
每个字母对应的格子要么是 ' ' （空格）要么与 board 中已有字母 匹配 。
如果单词是 水平 放置的，那么该单词左边和右边 相邻 格子不能为 ' ' 或小写英文字母。
如果单词是 竖直 放置的，那么该单词上边和下边 相邻 格子不能为 ' ' 或小写英文字母。
给你一个字符串 word ，如果 word 可以被放入 board 中，请你返回 true ，否则请返回 false 。

 

示例 1：



输入：board = [["#", " ", "#"], [" ", " ", "#"], ["#", "c", " "]], word = "abc"
输出：true
解释：单词 "abc" 可以如上图放置（从上往下）。
示例 2：



输入：board = [[" ", "#", "a"], [" ", "#", "c"], [" ", "#", "a"]], word = "ac"
输出：false
解释：无法放置单词，因为放置该单词后上方或者下方相邻格会有空格。
示例 3：



输入：board = [["#", " ", "#"], [" ", " ", "#"], ["#", " ", "c"]], word = "ca"
输出：true
解释：单词 "ca" 可以如上图放置（从右到左）。
 

提示：

m == board.length
n == board[i].length
1 <= m * n <= 2 * 105
board[i][j] 可能为 ' ' ，'#' 或者一个小写英文字母。
1 <= word.length <= max(m, n)
word 只包含小写英文字母。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/check-if-word-can-be-placed-in-crossword
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    bool placeWordInCrossword(vector<vector<char>>& board, string word) {
        return checkAllRows(board, word) || checkAllColumns(board, word);
    }

    bool checkAllRows(vector<vector<char>>& board, string& word) {
        int i, j, row = board.size(), column = board[0].size(), size = word.size();

        for (i = 0; i < row; ++i) {
            int prev = -1;

            for (j = 0; j < column; ++j) {
                if (board[i][j] != '#') {
                    continue;
                }

                if (j - prev == size + 1 && checkRow(board, i, prev + 1, word)) {  // 两个#之间的长度是size才开始检查
                    return true;
                }

                prev = j;
            }

            if (prev == column - size - 1 && checkRow(board, i, prev + 1, word)) {  // column位置的#
                return true;
            }
        }

        return false;
    }

    bool checkAllColumns(vector<vector<char>>& board, string& word) {
        int i, j, row = board.size(), column = board[0].size(), size = word.size();

        for (j = 0; j < column; ++j) {
            int prev = -1;

            for (i = 0; i < row; ++i) {
                if (board[i][j] != '#') {
                    continue;
                }

                if (i - prev == size + 1 && checkColumn(board, prev + 1, j, word)) {  // 两个#之间的长度是size才开始检查
                    return true;
                }

                prev = i;
            }

            if (prev == row - size - 1 && checkColumn(board, prev + 1, j, word)) {  // row位置的#
                return true;
            }
        }

        return false;
    }

    bool checkRow(vector<vector<char>>& board, int row, int column, string& word) {
        return checkLeftRight(board, row, column, word) || checkRightLeft(board, row, column + word.size() - 1, word);
    }

    bool checkLeftRight(vector<vector<char>>& board, int row, int column, string& word) {
        for (int j = 0; j < (int)word.size(); ++j) {
            if (board[row][column + j] != word[j] && board[row][column + j] != ' ') {
                return false;
            }
        }

        return true;
    }

    bool checkRightLeft(vector<vector<char>>& board, int row, int column, string& word) {
        for (int j = 0; j < (int)word.size(); ++j) {
            if (board[row][column - j] != word[j] && board[row][column - j] != ' ') {
                return false;
            }
        }

        return true;
    }

    bool checkColumn(vector<vector<char>>& board, int row, int column, string& word) {
        return checkUpDown(board, row, column, word) || checkDownUp(board, row + word.size() - 1, column, word);
    }

    bool checkUpDown(vector<vector<char>>& board, int row, int column, string& word) {
        for (int i = 0; i < (int)word.size(); ++i) {
            if (board[row + i][column] != word[i] && board[row + i][column] != ' ') {
                return false;
            }
        }

        return true;
    }

    bool checkDownUp(vector<vector<char>>& board, int row, int column, string& word) {
        for (int i = 0; i < (int)word.size(); ++i) {
            if (board[row - i][column] != word[i] && board[row - i][column] != ' ') {
                return false;
            }
        }

        return true;
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<vector<char>> board = { {'#',' ','#'},{' ',' ','#'},{'#','c',' '} };
    check.checkBool(true, o.placeWordInCrossword(board, "abc"));

    board = { {' ','#','a'},{' ','#','c'},{' ','#','a'} };
    check.checkBool(false, o.placeWordInCrossword(board, "ac"));

    board = { {'#',' ','#'},{' ',' ','#'},{'#',' ','c'} };
    check.checkBool(true, o.placeWordInCrossword(board, "ca"));

    board = { {'#'} };
    check.checkBool(false, o.placeWordInCrossword(board, "z"));

    board = { {'a'} };
    check.checkBool(false, o.placeWordInCrossword(board, "z"));

    board = { {'z'} };
    check.checkBool(true, o.placeWordInCrossword(board, "z"));

    board = { {' '} };
    check.checkBool(true, o.placeWordInCrossword(board, "z"));
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
