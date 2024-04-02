/* 执行操作后的最大分割数量.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你一个下标从 0 开始的字符串 s 和一个整数 k。

你需要执行以下分割操作，直到字符串 s 变为 空：

选择 s 的最长前缀，该前缀最多包含 k 个 不同 字符。
删除 这个前缀，并将分割数量加一。如果有剩余字符，它们在 s 中保持原来的顺序。
执行操作之 前 ，你可以将 s 中 至多一处 下标的对应字符更改为另一个小写英文字母。

在最优选择情形下改变至多一处下标对应字符后，用整数表示并返回操作结束时得到的最大分割数量。



示例 1：

输入：s = "accca", k = 2
输出：3
解释：在此示例中，为了最大化得到的分割数量，可以将 s[2] 改为 'b'。
s 变为 "acbca"。
按照以下方式执行操作，直到 s 变为空：
- 选择最长且至多包含 2 个不同字符的前缀，"acbca"。
- 删除该前缀，s 变为 "bca"。现在分割数量为 1。
- 选择最长且至多包含 2 个不同字符的前缀，"bca"。
- 删除该前缀，s 变为 "a"。现在分割数量为 2。
- 选择最长且至多包含 2 个不同字符的前缀，"a"。
- 删除该前缀，s 变为空。现在分割数量为 3。
因此，答案是 3。
可以证明，分割数量不可能超过 3。
示例 2：

输入：s = "aabaab", k = 3
输出：1
解释：在此示例中，为了最大化得到的分割数量，可以保持 s 不变。
按照以下方式执行操作，直到 s 变为空：
- 选择最长且至多包含 3 个不同字符的前缀，"aabaab"。
- 删除该前缀，s 变为空。现在分割数量为 1。
因此，答案是 1。
可以证明，分割数量不可能超过 1。
示例 3：

输入：s = "xxyz", k = 1
输出：4
解释：在此示例中，为了最大化得到的分割数量，可以将 s[1] 改为 'a'。
s 变为 "xayz"。
按照以下方式执行操作，直到 s 变为空：
- 选择最长且至多包含 1 个不同字符的前缀，"xayz"。
- 删除该前缀，s 变为 "ayz"。现在分割数量为 1。
- 选择最长且至多包含 1 个不同字符的前缀，"ayz"。
- 删除该前缀，s 变为 "yz"，现在分割数量为 2。
- 选择最长且至多包含 1 个不同字符的前缀，"yz"。
- 删除该前缀，s 变为 "z"。现在分割数量为 3。
- 选择最且至多包含 1 个不同字符的前缀，"z"。
- 删除该前缀，s 变为空。现在分割数量为 4。
因此，答案是 4。
可以证明，分割数量不可能超过 4。


提示：

1 <= s.length <= 104
s 只包含小写英文字母。
1 <= k <= 26
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int maxPartitionsAfterOperations(string s, int k) {
		int size = s.size();
		if (size == 1 || k == 26) {  // 如果s只有一个字符或者k是字符全集，显然无论如何操作都只能是1段
			return 1;
		}

		vector<int> preSegments(size), preMasks(size), sufSegments(size), sufMasks(size);

		getPrefix(s, size, k, preMasks, preSegments);  // 统计前缀可以分割的段数segments和最后一段的字符集mask
		getSuffix(s, size, k, sufMasks, sufSegments);  // 统计后缀可以分割的段数segments和最后一段的字符集mask

		return getMaxSegment(size, k, preMasks, preSegments, sufMasks, sufSegments);
    }

	void getPrefix(string& s, int size, int k, vector<int>& preMasks, vector<int>& preSegments) {
		int bits = 0, mask = 0, segment = 1;

		for (int i = 0; i < size; ++i) {
			int bit = (1 << (s[i] - 'a'));
			if ((mask & bit) == 0) {
				if (++bits > k) {
					++segment;
					mask = 0;
					bits = 1;
				}
			}

			mask |= bit;
			preMasks[i] = mask;
			preSegments[i] = segment;
		}
	}

	void getSuffix(string& s, int size, int k, vector<int>& sufMasks, vector<int>& sufSegments) {
		int bits = 0, mask = 0, segment = 1;

		for (int i = size - 1; i >= 0; --i) {
			int bit = (1 << (s[i] - 'a'));
			if ((mask & bit) == 0) {
				if (++bits > k) {
					++segment;
					mask = 0;
					bits = 1;
				}
			}

			mask |= bit;
			sufMasks[i] = mask;
			sufSegments[i] = segment;
		}
	}

	int getMaxSegment(int size, int k, vector<int>& preMasks, vector<int>& preSegments, vector<int>& sufMasks, vector<int>& sufSegments) {
		int maxSegment = sufSegments[0];  // 可以证明，从前往后和从后往前分割的总段数一定是相等的
		if ((sufSegments[0] == sufSegments[1] && popcount(sufMasks[1]) == k) ||
			(preSegments[size - 1] == preSegments[size - 2] && popcount(preMasks[size - 2]) == k)) {
			++maxSegment;  // 改变首尾字符可以多分出一段来
		}

		for (int i = 1; i < size - 1; ++i) {  // 遍历中间位置的字符，尝试修改它
			int segment = preSegments[i - 1] + sufSegments[i + 1];  // 默认可以分割的段数是前后缀之和，修改中间这个字符并不能改变段数
			int mask = preMasks[i - 1] | sufMasks[i + 1];  // 讨论前后缀最后一段的字符并集
			int bits = popcount(mask);
			if (bits < k) {
				--segment;  // 并集的字符数量小于k，那么无论如何修改字符s[i]，preLast、s[i]、sufLast都应该合并为一段，所以总段数要减1
			}
			else if (bits < 26 && popcount(preMasks[i - 1]) == k && popcount(sufMasks[i + 1]) == k) {
				++segment;  // preLast、sufLast都已经可以独立成段，那么将s[i]修改为一个其它字符，可以使总段数加1
			}

			maxSegment = max(maxSegment, segment);
		}

		return maxSegment;
	}

	int popcount(int n) {
		int cnt = 0;

		while (n != 0) {
			n &= (n - 1);
			++cnt;
		}

		return cnt;
	}
};

int main()
{
	Solution o;
	CheckResult check;

	check.checkInt(3, o.maxPartitionsAfterOperations("accca", 2));
	check.checkInt(1, o.maxPartitionsAfterOperations("aabaab", 3));
	check.checkInt(4, o.maxPartitionsAfterOperations("xxyz", 1));
	check.checkInt(2, o.maxPartitionsAfterOperations("aca", 2));
	check.checkInt(2, o.maxPartitionsAfterOperations("baca", 2));
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
