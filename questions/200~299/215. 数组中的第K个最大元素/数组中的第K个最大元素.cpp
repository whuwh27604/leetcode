/* 数组中的第K个最大元素.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
在未排序的数组中找到第 k 个最大的元素。请注意，你需要找的是数组排序后的第 k 个最大的元素，而不是第 k 个不同的元素。

示例 1:

输入: [3,2,1,5,6,4] 和 k = 2
输出: 5
示例 2:

输入: [3,2,3,1,2,4,5,5,6] 和 k = 4
输出: 4
说明:

你可以假设 k 总是有效的，且 1 ≤ k ≤ 数组的长度。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/kth-largest-element-in-an-array
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <set>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        multiset<int> kNums;

        for (int number : nums) {
            kNums.insert(number);
            if ((int)kNums.size() > k) {
                kNums.erase(kNums.begin());
            }
        }

        return *kNums.begin();
    }
};

int main()
{
    Solution o;
    CheckResult check;

    vector<int> nums = { 5 };
    check.checkInt(5, o.findKthLargest(nums, 1));

    nums = { 5,8 };
    check.checkInt(8, o.findKthLargest(nums, 1));

    nums = { 5,8 };
    check.checkInt(5, o.findKthLargest(nums, 2));

    nums = { 5,5 };
    check.checkInt(5, o.findKthLargest(nums, 1));

    nums = { 5,5 };
    check.checkInt(5, o.findKthLargest(nums, 2));

    nums = { 5,6,8 };
    check.checkInt(8, o.findKthLargest(nums, 1));

    nums = { 5,6,8 };
    check.checkInt(6, o.findKthLargest(nums, 2));

    nums = { 5,6,8 };
    check.checkInt(5, o.findKthLargest(nums, 3));

    nums = { 5,5,8 };
    check.checkInt(8, o.findKthLargest(nums, 1));

    nums = { 5,5,8 };
    check.checkInt(5, o.findKthLargest(nums, 2));

    nums = { 5,5,8 };
    check.checkInt(5, o.findKthLargest(nums, 3));

    nums = { 5,8,8 };
    check.checkInt(8, o.findKthLargest(nums, 1));

    nums = { 5,8,8 };
    check.checkInt(8, o.findKthLargest(nums, 2));

    nums = { 5,8,8 };
    check.checkInt(5, o.findKthLargest(nums, 3));

    nums = { 3,2,1,5,6,4 };
    check.checkInt(5, o.findKthLargest(nums, 2));

    nums = { 3,2,3,1,2,4,5,5,6 };
    check.checkInt(4, o.findKthLargest(nums, 4));

    nums = { 3,2,3,1,2,4,5,5,6 };
    check.checkInt(6, o.findKthLargest(nums, 1));

    nums = { 3,2,3,1,2,4,5,5,6 };
    check.checkInt(5, o.findKthLargest(nums, 2));

    nums = { 3,2,3,1,2,4,5,5,6 };
    check.checkInt(5, o.findKthLargest(nums, 3));

    nums = { 3,2,3,1,2,4,5,5,6 };
    check.checkInt(3, o.findKthLargest(nums, 5));

    nums = { 3,2,3,1,2,4,5,5,6 };
    check.checkInt(3, o.findKthLargest(nums, 6));

    nums = { 3,2,3,1,2,4,5,5,6 };
    check.checkInt(2, o.findKthLargest(nums, 7));

    nums = { 3,2,3,1,2,4,5,5,6 };
    check.checkInt(2, o.findKthLargest(nums, 8));

    nums = { 3,2,3,1,2,4,5,5,6 };
    check.checkInt(1, o.findKthLargest(nums, 9));
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
