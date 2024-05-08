/* Hello LeetCode!.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
力扣嘉年华同样准备了纪念品展位，参观者只需要集齐 helloleetcode 的 13 张字母卡片即可获得力扣纪念章。

在展位上有一些由字母卡片拼成的单词，words[i][j] 表示第 i 个单词的第 j 个字母。

你可以从这些单词中取出一些卡片，但每次拿取卡片都需要消耗游戏代币，规则如下：

从一个单词中取一个字母所需要的代币数量，为该字母左边和右边字母数量之积

可以从一个单词中多次取字母，每个字母仅可被取一次

例如：从 example 中取出字母 a，需要消耗代币 2*4=8，字母取出后单词变为 exmple； 再从中取出字母 m，需要消耗代币 2*3=6，字母取出后单词变为 exple；

请返回取得 helloleetcode 这些字母需要消耗代币的 最少 数量。如果无法取得，返回 -1。

注意：

取出字母的顺序没有要求
取出的所有字母恰好可以拼成 helloleetcode
示例 1：

输入：words = ["hold","engineer","cost","level"]

输出：5

解释：最优方法为： 从 hold 依次取出 h、o、l、d， 代价均为 0 从 engineer 依次取出第 1 个 e 与最后一个 e， 代价为 0 和 5*1=5 从 cost 取出 c、o、t， 代价均为 0 从 level 依次取出 l、l、e、e， 代价均为 0 所有字母恰好可以拼成 helloleetcode，因此最小的代价为 5

示例 2：

输入：words = ["hello","leetcode"]

输出：0

提示：

n == words.length
m == words[i].length
1 <= n <= 24
1 <= m <= 8
words[i][j] 仅为小写字母
*/

#include <iostream>
#include <algorithm>
#include "../check/CheckResult.h"

using namespace std;

class TargetMask {
public:
	int mask;
	int dec;
	int cnt;
	char c;
};

class Solution {
public:
	int Leetcode(vector<string>& words) {
		vector<int> count(127, 0);
		for (string& word : words) {
			for (char c : word) {
				++count[c];
			}
		}

		for (auto& mask : tMasks) {
			if (count[mask.c] < mask.cnt) {
				return -1;
			}
		}

		init(words);

		return DFS(0, (1 << words[0].size()) - 1, targetMask);
	}

	Solution() {
		n = 0;
		m = 8;
		tMaskSize = 11;
		targetMask = 0b11111011100;
		tMasks = { {0x400,0x400,1,'c'},{0x200,0x200,1,'d'},{0x100,0x100,1,'h'},{0x80,0x80,1,'t'},{0x60,0x20,2,'o'},{0x18,0x8,3,'l'},{0x7,0x1,4,'e'} };
		inf = INT_MAX / 2;
		costs.resize((size_t)1 << m, vector<int>(m, 0));
		getCost();
	}

	void init(vector<string>& words) {
		source = words;
		n = (int)words.size();
		memo.clear();
		memo.resize(n, vector<vector<int>>((size_t)1 << m, vector<int>((size_t)1 << tMaskSize, -1)));
	}

	void getCost() {
		for (int mask = 1; mask < (1 << m); ++mask) {
			int bits = getBits(mask), left = 0;

			for (int i = 0, bit = 1; bit <= mask; ++i, bit <<= 1) {
				if ((mask & bit) != 0) {
					costs[mask][i] = left * (bits - left - 1);
					++left;
				}
			}
		}
	}

	int getBits(int mask) {
		int bits = 0;

		while (mask != 0) {
			mask &= (mask - 1);
			++bits;
		}

		return bits;
	}

	int DFS(int index, int mask, int tarMask) {
		if (tarMask == 0) {
			return 0;
		}

		if (index == n) {
			return inf;
		}

		int& cost = memo[index][mask][tarMask];
		if (cost != -1) {
			return cost;
		}

		cost = DFS(index + 1, index + 1 == n ? 0 : (1 << source[index + 1].size()) - 1, tarMask);

		for (TargetMask& tMask : tMasks) {
			if ((tMask.mask & tarMask) != 0) {
				for (int i = 0, bit = 1; bit <= mask; ++i, bit <<= 1) {
					if ((mask & bit) != 0 && source[index][i] == tMask.c) {
						int nextMask = mask ^ bit, nextTarMask = tarMask - tMask.dec;
						if (nextMask == 0) {
							cost = min(cost, costs[mask][i] + DFS(index + 1, index + 1 == n ? 0 : (1 << source[index + 1].size()) - 1, nextTarMask));
						}
						else {
							cost = min(cost, costs[mask][i] + DFS(index, nextMask, nextTarMask));
						}
					}
				}
			}
		}

		return cost;
	}

	vector<string> source;
	vector<TargetMask> tMasks;
	vector<vector<int>> costs;
	vector<vector<vector<int>>> memo;
	int n;
	int m;
	int targetMask;
	int tMaskSize;
	int inf;
};

int main()
{
	Solution o;
	CheckResult check;

	vector<string> words = { "hold","engineer","cost","level" };
	check.checkInt(5, o.Leetcode(words));

	words = { "hello","leetcode" };
	check.checkInt(0, o.Leetcode(words));

	words = { "hello" };
	check.checkInt(-1, o.Leetcode(words));

	words = { "hold","engineer","cost","level","hold","engineer","cost","level","hold","engineer","cost","level","hold","engineer","cost","level","hold","engineer","cost","level","hold","engineer","cost","level" };
	check.checkInt(0, o.Leetcode(words));

	words = { "aaaaaaaa","bbbbbbbb","cccccccc","dddddddd","eeeeeeee","ffffffff","gggggggg","hhhhhhhh","iiiiiiii","jjjjjjjj","kkkkkkkk","llllllll","mmmmmmmm","nnnnnnnn","oooooooo","pppppppp","qqqqqqqq","rrrrrrrr","ssssssss","tttttttt","uuuuuuuu","vvvvvvvv","wwwwwwww","xxxxxxxx" };
	check.checkInt(0, o.Leetcode(words));
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
