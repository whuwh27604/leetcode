/* 最长连续递增序列.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给定一个未经排序的整数数组，找到最长且连续的的递增序列。

示例 1:

输入: [1,3,5,4,7]
输出: 3
解释: 最长连续递增序列是 [1,3,5], 长度为3。
尽管 [1,3,5,7] 也是升序的子序列, 但它不是连续的，因为5和7在原数组里被4隔开。
示例 2:

输入: [2,2,2,2,2]
输出: 1
解释: 最长连续递增序列是 [2], 长度为1。
注意：数组长度不会超过10000。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/longest-continuous-increasing-subsequence
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <algorithm>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
        if (nums.empty()) {
            return 0;
        }

        int length = 1, maxLength = 0;
        for (unsigned int i = 1; i < nums.size(); i++) {
            if (nums[i] > nums[i - 1]) {
                length++;
                continue;
            }

            maxLength = max(maxLength, length);
            length = 1;
        }

        maxLength = max(maxLength, length);
        return maxLength;
    }
};

int main()
{
    Solution o;
    CheckResult check;

    vector<int> nums = { 1,3,5,4,7 };
    check.checkInt(3, o.findLengthOfLCIS(nums));

    nums = { 2,2,2,2,2 };
    check.checkInt(1, o.findLengthOfLCIS(nums));

    nums = {  };
    check.checkInt(0, o.findLengthOfLCIS(nums));

    nums = { 2 };
    check.checkInt(1, o.findLengthOfLCIS(nums));

    nums = { 5,4,3,2,1 };
    check.checkInt(1, o.findLengthOfLCIS(nums));

    nums = { 1,2,3,4,5 };
    check.checkInt(5, o.findLengthOfLCIS(nums));

    nums = { 3,1,2,3,4,5 };
    check.checkInt(5, o.findLengthOfLCIS(nums));

    nums = { 1,2,1,2,1,2 };
    check.checkInt(2, o.findLengthOfLCIS(nums));
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
