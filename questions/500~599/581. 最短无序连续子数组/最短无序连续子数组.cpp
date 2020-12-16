/* 最短无序连续子数组.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给定一个整数数组，你需要寻找一个连续的子数组，如果对这个子数组进行升序排序，那么整个数组都会变为升序排序。

你找到的子数组应是最短的，请输出它的长度。

示例 1:

输入: [2, 6, 4, 8, 10, 9, 15]
输出: 5
解释: 你只需要对 [6, 4, 8, 10, 9] 进行升序排序，那么整个表都会变为升序排序。
说明 :

输入的数组长度范围在 [1, 10,000]。
输入的数组可能包含重复元素 ，所以升序的意思是<=。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/shortest-unsorted-continuous-subarray
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <algorithm>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        vector<int> sortedNums = nums;
        sort(sortedNums.begin(), sortedNums.end());

        unsigned int i, j;
        for (i = 0; i < nums.size(); i++) {
            if (nums[i] != sortedNums[i]) {
                break;
            }
        }

        for (j = (nums.size() - 1); j > i; j--) {
            if (nums[j] != sortedNums[j]) {
                break;
            }
        }

        return (j - i + 1);
    }
};

int main()
{
    Solution o;
    CheckResult check;

    vector<int> nums = { 2, 6, 4, 8, 10, 9, 15 };
    check.checkInt(5, o.findUnsortedSubarray(nums));

    nums = { 1,2,3,4,5 };
    check.checkInt(0, o.findUnsortedSubarray(nums));

    nums = { 5,4,3,2,1 };
    check.checkInt(5, o.findUnsortedSubarray(nums));

    nums = { 1,1,2,2,3,3 };
    check.checkInt(0, o.findUnsortedSubarray(nums));

    nums = { 3,3,2,2,1,1 };
    check.checkInt(6, o.findUnsortedSubarray(nums));

    nums = { 3 };
    check.checkInt(0, o.findUnsortedSubarray(nums));

    nums = { 3,5 };
    check.checkInt(0, o.findUnsortedSubarray(nums));

    nums = { 5,3 };
    check.checkInt(2, o.findUnsortedSubarray(nums));

    nums = { 1,2,4,3,5,6 };
    check.checkInt(2, o.findUnsortedSubarray(nums));

    nums = { 1,2,3,4,3,5,6 };
    check.checkInt(2, o.findUnsortedSubarray(nums));
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
