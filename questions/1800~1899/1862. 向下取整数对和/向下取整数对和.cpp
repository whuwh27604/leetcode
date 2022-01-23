/* 向下取整数对和.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你一个整数数组 nums ，请你返回所有下标对 0 <= i, j < nums.length 的 floor(nums[i] / nums[j]) 结果之和。由于答案可能会很大，请你返回答案对109 + 7 取余 的结果。

函数 floor() 返回输入数字的整数部分。

 

示例 1：

输入：nums = [2,5,9]
输出：10
解释：
floor(2 / 5) = floor(2 / 9) = floor(5 / 9) = 0
floor(2 / 2) = floor(5 / 5) = floor(9 / 9) = 1
floor(5 / 2) = 2
floor(9 / 2) = 4
floor(9 / 5) = 1
我们计算每一个数对商向下取整的结果并求和得到 10 。
示例 2：

输入：nums = [7,7,7,7,7,7,7]
输出：49
 

提示：

1 <= nums.length <= 105
1 <= nums[i] <= 105

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/sum-of-floored-pairs
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <algorithm>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int sumOfFlooredPairs(vector<int>& nums) {
        int maxNum = *max_element(nums.begin(), nums.end());

        vector<int> counts(maxNum + 1, 0);
        getCounts(nums, counts);

        vector<int> presums(maxNum + 1, 0);
        getPresums(counts, presums);

        return getSum(counts, presums, maxNum);
    }

    void getCounts(vector<int>& nums, vector<int>& counts) {
        for (int num : nums) {
            ++counts[num];
        }
    }

    void getPresums(vector<int>& counts, vector<int>& presums) {
        for (int i = 1; i < (int)counts.size(); ++i) {
            presums[i] = presums[i - 1] + counts[i];
        }
    }

    int getSum(vector<int>& counts, vector<int>& presums, int maxNum) {
        long long sum = 0;

        for (int divisor = 1; divisor <= maxNum; ++divisor) {
            if (counts[divisor] != 0) {
                for (int quotient = 1; quotient * divisor <= maxNum; ++quotient) {
                    int low = quotient * divisor - 1, high = low + divisor;
                    sum = (sum + quotient * ((long long)presums[high > maxNum ? maxNum : high] - presums[low]) * counts[divisor]) % 1000000007;
                }
            }
        }

        return (int)sum;
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<int> nums = { 2,5,9 };
    check.checkInt(10, o.sumOfFlooredPairs(nums));

    nums = { 1,1,1 };
    check.checkInt(9, o.sumOfFlooredPairs(nums));

    nums = { 1,2,3 };
    check.checkInt(9, o.sumOfFlooredPairs(nums));

    nums = { 7,7,7,7,7,7,7 };
    check.checkInt(49, o.sumOfFlooredPairs(nums));

    nums = { 1,2,3,4,5,6,7,8,9,10,101,102,103,104,105,106,107,108,109,110,1001,1002,1003,1004,1005,1006,1007,1008,1009,1100,9998,9997,9996,9995,9999,10000 };
    check.checkInt(215780, o.sumOfFlooredPairs(nums));

    nums = vector<int>(99999, 1);
    nums.push_back(100000);
    check.checkInt(999699869, o.sumOfFlooredPairs(nums));
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
