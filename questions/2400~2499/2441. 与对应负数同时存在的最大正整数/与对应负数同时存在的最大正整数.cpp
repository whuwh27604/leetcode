/* 与对应负数同时存在的最大正整数.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你一个 不包含 任何零的整数数组 nums ，找出自身与对应的负数都在数组中存在的最大正整数 k 。

返回正整数 k ，如果不存在这样的整数，返回 -1 。

 

示例 1：

输入：nums = [-1,2,-3,3]
输出：3
解释：3 是数组中唯一一个满足题目要求的 k 。
示例 2：

输入：nums = [-1,10,6,7,-7,1]
输出：7
解释：数组中存在 1 和 7 对应的负数，7 的值更大。
示例 3：

输入：nums = [-10,8,6,7,-2,-3]
输出：-1
解释：不存在满足题目要求的 k ，返回 -1 。
 

提示：

1 <= nums.length <= 1000
-1000 <= nums[i] <= 1000
nums[i] != 0

来源：力扣（LeetCode）
链接：https://leetcode.cn/problems/largest-positive-integer-that-exists-with-its-negative
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <unordered_set>
#include <algorithm>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int findMaxK(vector<int>& nums) {
        int maxK = -1;
        unordered_set<int> numbers;

        for (int num : nums) {
            if (numbers.count(-num) != 0) {
                maxK = max(maxK, abs(num));
            }

            numbers.insert(num);
        }

        return maxK;
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<int> nums = { -1,2,-3,3 };
    check.checkInt(3, o.findMaxK(nums));

    nums = { -1,10,6,7,-7,1 };
    check.checkInt(7, o.findMaxK(nums));

    nums = { -10,8,6,7,-2,-3 };
    check.checkInt(-1, o.findMaxK(nums));
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
