/* 在排序数组中查找元素的第一个和最后一个位置.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给定一个按照升序排列的整数数组 nums，和一个目标值 target。找出给定目标值在数组中的开始位置和结束位置。

你的算法时间复杂度必须是 O(log n) 级别。

如果数组中不存在目标值，返回 [-1, -1]。

示例 1:

输入: nums = [5,7,7,8,8,10], target = 8
输出: [3,4]
示例 2:

输入: nums = [5,7,7,8,8,10], target = 6
输出: [-1,-1]

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/find-first-and-last-position-of-element-in-sorted-array
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int len = nums.size();
        if (len == 0) {
            return { -1,-1 };
        }

        int left = binarySearchLess(nums, target, 0, len - 1);
        int right = binarySearchGreater(nums, target, 0, len - 1);

        if ((right - left) <= 1) {
            return { -1,-1 };
        }
        return { left + 1, right - 1 };
    }

    int binarySearchLess(vector<int>& nums, int target, int left, int right) {
        int middle = (left + right) / 2, len = nums.size();
        if (nums[middle] < target) {
            if (middle == len - 1) {
                return len;
            }
            if (nums[middle + 1] >= target) {
                return middle;
            }
            else {
                return binarySearchLess(nums, target, middle + 1, right);
            }
        }
        else {
            if (middle == 0) {
                return -1;
            }
            return binarySearchLess(nums, target, left, middle - 1);
        }
    }

    int binarySearchGreater(vector<int>& nums, int target, int left, int right) {
        int middle = (left + right) / 2, len = nums.size();
        if (nums[middle] > target) {
            if (middle == 0) {
                return -1;
            }
            if (nums[middle - 1] <= target) {
                return middle;
            }
            else {
                return binarySearchGreater(nums, target, left, middle - 1);
            }
        }
        else {
            if (middle == len - 1) {
                return len;
            }
            return binarySearchGreater(nums, target, middle + 1, right);
        }
    }
};

int main()
{
    Solution o;
    CheckResult check;

    vector<int> nums = { 5,7,7,8,8,10 };
    vector<int> actual = o.searchRange(nums, 8);
    vector<int> expected = { 3,4 };
    check.checkIntVector(expected, actual);

    nums = { 5,7,7,8,8,10 };
    actual = o.searchRange(nums, 6);
    expected = { -1,-1 };
    check.checkIntVector(expected, actual);

    nums = {  };
    actual = o.searchRange(nums, 5);
    expected = { -1,-1 };
    check.checkIntVector(expected, actual);

    nums = { 5 };
    actual = o.searchRange(nums, 5);
    expected = { 0,0 };
    check.checkIntVector(expected, actual);

    nums = { 5 };
    actual = o.searchRange(nums, 4);
    expected = { -1,-1 };
    check.checkIntVector(expected, actual);

    nums = { 5 };
    actual = o.searchRange(nums, 6);
    expected = { -1,-1 };
    check.checkIntVector(expected, actual);

    nums = { 5,5 };
    actual = o.searchRange(nums, 5);
    expected = { 0,1 };
    check.checkIntVector(expected, actual);

    nums = { 5,5 };
    actual = o.searchRange(nums, 6);
    expected = { -1,-1 };
    check.checkIntVector(expected, actual);

    nums = { 5,8 };
    actual = o.searchRange(nums, 5);
    expected = { 0,0 };
    check.checkIntVector(expected, actual);

    nums = { 5,8 };
    actual = o.searchRange(nums, 6);
    expected = { -1,-1 };
    check.checkIntVector(expected, actual);

    nums = { 5,8 };
    actual = o.searchRange(nums, 8);
    expected = { 1,1 };
    check.checkIntVector(expected, actual);

    nums = { 1,1,1,2,2,3,3,3,3, };
    actual = o.searchRange(nums, 1);
    expected = { 0,2 };
    check.checkIntVector(expected, actual);

    nums = { 1,1,1,2,2,3,3,3,3, };
    actual = o.searchRange(nums, 2);
    expected = { 3,4 };
    check.checkIntVector(expected, actual);

    nums = { 1,1,1,2,2,3,3,3,3, };
    actual = o.searchRange(nums, 3);
    expected = { 5,8 };
    check.checkIntVector(expected, actual);

    nums = { 1,1,1,1,1,1,1,1,1, };
    actual = o.searchRange(nums, 1);
    expected = { 0,8 };
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
