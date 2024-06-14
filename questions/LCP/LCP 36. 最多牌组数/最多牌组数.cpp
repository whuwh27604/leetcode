/* 最多牌组数.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
麻将的游戏规则中，共有两种方式凑成「一组牌」：

顺子：三张牌面数字连续的麻将，例如 [4,5,6]
刻子：三张牌面数字相同的麻将，例如 [10,10,10]
给定若干数字作为麻将牌的数值（记作一维数组 tiles），请返回所给 tiles 最多可组成的牌组数。

注意：凑成牌组时，每张牌仅能使用一次。

示例 1：

输入：tiles = [2,2,2,3,4]

输出：1

解释：最多可以组合出 [2,2,2] 或者 [2,3,4] 其中一组牌。

示例 2：

输入：tiles = [2,2,2,3,4,1,3]

输出：2

解释：最多可以组合出 [1,2,3] 与 [2,3,4] 两组牌。

提示：

1 <= tiles.length <= 10^5
1 <= tiles[i] <= 10^9
*/

#include <iostream>
#include <map>
#include <unordered_map>
#include "../check/CheckResult.h"
#include "../tools/TestData.h"

using namespace std;

class Solution {
public:
	int maxGroupNumber(vector<int>& tiles) {
		memo.clear();
		count.clear();
		countTiles(tiles);

		return getMaxGroup(0, 0, 0);
	}

	int getMaxGroup(int idx, int t1, int t2) {  // 当前在idx位置，idx - 2有t1个、idx - 1有t2个，这种状态下的最大牌组数
		if (idx == count.size()) {
			return 0;
		}

		int state = (idx << 5) | (t1 << 3) | t2;  // t1最大只有2，t2最大只有4
		if (memo.count(state) != 0) {
			return memo[state];
		}

		int& maxGroup = memo[state];
		int t3 = count[idx].second;

		/* 考虑当前数字x：
		   1、如果x-2，x-1，x可以组成3个顺子，那么可以转换成3个刻子，组成的牌组数是等价的
		   2、x和x-2，x-1组合完成后，还可能影响x-1，x，x+1以及x，x+1，x+2，按照1的结论，分别最多只需要考虑2组，所以x最多保留4个就够了 */

		for (int t2left = 0; t2left <= min(t2, 2); ++t2left) {  // 枚举t2保留的个数，最多只需要保留2个
			for (int t3left = 0; t3left <= min(t3, 4); ++t3left) {  // 枚举t3保留的个数，最多只需要保留4个
				int t2usable = t2 - t2left, t3usable = t3 - t3left;
				maxGroup = max(maxGroup, t1 / 3 + t2usable / 3 + t3usable / 3 + getMaxGroup(idx + 1, t2left, t3left));  // 全部组成刻子

				if (idx >= 2 && count[idx - 2].first + 2 == count[idx].first) {  // 可以组成顺子
					int maxT = min({ t1, t2usable, t3usable });
					for (int group = 0; group <= maxT; ++group) {  // 枚举组成顺子的个数
						maxGroup = max(maxGroup, group + (t1 - group) / 3 + (t2usable - group) / 3
							+ (t3usable - group) / 3 + getMaxGroup(idx + 1, t2left, t3left));
					}
				}
			}
		}

		return maxGroup;
	}

	void countTiles(vector<int>& tiles) {
		map<int, int> mp;

		for (int num : tiles) {
			++mp[num];
		}

		for (auto& kv : mp) {
			count.push_back({ kv.first,kv.second });
		}
	}

	vector<pair<int, int>> count;
	unordered_map<int, int> memo;
};

int main()
{
	Solution o;
	CheckResult check;

	vector<int> tiles = { 2,2,2,3,4 };
	check.checkInt(1, o.maxGroupNumber(tiles));

	tiles = { 2,2,2,3,4,1,3 };
	check.checkInt(2, o.maxGroupNumber(tiles));

	tiles = { 1,1,1,2,2,2,3,5,6,6,7,7,7,8,8,9 };
	check.checkInt(5, o.maxGroupNumber(tiles));

	tiles = { 1,2,2,2,3,4,5 };
	check.checkInt(2, o.maxGroupNumber(tiles));

	tiles = { 1,2,2,2,3,3,3 };
	check.checkInt(2, o.maxGroupNumber(tiles));

	tiles = { 1,1,1,1,2,2,3,3 };
	check.checkInt(2, o.maxGroupNumber(tiles));

	tiles = { 1,1,1,1,2,2,3,3,5,5,5,5,5,5,5,5,5,5,6,6,6,6,6,6,6,6,6,7,7,7,7,7,7,7,7,7,7,7,8,8,8,8,8,8,8,8,8,8,8,10,10,10,10,10,10 };
	check.checkInt(17, o.maxGroupNumber(tiles));

	tiles = { 1,1,1,1,2,2 };
	check.checkInt(1, o.maxGroupNumber(tiles));

	tiles = { 1,1,1,1,1,1,1,1,1,1,2,2,2,2 };
	check.checkInt(4, o.maxGroupNumber(tiles));

	tiles = { 1,1,2,2,2,2,2,3,3,3,3,4,4,4,4,4,4,5,5,6,6,6,6,6,7,7,7,7,8,8,8,9,9,10,10,10,10,11,11,11,12 };
	check.checkInt(13, o.maxGroupNumber(tiles));

	tiles = { 1,2,4,6,8,9,10 };
	check.checkInt(1, o.maxGroupNumber(tiles));

	tiles = { 7,7,7,7,7,7,7,7,7,8,8,8,8,8,8,8,8,9,9,9,9,9,9,9,9,9,9,10,10,10,10,10,10,10,10,10,10,10,11,11,11,11,11,12,12,12,12,12,12,13,13,13,13 };
	check.checkInt(17, o.maxGroupNumber(tiles));

	tiles = getIntVector("./testcase1.txt");
	check.checkInt(3005, o.maxGroupNumber(tiles));

	tiles = getIntVector("./testcase2.txt");
	check.checkInt(3131, o.maxGroupNumber(tiles));
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
