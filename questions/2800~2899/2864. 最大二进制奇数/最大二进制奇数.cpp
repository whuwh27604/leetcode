/* 最大二进制奇数.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你一个 二进制 字符串 s ，其中至少包含一个 '1' 。

你必须按某种方式 重新排列 字符串中的位，使得到的二进制数字是可以由该组合生成的 最大二进制奇数 。

以字符串形式，表示并返回可以由给定组合生成的最大二进制奇数。

注意 返回的结果字符串 可以 含前导零。



示例 1：

输入：s = "010"
输出："001"
解释：因为字符串 s 中仅有一个 '1' ，其必须出现在最后一位上。所以答案是 "001" 。
示例 2：

输入：s = "0101"
输出："1001"
解释：其中一个 '1' 必须出现在最后一位上。而由剩下的数字可以生产的最大数字是 "100" 。所以答案是 "1001" 。


提示：

1 <= s.length <= 100
s 仅由 '0' 和 '1' 组成
s 中至少包含一个 '1'
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    string maximumOddBinaryNumber(string s) {
        int size = s.size(), j = 0;

        for (int i = 0; i < size; ++i) {
            if (s[i] == '1') {
                if (i != j) {
                    s[j] = '1';
                    s[i] = '0';
                }

                ++j;
            }
        }

        s[j - 1] = '0';
        s[size - 1] = '1';

        return s;
    }
};

int main()
{
    CheckResult check;
    Solution o;

    check.checkString("001", o.maximumOddBinaryNumber("010"));
    check.checkString("1001", o.maximumOddBinaryNumber("0101"));
    check.checkString("1101", o.maximumOddBinaryNumber("0111"));
    check.checkString("1101", o.maximumOddBinaryNumber("1110"));
    check.checkString("1", o.maximumOddBinaryNumber("1"));
    check.checkString("111", o.maximumOddBinaryNumber("111"));
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
