/* 蛇梯棋.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
N x N 的棋盘 board 上，按从 1 到 N*N 的数字给方格编号，编号 从左下角开始，每一行交替方向。

例如，一块 6 x 6 大小的棋盘，编号如下：


r 行 c 列的棋盘，按前述方法编号，棋盘格中可能存在 “蛇” 或 “梯子”；如果 board[r][c] != -1，那个蛇或梯子的目的地将会是 board[r][c]。

玩家从棋盘上的方格 1 （总是在最后一行、第一列）开始出发。

每一回合，玩家需要从当前方格 x 开始出发，按下述要求前进：

选定目标方格：选择从编号 x+1，x+2，x+3，x+4，x+5，或者 x+6 的方格中选出一个目标方格 s ，目标方格的编号 <= N*N。
该选择模拟了掷骰子的情景，无论棋盘大小如何，你的目的地范围也只能处于区间 [x+1, x+6] 之间。
传送玩家：如果目标方格 S 处存在蛇或梯子，那么玩家会传送到蛇或梯子的目的地。否则，玩家传送到目标方格 S。 
注意，玩家在每回合的前进过程中最多只能爬过蛇或梯子一次：就算目的地是另一条蛇或梯子的起点，你也不会继续移动。

返回达到方格 N*N 所需的最少移动次数，如果不可能，则返回 -1。

 

示例：

输入：[
[-1,-1,-1,-1,-1,-1],
[-1,-1,-1,-1,-1,-1],
[-1,-1,-1,-1,-1,-1],
[-1,35,-1,-1,13,-1],
[-1,-1,-1,-1,-1,-1],
[-1,15,-1,-1,-1,-1]]
输出：4
解释：
首先，从方格 1 [第 5 行，第 0 列] 开始。
你决定移动到方格 2，并必须爬过梯子移动到到方格 15。
然后你决定移动到方格 17 [第 3 行，第 5 列]，必须爬过蛇到方格 13。
然后你决定移动到方格 14，且必须通过梯子移动到方格 35。
然后你决定移动到方格 36, 游戏结束。
可以证明你需要至少 4 次移动才能到达第 N*N 个方格，所以答案是 4。
 

提示：

2 <= board.length = board[0].length <= 20
board[i][j] 介于 1 和 N*N 之间或者等于 -1。
编号为 1 的方格上没有蛇或梯子。
编号为 N*N 的方格上没有蛇或梯子。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/snakes-and-ladders
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <queue>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int snakesAndLadders(vector<vector<int>>& board) {
        int N = board.size(), step = 0, target = N * N;
        vector<int> steps(target + 1, INT_MAX);
        steps[1] = 0;

        vector<int> portals(target + 1, 0);
        getPortals(board, N, portals);

        queue<int> bfs;
        bfs.push(1);

        while (!bfs.empty()) {
            int size = bfs.size();
            ++step;

            for (int i = 0; i < size; ++i) {
                int square = bfs.front();
                bfs.pop();

                for (int j = 1; j <= 6; ++j) {
                    int next = square + j;
                    if (portals[next] != 0) {
                        next = portals[next];
                    }

                    if (next == target) {
                        return step;
                    }

                    if (steps[next] > step) {
                        steps[next] = step;
                        bfs.push(next);
                    }
                }
            }
        }

        return -1;
    }

    void getPortals(vector<vector<int>>& board, int N, vector<int>& portals) {
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < N; ++j) {
                if (board[i][j] == -1) {
                    continue;
                }

                int square;
                if ((N - i) % 2 == 1) {
                    square = (N - 1 - i) * N + j + 1;
                }
                else {
                    square = (N - i) * N - j;
                }

                portals[square] = board[i][j];
            }
        }
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<vector<int>> board = {
    {-1,-1,-1,-1,-1,-1},
    {-1,-1,-1,-1,-1,-1},
    {-1,-1,-1,-1,-1,-1},
    {-1,35,-1,-1,13,-1},
    {-1,-1,-1,-1,-1,-1},
    {-1,15,-1,-1,-1,-1} };
    check.checkInt(4, o.snakesAndLadders(board));

    board = {
    {-1,-1,27,13,-1,25,-1},
    {-1,-1,-1,-1,-1,-1,-1},
    {44,-1,8,-1,-1,2,-1},
    {-1,30,-1,-1,-1,-1,-1},
    {3,-1,20,-1,46,6,-1},
    {-1,-1,-1,-1,-1,-1,29},
    {-1,29,21,33,-1,-1,-1} };
    check.checkInt(4, o.snakesAndLadders(board));

    board = {
    {-1,1,2,-1},
    {2,13,15,-1},
    {-1,10,-1,-1},
    {-1,6,2,8} };
    check.checkInt(2, o.snakesAndLadders(board));

    board = {
    {-1,36,-1,-1,-1,-1},
    {-1,-1,-1,-1,-1,-1},
    {-1,-1,-1,-1,-1,-1},
    {-1,35,-1,-1,13,-1},
    {-1,-1,-1,-1,-1,-1},
    {-1,15,-1,-1,-1,-1} };
    check.checkInt(4, o.snakesAndLadders(board));
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
