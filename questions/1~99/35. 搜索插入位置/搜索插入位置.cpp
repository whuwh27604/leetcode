/* 搜索插入位置.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给定一个排序数组和一个目标值，在数组中找到目标值，并返回其索引。如果目标值不存在于数组中，返回它将会被按顺序插入的位置。

你可以假设数组中无重复元素。

示例 1:

输入: [1,3,5,6], 5
输出: 2
示例 2:

输入: [1,3,5,6], 2
输出: 1
示例 3:

输入: [1,3,5,6], 7
输出: 4
示例 4:

输入: [1,3,5,6], 0
输出: 0

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/search-insert-position
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <vector>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        if (nums.size() == 0) {
            return 0;
        }

        int left = 0;
        int right = nums.size() - 1;
        int middle;
        bool find = false;

        if (target <= nums[left]) {
            return 0;
        }

        if (target > nums[right]) {
            return right + 1;
        }

        while (left <= right) {
            middle = (left + right) / 2;
            if (target > nums[middle]) {
                left = middle + 1;
            }
            else if (target == nums[middle]) {
                find = true;
                break;
            }
            else {
                right = middle - 1;
            }
        }

        if (find) {
            return middle;
        }
        return ((target < nums[middle]) ? middle : (middle + 1));
    }
};

int main()
{
    Solution o;
    CheckResult check;

    vector<int> nums = { 1,3,5,6 };
    int target = 0;
    check.checkInt(0, o.searchInsert(nums, target));

    target = 1;
    check.checkInt(0, o.searchInsert(nums, target));

    target = 2;
    check.checkInt(1, o.searchInsert(nums, target));

    target = 3;
    check.checkInt(1, o.searchInsert(nums, target));

    target = 4;
    check.checkInt(2, o.searchInsert(nums, target));

    target = 5;
    check.checkInt(2, o.searchInsert(nums, target));

    target = 6;
    check.checkInt(3, o.searchInsert(nums, target));

    target = 7;
    check.checkInt(4, o.searchInsert(nums, target));

    vector<int> t1Nums = { 1 };
    target = 0;
    check.checkInt(0, o.searchInsert(t1Nums, target));

    target = 1;
    check.checkInt(0, o.searchInsert(t1Nums, target));

    target = 2;
    check.checkInt(1, o.searchInsert(t1Nums, target));

    vector<int> t2Nums = { 1,3 };
    target = 0;
    check.checkInt(0, o.searchInsert(t2Nums, target));

    target = 1;
    check.checkInt(0, o.searchInsert(t2Nums, target));

    target = 2;
    check.checkInt(1, o.searchInsert(t2Nums, target));

    target = 3;
    check.checkInt(1, o.searchInsert(t2Nums, target));

    target = 4;
    check.checkInt(2, o.searchInsert(t2Nums, target));

    vector<int> t3Nums;
    target = 1;
    check.checkInt(0, o.searchInsert(t3Nums, target));
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
