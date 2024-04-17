/* 素数的最大距离.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你一个整数数组 nums。

返回两个（不一定不同的）素数在 nums 中 下标 的 最大距离。



示例 1：

输入： nums = [4,2,9,5,3]

输出： 3

解释： nums[1]、nums[3] 和 nums[4] 是素数。因此答案是 |4 - 1| = 3。

示例 2：

输入： nums = [4,8,2,8]

输出： 0

解释： nums[2] 是素数。因为只有一个素数，所以答案是 |2 - 2| = 0。



提示：

1 <= nums.length <= 3 * 105
1 <= nums[i] <= 100
输入保证 nums 中至少有一个素数。
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int maximumPrimeDifference(vector<int>& nums) {
		vector<int> primes = { 2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71,73,79,83,89,97 };
		vector<bool> isPrime(101, false);
		int first = -1, last = -1, size = (int)nums.size();

		for (int prime : primes) {
			isPrime[prime] = true;
		}

		for (int i = 0; i < size; ++i) {
			if (isPrime[nums[i]]) {
				if (first == -1) {
					first = i;
				}
				last = i;
			}
		}

		return last - first;
    }
};

int main()
{
	Solution o;
	CheckResult check;

	vector<int> nums = { 4,2,9,5,3 };
	check.checkInt(3, o.maximumPrimeDifference(nums));

	nums = { 4,8,2,8 };
	check.checkInt(0, o.maximumPrimeDifference(nums));
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
