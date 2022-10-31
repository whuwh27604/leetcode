/* 下一个更大元素 IV.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你一个下标从 0 开始的非负整数数组 nums 。对于 nums 中每一个整数，你必须找到对应元素的 第二大 整数。

如果 nums[j] 满足以下条件，那么我们称它为 nums[i] 的 第二大 整数：

j > i
nums[j] > nums[i]
恰好存在 一个 k 满足 i < k < j 且 nums[k] > nums[i] 。
如果不存在 nums[j] ，那么第二大整数为 -1 。

比方说，数组 [1, 2, 4, 3] 中，1 的第二大整数是 4 ，2 的第二大整数是 3 ，3 和 4 的第二大整数是 -1 。
请你返回一个整数数组 answer ，其中 answer[i]是 nums[i] 的第二大整数。

 

示例 1：

输入：nums = [2,4,0,9,6]
输出：[9,6,6,-1,-1]
解释：
下标为 0 处：2 的右边，4 是大于 2 的第一个整数，9 是第二个大于 2 的整数。
下标为 1 处：4 的右边，9 是大于 4 的第一个整数，6 是第二个大于 4 的整数。
下标为 2 处：0 的右边，9 是大于 0 的第一个整数，6 是第二个大于 0 的整数。
下标为 3 处：右边不存在大于 9 的整数，所以第二大整数为 -1 。
下标为 4 处：右边不存在大于 6 的整数，所以第二大整数为 -1 。
所以我们返回 [9,6,6,-1,-1] 。
示例 2：

输入：nums = [3,3]
输出：[-1,-1]
解释：
由于每个数右边都没有更大的数，所以我们返回 [-1,-1] 。
 

提示：

1 <= nums.length <= 105
0 <= nums[i] <= 109

来源：力扣（LeetCode）
链接：https://leetcode.cn/problems/next-greater-element-iv
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    vector<int> secondGreaterElement(vector<int>& nums) {
        int i, size = nums.size();
        vector<int> indices, oneGreaters, twoGreaters(size, -1);

        for (i = 0; i < size; ++i) {
            while (!oneGreaters.empty() && nums[oneGreaters.back()] < nums[i]) {
                twoGreaters[oneGreaters.back()] = nums[i];
                oneGreaters.pop_back();
            }

            int j = (int)indices.size() - 1;
            while (j >= 0 && nums[indices[j]] < nums[i]) {
                --j;
            }

            ++j;
            oneGreaters.insert(oneGreaters.end(), indices.begin() + j, indices.end());
            indices.resize(j);
            indices.push_back(i);
        }

        return twoGreaters;
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<int> nums = { 2,4,0,9,6 };
    vector<int> actual = o.secondGreaterElement(nums);
    vector<int> expected = { 9,6,6,-1,-1 };
    check.checkIntVector(expected, actual);

    nums = { 3,3 };
    actual = o.secondGreaterElement(nums);
    expected = { -1,-1 };
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
