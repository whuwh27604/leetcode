/* 二进制字符串重新安排顺序需要的时间.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你一个二进制字符串 s 。在一秒之中，所有 子字符串 "01" 同时 被替换成 "10" 。这个过程持续进行到没有 "01" 存在。

请你返回完成这个过程所需要的秒数。

 

示例 1：

输入：s = "0110101"
输出：4
解释：
一秒后，s 变成 "1011010" 。
再过 1 秒后，s 变成 "1101100" 。
第三秒过后，s 变成 "1110100" 。
第四秒后，s 变成 "1111000" 。
此时没有 "01" 存在，整个过程花费 4 秒。
所以我们返回 4 。
示例 2：

输入：s = "11100"
输出：0
解释：
s 中没有 "01" 存在，整个过程花费 0 秒。
所以我们返回 0 。
 

提示：

1 <= s.length <= 1000
s[i] 要么是 '0' ，要么是 '1' 。

来源：力扣（LeetCode）
链接：https://leetcode.cn/problems/time-needed-to-rearrange-a-binary-string
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <algorithm>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int secondsToRemoveOccurrences(string s) {
        int seconds = 0, zeros = 0;

        for (char c : s) {  // 记dp[i]表示s[0,i]完成的时间
            if (c == '0') {  // 如果是0，那么dp[i] = dp[i - 1]
                ++zeros;
            }
            else {  // 如果是1，那么dp[i] = dp[i - 1] + 1，并且至少需要zeros次移动
                if (zeros != 0) {  // 第一个0之前的1不需要移动
                    seconds = max(seconds + 1, zeros);
                }
            }
        }

        return seconds;
    }
};

int main()
{
    CheckResult check;
    Solution o;

    check.checkInt(4, o.secondsToRemoveOccurrences("0110101"));
    check.checkInt(0, o.secondsToRemoveOccurrences("11100"));
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
