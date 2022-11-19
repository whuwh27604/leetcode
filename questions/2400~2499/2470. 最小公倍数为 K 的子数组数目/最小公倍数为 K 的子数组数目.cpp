/* 最小公倍数为 K 的子数组数目.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你一个整数数组 nums 和一个整数 k ，请你统计并返回 nums 的 子数组 中满足 元素最小公倍数为 k 的子数组数目。

子数组 是数组中一个连续非空的元素序列。

数组的最小公倍数 是可被所有数组元素整除的最小正整数。



示例 1 ：

输入：nums = [3,6,2,7,1], k = 6
输出：4
解释：以 6 为最小公倍数的子数组是：
- [3,6,2,7,1]
- [3,6,2,7,1]
- [3,6,2,7,1]
- [3,6,2,7,1]
示例 2 ：

输入：nums = [3], k = 2
输出：0
解释：不存在以 2 为最小公倍数的子数组。


提示：

1 <= nums.length <= 1000
1 <= nums[i], k <= 1000
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int subarrayLCM(vector<int>& nums, int k) {
        int size = nums.size(), count = 0;

        for (int i = 0; i < size; ++i) {
            if (k % nums[i] != 0) {
                continue;
            }

            int lcm = nums[i];
            if (lcm == k) {
                ++count;
            }

            for (int j = i + 1; j < size && lcm <= k; ++j) {
                lcm = lcm * nums[j] / gcd(lcm, nums[j]);
                if (lcm == k) {
                    ++count;
                }
            }
        }

        return count;
    }

    int gcd(int x, int y) {
        return (y == 0) ? x : gcd(y, x % y);
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<int> nums = { 3,6,2,7,1 };
    check.checkInt(4, o.subarrayLCM(nums, 6));

    nums = { 3 };
    check.checkInt(0, o.subarrayLCM(nums, 2));

    nums = { 2,3,2,2,3,3 };
    check.checkInt(13, o.subarrayLCM(nums, 6));

    nums = { 2,3,2,2,3,3,2,2,2,3,3,3,2,2,2,2,3,3,3,3 };
    check.checkInt(170, o.subarrayLCM(nums, 6));

    nums = { 7,2,1,4,4,2,3 };
    check.checkInt(11, o.subarrayLCM(nums, 4));
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
