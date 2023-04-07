/* 转换二维数组.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你一个整数数组 nums 。请你创建一个满足以下条件的二维数组：

二维数组应该 只 包含数组 nums 中的元素。
二维数组中的每一行都包含 不同 的整数。
二维数组的行数应尽可能 少 。
返回结果数组。如果存在多种答案，则返回其中任何一种。

请注意，二维数组的每一行上可以存在不同数量的元素。



示例 1：

输入：nums = [1,3,4,1,2,3,1]
输出：[[1,3,4,2],[1,3],[1]]
解释：根据题目要求可以创建包含以下几行元素的二维数组：
- 1,3,4,2
- 1,3
- 1
nums 中的所有元素都有用到，并且每一行都由不同的整数组成，所以这是一个符合题目要求的答案。
可以证明无法创建少于三行且符合题目要求的二维数组。
示例 2：

输入：nums = [1,2,3,4]
输出：[[4,3,2,1]]
解释：nums 中的所有元素都不同，所以我们可以将其全部保存在二维数组中的第一行。


提示：

1 <= nums.length <= 200
1 <= nums[i] <= nums.length
*/

#include <iostream>
#include <algorithm>
#include <unordered_map>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    vector<vector<int>> findMatrix(vector<int>& nums) {
        unordered_map<int, int> numsCount;
        int maxCount = 0;

        for (int num : nums) {
            ++numsCount[num];
        }

        for (auto& kv : numsCount) {
            maxCount = max(maxCount, kv.second);
        }

        vector<vector<int>> matrix(maxCount);

        for (auto& kv : numsCount) {
            for (int i = 0; i < kv.second; ++i) {
                matrix[i].push_back(kv.first);
            }
        }

        return matrix;
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<int> nums = { 1,3,4,1,2,3,1 };
    vector<vector<int>> actual = o.findMatrix(nums);
    vector<vector<int>> expected = { {1,2,3,4},{1,3},{1} };
    check.checkIntVectorRandomVectorRandomOrder(expected, actual);

    nums = { 1,2,3,4 };
    actual = o.findMatrix(nums);
    expected = { {1,2,3,4} };
    check.checkIntVectorRandomVectorRandomOrder(expected, actual);

    nums = { 114,64,33,129,49,121,44,81,9,98,98,18,5,9,49,64,98,98,28,129,129,112,5,129,49,40,89,129,29,55,68,106,59,107,44,127,98,107,95,28,64,64,49,44,121,121,39,108,48,28,129,120,129,74,28,89,65,64,48,129,98,127,98,64,64,98,98,28,91,98,64,74,49,25,49,23,64,129,72,114,50,76,121,5,37,9,119,129,41,37,129,113,56,74,33,64,98,74,18,107,65,47,89,33,98,49,74,49,64,99,93,44,64,64,44,23,129,106,44,44,129,79,98,9,44,64,44,95,48,9 };
    actual = o.findMatrix(nums);
    expected = { {79,93,56,113,41,119,37,76,50,72,23,25,91,65,28,81,121,18,44,99,40,33,120,129,5,64,112,89,29,114,55,9,127,68,98,39,47,106,107,48,59,95,49,108,74},{37,23,65,28,121,18,44,33,129,5,64,89,114,9,127,98,106,107,48,95,49,74},{28,121,44,33,129,5,64,89,9,98,107,48,49,74},{28,121,44,129,64,9,98,49,74},{28,44,129,64,9,98,49,74},{44,129,64,98,49},{44,129,64,98,49},{44,129,64,98,49},{44,129,64,98},{129,64,98},{129,64,98},{129,64,98},{129,64,98},{64} };
    check.checkIntVectorRandomVectorRandomOrder(expected, actual);
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
