/* 生成平衡数组的方案数.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你一个整数数组 nums 。你需要选择 恰好 一个下标（下标从 0 开始）并删除对应的元素。请注意剩下元素的下标可能会因为删除操作而发生改变。

比方说，如果 nums = [6,1,7,4,1] ，那么：

选择删除下标 1 ，剩下的数组为 nums = [6,7,4,1] 。
选择删除下标 2 ，剩下的数组为 nums = [6,1,4,1] 。
选择删除下标 4 ，剩下的数组为 nums = [6,1,7,4] 。
如果一个数组满足奇数下标元素的和与偶数下标元素的和相等，该数组就是一个 平衡数组 。

请你返回删除操作后，剩下的数组 nums 是 平衡数组 的 方案数 。

 

示例 1：

输入：nums = [2,1,6,4]
输出：1
解释：
删除下标 0 ：[1,6,4] -> 偶数元素下标为：1 + 4 = 5 。奇数元素下标为：6 。不平衡。
删除下标 1 ：[2,6,4] -> 偶数元素下标为：2 + 4 = 6 。奇数元素下标为：6 。平衡。
删除下标 2 ：[2,1,4] -> 偶数元素下标为：2 + 4 = 6 。奇数元素下标为：1 。不平衡。
删除下标 3 ：[2,1,6] -> 偶数元素下标为：2 + 6 = 8 。奇数元素下标为：1 。不平衡。
只有一种让剩余数组成为平衡数组的方案。
示例 2：

输入：nums = [1,1,1]
输出：3
解释：你可以删除任意元素，剩余数组都是平衡数组。
示例 3：

输入：nums = [1,2,3]
输出：0
解释：不管删除哪个元素，剩下数组都不是平衡数组。
 

提示：

1 <= nums.length <= 105
1 <= nums[i] <= 104

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/ways-to-make-a-fair-array
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int waysToMakeFair(vector<int>& nums) {
        int evenSum = 0, oddSum = 0, eSum = 0, oSum = 0, ways = 0;

        getSum(nums, evenSum, oddSum);

        for (unsigned int i = 0; i < nums.size(); ++i) {
            if ((i & 1) == 0) {
                if (eSum + oddSum - oSum == oSum + evenSum - eSum - nums[i]) {
                    ++ways;
                }

                eSum += nums[i];
            }
            else {
                if (oSum + evenSum - eSum == eSum + oddSum - oSum - nums[i]) {
                    ++ways;
                }

                oSum += nums[i];
            }
        }

        return ways;
    }

    void getSum(vector<int>& nums, int& evenSum, int& oddSum) {
        for (unsigned int i = 0; i < nums.size(); ++i) {
            if ((i & 1) == 0) {
                evenSum += nums[i];
            }
            else {
                oddSum += nums[i];
            }
        }
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<int> nums = { 2,1,6,4 };
    check.checkInt(1, o.waysToMakeFair(nums));

    nums = { 1,1,1 };
    check.checkInt(3, o.waysToMakeFair(nums));

    nums = { 1,2,3 };
    check.checkInt(0, o.waysToMakeFair(nums));

    nums = { 3 };
    check.checkInt(1, o.waysToMakeFair(nums));

    nums = { 3,3 };
    check.checkInt(0, o.waysToMakeFair(nums));

    nums = { 1,2,3,4,5,6,7,8,9,10,9,8,7,6,5,4,3,2,1 };
    check.checkInt(9, o.waysToMakeFair(nums));
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
