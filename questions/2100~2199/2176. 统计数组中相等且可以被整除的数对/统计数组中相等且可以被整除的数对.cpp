/* 统计数组中相等且可以被整除的数对.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你一个下标从 0 开始长度为 n 的整数数组 nums 和一个整数 k ，请你返回满足 0 <= i < j < n ，nums[i] == nums[j] 且 (i * j) 能被 k 整除的数对 (i, j) 的 数目 。

 

示例 1：

输入：nums = [3,1,2,2,2,1,3], k = 2
输出：4
解释：
总共有 4 对数符合所有要求：
- nums[0] == nums[6] 且 0 * 6 == 0 ，能被 2 整除。
- nums[2] == nums[3] 且 2 * 3 == 6 ，能被 2 整除。
- nums[2] == nums[4] 且 2 * 4 == 8 ，能被 2 整除。
- nums[3] == nums[4] 且 3 * 4 == 12 ，能被 2 整除。
示例 2：

输入：nums = [1,2,3,4], k = 1
输出：0
解释：由于数组中没有重复数值，所以没有数对 (i,j) 符合所有要求。
 

提示：

1 <= nums.length <= 100
1 <= nums[i], k <= 100

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/count-equal-and-divisible-pairs-in-an-array
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int countPairs(vector<int>& nums, int k) {
        int i, size = nums.size(), pairs = 0;
        vector<vector<int>> indices(101);

        for (i = 0; i < size; ++i) {
            indices[nums[i]].push_back(i);
        }

        for (auto& indexes : indices) {
            if (indexes.size() > 1) {
                pairs += count(indexes, k);
            }
        }

        return pairs;
    }

    int count(vector<int>& indexes, int k) {
        int i, j, size = indexes.size(), pairs = 0;

        for (i = 0; i < size - 1; ++i) {
            for (j = i + 1; j < size; ++j) {
                if ((indexes[i] * indexes[j]) % k == 0) {
                    ++pairs;
                }
            }
        }

        return pairs;
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<int> nums = { 3,1,2,2,2,1,3 };
    check.checkInt(4, o.countPairs(nums, 2));

    nums = { 1,2,3,4 };
    check.checkInt(0, o.countPairs(nums, 1));

    nums = { 5 };
    check.checkInt(0, o.countPairs(nums, 1));
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
