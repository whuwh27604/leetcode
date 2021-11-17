/* 模拟行走机器人 II.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你一个在 XY 平面上的 width x height 的网格图，左下角 的格子为 (0, 0) ，右上角 的格子为 (width - 1, height - 1) 。网格图中相邻格子为四个基本方向之一（"North"，"East"，"South" 和 "West"）。一个机器人 初始 在格子 (0, 0) ，方向为 "East" 。

机器人可以根据指令移动指定的 步数 。每一步，它可以执行以下操作。

沿着当前方向尝试 往前一步 。
如果机器人下一步将到达的格子 超出了边界 ，机器人会 逆时针 转 90 度，然后再尝试往前一步。
如果机器人完成了指令要求的移动步数，它将停止移动并等待下一个指令。

请你实现 Robot 类：

Robot(int width, int height) 初始化一个 width x height 的网格图，机器人初始在 (0, 0) ，方向朝 "East" 。
void move(int num) 给机器人下达前进 num 步的指令。
int[] getPos() 返回机器人当前所处的格子位置，用一个长度为 2 的数组 [x, y] 表示。
String getDir() 返回当前机器人的朝向，为 "North" ，"East" ，"South" 或者 "West" 。
 

示例 1：



输入：
["Robot", "move", "move", "getPos", "getDir", "move", "move", "move", "getPos", "getDir"]
[[6, 3], [2], [2], [], [], [2], [1], [4], [], []]
输出：
[null, null, null, [4, 0], "East", null, null, null, [1, 2], "West"]

解释：
Robot robot = new Robot(6, 3); // 初始化网格图，机器人在 (0, 0) ，朝东。
robot.move(2);  // 机器人朝东移动 2 步，到达 (2, 0) ，并朝东。
robot.move(2);  // 机器人朝东移动 2 步，到达 (4, 0) ，并朝东。
robot.getPos(); // 返回 [4, 0]
robot.getDir(); // 返回 "East"
robot.move(2);  // 朝东移动 1 步到达 (5, 0) ，并朝东。
                // 下一步继续往东移动将出界，所以逆时针转变方向朝北。
                // 然后，往北移动 1 步到达 (5, 1) ，并朝北。
robot.move(1);  // 朝北移动 1 步到达 (5, 2) ，并朝 北 （不是朝西）。
robot.move(4);  // 下一步继续往北移动将出界，所以逆时针转变方向朝西。
                // 然后，移动 4 步到 (1, 2) ，并朝西。
robot.getPos(); // 返回 [1, 2]
robot.getDir(); // 返回 "West"

 

提示：

2 <= width, height <= 100
1 <= num <= 105
move ，getPos 和 getDir 总共 调用次数不超过 104 次。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/walking-robot-simulation-ii
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <algorithm>
#include "../check/CheckResult.h"

using namespace std;

class Robot {
public:
    Robot(int width, int height) {
        x = 0, y = 0, dir = 0, maxX = width, maxY = height;
    }

    void move(int num) {
        int step = 0;

        while (num != 0) {
            if ((dir == 0 && x == maxX - 1) || (dir == 1 && y == maxY - 1) || (dir == 2 && x == 0) || (dir == 3 && y == 0)) {
                dir = (dir + 1) % 4;
            }

            if (dir == 0) {
                step = min(num, maxX - x - 1);
                x += step;
            }
            else if (dir == 1) {
                step = min(num, maxY - y - 1);
                y += step;
            }
            else if (dir == 2) {
                step = min(num, x);
                x -= step;
            }
            else {
                step = min(num, y);
                y -= step;
            }

            num -= step;
            num %= (2 * (maxX + maxY - 2));
        }
    }

    vector<int> getPos() {
        return { x,y };
    }

    string getDir() {
        return dir == 0 ? "East" : (dir == 1 ? "North" : (dir == 2 ? "West" : "South"));
    }

private:
    int maxX;
    int maxY;
    int x;
    int y;
    int dir;
};

int main()
{
    CheckResult check;

    Robot o1(6, 3);
    o1.move(2);
    o1.move(2);
    vector<int> actual = o1.getPos();
    vector<int> expected = { 4,0 };
    check.checkIntVector(expected, actual);
    check.checkString("East", o1.getDir());
    o1.move(2);
    o1.move(1);
    o1.move(4);
    actual = o1.getPos();
    expected = { 1,2 };
    check.checkIntVector(expected, actual);
    check.checkString("West", o1.getDir());

    Robot o2(3, 3);
    o2.move(2);
    actual = o2.getPos();
    expected = { 2,0 };
    check.checkIntVector(expected, actual);
    check.checkString("East", o2.getDir());
    o2.move(6);
    actual = o2.getPos();
    expected = { 0,0 };
    check.checkIntVector(expected, actual);
    check.checkString("South", o2.getDir());

    Robot o3(3, 3);
    o3.move(800);
    actual = o3.getPos();
    expected = { 0,0 };
    check.checkIntVector(expected, actual);
    check.checkString("South", o3.getDir());
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
