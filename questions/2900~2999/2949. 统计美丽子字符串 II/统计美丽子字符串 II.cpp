/* 统计美丽子字符串 II.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你一个字符串 s 和一个正整数 k 。

用 vowels 和 consonants 分别表示字符串中元音字母和辅音字母的数量。

如果某个字符串满足以下条件，则称其为 美丽字符串 ：

vowels == consonants，即元音字母和辅音字母的数量相等。
(vowels * consonants) % k == 0，即元音字母和辅音字母的数量的乘积能被 k 整除。
返回字符串 s 中 非空美丽子字符串 的数量。

子字符串是字符串中的一个连续字符序列。

英语中的 元音字母 为 'a'、'e'、'i'、'o' 和 'u' 。

英语中的 辅音字母 为除了元音字母之外的所有字母。



示例 1：

输入：s = "baeyh", k = 2
输出：2
解释：字符串 s 中有 2 个美丽子字符串。
- 子字符串 "baeyh"，vowels = 2（["a","e"]），consonants = 2（["y","h"]）。
可以看出字符串 "aeyh" 是美丽字符串，因为 vowels == consonants 且 vowels * consonants % k == 0 。
- 子字符串 "baeyh"，vowels = 2（["a","e"]），consonants = 2（["b","y"]）。
可以看出字符串 "baey" 是美丽字符串，因为 vowels == consonants 且 vowels * consonants % k == 0 。
可以证明字符串 s 中只有 2 个美丽子字符串。
示例 2：

输入：s = "abba", k = 1
输出：3
解释：字符串 s 中有 3 个美丽子字符串。
- 子字符串 "abba"，vowels = 1（["a"]），consonants = 1（["b"]）。
- 子字符串 "abba"，vowels = 1（["a"]），consonants = 1（["b"]）。
- 子字符串 "abba"，vowels = 2（["a","a"]），consonants = 2（["b","b"]）。
可以证明字符串 s 中只有 3 个美丽子字符串。
示例 3：

输入：s = "bcdf", k = 1
输出：0
解释：字符串 s 中没有美丽子字符串。


提示：

1 <= s.length <= 5 * 104
1 <= k <= 1000
s 仅由小写英文字母组成。
*/

#include <iostream>
#include <unordered_map>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    long long beautifulSubstrings(string s, int k) {
		int sum = 0, size = s.size(), mod = getMod(k);
		long long beauties = 0;
		unordered_map<int, vector<int>> indices;
		indices[0].push_back(0);  // 预置一个sum为0，index为0的节点，后续的index从1开始

		for (int i = 0; i < size; ++i) {
			if (isVowel(s[i])) {
				++sum;
			}
			else {
				--sum;
			}

			indices[sum].push_back(i + 1);
		}

		for (auto& kv : indices) {  // 所有sum相等的2个节点之间的vowels == consonants，在这些节点中找长度是mod的倍数的
			beauties += getBeauties(kv.second, mod);
		}

		return beauties;
    }

	bool isVowel(char c) {
		return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
	}

	int getMod(int k) {
		int mod = 0;

		// (len / 2) ^ 2 % k = 0, k = x * n ^ 2, 那么len需要是2 * x * n的倍数，n越大时，2 * x * n越小;
		for (int n = 31; n > 0; --n) {
			int m = n * n;
			if (k % m == 0) {
				mod = k / m * n * 2;
				break;
			}
		}

		return mod;
	}

	long long getBeauties(vector<int>& indices, int mod) {
		long long beauties = 0;
		unordered_map<int, int> count;

		for (int index : indices) {  // 如果2个index对mod取余的结果相等，那么他们之间的长度是mod的倍数
			++count[index % mod];
		}

		for (auto& kv : count) {
			int cnt = kv.second;
			beauties += (((long long)cnt - 1) * cnt / 2);  // 两两之间的节点都可以构成一个beauty
		}

		return beauties;
	}
};

int main()
{
	Solution o;
	CheckResult check;

	check.checkLongLong(2, o.beautifulSubstrings("baeyh", 2));
	check.checkLongLong(3, o.beautifulSubstrings("abba", 1));
	check.checkLongLong(0, o.beautifulSubstrings("bcdf", 1));
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
