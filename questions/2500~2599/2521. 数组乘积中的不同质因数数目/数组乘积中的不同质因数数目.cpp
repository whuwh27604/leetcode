/* 数组乘积中的不同质因数数目.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你一个正整数数组 nums ，对 nums 所有元素求积之后，找出并返回乘积中 不同质因数 的数目。

注意：

质数 是指大于 1 且仅能被 1 及自身整除的数字。
如果 val2 / val1 是一个整数，则整数 val1 是另一个整数 val2 的一个因数。


示例 1：

输入：nums = [2,4,3,7,10,6]
输出：4
解释：
nums 中所有元素的乘积是：2 * 4 * 3 * 7 * 10 * 6 = 10080 = 25 * 32 * 5 * 7 。
共有 4 个不同的质因数，所以返回 4 。
示例 2：

输入：nums = [2,4,8,16]
输出：1
解释：
nums 中所有元素的乘积是：2 * 4 * 8 * 16 = 1024 = 210 。
共有 1 个不同的质因数，所以返回 1 。


提示：

1 <= nums.length <= 104
2 <= nums[i] <= 1000
*/

#include <iostream>
#include <unordered_set>
#include "../check/CheckResult.h"

using namespace std;

vector<int> primes;

void init() {
    static bool inited = false;

    if (!inited) {
        inited = true;
        int n = 1001;
        vector<int> nums(n, 1);

        for (int i = 2; i * i < n; ++i) {
            if (nums[i] == 0) {
                continue;
            }

            for (int j = (i * i); j < n; j += i) {  // i的小于i的倍数都已经排除过了，现在只需要排除更大的i的倍数
                nums[j] = 0;
            }
        }

        for (int k = 2; k < n; ++k) {
            if (nums[k] == 1) {
                primes.push_back(k);
            }
        }
    }
}

class Solution {
public:
    int distinctPrimeFactors(vector<int>& nums) {
        init();
        int size = primes.size();
        unordered_set<int> factors;

        for (int num : nums) {
            for (int i = 0; i < size && primes[i] <= num; ++i) {
                if (num % primes[i] == 0) {
                    factors.insert(primes[i]);
                }
            }
        }

        return (int)factors.size();
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<int> nums = { 2,4,3,7,10,6 };
    check.checkInt(4, o.distinctPrimeFactors(nums));

    nums = { 2,4,8,16 };
    check.checkInt(1, o.distinctPrimeFactors(nums));
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
