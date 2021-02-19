/* 按照频率将数组升序排序.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你一个整数数组 nums ，请你将数组按照每个值的频率 升序 排序。如果有多个值的频率相同，请你按照数值本身将它们 降序 排序。 

请你返回排序后的数组。

 

示例 1：

输入：nums = [1,1,2,2,2,3]
输出：[3,1,1,2,2,2]
解释：'3' 频率为 1，'1' 频率为 2，'2' 频率为 3 。
示例 2：

输入：nums = [2,3,1,3,2]
输出：[1,3,3,2,2]
解释：'2' 和 '3' 频率都为 2 ，所以它们之间按照数值本身降序排序。
示例 3：

输入：nums = [-1,1,-6,4,5,-6,1,4,1]
输出：[5,-1,4,4,-6,-6,1,1,1]
 

提示：

1 <= nums.length <= 100
-100 <= nums[i] <= 100

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/sort-array-by-increasing-frequency
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <algorithm>
#include "../check/CheckResult.h"

using namespace std;

bool pairCompare(const pair<int, int>& p1, const pair<int, int>& p2) {
    return p1.first == p2.first ? p1.second > p2.second : p1.first < p2.first;
}

class Solution {
public:
    vector<int> frequencySort(vector<int>& nums) {
        vector<int> numsCount(201, 0);
        countNums(nums, numsCount);

        vector<pair<int, int>> numFrequencyPairs;
        getNumFrequency(numsCount, numFrequencyPairs);

        sort(numFrequencyPairs.begin(), numFrequencyPairs.end(), pairCompare);

        vector<int> sortedNums(nums.size());
        getSortedNums(numFrequencyPairs, sortedNums);

        return sortedNums;
    }

    void countNums(vector<int>& nums, vector<int>& numsCount) {
        for (int num : nums) {
            ++numsCount[num + 100];
        }
    }

    void getNumFrequency(vector<int>& numsCount, vector<pair<int, int>>& numFrequencyPairs) {
        for (int i = 0; i < (int)numsCount.size(); ++i) {
            if (numsCount[i] != 0) {
                numFrequencyPairs.push_back({ numsCount[i], i - 100 });
            }
        }
    }

    void getSortedNums(vector<pair<int, int>>& numFrequencyPairs, vector<int>& sortedNums) {
        int i = 0, j;

        for (auto& numFrequencyPair : numFrequencyPairs) {
            for (j = 0; j < numFrequencyPair.first; ++j) {
                sortedNums[i++] = numFrequencyPair.second;
            }
        }
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<int> nums = { 1,1,2,2,2,3 };
    vector<int> actual = o.frequencySort(nums);
    vector<int> expected = { 3,1,1,2,2,2 };
    check.checkIntVector(expected, actual);

    nums = { 2,3,1,3,2 };
    actual = o.frequencySort(nums);
    expected = { 1,3,3,2,2 };
    check.checkIntVector(expected, actual);

    nums = { -1,1,-6,4,5,-6,1,4,1 };
    actual = o.frequencySort(nums);
    expected = { 5,-1,4,4,-6,-6,1,1,1 };
    check.checkIntVector(expected, actual);

    nums = { 2 };
    actual = o.frequencySort(nums);
    expected = { 2 };
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
