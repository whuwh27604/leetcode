/* 数组的最大因子得分.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你一个整数数组 nums。

因子得分 定义为数组所有元素的最小公倍数（LCM）与最大公约数（GCD）的 乘积。

在 最多 移除一个元素的情况下，返回 nums 的 最大因子得分。

注意，单个数字的 LCM 和 GCD 都是其本身，而 空数组 的因子得分为 0。

lcm(a, b) 表示 a 和 b 的 最小公倍数。

gcd(a, b) 表示 a 和 b 的 最大公约数。



示例 1：

输入： nums = [2,4,8,16]

输出： 64

解释：

移除数字 2 后，剩余元素的 GCD 为 4，LCM 为 16，因此最大因子得分为 4 * 16 = 64。

示例 2：

输入： nums = [1,2,3,4,5]

输出： 60

解释：

无需移除任何元素即可获得最大因子得分 60。

示例 3：

输入： nums = [3]

输出： 9



提示：

1 <= nums.length <= 100
1 <= nums[i] <= 30
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    long long maxScore(vector<int>& nums) {
        int size = (int)nums.size();
        vector<long long> preGCD(size), sufGCD(size), preLCM(size), sufLCM(size);

        preGCD[0] = preLCM[0] = nums[0];
        sufGCD[size - 1] = sufLCM[size - 1] = nums[size - 1];

        for (int i = 1; i < size; ++i) {
            preGCD[i] = gcd(preGCD[i - 1], nums[i]);
            preLCM[i] = lcm(preLCM[i - 1], nums[i]);
        }

        for (int i = size - 2; i >= 0; --i) {
            sufGCD[i] = gcd(sufGCD[i + 1], nums[i]);
            sufLCM[i] = lcm(sufLCM[i + 1], nums[i]);
        }

        long long ans = preGCD[size - 1] * preLCM[size - 1];

        if (size > 1) {
            ans = max(ans, preGCD[size - 2] * preLCM[size - 2]);
            ans = max(ans, sufGCD[1] * sufLCM[1]);
        }

        for (int i = 1; i < size - 1; ++i) {
            ans = max(ans, gcd(preGCD[i - 1], sufGCD[i + 1]) * lcm(preLCM[i - 1], sufLCM[i + 1]));
        }

        return ans;
    }

    long long gcd(long long x, long long y) {
        return (y == 0) ? x : gcd(y, x % y);
    }

    long long lcm(long long x, long long y) {
        return x / gcd(x, y) * y;
    }
};

int main()
{
    Solution o;
    CheckResult check;

    vector<int> nums = { 2,4,8,16 };
    check.checkLongLong(64, o.maxScore(nums));

    nums = { 1,2,3,4,5 };
    check.checkLongLong(60, o.maxScore(nums));

    nums = { 3 };
    check.checkLongLong(9, o.maxScore(nums));

    nums = { 1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,21,22,23,24,25,26,27,28,29,30 };
    check.checkLongLong(2329089562800, o.maxScore(nums));
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
