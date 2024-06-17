/* 施咒的最大总伤害.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
一个魔法师有许多不同的咒语。

给你一个数组 power ，其中每个元素表示一个咒语的伤害值，可能会有多个咒语有相同的伤害值。

已知魔法师使用伤害值为 power[i] 的咒语时，他们就 不能 使用伤害为 power[i] - 2 ，power[i] - 1 ，power[i] + 1 或者 power[i] + 2 的咒语。

每个咒语最多只能被使用 一次 。

请你返回这个魔法师可以达到的伤害值之和的 最大值 。



示例 1：

输入：power = [1,1,3,4]

输出：6

解释：

可以使用咒语 0，1，3，伤害值分别为 1，1，4，总伤害值为 6 。

示例 2：

输入：power = [7,1,6,6]

输出：13

解释：

可以使用咒语 1，2，3，伤害值分别为 1，6，6，总伤害值为 13 。



提示：

1 <= power.length <= 105
1 <= power[i] <= 109
*/

#include <iostream>
#include <map>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    long long maximumTotalDamage(vector<int>& power) {
        vector<int> nums, cnt;
        count(power, nums, cnt);
        int size = (int)cnt.size();
        vector<long long> damage(size, 0);
        damage[0] = (long long)nums[0] * cnt[0];

        for (int i = 1; i < size; ++i) {
            damage[i] = damage[i - 1];  // 不选nums[i]

            int j = i - 1;
            while (j >= 0 && nums[i] - nums[j] <= 2) {
                --j;
            }

            damage[i] = max(damage[i], (long long)nums[i] * cnt[i] + (j >= 0 ? damage[j] : 0));  // 选择nums[i]
        }

        return damage.back();
    }

    void count(vector<int>& power, vector<int>& nums, vector<int>& cnt) {
        map<int, int> numsCount;

        for (int num : power) {
            ++numsCount[num];
        }

        for (auto& kv : numsCount) {
            nums.push_back(kv.first);
            cnt.push_back(kv.second);
        }
    }
};

int main()
{
    Solution o;
    CheckResult check;

    vector<int> power = { 1,1,3,4 };
    check.checkLongLong(6, o.maximumTotalDamage(power));

    power = { 7,1,6,6 };
    check.checkLongLong(13, o.maximumTotalDamage(power));

    power = { 7,1,6,3 };
    check.checkLongLong(10, o.maximumTotalDamage(power));
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
