/* 找出满足差值条件的下标 I.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你一个下标从 0 开始、长度为 n 的整数数组 nums ，以及整数 indexDifference 和整数 valueDifference 。

你的任务是从范围 [0, n - 1] 内找出  2 个满足下述所有条件的下标 i 和 j ：

abs(i - j) >= indexDifference 且
abs(nums[i] - nums[j]) >= valueDifference
返回整数数组 answer。如果存在满足题目要求的两个下标，则 answer = [i, j] ；否则，answer = [-1, -1] 。如果存在多组可供选择的下标对，只需要返回其中任意一组即可。

注意：i 和 j 可能 相等 。



示例 1：

输入：nums = [5,1,4,1], indexDifference = 2, valueDifference = 4
输出：[0,3]
解释：在示例中，可以选择 i = 0 和 j = 3 。
abs(0 - 3) >= 2 且 abs(nums[0] - nums[3]) >= 4 。
因此，[0,3] 是一个符合题目要求的答案。
[3,0] 也是符合题目要求的答案。
示例 2：

输入：nums = [2,1], indexDifference = 0, valueDifference = 0
输出：[0,0]
解释：
在示例中，可以选择 i = 0 和 j = 0 。
abs(0 - 0) >= 0 且 abs(nums[0] - nums[0]) >= 0 。
因此，[0,0] 是一个符合题目要求的答案。
[0,1]、[1,0] 和 [1,1] 也是符合题目要求的答案。
示例 3：

输入：nums = [1,2,3], indexDifference = 2, valueDifference = 4
输出：[-1,-1]
解释：在示例中，可以证明无法找出 2 个满足所有条件的下标。
因此，返回 [-1,-1] 。


提示：

1 <= n == nums.length <= 100
0 <= nums[i] <= 50
0 <= indexDifference <= 100
0 <= valueDifference <= 50
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    vector<int> findIndices(vector<int>& nums, int indexDifference, int valueDifference) {
        int size = nums.size();

        for (int i = 0; i < size; ++i) {
            for (int j = i; j < size; ++j) {
                if (abs(i - j) >= indexDifference && abs(nums[i] - nums[j]) >= valueDifference) {
                    return { i,j };
                }
            }
        }

        return { -1,-1 };
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<int> nums = { 5,1,4,1 };
    vector<int> actual = o.findIndices(nums, 2, 4);
    vector<int> expected = { 0,3 };
    check.checkIntVector(expected, actual);

    nums = { 2,1 };
    actual = o.findIndices(nums, 0, 0);
    expected = { 0,0 };
    check.checkIntVector(expected, actual);

    nums = { 1,2,3 };
    actual = o.findIndices(nums, 2, 4);
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
