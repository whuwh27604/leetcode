/* 最少操作使数组递增.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你一个整数数组 nums （下标从 0 开始）。每一次操作中，你可以选择数组中一个元素，并将它增加 1 。

比方说，如果 nums = [1,2,3] ，你可以选择增加 nums[1] 得到 nums = [1,3,3] 。
请你返回使 nums 严格递增 的 最少 操作次数。

我们称数组 nums 是 严格递增的 ，当它满足对于所有的 0 <= i < nums.length - 1 都有 nums[i] < nums[i+1] 。一个长度为 1 的数组是严格递增的一种特殊情况。

 

示例 1：

输入：nums = [1,1,1]
输出：3
解释：你可以进行如下操作：
1) 增加 nums[2] ，数组变为 [1,1,2] 。
2) 增加 nums[1] ，数组变为 [1,2,2] 。
3) 增加 nums[2] ，数组变为 [1,2,3] 。
示例 2：

输入：nums = [1,5,2,4,1]
输出：14
示例 3：

输入：nums = [8]
输出：0
 

提示：

1 <= nums.length <= 5000
1 <= nums[i] <= 104

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/minimum-operations-to-make-the-array-increasing
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int minOperations(vector<int>& nums) {
        int minOpers = 0, next = 0;

        for (int num : nums) {
            if (num < next) {
                minOpers += (next - num);
                next += 1;
            }
            else {
                next = num + 1;
            }
        }

        return minOpers;
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<int> nums = { 1,1,1 };
    check.checkInt(3, o.minOperations(nums));

    nums = { 1,5,2,4,1 };
    check.checkInt(14, o.minOperations(nums));

    nums = { 8 };
    check.checkInt(0, o.minOperations(nums));

    nums = { 1,2,3,100,5,6,7 };
    check.checkInt(288, o.minOperations(nums));
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
