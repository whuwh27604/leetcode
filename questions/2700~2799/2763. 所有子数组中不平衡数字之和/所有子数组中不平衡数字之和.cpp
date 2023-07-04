/* 所有子数组中不平衡数字之和.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
一个长度为 n 下标从 0 开始的整数数组 arr 的 不平衡数字 定义为，在 sarr = sorted(arr) 数组中，满足以下条件的下标数目：

0 <= i < n - 1 ，和
sarr[i+1] - sarr[i] > 1
这里，sorted(arr) 表示将数组 arr 排序后得到的数组。

给你一个下标从 0 开始的整数数组 nums ，请你返回它所有 子数组 的 不平衡数字 之和。

子数组指的是一个数组中连续一段 非空 的元素序列。



示例 1：

输入：nums = [2,3,1,4]
输出：3
解释：总共有 3 个子数组有非 0 不平衡数字：
- 子数组 [3, 1] ，不平衡数字为 1 。
- 子数组 [3, 1, 4] ，不平衡数字为 1 。
- 子数组 [1, 4] ，不平衡数字为 1 。
其他所有子数组的不平衡数字都是 0 ，所以所有子数组的不平衡数字之和为 3 。
示例 2：

输入：nums = [1,3,3,3,5]
输出：8
解释：总共有 7 个子数组有非 0 不平衡数字：
- 子数组 [1, 3] ，不平衡数字为 1 。
- 子数组 [1, 3, 3] ，不平衡数字为 1 。
- 子数组 [1, 3, 3, 3] ，不平衡数字为 1 。
- 子数组 [1, 3, 3, 3, 5] ，不平衡数字为 2 。
- 子数组 [3, 3, 3, 5] ，不平衡数字为 1 。
- 子数组 [3, 3, 5] ，不平衡数字为 1 。
- 子数组 [3, 5] ，不平衡数字为 1 。
其他所有子数组的不平衡数字都是 0 ，所以所有子数组的不平衡数字之和为 8 。


提示：

1 <= nums.length <= 1000
1 <= nums[i] <= nums.length
*/

#include <iostream>
#include <algorithm>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int sumImbalanceNumbers(vector<int>& nums) {
        int size = nums.size();
        vector<int> leftBoundary(size, -1), rightBoundary(size, size);

        getLeftBoundary(size, nums, leftBoundary);
        getRightBoundary(size, nums, rightBoundary);

        return count(size, leftBoundary, rightBoundary);
    }

    void getLeftBoundary(int size, vector<int>& nums, vector<int>& leftBoundary) {
        vector<int> indices(size + 2, -1);

        for (int i = 0; i < size; ++i) {
            int num = nums[i];  // 对每一个num，左边界是它左边第一个num + 1的位置
            leftBoundary[i] = indices[num + 1];
            indices[num] = i;
        }
    }

    void getRightBoundary(int size, vector<int>& nums, vector<int>& rightBoundary) {
        vector<int> indices(size + 2, size);

        for (int i = size - 1; i >= 0; --i) {
            int num = nums[i];  // 对每一个num，右边界是它右边第一个num或者num + 1的位置
            rightBoundary[i] = min(indices[num], indices[num + 1]);
            indices[num] = i;
        }
    }

    int count(int size, vector<int>& leftBoundary, vector<int>& rightBoundary) {
        int imbalanceNumbers = 0;

        for (int i = 0; i < size; ++i) {  // 对子数组排序后的每一个连续数对a、b，如果b - a > 1，那么a、b构成一个imbalanceNumber。统计较小数a对最终结果的贡献
            // 对当前数num，只要是左边不包括num + 1的子数组，右边不包括num和num + 1的子数组，排序后num都会贡献一个a。当右边出现num时，贡献a的是靠后的num，不是当前num
            imbalanceNumbers += (i - leftBoundary[i]) * (rightBoundary[i] - i);
        }

        // 我们考虑的是a的贡献个数，上面的统计包括了部分b，那就是当num是子数组的最大值时。每个子数组都有一个最大值，所以减去所有子数组的个数
        return imbalanceNumbers - (size + 1) * size / 2;
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<int> nums = { 2,3,1,4 };
    check.checkInt(3, o.sumImbalanceNumbers(nums));

    nums = { 1,3,3,3,5 };
    check.checkInt(8, o.sumImbalanceNumbers(nums));
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
