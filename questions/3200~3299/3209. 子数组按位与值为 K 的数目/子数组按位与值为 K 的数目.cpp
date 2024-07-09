/* 子数组按位与值为 K 的数目.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你一个整数数组 nums 和一个整数 k ，请你返回 nums 中有多少个
子数组
满足：子数组中所有元素按位 AND 的结果为 k 。



示例 1：

输入：nums = [1,1,1], k = 1

输出：6

解释：

所有子数组都只含有元素 1 。

示例 2：

输入：nums = [1,1,2], k = 1

输出：3

解释：

按位 AND 值为 1 的子数组包括：[1,1,2], [1,1,2], [1,1,2] 。

示例 3：

输入：nums = [1,2,3], k = 2

输出：2

解释：

按位 AND 值为 2 的子数组包括：[1,2,3], [1,2,3] 。



提示：

1 <= nums.length <= 105
0 <= nums[i], k <= 109
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        long long subs = 0;
        int size = (int)nums.size(), left = 0, right = 0;
        vector<vector<int>> bit1s(maxBit, vector<int>(size + 1, 0));

        count(nums, size, bit1s);

        for (int i = 0; i < size; ++i) {
            while (left <= i && getSum(bit1s, left, i) < k) {  // [left, i]是第一个sum >= k的区间
                ++left;
            }

            while (right <= i && getSum(bit1s, right, i) <= k) {  // [right, i]是第一个sum > k的区间
                ++right;
            }

            subs += ((long long)right - left);  // [left, right)是sum = k的区间
        }

        return subs;
    }

    void count(vector<int>& nums, int size, vector<vector<int>>& bit1s) {
        for (int i = 0; i < size; ++i) {
            for (int j = 0, bit = 1; j < maxBit; ++j, bit <<= 1) {
                bit1s[j][i + 1] = bit1s[j][i] + ((nums[i] & bit) == 0 ? 0 : 1);
            }
        }
    }

    int getSum(vector<vector<int>>& bit1s, int left, int right) {
        int sum = 0, cnt = right - left + 1;

        for (int i = 0, bit = 1; i < maxBit; ++i, bit <<= 1) {
            if (bit1s[i][right + 1] - bit1s[i][left] == cnt) {
                sum |= bit;
            }
        }

        return sum;
    }

    int maxBit = 30;
};

int main()
{
    Solution o;
    CheckResult check;

    vector<int> nums = { 1,1,1 };
    check.checkLongLong(6, o.countSubarrays(nums, 1));

    nums = { 1,1,2 };
    check.checkLongLong(3, o.countSubarrays(nums, 1));

    nums = { 1,2,3 };
    check.checkLongLong(2, o.countSubarrays(nums, 2));

    nums = { 1,2,3,1,1,1,3,4,5,6,7,8,9,1,2,3,1,1,1,3,4,5,6,7,8,9,1,2,3,1,1,1,3,4,5,6,7,8,9,1,2,3,1,1,1,3,4,5,6,7,8,9 };
    check.checkLongLong(8, o.countSubarrays(nums, 2));

    nums = { 1,2,3,1,1,1,3,4,5,6,7,8,9,1,2,3,1,1,1,3,4,5,6,7,8,9,1,2,3,1,1,1,3,4,5,6,7,8,9,1,2,3,1,1,1,3,4,5,6,7,8,9 };
    check.checkLongLong(59, o.countSubarrays(nums, 1));
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
