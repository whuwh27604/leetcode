/* 子集.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给定一组不含重复元素的整数数组 nums，返回该数组所有可能的子集（幂集）。

说明：解集不能包含重复的子集。

示例:

输入: nums = [1,2,3]
输出:
[
  [3],
  [1],
  [2],
  [1,2,3],
  [1,3],
  [2,3],
  [1,2],
  []
]

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/subsets
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        int size = (int)pow(2, nums.size()) - 1;
        vector<vector<int>> allSubsets(size + 1, vector<int>{});

        for (int i = 0; i < size; ++i) {
            int selected = i + 1;
            int index = 0;

            while (selected != 0) {
                if ((selected & 1) == 1) {
                    allSubsets[i].push_back(nums[index]);
                }

                selected >>= 1;
                ++index;
            }
        }

        return allSubsets;
    }
};

int main()
{
    Solution o;
    CheckResult check;

    vector<int> nums = {};
    vector<vector<int>> actual = o.subsets(nums);
    vector<vector<int>> expected = { {} };
    check.checkIntVectorRandomVectorRandomOrder(expected, actual);

    nums = { 1 };
    actual = o.subsets(nums);
    expected = { {1},{} };
    check.checkIntVectorRandomVectorRandomOrder(expected, actual);

    nums = { 1,2 };
    actual = o.subsets(nums);
    expected = { {1},{2},{1,2},{} };
    check.checkIntVectorRandomVectorRandomOrder(expected, actual);

    nums = { 3,1,2 };
    actual = o.subsets(nums);
    expected = { {1},{2},{3},{1,2},{1,3},{2,3},{1,2,3},{} };
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
