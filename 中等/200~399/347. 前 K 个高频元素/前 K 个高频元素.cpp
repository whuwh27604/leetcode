/* 前 K 个高频元素.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给定一个非空的整数数组，返回其中出现频率前 k 高的元素。

 

示例 1:

输入: nums = [1,1,1,2,2,3], k = 2
输出: [1,2]
示例 2:

输入: nums = [1], k = 1
输出: [1]
 

提示：

你可以假设给定的 k 总是合理的，且 1 ≤ k ≤ 数组中不相同的元素的个数。
你的算法的时间复杂度必须优于 O(n log n) , n 是数组的大小。
题目数据保证答案唯一，换句话说，数组中前 k 个高频元素的集合是唯一的。
你可以按任意顺序返回答案。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/top-k-frequent-elements
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <map>
#include <unordered_map>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> numberFrequent;
        for (int number : nums) {
            auto iter = numberFrequent.find(number);
            if (iter == numberFrequent.end()) {
                numberFrequent[number] = 1;
            }
            else {
                iter->second++;
            }
        }

        multimap<int, int> frequentNumber;
        for (auto iter = numberFrequent.begin(); iter != numberFrequent.end(); iter++) {
            frequentNumber.insert({ iter->second, iter->first });
            if ((int)frequentNumber.size() > k) {
                frequentNumber.erase(frequentNumber.begin());
            }
        }

        vector<int> topKNumbers;
        for (auto iter = frequentNumber.begin(); iter != frequentNumber.end(); iter++) {
            topKNumbers.push_back(iter->second);
        }

        return topKNumbers;
    }
};

int main()
{
    Solution o;
    CheckResult check;

    vector<int> nums = { 1 };
    vector<int> actual = o.topKFrequent(nums, 1);
    vector<int> expected = { 1 };
    check.checkIntVector(expected, actual);

    nums = { 1,1,1,2,2,3 };
    actual = o.topKFrequent(nums, 1);
    expected = { 1 };
    check.checkIntVector(expected, actual);

    nums = { 1,1,1,2,2,3 };
    actual = o.topKFrequent(nums, 2);
    expected = { 2,1 };
    check.checkIntVector(expected, actual);

    nums = { 1,1,1,2,2,3 };
    actual = o.topKFrequent(nums, 3);
    expected = { 3,2,1 };
    check.checkIntVector(expected, actual);

    nums = { 1,1,1,2,2,3,3,4 };
    actual = o.topKFrequent(nums, 1);
    expected = { 1 };
    check.checkIntVector(expected, actual);

    nums = { 1,1,1,2,2,3,3,4 };
    actual = o.topKFrequent(nums, 3);
    expected = { 2,3,1 };
    check.checkIntVector(expected, actual);

    nums = { 1,1,1,2,2,3,3,4 };
    actual = o.topKFrequent(nums, 4);
    expected = { 4,2,3,1 };
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
