/* 寻找峰值.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
峰值元素是指其值大于左右相邻值的元素。

给定一个输入数组 nums，其中 nums[i] ≠ nums[i+1]，找到峰值元素并返回其索引。

数组可能包含多个峰值，在这种情况下，返回任何一个峰值所在位置即可。

你可以假设 nums[-1] = nums[n] = -∞。

示例 1:

输入: nums = [1,2,3,1]
输出: 2
解释: 3 是峰值元素，你的函数应该返回其索引 2。
示例 2:

输入: nums = [1,2,1,3,5,6,4]
输出: 1 或 5
解释: 你的函数可以返回索引 1，其峰值元素为 2；
     或者返回索引 5， 其峰值元素为 6。
说明:

你的解法应该是 O(logN) 时间复杂度的。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/find-peak-element
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        // nums[-1] = nums[n] = -∞的意思是说，升序情况下，最后一个数是峰值；降序情况下，第一个数是峰值。所以可以二分查找。
        return binarySearch(nums, 0, nums.size() - 1);
    }

    int binarySearch(vector<int>& nums, int left, int right) {
        if (left == right) {
            return left;
        }

        int middle = (left + right) / 2;
        if (nums[middle] < nums[middle + 1]) {
            return binarySearch(nums, middle + 1, right);
        }

        return binarySearch(nums, left, middle);
    }
};

int main()
{
    Solution o;
    CheckResult check;

    vector<int> nums = { 0 };
    check.checkInt(0, o.findPeakElement(nums));

    nums = { 5 };
    check.checkInt(0, o.findPeakElement(nums));
    
    nums = { 0,1 };
    check.checkInt(1, o.findPeakElement(nums));

    nums = { 1,0 };
    check.checkInt(0, o.findPeakElement(nums));

    nums = { 5,6,7 };
    check.checkInt(2, o.findPeakElement(nums));

    nums = { 7,6,5 };
    check.checkInt(0, o.findPeakElement(nums));

    nums = { 5,7,5 };
    check.checkInt(1, o.findPeakElement(nums));

    nums = { 6,4,5 };
    check.checkInt(2, o.findPeakElement(nums));

    nums = { 1,2,3,1 };
    check.checkInt(2, o.findPeakElement(nums));

    nums = { 1,3,2,4 };
    check.checkInt(1, o.findPeakElement(nums));

    nums = { 1,2,1,3,5,6,4 };
    check.checkInt(5, o.findPeakElement(nums));
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
