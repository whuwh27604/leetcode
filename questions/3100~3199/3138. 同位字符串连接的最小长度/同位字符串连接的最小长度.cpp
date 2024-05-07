/* 同位字符串连接的最小长度.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你一个字符串 s ，它由某个字符串 t 和它的 同位字符串 连接而成。

请你返回字符串 t 的 最小 可能长度。

同位字符串 指的是重新排列一个单词得到的另外一个字符串，原来字符串中的每个字符在新字符串中都恰好只使用一次。



示例 1：

输入：s = "abba"

输出：2

解释：

一个可能的字符串 t 为 "ba" 。

示例 2：

输入：s = "cdef"

输出：4

解释：

一个可能的字符串 t 为 "cdef" ，注意 t 可能等于 s 。



提示：

1 <= s.length <= 105
s 只包含小写英文字母。
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int minAnagramLength(string s) {
		int size = (int)s.size();

		for (int len = 1; len < size; ++len) {
			if (size % len == 0 && check(s, len)) {
				return len;
			}
		}

		return size;
    }

	bool check(string& s, int len) {
		int size = (int)s.size();
		vector<int> count(127, 0);

		for (int i = 0; i < len; ++i) {
			++count[s[i]];
		}

		for (int i = len; i < size; i += len) {
			vector<int> tmp(127, 0);

			for (int j = i; j < i + len; ++j) {
				if (++tmp[s[j]] > count[s[j]]) {
					return false;
				}
			}
		}

		return true;
	}
};

int main()
{
	Solution o;
	CheckResult check;

	check.checkInt(4, o.minAnagramLength("aabb"));
	check.checkInt(2, o.minAnagramLength("abba"));
	check.checkInt(4, o.minAnagramLength("cdef"));
	check.checkInt(6, o.minAnagramLength("aabbbb"));
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
