/* 元素值大于变化阈值的子数组.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你一个整数数组 nums 和一个整数 threshold 。

找到长度为 k 的 nums 子数组，满足数组中 每个 元素都 大于 threshold / k 。

请你返回满足要求的 任意 子数组的 大小 。如果没有这样的子数组，返回 -1 。

子数组 是数组中一段连续非空的元素序列。

 

示例 1：

输入：nums = [1,3,4,3,1], threshold = 6
输出：3
解释：子数组 [3,4,3] 大小为 3 ，每个元素都大于 6 / 3 = 2 。
注意这是唯一合法的子数组。
示例 2：

输入：nums = [6,5,6,5,8], threshold = 7
输出：1
解释：子数组 [8] 大小为 1 ，且 8 > 7 / 1 = 7 。所以返回 1 。
注意子数组 [6,5] 大小为 2 ，每个元素都大于 7 / 2 = 3.5 。
类似的，子数组 [6,5,6] ，[6,5,6,5] ，[6,5,6,5,8] 都是符合条件的子数组。
所以返回 2, 3, 4 和 5 都可以。
 

提示：

1 <= nums.length <= 105
1 <= nums[i], threshold <= 109

来源：力扣（LeetCode）
链接：https://leetcode.cn/problems/subarray-with-elements-greater-than-varying-threshold
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <stack>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int validSubarraySize(vector<int>& nums, int threshold) {
        int size = nums.size();
        vector<int> leftLess(size), rightLess(size);

        getLeftLess(nums, size, leftLess);
        getRightLess(nums, size, rightLess);

        return getSubarraySize(nums, size, threshold, leftLess, rightLess);
    }

    void getLeftLess(vector<int>& nums, int size, vector<int>& leftLess) {
        stack<int> increasing;

        for (int i = 0; i < size; ++i) {
            while (!increasing.empty() && nums[i] <= nums[increasing.top()]) {
                increasing.pop();
            }

            leftLess[i] = increasing.empty() ? -1 : increasing.top();
            increasing.push(i);
        }
    }

    void getRightLess(vector<int>& nums, int size, vector<int>& rightLess) {
        stack<int> increasing;

        for (int i = size - 1; i >= 0; --i) {
            while (!increasing.empty() && nums[i] <= nums[increasing.top()]) {
                increasing.pop();
            }

            rightLess[i] = increasing.empty() ? size : increasing.top();
            increasing.push(i);
        }
    }

    int getSubarraySize(vector<int>& nums, int size, int threshold, vector<int>& leftLess, vector<int>& rightLess) {
        for (int i = 0; i < size; ++i) {
            int len = rightLess[i] - leftLess[i] - 1;

            if (nums[i] > threshold / len) {
                return len;
            }
        }

        return -1;
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<int> nums = { 1,3,4,3,1 };
    check.checkInt(3, o.validSubarraySize(nums, 6));

    nums = { 6,5,6,5,8 };
    check.checkInt(5, o.validSubarraySize(nums, 7));

    nums = { 5,6,7,8,9 };
    check.checkInt(5, o.validSubarraySize(nums, 24));

    nums = { 818,232,595,418,608,229,37,330,876,774,931,939,479,884,354,328 };
    check.checkInt(-1, o.validSubarraySize(nums, 3790));
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
