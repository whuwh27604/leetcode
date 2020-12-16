/* 最长和谐子序列.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
和谐数组是指一个数组里元素的最大值和最小值之间的差别正好是1。

现在，给定一个整数数组，你需要在所有可能的子序列中找到最长的和谐子序列的长度。

示例 1:

输入: [1,3,2,2,5,2,3,7]
输出: 5
原因: 最长的和谐数组是：[3,2,2,2,3].
说明: 输入的数组长度最大不超过20,000.

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/longest-harmonious-subsequence
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <unordered_map>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int findLHS(vector<int>& nums) {
        unordered_map<long long, int> numsCount;
        for (unsigned int i = 0; i < nums.size(); i++) {
            if (numsCount.find(nums[i]) == numsCount.end()) {
                numsCount[nums[i]] = 1;
            }
            else {
                numsCount[nums[i]] += 1;
            }
        }

        int subsequenceLen, maxLen = 0;
        for (auto iter = numsCount.begin(); iter != numsCount.end(); iter++) {
            auto addOneIter = numsCount.find(iter->first + 1);
            if (addOneIter == numsCount.end()) {
                continue;
            }

            subsequenceLen = (iter->second + addOneIter->second);
            if (subsequenceLen > maxLen) {
                maxLen = subsequenceLen;
            }
        }

        return maxLen;
    }
};

int main()
{
    Solution o;
    CheckResult check;

    vector<int> nums = { 1,3,2,2,5,2,3,7 };
    check.checkInt(5, o.findLHS(nums));

    nums = {  };
    check.checkInt(0, o.findLHS(nums));

    nums = { 5 };
    check.checkInt(0, o.findLHS(nums));

    nums = { 5,5,5 };
    check.checkInt(0, o.findLHS(nums));

    nums = { 5,5,5,6,6 };
    check.checkInt(5, o.findLHS(nums));

    nums = { 1,5,1,5,1,5,1,6,6 };
    check.checkInt(5, o.findLHS(nums));

    nums = { 4,5,5,5,6,6 };
    check.checkInt(5, o.findLHS(nums));

    nums = { 4,5,5,5,6,6,6,6 };
    check.checkInt(7, o.findLHS(nums));

    nums = { INT_MAX, INT_MIN };
    check.checkInt(0, o.findLHS(nums));
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
