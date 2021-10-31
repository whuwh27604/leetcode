/* 找到数组的中间位置.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你一个下标从 0 开始的整数数组 nums ，请你找到 最左边 的中间位置 middleIndex （也就是所有可能中间位置下标最小的一个）。

中间位置 middleIndex 是满足 nums[0] + nums[1] + ... + nums[middleIndex-1] == nums[middleIndex+1] + nums[middleIndex+2] + ... + nums[nums.length-1] 的数组下标。

如果 middleIndex == 0 ，左边部分的和定义为 0 。类似的，如果 middleIndex == nums.length - 1 ，右边部分的和定义为 0 。

请你返回满足上述条件 最左边 的 middleIndex ，如果不存在这样的中间位置，请你返回 -1 。

 

示例 1：

输入：nums = [2,3,-1,8,4]
输出：3
解释：
下标 3 之前的数字和为：2 + 3 + -1 = 4
下标 3 之后的数字和为：4 = 4
示例 2：

输入：nums = [1,-1,4]
输出：2
解释：
下标 2 之前的数字和为：1 + -1 = 0
下标 2 之后的数字和为：0
示例 3：

输入：nums = [2,5]
输出：-1
解释：
不存在符合要求的 middleIndex 。
示例 4：

输入：nums = [1]
输出：0
解释：
下标 0 之前的数字和为：0
下标 0 之后的数字和为：0
 

提示：

1 <= nums.length <= 100
-1000 <= nums[i] <= 1000
 

注意：本题与主站 724 题相同：https://leetcode-cn.com/problems/find-pivot-index/

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/find-the-middle-index-in-array
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <numeric>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int findMiddleIndex(vector<int>& nums) {
        int i, size = nums.size(), totalSum = accumulate(nums.begin(), nums.end(), 0), leftSum = 0;

        for (i = 0; i < size; ++i) {
            if (leftSum == totalSum - leftSum - nums[i]) {
                return i;
            }

            leftSum += nums[i];
        }

        return -1;
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<int> nums = { 1, 7, 3, 6, 5, 6 };
    check.checkInt(3, o.findMiddleIndex(nums));

    nums = { 2,3,-1,8,4 };
    check.checkInt(3, o.findMiddleIndex(nums));

    nums = { 1,-1,4 };
    check.checkInt(2, o.findMiddleIndex(nums));

    nums = { 2,5 };
    check.checkInt(-1, o.findMiddleIndex(nums));

    nums = { 1 };
    check.checkInt(0, o.findMiddleIndex(nums));

    nums = { 1, 2, 3 };
    check.checkInt(-1, o.findMiddleIndex(nums));

    nums = { 3 };
    check.checkInt(0, o.findMiddleIndex(nums));

    nums = { 1, 2 };
    check.checkInt(-1, o.findMiddleIndex(nums));

    nums = { 0, 2 };
    check.checkInt(1, o.findMiddleIndex(nums));

    nums = { 3, 0 };
    check.checkInt(0, o.findMiddleIndex(nums));

    nums = { 0, 0 };
    check.checkInt(0, o.findMiddleIndex(nums));

    nums = { 0, 0, 0 };
    check.checkInt(0, o.findMiddleIndex(nums));

    nums = { 1, 2, 1 };
    check.checkInt(1, o.findMiddleIndex(nums));

    nums = { 5, 2, 2, -2, 2,3 };
    check.checkInt(1, o.findMiddleIndex(nums));

    nums = { 0, 2, -2 };
    check.checkInt(0, o.findMiddleIndex(nums));

    nums = { -1,-1,-1,0,1,1 };
    check.checkInt(0, o.findMiddleIndex(nums));

    nums = { -1,-1,-1,1,1 };
    check.checkInt(0, o.findMiddleIndex(nums));

    nums = { -1,-1,1,1,1 };
    check.checkInt(4, o.findMiddleIndex(nums));
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
