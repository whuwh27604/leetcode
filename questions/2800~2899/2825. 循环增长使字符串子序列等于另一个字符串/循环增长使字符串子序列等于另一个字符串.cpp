/* 循环增长使字符串子序列等于另一个字符串.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你一个下标从 0 开始的字符串 str1 和 str2 。

一次操作中，你选择 str1 中的若干下标。对于选中的每一个下标 i ，你将 str1[i] 循环 递增，变成下一个字符。也就是说 'a' 变成 'b' ，'b' 变成 'c' ，以此类推，'z' 变成 'a' 。

如果执行以上操作 至多一次 ，可以让 str2 成为 str1 的子序列，请你返回 true ，否则返回 false 。

注意：一个字符串的子序列指的是从原字符串中删除一些（可以一个字符也不删）字符后，剩下字符按照原本先后顺序组成的新字符串。



示例 1：

输入：str1 = "abc", str2 = "ad"
输出：true
解释：选择 str1 中的下标 2 。
将 str1[2] 循环递增，得到 'd' 。
因此，str1 变成 "abd" 且 str2 现在是一个子序列。所以返回 true 。
示例 2：

输入：str1 = "zc", str2 = "ad"
输出：true
解释：选择 str1 中的下标 0 和 1 。
将 str1[0] 循环递增得到 'a' 。
将 str1[1] 循环递增得到 'd' 。
因此，str1 变成 "ad" 且 str2 现在是一个子序列。所以返回 true 。
示例 3：

输入：str1 = "ab", str2 = "d"
输出：false
解释：这个例子中，没法在执行一次操作的前提下，将 str2 变为 str1 的子序列。
所以返回 false 。


提示：

1 <= str1.length <= 105
1 <= str2.length <= 105
str1 和 str2 只包含小写英文字母。
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    bool canMakeSubsequence(string str1, string str2) {
        int size1 = str1.size(), size2 = str2.size(), i, j = 0;

        for (i = 0; i < size1; ++i) {
            if (str1[i] == str2[j] || str1[i] + 1 == str2[j] || (str1[i] == 'z' && str2[j] == 'a')) {
                if (++j == size2) {
                    return true;
                }
            }
        }

        return false;
    }
};

int main()
{
    CheckResult check;
    Solution o;

    check.checkBool(true, o.canMakeSubsequence("abc", "ad"));
    check.checkBool(true, o.canMakeSubsequence("zc", "ad"));
    check.checkBool(false, o.canMakeSubsequence("ab", "d"));
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
