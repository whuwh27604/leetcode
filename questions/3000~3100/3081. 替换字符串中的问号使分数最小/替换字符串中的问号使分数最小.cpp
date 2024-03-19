/* 替换字符串中的问号使分数最小.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你一个字符串 s 。s[i] 要么是小写英文字母，要么是问号 '?' 。

对于长度为 m 且 只 含有小写英文字母的字符串 t ，我们定义函数 cost(i) 为下标 i 之前（也就是范围 [0, i - 1] 中）出现过与 t[i] 相同 字符出现的次数。

字符串 t 的 分数 为所有下标 i 的 cost(i) 之 和 。

比方说，字符串 t = "aab" ：

cost(0) = 0
cost(1) = 1
cost(2) = 0
所以，字符串 "aab" 的分数为 0 + 1 + 0 = 1 。
你的任务是用小写英文字母 替换 s 中 所有 问号，使 s 的 分数最小 。

请你返回替换所有问号 '?' 之后且分数最小的字符串。如果有多个字符串的 分数最小 ，那么返回字典序最小的一个。



示例 1：

输入：s = "???"

输出： "abc"

解释：这个例子中，我们将 s 中的问号 '?' 替换得到 "abc" 。

对于字符串 "abc" ，cost(0) = 0 ，cost(1) = 0 和 cost(2) = 0 。

"abc" 的分数为 0 。

其他修改 s 得到分数 0 的字符串为 "cba" ，"abz" 和 "hey" 。

这些字符串中，我们返回字典序最小的。

示例 2：

输入： s = "a?a?"

输出： "abac"

解释：这个例子中，我们将 s 中的问号 '?' 替换得到 "abac" 。

对于字符串 "abac" ，cost(0) = 0 ，cost(1) = 0 ，cost(2) = 1 和 cost(3) = 0 。

"abac" 的分数为 1 。



提示：

1 <= s.length <= 105
s[i] 要么是小写英文字母，要么是 '?' 。
*/

#include <iostream>
#include <queue>
#include "../check/CheckResult.h"

using namespace std;

class Node {
public:
	int count;
	char c;

	Node() : count(0), c(0) {}
	Node(int n, char c_) : count(n), c(c_) {}

	bool operator<(const Node& o) const {
		return count == o.count ? c > o.c : count > o.count;
	}
};

class Solution {
public:
    string minimizeStringValue(string s) {
		priority_queue<Node> nodes;
		int qmarks = 0;
		vector<int> changes(127, 0);

		count(s, nodes, qmarks);
		getChanges(nodes, qmarks, changes);
		
		return change(s, changes);
    }

	void count(string& s, priority_queue<Node>& nodes, int& qmarks) {
		vector<int> letters(127, 0);

		for (char c : s) {
			if (c == '?') {
				++qmarks;
			}
			else {
				++letters[c];
			}
		}

		for (char c = 'a'; c <= 'z'; ++c) {
			nodes.push(Node(letters[c], c));
		}
	}

	void getChanges(priority_queue<Node>& nodes, int qmarks, vector<int>& changes) {
		for (int i = 0; i < qmarks; ++i) {
			Node node = nodes.top();
			nodes.pop();
			++changes[node.c];
			++node.count;
			nodes.push(node);
		}
	}

	string change(string& s, vector<int>& changes) {
		int size = s.size();
		char c = 'a';
		string ans(size, 0);

		for (int i = 0; i < size; ++i) {
			if (s[i] == '?') {
				while (changes[c] == 0) {
					++c;
				}

				ans[i] = c;
				--changes[c];
			}
			else {
				ans[i] = s[i];
			}
		}

		return ans;
	}
};

int main()
{
	Solution o;
	CheckResult check;

	check.checkString("abc", o.minimizeStringValue("???"));
	check.checkString("abac", o.minimizeStringValue("a?a?"));
	check.checkString("aabcdefghijklmnopqrskuvwxyzt", o.minimizeStringValue("aabcdefghijklmnopqrskuvwxyz?"));
	check.checkString("aabcdefghijklmnopqrstuvwxyzb", o.minimizeStringValue("aabcdefghijklmnopqrstuvwxyz?"));
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
