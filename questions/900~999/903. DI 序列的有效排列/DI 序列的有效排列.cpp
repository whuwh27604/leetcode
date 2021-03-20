/* DI 序列的有效排列.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
我们给出 S，一个源于 {'D', 'I'} 的长度为 n 的字符串 。（这些字母代表 “减少” 和 “增加”。）
有效排列 是对整数 {0, 1, ..., n} 的一个排列 P[0], P[1], ..., P[n]，使得对所有的 i：

如果 S[i] == 'D'，那么 P[i] > P[i+1]，以及；
如果 S[i] == 'I'，那么 P[i] < P[i+1]。
有多少个有效排列？因为答案可能很大，所以请返回你的答案模 10^9 + 7.

 

示例：

输入："DID"
输出：5
解释：
(0, 1, 2, 3) 的五个有效排列是：
(1, 0, 3, 2)
(2, 0, 3, 1)
(2, 1, 3, 0)
(3, 0, 2, 1)
(3, 1, 2, 0)
 

提示：

1 <= S.length <= 200
S 仅由集合 {'D', 'I'} 中的字符组成。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/valid-permutations-for-di-sequence
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int numPermsDISequence(string S) {
        int i, j, size = S.size(), sum = 0, mod = 1000000007;
        vector<vector<int>> dp(size + 1, vector<int>(size + 1));  // 令dp[i][j]表示字符串长度为i时，以j为结尾的序列个数
        dp[0][0] = 1;  // 序列0

        for (i = 1; i <= size; ++i) {
            if (S[i - 1] == 'D') {
                dp[i][i] = 0;  // 最后一个数是i，肯定不可能构成降序
                for (j = i - 1; j >= 0; --j) {
                    dp[i][j] = (dp[i][j + 1] + dp[i - 1][j]) % mod;  // 最后一个数是j，那么上一个序列中所有大于等于j结尾的序列都可以构成降序
                }
            }
            else {
                dp[i][0] = 0;  // 最后一个数是0，肯定不可能构成升序
                for (j = 1; j <= i; ++j) {
                    dp[i][j] = (dp[i][j - 1] + dp[i - 1][j - 1]) % mod;  // 最后一个数是j，那么上一个序列中所有小于j结尾的序列都可以构成升序
                }
            }
        }

        for (j = 0; j <= size; ++j) {
            sum = (sum + dp[size][j]) % mod;
        }

        return sum;
    }
};

int main()
{
    CheckResult check;
    Solution o;

    check.checkInt(1, o.numPermsDISequence("I"));
    check.checkInt(1, o.numPermsDISequence("D"));
    check.checkInt(2, o.numPermsDISequence("DI"));
    check.checkInt(5, o.numPermsDISequence("DID"));
    check.checkInt(9, o.numPermsDISequence("DIDD"));
    check.checkInt(16, o.numPermsDISequence("DIDI"));
    check.checkInt(180617435, o.numPermsDISequence("DIDIDIDIDIDIDIDIDIDIDIDIDIDIDIDIDIDIDIDIDIDIDIDIDIDIDIDIDIDIDIDIDIDIDIDIDIDIDIDIDIDIDIDIDIDIDIDIDIDIDIDIDIDIDIDIDIDIDIDIDIDIDIDIDIDIDIDIDIDIDIDIDIDIDIDIDIDIDIDIDIDIDIDIDIDIDIDIDIDIDIDIDIDIDIDIDIDIDIDI"));
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
