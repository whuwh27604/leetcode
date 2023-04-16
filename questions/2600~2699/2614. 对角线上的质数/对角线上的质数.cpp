/* 对角线上的质数.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你一个下标从 0 开始的二维整数数组 nums 。

返回位于 nums 至少一条 对角线 上的最大 质数 。如果任一对角线上均不存在质数，返回 0 。

注意：

如果某个整数大于 1 ，且不存在除 1 和自身之外的正整数因子，则认为该整数是一个质数。
如果存在整数 i ，使得 nums[i][i] = val 或者 nums[i][nums.length - i - 1]= val ，则认为整数 val 位于 nums 的一条对角线上。


在上图中，一条对角线是 [1,5,9] ，而另一条对角线是 [3,5,7] 。



示例 1：

输入：nums = [[1,2,3],[5,6,7],[9,10,11]]
输出：11
解释：数字 1、3、6、9 和 11 是所有 "位于至少一条对角线上" 的数字。由于 11 是最大的质数，故返回 11 。
示例 2：

输入：nums = [[1,2,3],[5,17,7],[9,11,10]]
输出：17
解释：数字 1、3、9、10 和 17 是所有满足"位于至少一条对角线上"的数字。由于 17 是最大的质数，故返回 17 。


提示：

1 <= nums.length <= 300
nums.length == numsi.length
1 <= nums[i][j] <= 4*106
*/

#include <iostream>
#include <unordered_set>
#include <algorithm>
#include "../check/CheckResult.h"

using namespace std;

int maxNum = 4000000;
vector<int> primes;
unordered_set<int> primesSet;

void init() {
    static bool inited = false;

    if (!inited) {
        inited = true;
        vector<bool> isPrime(maxNum + 1, true);

        for (int i = 2; i <= maxNum; ++i) {
            if (isPrime[i]) {
                primes.push_back(i);
            }

            for (int j = 0; j < (int)primes.size() && i * primes[j] <= maxNum; ++j) {
                isPrime[i * primes[j]] = false;

                if (i % primes[j] == 0) {
                    break;
                }
            }
        }

        for (int prime : primes) {
            primesSet.insert(prime);
        }
    }
}

class Solution {
public:
    int diagonalPrime(vector<vector<int>>& nums) {
        int maxPrime = 0, size = nums.size();

        init();

        for (int i = 0; i < size; ++i) {
            int num = nums[i][i];
            if (primesSet.count(num) != 0) {
                maxPrime = max(maxPrime, num);
            }

            num = nums[i][size - i - 1];
            if (primesSet.count(num) != 0) {
                maxPrime = max(maxPrime, num);
            }
        }

        return maxPrime;
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<vector<int>> nums = { {1,2,3},{5,6,7},{9,10,11} };
    check.checkInt(11, o.diagonalPrime(nums));

    nums = { {1,2,3},{5,17,7},{9,11,10} };
    check.checkInt(17, o.diagonalPrime(nums));
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
