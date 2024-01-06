/* 划分数组并满足最大差限制.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你一个长度为 n 的整数数组 nums，以及一个正整数 k 。

将这个数组划分为一个或多个长度为 3 的子数组，并满足以下条件：

nums 中的 每个 元素都必须 恰好 存在于某个子数组中。
子数组中 任意 两个元素的差必须小于或等于 k 。
返回一个 二维数组 ，包含所有的子数组。如果不可能满足条件，就返回一个空数组。如果有多个答案，返回 任意一个 即可。



示例 1：

输入：nums = [1,3,4,8,7,9,3,5,1], k = 2
输出：[[1,1,3],[3,4,5],[7,8,9]]
解释：可以将数组划分为以下子数组：[1,1,3]，[3,4,5] 和 [7,8,9] 。
每个子数组中任意两个元素的差都小于或等于 2 。
注意，元素的顺序并不重要。
示例 2：

输入：nums = [1,3,3,2,7,3], k = 3
输出：[]
解释：无法划分数组满足所有条件。


提示：

n == nums.length
1 <= n <= 105
n 是 3 的倍数
1 <= nums[i] <= 105
1 <= k <= 105
*/

#include <iostream>
#include <algorithm>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    vector<vector<int>> divideArray(vector<int>& nums, int k) {
        int size = nums.size();
        vector<vector<int>> ans;

        sort(nums.begin(), nums.end());

        for (int i = 0; i < size; i += 3) {
            if (nums[i + 2] - nums[i] <= k) {
                ans.push_back({ nums[i],nums[i + 1],nums[i + 2] });
            }
            else {
                return {};
            }
        }

        return ans;
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<int> nums = { 15,13,12,13,12,14,12,2,3,13,12,14,14,13,5,12,12,2,13,2,2 };
    vector<vector<int>> actual = o.divideArray(nums, 2);
    vector<vector<int>> expected = {};
    check.checkIntVectorVector(expected, actual);

    nums = { 1,3,4,8,7,9,3,5,1 };
    actual = o.divideArray(nums, 2);
    expected = { {1,1,3},{3,4,5},{7,8,9} };
    check.checkIntVectorVector(expected, actual);

    nums = { 1,3,3,2,7,3 };
    actual = o.divideArray(nums, 3);
    expected = {};
    check.checkIntVectorVector(expected, actual);

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
