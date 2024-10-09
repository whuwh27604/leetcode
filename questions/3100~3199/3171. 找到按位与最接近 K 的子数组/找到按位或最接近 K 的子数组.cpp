/* 找到按位与最接近 K 的子数组.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你一个数组 nums 和一个整数 k 。你需要找到 nums 的一个
子数组
 ，满足子数组中所有元素按位或运算 OR 的值与 k 的 绝对差 尽可能 小 。换言之，你需要选择一个子数组 nums[l..r] 满足 |k - (nums[l] OR nums[l + 1] ... OR nums[r])| 最小。

请你返回 最小 的绝对差值。

子数组 是数组中连续的 非空 元素序列。



示例 1：

输入：nums = [1,2,4,5], k = 3

输出：0

解释：

子数组 nums[0..1] 的按位 OR 运算值为 3 ，得到最小差值 |3 - 3| = 0 。

示例 2：

输入：nums = [1,3,1,3], k = 2

输出：1

解释：

子数组 nums[1..1] 的按位 OR 运算值为 3 ，得到最小差值 |3 - 2| = 1 。

示例 3：

输入：nums = [1], k = 10

输出：9

解释：

只有一个子数组，按位 OR 运算值为 1 ，得到最小差值 |10 - 1| = 9 。



提示：

1 <= nums.length <= 105
1 <= nums[i] <= 109
1 <= k <= 109
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int minimumDifference(vector<int>& nums, int k) {
        int size = (int)nums.size(), left = 0, right = 0, sum = 0, minDiff = INT_MAX;
        vector<int> count(maxSize, 0);  // 关键是窗口左端移除时，如何快速计算sum，通过count统计每个bit位来解决这个问题

        for (; left < size; ++left) {
            while (right < size && ((sum | nums[right]) <= k)) {  // sum还小于k时，可以继续扩大窗口
                sum |= nums[right];
                minDiff = min(minDiff, k - sum);
                add(count, nums[right++]);
            }

            if (right < size) {
                minDiff = min(minDiff, (sum | nums[right]) - k);
            }

            if (right > left) {  // 如果有合法窗口，移除最左端
                sum = minus(count, nums[left]);
            }
            else {  // 否则right也要自增，避免下个循环比left小
                ++right;
            }
        }

        return minDiff;
    }

    void add(vector<int>& count, int num) {
        int idx = 0;

        while (num != 0) {
            count[idx++] += (num & 1);
            num >>= 1;
        }
    }

    int minus(vector<int>& count, int num) {
        int sum = 0;

        for (int i = 0, bit = 1; i < maxSize; ++i, bit <<= 1) {
            count[i] -= (num & 1);
            if (count[i] != 0) {  // 移除左端后，剩下的1的个数不为0，说明sum的该bit位为1
                sum |= bit;
            }
            num >>= 1;
        }

        return sum;
    }

    int maxSize = 30;
};

int main()
{
    Solution o;
    CheckResult check;

    vector<int> nums = { 1,2,4,5 };
    check.checkInt(0, o.minimumDifference(nums, 3));

    nums = { 1,3,1,3 };
    check.checkInt(1, o.minimumDifference(nums, 2));

    nums = { 1 };
    check.checkInt(9, o.minimumDifference(nums, 10));

    nums = { 6 };
    check.checkInt(4, o.minimumDifference(nums, 2));

    nums = { 1,10 };
    check.checkInt(4, o.minimumDifference(nums, 6));
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
