/* 成为 K 特殊字符串需要删除的最少字符数.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你一个字符串 word 和一个整数 k。

如果 |freq(word[i]) - freq(word[j])| <= k 对于字符串中所有下标 i 和 j  都成立，则认为 word 是 k 特殊字符串。

此处，freq(x) 表示字符 x 在 word 中的
出现频率
，而 |y| 表示 y 的绝对值。

返回使 word 成为 k 特殊字符串 需要删除的字符的最小数量。



示例 1：

输入：word = "aabcaba", k = 0

输出：3

解释：可以删除 2 个 "a" 和 1 个 "c" 使 word 成为 0 特殊字符串。word 变为 "baba"，此时 freq('a') == freq('b') == 2。

示例 2：

输入：word = "dabdcbdcdcd", k = 2

输出：2

解释：可以删除 1 个 "a" 和 1 个 "d" 使 word 成为 2 特殊字符串。word 变为 "bdcbdcdcd"，此时 freq('b') == 2，freq('c') == 3，freq('d') == 4。

示例 3：

输入：word = "aaabaaa", k = 2

输出：1

解释：可以删除 1 个 "b" 使 word 成为 2特殊字符串。因此，word 变为 "aaaaaa"，此时每个字母的频率都是 6。



提示：

1 <= word.length <= 105
0 <= k <= 105
word 仅由小写英文字母组成。
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int minimumDeletions(string word, int k) {
		vector<int> count(26, 0);
		int minDeletions = INT_MAX;

		for (char c : word) {
			++count[c - 'a'];
		}

		for (int cnt : count) {
			if (cnt != 0) {
				minDeletions = min(minDeletions, getDeletions(count, cnt, k));
			}
		}

		return minDeletions;
    }

	int getDeletions(vector<int>& count, int minFreq, int k) {
		int deletions = 0, maxFreq = minFreq + k;

		for (int cnt : count) {
			if (cnt < minFreq) {
				deletions += cnt;  // 比minFreq小的都要被删除
			}
			else {
				if (cnt > maxFreq) {
					deletions += (cnt - maxFreq);  // 比maxFreq大的要被删除到maxFreq个
				}
			}
		}

		return deletions;
	}
};

int main()
{
	Solution o;
	CheckResult check;

	check.checkInt(3, o.minimumDeletions("aabcaba", 0));
	check.checkInt(2, o.minimumDeletions("dabdcbdcdcd", 2));
	check.checkInt(1, o.minimumDeletions("aaabaaa", 2));
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
