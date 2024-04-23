/* 统计特殊字母的数量 I.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你一个字符串 word。如果 word 中同时存在某个字母的小写形式和大写形式，则称这个字母为 特殊字母 。

返回 word 中 特殊字母 的数量。



示例 1:

输入：word = "aaAbcBC"

输出：3

解释：

word 中的特殊字母是 'a'、'b' 和 'c'。

示例 2:

输入：word = "abc"

输出：0

解释：

word 中不存在大小写形式同时出现的字母。

示例 3:

输入：word = "abBCab"

输出：1

解释：

word 中唯一的特殊字母是 'b'。



提示：

1 <= word.length <= 50
word 仅由小写和大写英文字母组成。
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int numberOfSpecialChars(string word) {
		vector<bool> exist(127, false);
		int count = 0;

		for (char c : word) {
			exist[c] = true;
		}

		for (char c = 'A'; c <= 'Z'; ++c) {
			if (exist[c] && exist[c + 32]) {
				++count;
			}
		}

		return count;
    }
};

int main()
{
	Solution o;
	CheckResult check;

	check.checkInt(3, o.numberOfSpecialChars("aaAbcBC"));
	check.checkInt(0, o.numberOfSpecialChars("abc"));
	check.checkInt(1, o.numberOfSpecialChars("abBCab"));
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
