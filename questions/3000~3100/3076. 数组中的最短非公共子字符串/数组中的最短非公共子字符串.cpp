/* 数组中的最短非公共子字符串.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你一个数组 arr ，数组中有 n 个 非空 字符串。

请你求出一个长度为 n 的字符串 answer ，满足：

answer[i] 是 arr[i] 最短 的子字符串，且它不是 arr 中其他任何字符串的子字符串。如果有多个这样的子字符串存在，answer[i] 应该是它们中字典序最小的一个。如果不存在这样的子字符串，answer[i] 为空字符串。
请你返回数组 answer 。



示例 1：

输入：arr = ["cab","ad","bad","c"]
输出：["ab","","ba",""]
解释：求解过程如下：
- 对于字符串 "cab" ，最短没有在其他字符串中出现过的子字符串是 "ca" 或者 "ab" ，我们选择字典序更小的子字符串，也就是 "ab" 。
- 对于字符串 "ad" ，不存在没有在其他字符串中出现过的子字符串。
- 对于字符串 "bad" ，最短没有在其他字符串中出现过的子字符串是 "ba" 。
- 对于字符串 "c" ，不存在没有在其他字符串中出现过的子字符串。
示例 2：

输入：arr = ["abc","bcd","abcd"]
输出：["","","abcd"]
解释：求解过程如下：
- 对于字符串 "abc" ，不存在没有在其他字符串中出现过的子字符串。
- 对于字符串 "bcd" ，不存在没有在其他字符串中出现过的子字符串。
- 对于字符串 "abcd" ，最短没有在其他字符串中出现过的子字符串是 "abcd" 。


提示：

n == arr.length
2 <= n <= 100
1 <= arr[i].length <= 20
arr[i] 只包含小写英文字母。
*/

#include <iostream>
#include <unordered_map>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    vector<string> shortestSubstrings(vector<string>& arr) {
		int n = arr.size(), index = 0;
		vector<string> ans(n);
		unordered_map<string, int> words;

		for (auto& word : arr) {
			addDel(word, words, 1);
		}

		for (auto& word : arr) {
			addDel(word, words, 0);

			int size = word.size();

			for (int len = 0; len < size; ++len) {
				for (int i = 0; i + len < size; ++i) {
					string sub(word, i, len + 1);

					if (words[sub] == 0) {
						if (ans[index].empty()) {
							ans[index] = sub;
						}
						else {
							ans[index] = min(ans[index], sub);
						}
					}
				}

				if (!ans[index].empty()) {
					break;
				}
			}

			addDel(word, words, 1);
			++index;
		}

		return ans;
    }

	void addDel(string& word, unordered_map<string, int>& words, int oper) {
		int size = word.size();

		for (int len = 0; len < size; ++len) {
			for (int i = 0; i + len < size; ++i) {
				string sub(word, i, len + 1);
				if (oper == 1) {
					++words[sub];
				}
				else {
					--words[sub];
				}
			}
		}
	}
};

int main()
{
	Solution o;
	CheckResult check;

	vector<string> arr = { "cab","ad","bad","c" };
	vector<string> actual = o.shortestSubstrings(arr);
	vector<string> expected = { "ab","","ba","" };
	check.checkStringVector(expected, actual);

	arr = { "abc","bcd","abcd" };
	actual = o.shortestSubstrings(arr);
	expected = { "","","abcd" };
	check.checkStringVector(expected, actual);
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
