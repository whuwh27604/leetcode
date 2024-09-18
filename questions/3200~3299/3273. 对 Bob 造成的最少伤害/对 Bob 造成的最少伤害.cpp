/* 对 Bob 造成的最少伤害.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你一个整数 power 和两个整数数组 damage 和 health ，两个数组的长度都为 n 。

Bob 有 n 个敌人，如果第 i 个敌人还活着（也就是健康值 health[i] > 0 的时候），每秒钟会对 Bob 造成 damage[i] 点 伤害。

每一秒中，在敌人对 Bob 造成伤害 之后 ，Bob 会选择 一个 还活着的敌人进行攻击，该敌人的健康值减少 power 。

请你返回 Bob 将 所有 n 个敌人都消灭之前，最少 会收到多少伤害。



示例 1：

输入：power = 4, damage = [1,2,3,4], health = [4,5,6,8]

输出：39

解释：

最开始 2 秒内都攻击敌人 3 ，然后敌人 3 会被消灭，这段时间内对 Bob 的总伤害是 10 + 10 = 20 点。
接下来 2 秒内都攻击敌人 2 ，然后敌人 2 会被消灭，这段时间内对 Bob 的总伤害是 6 + 6 = 12 点。
接下来 1 秒内都攻击敌人 0 ，然后敌人 0 会被消灭，这段时间内对 Bob 的总伤害是 3 点。
接下来 2 秒内都攻击敌人 1 ，然后敌人 1 会被消灭，这段时间内对 Bob 的总伤害是 2 + 2 = 4 点。
示例 2：

输入：power = 1, damage = [1,1,1,1], health = [1,2,3,4]

输出：20

解释：

最开始 1 秒内都攻击敌人 0 ，然后敌人 0 会被消灭，这段时间对 Bob 的总伤害是 4 点。
接下来 2 秒内都攻击敌人 1 ，然后敌人 1 会被消灭，这段时间对 Bob 的总伤害是 3 + 3 = 6 点。
接下来 3 秒内都攻击敌人 2 ，然后敌人 2 会被消灭，这段时间对 Bob 的总伤害是 2 + 2 + 2 = 6 点。
接下来 4 秒内都攻击敌人 3 ，然后敌人 3 会被消灭，这段时间对 Bob 的总伤害是 1 + 1 + 1 + 1 = 4 点。
示例 3：

输入：power = 8, damage = [40], health = [59]

输出：320



提示：

1 <= power <= 104
1 <= n == damage.length == health.length <= 105
1 <= damage[i], health[i] <= 104
*/

#include <iostream>
#include <algorithm>
#include "../check/CheckResult.h"

using namespace std;

class Node {
public:
    int damage;
    int time;

    Node() : damage(0), time(0) {}
    Node(int d, int t) : damage(d), time(t) {}

    bool operator<(const Node& o) const {
        return damage * o.time > o.damage * time;
    }
};

class Solution {
public:
    long long minDamage(int power, vector<int>& damage, vector<int>& health) {
        long long totalDamage = 0, time = 0;
        int size = (int)damage.size();
        vector<Node> nodes(size);

        for (int i = 0; i < size; ++i) {
            nodes[i] = Node(damage[i], (health[i] - 1) / power + 1);
        }

        sort(nodes.begin(), nodes.end());

        for (Node& node : nodes) {
            time += node.time;
            totalDamage += node.damage * time;
        }

        return totalDamage;
    }
};

int main()
{
    Solution o;
    CheckResult check;

    vector<int> damage = { 1,2,3,4 };
    vector<int> health = { 4,5,6,8 };
    check.checkLongLong(39, o.minDamage(4, damage, health));

    damage = { 1,1,1,1 };
    health = { 1,2,3,4 };
    check.checkLongLong(20, o.minDamage(1, damage, health));
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
