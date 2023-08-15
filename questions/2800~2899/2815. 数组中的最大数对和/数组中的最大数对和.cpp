/* 数组中的最大数对和.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你一个下标从 0 开始的整数数组 nums 。请你从 nums 中找出和 最大 的一对数，且这两个数数位上最大的数字相等。

返回最大和，如果不存在满足题意的数字对，返回 -1 。



示例 1：

输入：nums = [51,71,17,24,42]
输出：88
解释：
i = 1 和 j = 2 ，nums[i] 和 nums[j] 数位上最大的数字相等，且这一对的总和 71 + 17 = 88 。
i = 3 和 j = 4 ，nums[i] 和 nums[j] 数位上最大的数字相等，且这一对的总和 24 + 42 = 66 。
可以证明不存在其他数对满足数位上最大的数字相等，所以答案是 88 。
示例 2：

输入：nums = [1,2,3,4]
输出：-1
解释：不存在数对满足数位上最大的数字相等。


提示：

2 <= nums.length <= 100
1 <= nums[i] <= 104
*/

#include <iostream>
#include <algorithm>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int maxSum(vector<int>& nums) {
        vector<int> maxNums(10, -1);
        int ans = -1;

        for (int num : nums) {
            int maxDigit = getMaxDigit(num);
            if (maxNums[maxDigit] == -1) {
                maxNums[maxDigit] = num;
            }
            else {
                ans = max(ans, num + maxNums[maxDigit]);
                maxNums[maxDigit] = max(maxNums[maxDigit], num);
            }
        }

        return ans;
    }

    int getMaxDigit(int num) {
        int digit = 0;

        while (num != 0) {
            digit = max(digit, num % 10);
            num /= 10;
        }

        return digit;
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<int> nums = { 51,71,17,24,42 };
    check.checkInt(88, o.maxSum(nums));

    nums = { 1,2,3,4 };
    check.checkInt(-1, o.maxSum(nums));
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
