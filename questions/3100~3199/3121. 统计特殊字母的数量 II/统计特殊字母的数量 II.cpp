/* 统计特殊字母的数量 II.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你一个字符串 word。如果 word 中同时出现某个字母 c 的小写形式和大写形式，并且 每个 小写形式的 c 都出现在第一个大写形式的 c 之前，则称字母 c 是一个 特殊字母 。

返回 word 中 特殊字母 的数量。



示例 1:

输入：word = "aaAbcBC"

输出：3

解释：

特殊字母是 'a'、'b' 和 'c'。

示例 2:

输入：word = "abc"

输出：0

解释：

word 中不存在特殊字母。

示例 3:

输入：word = "AbBCab"

输出：0

解释：

word 中不存在特殊字母。



提示：

1 <= word.length <= 2 * 105
word 仅由小写和大写英文字母组成。
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int numberOfSpecialChars(string word) {
		vector<int> state(26, 0);  // 0; 1 : a; 2 : aA; -1 : A,Aa
		int count = 0;

		for (char c : word) {
			if (c > 'Z') {
				int idx = c - 'a';
				if (state[idx] == 0) {
					state[idx] = 1;
				}
				else if (state[idx] == 2) {
					state[idx] = -1;
				}
			}
			else {
				int idx = c - 'A';
				if (state[idx] == 0) {
					state[idx] = -1;
				}
				else if (state[idx] == 1) {
					state[idx] = 2;
				}
			}
		}

		for (int i = 0; i < 26; ++i) {
			if (state[i] == 2) {
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
	check.checkInt(0, o.numberOfSpecialChars("AbBCab"));
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
