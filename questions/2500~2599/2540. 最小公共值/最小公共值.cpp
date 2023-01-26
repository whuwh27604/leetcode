/* 最小公共值.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你两个整数数组 nums1 和 nums2 ，它们已经按非降序排序，请你返回两个数组的 最小公共整数 。如果两个数组 nums1 和 nums2 没有公共整数，请你返回 -1 。

如果一个整数在两个数组中都 至少出现一次 ，那么这个整数是数组 nums1 和 nums2 公共 的。



示例 1：

输入：nums1 = [1,2,3], nums2 = [2,4]
输出：2
解释：两个数组的最小公共元素是 2 ，所以我们返回 2 。
示例 2：

输入：nums1 = [1,2,3,6], nums2 = [2,3,4,5]
输出：2
解释：两个数组中的公共元素是 2 和 3 ，2 是较小值，所以返回 2 。


提示：

1 <= nums1.length, nums2.length <= 105
1 <= nums1[i], nums2[j] <= 109
nums1 和 nums2 都是 非降序 的。
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int getCommon(vector<int>& nums1, vector<int>& nums2) {
        int i = 0, j = 0, size1 = nums1.size(), size2 = nums2.size();

        for (i = 0; i < size1; ++i) {
            for (; j < size2; ++j) {
                if (nums1[i] == nums2[j]) {
                    return nums1[i];
                }
                if (nums1[i] < nums2[j]) {
                    break;
                }
            }
        }

        return -1;
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<int> nums1 = { 1,2,3 };
    vector<int> nums2 = { 2,4 };
    check.checkInt(2, o.getCommon(nums1, nums2));

    nums1 = { 1,2,3,6 };
    nums2 = { 2,3,4,5 };
    check.checkInt(2, o.getCommon(nums1, nums2));

    nums1 = { 2,3,4,5 };
    nums2 = { 1,2,3,6 };
    check.checkInt(2, o.getCommon(nums1, nums2));

    nums1 = { 1 };
    nums2 = { 2 };
    check.checkInt(-1, o.getCommon(nums1, nums2));

    nums1 = { 3,5 };
    nums2 = { 2 };
    check.checkInt(-1, o.getCommon(nums1, nums2));
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
