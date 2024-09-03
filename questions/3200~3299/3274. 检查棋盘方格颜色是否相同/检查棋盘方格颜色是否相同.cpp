/* 检查棋盘方格颜色是否相同.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你两个字符串 coordinate1 和 coordinate2，代表 8 x 8 国际象棋棋盘上的两个方格的坐标。

以下是棋盘的参考图。



如果这两个方格颜色相同，返回 true，否则返回 false。

坐标总是表示有效的棋盘方格。坐标的格式总是先字母（表示列），再数字（表示行）。



示例 1：

输入： coordinate1 = "a1", coordinate2 = "c3"

输出： true

解释：

两个方格均为黑色。

示例 2：

输入： coordinate1 = "a1", coordinate2 = "h3"

输出： false

解释：

方格 "a1" 是黑色，而 "h3" 是白色。



提示：

coordinate1.length == coordinate2.length == 2
'a' <= coordinate1[0], coordinate2[0] <= 'h'
'1' <= coordinate1[1], coordinate2[1] <= '8'
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    bool checkTwoChessboards(string coordinate1, string coordinate2) {
        return ((coordinate1[0] + coordinate1[1]) & 1) == ((coordinate2[0] + coordinate2[1]) & 1);
    }
};

int main()
{
    Solution o;
    CheckResult check;

    check.checkBool(true, o.checkTwoChessboards("a1", "c3"));
    check.checkBool(false, o.checkTwoChessboards("a1", "h3"));
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
