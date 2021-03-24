/* 划分为k个相等的子集.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给定一个整数数组  nums 和一个正整数 k，找出是否有可能把这个数组分成 k 个非空子集，其总和都相等。

示例 1：

输入： nums = [4, 3, 2, 3, 5, 2, 1], k = 4
输出： True
说明： 有可能将其分成 4 个子集（5），（1,4），（2,3），（2,3）等于总和。
 

提示：

1 <= k <= len(nums) <= 16
0 < nums[i] < 10000

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/partition-to-k-equal-sum-subsets
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <algorithm>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        int size = nums.size(), maxNum = INT_MIN, sum = getSum(nums, maxNum), target = sum / k;
        if ((target * k != sum) || (target < maxNum)) {
            return false;
        }

        vector<bool> used(size, false);
        return dfs(nums, target, target, k, 0, used);
    }

    int getSum(vector<int>& nums, int& maxNum) {
        int sum = 0;

        for (int num : nums) {
            sum += num;
            maxNum = max(maxNum, num);
        }

        return sum;
    }

    bool dfs(vector<int>& nums, int target, int rest, int k, int start, vector<bool>& used) {
        if (k == 0) {  // 如果分出了k个组则表示成功了
            return true;
        }

        int i, size = nums.size();
        for (i = start; i < size; ++i) {  // 遍历数字取那些没被用过的数字
            if (!used[i]) {
                used[i] = true;

                /* 考虑两种情况：1、当前数字考虑后依然小于目标，则在当前组内递归(减少目标值，起始位置+1)
                   2、当前数字考虑后依然等于目标，则继续遍历下一组(重置目标和起始位置) */
                if ((nums[i] < rest && dfs(nums, target, rest - nums[i], k, i + 1, used))
                    || (nums[i] == rest && dfs(nums, target, target, k - 1, 0, used))) {
                    return true;
                }
                
                used[i] = false;  // 遍历完回溯
            }
        }

        return false;
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<int> nums = { 4,3,2,3,5,2,1 };
    check.checkBool(true, o.canPartitionKSubsets(nums, 4));
    
    nums = { 3,1,1,4,2,4 };
    check.checkBool(true, o.canPartitionKSubsets(nums, 3));

    nums = { 10,10,10,7,7,7,7,7,7,6,6,6 };
    check.checkBool(true, o.canPartitionKSubsets(nums, 3));

    nums = { 1,2,3,4 };
    check.checkBool(false, o.canPartitionKSubsets(nums, 4));

    nums = { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1 };
    check.checkBool(true, o.canPartitionKSubsets(nums, 2));

    nums = { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1 };
    check.checkBool(true, o.canPartitionKSubsets(nums, 8));

    nums = { 0 };
    check.checkBool(true, o.canPartitionKSubsets(nums, 1));

    nums = { 0 };
    check.checkBool(false, o.canPartitionKSubsets(nums, 2));
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
