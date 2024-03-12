/* 回文字符串的最大数量.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你一个下标从 0 开始的字符串数组 words ，数组的长度为 n ，且包含下标从 0 开始的若干字符串。

你可以执行以下操作 任意 次数（包括零次）：

选择整数i、j、x和y，满足0 <= i, j < n，0 <= x < words[i].length，0 <= y < words[j].length，交换 字符 words[i][x] 和 words[j][y] 。
返回一个整数，表示在执行一些操作后，words 中可以包含的回文字符串的 最大 数量。

注意：在操作过程中，i 和 j 可以相等。



示例 1：

输入：words = ["abbb","ba","aa"]
输出：3
解释：在这个例子中，获得最多回文字符串的一种方式是：
选择 i = 0, j = 1, x = 0, y = 0，交换 words[0][0] 和 words[1][0] 。words 变成了 ["bbbb","aa","aa"] 。
words 中的所有字符串都是回文。
因此，可实现的回文字符串的最大数量是 3 。
示例 2：

输入：words = ["abc","ab"]
输出：2
解释：在这个例子中，获得最多回文字符串的一种方式是：
选择 i = 0, j = 1, x = 1, y = 0，交换 words[0][1] 和 words[1][0] 。words 变成了 ["aac","bb"] 。
选择 i = 0, j = 0, x = 1, y = 2，交换 words[0][1] 和 words[0][2] 。words 变成了 ["aca","bb"] 。
两个字符串都是回文 。
因此，可实现的回文字符串的最大数量是 2。
示例 3：

输入：words = ["cd","ef","a"]
输出：1
解释：在这个例子中，没有必要执行任何操作。
words 中有一个回文 "a" 。
可以证明，在执行任何次数操作后，无法得到更多回文。
因此，答案是 1 。


提示：

1 <= words.length <= 1000
1 <= words[i].length <= 100
words[i] 仅由小写英文字母组成。
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int maxPalindromesAfterOperations(vector<string>& words) {
		vector<int> letters(26, 0), lens(101, 0);
		int palindromes = 0, index = 0;

		for (string& word : words) {  // 统计字符串长度和字符个数
			++lens[word.size()];

			for (char c : word) {
				++letters[c - 'a'];
			}
		}

		for (int i = 1; i < 101; ++i) {  // 优先构造长度短的word
			if (lens[i] == 0) {
				continue;
			}

			for (int j = 0; j < lens[i]; ++j) {
				int len = i / 2 * 2;  // 需要len个成对的字符

				while (index < 26 && letters[index] < len) {
					len -= letters[index++] / 2 * 2;  // 从letters里面找len个成对的字符
				}

				if (index == 26) {  // 当前len构造失败，后续都不可能构造出来了
					return palindromes;
				}

				letters[index] -= len;
				++palindromes;  // 可以成功构造一个palindrome
			}
		}

		return palindromes;
    }
};

int main()
{
	Solution o;
	CheckResult check;

	vector<string> words = { "abbb","ba","aa" };
	check.checkInt(3, o.maxPalindromesAfterOperations(words));

	words = { "abc","ab" };
	check.checkInt(2, o.maxPalindromesAfterOperations(words));

	words = { "cd","ef","a" };
	check.checkInt(1, o.maxPalindromesAfterOperations(words));
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
