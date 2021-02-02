/* 将数组分成三个子数组的方案数.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
我们称一个分割整数数组的方案是 好的 ，当它满足：

数组被分成三个 非空 连续子数组，从左至右分别命名为 left ， mid ， right 。
left 中元素和小于等于 mid 中元素和，mid 中元素和小于等于 right 中元素和。
给你一个 非负 整数数组 nums ，请你返回 好的 分割 nums 方案数目。由于答案可能会很大，请你将结果对 109 + 7 取余后返回。

 

示例 1：

输入：nums = [1,1,1]
输出：1
解释：唯一一种好的分割方案是将 nums 分成 [1] [1] [1] 。
示例 2：

输入：nums = [1,2,2,2,5,0]
输出：3
解释：nums 总共有 3 种好的分割方案：
[1] [2] [2,2,5,0]
[1] [2,2] [2,5,0]
[1,2] [2,2] [5,0]
示例 3：

输入：nums = [3,2,1]
输出：0
解释：没有好的分割方案。
 

提示：

3 <= nums.length <= 105
0 <= nums[i] <= 104

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/ways-to-split-array-into-three-subarrays
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int waysToSplit(vector<int>& nums) {
        int size = nums.size(), leftEnd = 0, midEnd = 0, rightStartLast = 0;
        int totalSum = getTotalSum(nums), leftSum = 0, midSum = nums[0], rightSum = totalSum, ways = 0;

        for (leftEnd = 0; leftEnd < size - 2; ++leftEnd) {  // 遍历left到nums[i-3]，因为mid、right不能为空
            leftSum += nums[leftEnd];
            if (leftSum > totalSum / 3) {  // left已经大于总和的1/3，肯定无解了
                break;
            }

            midSum -= nums[leftEnd];  // left增加了一个，所以原来的mid减一个
            if (midEnd == leftEnd) {  // 因为sum有可能是0，导致midEnd和leftEnd重叠，要调整一下
                midSum += nums[++midEnd];
            }

            while (midEnd < size && midSum < leftSum) {  // 然后找第一个mid
                midSum += nums[++midEnd];
            }

            while (rightStartLast + 1 < size && rightSum - nums[rightStartLast] >= totalSum - leftSum - (rightSum - nums[rightStartLast])) {
                rightSum -= nums[rightStartLast++];  // 找最后一个rightStartLast。这里的关键，要理解因为leftSum的变大，rightStartLast一定是往右移动的
            }

            if (rightStartLast > midEnd) {  // 特别注意，在某一个left时，mid、right无解并不意味着整个循环的结束，有可能left再变大，mid、right又有解了。
                ways = (ways + rightStartLast - midEnd) % 1000000007;
            }
        }

        return ways;
    }

    int getTotalSum(vector<int>& nums) {
        int sum = 0;

        for (int num : nums) {
            sum += num;
        }

        return sum;
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<int> nums = { 1,1,1 };
    check.checkInt(1, o.waysToSplit(nums));

    nums = { 1,2,2,2,5,0 };
    check.checkInt(3, o.waysToSplit(nums));

    nums = { 3,2,1 };
    check.checkInt(0, o.waysToSplit(nums));

    nums = { 8892,2631,7212,1188,6580,1690,5950,7425,8787,4361,9849 };
    check.checkInt(10, o.waysToSplit(nums));

    nums = { 8892,2631,7212,1188,6580,1690,5950,7425,8787,4361,9849,4063,9496,9140,9986,1058,2734,6961,8855,2567,7683,4770,40,850,72,2285,9328,6794,8632,9163,3928,6962,6545,6920,926,8885,1570,4454,6876,7447,8264,3123,2980,7276,470,8736,3153,3924,3129,7136,1739,1354,661,1309,6231,9890,58,4623,3555,3100,3437 };
    check.checkInt(227, o.waysToSplit(nums));

    nums = { 97250,3792,102166,104495 };
    check.checkInt(1, o.waysToSplit(nums));

    nums = { 0,0,0 };
    check.checkInt(1, o.waysToSplit(nums));

    nums = { 0,0,0,0 };
    check.checkInt(3, o.waysToSplit(nums));

    nums = { 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 };
    check.checkInt(2556, o.waysToSplit(nums));
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
