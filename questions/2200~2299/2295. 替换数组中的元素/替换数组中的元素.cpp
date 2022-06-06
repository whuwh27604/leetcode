/* 替换数组中的元素.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你一个下标从 0 开始的数组 nums ，它包含 n 个 互不相同 的正整数。请你对这个数组执行 m 个操作，在第 i 个操作中，你需要将数字 operations[i][0] 替换成 operations[i][1] 。

题目保证在第 i 个操作中：

operations[i][0] 在 nums 中存在。
operations[i][1] 在 nums 中不存在。
请你返回执行完所有操作后的数组。

 

示例 1：

输入：nums = [1,2,4,6], operations = [[1,3],[4,7],[6,1]]
输出：[3,2,7,1]
解释：我们对 nums 执行以下操作：
- 将数字 1 替换为 3 。nums 变为 [3,2,4,6] 。
- 将数字 4 替换为 7 。nums 变为 [3,2,7,6] 。
- 将数字 6 替换为 1 。nums 变为 [3,2,7,1] 。
返回最终数组 [3,2,7,1] 。
示例 2：

输入：nums = [1,2], operations = [[1,3],[2,1],[3,2]]
输出：[2,1]
解释：我们对 nums 执行以下操作：
- 将数字 1 替换为 3 。nums 变为 [3,2] 。
- 将数字 2 替换为 1 。nums 变为 [3,1] 。
- 将数字 3 替换为 2 。nums 变为 [2,1] 。
返回最终数组 [2,1] 。
 

提示：

n == nums.length
m == operations.length
1 <= n, m <= 105
nums 中所有数字 互不相同 。
operations[i].length == 2
1 <= nums[i], operations[i][0], operations[i][1] <= 106
在执行第 i 个操作时，operations[i][0] 在 nums 中存在。
在执行第 i 个操作时，operations[i][1] 在 nums 中不存在。

来源：力扣（LeetCode）
链接：https://leetcode.cn/problems/replace-elements-in-an-array
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <unordered_map>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    vector<int> arrayChange(vector<int>& nums, vector<vector<int>>& operations) {
        unordered_map<int, int> numIndices;
        int i, size = nums.size();

        for (i = 0; i < size; ++i) {
            numIndices[nums[i]] = i;
        }

        for (auto& operation : operations) {
            int from = operation[0], to = operation[1], index = numIndices[from];
            nums[index] = to;
            numIndices[to] = index;
        }

        return nums;
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<int> nums = { 1,2,4,6 };
    vector<vector<int>> operations = { {1,3},{4,7},{6,1} };
    vector<int> actual = o.arrayChange(nums, operations);
    vector<int> expected = { 3,2,7,1 };
    check.checkIntVector(expected, actual);

    nums = { 1,2 };
    operations = { {1,3},{2,1},{3,2} };
    actual = o.arrayChange(nums, operations);
    expected = { 2,1 };
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
