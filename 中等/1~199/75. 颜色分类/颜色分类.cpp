/* 颜色分类.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给定一个包含红色、白色和蓝色，一共 n 个元素的数组，原地对它们进行排序，使得相同颜色的元素相邻，并按照红色、白色、蓝色顺序排列。

此题中，我们使用整数 0、 1 和 2 分别表示红色、白色和蓝色。

注意:
不能使用代码库中的排序函数来解决这道题。

示例:

输入: [2,0,2,1,1,0]
输出: [0,0,1,1,2,2]
进阶：

一个直观的解决方案是使用计数排序的两趟扫描算法。
首先，迭代计算出0、1 和 2 元素的个数，然后按照0、1、2的排序，重写当前数组。
你能想出一个仅使用常数空间的一趟扫描算法吗？

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/sort-colors
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int len = nums.size(), current, redIndex = 0, blueIndex = len - 1;
        
        while ((redIndex < len) && (nums[redIndex] == 0)) {
            redIndex++;
        }

        while ((blueIndex >= 0) && (nums[blueIndex] == 2)) {
            blueIndex--;
        }
        
        for (current = redIndex; current < len; current++) {
            if (current > blueIndex) {
                break;
            }

            if (nums[current] == 2) {
                swap(nums[current], nums[blueIndex]);
                while ((blueIndex >= 0) && (nums[blueIndex] == 2)) {
                    blueIndex--;
                }

                if (nums[current] == 0) {
                    swap(nums[current], nums[redIndex++]);
                }
            }
            else if (nums[current] == 0) {
                swap(nums[current], nums[redIndex++]);
            }
        }
    }
};

int main()
{
    Solution o;
    CheckResult check;

    vector<int> nums = { 2,0,2,1,1,0 };
    o.sortColors(nums);
    vector<int> expected = { 0,0,1,1,2,2 };
    check.checkIntVector(expected, nums);

    nums = { 0,2,0,2,1,1,0,2 };
    o.sortColors(nums);
    expected = { 0,0,0,1,1,2,2,2 };
    check.checkIntVector(expected, nums);

    nums = {  };
    o.sortColors(nums);
    expected = {  };
    check.checkIntVector(expected, nums);

    nums = { 0 };
    o.sortColors(nums);
    expected = { 0 };
    check.checkIntVector(expected, nums);

    nums = { 1 };
    o.sortColors(nums);
    expected = { 1 };
    check.checkIntVector(expected, nums);

    nums = { 2 };
    o.sortColors(nums);
    expected = { 2 };
    check.checkIntVector(expected, nums);

    nums = { 1,0 };
    o.sortColors(nums);
    expected = { 0,1 };
    check.checkIntVector(expected, nums);

    nums = { 1,0,1,0 };
    o.sortColors(nums);
    expected = { 0,0,1,1 };
    check.checkIntVector(expected, nums);

    nums = { 2,0 };
    o.sortColors(nums);
    expected = { 0,2 };
    check.checkIntVector(expected, nums);

    nums = { 2,0,0,2 };
    o.sortColors(nums);
    expected = { 0,0,2,2 };
    check.checkIntVector(expected, nums);

    nums = { 2,1 };
    o.sortColors(nums);
    expected = { 1,2 };
    check.checkIntVector(expected, nums);

    nums = { 2,2,1,1 };
    o.sortColors(nums);
    expected = { 1,1,2,2 };
    check.checkIntVector(expected, nums);

    nums = { 2,1,0 };
    o.sortColors(nums);
    expected = { 0,1,2 };
    check.checkIntVector(expected, nums);

    nums = { 0,1,2,0,1,2 };
    o.sortColors(nums);
    expected = { 0,0,1,1,2,2 };
    check.checkIntVector(expected, nums);

    nums = { 0,1,2,1,2,0,2,0,1 };
    o.sortColors(nums);
    expected = { 0,0,0,1,1,1,2,2,2 };
    check.checkIntVector(expected, nums);

    nums = { 0,2,2,2,0,2,1,1 };
    o.sortColors(nums);
    expected = { 0,0,1,1,2,2,2,2 };
    check.checkIntVector(expected, nums);

    nums = { 0,1,2,0,2,1,1,0,2,1,2,0,2,0,1,2,1,0,0,1,2,1,0,2,0,2,1,2,0,1,1,2,0,2,1,0 };
    o.sortColors(nums);
    expected = { 0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,2,2,2,2,2,2,2,2,2,2,2,2 };
    check.checkIntVector(expected, nums);
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
