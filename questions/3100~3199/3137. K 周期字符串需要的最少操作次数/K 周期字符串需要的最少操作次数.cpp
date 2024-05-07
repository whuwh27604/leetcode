/* K 周期字符串需要的最少操作次数.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你一个长度为 n 的字符串 word 和一个整数 k ，其中 k 是 n 的因数。

在一次操作中，你可以选择任意两个下标 i 和 j，其中 0 <= i, j < n ，且这两个下标都可以被 k 整除，然后用从 j 开始的长度为 k 的子串替换从 i 开始的长度为 k 的子串。也就是说，将子串 word[i..i + k - 1] 替换为子串 word[j..j + k - 1] 。

返回使 word 成为 K 周期字符串 所需的 最少 操作次数。

如果存在某个长度为 k 的字符串 s，使得 word 可以表示为任意次数连接 s ，则称字符串 word 是 K 周期字符串 。例如，如果 word == "ababab"，那么 word 就是 s = "ab" 时的 2 周期字符串 。



示例 1：

输入：word = "leetcodeleet", k = 4

输出：1

解释：可以选择 i = 4 和 j = 0 获得一个 4 周期字符串。这次操作后，word 变为 "leetleetleet" 。

示例 2：

输入：word = "leetcoleet", k = 2

输出：3

解释：可以执行以下操作获得一个 2 周期字符串。

i	j	word
0	2	etetcoleet
4	0	etetetleet
6	0	etetetetet


提示：

1 <= n == word.length <= 105
1 <= k <= word.length
k 能整除 word.length 。
word 仅由小写英文字母组成。
*/

#include <iostream>
#include <unordered_map>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int minimumOperationsToMakeKPeriodic(string word, int k) {
		unordered_map<string, int> count;
		int maxCount = 0, size = (int)word.size();

		for (int i = 0; i < size; i += k) {
			string sub(word, i, k);
			maxCount = max(maxCount, ++count[string(word, i, k)]);
		}

		return size / k - maxCount;
    }
};

int main()
{
	Solution o;
	CheckResult check;

	check.checkInt(1, o.minimumOperationsToMakeKPeriodic("leetcodeleet", 4));
	check.checkInt(3, o.minimumOperationsToMakeKPeriodic("leetcoleet", 2));
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
