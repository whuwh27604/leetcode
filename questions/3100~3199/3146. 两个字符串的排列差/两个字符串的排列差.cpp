/* 两个字符串的排列差.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你两个字符串 s 和 t，每个字符串中的字符都不重复，且 t 是 s 的一个排列。

排列差 定义为 s 和 t 中每个字符在两个字符串中位置的绝对差值之和。

返回 s 和 t 之间的 排列差 。



示例 1：

输入：s = "abc", t = "bac"

输出：2

解释：

对于 s = "abc" 和 t = "bac"，排列差是：

"a" 在 s 中的位置与在 t 中的位置之差的绝对值。
"b" 在 s 中的位置与在 t 中的位置之差的绝对值。
"c" 在 s 中的位置与在 t 中的位置之差的绝对值。
即，s 和 t 的排列差等于 |0 - 1| + |2 - 2| + |1 - 0| = 2。

示例 2：

输入：s = "abcde", t = "edbac"

输出：12

解释： s 和 t 的排列差等于 |0 - 3| + |1 - 2| + |2 - 4| + |3 - 1| + |4 - 0| = 12。



提示：

1 <= s.length <= 26
每个字符在 s 中最多出现一次。
t 是 s 的一个排列。
s 仅由小写英文字母组成。
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int findPermutationDifference(string s, string t) {
		int n = (int)s.size(), sum = 0;
		vector<int> indices(127);

		for (int i = 0; i < n; ++i) {
			indices[s[i]] = i;
		}

		for (int i = 0; i < n; ++i) {
			sum += abs(i - indices[t[i]]);
		}

		return sum;
    }
};

int main()
{
	Solution o;
	CheckResult check;

	check.checkInt(2, o.findPermutationDifference("abc", "bac"));
	check.checkInt(12, o.findPermutationDifference("abcde", "edbac"));
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
