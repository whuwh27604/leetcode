/* 从两个数字数组里生成最小数字.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你两个只包含 1 到 9 之间数字的数组 nums1 和 nums2 ，每个数组中的元素 互不相同 ，请你返回 最小 的数字，两个数组都 至少 包含这个数字的某个数位。


示例 1：

输入：nums1 = [4,1,3], nums2 = [5,7]
输出：15
解释：数字 15 的数位 1 在 nums1 中出现，数位 5 在 nums2 中出现。15 是我们能得到的最小数字。
示例 2：

输入：nums1 = [3,5,2,6], nums2 = [3,1,7]
输出：3
解释：数字 3 的数位 3 在两个数组中都出现了。


提示：

1 <= nums1.length, nums2.length <= 9
1 <= nums1[i], nums2[i] <= 9
每个数组中，元素 互不相同 。
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int minNumber(vector<int>& nums1, vector<int>& nums2) {
        vector<bool> n1(10, false), n2(10, false);
        int num1 = 0, num2 = 0;

        for (int num : nums1) {
            n1[num] = true;
        }

        for (int num : nums2) {
            n2[num] = true;
        }

        for (int num = 1; num < 10; ++num) {
            if (n1[num] && n2[num]) {
                return num;
            }

            if (num1 == 0 && n1[num]) {
                num1 = num;
            }

            if (num2 == 0 && n2[num]) {
                num2 = num;
            }
        }

        return num1 < num2 ? num1 * 10 + num2 : num1 + num2 * 10;
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<int> nums1 = { 4,1,3 };
    vector<int> nums2 = { 5,7 };
    check.checkInt(15, o.minNumber(nums1, nums2));

    nums1 = { 3,5,2,6 };
    nums2 = { 3,1,7 };
    check.checkInt(3, o.minNumber(nums1, nums2));
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
