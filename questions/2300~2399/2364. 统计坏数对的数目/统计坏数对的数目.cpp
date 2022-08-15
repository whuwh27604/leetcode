/* 统计坏数对的数目.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你一个下标从 0 开始的整数数组 nums 。如果 i < j 且 j - i != nums[j] - nums[i] ，那么我们称 (i, j) 是一个 坏数对 。

请你返回 nums 中 坏数对 的总数目。

 

示例 1：

输入：nums = [4,1,3,3]
输出：5
解释：数对 (0, 1) 是坏数对，因为 1 - 0 != 1 - 4 。
数对 (0, 2) 是坏数对，因为 2 - 0 != 3 - 4, 2 != -1 。
数对 (0, 3) 是坏数对，因为 3 - 0 != 3 - 4, 3 != -1 。
数对 (1, 2) 是坏数对，因为 2 - 1 != 3 - 1, 1 != 2 。
数对 (2, 3) 是坏数对，因为 3 - 2 != 3 - 3, 1 != 0 。
总共有 5 个坏数对，所以我们返回 5 。
示例 2：

输入：nums = [1,2,3,4,5]
输出：0
解释：没有坏数对。
 

提示：

1 <= nums.length <= 105
1 <= nums[i] <= 109

来源：力扣（LeetCode）
链接：https://leetcode.cn/problems/count-number-of-bad-pairs
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <unordered_map>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    long long countBadPairs(vector<int>& nums) {
        unordered_map<int, long long> counts;
        int i, size = nums.size();
        long long goodPairs = 0;

        for (i = 0; i < size; ++i) {
            int key = nums[i] - i;
            goodPairs += counts[key];
            ++counts[key];
        }

        return (long long)size * (size - 1) / 2 - goodPairs;
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<int> nums = { 4,1,3,3 };
    check.checkLongLong(5, o.countBadPairs(nums));

    nums = { 1,2,3,4,5 };
    check.checkLongLong(0, o.countBadPairs(nums));
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
