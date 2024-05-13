/* 分割字符频率相等的最少子字符串.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你一个字符串 s ，你需要将它分割成一个或者更多的 平衡 子字符串。比方说，s == "ababcc" 那么 ("abab", "c", "c") ，("ab", "abc", "c") 和 ("ababcc") 都是合法分割，但是 ("a", "bab", "cc") ，("aba", "bc", "c") 和 ("ab", "abcc") 不是，不平衡的子字符串用粗体表示。

请你返回 s 最少 能分割成多少个平衡子字符串。

注意：一个 平衡 字符串指的是字符串中所有字符出现的次数都相同。



示例 1：

输入：s = "fabccddg"

输出：3

解释：

我们可以将 s 分割成 3 个子字符串：("fab, "ccdd", "g") 或者 ("fabc", "cd", "dg") 。

示例 2：

输入：s = "abababaccddb"

输出：2

解释：

我们可以将 s 分割成 2 个子字符串：("abab", "abaccddb") 。



提示：

1 <= s.length <= 1000
s 只包含小写英文字母。
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int minimumSubstringsInPartition(string s) {
		int n = (int)s.size();
		vector<int> dp(n + 1, n);
		dp[0] = 0;

		for (int i = 1; i <= n; ++i) {
			vector<int> count(26, 0);

			for (int j = i; j > 0; --j) {
				++count[s[j - 1] - 'a'];

				if (check(count)) {
					dp[i] = min(dp[i], dp[j - 1] + 1);
				}
			}
		}

		return dp[n];
    }

	bool check(vector<int>& count) {
		int freq = 0;

		for (int cnt : count) {
			if (freq == 0) {
				freq = cnt;
			}
			else {
				if (cnt != 0 && cnt != freq) {
					return false;
				}
			}
		}

		return true;
	}
};

int main()
{
	Solution o;
	CheckResult check;

	check.checkInt(3, o.minimumSubstringsInPartition("fabccddg"));
	check.checkInt(2, o.minimumSubstringsInPartition("abababaccddb"));
	check.checkInt(1, o.minimumSubstringsInPartition("z"));
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
