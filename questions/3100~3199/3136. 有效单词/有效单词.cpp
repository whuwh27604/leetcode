/* 有效单词.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
有效单词 需要满足以下几个条件：

至少 包含 3 个字符。
由数字 0-9 和英文大小写字母组成。（不必包含所有这类字符。）
至少 包含一个 元音字母 。
至少 包含一个 辅音字母 。
给你一个字符串 word 。如果 word 是一个有效单词，则返回 true ，否则返回 false 。

注意：

'a'、'e'、'i'、'o'、'u' 及其大写形式都属于 元音字母 。
英文中的 辅音字母 是指那些除元音字母之外的字母。


示例 1：

输入：word = "234Adas"

输出：true

解释：

这个单词满足所有条件。

示例 2：

输入：word = "b3"

输出：false

解释：

这个单词的长度少于 3 且没有包含元音字母。

示例 3：

输入：word = "a3$e"

输出：false

解释：

这个单词包含了 '$' 字符且没有包含辅音字母。



提示：

1 <= word.length <= 20
word 由英文大写和小写字母、数字、'@'、'#' 和 '$' 组成。
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    bool isValid(string word) {
		bool hasVowel = false, hasConsonant = false;

		for (char c : word) {
			if (c >= '0' && c <= '9') {
				// nothing to do
			}
			else if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z')) {
				if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u'
					|| c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U') {
					hasVowel = true;
				}
				else {
					hasConsonant = true;
				}
			}
			else {
				return false;
			}
		}

		return word.size() > 2 && hasVowel && hasConsonant;
    }
};

int main()
{
	Solution o;
	CheckResult check;

	check.checkBool(true, o.isValid("234Adas"));
	check.checkBool(false, o.isValid("b3"));
	check.checkBool(false, o.isValid("a3$e"));
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
