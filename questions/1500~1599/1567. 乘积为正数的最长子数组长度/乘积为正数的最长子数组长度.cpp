/* 乘积为正数的最长子数组长度.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你一个整数数组 nums ，请你求出乘积为正数的最长子数组的长度。

一个数组的子数组是由原数组中零个或者更多个连续数字组成的数组。

请你返回乘积为正数的最长子数组长度。

 

示例  1：

输入：nums = [1,-2,-3,4]
输出：4
解释：数组本身乘积就是正数，值为 24 。
示例 2：

输入：nums = [0,1,-2,-3,-4]
输出：3
解释：最长乘积为正数的子数组为 [1,-2,-3] ，乘积为 6 。
注意，我们不能把 0 也包括到子数组中，因为这样乘积为 0 ，不是正数。
示例 3：

输入：nums = [-1,-2,-3,0,1]
输出：2
解释：乘积为正数的最长子数组是 [-1,-2] 或者 [-2,-3] 。
示例 4：

输入：nums = [-1,2]
输出：1
示例 5：

输入：nums = [1,2,3,5,-6,4,0,10]
输出：4
 

提示：

1 <= nums.length <= 10^5
-10^9 <= nums[i] <= 10^9

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/maximum-length-of-subarray-with-positive-product
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <algorithm>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int getMaxLen(vector<int>& nums) {
        int firstNegativeLeft = -1, negatives = 0, len = 0, segmentLen = 0, maxLen = 0;
        nums.push_back(0);

        for (int num : nums) {
            if (num == 0) {
                if ((negatives & 1) == 0) {
                    maxLen = max(maxLen, len);
                }
                else {
                    maxLen = max({ maxLen, len - firstNegativeLeft - 1, len - segmentLen - 1 });
                }

                firstNegativeLeft = -1;
                negatives = len = segmentLen = 0;
            }
            else if (num < 0) {
                if (firstNegativeLeft == -1) {
                    firstNegativeLeft = segmentLen;
                }

                ++negatives;
                ++len;
                segmentLen = 0;
            }
            else {
                ++len;
                ++segmentLen;
            }
        }

        return maxLen;
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<int> nums = { 1,-2,-3,4 };
    check.checkInt(4, o.getMaxLen(nums));

    nums = { 0,1,-2,-3,-4 };
    check.checkInt(3, o.getMaxLen(nums));

    nums = { -1,-2,-3,0,1 };
    check.checkInt(2, o.getMaxLen(nums));

    nums = { -1,2 };
    check.checkInt(1, o.getMaxLen(nums));

    nums = { 1,2,3,5,-6,4,0,10 };
    check.checkInt(4, o.getMaxLen(nums));

    nums = { 1 };
    check.checkInt(1, o.getMaxLen(nums));

    nums = { -1 };
    check.checkInt(0, o.getMaxLen(nums));
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
