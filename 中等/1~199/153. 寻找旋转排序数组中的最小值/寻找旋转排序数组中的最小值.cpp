/* 寻找旋转排序数组中的最小值.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
假设按照升序排序的数组在预先未知的某个点上进行了旋转。

( 例如，数组 [0,1,2,4,5,6,7] 可能变为 [4,5,6,7,0,1,2] )。

请找出其中最小的元素。

你可以假设数组中不存在重复元素。

示例 1:

输入: [3,4,5,1,2]
输出: 1
示例 2:

输入: [4,5,6,7,0,1,2]
输出: 0

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/find-minimum-in-rotated-sorted-array
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int findMin(vector<int>& nums) {
        int size = nums.size();
        if (size == 1) {
            return nums[0];
        }

        int index = binarySearch(nums, 0, nums.size() - 1);
        return nums[index];
    }

    int binarySearch(vector<int>& nums, int left, int right) {
        if (left == right) {
            return 0;
        }

        int middle = (left + right) / 2;
        if (nums[middle] > nums[middle + 1]) {
            return middle + 1;
        }

        if (nums[middle] < nums[right]) {
            return binarySearch(nums, left, middle);
        }
        else {
            return binarySearch(nums, middle, right);
        }
    }
};

int main()
{
    Solution o;
    CheckResult check;

    vector<int> nums = { 3,4,5,1,2 };
    check.checkInt(1, o.findMin(nums));

    nums = { 2,3,4,5,1 };
    check.checkInt(1, o.findMin(nums));

    nums = { 1,2,3,4,5 };
    check.checkInt(1, o.findMin(nums));

    nums = { 5,1,2,3,4 };
    check.checkInt(1, o.findMin(nums));

    nums = { 4,5,1,2,3 };
    check.checkInt(1, o.findMin(nums));

    nums = { 0,1,2,4,5,6,7 };
    check.checkInt(0, o.findMin(nums));

    nums = { 7,0,1,2,4,5,6 };
    check.checkInt(0, o.findMin(nums));

    nums = { 6,7,0,1,2,4,5 };
    check.checkInt(0, o.findMin(nums));

    nums = { 5,6,7,0,1,2,4 };
    check.checkInt(0, o.findMin(nums));

    nums = { 4,5,6,7,0,1,2 };
    check.checkInt(0, o.findMin(nums));

    nums = { 2,4,5,6,7,0,1 };
    check.checkInt(0, o.findMin(nums));

    nums = { 1,2,4,5,6,7,0 };
    check.checkInt(0, o.findMin(nums));

    nums = { 5 };
    check.checkInt(5, o.findMin(nums));

    nums = { 5,6 };
    check.checkInt(5, o.findMin(nums));

    nums = { 6,5 };
    check.checkInt(5, o.findMin(nums));

    nums = { 5,6,7 };
    check.checkInt(5, o.findMin(nums));

    nums = { 7,5,6 };
    check.checkInt(5, o.findMin(nums));

    nums = { 6,7,5 };
    check.checkInt(5, o.findMin(nums));

    nums = { 1,2,3,4 };
    check.checkInt(1, o.findMin(nums));

    nums = { 4,1,2,3 };
    check.checkInt(1, o.findMin(nums));

    nums = { 3,4,1,2 };
    check.checkInt(1, o.findMin(nums));

    nums = { 2,3,4,1 };
    check.checkInt(1, o.findMin(nums));
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
