/* 数字游戏.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
小扣在秋日市集入口处发现了一个数字游戏。主办方共有 N 个计数器，计数器编号为 0 ~ N-1。每个计数器上分别显示了一个数字，小扣按计数器编号升序将所显示的数字记于数组 nums。每个计数器上有两个按钮，分别可以实现将显示数字加一或减一。小扣每一次操作可以选择一个计数器，按下加一或减一按钮。

主办方请小扣回答出一个长度为 N 的数组，第 i 个元素(0 <= i < N)表示将 0~i 号计数器 初始 所示数字操作成满足所有条件 nums[a]+1 == nums[a+1],(0 <= a < i) 的最小操作数。回答正确方可进入秋日市集。

由于答案可能很大，请将每个最小操作数对 1,000,000,007 取余。

示例 1：

输入：nums = [3,4,5,1,6,7]

输出：[0,0,0,5,6,7]

解释： i = 0，[3] 无需操作 i = 1，[3,4] 无需操作； i = 2，[3,4,5] 无需操作； i = 3，将 [3,4,5,1] 操作成 [3,4,5,6], 最少 5 次操作； i = 4，将 [3,4,5,1,6] 操作成 [3,4,5,6,7], 最少 6 次操作； i = 5，将 [3,4,5,1,6,7] 操作成 [3,4,5,6,7,8]，最少 7 次操作； 返回 [0,0,0,5,6,7]。

示例 2：

输入：nums = [1,2,3,4,5]

输出：[0,0,0,0,0]

解释：对于任意计数器编号 i 都无需操作。

示例 3：

输入：nums = [1,1,1,2,3,4]

输出：[0,1,2,3,3,3]

解释： i = 0，无需操作； i = 1，将 [1,1] 操作成 [1,2] 或 [0,1] 最少 1 次操作； i = 2，将 [1,1,1] 操作成 [1,2,3] 或 [0,1,2]，最少 2 次操作； i = 3，将 [1,1,1,2] 操作成 [1,2,3,4] 或 [0,1,2,3]，最少 3 次操作； i = 4，将 [1,1,1,2,3] 操作成 [-1,0,1,2,3]，最少 3 次操作； i = 5，将 [1,1,1,2,3,4] 操作成 [-1,0,1,2,3,4]，最少 3 次操作； 返回 [0,1,2,3,3,3]。

提示：

1 <= nums.length <= 10^5
1 <= nums[i] <= 10^3
*/

#include <iostream>
#include <map>
#include "../check/CheckResult.h"

using namespace std;

class Map {
public:
	map<int, int> count;
	long long sum;
	int size;

	Map() : sum(0), size(0) {}

	void insert(int num) {
		sum += num;
		++size;
		++count[num];
	}

	void erase(int num) {
		sum -= num;
		--size;
		if (--count[num] == 0) {
			count.erase(num);
		}
	}
};

class PairMap {
public:
	Map map1;
	Map map2;

	PairMap() {
		map1.count[INT_MIN] = 1;
		map2.count[INT_MAX] = 1;
	}

	void insert(int num) {
		if (num < map2.count.begin()->first) {
			map1.insert(num);
		}
		else {
			map2.insert(num);
		}

		// 始终保持map1.size == map2.size || map1.size + 1 == map2.size，这样map2的第一个数就是中位数
		if (map1.size + 2 == map2.size) {  // map2比map1多2个数了，把map2的第一个数据挪到map1
			num = map2.count.begin()->first;
			map1.insert(num);
			map2.erase(num);
		}
		else if (map1.size - 1 == map2.size) {  // map1比map2多了，把map1的最后一个数据挪到map2
			num = map1.count.rbegin()->first;
			map2.insert(num);
			map1.erase(num);
		}
	}

	int getOperations() {
		long long median = map2.count.begin()->first;

		return (int)((median * map1.size - map1.sum + map2.sum - median * map2.size) % 1000000007);
	}
};

class Solution {
public:
	vector<int> numsGame(vector<int>& nums) {
		/* 对nums[i] = Ai来说，假设目标是A0 = x，则需要|A0 - X| + |A1 - (X + 1)| + ... + |Ai - (X + i)|最小
		*  即|A0 - X| + |(A1 - 1) - X| + ... + |(Ai - i) - X|最小
		*  那么就是要求[A0, A1 - 1, ... Ai - i]的中位数
		*/
		PairMap pmap;
		int size = nums.size();
		vector<int> ans(size);

		for (int i = 0; i < size; ++i) {
			pmap.insert(nums[i] - i);
			ans[i] = pmap.getOperations();
		}

		return ans;
	}
};

int main()
{
	Solution o;
	CheckResult check;

	vector<int> nums = { 3,4,5,1,6,7 };
	vector<int> actual = o.numsGame(nums);
	vector<int> expected = { 0,0,0,5,6,7 };
	check.checkIntVector(expected, actual);

	nums = { 1,2,3,4,5 };
	actual = o.numsGame(nums);
	expected = { 0,0,0,0,0 };
	check.checkIntVector(expected, actual);

	nums = { 1,1,1,2,3,4 };
	actual = o.numsGame(nums);
	expected = { 0,1,2,3,3,3 };
	check.checkIntVector(expected, actual);
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
