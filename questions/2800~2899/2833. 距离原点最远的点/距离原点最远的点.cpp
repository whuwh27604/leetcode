/* 距离原点最远的点.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你一个长度为 n 的字符串 moves ，该字符串仅由字符 'L'、'R' 和 '_' 组成。字符串表示你在一条原点为 0 的数轴上的若干次移动。

你的初始位置就在原点（0），第 i 次移动过程中，你可以根据对应字符选择移动方向：

如果 moves[i] = 'L' 或 moves[i] = '_' ，可以选择向左移动一个单位距离
如果 moves[i] = 'R' 或 moves[i] = '_' ，可以选择向右移动一个单位距离
移动 n 次之后，请你找出可以到达的距离原点 最远 的点，并返回 从原点到这一点的距离 。



示例 1：

输入：moves = "L_RL__R"
输出：3
解释：可以到达的距离原点 0 最远的点是 -3 ，移动的序列为 "LLRLLLR" 。
示例 2：

输入：moves = "_R__LL_"
输出：5
解释：可以到达的距离原点 0 最远的点是 -5 ，移动的序列为 "LRLLLLL" 。
示例 3：

输入：moves = "_______"
输出：7
解释：可以到达的距离原点 0 最远的点是 7 ，移动的序列为 "RRRRRRR" 。


提示：

1 <= moves.length == n <= 50
moves 仅由字符 'L'、'R' 和 '_' 组成
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int furthestDistanceFromOrigin(string moves) {
        int count1 = 0, count2 = 0;

        for (char c : moves) {
            if (c == 'L') {
                --count1;
            }
            else if (c == 'R') {
                ++count1;
            }
            else {
                ++count2;
            }
        }

        return abs(count1) + count2;
    }
};

int main()
{
    CheckResult check;
    Solution o;

    check.checkInt(3, o.furthestDistanceFromOrigin("L_RL__R"));
    check.checkInt(5, o.furthestDistanceFromOrigin("_R__LL_"));
    check.checkInt(7, o.furthestDistanceFromOrigin("_______"));
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
