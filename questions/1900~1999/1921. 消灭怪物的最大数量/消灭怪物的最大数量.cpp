/* 消灭怪物的最大数量.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
你正在玩一款电子游戏，在游戏中你需要保护城市免受怪物侵袭。给你一个 下标从 0 开始 且长度为 n 的整数数组 dist ，其中 dist[i] 是第 i 个怪物与城市的 初始距离（单位：米）。

怪物以 恒定 的速度走向城市。给你一个长度为 n 的整数数组 speed 表示每个怪物的速度，其中 speed[i] 是第 i 个怪物的速度（单位：米/分）。

怪物从 第 0 分钟 时开始移动。你有一把武器，并可以 选择 在每一分钟的开始时使用，包括第 0 分钟。但是你无法在一分钟的中间使用武器。这种武器威力惊人，一次可以消灭任一还活着的怪物。

一旦任一怪物到达城市，你就输掉了这场游戏。如果某个怪物 恰 在某一分钟开始时到达城市，这会被视为 输掉 游戏，在你可以使用武器之前，游戏就会结束。

返回在你输掉游戏前可以消灭的怪物的 最大 数量。如果你可以在所有怪物到达城市前将它们全部消灭，返回  n 。

 

示例 1：

输入：dist = [1,3,4], speed = [1,1,1]
输出：3
解释：
第 0 分钟开始时，怪物的距离是 [1,3,4]，你消灭了第一个怪物。
第 1 分钟开始时，怪物的距离是 [X,2,3]，你没有消灭任何怪物。
第 2 分钟开始时，怪物的距离是 [X,1,2]，你消灭了第二个怪物。
第 3 分钟开始时，怪物的距离是 [X,X,1]，你消灭了第三个怪物。
所有 3 个怪物都可以被消灭。
示例 2：

输入：dist = [1,1,2,3], speed = [1,1,1,1]
输出：1
解释：
第 0 分钟开始时，怪物的距离是 [1,1,2,3]，你消灭了第一个怪物。
第 1 分钟开始时，怪物的距离是 [X,0,1,2]，你输掉了游戏。
你只能消灭 1 个怪物。
示例 3：

输入：dist = [3,2,4], speed = [5,3,2]
输出：1
解释：
第 0 分钟开始时，怪物的距离是 [3,2,4]，你消灭了第一个怪物。
第 1 分钟开始时，怪物的距离是 [X,0,2]，你输掉了游戏。
你只能消灭 1 个怪物。
 

提示：

n == dist.length == speed.length
1 <= n <= 105
1 <= dist[i], speed[i] <= 105

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/eliminate-maximum-number-of-monsters
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <queue>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int eliminateMaximum(vector<int>& dist, vector<int>& speed) {
        int i, size = dist.size(), time = 0, monsters = 0;
        priority_queue<int, vector<int>, greater<int>> times;

        for (i = 0; i < size; ++i) {
            times.push((int)ceil((double)dist[i] / speed[i]));
        }

        while (!times.empty() && time < times.top()) {
            times.pop();
            time += 1;
            monsters += 1;
        }

        return monsters;
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<int> dist = { 1,3,4 };
    vector<int> speed = { 1,1,1 };
    check.checkInt(3, o.eliminateMaximum(dist, speed));

    dist = { 1,1,2,3 };
    speed = { 1,1,1,1 };
    check.checkInt(1, o.eliminateMaximum(dist, speed));

    dist = { 3,2,4 };
    speed = { 5,3,2 };
    check.checkInt(1, o.eliminateMaximum(dist, speed));
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
