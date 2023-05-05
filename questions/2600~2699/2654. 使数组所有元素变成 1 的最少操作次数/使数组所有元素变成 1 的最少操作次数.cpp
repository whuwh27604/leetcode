/* 使数组所有元素变成 1 的最少操作次数.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你一个下标从 0 开始的 正 整数数组 nums 。你可以对数组执行以下操作 任意 次：

选择一个满足 0 <= i < n - 1 的下标 i ，将 nums[i] 或者 nums[i+1] 两者之一替换成它们的最大公约数。
请你返回使数组 nums 中所有元素都等于 1 的 最少 操作次数。如果无法让数组全部变成 1 ，请你返回 -1 。

两个正整数的最大公约数指的是能整除这两个数的最大正整数。



示例 1：

输入：nums = [2,6,3,4]
输出：4
解释：我们可以执行以下操作：
- 选择下标 i = 2 ，将 nums[2] 替换为 gcd(3,4) = 1 ，得到 nums = [2,6,1,4] 。
- 选择下标 i = 1 ，将 nums[1] 替换为 gcd(6,1) = 1 ，得到 nums = [2,1,1,4] 。
- 选择下标 i = 0 ，将 nums[0] 替换为 gcd(2,1) = 1 ，得到 nums = [1,1,1,4] 。
- 选择下标 i = 2 ，将 nums[3] 替换为 gcd(1,4) = 1 ，得到 nums = [1,1,1,1] 。
示例 2：

输入：nums = [2,10,6,14]
输出：-1
解释：无法将所有元素都变成 1 。


提示：

2 <= nums.length <= 50
1 <= nums[i] <= 106
*/

#include <iostream>
#include <algorithm>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int minOperations(vector<int>& nums) {
        int size = nums.size(), low = 2, high = size, minLen = INT_MAX;

        int ones = countOnes(nums);
        if (ones != 0) {
            return size - ones;
        }

        for (int left = 0; left < size - 1; ++left) {
            int result = nums[left];

            for (int right = left + 1; right < size; ++right) {
                result = gcd(result, nums[right]);
                if (result == 1) {
                    minLen = min(minLen, right - left + 1);
                    break;
                }
            }
        }

        return minLen == INT_MAX ? -1 : minLen - 1 + size - 1;  // 长度为minLen的数组，需要minLen - 1步操作出第一个1，然后还需要size - 1步将剩下的数都变为1
    }

    int countOnes(vector<int>& nums) {
        int count = 0;

        for (int num : nums) {
            if (num == 1) {
                ++count;
            }
        }

        return count;
    }

    int gcd(int x, int y) {
        return y == 0 ? x : gcd(y, x % y);
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<int> nums = { 2,6,3,4 };
    check.checkInt(4, o.minOperations(nums));

    nums = { 2,10,6,14 };
    check.checkInt(-1, o.minOperations(nums));
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
