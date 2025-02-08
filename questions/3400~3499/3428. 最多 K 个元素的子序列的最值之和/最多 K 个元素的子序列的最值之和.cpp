/* 最多 K 个元素的子序列的最值之和.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你一个整数数组 nums 和一个正整数 k，返回所有长度最多为 k 的 子序列 中 最大值 与 最小值 之和的总和。

非空子序列 是指从另一个数组中删除一些或不删除任何元素（且不改变剩余元素的顺序）得到的数组。

由于答案可能非常大，请返回对 109 + 7 取余数的结果。



示例 1：

输入： nums = [1,2,3], k = 2

输出： 24

解释：

数组 nums 中所有长度最多为 2 的子序列如下：

子序列	最小值	最大值	和
[1]	1	1	2
[2]	2	2	4
[3]	3	3	6
[1, 2]	1	2	3
[1, 3]	1	3	4
[2, 3]	2	3	5
总和	 	 	24
因此，输出为 24。

示例 2：

输入： nums = [5,0,6], k = 1

输出： 22

解释：

对于长度恰好为 1 的子序列，最小值和最大值均为元素本身。因此，总和为 5 + 5 + 0 + 0 + 6 + 6 = 22。

示例 3：

输入： nums = [1,1,1], k = 2

输出： 12

解释：

子序列 [1, 1] 和 [1] 各出现 3 次。对于所有这些子序列，最小值和最大值均为 1。因此，总和为 12。



提示：

1 <= nums.length <= 105
0 <= nums[i] <= 109
1 <= k <= min(100, nums.length)
*/

#include <iostream>
#include <algorithm>
#include "../check/CheckResult.h"

using namespace std;

const int maxN = 100000;
const int maxM = 100;
const int mod = 1000000007;

vector<vector<int>> comb(maxN, vector<int>(maxM, 0));

void calc() {
    comb[0][0] = 1;

    for (int n = 1; n < maxN; ++n) {
        comb[n][0] = 1;

        for (int m = 1; m < maxM; ++m) {
            comb[n][m] = (comb[n - 1][m] + comb[n - 1][m - 1]) % mod;
        }
    }
}

void init() {
    static bool inited = false;

    if (!inited) {
        inited = true;
        calc();
    }
}

class Solution {
public:
    int minMaxSums(vector<int>& nums, int k) {
        init();
        sort(nums.begin(), nums.end());

        int size = (int)nums.size();
        long long sum = 0;
        vector<long long> seqs(size, 0);
        seqs[0] = 1;

        for (int len = 1; len < size; ++len) {
            seqs[len] = (seqs[len - 1] * 2 + mod - comb[len - 1][k - 1]) % mod;
        }

        for (int i = 0; i < size; ++i) {
            int len1 = i, len2 = size - i - 1;
            sum = (sum + (seqs[len1] + seqs[len2]) * nums[i]) % mod;
        }

        return (int)sum;
    }
};

int main()
{
    Solution o;
    CheckResult check;

    vector<int> nums = { 1,2,3 };
    check.checkInt(24, o.minMaxSums(nums, 2));

    nums = { 5,0,6 };
    check.checkInt(22, o.minMaxSums(nums, 1));

    nums = { 1,1,1 };
    check.checkInt(12, o.minMaxSums(nums, 2));

    nums = { 1,1,1,5,0,6,1,2,3,1,1,1,5,0,6,1,2,3,1,1,1,5,0,6,1,2,3,1,1,1,5,0,6,1,2,3,1,1,1,5,0,6,1,2,3,1,1,1,5,0,6,1,2,3,1,1,1,5,0,6,1,2,3,1,1,1,5,0,6,1,2,3,1,1,1,5,0,6,1,2,3,1,1,1,5,0,6,1,2,3,1,1,1,5,0,6,1,2,3,1,1,1,5,0,6,1,2,3,1,1,1,5,0,6,1,2,3,1,1,1,5,0,6,1,2,3,1,1,1,5,0,6,1,2,3,1,1,1,5,0,6,1,2,3,1,1,1,5,0,6,1,2,3,1,1,1,5,0,6,1,2,3 };
    check.checkInt(312918922, o.minMaxSums(nums, 10));
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
