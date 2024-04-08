/* 满足距离约束且字典序最小的字符串.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你一个字符串 s 和一个整数 k 。

定义函数 distance(s1, s2) ，用于衡量两个长度为 n 的字符串 s1 和 s2 之间的距离，即：

字符 'a' 到 'z' 按 循环 顺序排列，对于区间 [0, n - 1] 中的 i ，计算所有「 s1[i] 和 s2[i] 之间 最小距离」的 和 。
例如，distance("ab", "cd") == 4 ，且 distance("a", "z") == 1 。

你可以对字符串 s 执行 任意次 操作。在每次操作中，可以将 s 中的一个字母 改变 为 任意 其他小写英文字母。

返回一个字符串，表示在执行一些操作后你可以得到的 字典序最小 的字符串 t ，且满足 distance(s, t) <= k 。



示例 1：

输入：s = "zbbz", k = 3
输出："aaaz"
解释：在这个例子中，可以执行以下操作：
将 s[0] 改为 'a' ，s 变为 "abbz" 。
将 s[1] 改为 'a' ，s 变为 "aabz" 。
将 s[2] 改为 'a' ，s 变为 "aaaz" 。
"zbbz" 和 "aaaz" 之间的距离等于 k = 3 。
可以证明 "aaaz" 是在任意次操作后能够得到的字典序最小的字符串。
因此，答案是 "aaaz" 。
示例 2：

输入：s = "xaxcd", k = 4
输出："aawcd"
解释：在这个例子中，可以执行以下操作：
将 s[0] 改为 'a' ，s 变为 "aaxcd" 。
将 s[2] 改为 'w' ，s 变为 "aawcd" 。
"xaxcd" 和 "aawcd" 之间的距离等于 k = 4 。
可以证明 "aawcd" 是在任意次操作后能够得到的字典序最小的字符串。
因此，答案是 "aawcd" 。
示例 3：

输入：s = "lol", k = 0
输出："lol"
解释：在这个例子中，k = 0，更改任何字符都会使得距离大于 0 。
因此，答案是 "lol" 。


提示：

1 <= s.length <= 100
0 <= k <= 2000
s 只包含小写英文字母。
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    string getSmallestString(string s, int k) {
		int size = s.size();
		string t(size, 0);

		for (int i = 0; i < size; ++i) {
			if (k == 0) {  // 没有可变距离时，只能选择原字符
				t[i] = s[i];
			}
			else {
				int dist = min('z' - s[i] + 1, s[i] - 'a');
				if (dist <= k) {  // 如果距离还够变为a，则优先变为a
					t[i] = 'a';
					k -= dist;
				}
				else {  // 否则尽可能变为更小的字符
					t[i] = s[i] - k;
					k = 0;
				}
			}
		}

		return t;
    }
};

int main()
{
	Solution o;
	CheckResult check;

	check.checkString("aaaz", o.getSmallestString("zbbz", 3));
	check.checkString("aawcd", o.getSmallestString("xaxcd", 4));
	check.checkString("lol", o.getSmallestString("lol", 0));
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
