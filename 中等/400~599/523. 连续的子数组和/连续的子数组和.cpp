/* 连续的子数组和.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给定一个包含 非负数 的数组和一个目标 整数 k，编写一个函数来判断该数组是否含有连续的子数组，其大小至少为 2，且总和为 k 的倍数，即总和为 n*k，其中 n 也是一个整数。

 

示例 1：

输入：[23,2,4,6,7], k = 6
输出：True
解释：[2,4] 是一个大小为 2 的子数组，并且和为 6。
示例 2：

输入：[23,2,6,4,7], k = 6
输出：True
解释：[23,2,6,4,7]是大小为 5 的子数组，并且和为 42。
 

说明：

数组的长度不会超过 10,000 。
你可以认为所有数字总和在 32 位有符号整数范围内。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/continuous-subarray-sum
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <unordered_map>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> sumRemainderIndex;
        sumRemainderIndex[0] = -1;
        int i, size = nums.size(), sum = 0;

        for (i = 0; i < size; i++) {
            sum += nums[i];
            if (k != 0) {
                sum %= k;
            }

            auto iter = sumRemainderIndex.find(sum);
            if (iter == sumRemainderIndex.end()) {
                sumRemainderIndex[sum] = i;
            }
            else if ((i - iter->second) > 1) {  // 两次的余数相等，说明在区间(iter->second, i]内的数是k的倍数。避免nums[i]直接是k的倍数，所以要大于1
                return true;
            }
        }

        return false;
    }
};

int main()
{
    Solution o;
    CheckResult check;

    vector<int> nums = { 23,2,4,6,7 };
    check.checkBool(true, o.checkSubarraySum(nums, 6));

    nums = { 23,2,4,6,7 };
    check.checkBool(true, o.checkSubarraySum(nums, -6));
    
    nums = { 23,2,4,6,7 };
    check.checkBool(true, o.checkSubarraySum(nums, -1));

    nums = { 23,2,6,4,7 };
    check.checkBool(true, o.checkSubarraySum(nums, 6));

    nums = {  };
    check.checkBool(false, o.checkSubarraySum(nums, 1));

    nums = { 1 };
    check.checkBool(false, o.checkSubarraySum(nums, 1));

    nums = { 1,0 };
    check.checkBool(true, o.checkSubarraySum(nums, 1));

    nums = { 1,0 };
    check.checkBool(false, o.checkSubarraySum(nums, 0));

    nums = { 0,0 };
    check.checkBool(true, o.checkSubarraySum(nums, 0));

    nums = { 0,0 };
    check.checkBool(true, o.checkSubarraySum(nums, -1));

    nums = { 23,0,0 };
    check.checkBool(true, o.checkSubarraySum(nums, 6));

    nums = { 0,1,0 };
    check.checkBool(false, o.checkSubarraySum(nums, 0));

    nums = { 0,1,0,1,0,1 };
    check.checkBool(false, o.checkSubarraySum(nums, 0));
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
