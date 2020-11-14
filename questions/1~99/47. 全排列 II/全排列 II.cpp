/* 全排列 II.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给定一个可包含重复数字的序列，返回所有不重复的全排列。

示例:

输入: [1,1,2]
输出:
[
  [1,1,2],
  [1,2,1],
  [2,1,1]
]

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/permutations-ii
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <algorithm>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        vector<int> onePermutation;
        vector<vector<int>> allPermutations;
        permute(nums, onePermutation, allPermutations);

        return allPermutations;
    }

    void permute(vector<int>& nums, vector<int>& onePermutation, vector<vector<int>>& allPermutations) {
        int i, size = nums.size();

        if (size == 1) {
            vector<int> permutation = onePermutation;
            permutation.push_back(nums[0]);
            allPermutations.push_back(permutation);
            return;
        }

        for (i = 0; i < size; ++i) {
            if ((i != 0) && (nums[i] == nums[i - 1])) {
                continue;
            }

            vector<int> permutation = onePermutation;
            permutation.push_back(nums[i]);
            vector<int> tmpNums = nums;
            tmpNums.erase(tmpNums.begin() + i);
            permute(tmpNums, permutation, allPermutations);
        }
    }
};

int main()
{
    Solution o;
    CheckResult check;

    vector<int> nums = { 1,1,2 };
    vector<vector<int>> actual = o.permuteUnique(nums);
    vector<vector<int>> expected = { {1,1,2},{1,2,1},{2,1,1} };
    check.checkIntVectorVectorRandomOrder(expected, actual);

    nums = { 1 };
    actual = o.permuteUnique(nums);
    expected = { {1} };
    check.checkIntVectorVectorRandomOrder(expected, actual);

    nums = { 1,1 };
    actual = o.permuteUnique(nums);
    expected = { {1,1} };
    check.checkIntVectorVectorRandomOrder(expected, actual);

    nums = { 1,2,2 };
    actual = o.permuteUnique(nums);
    expected = { {1,2,2},{2,1,2},{2,2,1} };
    check.checkIntVectorVectorRandomOrder(expected, actual);

    nums = { 1,2,3 };
    actual = o.permuteUnique(nums);
    expected = { {1,2,3},{1,3,2},{2,1,3},{2,3,1},{3,1,2},{3,2,1} };
    check.checkIntVectorVectorRandomOrder(expected, actual);
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
