/* 矩阵中的蛇.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
大小为 n x n 的矩阵 grid 中有一条蛇。蛇可以朝 四个可能的方向 移动。矩阵中的每个单元格都使用位置进行标识： grid[i][j] = (i * n) + j。

蛇从单元格 0 开始，并遵循一系列命令移动。

给你一个整数 n 表示 grid 的大小，另给你一个字符串数组 commands，其中包括 "UP"、"RIGHT"、"DOWN" 和 "LEFT"。题目测评数据保证蛇在整个移动过程中将始终位于 grid 边界内。

返回执行 commands 后蛇所停留的最终单元格的位置。



示例 1：

输入：n = 2, commands = ["RIGHT","DOWN"]

输出：3

解释：

0	1
2	3
0	1
2	3
0	1
2	3
示例 2：

输入：n = 3, commands = ["DOWN","RIGHT","UP"]

输出：1

解释：

0	1	2
3	4	5
6	7	8
0	1	2
3	4	5
6	7	8
0	1	2
3	4	5
6	7	8
0	1	2
3	4	5
6	7	8


提示：

2 <= n <= 10
1 <= commands.length <= 100
commands 仅由 "UP"、"RIGHT"、"DOWN" 和 "LEFT" 组成。
生成的测评数据确保蛇不会移动到矩阵的边界外。
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int finalPositionOfSnake(int n, vector<string>& commands) {
        int r = 0, c = 0;

        for (string& com : commands) {
            if (com == "UP") {
                --r;
            }
            else if (com == "DOWN") {
                ++r;
            }
            else if (com == "LEFT") {
                --c;
            }
            else {
                ++c;
            }
        }

        return r * n + c;
    }
};

int main()
{
    Solution o;
    CheckResult check;

    vector<string> commands = { "RIGHT","DOWN" };
    check.checkInt(3, o.finalPositionOfSnake(2, commands));

    commands = { "DOWN","RIGHT","UP" };
    check.checkInt(1, o.finalPositionOfSnake(3, commands));
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
