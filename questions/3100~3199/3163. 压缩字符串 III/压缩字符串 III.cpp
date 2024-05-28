/* 压缩字符串 III.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你一个字符串 word，请你使用以下算法进行压缩：

从空字符串 comp 开始。当 word 不为空 时，执行以下操作：
移除 word 的最长单字符前缀，该前缀由单一字符 c 重复多次组成，且该前缀长度 最多 为 9 。
将前缀的长度和字符 c 追加到 comp 。
返回字符串 comp 。





示例 1：

输入：word = "abcde"

输出："1a1b1c1d1e"

解释：

初始时，comp = "" 。进行 5 次操作，每次操作分别选择 "a"、"b"、"c"、"d" 和 "e" 作为前缀。

对每个前缀，将 "1" 和对应的字符追加到 comp。

示例 2：

输入：word = "aaaaaaaaaaaaaabb"

输出："9a5a2b"

解释：

初始时，comp = ""。进行 3 次操作，每次操作分别选择 "aaaaaaaaa"、"aaaaa" 和 "bb" 作为前缀。

对于前缀 "aaaaaaaaa"，将 "9" 和 "a" 追加到 comp。
对于前缀 "aaaaa"，将 "5" 和 "a" 追加到 comp。
对于前缀 "bb"，将 "2" 和 "b" 追加到 comp。


提示：

1 <= word.length <= 2 * 105
word 仅由小写英文字母组成。
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    string compressedString(string word) {
		string comp;
		int size = (int)word.size(), i = 0;

		while (i < size) {
			int j = i + 1;

			while (j < size && word[j] == word[i] && j - i < 9) {
				++j;
			}

			comp += ('0' + j - i);
			comp += word[i];
			i = j;
		}

		return comp;
    }
};

int main()
{
	Solution o;
	CheckResult check;

	check.checkString("1a1b1c1d1e", o.compressedString("abcde"));
	check.checkString("9a5a2b", o.compressedString("aaaaaaaaaaaaaabb"));
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
