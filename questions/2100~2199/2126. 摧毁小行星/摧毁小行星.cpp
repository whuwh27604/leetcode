/* 摧毁小行星.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你一个整数 mass ，它表示一颗行星的初始质量。再给你一个整数数组 asteroids ，其中 asteroids[i] 是第 i 颗小行星的质量。

你可以按 任意顺序 重新安排小行星的顺序，然后让行星跟它们发生碰撞。如果行星碰撞时的质量 大于等于 小行星的质量，那么小行星被 摧毁 ，并且行星会 获得 这颗小行星的质量。否则，行星将被摧毁。

如果所有小行星 都 能被摧毁，请返回 true ，否则返回 false 。

 

示例 1：

输入：mass = 10, asteroids = [3,9,19,5,21]
输出：true
解释：一种安排小行星的方式为 [9,19,5,3,21] ：
- 行星与质量为 9 的小行星碰撞。新的行星质量为：10 + 9 = 19
- 行星与质量为 19 的小行星碰撞。新的行星质量为：19 + 19 = 38
- 行星与质量为 5 的小行星碰撞。新的行星质量为：38 + 5 = 43
- 行星与质量为 3 的小行星碰撞。新的行星质量为：43 + 3 = 46
- 行星与质量为 21 的小行星碰撞。新的行星质量为：46 + 21 = 67
所有小行星都被摧毁。
示例 2：

输入：mass = 5, asteroids = [4,9,23,4]
输出：false
解释：
行星无论如何没法获得足够质量去摧毁质量为 23 的小行星。
行星把别的小行星摧毁后，质量为 5 + 4 + 9 + 4 = 22 。
它比 23 小，所以无法摧毁最后一颗小行星。
 

提示：

1 <= mass <= 105
1 <= asteroids.length <= 105
1 <= asteroids[i] <= 105

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/destroying-asteroids
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <algorithm>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    bool asteroidsDestroyed(int mass, vector<int>& asteroids) {
        long long current = mass;

        sort(asteroids.begin(), asteroids.end());

        for (int asteroid : asteroids) {
            if (current < asteroid) {
                return false;
            }

            current += asteroid;
        }

        return true;
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<int> asteroids = { 3,9,19,5,21 };
    check.checkBool(true, o.asteroidsDestroyed(10, asteroids));

    asteroids = { 4,9,23,4 };
    check.checkBool(false, o.asteroidsDestroyed(5, asteroids));

    asteroids = { 4 };
    check.checkBool(false, o.asteroidsDestroyed(3, asteroids));
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
