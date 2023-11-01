/* 找出数组中的 K-or 值.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你一个下标从 0 开始的整数数组 nums 和一个整数 k 。

nums 中的 K-or 是一个满足以下条件的非负整数：

只有在 nums 中，至少存在 k 个元素的第 i 位值为 1 ，那么 K-or 中的第 i 位的值才是 1 。
返回 nums 的 K-or 值。

注意 ：对于整数 x ，如果 (2i AND x) == 2i ，则 x 中的第 i 位值为 1 ，其中 AND 为按位与运算符。



示例 1：

输入：nums = [7,12,9,8,9,15], k = 4
输出：9
解释：nums[0]、nums[2]、nums[4] 和 nums[5] 的第 0 位的值为 1 。
nums[0] 和 nums[5] 的第 1 位的值为 1 。
nums[0]、nums[1] 和 nums[5] 的第 2 位的值为 1 。
nums[1]、nums[2]、nums[3]、nums[4] 和 nums[5] 的第 3 位的值为 1 。
只有第 0 位和第 3 位满足数组中至少存在 k 个元素在对应位上的值为 1 。因此，答案为 2^0 + 2^3 = 9 。
示例 2：

输入：nums = [2,12,1,11,4,5], k = 6
输出：0
解释：因为 k == 6 == nums.length ，所以数组的 6-or 等于其中所有元素按位与运算的结果。因此，答案为 2 AND 12 AND 1 AND 11 AND 4 AND 5 = 0 。
示例 3：

输入：nums = [10,8,5,9,11,6,8], k = 1
输出：15
解释：因为 k == 1 ，数组的 1-or 等于其中所有元素按位或运算的结果。因此，答案为 10 OR 8 OR 5 OR 9 OR 11 OR 6 OR 8 = 15 。


提示：

1 <= nums.length <= 50
0 <= nums[i] < 231
1 <= k <= nums.length
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int findKOr(vector<int>& nums, int k) {
        int kor = 0, maxBit = (1 << 30);

        for (long long bit = 1; bit <= maxBit; bit <<= 1) {
            int count = 0;

            for (int num : nums) {
                if ((num & bit) != 0) {
                    if (++count == k) {
                        kor |= bit;
                        break;
                    }
                }
            }
        }

        return kor;
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<int> nums = { 7,12,9,8,9,15 };
    check.checkInt(9, o.findKOr(nums, 4));

    nums = { 2,12,1,11,4,5 };
    check.checkInt(0, o.findKOr(nums, 6));

    nums = { 10,8,5,9,11,6,8 };
    check.checkInt(15, o.findKOr(nums, 1));
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
