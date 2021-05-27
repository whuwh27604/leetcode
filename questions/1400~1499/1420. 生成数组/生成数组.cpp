/* 生成数组.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你三个整数 n、m 和 k 。下图描述的算法用于找出正整数数组中最大的元素。



请你生成一个具有下述属性的数组 arr ：

arr 中有 n 个整数。
1 <= arr[i] <= m 其中 (0 <= i < n) 。
将上面提到的算法应用于 arr ，search_cost 的值等于 k 。
返回上述条件下生成数组 arr 的 方法数 ，由于答案可能会很大，所以 必须 对 10^9 + 7 取余。

 

示例 1：

输入：n = 2, m = 3, k = 1
输出：6
解释：可能的数组分别为 [1, 1], [2, 1], [2, 2], [3, 1], [3, 2] [3, 3]
示例 2：

输入：n = 5, m = 2, k = 3
输出：0
解释：没有数组可以满足上述条件
示例 3：

输入：n = 9, m = 1, k = 1
输出：1
解释：可能的数组只有 [1, 1, 1, 1, 1, 1, 1, 1, 1]
示例 4：

输入：n = 50, m = 100, k = 25
输出：34549172
解释：不要忘了对 1000000007 取余
示例 5：

输入：n = 37, m = 17, k = 7
输出：418930126
 

提示：

1 <= n <= 50
1 <= m <= 100
0 <= k <= n

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/build-array-where-you-can-find-the-maximum-exactly-k-comparisons
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int numOfArrays(int n, int m, int k) {
        if (k == 0 || k > m) {
            return 0;
        }

        int len, cost, maxValue, mod = 1000000007;
        int size = (n + 1) * (k + 1) * (m + 1);
        long long* dp = new long long[size];  // dp[len][cost][maxValue]
        memset(dp, 0, sizeof(long long) * size);

        for (maxValue = 1; maxValue <= m; ++maxValue) {
            dp[(k + 1) * (m + 1) + (m + 1) + maxValue] = 1;
        }

        for (len = 2; len <= n; ++len) {
            for (cost = 1; cost <= len && cost <= k; ++cost) {
                long long presum = 0;

                for (maxValue = 1; maxValue <= m; ++maxValue) {
                    /* 考虑最后一个数，如果它不是最大，那么它可以是[1,maxValue]中的任何一个，贡献个数dp[len-1][cost][maxValue] * maxValue；
                       如果它最大，只能是maxValue，那么个数为sum(dp[len-1][cost-1][1,maxValue-1] */
                    dp[len * (k + 1) * (m + 1) + cost * (m + 1) + maxValue] = (dp[(len - 1) * (k + 1) * (m + 1) + cost * (m + 1) + maxValue] * maxValue + presum) % mod;
                    presum = (presum + dp[(len - 1) * (k + 1) * (m + 1) + (cost - 1) * (m + 1) + maxValue]) % mod;
                }
            }
        }

        long long arrays = 0;
        for (maxValue = 1; maxValue <= m; ++maxValue) {
            arrays += dp[n * (k + 1) * (m + 1) + k * (m + 1) + maxValue];
        }

        return (int)(arrays % mod);
    }
};

int main()
{
    CheckResult check;
    Solution o;

    check.checkInt(0, o.numOfArrays(2, 3, 0));
    check.checkInt(0, o.numOfArrays(5, 2, 3));
    check.checkInt(6, o.numOfArrays(2, 3, 1));
    check.checkInt(1, o.numOfArrays(9, 1, 1));
    check.checkInt(34549172, o.numOfArrays(50, 100, 25));
    check.checkInt(418930126, o.numOfArrays(37, 17, 7));
    check.checkInt(3710, o.numOfArrays(5, 7, 3));
    check.checkInt(60, o.numOfArrays(3, 5, 2));
    check.checkInt(30, o.numOfArrays(3, 4, 2));
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
