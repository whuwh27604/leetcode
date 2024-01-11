/* 回文串重新排列查询.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你一个长度为 偶数 n ，下标从 0 开始的字符串 s 。

同时给你一个下标从 0 开始的二维整数数组 queries ，其中 queries[i] = [ai, bi, ci, di] 。

对于每个查询 i ，你需要执行以下操作：

将下标在范围 0 <= ai <= bi < n / 2 内的 子字符串 s[ai:bi] 中的字符重新排列。
将下标在范围 n / 2 <= ci <= di < n 内的 子字符串 s[ci:di] 中的字符重新排列。
对于每个查询，你的任务是判断执行操作后能否让 s 变成一个 回文串 。

每个查询与其他查询都是 独立的 。

请你返回一个下标从 0 开始的数组 answer ，如果第 i 个查询执行操作后，可以将 s 变为一个回文串，那么 answer[i] = true，否则为 false 。

子字符串 指的是一个字符串中一段连续的字符序列。
s[x:y] 表示 s 中从下标 x 到 y 且两个端点 都包含 的子字符串。


示例 1：

输入：s = "abcabc", queries = [[1,1,3,5],[0,2,5,5]]
输出：[true,true]
解释：这个例子中，有 2 个查询：
第一个查询：
- a0 = 1, b0 = 1, c0 = 3, d0 = 5
- 你可以重新排列 s[1:1] => abcabc 和 s[3:5] => abcabc 。
- 为了让 s 变为回文串，s[3:5] 可以重新排列得到 => abccba 。
- 现在 s 是一个回文串。所以 answer[0] = true 。
第二个查询：
- a1 = 0, b1 = 2, c1 = 5, d1 = 5.
- 你可以重新排列 s[0:2] => abcabc 和 s[5:5] => abcabc 。
- 为了让 s 变为回文串，s[0:2] 可以重新排列得到 => cbaabc 。
- 现在 s 是一个回文串，所以 answer[1] = true 。
示例 2：

输入：s = "abbcdecbba", queries = [[0,2,7,9]]
输出：[false]
解释：这个示例中，只有一个查询。
a0 = 0, b0 = 2, c0 = 7, d0 = 9.
你可以重新排列 s[0:2] => abbcdecbba 和 s[7:9] => abbcdecbba 。
无法通过重新排列这些子字符串使 s 变为一个回文串，因为 s[3:6] 不是一个回文串。
所以 answer[0] = false 。
示例 3：

输入：s = "acbcab", queries = [[1,2,4,5]]
输出：[true]
解释：这个示例中，只有一个查询。
a0 = 1, b0 = 2, c0 = 4, d0 = 5.
你可以重新排列 s[1:2] => acbcab 和 s[4:5] => acbcab 。
为了让 s 变为回文串，s[1:2] 可以重新排列得到 => abccab 。
然后 s[4:5] 重新排列得到 abccba 。
现在 s 是一个回文串，所以 answer[0] = true 。


提示：

2 <= n == s.length <= 105
1 <= queries.length <= 105
queries[i].length == 4
ai == queries[i][0], bi == queries[i][1]
ci == queries[i][2], di == queries[i][3]
0 <= ai <= bi < n / 2
n / 2 <= ci <= di < n
n 是一个偶数。
s 只包含小写英文字母。
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    vector<bool> canMakePalindromeQueries(string s, vector<vector<int>>& queries) {
		int n = (int)s.size(), half = n / 2;
		vector<vector<int>> presum1(half + 1, vector<int>(size, 0)), presum2(half + 1, vector<int>(size, 0));
		vector<int> diffSum(half + 1, 0);
		vector<bool> ans;

		getPresum(s, n, half, presum1, presum2, diffSum);

		for (auto& query : queries) {
			int a = query[0], b = query[1], c = n - query[3] - 1, d = n - query[2] - 1;
			if (a <= c) {
				ans.push_back(check(presum1, presum2, diffSum, half, a, b, c, d));
			}
			else {
				ans.push_back(check(presum2, presum1, diffSum, half, c, d, a, b));
			}
		}

		return ans;
    }

	void getPresum(string& s, int n, int half, vector<vector<int>>& presum1, vector<vector<int>>& presum2, vector<int>& diffSum) {
		vector<int> cnt1(size, 0), cnt2(size, 0);

		for (int i = 0; i < half; ++i) {
			int idx1 = s[i] - 'a', idx2 = s[n - 1 - i] - 'a';
			++cnt1[idx1];
			presum1[i + 1] = cnt1;
			++cnt2[idx2];
			presum2[i + 1] = cnt2;
			diffSum[i + 1] = idx1 == idx2 ? diffSum[i] : diffSum[i] + 1;
		}
	}

	bool check(vector<vector<int>>& presum1, vector<vector<int>>& presum2, vector<int>& diffSum,
		int half, int a, int b, int c, int d) {
		vector<int> cnt1, cnt2;

		int x = max(b, d) + 1;
		if (diffSum[a] != 0 || diffSum[half] - diffSum[x] != 0) {  // 区间[0,a)和区间[x,half)必须完全相等
			return false;
		}

		if (d <= b) {  // [c,d]包含在区间[a,b]内，那么只需要[a,b]范围内字符统计相等
			cnt1 = minus(presum1[a], presum1[b + 1]), cnt2 = minus(presum2[a], presum2[b + 1]);
			return isEqual(cnt1, cnt2);
		}

		if (c > b) {  // 两个区间不相交，那么[a,b]、[c,d]都必须统计相等，(b,c)必须完全相等
			cnt1 = minus(presum1[a], presum1[b + 1]), cnt2 = minus(presum2[a], presum2[b + 1]);
			if (!isEqual(cnt1, cnt2)) {
				return false;
			}

			cnt1 = minus(presum1[c], presum1[d + 1]), cnt2 = minus(presum2[c], presum2[d + 1]);
			if (!isEqual(cnt1, cnt2)) {
				return false;
			}

			return diffSum[c] - diffSum[b + 1] == 0;
		}

		// [a,b]、[c,d]相交但不包含，那么s1[a,b]必须包含s2[a,c)，s2[c,d]必须包含s1(b,d]，然后剩下部分要统计相等
		cnt1 = minus(presum1[a], presum1[b + 1]), cnt2 = minus(presum2[a], presum2[c]);
		if (!exclude(cnt1, cnt2)) {
			return false;
		}

		vector<int> left = cnt1;
		cnt1 = minus(presum2[c], presum2[d + 1]), cnt2 = minus(presum1[b + 1], presum1[d + 1]);
		if (!exclude(cnt1, cnt2)) {
			return false;
		}

		return left == cnt1;
	}

	vector<int> minus(vector<int>& sum1, vector<int>& sum2) {
		vector<int> cnt(size);

		for (int i = 0; i < size; ++i) {
			cnt[i] = sum2[i] - sum1[i];
		}

		return cnt;
	}

	bool exclude(vector<int>& cnt1, vector<int>& cnt2) {
		for (int i = 0; i < size; ++i) {
			if (cnt1[i] < cnt2[i]) {
				return false;
			}

			cnt1[i] -= cnt2[i];
		}

		return true;
	}

	bool isEqual(vector<int>& cnt1, vector<int>& cnt2) {
		for (int i = 0; i < size; ++i) {
			if (cnt1[i] != cnt2[i]) {
				return false;
			}
		}

		return true;
	}

	int size = 26;
};

int main()
{
	Solution o;
	CheckResult check;

	vector<vector<int>> queries = { {1,1,3,5},{0,2,5,5} };
	vector<bool> actual = o.canMakePalindromeQueries("abcabc", queries);
	vector<bool> expected = { true,true };
	check.checkBoolVector(expected, actual);

	queries = { {0,2,7,9} };
	actual = o.canMakePalindromeQueries("abbcdecbba", queries);
	expected = { false };
	check.checkBoolVector(expected, actual);

	queries = { {1,2,4,5} };
	actual = o.canMakePalindromeQueries("acbcab", queries);
	expected = { true };
	check.checkBoolVector(expected, actual);

	queries = { {5,10,13,23} };
	actual = o.canMakePalindromeQueries("stgjtzqwgkuadjgqugkwdtzast", queries);
	expected = { false };
	check.checkBoolVector(expected, actual);
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
