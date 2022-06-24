/* 变为棋盘.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
一个 n x n 的二维网络 board 仅由 0 和 1 组成 。每次移动，你能任意交换两列或是两行的位置。

返回 将这个矩阵变为  “棋盘”  所需的最小移动次数 。如果不存在可行的变换，输出 -1。

“棋盘” 是指任意一格的上下左右四个方向的值均与本身不同的矩阵。

 

示例 1:



输入: board = [[0,1,1,0],[0,1,1,0],[1,0,0,1],[1,0,0,1]]
输出: 2
解释:一种可行的变换方式如下，从左到右：
第一次移动交换了第一列和第二列。
第二次移动交换了第二行和第三行。
示例 2:



输入: board = [[0, 1], [1, 0]]
输出: 0
解释: 注意左上角的格值为0时也是合法的棋盘，也是合法的棋盘.
示例 3:



输入: board = [[1, 0], [1, 0]]
输出: -1
解释: 任意的变换都不能使这个输入变为合法的棋盘。
 

提示：

n == board.length
n == board[i].length
2 <= n <= 30
board[i][j] 将只包含 0或 1

来源：力扣（LeetCode）
链接：https://leetcode.cn/problems/transform-to-chessboard
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <algorithm>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int movesToChessboard(vector<vector<int>>& board) {
        int n = board.size(), minMoves = INT_MAX;
        vector<int> boardBits, rMoved, cMoved;

        toBits(board, boardBits);

        for (int rFirst = 0; rFirst < 2; ++rFirst) {
            int rMoves = moveRow(n, rFirst, boardBits, rMoved);

            if (rMoves != -1) {
                for (int cFirst = 0; cFirst < 2; ++cFirst) {
                    int cMoves = moveColumn(n, cFirst, rMoved, cMoved);

                    if (cMoves != -1 && check(n, cFirst, cMoved)) {
                        minMoves = min(minMoves, rMoves + cMoves);
                    }
                }
            }
        }

        return minMoves == INT_MAX ? -1 : minMoves;
    }

    void toBits(vector<vector<int>>& board, vector<int>& boardBits) {
        for (auto& row : board) {
            int bits = 0;

            for (int bit : row) {
                bits = ((bits << 1) | bit);
            }

            boardBits.push_back(bits);
        }
    }

    int moveRow(int n, int first, vector<int> boardBits, vector<int>& rMoved) {
        vector<int> move1, move2;

        for (int i = 0, wanted = first; i < n; ++i, wanted ^= 1) {
            if ((boardBits[i] & 1) != wanted) {
                if (i % 2 == 0) {
                    move1.push_back(i);
                }
                else {
                    move2.push_back(i);
                }
            }
        }

        if (move1.size() == move2.size()) {
            for (int i = 0; i < (int)move1.size(); ++i) {
                swap(boardBits[move1[i]], boardBits[move2[i]]);
            }

            rMoved = boardBits;
            return move1.size();
        }

        return -1;
    }

    int moveColumn(int n, int first, vector<int> boardBits, vector<int>& cMoved) {
        vector<int> move1, move2;

        for (int i = 0, bit = 1, wanted = first; i < n; ++i, bit <<= 1, wanted ^= 1) {
            if (!((wanted == 0 && (boardBits[0] & bit) == 0) || (wanted == 1 && (boardBits[0] & bit) != 0))) {
                if (i % 2 == 0) {
                    move1.push_back(bit);
                }
                else {
                    move2.push_back(bit);
                }
            }
        }

        if (move1.size() == move2.size()) {
            for (int i = 0; i < (int)move1.size(); ++i) {
                for (int j = 0; j < n; ++j) {
                    boardBits[j] ^= move1[i];
                    boardBits[j] ^= move2[i];
                }
            }

            cMoved = boardBits;
            return move1.size();
        }

        return -1;
    }

    bool check(int n, int first, vector<int>& boardBits) {
        for (int i = 0, rWanted = first; i < n; ++i, rWanted ^= 1) {
            for (int bit = 1, cWanted = rWanted; bit < (1 << n); bit <<= 1, cWanted ^= 1) {
                if ((cWanted == 0 && (boardBits[i] & bit) != 0) || (cWanted == 1 && (boardBits[i] & bit) == 0)) {
                    return false;
                }
            }
        }

        return true;
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<vector<int>> board = { {1,0},{1,0} };
    check.checkInt(-1, o.movesToChessboard(board));

    board = { {0,1},{1,0} };
    check.checkInt(0, o.movesToChessboard(board));

    board = { {0,1,1,0},{0,1,1,0},{1,0,0,1},{1,0,0,1} };
    check.checkInt(2, o.movesToChessboard(board));

    board = { {1,1,0},{0,0,1},{0,0,1} };
    check.checkInt(2, o.movesToChessboard(board));

    board = { {1,0,1,1,0},{1,0,1,1,0},{1,0,1,1,0},{0,1,0,0,1},{0,1,0,0,1} };
    check.checkInt(2, o.movesToChessboard(board));
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
