/* 进行操作使字符串为空.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你一个字符串 s 。

请你进行以下操作直到 s 为 空 ：

每次操作 依次 遍历 'a' 到 'z'，如果当前字符出现在 s 中，那么删除出现位置 最早 的该字符（如果存在的话）。
例如，最初 s = "aabcbbca"。我们执行下述操作：

移除下划线的字符  s = "aabcbbca"。结果字符串为 s = "abbca"。
移除下划线的字符  s = "abbca"。结果字符串为 s = "ba"。
移除下划线的字符  s = "ba"。结果字符串为 s = ""。
请你返回进行 最后 一次操作 之前 的字符串 s 。在上面的例子中，答案是 "ba"。



示例 1：

输入：s = "aabcbbca"
输出："ba"
解释：已经在题目描述中解释。
示例 2：

输入：s = "abcd"
输出："abcd"
解释：我们进行以下操作：
- 删除 s = "abcd" 中加粗加斜字符，得到字符串 s = "" 。
进行最后一次操作之前的字符串为 "abcd" 。


提示：

1 <= s.length <= 5 * 105
s 只包含小写英文字母。
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    string lastNonEmptyString(string s) {
		vector<int> letters(26, 0);
		int maxFreq = 0;
		string ans;

		for (char c : s) {
			++letters[c - 'a'];
		}

		for (int freq : letters) {
			maxFreq = max(maxFreq, freq);
		}

		for (int i = s.size() - 1; i >= 0; --i) {
			char c = s[i];
			if (letters[c - 'a'] == maxFreq) {
				ans += c;
				letters[c - 'a'] = 0;
			}
		}

		reverse(ans.begin(), ans.end());

		return ans;
    }
};

int main()
{
	Solution o;
	CheckResult check;

	check.checkString("ba", o.lastNonEmptyString("aabcbbca"));
	check.checkString("abcd", o.lastNonEmptyString("abcd"));
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
