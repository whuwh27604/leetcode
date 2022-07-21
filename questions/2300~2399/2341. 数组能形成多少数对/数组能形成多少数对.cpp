/* 数组能形成多少数对.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你一个下标从 0 开始的整数数组 nums 。在一步操作中，你可以执行以下步骤：

从 nums 选出 两个 相等的 整数
从 nums 中移除这两个整数，形成一个 数对
请你在 nums 上多次执行此操作直到无法继续执行。

返回一个下标从 0 开始、长度为 2 的整数数组 answer 作为答案，其中 answer[0] 是形成的数对数目，answer[1] 是对 nums 尽可能执行上述操作后剩下的整数数目。

 

示例 1：

输入：nums = [1,3,2,1,3,2,2]
输出：[3,1]
解释：
nums[0] 和 nums[3] 形成一个数对，并从 nums 中移除，nums = [3,2,3,2,2] 。
nums[0] 和 nums[2] 形成一个数对，并从 nums 中移除，nums = [2,2,2] 。
nums[0] 和 nums[1] 形成一个数对，并从 nums 中移除，nums = [2] 。
无法形成更多数对。总共形成 3 个数对，nums 中剩下 1 个数字。
示例 2：

输入：nums = [1,1]
输出：[1,0]
解释：nums[0] 和 nums[1] 形成一个数对，并从 nums 中移除，nums = [] 。
无法形成更多数对。总共形成 1 个数对，nums 中剩下 0 个数字。
示例 3：

输入：nums = [0]
输出：[0,1]
解释：无法形成数对，nums 中剩下 1 个数字。
 

提示：

1 <= nums.length <= 100
0 <= nums[i] <= 100

来源：力扣（LeetCode）
链接：https://leetcode.cn/problems/maximum-number-of-pairs-in-array
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    vector<int> numberOfPairs(vector<int>& nums) {
        int pairs = 0, left = 0;
        vector<bool> exist(101, false);

        for (int num : nums) {
            if (exist[num]) {
                exist[num] = false;
                ++pairs;
                --left;
            }
            else {
                exist[num] = true;
                ++left;
            }
        }

        return { pairs, left };
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<int> nums = { 1,3,2,1,3,2,2 };
    vector<int> actual = o.numberOfPairs(nums);
    vector<int> expected = { 3,1 };
    check.checkIntVector(expected, actual);

    nums = { 1,1 };
    actual = o.numberOfPairs(nums);
    expected = { 1,0 };
    check.checkIntVector(expected, actual);

    nums = { 0 };
    actual = o.numberOfPairs(nums);
    expected = { 0,1 };
    check.checkIntVector(expected, actual);
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
