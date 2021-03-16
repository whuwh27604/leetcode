/* 使数组和能被 P 整除.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你一个正整数数组 nums，请你移除 最短 子数组（可以为 空），使得剩余元素的 和 能被 p 整除。 不允许 将整个数组都移除。

请你返回你需要移除的最短子数组的长度，如果无法满足题目要求，返回 -1 。

子数组 定义为原数组中连续的一组元素。

 

示例 1：

输入：nums = [3,1,4,2], p = 6
输出：1
解释：nums 中元素和为 10，不能被 p 整除。我们可以移除子数组 [4] ，剩余元素的和为 6 。
示例 2：

输入：nums = [6,3,5,2], p = 9
输出：2
解释：我们无法移除任何一个元素使得和被 9 整除，最优方案是移除子数组 [5,2] ，剩余元素为 [6,3]，和为 9 。
示例 3：

输入：nums = [1,2,3], p = 3
输出：0
解释：和恰好为 6 ，已经能被 3 整除了。所以我们不需要移除任何元素。
示例  4：

输入：nums = [1,2,3], p = 7
输出：-1
解释：没有任何方案使得移除子数组后剩余元素的和被 7 整除。
示例 5：

输入：nums = [1000000000,1000000000,1000000000], p = 3
输出：0
 

提示：

1 <= nums.length <= 105
1 <= nums[i] <= 109
1 <= p <= 109

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/make-sum-divisible-by-p
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <unordered_map>
#include <algorithm>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {
        int i, size = nums.size(), minLen = size;
        unordered_map<int, int> remainderIndices = { {0,-1} };  // 预置一个余数为0，索引为-1的节点

        int targetRemainder = getSum(nums) % p;  // 整个数组对p的余数是r，那么我们找一个子数组对p的余数也是r，减去这个子数组之后剩下就能被p整除
        if (targetRemainder == 0) {
            return 0;  // 已经可以被p整除，不用删除任何子数组
        }

        long long sum = 0;
        for (i = 0; i < size; ++i) {
            // 当前[0,i]余数是r，假设[0,j]余数是r-targetRemainder，那么(j,i]的余数就是targetRemainder
            sum += nums[i];
            int remainder = sum % p;
            int wanted = (remainder + p - targetRemainder) % p;
            if (remainderIndices.count(wanted) != 0) {
                minLen = min(minLen, i - remainderIndices[wanted]);
            }
            remainderIndices[remainder] = i;
        }

        return minLen == size ? -1 : minLen;  // 如果要把整个数组都删除，应该返回-1
    }

    long long getSum(vector<int>& nums) {
        long long totalSum = 0;

        for (int num : nums) {
            totalSum += num;
        }

        return totalSum;
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<int> nums = { 3,1,4,2 };
    check.checkInt(1, o.minSubarray(nums, 6));

    nums = { 6,3,5,2 };
    check.checkInt(2, o.minSubarray(nums, 9));

    nums = { 1,2,3 };
    check.checkInt(0, o.minSubarray(nums, 3));

    nums = { 1,2,3 };
    check.checkInt(-1, o.minSubarray(nums, 7));

    nums = { 1000000000,1000000000,1000000000 };
    check.checkInt(0, o.minSubarray(nums, 3));

    nums = { 3,6,8,1 };
    check.checkInt(-1, o.minSubarray(nums, 8));

    nums = { 17,3,16,12,3,19,1,8,5,8 };
    check.checkInt(-1, o.minSubarray(nums, 54));

    nums = { 8,32,31,18,34,20,21,13,1,27,23,22,11,15,30,4,2 };
    check.checkInt(7, o.minSubarray(nums, 148));
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
