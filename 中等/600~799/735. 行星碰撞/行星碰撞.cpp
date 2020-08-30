/* 行星碰撞.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给定一个整数数组 asteroids，表示在同一行的行星。

对于数组中的每一个元素，其绝对值表示行星的大小，正负表示行星的移动方向（正表示向右移动，负表示向左移动）。每一颗行星以相同的速度移动。

找出碰撞后剩下的所有行星。碰撞规则：两个行星相互碰撞，较小的行星会爆炸。如果两颗行星大小相同，则两颗行星都会爆炸。两颗移动方向相同的行星，永远不会发生碰撞。

示例 1:

输入:
asteroids = [5, 10, -5]
输出: [5, 10]
解释:
10 和 -5 碰撞后只剩下 10。 5 和 10 永远不会发生碰撞。
示例 2:

输入:
asteroids = [8, -8]
输出: []
解释:
8 和 -8 碰撞后，两者都发生爆炸。
示例 3:

输入:
asteroids = [10, 2, -5]
输出: [10]
解释:
2 和 -5 发生碰撞后剩下 -5。10 和 -5 发生碰撞后剩下 10。
示例 4:

输入:
asteroids = [-2, -1, 1, 2]
输出: [-2, -1, 1, 2]
解释:
-2 和 -1 向左移动，而 1 和 2 向右移动。
由于移动方向相同的行星不会发生碰撞，所以最终没有行星发生碰撞。
说明:

数组 asteroids 的长度不超过 10000。
每一颗行星的大小都是非零整数，范围是 [-1000, 1000] 。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/asteroid-collision
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <stack>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int> asteroidsLeft;

        for (int asteroid : asteroids) {
            bool left = true;

            while (!asteroidsLeft.empty() && (asteroidsLeft.back() > 0) && (asteroid < 0)) {
                if (abs(asteroid) <= abs(asteroidsLeft.back())) {
                    left = false;
                    if (abs(asteroid) == abs(asteroidsLeft.back())) {
                        asteroidsLeft.pop_back();
                    }
                    break;
                }

                asteroidsLeft.pop_back();
            }

            if (left) {
                asteroidsLeft.push_back(asteroid);
            }
        }

        return asteroidsLeft;
    }
};

int main()
{
    Solution o;
    CheckResult check;

    vector<int> asteroids = { 5,10,-5 };
    vector<int> actual = o.asteroidCollision(asteroids);
    vector<int> expected = { 5,10 };
    check.checkIntVector(expected, actual);

    asteroids = { 8,-8 };
    actual = o.asteroidCollision(asteroids);
    expected = {  };
    check.checkIntVector(expected, actual);

    asteroids = { 10,2,-5 };
    actual = o.asteroidCollision(asteroids);
    expected = { 10 };
    check.checkIntVector(expected, actual);

    asteroids = { -2,-1,1,2 };
    actual = o.asteroidCollision(asteroids);
    expected = { -2,-1,1,2 };
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
