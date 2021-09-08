/* 子数组最小乘积的最大值.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
一个数组的 最小乘积 定义为这个数组中 最小值 乘以 数组的 和 。

比方说，数组 [3,2,5] （最小值是 2）的最小乘积为 2 * (3+2+5) = 2 * 10 = 20 。
给你一个正整数数组 nums ，请你返回 nums 任意 非空子数组 的最小乘积 的 最大值 。由于答案可能很大，请你返回答案对  109 + 7 取余 的结果。

请注意，最小乘积的最大值考虑的是取余操作 之前 的结果。题目保证最小乘积的最大值在 不取余 的情况下可以用 64 位有符号整数 保存。

子数组 定义为一个数组的 连续 部分。

 

示例 1：

输入：nums = [1,2,3,2]
输出：14
解释：最小乘积的最大值由子数组 [2,3,2] （最小值是 2）得到。
2 * (2+3+2) = 2 * 7 = 14 。
示例 2：

输入：nums = [2,3,3,1,2]
输出：18
解释：最小乘积的最大值由子数组 [3,3] （最小值是 3）得到。
3 * (3+3) = 3 * 6 = 18 。
示例 3：

输入：nums = [3,1,5,6,4,2]
输出：60
解释：最小乘积的最大值由子数组 [5,6,4] （最小值是 4）得到。
4 * (5+6+4) = 4 * 15 = 60 。
 

提示：

1 <= nums.length <= 105
1 <= nums[i] <= 107

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/maximum-subarray-min-product
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <algorithm>
#include <stack>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int maxSumMinProduct(vector<int>& nums) {
        int i, size = nums.size();
        long long maxProduct = 0;

        vector<long long> presum(size);
        getPresum(nums, presum);

        vector<int> rightLess(size);
        findRightLess(nums, rightLess);

        vector<int> leftLess(size);
        findLeftLess(nums, leftLess);

        for (i = 0; i < size; ++i) {
            maxProduct = max(maxProduct, nums[i] * (presum[rightLess[i] - 1] - (leftLess[i] == -1 ? 0 : presum[leftLess[i]])));
        }

        return (int)(maxProduct % 1000000007);
    }

    void getPresum(vector<int>& nums, vector<long long>& presum) {
        int i, size = nums.size();
        long long sum = 0;

        for (i = 0; i < size; ++i) {
            sum += nums[i];
            presum[i] = sum;
        }
    }

    void findRightLess(vector<int>& nums, vector<int>& rightLess) {
        int i, size = nums.size();
        stack<int> indices;

        for (i = 0; i < size; ++i) {
            while (!indices.empty() && nums[indices.top()] > nums[i]) {
                rightLess[indices.top()] = i;
                indices.pop();
            }

            indices.push(i);
        }

        while (!indices.empty()) {
            rightLess[indices.top()] = size;
            indices.pop();
        }
    }

    void findLeftLess(vector<int>& nums, vector<int>& leftLess) {
        int i, size = nums.size();
        stack<int> indices;

        for (i = size - 1; i >= 0; --i) {
            while (!indices.empty() && nums[indices.top()] > nums[i]) {
                leftLess[indices.top()] = i;
                indices.pop();
            }

            indices.push(i);
        }

        while (!indices.empty()) {
            leftLess[indices.top()] = -1;
            indices.pop();
        }
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<int> nums = { 1,2,3,2 };
    check.checkInt(14, o.maxSumMinProduct(nums));

    nums = { 2,3,3,1,2 };
    check.checkInt(18, o.maxSumMinProduct(nums));

    nums = { 3,1,5,6,4,2 };
    check.checkInt(60, o.maxSumMinProduct(nums));

    nums = { 1,1,3,2,2,2,1,5,1,5 };
    check.checkInt(25, o.maxSumMinProduct(nums));
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
