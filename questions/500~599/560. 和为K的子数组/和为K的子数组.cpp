/* 和为K的子数组.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给定一个整数数组和一个整数 k，你需要找到该数组中和为 k 的连续的子数组的个数。

示例 1 :

输入:nums = [1,1,1], k = 2
输出: 2 , [1,1] 与 [1,1] 为两种不同的情况。
说明 :

数组的长度为 [1, 20,000]。
数组中元素的范围是 [-1000, 1000] ，且整数 k 的范围是 [-1e7, 1e7]。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/subarray-sum-equals-k
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <unordered_map>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> prefixSumCount = { {0,1} };
        int sum = 0, count = 0;

        for (int num : nums) {
            sum += num;

            auto iter = prefixSumCount.find(sum - k);
            if (iter != prefixSumCount.end()) {
                count += iter->second;
            }

            iter = prefixSumCount.find(sum);
            if (iter != prefixSumCount.end()) {
                iter->second++;
            }
            else {
                prefixSumCount[sum] = 1;
            }
        }

        return count;
    }
};

int main()
{
    Solution o;
    CheckResult check;

    vector<int> nums = { 1,1,1 };
    check.checkInt(2, o.subarraySum(nums, 2));

    nums = { 5 };
    check.checkInt(1, o.subarraySum(nums, 5));

    nums = { 5 };
    check.checkInt(0, o.subarraySum(nums, 6));

    nums = { 5,1,-1,1,-1,1,-1,1,-1 };
    check.checkInt(5, o.subarraySum(nums, 5));

    nums = { 5,1,-1,1,-1,1,-1,1,-1 };
    check.checkInt(4, o.subarraySum(nums, 6));

    nums = { 5,1,-1,1,-1,1,-1,1,-1 };
    check.checkInt(10, o.subarraySum(nums, 1));

    nums = { 5,1,-1,1,-1,1,-1,1,-1 };
    check.checkInt(10, o.subarraySum(nums, -1));

    nums = { 5,1,-1,1,-1,1,-1,1,-1 };
    check.checkInt(16, o.subarraySum(nums, 0));

    nums = { 5,1,-1,1,-1,1,-1,1,-1 };
    check.checkInt(0, o.subarraySum(nums, 2));

    nums = { 1,2,-1,1 };
    check.checkInt(2, o.subarraySum(nums, 3));

    nums = { -1,-1,1,-1,1 };
    check.checkInt(4, o.subarraySum(nums, 0));

    nums = { 1,2,3 };
    check.checkInt(2, o.subarraySum(nums, 3));

    nums = { 2,-1,3,4,-2 };
    check.checkInt(3, o.subarraySum(nums, 2));

    nums = { 0,0,0,0,0,0,0,0,0,0 };
    check.checkInt(55, o.subarraySum(nums, 0));

    nums = { 28,54,7,-70,22,65,-6 };
    check.checkInt(1, o.subarraySum(nums, 100));
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
