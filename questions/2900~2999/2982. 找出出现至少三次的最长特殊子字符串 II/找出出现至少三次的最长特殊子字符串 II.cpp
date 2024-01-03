/* 找出出现至少三次的最长特殊子字符串 II.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
* 给你一个仅由小写英文字母组成的字符串 s 。

如果一个字符串仅由单一字符组成，那么它被称为 特殊 字符串。例如，字符串 "abc" 不是特殊字符串，而字符串 "ddd"、"zz" 和 "f" 是特殊字符串。

返回在 s 中出现 至少三次 的 最长特殊子字符串 的长度，如果不存在出现至少三次的特殊子字符串，则返回 -1 。

子字符串 是字符串中的一个连续 非空 字符序列。

 

示例 1：

输入：s = "aaaa"
输出：2
解释：出现三次的最长特殊子字符串是 "aa" ：子字符串 "aaaa"、"aaaa" 和 "aaaa"。
可以证明最大长度是 2 。
示例 2：

输入：s = "abcdef"
输出：-1
解释：不存在出现至少三次的特殊子字符串。因此返回 -1 。
示例 3：

输入：s = "abcaba"
输出：1
解释：出现三次的最长特殊子字符串是 "a" ：子字符串 "abcaba"、"abcaba" 和 "abcaba"。
可以证明最大长度是 1 。
 

提示：

3 <= s.length <= 5 * 105
s 仅由小写英文字母组成。
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
	int maximumLength(string s) {
		vector<vector<int>> count(26);
		int maxLen = 0;

		countSpecial(s, count);

		for (auto& cnt : count) {
			if (!cnt.empty()) {
				int max1 = 0, max2 = 0, max3 = 0;
				getMax3(cnt, max1, max2, max3);
				maxLen = max(maxLen, getMaxLen(max1, max2, max3));
			}
		}

		return maxLen == 0 ? -1 : maxLen;
	}

	void countSpecial(string& s, vector<vector<int>>& count) {
		int size = (int)s.size(), i = 0, start = 0;

		while (i < size) {
			while (i < size && s[i] == s[start]) {
				++i;
			}

			count[s[start] - 'a'].push_back(i - start);
			start = i;
		}
	}

	void getMax3(vector<int>& cnt, int& max1, int& max2, int& max3) {
		for (int len : cnt) {
			if (len >= max1) {
				max3 = max2;
				max2 = max1;
				max1 = len;
			}
			else if (len >= max2) {
				max3 = max2;
				max2 = len;
			}
			else if (len > max3) {
				max3 = len;
			}
		}
	}

	int getMaxLen(int max1, int max2, int max3) {
		int maxLen = 0;

		maxLen = max(maxLen, max1 - 2);  // 从最长的串取3个长度为max1 - 2的子串
		// max1 == max2时，从串1取2个max1 - 1子串，从串2取1个max1 - 1子串；max1 > max2时，从串1取2个max2子串，从串2取1个max2子串
		maxLen = max(maxLen, min(max1 - 1, max2));
		maxLen = max(maxLen, max3);  // 从串1、串2、串3各取一个max3子串

		return maxLen;
	}
};

int main()
{
	Solution o;
	CheckResult check;

	check.checkInt(2, o.maximumLength("aaaa"));
	check.checkInt(-1, o.maximumLength("abcdef"));
	check.checkInt(1, o.maximumLength("abcaba"));
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
