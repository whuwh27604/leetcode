/* 好子集的数目.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你一个整数数组 nums 。如果 nums 的一个子集中，所有元素的乘积可以用若干个 互不相同的质数 相乘得到，那么我们称它为 好子集 。

比方说，如果 nums = [1, 2, 3, 4] ：
[2, 3] ，[1, 2, 3] 和 [1, 3] 是 好 子集，乘积分别为 6 = 2*3 ，6 = 2*3 和 3 = 3 。
[1, 4] 和 [4] 不是 好 子集，因为乘积分别为 4 = 2*2 和 4 = 2*2 。
请你返回 nums 中不同的 好 子集的数目对 109 + 7 取余 的结果。

nums 中的 子集 是通过删除 nums 中一些（可能一个都不删除，也可能全部都删除）元素后剩余元素组成的数组。如果两个子集删除的下标不同，那么它们被视为不同的子集。

 

示例 1：

输入：nums = [1,2,3,4]
输出：6
解释：好子集为：
- [1,2]：乘积为 2 ，可以表示为质数 2 的乘积。
- [1,2,3]：乘积为 6 ，可以表示为互不相同的质数 2 和 3 的乘积。
- [1,3]：乘积为 3 ，可以表示为质数 3 的乘积。
- [2]：乘积为 2 ，可以表示为质数 2 的乘积。
- [2,3]：乘积为 6 ，可以表示为互不相同的质数 2 和 3 的乘积。
- [3]：乘积为 3 ，可以表示为质数 3 的乘积。
示例 2：

输入：nums = [4,2,3,15]
输出：5
解释：好子集为：
- [2]：乘积为 2 ，可以表示为质数 2 的乘积。
- [2,3]：乘积为 6 ，可以表示为互不相同质数 2 和 3 的乘积。
- [2,15]：乘积为 30 ，可以表示为互不相同质数 2，3 和 5 的乘积。
- [3]：乘积为 3 ，可以表示为质数 3 的乘积。
- [15]：乘积为 15 ，可以表示为互不相同质数 3 和 5 的乘积。
 

提示：

1 <= nums.length <= 105
1 <= nums[i] <= 30

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/the-number-of-good-subsets
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int numberOfGoodSubsets(vector<int>& nums) {
        vector<int> composites = { 6,10,14,15,21,22,26,30 };
        vector<vector<int>> factors(31);
        factors[6] = { 2,3 }, factors[10] = { 2,5 }, factors[14] = { 2,7 }, factors[15] = { 3,5 }, factors[21] = { 3,7 }, factors[22] = { 2,11 }, factors[26] = { 2,13 }, factors[30] = { 2,3,5 };
        vector<pair<int, int>> compositePairs = { {15,14},{15,22},{15,26},{21,10},{21,22},{21,26} };  // 两个composites的情况，不可能出现3个composites同时选择
        vector<int> invalid = { 4,8,9,12,16,18,20,24,25,27,28 };
        vector<long long> count(31, 0);

        for (int num : nums) {  // 统计个数
            ++count[num];
        }

        for (int num : invalid) {  // 非法数直接删除
            count[num] = 0;
        }

        vector<long long> backup = count;
        for (int num : composites) {  // 只保留primes个数
            count[num] = 0;
        }

        long long subsets1 = power(count[1]);
        long long goodSubsets = countPrimes(count, subsets1);
        goodSubsets = (goodSubsets + count1Composite(composites, factors, count, backup, subsets1)) % mod;
        goodSubsets = (goodSubsets + count2Composites(compositePairs, factors, count, backup, subsets1)) % mod;

        return (int)goodSubsets;
    }

    long long power(long long n) {
        long long ans = 1;

        for (int i = 0; i < n; ++i) {
            ans = (ans << 1) % mod;
        }

        return ans;
    }

    long long countSubsets(vector<long long>& count) {
        long long subsets = 1;

        for (int i = 2; i < 31; ++i) {
            if (count[i] > 0) {
                subsets = (subsets * (count[i] + 1)) % mod;
            }
        }

        return subsets;
    }

    long long countPrimes(vector<long long>& count, long long subsets1) {
        return (countSubsets(count) + mod - 1) * subsets1 % mod;  // 所有primes的子集数量，去掉空集
    }

    long long count1Composite(vector<int>& composites, vector<vector<int>>& factors, vector<long long>& count, vector<long long>& backup, long long subsets1) {
        long long goodSubsets = 0;

        for (int num : composites) {
            vector<long long> tmp = count;

            for (int factor : factors[num]) {
                tmp[factor] = 0;  // 选中一个composite后，它的factor就不能再选
            }

            goodSubsets = (goodSubsets + countSubsets(tmp) * backup[num] % mod * subsets1 % mod) % mod;  // 1 composite+primes，primes可以为空集
        }

        return goodSubsets;
    }

    long long count2Composites(vector<pair<int, int>>& compositePairs, vector<vector<int>>& factors, vector<long long>& count, vector<long long>& backup, long long subsets1) {
        long long goodSubsets = 0;

        for (auto& compositePair : compositePairs) {
            vector<long long> tmp = count;

            for (int factor : factors[compositePair.first]) {
                tmp[factor] = 0;
            }

            for (int factor : factors[compositePair.second]) {
                tmp[factor] = 0;
            }

            goodSubsets = (goodSubsets + countSubsets(tmp) * backup[compositePair.first] % mod * backup[compositePair.second] % mod * subsets1 % mod) % mod;  // 2 composites+primes，primes可以为空集
        }

        return goodSubsets;
    }

    int mod = 1000000007;
};

int main()
{
    CheckResult check;
    Solution o;

    vector<int> nums = { 1,2,3,4 };
    check.checkInt(6, o.numberOfGoodSubsets(nums));

    nums = { 1,1,2,6 };
    check.checkInt(8, o.numberOfGoodSubsets(nums));

    nums = { 2,3,14,15 };
    check.checkInt(8, o.numberOfGoodSubsets(nums));

    nums = { 4,2,3,15 };
    check.checkInt(5, o.numberOfGoodSubsets(nums));

    nums = { 1 };
    check.checkInt(0, o.numberOfGoodSubsets(nums));

    nums = { 1,1,1,1,1,2,2,3,3,3,4,4,4,4,5,5,5,5,5,6,6,6,6,6,6,7,7,7,7,7,7,7,8,8,8,8,8,8,8,8,9,9,9,9,9,9,9,9,9,10,11,12,12,13,13,13,14,14,14,14,
    15,15,15,15,15,16,16,16,16,16,16,17,17,17,17,17,17,17,18,18,18,18,18,18,18,18,19,19,19,19,19,19,19,19,19,20,
    21,22,22,23,23,23,24,24,24,24,25,25,25,25,25,26,26,26,26,26,26,27,27,27,27,27,27,27,28,28,28,28,28,28,28,28,29,29,29,29,29,29,29,29,29,30 };
    check.checkInt(436876761, o.numberOfGoodSubsets(nums));
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
