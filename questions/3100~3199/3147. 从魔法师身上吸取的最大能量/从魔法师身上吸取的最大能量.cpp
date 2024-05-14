/* 从魔法师身上吸取的最大能量.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
在神秘的地牢中，n 个魔法师站成一排。每个魔法师都拥有一个属性，这个属性可以给你提供能量。有些魔法师可能会给你负能量，即从你身上吸取能量。

你被施加了一种诅咒，当你从魔法师 i 处吸收能量后，你将被立即传送到魔法师 (i + k) 处。这一过程将重复进行，直到你到达一个不存在 (i + k) 的魔法师为止。

换句话说，你将选择一个起点，然后以 k 为间隔跳跃，直到到达魔法师序列的末端，在过程中吸收所有的能量。

给定一个数组 energy 和一个整数k，返回你能获得的 最大 能量。



示例 1：

输入： energy = [5,2,-10,-5,1], k = 3

输出： 3

解释：可以从魔法师 1 开始，吸收能量 2 + 1 = 3。

示例 2：

输入： energy = [-2,-3,-1], k = 2

输出： -1

解释：可以从魔法师 2 开始，吸收能量 -1。



提示：

1 <= energy.length <= 105
-1000 <= energy[i] <= 1000
1 <= k <= energy.length - 1
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int maximumEnergy(vector<int>& energy, int k) {
		int maxEnergy = INT_MIN, n = (int)energy.size();

		for (int i = n - 1; i >= n - k; --i) {
			int sum = 0;

			for (int j = i; j >= 0; j -= k) {
				sum += energy[j];
				maxEnergy = max(maxEnergy, sum);
			}
		}

		return maxEnergy;
    }
};

int main()
{
	Solution o;
	CheckResult check;

	vector<int> energy = { 5,2,-10,-5,1 };
	check.checkInt(3, o.maximumEnergy(energy, 3));

	energy = { -2,-3,-1 };
	check.checkInt(-1, o.maximumEnergy(energy, 2));
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
