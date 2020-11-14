/* 困于环中的机器人.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
在无限的平面上，机器人最初位于 (0, 0) 处，面朝北方。机器人可以接受下列三条指令之一：

"G"：直走 1 个单位
"L"：左转 90 度
"R"：右转 90 度
机器人按顺序执行指令 instructions，并一直重复它们。

只有在平面中存在环使得机器人永远无法离开时，返回 true。否则，返回 false。

 

示例 1：

输入："GGLLGG"
输出：true
解释：
机器人从 (0,0) 移动到 (0,2)，转 180 度，然后回到 (0,0)。
重复这些指令，机器人将保持在以原点为中心，2 为半径的环中进行移动。
示例 2：

输入："GG"
输出：false
解释：
机器人无限向北移动。
示例 3：

输入："GL"
输出：true
解释：
机器人按 (0, 0) -> (0, 1) -> (-1, 1) -> (-1, 0) -> (0, 0) -> ... 进行移动。
 

提示：

1 <= instructions.length <= 100
instructions[i] 在 {'G', 'L', 'R'} 中

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/robot-bounded-in-circle
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    bool isRobotBounded(string instructions) {
        /* 分三种情况：
           1、回到原点，不管哪个方向，都是环路
           2、没有回到原点，方向为北，则不成环，只会越来越远
           3、没有回到原点，方向不为北，只用考虑首末点以及相对坐标系方向的变化，则重复4遍指令后会回到原点，所以是环路 */
        int x = 0, y = 0, dir = 0;
        int dx[4] = { 0,1,0,-1 }, dy[4] = { 1,0,-1,0 };

        for (char instruction : instructions) {
            if (instruction == 'G') {
                x += dx[dir];
                y += dy[dir];
            }
            else if (instruction == 'L') {
                dir = (dir + 3) % 4;
            }
            else {
                dir = (dir + 1) % 4;
            }
        }

        return !((x != 0 || y != 0) && (dir == 0));
    }
};

int main()
{
    CheckResult check;
    Solution o;

    check.checkBool(true, o.isRobotBounded("GGLLGG"));
    check.checkBool(false, o.isRobotBounded("GG"));
    check.checkBool(true, o.isRobotBounded("GL"));
    check.checkBool(true, o.isRobotBounded("GLRLLGLL"));
    check.checkBool(true, o.isRobotBounded("GGRGGRGGRGGR"));
    check.checkBool(true, o.isRobotBounded("RLLGLRRRRGGRRRGLLRRR"));
    check.checkBool(true, o.isRobotBounded("RGGGLGLLLLGLRGRLGGRLLRRRL"));
    check.checkBool(true, o.isRobotBounded("RLLGGLRGLGLLLGRLRLRLRRRRLRLGRLLLGGL"));
    check.checkBool(true, o.isRobotBounded("GRLLRLLLLGLLLGLLRGLLGRLLLRLLLLRLLGGGGGGLGLRRGLLGLG"));
    check.checkBool(true, o.isRobotBounded("RLRLLLLLRLRLLLRLRRRRLRLRRRRLLLLRRRRLLLRLLLRRRLLLLRLRRRLLRLLRRRLRR"));
    check.checkBool(true, o.isRobotBounded("LLGRGRRGGRGGRLGRGGRRLLRGGLRLLRGGLRLGLLRRGGRGLGRGGRLLLGGGRGRLGLLLRRLGGRRLGLGGRGLRLRRRLLGRGLRGLRRGLGRG"));
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
