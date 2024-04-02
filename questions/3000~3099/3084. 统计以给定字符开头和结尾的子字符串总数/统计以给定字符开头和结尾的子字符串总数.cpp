/* 统计以给定字符开头和结尾的子字符串总数.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你一个字符串 s 和一个字符 c 。返回在字符串 s 中并且以 c 字符开头和结尾的
非空子字符串
的总数。



示例 1：

输入：s = "abada", c = "a"

输出：6

解释：以 "a" 开头和结尾的子字符串有： "abada"、"abada"、"abada"、"abada"、"abada"、"abada"。

示例 2：

输入：s = "zzz", c = "z"

输出：6

解释：字符串 s 中总共有 6 个子字符串，并且它们都以 "z" 开头和结尾。



提示：

1 <= s.length <= 105
s 和 c 均由小写英文字母组成。
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    long long countSubstrings(string s, char c) {
		long long cnt = 0;

		for (char r : s) {
			if (r == c) {
				++cnt;
			}
		}

		return (cnt + 1) * cnt / 2;
    }
};

int main()
{
	Solution o;
	CheckResult check;

	check.checkLongLong(6, o.countSubstrings("abada", 'a'));
	check.checkLongLong(6, o.countSubstrings("zzz", 'z'));
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
