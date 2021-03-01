/* 滑动谜题.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
在一个 2 x 3 的板上（board）有 5 块砖瓦，用数字 1~5 来表示, 以及一块空缺用 0 来表示.

一次移动定义为选择 0 与一个相邻的数字（上下左右）进行交换.

最终当板 board 的结果是 [[1,2,3],[4,5,0]] 谜板被解开。

给出一个谜板的初始状态，返回最少可以通过多少次移动解开谜板，如果不能解开谜板，则返回 -1 。

示例：

输入：board = [[1,2,3],[4,0,5]]
输出：1
解释：交换 0 和 5 ，1 步完成
输入：board = [[1,2,3],[5,4,0]]
输出：-1
解释：没有办法完成谜板
输入：board = [[4,1,2],[5,0,3]]
输出：5
解释：
最少完成谜板的最少移动次数是 5 ，
一种移动路径:
尚未移动: [[4,1,2],[5,0,3]]
移动 1 次: [[4,1,2],[0,5,3]]
移动 2 次: [[0,1,2],[4,5,3]]
移动 3 次: [[1,0,2],[4,5,3]]
移动 4 次: [[1,2,0],[4,5,3]]
移动 5 次: [[1,2,3],[4,5,0]]
输入：board = [[3,2,4],[1,5,0]]
输出：14
提示：

board 是一个如上所述的 2 x 3 的数组.
board[i][j] 是一个 [0, 1, 2, 3, 4, 5] 的排列.

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/sliding-puzzle
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <queue>
#include <unordered_set>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int slidingPuzzle(vector<vector<int>>& board) {
        int moves = -1;
        vector<vector<int>> swappings = { {1,3},{0,2,4},{1,5},{0,4},{1,3,5},{2,4} };
        unordered_set<string> visited;
        string node = to_string(board[0][0]) + to_string(board[0][1]) + to_string(board[0][2]) + to_string(board[1][0]) + to_string(board[1][1]) + to_string(board[1][2]);
        string target = "123450";
        queue<string> bfs;
        bfs.push(node);

        while (!bfs.empty()) {
            ++moves;
            int i, size = bfs.size();

            for (i = 0; i < size; ++i) {
                node = bfs.front();
                bfs.pop();

                if (node == target) {
                    return moves;
                }

                int empty;
                for (empty = 0; empty < 6; ++empty) {
                    if (node[empty] == '0') {
                        break;
                    }
                }

                for (int swapping : swappings[empty]) {
                    string next = node;
                    swap(next[empty], next[swapping]);
                    if (visited.count(next) == 0) {
                        visited.insert(next);
                        bfs.push(next);
                    }
                }
            }
        }

        return -1;
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<vector<int>> board = { {1,2,3},{4,0,5} };
    check.checkInt(1, o.slidingPuzzle(board));

    board = { {1,2,3},{5,4,0} };
    check.checkInt(-1, o.slidingPuzzle(board));

    board = { {4,1,2},{5,0,3} };
    check.checkInt(5, o.slidingPuzzle(board));
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
