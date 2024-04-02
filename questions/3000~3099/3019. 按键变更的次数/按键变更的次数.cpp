/* 按键变更的次数.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你一个下标从 0 开始的字符串 s ，该字符串由用户输入。按键变更的定义是：使用与上次使用的按键不同的键。例如 s = "ab" 表示按键变更一次，而 s = "bBBb" 不存在按键变更。

返回用户输入过程中按键变更的次数。

注意：shift 或 caps lock 等修饰键不计入按键变更，也就是说，如果用户先输入字母 'a' 然后输入字母 'A' ，不算作按键变更。



示例 1：

输入：s = "aAbBcC"
输出：2
解释：
从 s[0] = 'a' 到 s[1] = 'A'，不存在按键变更，因为不计入 caps lock 或 shift 。
从 s[1] = 'A' 到 s[2] = 'b'，按键变更。
从 s[2] = 'b' 到 s[3] = 'B'，不存在按键变更，因为不计入 caps lock 或 shift 。
从 s[3] = 'B' 到 s[4] = 'c'，按键变更。
从 s[4] = 'c' 到 s[5] = 'C'，不存在按键变更，因为不计入 caps lock 或 shift 。
示例 2：

输入：s = "AaAaAaaA"
输出：0
解释： 不存在按键变更，因为这个过程中只按下字母 'a' 和 'A' ，不需要进行按键变更。


提示：

1 <= s.length <= 100
s 仅由英文大写字母和小写字母组成。
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int countKeyChanges(string s) {
		int changes = 0, size = s.size();

		for (int i = 1; i < size; ++i) {
			int delta = (s[i] < 'a' ? 32 : -32);
			if (s[i] != s[i - 1] && s[i] + delta != s[i - 1]) {
				++changes;
			}
		}

		return changes;
    }
};

int main()
{
	Solution o;
	CheckResult check;

	check.checkInt(2, o.countKeyChanges("aAbBcC"));
	check.checkInt(0, o.countKeyChanges("AaAaAaaA"));
	check.checkInt(0, o.countKeyChanges("z"));
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
