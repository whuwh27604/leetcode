/* 划分技能点相等的团队.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你一个正整数数组 skill ，数组长度为 偶数 n ，其中 skill[i] 表示第 i 个玩家的技能点。将所有玩家分成 n / 2 个 2 人团队，使每一个团队的技能点之和 相等 。

团队的 化学反应 等于团队中玩家的技能点 乘积 。

返回所有团队的 化学反应 之和，如果无法使每个团队的技能点之和相等，则返回 -1 。



示例 1：

输入：skill = [3,2,5,1,3,4]
输出：22
解释：
将玩家分成 3 个团队 (1, 5), (2, 4), (3, 3) ，每个团队的技能点之和都是 6 。
所有团队的化学反应之和是 1 * 5 + 2 * 4 + 3 * 3 = 5 + 8 + 9 = 22 。
示例 2：

输入：skill = [3,4]
输出：12
解释：
两个玩家形成一个团队，技能点之和是 7 。
团队的化学反应是 3 * 4 = 12 。
示例 3：

输入：skill = [1,1,2,3]
输出：-1
解释：
无法将玩家分成每个团队技能点都相等的若干个 2 人团队。


提示：

2 <= skill.length <= 105
skill.length 是偶数
1 <= skill[i] <= 1000
*/

#include <iostream>
#include <unordered_map>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    long long dividePlayers(vector<int>& skill) {
        unordered_map<int, int> count;
        int sum = 0, size = skill.size(), group = size / 2;
        long long chemistry = 0;

        for (int ski : skill) {
            sum += ski;
            ++count[ski];
        }

        int target = sum / group;
        if (target * group != sum) {
            return -1;
        }

        if (target % 2 == 0) {
            int half = target / 2;
            if (count[half] != 0) {
                if (count[half] % 2 != 0) {
                    return -1;
                }
                chemistry += ((long long)half * half * count[half] / 2);
                count[half] = 0;
            }
        }

        for (auto& kv : count) {
            if (kv.second != 0) {
                if (count[target - kv.first] != kv.second) {
                    return -1;
                }
                chemistry += (kv.first * ((long long)target - kv.first) * kv.second);
                kv.second = 0;
                count[target - kv.first] = 0;
            }
        }

        return chemistry;
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<int> skill = { 3,2,5,1,3,4 };
    check.checkLongLong(22, o.dividePlayers(skill));

    skill = { 3,4 };
    check.checkLongLong(12, o.dividePlayers(skill));

    skill = { 1,1,2,3 };
    check.checkLongLong(-1, o.dividePlayers(skill));

    skill = { 3,3,3,3 };
    check.checkLongLong(18, o.dividePlayers(skill));
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
