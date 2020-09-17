/* 寻找旋转排序数组中的最小值 II.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
假设按照升序排序的数组在预先未知的某个点上进行了旋转。

( 例如，数组 [0,1,2,4,5,6,7] 可能变为 [4,5,6,7,0,1,2] )。

请找出其中最小的元素。

注意数组中可能存在重复的元素。

示例 1：

输入: [1,3,5]
输出: 1
示例 2：

输入: [2,2,2,0,1]
输出: 0
说明：

这道题是 寻找旋转排序数组中的最小值 的延伸题目。
允许重复会影响算法的时间复杂度吗？会如何影响，为什么？

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/find-minimum-in-rotated-sorted-array-ii
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int findMin(vector<int>& nums) {
        int left = 0, right = nums.size() - 1;

        while (left < right) {
            int middle = (right - left) / 2 + left;
            if (nums[middle] < nums[right]) {
                right = middle;
            }
            else if (nums[middle] == nums[right]) {
                right -= 1;
            }
            else {
                left = middle + 1;
            }
        }

        return nums[left];
    }
};

int main()
{
    Solution o;
    CheckResult check;

    vector<int> nums = { 3,4,5,1,2 };
    check.checkInt(1, o.findMin(nums));

    nums = { 2,2,2,0,1 };
    check.checkInt(0, o.findMin(nums));

    nums = { 2,2,2,2,2 };
    check.checkInt(2, o.findMin(nums));

    nums = { 1,2,3,4,5 };
    check.checkInt(1, o.findMin(nums));

    nums = { 2,2,2,0,1,2 };
    check.checkInt(0, o.findMin(nums));

    nums = { 2,3,1,2 };
    check.checkInt(1, o.findMin(nums));

    nums = { 2,2,2,3,4,2,2 };
    check.checkInt(2, o.findMin(nums));

    nums = { 1 };
    check.checkInt(1, o.findMin(nums));

    nums = { 1,2 };
    check.checkInt(1, o.findMin(nums));

    nums = { 2,1 };
    check.checkInt(1, o.findMin(nums));

    nums = { 10,1,10,10,10 };
    check.checkInt(1, o.findMin(nums));

    nums = { 2,2,2,3,1 };
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
