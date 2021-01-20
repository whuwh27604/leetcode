/* 将 x 减到 0 的最小操作数.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你一个整数数组 nums 和一个整数 x 。每一次操作时，你应当移除数组 nums 最左边或最右边的元素，然后从 x 中减去该元素的值。请注意，需要 修改 数组以供接下来的操作使用。

如果可以将 x 恰好 减到 0 ，返回 最小操作数 ；否则，返回 -1 。

 

示例 1：

输入：nums = [1,1,4,2,3], x = 5
输出：2
解释：最佳解决方案是移除后两个元素，将 x 减到 0 。
示例 2：

输入：nums = [5,6,7,8,9], x = 4
输出：-1
示例 3：

输入：nums = [3,2,20,1,1,3], x = 10
输出：5
解释：最佳解决方案是移除后三个元素和前两个元素（总共 5 次操作），将 x 减到 0 。
 

提示：

1 <= nums.length <= 105
1 <= nums[i] <= 104
1 <= x <= 109

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/minimum-operations-to-reduce-x-to-zero
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <algorithm>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int left = 0, right, size = nums.size(), maxMiddle = -1, sum = 0, target = getSum(nums) - x;

        if (target < 0) {
            return -1;
        }

        for (right = 0; right < size; ++right) {
            sum += nums[right];

            while (sum > target) {
                sum -= nums[left++];
            }

            if (sum == target) {
                maxMiddle = max(maxMiddle, right - left + 1);
            }
        }

        return maxMiddle == -1 ? -1 : size - maxMiddle;
    }

    int getSum(vector<int>& nums) {
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

    vector<int> nums = { 1,1,4,2,3 };
    check.checkInt(2, o.minOperations(nums, 5));

    nums = { 1,1,4,2,3 };
    check.checkInt(5, o.minOperations(nums, 11));

    nums = { 5,6,7,8,9 };
    check.checkInt(-1, o.minOperations(nums, 4));

    nums = { 3,2,20,1,1,3 };
    check.checkInt(5, o.minOperations(nums, 10));

    nums = { 3 };
    check.checkInt(1, o.minOperations(nums, 3));

    nums = { 3 };
    check.checkInt(-1, o.minOperations(nums, 10));

    nums = { 6016,5483,541,4325,8149,3515,7865,2209,9623,9763,4052,6540,2123,2074,765,7520,4941,5290,5868,6150,6006,6077,2856,7826,9119 };
    check.checkInt(6, o.minOperations(nums, 31841));
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
