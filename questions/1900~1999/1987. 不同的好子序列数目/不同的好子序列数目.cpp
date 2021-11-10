/* 不同的好子序列数目.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你一个二进制字符串 binary 。 binary 的一个 子序列 如果是 非空 的且没有 前导 0 （除非数字是 "0" 本身），那么它就是一个 好 的子序列。

请你找到 binary 不同好子序列 的数目。

比方说，如果 binary = "001" ，那么所有 好 子序列为 ["0", "0", "1"] ，所以 不同 的好子序列为 "0" 和 "1" 。 注意，子序列 "00" ，"01" 和 "001" 不是好的，因为它们有前导 0 。
请你返回 binary 中 不同好子序列 的数目。由于答案可能很大，请将它对 109 + 7 取余 后返回。

一个 子序列 指的是从原数组中删除若干个（可以一个也不删除）元素后，不改变剩余元素顺序得到的序列。

 

示例 1：

输入：binary = "001"
输出：2
解释：好的二进制子序列为 ["0", "0", "1"] 。
不同的好子序列为 "0" 和 "1" 。
示例 2：

输入：binary = "11"
输出：2
解释：好的二进制子序列为 ["1", "1", "11"] 。
不同的好子序列为 "1" 和 "11" 。
示例 3：

输入：binary = "101"
输出：5
解释：好的二进制子序列为 ["1", "0", "1", "10", "11", "101"] 。
不同的好子序列为 "0" ，"1" ，"10" ，"11" 和 "101" 。
 

提示：

1 <= binary.length <= 105
binary 只含有 '0' 和 '1' 。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/number-of-unique-good-subsequences
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int numberOfUniqueGoodSubsequences(string binary) {
        int zero = 0, one = 0, mod = 1000000007;
        bool zeroExist = false;

        for (char c : binary) {
            if (c == '0') {
                zero = (zero + one) % mod;
                zeroExist = true;
            }
            else {
                one = (zero + one + 1) % mod;
            }
        }

        return (zero + one + (zeroExist ? 1 : 0)) % mod;
    }
};

int main()
{
    CheckResult check;
    Solution o;

    check.checkInt(2, o.numberOfUniqueGoodSubsequences("001"));
    check.checkInt(2, o.numberOfUniqueGoodSubsequences("11"));
    check.checkInt(5, o.numberOfUniqueGoodSubsequences("101"));
    check.checkInt(1, o.numberOfUniqueGoodSubsequences("1"));
    check.checkInt(1, o.numberOfUniqueGoodSubsequences("0"));
    check.checkInt(184167483, o.numberOfUniqueGoodSubsequences("101010101001010010101010101010010101010101010010101010101010100101010101001010101001010101010100101010101"));
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
