/* 合法分组的最少组数.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你一个长度为 n 下标从 0 开始的整数数组 nums 。

我们想将下标进行分组，使得 [0, n - 1] 内所有下标 i 都 恰好 被分到其中一组。

如果以下条件成立，我们说这个分组方案是合法的：

对于每个组 g ，同一组内所有下标在 nums 中对应的数值都相等。
对于任意两个组 g1 和 g2 ，两个组中 下标数量 的 差值不超过 1 。
请你返回一个整数，表示得到一个合法分组方案的 最少 组数。



示例 1：

输入：nums = [3,2,3,2,3]
输出：2
解释：一个得到 2 个分组的方案如下，中括号内的数字都是下标：
组 1 -> [0,2,4]
组 2 -> [1,3]
所有下标都只属于一个组。
组 1 中，nums[0] == nums[2] == nums[4] ，所有下标对应的数值都相等。
组 2 中，nums[1] == nums[3] ，所有下标对应的数值都相等。
组 1 中下标数目为 3 ，组 2 中下标数目为 2 。
两者之差不超过 1 。
无法得到一个小于 2 组的答案，因为如果只有 1 组，组内所有下标对应的数值都要相等。
所以答案为 2 。
示例 2：

输入：nums = [10,10,10,3,1,1]
输出：4
解释：一个得到 2 个分组的方案如下，中括号内的数字都是下标：
组 1 -> [0]
组 2 -> [1,2]
组 3 -> [3]
组 4 -> [4,5]
分组方案满足题目要求的两个条件。
无法得到一个小于 4 组的答案。
所以答案为 4 。


提示：

1 <= nums.length <= 105
1 <= nums[i] <= 109
*/

#include <iostream>
#include <unordered_map>
#include <algorithm>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int minGroupsForValidAssignment(vector<int>& nums) {
        vector<int> count;

        countNums(nums, count);
        int minCnt = *min_element(count.begin(), count.end());
        int groups = -1;

        for (int cnt = minCnt; cnt > 0; --cnt) {  // 枚举分组后每组里面数的个数，最多只用讨论到minCnt
            groups = getGroups(count, cnt);
            if (groups != -1) {  // cnt越大时，分组越少，找到一个合法的就可以返回了
                break;
            }
        }

        return groups;
    }

    void countNums(vector<int>& nums, vector<int>& count) {
        unordered_map<int, int> mp;

        for (int num : nums) {
            ++mp[num];
        }

        for (auto& kv : mp) {
            count.push_back(kv.second);
        }
    }

    int getGroups(vector<int>& count, int cnt) {
        int groups = 0;

        for (int num : count) {
            int group = num / (cnt + 1), remainder = num % (cnt + 1);  // 优先按照每组cnt + 1个数分组
            if (remainder == 0) {  // 如果没有余数，刚好分为group个组
                groups += group;
            }
            else if (remainder + group >= cnt) {  // 如果有余数，从前面group个组每个组取一个，和余数一起放在group + 1组，这样至少要凑够cnt个
                groups += (group + 1);
            }
            else {  // 如果不够，则不能按照cnt、cnt + 1的方案分组
                return -1;  // num = group * (cnt + 1) + remainder，group + remainder < cnt，按照每组cnt个分组，也无法分完
            }
        }

        return groups;
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<int> nums = { 3,2,3,2,3 };
    check.checkInt(2, o.minGroupsForValidAssignment(nums));

    nums = { 10,10,10,3,1,1 };
    check.checkInt(4, o.minGroupsForValidAssignment(nums));
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
