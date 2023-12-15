/* 找到两个数组中的公共元素.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你两个下标从 0 开始的整数数组 nums1 和 nums2 ，它们分别含有 n 和 m 个元素。

请你计算以下两个数值：

统计 0 <= i < n 中的下标 i ，满足 nums1[i] 在 nums2 中 至少 出现了一次。
统计 0 <= i < m 中的下标 i ，满足 nums2[i] 在 nums1 中 至少 出现了一次。
请你返回一个长度为 2 的整数数组 answer ，按顺序 分别为以上两个数值。



示例 1：

输入：nums1 = [4,3,2,3,1], nums2 = [2,2,5,2,3,6]
输出：[3,4]
解释：分别计算两个数值：
- nums1 中下标为 1 ，2 和 3 的元素在 nums2 中至少出现了一次，所以第一个值为 3 。
- nums2 中下标为 0 ，1 ，3 和 4 的元素在 nums1 中至少出现了一次，所以第二个值为 4 。
示例 2：

输入：nums1 = [3,4,2,3], nums2 = [1,5]
输出：[0,0]
解释：两个数组中没有公共元素，所以两个值都为 0 。


提示：

n == nums1.length
m == nums2.length
1 <= n, m <= 100
1 <= nums1[i], nums2[i] <= 100
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    vector<int> findIntersectionValues(vector<int>& nums1, vector<int>& nums2) {
        vector<bool> numbers1(101, false), numbers2(101, false);

        getNumbers(nums1, numbers1);
        getNumbers(nums2, numbers2);

        vector<int> ans = { findValues(nums1, numbers2), findValues(nums2, numbers1) };

        return ans;
    }

    void getNumbers(vector<int>& nums, vector<bool>& numbers) {
        for (int num : nums) {
            numbers[num] = true;
        }
    }

    int findValues(vector<int>& nums, vector<bool>& numbers) {
        int count = 0;

        for (int num : nums) {
            if (numbers[num]) {
                ++count;
            }
        }

        return count;
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<int> nums1 = { 4,3,2,3,1 };
    vector<int> nums2 = { 2,2,5,2,3,6 };
    vector<int> actual = o.findIntersectionValues(nums1, nums2);
    vector<int> expected = { 3,4 };
    check.checkIntVector(expected, actual);

    nums1 = { 3,4,2,3 };
    nums2 = { 1,5 };
    actual = o.findIntersectionValues(nums1, nums2);
    expected = { 0,0 };
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
