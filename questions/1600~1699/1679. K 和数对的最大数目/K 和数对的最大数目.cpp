/* K 和数对的最大数目.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你一个整数数组 nums 和一个整数 k 。

每一步操作中，你需要从数组中选出和为 k 的两个整数，并将它们移出数组。

返回你可以对数组执行的最大操作数。

 

示例 1：

输入：nums = [1,2,3,4], k = 5
输出：2
解释：开始时 nums = [1,2,3,4]：
- 移出 1 和 4 ，之后 nums = [2,3]
- 移出 2 和 3 ，之后 nums = []
不再有和为 5 的数对，因此最多执行 2 次操作。
示例 2：

输入：nums = [3,1,3,4,3], k = 6
输出：1
解释：开始时 nums = [3,1,3,4,3]：
- 移出前两个 3 ，之后nums = [1,4,3]
不再有和为 6 的数对，因此最多执行 1 次操作。
 

提示：

1 <= nums.length <= 105
1 <= nums[i] <= 109
1 <= k <= 109

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/max-number-of-k-sum-pairs
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <unordered_map>
#include <algorithm>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        unordered_map<int, int> numsCount;
        int operations = 0;

        for (int num : nums) {
            ++numsCount[num];
        }

        if (k % 2 == 0) {
            int half = k / 2;
            if (numsCount.count(half) != 0) {
                operations += (numsCount[half] / 2);
                numsCount.erase(half);
            }
        }

        for (auto iter = numsCount.begin(); iter != numsCount.end(); ++iter) {
            int num = k - iter->first;

            if (numsCount.count(num) != 0) {
                operations += min(iter->second, numsCount[num]);
                numsCount.erase(num);
            }
        }

        return operations;
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<int> nums = { 4 };
    check.checkInt(0, o.maxOperations(nums, 4));

    nums = { 1,3 };
    check.checkInt(1, o.maxOperations(nums, 4));

    nums = { 1,3,1 };
    check.checkInt(1, o.maxOperations(nums, 4));

    nums = { 1,2,3,4 };
    check.checkInt(2, o.maxOperations(nums, 5));

    nums = { 3,1,3,4,3 };
    check.checkInt(1, o.maxOperations(nums, 6));

    nums = { 73,74,74,71,68,67,45,1,24,2,26,48,82,82,28,60,19,36,26,9,12,83,1,86,18,78,14,66,20,26,4,80,44,35,53,48,74,25,75,47,31,20,59,10,35,24,26,3,48,69,78,43,12,86,37,49,1,90,20,35,58,20,2,20,16,18,88,25,44,63,12,16,64,41,86,87,2,23,14,63,43,60,47,7,23,11,64,53,71,78,82,56,65,25,27,52,89,68,63,14,48 };
    check.checkInt(11, o.maxOperations(nums, 44));
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
