﻿/* 输入单词需要的最少按键次数 I.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你一个字符串 word，由 不同 小写英文字母组成。

电话键盘上的按键与 不同 小写英文字母集合相映射，可以通过按压按键来组成单词。例如，按键 2 对应 ["a","b","c"]，我们需要按一次键来输入 "a"，按两次键来输入 "b"，按三次键来输入 "c"。

现在允许你将编号为 2 到 9 的按键重新映射到 不同 字母集合。每个按键可以映射到 任意数量 的字母，但每个字母 必须 恰好 映射到 一个 按键上。你需要找到输入字符串 word 所需的 最少 按键次数。

返回重新映射按键后输入 word 所需的 最少 按键次数。

下面给出了一种电话键盘上字母到按键的映射作为示例。注意 1，*，# 和 0 不 对应任何字母。




示例 1：


输入：word = "abcde"
输出：5
解释：图片中给出的重新映射方案的输入成本最小。
"a" -> 在按键 2 上按一次
"b" -> 在按键 3 上按一次
"c" -> 在按键 4 上按一次
"d" -> 在按键 5 上按一次
"e" -> 在按键 6 上按一次
总成本为 1 + 1 + 1 + 1 + 1 = 5 。
可以证明不存在其他成本更低的映射方案。
示例 2：


输入：word = "xycdefghij"
输出：12
解释：图片中给出的重新映射方案的输入成本最小。
"x" -> 在按键 2 上按一次
"y" -> 在按键 2 上按两次
"c" -> 在按键 3 上按一次
"d" -> 在按键 3 上按两次
"e" -> 在按键 4 上按一次
"f" -> 在按键 5 上按一次
"g" -> 在按键 6 上按一次
"h" -> 在按键 7 上按一次
"i" -> 在按键 8 上按一次
"j" -> 在按键 9 上按一次
总成本为 1 + 2 + 1 + 2 + 1 + 1 + 1 + 1 + 1 + 1 = 12 。
可以证明不存在其他成本更低的映射方案。


提示：

1 <= word.length <= 26
word 仅由小写英文字母组成。
word 中的所有字母互不相同。
*/

#include <iostream>
#include <algorithm>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int minimumPushes(string word) {
		int len = word.size(), push = 1, pushes = 0;

		while (len >= 8) {
			pushes += (8 * push++);  // word每个字符都不相同
			len -= 8;
		}

		return pushes + len * push;
    }
};

int main()
{
	Solution o;
	CheckResult check;

	check.checkInt(5, o.minimumPushes("abcde"));
	check.checkInt(12, o.minimumPushes("xycdefghij"));
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
