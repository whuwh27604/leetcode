/* 统计「优美子数组」.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你一个整数数组 nums 和一个整数 k。

如果某个 连续 子数组中恰好有 k 个奇数数字，我们就认为这个子数组是「优美子数组」。

请返回这个数组中「优美子数组」的数目。

 

示例 1：

输入：nums = [1,1,2,1,1], k = 3
输出：2
解释：包含 3 个奇数的子数组是 [1,1,2,1] 和 [1,2,1,1] 。
示例 2：

输入：nums = [2,4,6], k = 1
输出：0
解释：数列中不包含任何奇数，所以不存在优美子数组。
示例 3：

输入：nums = [2,2,2,1,2,2,1,2,2,2], k = 2
输出：16
 

提示：

1 <= nums.length <= 50000
1 <= nums[i] <= 10^5
1 <= k <= nums.length

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/count-number-of-nice-subarrays
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        vector<int> evens;
        countEvens(nums, evens);

        return countSubarrays(evens, k);
    }

    void countEvens(vector<int>& nums, vector<int>& evens) {
        int count = 0;

        for (int num : nums) {
            if ((num & 1) == 1) {
                evens.push_back(count);
                count = 0;
            }
            else {
                ++count;
            }
        }

        evens.push_back(count);
    }

    int countSubarrays(vector<int>& evens, int k) {
        int i, j, size = evens.size(), count = 0;

        for (i = 0, j = i + k; j < size; ++i, ++j) {
            count += ((evens[i] + 1) * (evens[j] + 1));
        }

        return count;
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<int> nums = { 1,1,2,1,1 };
    check.checkInt(2, o.numberOfSubarrays(nums, 3));

    nums = { 2,4,6 };
    check.checkInt(0, o.numberOfSubarrays(nums, 1));

    nums = { 2,2,2,1,2,2,1,2,2,2 };
    check.checkInt(16, o.numberOfSubarrays(nums, 2));

    nums = { 2,2,2,1,2,1,1,2,2,2 };
    check.checkInt(12, o.numberOfSubarrays(nums, 2));

    nums = { 2,2,1,2,2 };
    check.checkInt(0, o.numberOfSubarrays(nums, 2));

    nums = { 2,2,1,2,2,2 };
    check.checkInt(12, o.numberOfSubarrays(nums, 1));

    nums = { 2,2,1,2,2,2,1 };
    check.checkInt(16, o.numberOfSubarrays(nums, 1));

    nums = { 1,1,1,1,1 };
    check.checkInt(1, o.numberOfSubarrays(nums, 5));

    nums = { 1,1,1,1,1 };
    check.checkInt(5, o.numberOfSubarrays(nums, 1));

    nums = { 2,2,2,1,2,2,1,2,2,2,2,2,2,1,2,2,1,2,2,2 };
    check.checkInt(65, o.numberOfSubarrays(nums, 2));

    nums = { 1 };
    check.checkInt(1, o.numberOfSubarrays(nums, 1));

    nums = { 2 };
    check.checkInt(0, o.numberOfSubarrays(nums, 1));
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
