/* 字符串的分数.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你一个字符串 s 。一个字符串的 分数 定义为相邻字符 ASCII 码差值绝对值的和。

请你返回 s 的 分数 。



示例 1：

输入：s = "hello"

输出：13

解释：

s 中字符的 ASCII 码分别为：'h' = 104 ，'e' = 101 ，'l' = 108 ，'o' = 111 。所以 s 的分数为 |104 - 101| + |101 - 108| + |108 - 108| + |108 - 111| = 3 + 7 + 0 + 3 = 13 。

示例 2：

输入：s = "zaz"

输出：50

解释：

s 中字符的 ASCII 码分别为：'z' = 122 ，'a' = 97 。所以 s 的分数为 |122 - 97| + |97 - 122| = 25 + 25 = 50 。



提示：

2 <= s.length <= 100
s 只包含小写英文字母。
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int scoreOfString(string s) {
		int score = 0, size = (int)s.size();

		for (int i = 1; i < size; ++i) {
			score += abs(s[i] - s[i - 1]);
		}

		return score;
    }
};

int main()
{
	Solution o;
	CheckResult check;

	check.checkInt(13, o.scoreOfString("hello"));
	check.checkInt(50, o.scoreOfString("zaz"));
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
