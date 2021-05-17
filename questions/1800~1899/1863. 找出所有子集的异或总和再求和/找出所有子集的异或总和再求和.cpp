/* 找出所有子集的异或总和再求和.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
一个数组的 异或总和 定义为数组中所有元素按位 XOR 的结果；如果数组为 空 ，则异或总和为 0 。

例如，数组 [2,5,6] 的 异或总和 为 2 XOR 5 XOR 6 = 1 。
给你一个数组 nums ，请你求出 nums 中每个 子集 的 异或总和 ，计算并返回这些值相加之 和 。

注意：在本题中，元素 相同 的不同子集应 多次 计数。

数组 a 是数组 b 的一个 子集 的前提条件是：从 b 删除几个（也可能不删除）元素能够得到 a 。

 

示例 1：

输入：nums = [1,3]
输出：6
解释：[1,3] 共有 4 个子集：
- 空子集的异或总和是 0 。
- [1] 的异或总和为 1 。
- [3] 的异或总和为 3 。
- [1,3] 的异或总和为 1 XOR 3 = 2 。
0 + 1 + 3 + 2 = 6
示例 2：

输入：nums = [5,1,6]
输出：28
解释：[5,1,6] 共有 8 个子集：
- 空子集的异或总和是 0 。
- [5] 的异或总和为 5 。
- [1] 的异或总和为 1 。
- [6] 的异或总和为 6 。
- [5,1] 的异或总和为 5 XOR 1 = 4 。
- [5,6] 的异或总和为 5 XOR 6 = 3 。
- [1,6] 的异或总和为 1 XOR 6 = 7 。
- [5,1,6] 的异或总和为 5 XOR 1 XOR 6 = 2 。
0 + 5 + 1 + 6 + 4 + 3 + 7 + 2 = 28
示例 3：

输入：nums = [3,4,5,6,7,8]
输出：480
解释：每个子集的全部异或总和值之和为 480 。
 

提示：

1 <= nums.length <= 12
1 <= nums[i] <= 20

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/sum-of-all-subset-xor-totals
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int subsetXORSum(vector<int>& nums) {
        int size = (int)pow(2, nums.size()) - 1, totalSum = 0;

        for (int i = 0; i < size; ++i) {
            int selected = i + 1, index = 0, xorSum = 0;

            while (selected != 0) {
                if ((selected & 1) == 1) {
                    xorSum ^= nums[index];
                }

                selected >>= 1;
                ++index;
            }

            totalSum += xorSum;
        }

        return totalSum;
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<int> nums = { 1,3 };
    check.checkInt(6, o.subsetXORSum(nums));

    nums = { 5,1,6 };
    check.checkInt(28, o.subsetXORSum(nums));

    nums = { 3,4,5,6,7,8 };
    check.checkInt(480, o.subsetXORSum(nums));

    nums = { 3 };
    check.checkInt(3, o.subsetXORSum(nums));
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
