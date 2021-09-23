/* 两个回文子序列长度的最大乘积.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你一个字符串 s ，请你找到 s 中两个 不相交回文子序列 ，使得它们长度的 乘积最大 。两个子序列在原字符串中如果没有任何相同下标的字符，则它们是 不相交 的。

请你返回两个回文子序列长度可以达到的 最大乘积 。

子序列 指的是从原字符串中删除若干个字符（可以一个也不删除）后，剩余字符不改变顺序而得到的结果。如果一个字符串从前往后读和从后往前读一模一样，那么这个字符串是一个 回文字符串 。

 

示例 1：



输入：s = "leetcodecom"
输出：9
解释：最优方案是选择 "ete" 作为第一个子序列，"cdc" 作为第二个子序列。
它们的乘积为 3 * 3 = 9 。
示例 2：

输入：s = "bb"
输出：1
解释：最优方案为选择 "b" （第一个字符）作为第一个子序列，"b" （第二个字符）作为第二个子序列。
它们的乘积为 1 * 1 = 1 。
示例 3：

输入：s = "accbcaxxcxx"
输出：25
解释：最优方案为选择 "accca" 作为第一个子序列，"xxcxx" 作为第二个子序列。
它们的乘积为 5 * 5 = 25 。
 

提示：

2 <= s.length <= 12
s 只含有小写英文字母。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/maximum-product-of-the-length-of-two-palindromic-subsequences
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <algorithm>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int maxProduct(string s) {
        int num1, size = s.size(), maxNum = (1 << size) - 1, product = 0;

        for (num1 = 1; num1 < maxNum; ++num1) {  // 枚举所有可能的第一个子序列
            if (!isPalindromic(s, num1)) {
                continue;
            }

            int len = hammingWeight(num1), num2 = maxNum ^ num1;

            for (int i = num2; i != 0; i = ((i - 1) & num2)) {  // 枚举所有可能的第二个子序列
                if (isPalindromic(s, i)) {
                    product = max(product, len * hammingWeight(i));
                }
            }
        }

        return product;
    }

    bool isPalindromic(string& s, int num) {
        for (int i = 0, j = s.size() - 1, bit1 = 1, bit2 = (1 << j); i < j; ++i, bit1 <<= 1, --j, bit2 >>= 1) {
            while ((bit1 & num) == 0) {
                ++i, bit1 <<= 1;
            }

            while ((bit2 & num) == 0) {
                --j, bit2 >>= 1;
            }

            if (s[i] != s[j]) {
                return false;
            }
        }

        return true;
    }

    int hammingWeight(int num) {
        int count = 0;

        while (num != 0) {
            ++count;
            num &= (num - 1);  // n&(n-1)只把n中最后一个1变为0
        }

        return count;
    }
};

int main()
{
    CheckResult check;
    Solution o;

    check.checkInt(9, o.maxProduct("leetcodecom"));
    check.checkInt(1, o.maxProduct("bb"));
    check.checkInt(25, o.maxProduct("accbcaxxcxx"));
    check.checkInt(36, o.maxProduct("aaaaaaaaaaaa"));
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
