/* 可以攻击国王的皇后.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
在一个 8x8 的棋盘上，放置着若干「黑皇后」和一个「白国王」。

「黑皇后」在棋盘上的位置分布用整数坐标数组 queens 表示，「白国王」的坐标用数组 king 表示。

「黑皇后」的行棋规定是：横、直、斜都可以走，步数不受限制，但是，不能越子行棋。

请你返回可以直接攻击到「白国王」的所有「黑皇后」的坐标（任意顺序）。

 

示例 1：



输入：queens = [[0,1],[1,0],[4,0],[0,4],[3,3],[2,4]], king = [0,0]
输出：[[0,1],[1,0],[3,3]]
解释：
[0,1] 的皇后可以攻击到国王，因为他们在同一行上。
[1,0] 的皇后可以攻击到国王，因为他们在同一列上。
[3,3] 的皇后可以攻击到国王，因为他们在同一条对角线上。
[0,4] 的皇后无法攻击到国王，因为她被位于 [0,1] 的皇后挡住了。
[4,0] 的皇后无法攻击到国王，因为她被位于 [1,0] 的皇后挡住了。
[2,4] 的皇后无法攻击到国王，因为她和国王不在同一行/列/对角线上。
示例 2：



输入：queens = [[0,0],[1,1],[2,2],[3,4],[3,5],[4,4],[4,5]], king = [3,3]
输出：[[2,2],[3,4],[4,4]]
示例 3：



输入：queens = [[5,6],[7,7],[2,1],[0,7],[1,6],[5,1],[3,7],[0,3],[4,0],[1,2],[6,3],[5,0],[0,4],[2,2],[1,1],[6,4],[5,4],[0,0],[2,6],[4,5],[5,2],[1,4],[7,5],[2,3],[0,5],[4,2],[1,0],[2,7],[0,1],[4,6],[6,1],[0,6],[4,3],[1,7]], king = [3,4]
输出：[[2,3],[1,4],[1,6],[3,7],[4,3],[5,4],[4,5]]
 

提示：

1 <= queens.length <= 63
queens[0].length == 2
0 <= queens[i][j] < 8
king.length == 2
0 <= king[0], king[1] < 8
一个棋盘格上最多只能放置一枚棋子。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/queens-that-can-attack-the-king
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    vector<vector<int>> queensAttacktheKing(vector<vector<int>>& queens, vector<int>& king) {
        vector<vector<int>> board(8, vector<int>(8, 0));
        for (vector<int>& queen : queens) {
            board[queen[0]][queen[1]] = 1;
        }

        int row = king[0], column = king[1];
        int dr[8] = { 0,1,1,1,0,-1,-1,-1 }, dc[8] = { 1,1,0,-1,-1,-1,0,1 };
        vector<vector<int>> attackingQueens;

        for (int i = 0; i < 8; ++i) {
            for (int j = 1; j < 8; ++j) {
                int r = row + dr[i] * j, c = column + dc[i] * j;
                if (r < 0 || r > 7 || c < 0 || c > 7) {
                    break;
                }

                if (board[r][c] == 1) {
                    attackingQueens.push_back({ r,c });
                    break;
                }
            }
        }

        return attackingQueens;
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<vector<int>> queens = { {0,1},{1,0},{4,0},{0,4},{3,3},{2,4} };
    vector<int> king = { 0,0 };
    vector<vector<int>> actual = o.queensAttacktheKing(queens, king);
    vector<vector<int>> expected = { {0,1},{1,0},{3,3} };
    check.checkIntVectorVectorRandomOrder(expected, actual);

    queens = { {0,0},{1,1},{2,2},{3,4},{3,5},{4,4},{4,5} };
    king = { 3,3 };
    actual = o.queensAttacktheKing(queens, king);
    expected = { {2,2},{3,4},{4,4} };
    check.checkIntVectorVectorRandomOrder(expected, actual);

    queens = { {5,6},{7,7},{2,1},{0,7},{1,6},{5,1},{3,7},{0,3},{4,0},{1,2},{6,3},{5,0},{0,4},{2,2},{1,1},{6,4},{5,4},{0,0},{2,6},{4,5},{5,2},{1,4},{7,5},{2,3},{0,5},{4,2},{1,0},{2,7},{0,1},{4,6},{6,1},{0,6},{4,3},{1,7} };
    king = { 3,4 };
    actual = o.queensAttacktheKing(queens, king);
    expected = { {2,3},{1,4},{1,6},{3,7},{4,3},{5,4},{4,5} };
    check.checkIntVectorVectorRandomOrder(expected, actual);

    queens = { {0,0} };
    king = { 7,7 };
    actual = o.queensAttacktheKing(queens, king);
    expected = { {0,0} };
    check.checkIntVectorVectorRandomOrder(expected, actual);

    queens = { {0,1} };
    king = { 7,7 };
    actual = o.queensAttacktheKing(queens, king);
    expected = {  };
    check.checkIntVectorVectorRandomOrder(expected, actual);
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
