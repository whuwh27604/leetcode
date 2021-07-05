/* 恢复数组.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
某个程序本来应该输出一个整数数组。但是这个程序忘记输出空格了以致输出了一个数字字符串，我们所知道的信息只有：数组中所有整数都在 [1, k] 之间，且数组中的数字都没有前导 0 。

给你字符串 s 和整数 k 。可能会有多种不同的数组恢复结果。

按照上述程序，请你返回所有可能输出字符串 s 的数组方案数。

由于数组方案数可能会很大，请你返回它对 10^9 + 7 取余 后的结果。

 

示例 1：

输入：s = "1000", k = 10000
输出：1
解释：唯一一种可能的数组方案是 [1000]
示例 2：

输入：s = "1000", k = 10
输出：0
解释：不存在任何数组方案满足所有整数都 >= 1 且 <= 10 同时输出结果为 s 。
示例 3：

输入：s = "1317", k = 2000
输出：8
解释：可行的数组方案为 [1317]，[131,7]，[13,17]，[1,317]，[13,1,7]，[1,31,7]，[1,3,17]，[1,3,1,7]
示例 4：

输入：s = "2020", k = 30
输出：1
解释：唯一可能的数组方案是 [20,20] 。 [2020] 不是可行的数组方案，原因是 2020 > 30 。 [2,020] 也不是可行的数组方案，因为 020 含有前导 0 。
示例 5：

输入：s = "1234567890", k = 90
输出：34
 

提示：

1 <= s.length <= 10^5.
s 只包含数字且不包含前导 0 。
1 <= k <= 10^9.

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/restore-the-array
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int numberOfArrays(string s, int k) {
        int i, j, size = s.size();
        vector<int> dp(size + 1, 0);
        dp[size] = 1;

        for (i = size - 1; i >= 0; --i) {
            if (s[i] == '0') {
                continue;
            }

            long long num = 0;

            for (j = i; j < size; ++j) {
                num = num * 10 + s[j] - '0';
                if (num > k) {
                    break;
                }

                dp[i] = (dp[i] + dp[j + 1]) % 1000000007;
            }
        }

        return dp[0];
    }
};

int main()
{
    CheckResult check;
    Solution o;

    check.checkInt(1, o.numberOfArrays("1000", 10000));
    check.checkInt(0, o.numberOfArrays("1000", 10));
    check.checkInt(8, o.numberOfArrays("1317", 2000));
    check.checkInt(1, o.numberOfArrays("2020", 30));
    check.checkInt(34, o.numberOfArrays("1234567890", 90));
    check.checkInt(1, o.numberOfArrays("1", 1));
    check.checkInt(0, o.numberOfArrays("0", 1));
    check.checkInt(615577024, o.numberOfArrays("12345678901234567890123456789012345678901234567890123456789012345678901234567890", 1000000000));
    check.checkInt(154273513, o.numberOfArrays("123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890", 1000000000));
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
