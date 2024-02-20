/* 最长公共前缀的长度.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你两个 正整数 数组 arr1 和 arr2 。

正整数的 前缀 是其 最左边 的一位或多位数字组成的整数。例如，123 是整数 12345 的前缀，而 234 不是 。

设若整数 c 是整数 a 和 b 的 公共前缀 ，那么 c 需要同时是 a 和 b 的前缀。例如，5655359 和 56554 有公共前缀 565 ，而 1223 和 43456 没有 公共前缀。

你需要找出属于 arr1 的整数 x 和属于 arr2 的整数 y 组成的所有数对 (x, y) 之中最长的公共前缀的长度。

返回所有数对之中最长公共前缀的长度。如果它们之间不存在公共前缀，则返回 0 。



示例 1：

输入：arr1 = [1,10,100], arr2 = [1000]
输出：3
解释：存在 3 个数对 (arr1[i], arr2[j]) ：
- (1, 1000) 的最长公共前缀是 1 。
- (10, 1000) 的最长公共前缀是 10 。
- (100, 1000) 的最长公共前缀是 100 。
最长的公共前缀是 100 ，长度为 3 。
示例 2：

输入：arr1 = [1,2,3], arr2 = [4,4,4]
输出：0
解释：任何数对 (arr1[i], arr2[j]) 之中都不存在公共前缀，因此返回 0 。
请注意，同一个数组内元素之间的公共前缀不在考虑范围内。


提示：

1 <= arr1.length, arr2.length <= 5 * 104
1 <= arr1[i], arr2[i] <= 108
*/

#include <iostream>
#include <unordered_set>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
		unordered_set<int> nums;
		int lcp = 0;

		getNums(arr1, nums);

		for (int num : arr2) {
			while (num != 0) {
				if (nums.count(num) != 0) {
					lcp = max(lcp, getLen(num));
					break;
				}

				num /= 10;
			}
		}

		return lcp;
    }

	void getNums(vector<int>& arr, unordered_set<int>& nums) {
		for (int num : arr) {
			while (num != 0) {
				nums.insert(num);
				num /= 10;
			}
		}
	}

	int getLen(int num) {
		int len = 0;

		while (num != 0) {
			num /= 10;
			++len;
		}

		return len;
	}
};

int main()
{
	Solution o;
	CheckResult check;

	vector<int> arr1 = { 1,10,100 };
	vector<int> arr2 = { 1000 };
	check.checkInt(3, o.longestCommonPrefix(arr1, arr2));

	arr1 = { 1,2,3 };
	arr2 = { 4,4,4 };
	check.checkInt(0, o.longestCommonPrefix(arr1, arr2));

	arr1 = { 12 };
	arr2 = { 13 };
	check.checkInt(1, o.longestCommonPrefix(arr1, arr2));
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
