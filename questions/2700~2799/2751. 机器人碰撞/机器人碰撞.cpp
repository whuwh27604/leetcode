/* 机器人碰撞.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
现有 n 个机器人，编号从 1 开始，每个机器人包含在路线上的位置、健康度和移动方向。

给你下标从 0 开始的两个整数数组 positions、healths 和一个字符串 directions（directions[i] 为 'L' 表示 向左 或 'R' 表示 向右）。 positions 中的所有整数 互不相同 。

所有机器人以 相同速度 同时 沿给定方向在路线上移动。如果两个机器人移动到相同位置，则会发生 碰撞 。

如果两个机器人发生碰撞，则将 健康度较低 的机器人从路线中 移除 ，并且另一个机器人的健康度 减少 1 。幸存下来的机器人将会继续沿着与之前 相同 的方向前进。如果两个机器人的健康度相同，则将二者都从路线中移除。

请你确定全部碰撞后幸存下的所有机器人的 健康度 ，并按照原来机器人编号的顺序排列。即机器人 1 （如果幸存）的最终健康度，机器人 2 （如果幸存）的最终健康度等。 如果不存在幸存的机器人，则返回空数组。

在不再发生任何碰撞后，请你以数组形式，返回所有剩余机器人的健康度（按机器人输入中的编号顺序）。

注意：位置  positions 可能是乱序的。



示例 1：



输入：positions = [5,4,3,2,1], healths = [2,17,9,15,10], directions = "RRRRR"
输出：[2,17,9,15,10]
解释：在本例中不存在碰撞，因为所有机器人向同一方向移动。所以，从第一个机器人开始依序返回健康度，[2, 17, 9, 15, 10] 。
示例 2：



输入：positions = [3,5,2,6], healths = [10,10,15,12], directions = "RLRL"
输出：[14]
解释：本例中发生 2 次碰撞。首先，机器人 1 和机器人 2 将会碰撞，因为二者健康度相同，二者都将被从路线中移除。接下来，机器人 3 和机器人 4 将会发生碰撞，由于机器人 4 的健康度更小，则它会被移除，而机器人 3 的健康度变为 15 - 1 = 14 。仅剩机器人 3 ，所以返回 [14] 。
示例 3：



输入：positions = [1,2,5,6], healths = [10,10,11,11], directions = "RLRL"
输出：[]
解释：机器人 1 和机器人 2 将会碰撞，因为二者健康度相同，二者都将被从路线中移除。机器人 3 和机器人 4 将会碰撞，因为二者健康度相同，二者都将被从路线中移除。所以返回空数组 [] 。


提示：

1 <= positions.length == healths.length == directions.length == n <= 105
1 <= positions[i], healths[i] <= 109
directions[i] == 'L' 或 directions[i] == 'R'
positions 中的所有值互不相同
*/

#include <iostream>
#include <algorithm>
#include <stack>
#include "../check/CheckResult.h"

using namespace std;

class Robot {
public:
    int index;
    int position;
    int health;
    char direction;

    Robot() : index(0), position(0), health(0), direction('L') {}
    Robot(int i, int p, int h, char d) : index(i), position(p), health(h), direction(d) {}

    bool operator<(const Robot& r) const {
        return position < r.position;
    }
};

class Solution {
public:
    vector<int> survivedRobotsHealths(vector<int>& positions, vector<int>& healths, string directions) {
        int n = positions.size();
        vector<Robot> robots(n);
        vector<pair<int, int>> survived;
        vector<int> ans;
        stack<Robot> rightRobots;

        for (int i = 0; i < n; ++i) {
            robots[i] = { i,positions[i],healths[i],directions[i] };
        }

        sort(robots.begin(), robots.end());

        for (auto& robot : robots) {
            if (robot.direction == 'R') {
                rightRobots.push(robot);
            }
            else {
                while (!rightRobots.empty() && rightRobots.top().health < robot.health) {  // 将health小于自己的往右的robot消灭掉
                    rightRobots.pop();
                    robot.health -= 1;
                }

                if (rightRobots.empty()) {  // 没有往右的，当前robot将会survive
                    survived.push_back({ robot.index,robot.health });
                }
                else {
                    if (rightRobots.top().health == robot.health) {  // health相等，2个robot同时消灭掉
                        rightRobots.pop();
                    }
                    else {  // 往右的robot的health较大，当前robot被消灭掉，同时栈顶robot的health减1
                        rightRobots.top().health -= 1;
                    }
                }
            }
        }

        while (!rightRobots.empty()) {
            survived.push_back({ rightRobots.top().index, rightRobots.top().health });
            rightRobots.pop();
        }

        sort(survived.begin(), survived.end());

        for (auto& p : survived) {
            ans.push_back(p.second);
        }

        return ans;
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<int> positions = { 5,4,3,2,1 };
    vector<int> healths = { 2,17,9,15,10 };
    vector<int> actual = o.survivedRobotsHealths(positions, healths, "RRRRR");
    vector<int> expected = { 2,17,9,15,10 };
    check.checkIntVector(expected, actual);

    positions = { 3,5,2,6 };
    healths = { 10,10,15,12 };
    actual = o.survivedRobotsHealths(positions, healths, "RLRL");
    expected = { 14 };
    check.checkIntVector(expected, actual);

    positions = { 1,2,5,6 };
    healths = { 10,10,11,11 };
    actual = o.survivedRobotsHealths(positions, healths, "RLRL");
    expected = {  };
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
