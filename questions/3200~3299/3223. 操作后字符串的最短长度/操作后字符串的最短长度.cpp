/* 操作后字符串的最短长度.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你一个字符串 s 。

你需要对 s 执行以下操作 任意 次：

选择一个下标 i ，满足 s[i] 左边和右边都 至少 有一个字符与它相同。
删除 s[i] 左边 离它 最近 且相同的字符。
删除 s[i] 右边 离它 最近 且相同的字符。
请你返回执行完所有操作后， s 的 最短 长度。



示例 1：

输入：s = "abaacbcbb"

输出：5

解释：
我们执行以下操作：

选择下标 2 ，然后删除下标 0 和 3 处的字符，得到 s = "bacbcbb" 。
选择下标 3 ，然后删除下标 0 和 5 处的字符，得到 s = "acbcb" 。
示例 2：

输入：s = "aa"

输出：2

解释：
无法对字符串进行任何操作，所以返回初始字符串的长度。



提示：

1 <= s.length <= 2 * 105
s 只包含小写英文字母。
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int minimumLength(string s) {
        vector<int> count(127, 0);
        int len = 0;

        for (char c : s) {
            ++count[c];
        }

        for (char c = 'a'; c <= 'z'; ++c) {
            if (count[c] != 0) {
                len += ((count[c] & 1) == 0 ? 2 : 1);
            }
        }

        return len;
    }
};

int main()
{
    Solution o;
    CheckResult check;

    check.checkInt(5, o.minimumLength("abaacbcbb"));
    check.checkInt(2, o.minimumLength("aa"));
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
