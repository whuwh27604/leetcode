/* 找出井字棋的获胜者.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
A 和 B 在一个 3 x 3 的网格上玩井字棋。

井字棋游戏的规则如下：

玩家轮流将棋子放在空方格 (" ") 上。
第一个玩家 A 总是用 "X" 作为棋子，而第二个玩家 B 总是用 "O" 作为棋子。
"X" 和 "O" 只能放在空方格中，而不能放在已经被占用的方格上。
只要有 3 个相同的（非空）棋子排成一条直线（行、列、对角线）时，游戏结束。
如果所有方块都放满棋子（不为空），游戏也会结束。
游戏结束后，棋子无法再进行任何移动。
给你一个数组 moves，其中每个元素是大小为 2 的另一个数组（元素分别对应网格的行和列），它按照 A 和 B 的行动顺序（先 A 后 B）记录了两人各自的棋子位置。

如果游戏存在获胜者（A 或 B），就返回该游戏的获胜者；如果游戏以平局结束，则返回 "Draw"；如果仍会有行动（游戏未结束），则返回 "Pending"。

你可以假设 moves 都 有效（遵循井字棋规则），网格最初是空的，A 将先行动。

 

示例 1：

输入：moves = [[0,0],[2,0],[1,1],[2,1],[2,2]]
输出："A"
解释："A" 获胜，他总是先走。
"X  "    "X  "    "X  "    "X  "    "X  "
"   " -> "   " -> " X " -> " X " -> " X "
"   "    "O  "    "O  "    "OO "    "OOX"
示例 2：

输入：moves = [[0,0],[1,1],[0,1],[0,2],[1,0],[2,0]]
输出："B"
解释："B" 获胜。
"X  "    "X  "    "XX "    "XXO"    "XXO"    "XXO"
"   " -> " O " -> " O " -> " O " -> "XO " -> "XO "
"   "    "   "    "   "    "   "    "   "    "O  "
示例 3：

输入：moves = [[0,0],[1,1],[2,0],[1,0],[1,2],[2,1],[0,1],[0,2],[2,2]]
输出："Draw"
输出：由于没有办法再行动，游戏以平局结束。
"XXO"
"OOX"
"XOX"
示例 4：

输入：moves = [[0,0],[1,1]]
输出："Pending"
解释：游戏还没有结束。
"X  "
" O "
"   "
 

提示：

1 <= moves.length <= 9
moves[i].length == 2
0 <= moves[i][j] <= 2
moves 里没有重复的元素。
moves 遵循井字棋的规则。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/find-winner-on-a-tic-tac-toe-game
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    string tictactoe(vector<vector<int>>& moves) {
        int grid = 0, len = moves.size(), turn;

        for (int i = 0; i < len; i++) {
            int bit = moves[i][0] * 3 + moves[i][1];
            turn = i % 2;
            if (turn == 1) {
                bit += 9;
            }

            grid |= (1 << bit);
        }

        if (isWin(grid, turn)) {
            return (turn == 0 ? "A" : "B");
        }

        return (len == 9) ? "Draw" : "Pending";
    }

    bool isWin(int grid, int turn) {
        int wins[8] = { 0b111,0b111000,0b111000000,0b1001001,0b10010010,0b100100100,0b100010001,0b1010100 };
        if (turn == 1) {
            grid >>= 9;
        }

        for (int i = 0; i < 8; i++) {
            if ((grid & wins[i]) == wins[i]) {
                return true;
            }
        }

        return false;
    }
};

int main()
{
    Solution o;
    CheckResult check;

    vector<vector<int>> moves = { {0,0},{2,0},{1,1},{2,1},{2,2} };
    check.checkString("A", o.tictactoe(moves));

    moves = { {0,2},{1,2},{1,1},{2,1},{2,0} };
    check.checkString("A", o.tictactoe(moves));

    moves = { {0,0},{1,1},{0,1},{1,2},{0,2} };
    check.checkString("A", o.tictactoe(moves));

    moves = { {1,0},{0,0},{1,1},{0,1},{1,2} };
    check.checkString("A", o.tictactoe(moves));

    moves = { {2,0},{0,0},{2,1},{0,1},{1,0},{1,2},{2,2} };
    check.checkString("A", o.tictactoe(moves));

    moves = { {0,0},{0,1},{1,0},{1,1},{2,0} };
    check.checkString("A", o.tictactoe(moves));

    moves = { {0,1},{0,2},{1,1},{1,2},{2,1} };
    check.checkString("A", o.tictactoe(moves));

    moves = { {0,2},{0,1},{1,2},{1,1},{0,0},{1,0},{2,2} };
    check.checkString("A", o.tictactoe(moves));

    moves = { {0,0},{1,1},{0,1},{0,2},{1,0},{2,0} };
    check.checkString("B", o.tictactoe(moves));

    moves = { {1,0},{0,0},{2,0},{1,1},{2,1},{2,2} };
    check.checkString("B", o.tictactoe(moves));

    moves = { {1,0},{0,2},{1,2},{1,1},{2,1},{2,0} };
    check.checkString("B", o.tictactoe(moves));

    moves = { {2,2},{0,0},{1,1},{0,1},{1,2},{0,2} };
    check.checkString("B", o.tictactoe(moves));

    moves = { {0,2},{1,0},{0,0},{1,1},{0,1},{1,2} };
    check.checkString("B", o.tictactoe(moves));

    moves = { {1,1},{2,0},{0,0},{2,1},{0,1},{1,0},{1,2},{2,2} };
    check.checkString("B", o.tictactoe(moves));

    moves = { {0,2},{0,0},{0,1},{1,0},{1,1},{2,0} };
    check.checkString("B", o.tictactoe(moves));

    moves = { {1,0},{0,1},{0,2},{1,1},{1,2},{2,1} };
    check.checkString("B", o.tictactoe(moves));

    moves = { {2,0},{0,2},{0,1},{1,2},{1,1},{0,0},{1,0},{2,2} };
    check.checkString("B", o.tictactoe(moves));

    moves = { {0,0},{1,1},{2,0},{1,0},{1,2},{2,1},{0,1},{0,2},{2,2} };
    check.checkString("Draw", o.tictactoe(moves));

    moves = { {0,0},{1,1} };
    check.checkString("Pending", o.tictactoe(moves));

    moves = { {1,0},{0,0},{1,1},{0,1},{1,2},{0,2} };  // 这个用例算非法用例？
    check.checkString("B", o.tictactoe(moves));
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
