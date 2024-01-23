/* 最大频率元素计数.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你一个由 正整数 组成的数组 nums 。

返回数组 nums 中所有具有 最大 频率的元素的 总频率 。

元素的 频率 是指该元素在数组中出现的次数。



示例 1：

输入：nums = [1,2,2,3,1,4]
输出：4
解释：元素 1 和 2 的频率为 2 ，是数组中的最大频率。
因此具有最大频率的元素在数组中的数量是 4 。
示例 2：

输入：nums = [1,2,3,4,5]
输出：5
解释：数组中的所有元素的频率都为 1 ，是最大频率。
因此具有最大频率的元素在数组中的数量是 5 。


提示：

1 <= nums.length <= 100
1 <= nums[i] <= 100
*/

#include <iostream>
#include <unordered_map>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
		int maxFreq = 0, count = 0;
		unordered_map<int, int> freqs;

		for (int num : nums) {
			++freqs[num];
		}

		for (auto& kv : freqs) {
			if (kv.second > maxFreq) {
				maxFreq = kv.second;
				count = 1;
			}
			else if (kv.second == maxFreq) {
				++count;
			}
		}

		return maxFreq * count;
    }
};

int main()
{
	Solution o;
	CheckResult check;

	vector<int> nums = { 1,2,2,3,1,4 };
	check.checkInt(4, o.maxFrequencyElements(nums));

	nums = { 1,2,3,4,5 };
	check.checkInt(5, o.maxFrequencyElements(nums));
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
