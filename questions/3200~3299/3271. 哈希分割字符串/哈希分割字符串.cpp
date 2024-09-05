/* 哈希分割字符串.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你一个长度为 n 的字符串 s 和一个整数 k ，n 是 k 的 倍数 。你的任务是将字符串 s 哈希为一个长度为 n / k 的新字符串 result 。

首先，将 s 分割成 n / k 个
子字符串
 ，每个子字符串的长度都为 k 。然后，将 result 初始化为一个 空 字符串。

我们依次从前往后处理每一个 子字符串 ：

一个字符的 哈希值 是它在 字母表 中的下标（也就是 'a' → 0 ，'b' → 1 ，... ，'z' → 25）。
将子字符串中字幕的 哈希值 求和。
将和对 26 取余，将结果记为 hashedChar 。
找到小写字母表中 hashedChar 对应的字符。
将该字符添加到 result 的末尾。
返回 result 。



示例 1：

输入：s = "abcd", k = 2

输出："bf"

解释：

第一个字符串为 "ab" ，0 + 1 = 1 ，1 % 26 = 1 ，result[0] = 'b' 。

第二个字符串为： "cd" ，2 + 3 = 5 ，5 % 26 = 5 ，result[1] = 'f' 。

示例 2：

输入：s = "mxz", k = 3

输出："i"

解释：

唯一的子字符串为 "mxz" ，12 + 23 + 25 = 60 ，60 % 26 = 8 ，result[0] = 'i' 。



提示：

1 <= k <= 100
k <= s.length <= 1000
s.length 能被 k 整除。
s 只含有小写英文字母。
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    string stringHash(string s, int k) {
        int n = (int)s.size(), hashedChar = 0;
        string key;

        for (int i = 0; i < n; ++i) {
            hashedChar += (s[i] - 'a');
            if ((i + 1) % k == 0) {
                key += (hashedChar % 26 + 'a');
                hashedChar = 0;
            }
        }

        return key;
    }
};

int main()
{
    Solution o;
    CheckResult check;

    check.checkString("bf", o.stringHash("abcd", 2));
    check.checkString("i", o.stringHash("mxz", 3));
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
