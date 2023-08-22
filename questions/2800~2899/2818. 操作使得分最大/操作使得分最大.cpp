/* 操作使得分最大.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你一个长度为 n 的正整数数组 nums 和一个整数 k 。

一开始，你的分数为 1 。你可以进行以下操作至多 k 次，目标是使你的分数最大：

选择一个之前没有选过的 非空 子数组 nums[l, ..., r] 。
从 nums[l, ..., r] 里面选择一个 质数分数 最高的元素 x 。如果多个元素质数分数相同且最高，选择下标最小的一个。
将你的分数乘以 x 。
nums[l, ..., r] 表示 nums 中起始下标为 l ，结束下标为 r 的子数组，两个端点都包含。

一个整数的 质数分数 等于 x 不同质因子的数目。比方说， 300 的质数分数为 3 ，因为 300 = 2 * 2 * 3 * 5 * 5 。

请你返回进行至多 k 次操作后，可以得到的 最大分数 。

由于答案可能很大，请你将结果对 109 + 7 取余后返回。



示例 1：

输入：nums = [8,3,9,3,8], k = 2
输出：81
解释：进行以下操作可以得到分数 81 ：
- 选择子数组 nums[2, ..., 2] 。nums[2] 是子数组中唯一的元素。所以我们将分数乘以 nums[2] ，分数变为 1 * 9 = 9 。
- 选择子数组 nums[2, ..., 3] 。nums[2] 和 nums[3] 质数分数都为 1 ，但是 nums[2] 下标更小。所以我们将分数乘以 nums[2] ，分数变为 9 * 9 = 81 。
81 是可以得到的最高得分。
示例 2：

输入：nums = [19,12,14,6,10,18], k = 3
输出：4788
解释：进行以下操作可以得到分数 4788 ：
- 选择子数组 nums[0, ..., 0] 。nums[0] 是子数组中唯一的元素。所以我们将分数乘以 nums[0] ，分数变为 1 * 19 = 19 。
- 选择子数组 nums[5, ..., 5] 。nums[5] 是子数组中唯一的元素。所以我们将分数乘以 nums[5] ，分数变为 19 * 18 = 342 。
- 选择子数组 nums[2, ..., 3] 。nums[2] 和 nums[3] 质数分数都为 2，但是 nums[2] 下标更小。所以我们将分数乘以 nums[2] ，分数变为  342 * 14 = 4788 。
4788 是可以得到的最高的分。


提示：

1 <= nums.length == n <= 105
1 <= nums[i] <= 105
1 <= k <= min(n * (n + 1) / 2, 109)
*/

#include <iostream>
#include <unordered_set>
#include <stack>
#include <algorithm>
#include "../check/CheckResult.h"

using namespace std;

int maxNum = 100000, mod = 1000000007;
vector<int> factorCount(maxNum + 1, 0);

void EratosthenesSieve() {
    for (int i = 2; i <= maxNum; ++i) {
        if (factorCount[i] == 0) {  // i是质数
            for (int j = i; j <= maxNum; j += i) {
                ++factorCount[j];
            }
        }
    }
}

void init() {
    static bool inited = false;

    if (!inited) {
        inited = true;
        EratosthenesSieve();
    }
}

class Solution {
public:
    int maximumScore(vector<int>& nums, int k) {
        int n = nums.size();
        long long score = 1;
        vector<int> primeScores(n);
        vector<long long> subarrayCount(n);
        vector<pair<int, int>> numIndices(n);

        init();
        getPrimeScore(n, nums, primeScores, numIndices);
        sort(numIndices.begin(), numIndices.end());
        countSubarray(n, primeScores, subarrayCount);

        for (int i = n - 1; i >= 0 && k != 0; --i) {
            int x = numIndices[i].first, index = numIndices[i].second;
            long long count = subarrayCount[index];

            if (count >= k) {
                score = score * fastPower(x, k) % mod;
                k = 0;
            }
            else {
                score = score * fastPower(x, count) % mod;
                k -= (int)count;
            }
        }

        return (int)score;
    }

    void getPrimeScore(int n, vector<int>& nums, vector<int>& primeScores, vector<pair<int, int>>& numIndices) {
        for (int i = 0; i < n; ++i) {
            primeScores[i] = factorCount[nums[i]];
            numIndices[i] = { nums[i],i };
        }
    }

    void countSubarray(int n, vector<int>& primeScores, vector<long long>& subarrayCount) {
        vector<int> leftNoless(n, -1), rightGreater(n, n);

        getLeftNoless(n, primeScores, leftNoless);
        getRightGreater(n, primeScores, rightGreater);

        for (int i = 0; i < n; ++i) {
            subarrayCount[i] = ((long long)i - leftNoless[i]) * ((long long)rightGreater[i] - i);
        }
    }

    void getLeftNoless(int n, vector<int>& primeScores, vector<int>& leftNoless) {
        stack<int> decreasing;

        for (int i = 0; i < n; ++i) {
            while (!decreasing.empty() && primeScores[decreasing.top()] < primeScores[i]) {
                decreasing.pop();
            }

            if (!decreasing.empty()) {
                leftNoless[i] = decreasing.top();
            }

            decreasing.push(i);
        }
    }

    void getRightGreater(int n, vector<int>& primeScores, vector<int>& rightGreater) {
        stack<int> decreasing;

        for (int i = n - 1; i >= 0; --i) {
            while (!decreasing.empty() && primeScores[decreasing.top()] <= primeScores[i]) {
                decreasing.pop();
            }

            if (!decreasing.empty()) {
                rightGreater[i] = decreasing.top();
            }

            decreasing.push(i);
        }
    }

    long long fastPower(long long x, long long n) {
        long long ans = 1;

        while (n != 0) {
            if ((n & 1) == 1) {
                ans = ans * x % mod;
            }

            x = x * x % mod;
            n >>= 1;
        }

        return ans;
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<int> nums = { 8,3,9,3,8 };
    check.checkInt(81, o.maximumScore(nums, 2));

    nums = { 19,12,14,6,10,18 };
    check.checkInt(4788, o.maximumScore(nums, 3));

    nums = { 1,75866,1,92619,1334,29568,62581,53130,94710,72816,87780,67830,20930,49559,50505,63669,33660,42252,457,17339,13668,73583,94603,82062,1,21090,8101,90146,86195,43839,7460,30690,21661,1,1,12680,68710,96288,57558,10920,94613,1,59960,1,63389,19264,51409 };
    check.checkInt(531428126, o.maximumScore(nums, 106));

    nums = { 75866,92619,1334,29568,62581,53130,94710,72816,87780,67830,20930,49559,50505,63669,33660,42252,457,17339,13668,73583,94603,82062,21090,8101,90146,86195,43839,7460,30690,21661,12680,68710,96288,57558,10920,94613,59960,63389,19264,51409 };
    check.checkInt(764584928, o.maximumScore(nums, 106));
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
