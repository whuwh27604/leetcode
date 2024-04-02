/* 字符串及其反转中是否存在同一子字符串.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你一个字符串 s ，请你判断字符串 s 是否存在一个长度为 2 的子字符串，在其反转后的字符串中也出现。

如果存在这样的子字符串，返回 true；如果不存在，返回 false 。



示例 1：

输入：s = "leetcode"

输出：true

解释：子字符串 "ee" 的长度为 2，它也出现在 reverse(s) == "edocteel" 中。

示例 2：

输入：s = "abcba"

输出：true

解释：所有长度为 2 的子字符串 "ab"、"bc"、"cb"、"ba" 也都出现在 reverse(s) == "abcba" 中。

示例 3：

输入：s = "abcd"

输出：false

解释：字符串 s 中不存在满足「在其反转后的字符串中也出现」且长度为 2 的子字符串。



提示：

1 <= s.length <= 100
字符串 s 仅由小写英文字母组成。
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    bool isSubstringPresent(string s) {
		int size = s.size();
		vector<vector<bool>> exist(26, vector<bool>(26, false));

		for (int i = 0; i < size - 1; ++i) {
			int x = s[i] - 'a', y = s[i + 1] - 'a';
			exist[x][y] = true;

			if (exist[y][x]) {
				return true;
			}
		}

		return false;
    }
};

int main()
{
	Solution o;
	CheckResult check;

	check.checkBool(true, o.isSubstringPresent("leetcode"));
	check.checkBool(true, o.isSubstringPresent("abcba"));
	check.checkBool(false, o.isSubstringPresent("abcd"));
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
