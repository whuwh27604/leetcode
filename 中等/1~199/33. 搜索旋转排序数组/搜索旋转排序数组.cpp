/* 搜索旋转排序数组.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
假设按照升序排序的数组在预先未知的某个点上进行了旋转。

( 例如，数组 [0,1,2,4,5,6,7] 可能变为 [4,5,6,7,0,1,2] )。

搜索一个给定的目标值，如果数组中存在这个目标值，则返回它的索引，否则返回 -1 。

你可以假设数组中不存在重复的元素。

你的算法时间复杂度必须是 O(log n) 级别。

示例 1:

输入: nums = [4,5,6,7,0,1,2], target = 0
输出: 4
示例 2:

输入: nums = [4,5,6,7,0,1,2], target = 3
输出: -1

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/search-in-rotated-sorted-array
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        return binarySearch(nums, target, 0, nums.size() - 1);
    }

    int binarySearch(vector<int>& nums, int target, int left, int right) {
        if (left > right) {
            return -1;
        }

        int middle = (left + right) / 2;
        if (nums[middle] == target) {
            return middle;
        }

        if (nums[middle] >= nums[left]) {  // 边界上middle可能等于left
            if ((target >= nums[left]) && (target < nums[middle])) {
                return binarySearch(nums, target, left, middle - 1);
            }
            else {
                return binarySearch(nums, target, middle + 1, right);
            }
        }
        else {
            if ((target > nums[middle]) && (target <= nums[right])) {
                return binarySearch(nums, target, middle + 1, right);
            }
            else {
                return binarySearch(nums, target, left, middle - 1);
            }
        }
    }
};

int main()
{
    Solution o;
    CheckResult check;

    vector<int> nums = { 4,5,6,7,0,1,2 };
    check.checkInt(4, o.search(nums, 0));
    check.checkInt(0, o.search(nums, 4));
    check.checkInt(3, o.search(nums, 7));
    check.checkInt(5, o.search(nums, 1));
    check.checkInt(6, o.search(nums, 2));
    check.checkInt(-1, o.search(nums, 8));

    nums = { -3,-2,-1,0,1,2,3 };
    check.checkInt(0, o.search(nums, -3));
    check.checkInt(6, o.search(nums, 3));
    check.checkInt(3, o.search(nums, 0));
    check.checkInt(-1, o.search(nums, 4));

    nums = { 2,3,4,5,6,7,8,1 };
    check.checkInt(0, o.search(nums, 2));
    check.checkInt(5, o.search(nums, 7));
    check.checkInt(6, o.search(nums, 8));
    check.checkInt(7, o.search(nums, 1));
    check.checkInt(-1, o.search(nums, 0));
    check.checkInt(-1, o.search(nums, 9));

    nums = { 9,1,2,3,4,5,6,7,8 };
    check.checkInt(0, o.search(nums, 9));
    check.checkInt(1, o.search(nums, 1));
    check.checkInt(2, o.search(nums, 2));
    check.checkInt(7, o.search(nums, 7));
    check.checkInt(8, o.search(nums, 8));
    check.checkInt(-1, o.search(nums, 0));
    check.checkInt(-1, o.search(nums, 10));

    nums = { 5 };
    check.checkInt(0, o.search(nums, 5));
    check.checkInt(-1, o.search(nums, 4));
    check.checkInt(-1, o.search(nums, 6));

    nums = { 5,6 };
    check.checkInt(0, o.search(nums, 5));
    check.checkInt(1, o.search(nums, 6));
    check.checkInt(-1, o.search(nums, 4));
    check.checkInt(-1, o.search(nums, 7));

    nums = { 6,5 };
    check.checkInt(0, o.search(nums, 6));
    check.checkInt(1, o.search(nums, 5));
    check.checkInt(-1, o.search(nums, 4));
    check.checkInt(-1, o.search(nums, 7));

    nums = { 10,-10,0 };
    check.checkInt(0, o.search(nums, 10));
    check.checkInt(1, o.search(nums, -10));
    check.checkInt(2, o.search(nums, 0));
    check.checkInt(-1, o.search(nums, -11));
    check.checkInt(-1, o.search(nums, 11));

    nums = { 0,10,-10 };
    check.checkInt(0, o.search(nums, 0));
    check.checkInt(1, o.search(nums, 10));
    check.checkInt(2, o.search(nums, -10));
    check.checkInt(-1, o.search(nums, -11));
    check.checkInt(-1, o.search(nums, 11));
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
