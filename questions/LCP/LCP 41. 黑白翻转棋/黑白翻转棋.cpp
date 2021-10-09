/* 黑白翻转棋.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
在 n*m 大小的棋盘中，有黑白两种棋子，黑棋记作字母 "X", 白棋记作字母 "O"，空余位置记作 "."。当落下的棋子与其他相同颜色的棋子在行、列或对角线完全包围（中间不存在空白位置）另一种颜色的棋子，则可以翻转这些棋子的颜色。



「力扣挑战赛」黑白翻转棋项目中，将提供给选手一个未形成可翻转棋子的棋盘残局，其状态记作 chessboard。若下一步可放置一枚黑棋，请问选手最多能翻转多少枚白棋。

注意：

若翻转白棋成黑棋后，棋盘上仍存在可以翻转的白棋，将可以 继续 翻转白棋
输入数据保证初始棋盘状态无可以翻转的棋子且存在空余位置
示例 1：

输入：chessboard = ["....X.","....X.","XOOO..","......","......"]

输出：3

解释：
可以选择下在 [2,4] 处，能够翻转白方三枚棋子。

示例 2：

输入：chessboard = [".X.",".O.","XO."]

输出：2

解释：
可以选择下在 [2,2] 处，能够翻转白方两枚棋子。


示例 3：

输入：chessboard = [".......",".......",".......","X......",".O.....","..O....","....OOX"]

输出：4

解释：
可以选择下在 [6,3] 处，能够翻转白方四枚棋子。


提示：

1 <= chessboard.length, chessboard[i].length <= 8
chessboard[i] 仅包含 "."、"O" 和 "X"

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/fHi6rV
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <queue>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int flipChess(vector<string>& chessboard) {
        int i, j, row = chessboard.size(), column = chessboard[0].size();
        int maxFlips = 0;
        queue<int> bfs;

        for (i = 0; i < row; ++i) {
            for (j = 0; j < column; ++j) {
                if (chessboard[i][j] != '.') {
                    continue;
                }

                for (int dir = 0; dir < 8; ++dir) {
                    bfs.push((i << 16) | (j << 8) | dir);
                }

                int flips = 0;
                vector<string> copyBoard = chessboard;

                while (!bfs.empty()) {
                    int r = bfs.front() >> 16, c = (bfs.front() >> 8) & 0xff, dir = bfs.front() & 0xff, len = 0;
                    bfs.pop();

                    if (canPlace(copyBoard, r, c, dir, len)) {
                        place(copyBoard, r, c, dir, len, bfs);
                        flips += (len - 1);
                    }
                }

                maxFlips = max(maxFlips, flips);
            }
        }

        return maxFlips;
    }

    bool canPlace(vector<string>& chessboard, int r, int c, int dir, int& len) {
        int dr[8] = { 0,1,1,1,0,-1,-1,-1 }, dc[8] = { 1,1,0,-1,-1,-1,0,1 };
        int row = chessboard.size(), column = chessboard[0].size(), nr = r + dr[dir], nc = c + dc[dir];
        len = 1;

        while (nr >= 0 && nr < row && nc >= 0 && nc < column && chessboard[nr][nc] == 'O') {
            ++len;
            nr = r + dr[dir] * len, nc = c + dc[dir] * len;
        }

        return len > 1 && nr >= 0 && nr < row&& nc >= 0 && nc < column && chessboard[nr][nc] == 'X';
    }

    void place(vector<string>& chessboard, int r, int c, int dir, int len, queue<int>& bfs) {
        int dr[8] = { 0,1,1,1,0,-1,-1,-1 }, dc[8] = { 1,1,0,-1,-1,-1,0,1 };
        int row = chessboard.size(), column = chessboard[0].size();
        chessboard[r][c] = 'X';

        for (int i = 1; i < len; ++i) {
            int nr = r + dr[dir] * i, nc = c + dc[dir] * i;
            chessboard[nr][nc] = 'X';
            
            for (int j = 0; j < 8; ++j) {
                bfs.push((nr << 16) | (nc << 8) | j);
            }
        }
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<string> chessboard = { "....X.","....X.","XOOO..","......","......" };
    check.checkInt(3, o.flipChess(chessboard));

    chessboard = { ".X.",".O.","XO." };
    check.checkInt(2, o.flipChess(chessboard));

    chessboard = { ".......",".......",".......","X......",".O.....","..O....","....OOX" };
    check.checkInt(4, o.flipChess(chessboard));

    chessboard = { "O" };
    check.checkInt(0, o.flipChess(chessboard));

    chessboard = { "........",".XXXXXO.",".XOOOXO.",".XO.OXO.",".XOOOXO.",".XXXXXO.",".OOOOOO.","........" };
    check.checkInt(8, o.flipChess(chessboard));
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
