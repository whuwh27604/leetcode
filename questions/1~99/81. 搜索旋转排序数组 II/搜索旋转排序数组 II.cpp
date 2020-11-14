/* 搜索旋转排序数组 II.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
假设按照升序排序的数组在预先未知的某个点上进行了旋转。

( 例如，数组 [0,0,1,2,2,5,6] 可能变为 [2,5,6,0,0,1,2] )。

编写一个函数来判断给定的目标值是否存在于数组中。若存在返回 true，否则返回 false。

示例 1:

输入: nums = [2,5,6,0,0,1,2], target = 0
输出: true
示例 2:

输入: nums = [2,5,6,0,0,1,2], target = 3
输出: false
进阶:

这是 搜索旋转排序数组 的延伸题目，本题中的 nums  可能包含重复元素。
这会影响到程序的时间复杂度吗？会有怎样的影响，为什么？

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/search-in-rotated-sorted-array-ii
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int index = binarySearch(nums, target, 0, nums.size() - 1);
        return (index != -1);
    }

    int binarySearch(vector<int>& nums, int target, int left, int right) {
        if (left > right) {
            return -1;
        }

        int middle = (left + right) / 2;
        if (nums[middle] == target) {
            return middle;
        }

        if ((nums[middle] > nums[left]) || (nums[middle] > nums[right]) ){  // 左边有序
            if ((target >= nums[left]) && (target < nums[middle])) {
                return binarySearch(nums, target, left, middle - 1);
            }
            else {
                return binarySearch(nums, target, middle + 1, right);
            }
        }

        if ((nums[middle] < nums[right]) || (nums[middle] < nums[left])) {  // 右边有序
            if ((target > nums[middle]) && (target <= nums[right])) {
                return binarySearch(nums, target, middle + 1, right);
            }
            else {
                return binarySearch(nums, target, left, middle - 1);
            }
        }

        int i;  // nums[middle] == nums[left] == nums[right]的情况，无法判断哪边有序，只能先线性查找一个不一样的数，最坏情况下可能变为O(n)复杂度
        for (i = left; i <= middle; i++) {
            if (nums[i] != nums[middle]) {
                break;
            }
        }

        if (i < middle) {
            return binarySearch(nums, target, i, middle - 1);
        }
        else {
            return binarySearch(nums, target, middle + 1, right - 1);
        }
    }
};

int main()
{
    Solution o;
    CheckResult check;

    vector<int> nums = {};
    check.checkBool(false, o.search(nums, 1));

    nums = { 1 };
    check.checkBool(true, o.search(nums, 1));

    nums = { 2 };
    check.checkBool(false, o.search(nums, 1));

    nums = { 2,2 };
    check.checkBool(true, o.search(nums, 2));

    nums = { 2,2 };
    check.checkBool(false, o.search(nums, 3));

    nums = { 4,2 };
    check.checkBool(true, o.search(nums, 2));
    check.checkBool(true, o.search(nums, 4));

    nums = { 4,2 };
    check.checkBool(false, o.search(nums, 3));

    nums = { 2,5,6,0,0,1,2 };
    check.checkBool(true, o.search(nums, 0));
    check.checkBool(true, o.search(nums, 2));
    check.checkBool(true, o.search(nums, 5));
    check.checkBool(true, o.search(nums, 6));
    check.checkBool(true, o.search(nums, 1));
    check.checkBool(false, o.search(nums, -1));
    check.checkBool(false, o.search(nums, 3));
    check.checkBool(false, o.search(nums, 4));
    check.checkBool(false, o.search(nums, 7));

    nums = { 2,2,2,2,2,5,2,2 };
    check.checkBool(true, o.search(nums, 2));
    check.checkBool(true, o.search(nums, 5));
    check.checkBool(false, o.search(nums, 1));
    check.checkBool(false, o.search(nums, 3));
    check.checkBool(false, o.search(nums, 4));
    check.checkBool(false, o.search(nums, 6));

    nums = { 2,2,5,2,2,2,2,2 };
    check.checkBool(true, o.search(nums, 2));
    check.checkBool(true, o.search(nums, 5));
    check.checkBool(false, o.search(nums, 1));
    check.checkBool(false, o.search(nums, 3));
    check.checkBool(false, o.search(nums, 4));
    check.checkBool(false, o.search(nums, 6));

    nums = { 5,2,2,2,2,2,2,2 };
    check.checkBool(true, o.search(nums, 2));
    check.checkBool(true, o.search(nums, 5));
    check.checkBool(false, o.search(nums, 1));
    check.checkBool(false, o.search(nums, 3));
    check.checkBool(false, o.search(nums, 4));
    check.checkBool(false, o.search(nums, 6));

    nums = { 2,2,2,2,2,2,5 };
    check.checkBool(true, o.search(nums, 2));
    check.checkBool(true, o.search(nums, 5));
    check.checkBool(false, o.search(nums, 1));
    check.checkBool(false, o.search(nums, 3));
    check.checkBool(false, o.search(nums, 4));
    check.checkBool(false, o.search(nums, 6));

    nums = { 2,4,4,5,5,6,6,7,7,0,0,1,1,2,2 };
    check.checkBool(true, o.search(nums, 2));
    check.checkBool(true, o.search(nums, 0));
    check.checkBool(true, o.search(nums, 7));
    check.checkBool(false, o.search(nums, -1));
    check.checkBool(false, o.search(nums, 3));
    check.checkBool(false, o.search(nums, 8));

    nums = { 2,3,4,5,6,7,8,1,1 };
    check.checkBool(true, o.search(nums, 2));
    check.checkBool(true, o.search(nums, 1));
    check.checkBool(true, o.search(nums, 8));
    check.checkBool(false, o.search(nums, 9));
    check.checkBool(false, o.search(nums, 0));
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
