/* 每个字符最多出现两次的最长子字符串.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你一个字符串 s ，请找出满足每个字符最多出现两次的最长子字符串，并返回该
子字符串
的 最大 长度。



示例 1：

输入： s = "bcbbbcba"

输出： 4

解释：

以下子字符串长度为 4，并且每个字符最多出现两次："bcbbbcba"。

示例 2：

输入： s = "aaaa"

输出： 2

解释：

以下子字符串长度为 2，并且每个字符最多出现两次："aaaa"。



提示：

2 <= s.length <= 100
s 仅由小写英文字母组成。
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int maximumLengthSubstring(string s) {
		vector<int> count(127, 0);
		int size = s.size(), left = 0, maxLen = 0;

		for (int right = 0; right < size; ++right) {
			++count[s[right]];

			while (count[s[right]] > 2) {
				--count[s[left++]];
			}

			maxLen = max(maxLen, right - left + 1);
		}

		return maxLen;
    }
};

int main()
{
	Solution o;
	CheckResult check;

	check.checkInt(4, o.maximumLengthSubstring("bcbbbcba"));
	check.checkInt(2, o.maximumLengthSubstring("aaaa"));
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
