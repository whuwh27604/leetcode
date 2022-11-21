/* 数组中不等三元组的数目.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你一个下标从 0 开始的正整数数组 nums 。请你找出并统计满足下述条件的三元组 (i, j, k) 的数目：

0 <= i < j < k < nums.length
nums[i]、nums[j] 和 nums[k] 两两不同 。
换句话说：nums[i] != nums[j]、nums[i] != nums[k] 且 nums[j] != nums[k] 。
返回满足上述条件三元组的数目。



示例 1：

输入：nums = [4,4,2,4,3]
输出：3
解释：下面列出的三元组均满足题目条件：
- (0, 2, 4) 因为 4 != 2 != 3
- (1, 2, 4) 因为 4 != 2 != 3
- (2, 3, 4) 因为 2 != 4 != 3
共计 3 个三元组，返回 3 。
注意 (2, 0, 4) 不是有效的三元组，因为 2 > 0 。
示例 2：

输入：nums = [1,1,1,1,1]
输出：0
解释：不存在满足条件的三元组，所以返回 0 。


提示：

3 <= nums.length <= 100
1 <= nums[i] <= 1000
*/

#include <iostream>
#include <map>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int unequalTriplets(vector<int>& nums) {
        map<int, int> numsCount;
        int triplets = 0, left = 0, right = nums.size();

        for (int num : nums) {
            ++numsCount[num];
        }

        for (auto& kv : numsCount) {
            right -= kv.second;
            triplets += (kv.second * left * right);
            left += kv.second;
        }

        return triplets;
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<int> nums = { 4,4,2,4,3 };
    check.checkInt(3, o.unequalTriplets(nums));

    nums = { 1,1,1,1,1 };
    check.checkInt(0, o.unequalTriplets(nums));
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
