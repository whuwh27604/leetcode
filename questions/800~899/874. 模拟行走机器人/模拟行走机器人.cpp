/* 模拟行走机器人.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
机器人在一个无限大小的网格上行走，从点 (0, 0) 处开始出发，面向北方。该机器人可以接收以下三种类型的命令：

-2：向左转 90 度
-1：向右转 90 度
1 <= x <= 9：向前移动 x 个单位长度
在网格上有一些格子被视为障碍物。

第 i 个障碍物位于网格点  (obstacles[i][0], obstacles[i][1])

机器人无法走到障碍物上，它将会停留在障碍物的前一个网格方块上，但仍然可以继续该路线的其余部分。

返回从原点到机器人所有经过的路径点（坐标为整数）的最大欧式距离的平方。

 

示例 1：

输入: commands = [4,-1,3], obstacles = []
输出: 25
解释: 机器人将会到达 (3, 4)
示例 2：

输入: commands = [4,-1,4,-2,4], obstacles = [[2,4]]
输出: 65
解释: 机器人在左转走到 (1, 8) 之前将被困在 (1, 4) 处
 

提示：

0 <= commands.length <= 10000
0 <= obstacles.length <= 10000
-30000 <= obstacle[i][0] <= 30000
-30000 <= obstacle[i][1] <= 30000
答案保证小于 2 ^ 31

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/walking-robot-simulation
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <unordered_set>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        unordered_set<unsigned long long> hashObstacles;
        for (unsigned int i = 0; i < obstacles.size(); i++) {
            hashObstacles.insert((((unsigned long long)(unsigned int)obstacles[i][0]) << 32) + (unsigned int)obstacles[i][1]);
        }

        unsigned long long current = 0;
        int command, units, maxDistance = 0;
        int direction = 0, dx[4] = { 0,-1,0,1 }, dy[4] = { 1,0,-1,0 };
        for (unsigned int i = 0; i < commands.size(); i++) {
            command = commands[i];
            if (command == -1) {
                direction = (direction + 3) % 4;
                continue;
            }

            if (command == -2) {
                direction = (direction + 1) % 4;
                continue;
            }

            int x = (int)(current >> 32), y = (int)current;
            for (units = 1; units <= command; units++) {
                x += dx[direction];
                y += dy[direction];
                if (hashObstacles.find(((unsigned long long)(unsigned int)x << 32) + (unsigned int)y) != hashObstacles.end()) {
                    break;
                }
            }

            if (units != command + 1) {
                x -= dx[direction];
                y -= dy[direction];
            }

            int distance = x * x + y * y;
            maxDistance = (distance > maxDistance) ? distance : maxDistance;
            current = ((unsigned long long)(unsigned int)x << 32) + (unsigned int)y;
        }

        return maxDistance;
    }
};

int main()
{
    Solution o;
    CheckResult check;

    vector<int> commands = { 4, -1,3 };
    vector<vector<int>> obstacles = {};
    check.checkInt(25, o.robotSim(commands, obstacles));
    
    commands = { 4,-1,4,-2,4 };
    obstacles = { {2,4} };
    check.checkInt(65, o.robotSim(commands, obstacles));

    commands = { 0 };
    obstacles = { {2,4} };
    check.checkInt(0, o.robotSim(commands, obstacles));

    commands = { 3,-2,6,-2,20,-2,30,-1,2 };
    obstacles = { {0,3},{-4,2},{-3,-10},{21,-9} };
    check.checkInt(521, o.robotSim(commands, obstacles));
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
