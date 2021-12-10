/* 划分数字的方案数.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
你写下了若干 正整数 ，并将它们连接成了一个字符串 num 。但是你忘记给这些数字之间加逗号了。你只记得这一列数字是 非递减 的且 没有 任何数字有前导 0 。

请你返回有多少种可能的 正整数数组 可以得到字符串 num 。由于答案可能很大，将结果对 109 + 7 取余 后返回。

 

示例 1：

输入：num = "327"
输出：2
解释：以下为可能的方案：
3, 27
327
示例 2：

输入：num = "094"
输出：0
解释：不能有数字有前导 0 ，且所有数字均为正数。
示例 3：

输入：num = "0"
输出：0
解释：不能有数字有前导 0 ，且所有数字均为正数。
示例 4：

输入：num = "9999999999999"
输出：101
 

提示：

1 <= num.length <= 3500
num 只含有数字 '0' 到 '9' 。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/number-of-ways-to-separate-numbers
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <algorithm>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int numberOfCombinations(string num) {
        if (num[0] == '0') {
            return 0;
        }

        int i, len, size = num.size(), mod = 1000000007;
        int* lcp = new int[size * size]();  // lcp[i][j]表示从i、j开始的两个子串的longest common prefix
        int* dp = new int[size * (size + 1)]();  // dp[i][j]表示num[0,i]最后一个数字的长度为j的方法数
        int* presum = new int[size * (size + 1)]();

        getLCP(num, lcp);

        for (i = 0; i < size; ++i) {
            for (len = 1; len <= i; ++len) {  // 当前num[0,i]长度为i+1，枚举最后一个数字的长度为[1,i]
                if (num[i - len + 1] != '0') {  // 如果该长度第一个字符为0，不是一个合法的数字，dp[i][len] = 0
                    dp[i * (size + 1) + len] = (dp[i * (size + 1) + len] + presum[(i - len) * (size + 1) + len - 1]) % mod;  // 最后一个是num[i - len + 1]，前面是num[0, i - len]，这里面最后一个数字长度为[1, len - 1]肯定都是合法的
                    int start1 = i - 2 * len + 1, start2 = i - len + 1;
                    if (start1 >= 0) {
                        int maxPrefix = lcp[start1 * size + start2];
                        if (maxPrefix == len || num[start1 + maxPrefix] < num[start2 + maxPrefix]) {  // 前面num[0, i - len]最后一个数也选择长度len时，它小于等于num[i - len + 1]也是合法的
                            dp[i * (size + 1) + len] = (dp[i * (size + 1) + len] + dp[(i - len) * (size + 1) + len]) % mod;
                        }
                    }
                }

                presum[i * (size + 1) + len] = (presum[i * (size + 1) + len - 1] + dp[i * (size + 1) + len]) % mod;
            }

            dp[i * (size + 1) + len] = 1;  // len为i+1时，整个num[0,i]作为一个整体只有一种方法
            presum[i * (size + 1) + len] = (presum[i * (size + 1) + len - 1] + 1) % mod;

            for (len = i + 2; len <= size; ++len) {  // 把presum补齐
                presum[i * (size + 1) + len] = presum[i * (size + 1) + len - 1];
            }
        }

        int combinations = presum[(size - 1) * (size + 1) + size];
        delete[] lcp;
        delete[] dp;
        delete[] presum;

        return combinations;
    }

    void getLCP(string& num, int* lcp) {
        int size = num.size(), i, j = size - 1;

        for (i = size - 2; i >= 0; --i) {
            lcp[i * size + j] = num[i] == num[j] ? 1 : 0;
        }

        for (j = size - 2; j > 0; --j) {
            lcp[(j - 1) * size + j] = num[j - 1] == num[j] ? 1 : 0;

            for (i = j - 2; i >= 0; --i) {
                lcp[i * size + j] = num[i] == num[j] ? min(lcp[(i + 1) * size + j + 1] + 1, j - i) : 0;
            }
        }
    }
};

int main()
{
    CheckResult check;
    Solution o;

    check.checkInt(2, o.numberOfCombinations("327"));
    check.checkInt(0, o.numberOfCombinations("0"));
    check.checkInt(0, o.numberOfCombinations("094"));
    check.checkInt(7, o.numberOfCombinations("99999"));
    check.checkInt(101, o.numberOfCombinations("9999999999999"));
    check.checkInt(3, o.numberOfCombinations("102030"));
    check.checkInt(5, o.numberOfCombinations("1234"));
    check.checkInt(39062, o.numberOfCombinations("123004560789000987065400321000123004560789000987065400321000123004560789000987065400321000"));
    check.checkInt(755568658, o.numberOfCombinations(string(3500, '9')));
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
