/* 生命游戏.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
根据 百度百科 ，生命游戏，简称为生命，是英国数学家约翰·何顿·康威在 1970 年发明的细胞自动机。

给定一个包含 m × n 个格子的面板，每一个格子都可以看成是一个细胞。每个细胞都具有一个初始状态：1 即为活细胞（live），或 0 即为死细胞（dead）。每个细胞与其八个相邻位置（水平，垂直，对角线）的细胞都遵循以下四条生存定律：

如果活细胞周围八个位置的活细胞数少于两个，则该位置活细胞死亡；
如果活细胞周围八个位置有两个或三个活细胞，则该位置活细胞仍然存活；
如果活细胞周围八个位置有超过三个活细胞，则该位置活细胞死亡；
如果死细胞周围正好有三个活细胞，则该位置死细胞复活；
根据当前状态，写一个函数来计算面板上所有细胞的下一个（一次更新后的）状态。下一个状态是通过将上述规则同时应用于当前状态下的每个细胞所形成的，其中细胞的出生和死亡是同时发生的。

 

示例：

输入：
[
  [0,1,0],
  [0,0,1],
  [1,1,1],
  [0,0,0]
]
输出：
[
  [0,0,0],
  [1,0,1],
  [0,1,1],
  [0,1,0]
]
 

进阶：

你可以使用原地算法解决本题吗？请注意，面板上所有格子需要同时被更新：你不能先更新某些格子，然后使用它们的更新后的值再更新其他格子。
本题中，我们使用二维数组来表示面板。原则上，面板是无限的，但当活细胞侵占了面板边界时会造成问题。你将如何解决这些问题？

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/game-of-life
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        if (board.empty() || board[0].empty()) {
            return;
        }

        // 1->0,set:-1  0->1,set:-2
        int i, j, m = board.size(), n = board[0].size();
        for (i = 0; i < m; i++) {
            for (j = 0; j < n; j++) {
                int aroundLives = 0, liveDead;
                liveDead = ((i == 0 || j == 0) ? 0 : board[i - 1][j - 1]);
                liveDead = ((liveDead < 0) ? (liveDead + 2) : liveDead);
                aroundLives += liveDead;
                liveDead = ((i == 0) ? 0 : board[i - 1][j]);
                liveDead = ((liveDead < 0) ? (liveDead + 2) : liveDead);
                aroundLives += liveDead;
                liveDead = ((i == 0 || j == n - 1) ? 0 : board[i - 1][j + 1]);
                liveDead = ((liveDead < 0) ? (liveDead + 2) : liveDead);
                aroundLives += liveDead;
                aroundLives += ((j == n - 1) ? 0 : board[i][j + 1]);
                aroundLives += ((i == m - 1 || j == n - 1) ? 0 : board[i + 1][j + 1]);
                aroundLives += ((i == m - 1) ? 0 : board[i + 1][j]);
                aroundLives += ((i == m - 1 || j == 0) ? 0 : board[i + 1][j - 1]);
                liveDead = ((j == 0) ? 0 : board[i][j - 1]);
                liveDead = ((liveDead < 0) ? (liveDead + 2) : liveDead);
                aroundLives += liveDead;

                if ((board[i][j] == 1) && ((aroundLives < 2) || (aroundLives > 3))) {
                    board[i][j] = -1;
                }
                else if ((board[i][j] == 0) && (aroundLives == 3)) {
                    board[i][j] = -2;
                }
            }
        }

        for (i = 0; i < m; i++) {
            for (j = 0; j < n; j++) {
                if (board[i][j] < 0) {
                    board[i][j] = -1 - board[i][j];
                }
            }
        }

        return;
    }
};

int main()
{
    Solution o;
    CheckResult check;

    vector<vector<int>> board = {};
    o.gameOfLife(board);
    check.checkBool(true, board.empty());

    board = { {} };
    o.gameOfLife(board);
    vector<vector<int>> expected = { {} };
    check.checkIntVectorVector(expected, board);
    
    board = { {1} };
    o.gameOfLife(board);
    expected = { {0} };
    check.checkIntVectorVector(expected, board);

    board = { {1,1,1} };
    o.gameOfLife(board);
    expected = { {0,1,0} };
    check.checkIntVectorVector(expected, board);

    board = { {0,1,0},{1,1,1},{0,1,0} };
    o.gameOfLife(board);
    expected = { {1,1,1},{1,0,1},{1,1,1} };
    check.checkIntVectorVector(expected, board);

    board = { {0,1,0},{0,0,1},{1,1,1},{0,0,0} };
    o.gameOfLife(board);
    expected = { {0,0,0},{1,0,1},{0,1,1},{0,1,0} };
    check.checkIntVectorVector(expected, board);
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
