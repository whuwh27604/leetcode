/* 最大得分的路径数目.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你一个正方形字符数组 board ，你从数组最右下方的字符 'S' 出发。

你的目标是到达数组最左上角的字符 'E' ，数组剩余的部分为数字字符 1, 2, ..., 9 或者障碍 'X'。在每一步移动中，你可以向上、向左或者左上方移动，可以移动的前提是到达的格子没有障碍。

一条路径的 「得分」 定义为：路径上所有数字的和。

请你返回一个列表，包含两个整数：第一个整数是 「得分」 的最大值，第二个整数是得到最大得分的方案数，请把结果对 10^9 + 7 取余。

如果没有任何路径可以到达终点，请返回 [0, 0] 。

 

示例 1：

输入：board = ["E23","2X2","12S"]
输出：[7,1]
示例 2：

输入：board = ["E12","1X1","21S"]
输出：[4,2]
示例 3：

输入：board = ["E11","XXX","11S"]
输出：[0,0]
 

提示：

2 <= board.length == board[i].length <= 100

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/number-of-paths-with-max-score
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <algorithm>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    vector<int> pathsWithMaxScore(vector<string>& board) {
        int r, c, size = board.size(), mod = 1000000007;
        vector<vector<int>> maxScores(size, vector<int>(size, -1)), paths(size, vector<int>(size, 0));
        maxScores[0][0] = 0, paths[0][0] = 1;

        for (c = 1; c < size; ++c) {  // row == 0
            if (board[0][c] != 'X' && paths[0][c - 1] != 0) {
                maxScores[0][c] = maxScores[0][c - 1] + board[0][c] - '0';
                paths[0][c] = 1;
            }
        }

        for (r = 1; r < size; ++r) {
            if (board[r][0] != 'X' && paths[r - 1][0] != 0) {  // column == 0
                maxScores[r][0] = maxScores[r - 1][0] + board[r][0] - '0';
                paths[r][0] = 1;
            }

            for (c = 1; c < size; ++c) {
                if (board[r][c] == 'X') {
                    continue;
                }

                int score = (board[r][c] == 'S') ? 0 : board[r][c] - '0';

                if (paths[r][c - 1] != 0) {  // 先计算最大得分
                    maxScores[r][c] = max(maxScores[r][c], maxScores[r][c - 1] + score);
                }

                if (paths[r - 1][c] != 0) {
                    maxScores[r][c] = max(maxScores[r][c], maxScores[r - 1][c] + score);
                }

                if (paths[r - 1][c - 1] != 0) {
                    maxScores[r][c] = max(maxScores[r][c], maxScores[r - 1][c - 1] + score);
                }

                int wanted = maxScores[r][c] - score;

                if (maxScores[r][c - 1] == wanted) {  // 然后看从哪条路过来可以得到最大得分，加上对应的paths
                    paths[r][c] = (paths[r][c] + paths[r][c - 1]) % mod;
                }

                if (maxScores[r - 1][c] == wanted) {
                    paths[r][c] = (paths[r][c] + paths[r - 1][c]) % mod;
                }

                if (maxScores[r - 1][c - 1] == wanted) {
                    paths[r][c] = (paths[r][c] + paths[r - 1][c - 1]) % mod;
                }
            }
        }

        if (paths.back().back() == 0) {
            return { 0,0 };
        }

        return { maxScores.back().back(), paths.back().back() };
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<string> board = { "E23","2X2","12S" };
    vector<int> actual = o.pathsWithMaxScore(board);
    vector<int> expected = { 7,1 };
    check.checkIntVector(expected, actual);

    board = { "E12","1X1","21S" };
    actual = o.pathsWithMaxScore(board);
    expected = { 4,2 };
    check.checkIntVector(expected, actual);

    board = { "E11","XXX","11S" };
    actual = o.pathsWithMaxScore(board);
    expected = { 0,0 };
    check.checkIntVector(expected, actual);

    board = { "EX","XS" };
    actual = o.pathsWithMaxScore(board);
    expected = { 0,1 };
    check.checkIntVector(expected, actual);
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
