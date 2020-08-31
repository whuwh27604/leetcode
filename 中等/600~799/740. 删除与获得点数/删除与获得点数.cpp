/* 删除与获得点数.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给定一个整数数组 nums ，你可以对它进行一些操作。

每次操作中，选择任意一个 nums[i] ，删除它并获得 nums[i] 的点数。之后，你必须删除每个等于 nums[i] - 1 或 nums[i] + 1 的元素。

开始你拥有 0 个点数。返回你能通过这些操作获得的最大点数。

示例 1:

输入: nums = [3, 4, 2]
输出: 6
解释:
删除 4 来获得 4 个点数，因此 3 也被删除。
之后，删除 2 来获得 2 个点数。总共获得 6 个点数。
示例 2:

输入: nums = [2, 2, 3, 3, 3, 4]
输出: 9
解释:
删除 3 来获得 3 个点数，接着要删除两个 2 和 4 。
之后，再次删除 3 获得 3 个点数，再次删除 3 获得 3 个点数。
总共获得 9 个点数。
注意:

nums的长度最大为20000。
每个整数nums[i]的大小都在[1, 10000]范围内。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/delete-and-earn
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <map>
#include <algorithm>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        if (nums.empty()) {
            return 0;
        }

        vector<pair<int, int>> numsCount;
        countNums(nums, numsCount);

        int i, size = numsCount.size();
        int* dp = new int[size + 1];
        dp[0] = 0;
        dp[1] = numsCount[0].first * numsCount[0].second;

        for (i = 1; i < size; i++) {
            if (numsCount[i].first != numsCount[i - 1].first + 1) {
                dp[i + 1] = dp[i] + numsCount[i].first * numsCount[i].second;
            }
            else {
                dp[i + 1] = max(dp[i], dp[i - 1] + numsCount[i].first * numsCount[i].second);
            }
        }

        int earn = dp[size];
        delete[] dp;

        return earn;
    }

    void countNums(vector<int>& nums, vector<pair<int, int>>& numsCount) {
        map<int, int> count;

        for (int num : nums) {
            auto iter = count.find(num);
            if (iter == count.end()) {
                count[num] = 1;
            }
            else {
                iter->second++;
            }
        }

        for (auto iter = count.begin(); iter != count.end(); iter++) {
            numsCount.push_back({ iter->first, iter->second });
        }
    }
};

int main()
{
    Solution o;
    CheckResult check;

    vector<int> nums = { 3,4,2 };
    check.checkInt(6, o.deleteAndEarn(nums));

    nums = { 2,2,3,3,3,4 };
    check.checkInt(9, o.deleteAndEarn(nums));

    nums = { 73,74,75,71,69,72,76,73 };
    check.checkInt(362, o.deleteAndEarn(nums));

    nums = {  };
    check.checkInt(0, o.deleteAndEarn(nums));

    nums = { 5 };
    check.checkInt(5, o.deleteAndEarn(nums));

    nums = { 5,5 };
    check.checkInt(10, o.deleteAndEarn(nums));

    nums = { 5,6 };
    check.checkInt(6, o.deleteAndEarn(nums));
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
