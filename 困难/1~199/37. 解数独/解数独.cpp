/* 解数独.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
编写一个程序，通过已填充的空格来解决数独问题。

一个数独的解法需遵循如下规则：

数字 1-9 在每一行只能出现一次。
数字 1-9 在每一列只能出现一次。
数字 1-9 在每一个以粗实线分隔的 3x3 宫内只能出现一次。
空白格用 '.' 表示。



一个数独。



答案被标成红色。

Note:

给定的数独序列只包含数字 1-9 和字符 '.' 。
你可以假设给定的数独只有唯一解。
给定数独永远是 9x9 形式的。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/sudoku-solver
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <unordered_set>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    void solveSudoku(vector<vector<char>>& board) {
        vector<int> rows(9, 0), columns(9, 0);
        vector<vector<int>> boxes(3, vector<int>(3, 0));
        compress(board, rows, columns, boxes);
        while(infer(board, rows, columns, boxes)){}
        vector<pair<int, int>> spaces;
        getSpaces(board, spaces);

        (void)DFS(board, spaces, rows, columns, boxes);  // 题目限定有唯一解，不用处理返回值
    }

    bool DFS(vector<vector<char>>& board, vector<pair<int, int>>& spaces, vector<int>& rows, vector<int>& columns, vector<vector<int>>& boxes) {
        if (spaces.empty()) {
            return true;
        }

        int row = spaces.back().first, column = spaces.back().second;
        spaces.pop_back();
        int mask = (~(rows[row] | columns[column] | boxes[row / 3][column / 3]) & 0x1ff);  // 行列宫都没有出现的数字

        while (mask != 0) {
            int bit = mask & (-mask);  // 保留最后一个1，即尝试这个数字
            int num = my__builtin_ctz(bit);
            board[row][column] = '0' + num + 1;
            flip(row, column, num, rows, columns, boxes);

            if (DFS(board, spaces, rows, columns, boxes)) {
                return true;
            }

            flip(row, column, num, rows, columns, boxes);  // 回退，准备尝试下一个数字
            mask &= (mask - 1);  // 最后一个1已经尝试失败，关闭它
        }

        spaces.push_back({ row, column });  // 所有可选的数字都失败了，回退
        return false;
    }

    bool infer(vector<vector<char>>& board, vector<int>& rows, vector<int>& columns, vector<vector<int>>& boxes) {
        bool inferredSomeone = false;

        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                if (board[i][j] == '.') {
                    int mask = (~(rows[i] | columns[j] | boxes[i / 3][j / 3]) & 0x1ff);  // 行列宫都没有出现的数字
                    if ((mask & (mask - 1)) == 0) {  // 只有一个数没有出现过，所以可以确定它
                        int num = my__builtin_ctz(mask);
                        board[i][j] = '0' + num + 1;
                        flip(i, j, num, rows, columns, boxes);
                        inferredSomeone = true;
                    }
                }                
            }
        }

        return inferredSomeone;
    }

    void compress(vector<vector<char>>& board, vector<int>& rows, vector<int>& columns, vector<vector<int>>& boxes) {
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                if (board[i][j] != '.') {
                    flip(i, j, (board[i][j] - '0' - 1), rows, columns, boxes);
                }
            }
        }
    }

    void getSpaces(vector<vector<char>>& board, vector<pair<int, int>>& spaces) {
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                if (board[i][j] == '.') {
                    spaces.push_back({ i, j });
                }
            }
        }
    }

    void flip(int row, int column, int num, vector<int>& rows, vector<int>& columns, vector<vector<int>>& boxes) {
        rows[row] ^= (1 << num);  // 反转第num位
        columns[column] ^= (1 << num);
        boxes[row / 3][column / 3] ^= (1 << num);
    }

    int my__builtin_ctz(int mask) {
        int count = 0;

        while ((mask & 1) == 0) {
            mask >>= 1;
            count++;
        }

        return count;
    }
};

int main()
{
    Solution o;
    CheckResult check;

    vector<vector<char>> board = {
        { '5','3','.','.','7','.','.','.','.' },
        { '6','.','.','1','9','5','.','.','.' },
        { '.','9','8','.','.','.','.','6','.' },
        { '8','.','.','.','6','.','.','.','3' },
        { '4','.','.','8','.','3','.','.','1' },
        { '7','.','.','.','2','.','.','.','6' },
        { '.','6','.','.','.','.','2','8','.' },
        { '.','.','.','4','1','9','.','.','5' },
        { '.','.','.','.','8','.','.','7','9' } };
    o.solveSudoku(board);
    vector<vector<char>> expected = {
        { '5','3','4','6','7','8','9','1','2' },
        { '6','7','2','1','9','5','3','4','8' },
        { '1','9','8','3','4','2','5','6','7' },
        { '8','5','9','7','6','1','4','2','3' },
        { '4','2','6','8','5','3','7','9','1' },
        { '7','1','3','9','2','4','8','5','6' },
        { '9','6','1','5','3','7','2','8','4' },
        { '2','8','7','4','1','9','6','3','5' },
        { '3','4','5','2','8','6','1','7','9' } };
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
