/* 棋盘上有效移动组合的数目.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
有一个 8 x 8 的棋盘，它包含 n 个棋子（棋子包括车，后和象三种）。给你一个长度为 n 的字符串数组 pieces ，其中 pieces[i] 表示第 i 个棋子的类型（车，后或象）。除此以外，还给你一个长度为 n 的二维整数数组 positions ，其中 positions[i] = [ri, ci] 表示第 i 个棋子现在在棋盘上的位置为 (ri, ci) ，棋盘下标从 1 开始。

棋盘上每个棋子都可以移动 至多一次 。每个棋子的移动中，首先选择移动的 方向 ，然后选择 移动的步数 ，同时你要确保移动过程中棋子不能移到棋盘以外的地方。棋子需按照以下规则移动：

车可以 水平或者竖直 从 (r, c) 沿着方向 (r+1, c)，(r-1, c)，(r, c+1) 或者 (r, c-1) 移动。
后可以 水平竖直或者斜对角 从 (r, c) 沿着方向 (r+1, c)，(r-1, c)，(r, c+1)，(r, c-1)，(r+1, c+1)，(r+1, c-1)，(r-1, c+1)，(r-1, c-1) 移动。
象可以 斜对角 从 (r, c) 沿着方向 (r+1, c+1)，(r+1, c-1)，(r-1, c+1)，(r-1, c-1) 移动。
移动组合 包含所有棋子的 移动 。每一秒，每个棋子都沿着它们选择的方向往前移动 一步 ，直到它们到达目标位置。所有棋子从时刻 0 开始移动。如果在某个时刻，两个或者更多棋子占据了同一个格子，那么这个移动组合 不有效 。

请你返回 有效 移动组合的数目。

注意：

初始时，不会有两个棋子 在 同一个位置 。
有可能在一个移动组合中，有棋子不移动。
如果两个棋子 直接相邻 且两个棋子下一秒要互相占据对方的位置，可以将它们在同一秒内 交换位置 。
 

示例 1:



输入：pieces = ["rook"], positions = [[1,1]]
输出：15
解释：上图展示了棋子所有可能的移动。
示例 2：



输入：pieces = ["queen"], positions = [[1,1]]
输出：22
解释：上图展示了棋子所有可能的移动。
示例 3:



输入：pieces = ["bishop"], positions = [[4,3]]
输出：12
解释：上图展示了棋子所有可能的移动。
示例 4:



输入：pieces = ["rook","rook"], positions = [[1,1],[8,8]]
输出：223
解释：每个车有 15 种移动，所以总共有 15 * 15 = 225 种移动组合。
但是，有两个是不有效的移动组合：
- 将两个车都移动到 (8, 1) ，会导致它们在同一个格子相遇。
- 将两个车都移动到 (1, 8) ，会导致它们在同一个格子相遇。
所以，总共有 225 - 2 = 223 种有效移动组合。
注意，有两种有效的移动组合，分别是一个车在 (1, 8) ，另一个车在 (8, 1) 。
即使棋盘状态是相同的，这两个移动组合被视为不同的，因为每个棋子移动操作是不相同的。
示例 5：



输入：pieces = ["queen","bishop"], positions = [[5,7],[3,4]]
输出：281
解释：总共有 12 * 24 = 288 种移动组合。
但是，有一些不有效的移动组合：
- 如果后停在 (6, 7) ，它会阻挡象到达 (6, 7) 或者 (7, 8) 。
- 如果后停在 (5, 6) ，它会阻挡象到达 (5, 6) ，(6, 7) 或者 (7, 8) 。
- 如果象停在 (5, 2) ，它会阻挡后到达 (5, 2) 或者 (5, 1) 。
在 288 个移动组合当中，281 个是有效的。
 

提示：

n == pieces.length
n == positions.length
1 <= n <= 4
pieces 只包含字符串 "rook" ，"queen" 和 "bishop" 。
棋盘上总共最多只有一个后。
1 <= xi, yi <= 8
每一个 positions[i] 互不相同。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/number-of-valid-move-combinations-on-chessboard
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <queue>
#include "../check/CheckResult.h"

using namespace std;

class Move {
public:
    int rStart;
    int cStart;
    int rEnd;
    int cEnd;
    int direction;

    Move() : rStart(0), cStart(0), rEnd(0), cEnd(0), direction(0) {}
    Move(int rs, int cs, int re, int ce, int dir) : rStart(rs), cStart(cs), rEnd(re), cEnd(ce), direction(dir) {}
};  // 一个棋子的一次移动方案

class Combination {
public:
    vector<Move> moves;
};  // 多个棋子的一次移动方案的组合

class Solution {
public:
    int countCombinations(vector<string>& pieces, vector<vector<int>>& positions) {
        int i, n = pieces.size(), count = 0;
        vector<vector<Move>> allMoves(n);
        vector<Combination> combinations = { Combination() };

        for (i = 0; i < n; ++i) {  // 先查询所有棋子的可能的一次移动方案
            getMoves(pieces[i], positions[i][0], positions[i][1], allMoves[i]);
        }

        for (auto& pieceMoves : allMoves) {  // 枚举所有可能的组合方案
            vector<Combination> tmp;

            for (Move& move : pieceMoves) {
                for (Combination comb : combinations) {
                    comb.moves.push_back(move);
                    tmp.push_back(comb);
                }
            }

            combinations = tmp;
        }

        for (Combination& comb : combinations) {  // 依次检查该组合方案是否合法
            if (check(comb, n)) {
                ++count;
            }
        }

        return count;
    }

    bool check(Combination& combination, int n) {
        bool moved = true;

        for (int step = 0; moved && step < board; ++step) {
            moved = false;

            for (Move& move : combination.moves) {
                if (move.rStart != move.rEnd || move.cStart != move.cEnd) {
                    move.rStart += dr[move.direction], move.cStart += dc[move.direction];
                    moved = true;
                }
            }

            for (int i = 0; i < n - 1; ++i) {
                for (int j = i + 1; j < n; ++j) {
                    if (combination.moves[i].rStart == combination.moves[j].rStart && combination.moves[i].cStart == combination.moves[j].cStart) {
                        return false;  // 两个棋子移动到了同一个位置则非法
                    }
                }
            }
        }

        return true;
    }

    void getMoves(string& piece, int r, int c, vector<Move>& moves) {
        int start, end;

        if (piece == "rook") {
            start = 0, end = 3;
        }
        else if (piece == "bishop") {
            start = 4, end = 7;
        }
        else {
            start = 0, end = 7;
        }

        moves.push_back(Move(r, c, r, c, 0));

        for (int dir = start; dir <= end; ++dir) {
            for (int step = 1; step < board; ++step) {
                int nr = r + step * dr[dir], nc = c + step * dc[dir];

                if (nr < 1 || nr > board || nc < 1 || nc > board) {
                    break;
                }

                moves.push_back(Move(r, c, nr, nc, dir));
            }
        }
    }

    Solution() {
        dr = { 0,1,0,-1,-1,1,1,-1 };
        dc = { 1,0,-1,0,1,1,-1,-1 };
        board = 8;
    }

    vector<int> dr;
    vector<int> dc;
    int board;
};

int main()
{
    CheckResult check;
    Solution o;

    vector<string> pieces = { "rook" };
    vector<vector<int>> positions = { {1,1} };
    check.checkInt(15, o.countCombinations(pieces, positions));

    pieces = { "queen" };
    positions = { {1,1} };
    check.checkInt(22, o.countCombinations(pieces, positions));

    pieces = { "bishop" };
    positions = { {4,3} };
    check.checkInt(12, o.countCombinations(pieces, positions));

    pieces = { "rook","rook" };
    positions = { {1,1},{8,8} };
    check.checkInt(223, o.countCombinations(pieces, positions));

    pieces = { "queen","bishop" };
    positions = { {5,7},{3,4} };
    check.checkInt(281, o.countCombinations(pieces, positions));

    pieces = { "bishop","rook" };
    positions = { {8,5},{7,7} };
    check.checkInt(96, o.countCombinations(pieces, positions));

    pieces = { "queen","bishop","rook" };
    positions = { {6,2},{6,8},{2,8} };
    check.checkInt(2464, o.countCombinations(pieces, positions));
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
