/* 矩阵中的和.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你一个下标从 0 开始的二维整数数组 nums 。一开始你的分数为 0 。你需要执行以下操作直到矩阵变为空：

矩阵中每一行选取最大的一个数，并删除它。如果一行中有多个最大的数，选择任意一个并删除。
在步骤 1 删除的所有数字中找到最大的一个数字，将它添加到你的 分数 中。
请你返回最后的 分数 。



示例 1：

输入：nums = [[7,2,1],[6,4,2],[6,5,3],[3,2,1]]
输出：15
解释：第一步操作中，我们删除 7 ，6 ，6 和 3 ，将分数增加 7 。下一步操作中，删除 2 ，4 ，5 和 2 ，将分数增加 5 。最后删除 1 ，2 ，3 和 1 ，将分数增加 3 。所以总得分为 7 + 5 + 3 = 15 。
示例 2：

输入：nums = [[1]]
输出：1
解释：我们删除 1 并将分数增加 1 ，所以返回 1 。


提示：

1 <= nums.length <= 300
1 <= nums[i].length <= 500
0 <= nums[i][j] <= 103
*/

#include <iostream>
#include <algorithm>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int matrixSum(vector<vector<int>>& nums) {
        int row = nums.size(), column = nums[0].size(), score = 0;

        for (auto& oneRow : nums) {
            sort(oneRow.begin(), oneRow.end());
        }

        for (int j = 0; j < column; ++j) {
            int num = 0;

            for (int i = 0; i < row; ++i) {
                num = max(num, nums[i][j]);
            }

            score += num;
        }

        return score;
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<vector<int>> nums = { {7,2,1},{6,4,2},{6,5,3},{3,2,1} };
    check.checkInt(15, o.matrixSum(nums));

    nums = { {1} };
    check.checkInt(1, o.matrixSum(nums));
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
