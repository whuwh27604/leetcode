/* 得到 K 个半回文串的最少修改次数.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你一个字符串 s 和一个整数 k ，请你将 s 分成 k 个 子字符串 ，使得每个 子字符串 变成 半回文串 需要修改的字符数目最少。

请你返回一个整数，表示需要修改的 最少 字符数目。

注意：

如果一个字符串从左往右和从右往左读是一样的，那么它是一个 回文串 。
如果长度为 len 的字符串存在一个满足 1 <= d < len 的正整数 d ，len % d == 0 成立且所有对 d 做除法余数相同的下标对应的字符连起来得到的字符串都是 回文串 ，那么我们说这个字符串是 半回文串 。比方说 "aa" ，"aba" ，"adbgad" 和 "abab" 都是 半回文串 ，而 "a" ，"ab" 和 "abca" 不是。
子字符串 指的是一个字符串中一段连续的字符序列。


示例 1：

输入：s = "abcac", k = 2
输出：1
解释：我们可以将 s 分成子字符串 "ab" 和 "cac" 。子字符串 "cac" 已经是半回文串。如果我们将 "ab" 变成 "aa" ，它也会变成一个 d = 1 的半回文串。
该方案是将 s 分成 2 个子字符串的前提下，得到 2 个半回文子字符串需要的最少修改次数。所以答案为 1 。
示例 2:

输入：s = "abcdef", k = 2
输出：2
解释：我们可以将 s 分成子字符串 "abc" 和 "def" 。子字符串 "abc" 和 "def" 都需要修改一个字符得到半回文串，所以我们总共需要 2 次字符修改使所有子字符串变成半回文串。
该方案是将 s 分成 2 个子字符串的前提下，得到 2 个半回文子字符串需要的最少修改次数。所以答案为 2 。
示例 3：

输入：s = "aabbaa", k = 3
输出：0
解释：我们可以将 s 分成子字符串 "aa" ，"bb" 和 "aa" 。
字符串 "aa" 和 "bb" 都已经是半回文串了。所以答案为 0 。


提示：

2 <= s.length <= 200
1 <= k <= s.length / 2
s 只包含小写英文字母。
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

int maxNum = 200;
vector<vector<int>> ds(maxNum + 1, vector<int>(1, 1));

void init() {
	static bool inited = false;

	if (!inited) {
		inited = true;

		for (int d = 2; d <= 100; ++d) {
			for (int n = d + d; n <= maxNum; n += d) {  // 注意d要小于len，所以d不能作为d本身的因子，至少从2d开始
				ds[n].push_back(d);
			}
		}
	}
}

class Solution {
public:
    int minimumChanges(string s, int k) {
		int size = (int)s.size();
		vector<vector<int>> changes(size, vector<int>(size, maxNum));

		init();
		getChanges(s, size, changes);

		return getMinChange(size, k, changes);
    }

	void getChanges(string& s, int size, vector<vector<int>>& changes) {
		for (int i = 0; i < size - 1; ++i) {
			for (int j = i + 1; j < size; ++j) {  // 单字符是不合法的，半回文串的长度至少从2开始
				changes[i][j] = getChange(s, i, j);
			}
		}
	}

	int getChange(string& s, int start, int end) {
		int minChange = maxNum;
		int len = end - start + 1;

		for (int d : ds[len]) {  // 枚举len的因子，统计在该因子下的修改次数
			int change = 0;

			for (int i = start; i < start + d; ++i) {
				int x = i, y = i + (end - i) / d * d;

				while (x < y) {
					if (s[x] != s[y]) {
						++change;
					}

					x += d;
					y -= d;
				}
			}

			minChange = min(minChange, change);
		}

		return minChange;
	}

	int getMinChange(int size, int k, vector<vector<int>>& changes) {
		vector<vector<int>> dp(size, vector<int>(k + 1, maxNum));  // dp[idx][subs]表示s[0, idx]划分为subs个子串的修改次数

		for (int idx = 1; idx < size; ++idx) {
			dp[idx][1] = changes[0][idx];

			for (int subs = 2; subs <= k; ++subs) {
				for (int start = idx - 1; start >= 2 * (subs - 1); --start) {  // 枚举最后一个sub的开始位置，前面要留够sub-1个子串的长度
					dp[idx][subs] = min(dp[idx][subs], dp[start - 1][subs - 1] + changes[start][idx]);
				}
			}
		}

		return dp[size - 1][k];
	}
};

int main()
{
	Solution o;
	CheckResult check;

	check.checkInt(1, o.minimumChanges("abcac", 2));
	check.checkInt(2, o.minimumChanges("abcdef", 2));
	check.checkInt(0, o.minimumChanges("aabbaa", 3));
	check.checkInt(2, o.minimumChanges("acba", 2));
	check.checkInt(2, o.minimumChanges("abcc", 1));
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
