/* 分割数组使乘积互质.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你一个长度为 n 的整数数组 nums ，下标从 0 开始。

如果在下标 i 处 分割 数组，其中 0 <= i <= n - 2 ，使前 i + 1 个元素的乘积和剩余元素的乘积互质，则认为该分割 有效 。

例如，如果 nums = [2, 3, 3] ，那么在下标 i = 0 处的分割有效，因为 2 和 9 互质，而在下标 i = 1 处的分割无效，因为 6 和 3 不互质。在下标 i = 2 处的分割也无效，因为 i == n - 1 。
返回可以有效分割数组的最小下标 i ，如果不存在有效分割，则返回 -1 。

当且仅当 gcd(val1, val2) == 1 成立时，val1 和 val2 这两个值才是互质的，其中 gcd(val1, val2) 表示 val1 和 val2 的最大公约数。



示例 1：



输入：nums = [4,7,8,15,3,5]
输出：2
解释：上表展示了每个下标 i 处的前 i + 1 个元素的乘积、剩余元素的乘积和它们的最大公约数的值。
唯一一个有效分割位于下标 2 。
示例 2：



输入：nums = [4,7,15,8,3,5]
输出：-1
解释：上表展示了每个下标 i 处的前 i + 1 个元素的乘积、剩余元素的乘积和它们的最大公约数的值。
不存在有效分割。


提示：

n == nums.length
1 <= n <= 104
1 <= nums[i] <= 106
*/

#include <iostream>
#include <algorithm>
#include "../check/CheckResult.h"

using namespace std;

const int maxN = 1000000;
vector<int> primes;
vector<bool> isPrimes(maxN + 1, true);
vector<int> minFactors(maxN + 1);

void eulerFilter() {
    isPrimes[0] = isPrimes[1] = false;

    for (int num = 2; num <= maxN; ++num) {
        if (isPrimes[num]) {
            primes.push_back(num);
            minFactors[num] = num;
        }

        for (int prime : primes) {
            int composite = num * prime;
            if (composite > maxN) {
                break;
            }

            isPrimes[composite] = false;
            minFactors[composite] = prime;

            if (num % prime == 0) {
                break;
            }
        }
    }
}

void init() {
    static bool inited = false;

    if (!inited) {
        inited = true;
        eulerFilter();
    }
}

class Solution {
public:
    int findValidSplit(vector<int>& nums) {
        init();

        vector<int> factorMaxIndices(primes.back() + 1, -1);
        int size = nums.size(), maxIndex = 0;

        for (int i = 0; i < size; ++i) {
            int num = nums[i];
            while (num != 1) {
                int factor = minFactors[num];
                factorMaxIndices[factor] = i;
                num /= factor;
            }
        }

        for (int i = 0; i < size - 1; ++i) {
            int num = nums[i];
            while (num != 1) {
                int factor = minFactors[num];
                maxIndex = max(maxIndex, factorMaxIndices[factor]);
                num /= factor;
            }

            if (maxIndex == i) {
                return i;
            }
        }

        return -1;
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<int> nums = { 4,7,8,15,3,5 };
    check.checkInt(2, o.findValidSplit(nums));

    nums = { 4,7,15,8,3,5 };
    check.checkInt(-1, o.findValidSplit(nums));

    nums = { 1,1 };
    check.checkInt(0, o.findValidSplit(nums));

    nums = { 1 };
    check.checkInt(-1, o.findValidSplit(nums));
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
