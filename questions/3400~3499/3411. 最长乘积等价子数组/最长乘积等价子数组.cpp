/* 最长乘积等价子数组.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你一个由 正整数 组成的数组 nums。

如果一个数组 arr 满足 prod(arr) == lcm(arr) * gcd(arr)，则称其为 乘积等价数组 ，其中：

prod(arr) 表示 arr 中所有元素的乘积。
gcd(arr) 表示 arr 中所有元素的最大公因数 (GCD)。
lcm(arr) 表示 arr 中所有元素的最小公倍数 (LCM)。
返回数组 nums 的 最长 乘积等价子数组 的长度。

子数组 是数组中连续的、非空的元素序列。

术语 gcd(a, b) 表示 a 和 b 的 最大公因数 。

术语 lcm(a, b) 表示 a 和 b 的 最小公倍数 。



示例 1：

输入： nums = [1,2,1,2,1,1,1]

输出： 5

解释：

最长的乘积等价子数组是 [1, 2, 1, 1, 1]，其中 prod([1, 2, 1, 1, 1]) = 2， gcd([1, 2, 1, 1, 1]) = 1，以及 lcm([1, 2, 1, 1, 1]) = 2。

示例 2：

输入： nums = [2,3,4,5,6]

输出： 3

解释：

最长的乘积等价子数组是 [3, 4, 5]。

示例 3：

输入： nums = [1,2,3,1,4,5,1]

输出： 5



提示：

2 <= nums.length <= 100
1 <= nums[i] <= 10
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int maxLength(vector<int>& nums) {
        int size = (int)nums.size(), maxLen = 2;  // x * y = gcd(x, y) * lcm(x, y)，所以长度至少为2
        int maxG = 9, maxL = 5 * 7 * 8 * 9, maxP = maxG * maxL;

        for (int i = 0; i < size - 2; ++i) {
            int P = nums[i], G = P, L = P;

            for (int j = i + 1; j < size && P <= maxP; ++j) {
                P *= nums[j];
                G = gcd(G, nums[j]);
                L = lcm(L, nums[j]);

                if (P == G * L) {
                    maxLen = max(maxLen, j - i + 1);
                }
            }
        }

        return maxLen;
    }

    int gcd(int x, int y) {
        return (y == 0) ? x : gcd(y, x % y);
    }

    int lcm(int x, int y) {
        return x * y / gcd(x, y);
    }
};

int main()
{
    Solution o;
    CheckResult check;

    vector<int> nums = { 1,2,1,2,1,1,1 };
    check.checkInt(5, o.maxLength(nums));

    nums = { 2,3,4,5,6 };
    check.checkInt(3, o.maxLength(nums));

    nums = { 1,2,3,1,4,5,1 };
    check.checkInt(5, o.maxLength(nums));

    nums = { 1,3,9,5,9,5,1,5,7,5,5,8,6,3,7 };
    check.checkInt(3, o.maxLength(nums));
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
