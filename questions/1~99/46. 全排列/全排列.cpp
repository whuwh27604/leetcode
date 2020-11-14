/* 全排列.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给定一个 没有重复 数字的序列，返回其所有可能的全排列。

示例:

输入: [1,2,3]
输出:
[
  [1,2,3],
  [1,3,2],
  [2,1,3],
  [2,3,1],
  [3,1,2],
  [3,2,1]
]

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/permutations
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <unordered_set>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        int i, j, len = nums.size();
        unordered_set<int> numbers;
        for (i = 0; i < len; i++) {
            numbers.insert(nums[i]);
        }

        list<vector<int>> allPermutation;
        for (i = 0; i < len; i++) {
            allPermutation.push_back({ nums[i] });
        }

        for (i = 1; i < len; i++) {
            int listLen = allPermutation.size();
            for (j = 0; j < listLen; j++) {
                vector<int> onePermutation = allPermutation.front();
                allPermutation.pop_front();

                unordered_set<int> tmpNumbers = numbers;
                for (unsigned int k = 0; k < onePermutation.size(); k++) {
                    tmpNumbers.erase(onePermutation[k]);
                }

                for (auto iter = tmpNumbers.begin(); iter != tmpNumbers.end(); iter++) {
                    onePermutation.push_back(*iter);
                    allPermutation.push_back(onePermutation);
                    onePermutation.pop_back();
                }
            }
        }

        vector<vector<int>> ans;
        for (auto iter = allPermutation.begin(); iter != allPermutation.end(); iter++) {
            ans.push_back(*iter);
        }

        return ans;
    }
};

int main()
{
    Solution o;
    CheckResult check;

    vector<int> nums = {};
    vector<vector<int>> actual = o.permute(nums);
    vector<vector<int>> expected = {};
    check.checkIntDoubleVector(expected, actual);

    nums = {1};
    actual = o.permute(nums);
    expected = { {1} };
    check.checkIntDoubleVector(expected, actual);

    nums = { 1,2 };
    actual = o.permute(nums);
    expected = { {1,2},{2,1} };
    check.checkIntDoubleVector(expected, actual);

    nums = { 1,2,3 };
    actual = o.permute(nums);
    expected = { {1,2,3},{1,3,2},{2,1,3},{2,3,1},{3,1,2},{3,2,1} };
    check.checkIntDoubleVector(expected, actual);

    nums = { 1,2,3,4 };
    actual = o.permute(nums);
    expected = { {1,2,3,4},{1,2,4,3},{1,3,2,4},{1,3,4,2},{1,4,2,3},{1,4,3,2},{2,1,3,4},{2,1,4,3},{2,3,1,4},{2,3,4,1},{2,4,1,3},{2,4,3,1},
        {3,1,2,4},{3,1,4,2},{3,2,1,4},{3,2,4,1},{3,4,1,2},{3,4,2,1},{4,1,2,3},{4,1,3,2},{4,2,1,3},{4,2,3,1},{4,3,1,2},{4,3,2,1} };
    check.checkIntDoubleVector(expected, actual);

    nums = { 1,2,3,4,5,6,7,8 };
    actual = o.permute(nums);
    expected = {};
    //check.checkIntDoubleVector(expected, actual);
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
