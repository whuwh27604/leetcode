/* K个逆序对数组.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给出两个整数 n 和 k，找出所有包含从 1 到 n 的数字，且恰好拥有 k 个逆序对的不同的数组的个数。

逆序对的定义如下：对于数组的第i个和第 j个元素，如果满i < j且 a[i] > a[j]，则其为一个逆序对；否则不是。

由于答案可能很大，只需要返回 答案 mod 109 + 7 的值。

示例 1:

输入: n = 3, k = 0
输出: 1
解释:
只有数组 [1,2,3] 包含了从1到3的整数并且正好拥有 0 个逆序对。
示例 2:

输入: n = 3, k = 1
输出: 2
解释:
数组 [1,3,2] 和 [2,1,3] 都有 1 个逆序对。
说明:

 n 的范围是 [1, 1000] 并且 k 的范围是 [0, 1000]。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/k-inverse-pairs-array
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int kInversePairs(int n, int k) {
        /* 令dp[i,j]表示i个数，j个逆序对的数量，那么考虑dp[i+1][j+1]：
           把1放在最前面，不能产生逆序对，剩下i个数，所以是dp[i][j+1]
           把2放在最前面，产生一个逆序对（2，1），剩下i个数，所以是dp[i][j]
           ...
           把j+1放在最前面，产生j个逆序对，剩下i个数，所以是dp[i][1]
           把j+2放在最前面，产生j+1个逆序对，剩下i个数，所以是dp[i][0]
           所以dp[i+1][j+1]=dp[i][j+1]+dp[i][j]+...+dp[i][0] */
        if (k == 0) {
            return 1;
        }

        int mod = 1000000007;
        vector<vector<int>> dp(n + 1, vector<int>(k + 1, 0));
        vector<vector<int>> presum(n + 1, vector<int>(k + 1, 0));

        for (int i = 1; i <= n; ++i) {
            dp[i][0] = 1;
            presum[i][0] = 1;

            for (int j = 1; j <= k; ++j) {
                dp[i][j] = (j < i) ? presum[i - 1][j] : (presum[i - 1][j] + mod - presum[i - 1][j - i]) % mod;
                presum[i][j] = (presum[i][j - 1] + dp[i][j]) % mod;
            }
        }

        return dp[n][k];
    }
};

int main()
{
    CheckResult check;
    Solution o;

    check.checkInt(1, o.kInversePairs(1, 0));
    check.checkInt(0, o.kInversePairs(1, 1));
    check.checkInt(1, o.kInversePairs(2, 0));
    check.checkInt(1, o.kInversePairs(2, 1));
    check.checkInt(0, o.kInversePairs(2, 2));
    check.checkInt(1, o.kInversePairs(3, 0));
    check.checkInt(2, o.kInversePairs(3, 1));
    check.checkInt(2, o.kInversePairs(3, 2));
    check.checkInt(1, o.kInversePairs(3, 3));
    check.checkInt(0, o.kInversePairs(3, 4));
    check.checkInt(21670, o.kInversePairs(10, 10));
    check.checkInt(959322173, o.kInversePairs(100, 100));
    check.checkInt(663677020, o.kInversePairs(1000, 1000));
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
