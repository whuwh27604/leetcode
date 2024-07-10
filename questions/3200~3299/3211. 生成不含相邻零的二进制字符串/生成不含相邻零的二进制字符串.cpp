/* 生成不含相邻零的二进制字符串.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你一个正整数 n。

如果一个二进制字符串 x 的所有长度为 2 的
子字符串
中包含 至少 一个 "1"，则称 x 是一个 有效 字符串。

返回所有长度为 n 的 有效 字符串，可以以任意顺序排列。



示例 1：

输入： n = 3

输出： ["010","011","101","110","111"]

解释：

长度为 3 的有效字符串有："010"、"011"、"101"、"110" 和 "111"。

示例 2：

输入： n = 1

输出： ["0","1"]

解释：

长度为 1 的有效字符串有："0" 和 "1"。



提示：

1 <= n <= 18
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    vector<string> validStrings(int n) {
        vector<string> cur = { "0","1" };

        for (int i = 2; i <= n; ++i) {
            vector<string> next;

            for (string& s : cur) {
                string t = s + '1';
                next.push_back(t);
                if (s.back() == '1') {
                    t = s + '0';
                    next.push_back(t);
                }
            }

            cur = next;
        }

        return cur;
    }
};

int main()
{
    Solution o;
    CheckResult check;

    vector<string> actual = o.validStrings(1);
    vector<string> expected = { "0","1" };
    check.checkStringVectorRandomOrder(expected, actual);

    actual = o.validStrings(3);
    expected = { "010","011","101","110","111" };
    check.checkStringVectorRandomOrder(expected, actual);
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
