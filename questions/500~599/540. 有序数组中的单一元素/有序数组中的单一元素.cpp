/* 有序数组中的单一元素.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给定一个只包含整数的有序数组，每个元素都会出现两次，唯有一个数只会出现一次，找出这个数。

示例 1:

输入: [1,1,2,3,3,4,4,8,8]
输出: 2
示例 2:

输入: [3,3,7,7,10,11,11]
输出: 10
注意: 您的方案应该在 O(log n)时间复杂度和 O(1)空间复杂度中运行。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/single-element-in-a-sorted-array
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int left = 0, right = nums.size() - 1;

        while (left < right) {
            int middle = (left + right) / 2;
            if (nums[middle] == nums[middle + 1]) {
                if ((right - middle + 1) % 2 == 0) {
                    right = middle - 1;
                }
                else {
                    left = middle + 2;
                }
            }
            else {
                if (nums[middle] != nums[middle - 1]) {
                    return nums[middle];
                }
                else {
                    if ((right - middle) % 2 == 0) {
                        right = middle - 2;
                    }
                    else {
                        left = middle + 1;
                    }
                }
            }
        }

        return nums[left];
    }
};

int main()
{
    Solution o;
    CheckResult check;

    vector<int> nums = { 5 };
    check.checkInt(5, o.singleNonDuplicate(nums));

    nums = { 3,3,5 };
    check.checkInt(5, o.singleNonDuplicate(nums));

    nums = { 3,5,5 };
    check.checkInt(3, o.singleNonDuplicate(nums));

    nums = { -1,0,0,1,1 };
    check.checkInt(-1, o.singleNonDuplicate(nums));

    nums = { -1,-1,0,1,1 };
    check.checkInt(0, o.singleNonDuplicate(nums));

    nums = { -1,-1,0,0,1 };
    check.checkInt(1, o.singleNonDuplicate(nums));

    nums = { 1,1,2,3,3,4,4,8,8 };
    check.checkInt(2, o.singleNonDuplicate(nums));

    nums = { 1,2,2,3,3,4,4,8,8 };
    check.checkInt(1, o.singleNonDuplicate(nums));

    nums = { 1,1,2,2,3,4,4,8,8 };
    check.checkInt(3, o.singleNonDuplicate(nums));

    nums = { 1,1,2,2,3,3,4,8,8 };
    check.checkInt(4, o.singleNonDuplicate(nums));

    nums = { 1,1,2,2,3,3,4,4,8 };
    check.checkInt(8, o.singleNonDuplicate(nums));

    nums = { 3,3,7,7,10,11,11 };
    check.checkInt(10, o.singleNonDuplicate(nums));
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
