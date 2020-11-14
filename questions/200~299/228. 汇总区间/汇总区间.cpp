/* 汇总区间.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给定一个无重复元素的有序整数数组，返回数组区间范围的汇总。

示例 1:

输入: [0,1,2,4,5,7]
输出: ["0->2","4->5","7"]
解释: 0,1,2 可组成一个连续的区间; 4,5 可组成一个连续的区间。
示例 2:

输入: [0,2,3,4,6,8,9]
输出: ["0","2->4","6","8->9"]
解释: 2,3,4 可组成一个连续的区间; 8,9 可组成一个连续的区间。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/summary-ranges
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> ranges;
        string range;
        int left = 0, right = 1, size = nums.size();
        if (size == 0) {
            return ranges;
        }

        while (right < size) {
            if (nums[right] != (nums[right - 1] + 1)) {
                range = (left == (right - 1)) ? to_string(nums[left]) : (to_string(nums[left]) + "->" + to_string(nums[right - 1]));
                ranges.push_back(range);
                left = right;
            }

            right++;
        }

        range = (left == (right - 1)) ? to_string(nums[left]) : (to_string(nums[left]) + "->" + to_string(nums[right - 1]));
        ranges.push_back(range);

        return ranges;
    }
};

int main()
{
    Solution o;
    CheckResult check;

    vector<int> nums = {};
    vector<string> actual = o.summaryRanges(nums);
    vector<string> expected = {};
    check.checkStringVector(expected, actual);

    nums = { 0 };
    actual = o.summaryRanges(nums);
    expected = { "0" };
    check.checkStringVector(expected, actual);

    nums = { 0,2,3 };
    actual = o.summaryRanges(nums);
    expected = { "0","2->3" };
    check.checkStringVector(expected, actual);

    nums = { -1,0,1,3 };
    actual = o.summaryRanges(nums);
    expected = { "-1->1","3" };
    check.checkStringVector(expected, actual);

    nums = { -3,3 };
    actual = o.summaryRanges(nums);
    expected = { "-3","3" };
    check.checkStringVector(expected, actual);

    nums = { -3,-2,-1,1,2,3 };
    actual = o.summaryRanges(nums);
    expected = { "-3->-1","1->3" };
    check.checkStringVector(expected, actual);

    nums = { 0,1,2,4,5,7 };
    actual = o.summaryRanges(nums);
    expected = { "0->2","4->5","7" };
    check.checkStringVector(expected, actual);

    nums = { -2,0,1,2,4,5 };
    actual = o.summaryRanges(nums);
    expected = { "-2","0->2","4->5" };
    check.checkStringVector(expected, actual);

    nums = { -2,0,1,2,4,5,7 };
    actual = o.summaryRanges(nums);
    expected = { "-2","0->2","4->5","7" };
    check.checkStringVector(expected, actual);

    nums = { 0,2,5,7 };
    actual = o.summaryRanges(nums);
    expected = { "0","2","5","7" };
    check.checkStringVector(expected, actual);

    nums = { 0,1,2,4,5,7,8 };
    actual = o.summaryRanges(nums);
    expected = { "0->2","4->5","7->8" };
    check.checkStringVector(expected, actual);

    nums = { 0,2,3,4,6,8,9 };
    actual = o.summaryRanges(nums);
    expected = { "0","2->4","6","8->9" };
    check.checkStringVector(expected, actual);
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
