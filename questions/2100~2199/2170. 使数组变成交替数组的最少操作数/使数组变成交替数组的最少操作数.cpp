/* 使数组变成交替数组的最少操作数.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你一个下标从 0 开始的数组 nums ，该数组由 n 个正整数组成。

如果满足下述条件，则数组 nums 是一个 交替数组 ：

nums[i - 2] == nums[i] ，其中 2 <= i <= n - 1 。
nums[i - 1] != nums[i] ，其中 1 <= i <= n - 1 。
在一步 操作 中，你可以选择下标 i 并将 nums[i] 更改 为 任一 正整数。

返回使数组变成交替数组的 最少操作数 。

 

示例 1：

输入：nums = [3,1,3,2,4,3]
输出：3
解释：
使数组变成交替数组的方法之一是将该数组转换为 [3,1,3,1,3,1] 。
在这种情况下，操作数为 3 。
可以证明，操作数少于 3 的情况下，无法使数组变成交替数组。
示例 2：

输入：nums = [1,2,2,2,2]
输出：2
解释：
使数组变成交替数组的方法之一是将该数组转换为 [1,2,1,2,1].
在这种情况下，操作数为 2 。
注意，数组不能转换成 [2,2,2,2,2] 。因为在这种情况下，nums[0] == nums[1]，不满足交替数组的条件。
 

提示：

1 <= nums.length <= 105
1 <= nums[i] <= 105

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/minimum-operations-to-make-the-array-alternating
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <unordered_map>
#include <algorithm>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        unordered_map<int, int> evenCounts, oddCounts;
        int size = nums.size(), evenSize = (size + 1) / 2, oddSize = size - evenSize;
        int evenFirstCount = 0, evenSecondCount = 0, oddFirstCount = 0, oddSecondCount = 0;
        vector<int> evenFirst, oddFirst;

        count(nums, evenCounts, oddCounts);
        getFirstSecond(evenCounts, evenFirst, evenFirstCount, evenSecondCount);
        getFirstSecond(oddCounts, oddFirst, oddFirstCount, oddSecondCount);

        if (evenFirst.size() == 1 && oddFirst.size() == 1 && evenFirst[0] == oddFirst[0]) {
            return min((evenSize - evenFirstCount) + (oddSize - oddSecondCount), (evenSize - evenSecondCount) + (oddSize - oddFirstCount));
        }
        else {
            return (evenSize - evenFirstCount) + (oddSize - oddFirstCount);
        }
    }

    void count(vector<int>& nums, unordered_map<int, int>& evenCounts, unordered_map<int, int>& oddCounts) {
        for (int i = 0; i < (int)nums.size(); ++i) {
            ((i & 1) == 0) ? ++evenCounts[nums[i]] : ++oddCounts[nums[i]];
        }
    }

    void getFirstSecond(unordered_map<int, int>& counts, vector<int>& first, int& firstCount, int& secondCount) {
        for (auto& cnt : counts) {
            if (cnt.second > firstCount) {
                first = { cnt.first };
                secondCount = firstCount;
                firstCount = cnt.second;
            }
            else if (cnt.second == firstCount) {
                first.push_back(cnt.first);
                secondCount = firstCount;
            }
            else if (cnt.second > secondCount) {
                secondCount = cnt.second;
            }
        }
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<int> nums = { 3,1,3,2,4,3 };
    check.checkInt(3, o.minimumOperations(nums));

    nums = { 1,2,2,2,2 };
    check.checkInt(2, o.minimumOperations(nums));

    nums = { 11,84,94,79,63,59,95,93,3,23,25,21,31,97,29,83,6,91,81,57,60,92,52,87,40,97,41,4,89,55,46,81,14,22,11,92,2,39,81,85,25,21,88,26,14,11,21,71,83,52,74,77,32,8,56,30,88,54,43,71,60,61,96,25,10,10,9,84,85 };
    check.checkInt(65, o.minimumOperations(nums));

    nums = { 1 };
    check.checkInt(0, o.minimumOperations(nums));

    nums = { 1,2 };
    check.checkInt(0, o.minimumOperations(nums));

    nums = { 1,1 };
    check.checkInt(1, o.minimumOperations(nums));

    nums = { 1,2,3 };
    check.checkInt(1, o.minimumOperations(nums));

    nums = { 1,1,1 };
    check.checkInt(1, o.minimumOperations(nums));

    nums = { 1,1,1,1 };
    check.checkInt(2, o.minimumOperations(nums));

    nums = { 1,2,1,2,1,2,3 };
    check.checkInt(1, o.minimumOperations(nums));

    nums = { 1,2,1,2,1,2,3,4,5,4 };
    check.checkInt(4, o.minimumOperations(nums));
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
