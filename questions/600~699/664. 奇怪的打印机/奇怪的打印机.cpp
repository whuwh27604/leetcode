/* 奇怪的打印机.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
有台奇怪的打印机有以下两个特殊要求：

打印机每次只能打印由 同一个字符 组成的序列。
每次可以在任意起始和结束位置打印新字符，并且会覆盖掉原来已有的字符。
给你一个字符串 s ，你的任务是计算这个打印机打印它需要的最少打印次数。

 
示例 1：

输入：s = "aaabbb"
输出：2
解释：首先打印 "aaa" 然后打印 "bbb"。
示例 2：

输入：s = "aba"
输出：2
解释：首先打印 "aaa" 然后在第二个位置打印 "b" 覆盖掉原来的字符 'a'。
 

提示：

1 <= s.length <= 100
s 由小写英文字母组成

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/strange-printer
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <algorithm>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int strangePrinter(string s) {
        int i, j, k, len, size = s.size();
        vector<vector<int>> dp(size, vector<int>(size, INT_MAX));

        for (i = 0; i < size; ++i) {
            dp[i][i] = 1;
        }

        for (len = 2; len <= size; ++len) {
            for (i = 0; i <= size - len; ++i) {
                j = i + len - 1;

                if (s[i] == s[j]) {
                    dp[i][j] = dp[i][j - 1];
                }
                else {
                    for (k = i; k < j; ++k) {
                        dp[i][j] = min(dp[i][j], dp[i][k] + dp[k + 1][j]);
                    }
                }
            }
        }

        return dp[0][size - 1];
    }
};

int main()
{
    CheckResult check;
    Solution o;

    check.checkInt(2, o.strangePrinter("aaabbb"));
    check.checkInt(2, o.strangePrinter("aba"));
    check.checkInt(4, o.strangePrinter("ababc"));
    check.checkInt(1, o.strangePrinter("z"));
    check.checkInt(39, o.strangePrinter("rqyeroirykfhlhfkladhzvbvmzbvmzeouiryukfjhakfzbznvmznv"));
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
