/* 最高频元素的频数.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
元素的 频数 是该元素在一个数组中出现的次数。

给你一个整数数组 nums 和一个整数 k 。在一步操作中，你可以选择 nums 的一个下标，并将该下标对应元素的值增加 1 。

执行最多 k 次操作后，返回数组中最高频元素的 最大可能频数 。

 

示例 1：

输入：nums = [1,2,4], k = 5
输出：3
解释：对第一个元素执行 3 次递增操作，对第二个元素执 2 次递增操作，此时 nums = [4,4,4] 。
4 是数组中最高频元素，频数是 3 。
示例 2：

输入：nums = [1,4,8,13], k = 5
输出：2
解释：存在多种最优解决方案：
- 对第一个元素执行 3 次递增操作，此时 nums = [4,4,8,13] 。4 是数组中最高频元素，频数是 2 。
- 对第二个元素执行 4 次递增操作，此时 nums = [1,8,8,13] 。8 是数组中最高频元素，频数是 2 。
- 对第三个元素执行 5 次递增操作，此时 nums = [1,4,13,13] 。13 是数组中最高频元素，频数是 2 。
示例 3：

输入：nums = [3,9,6], k = 2
输出：1
 

提示：

1 <= nums.length <= 105
1 <= nums[i] <= 105
1 <= k <= 105

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/frequency-of-the-most-frequent-element
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <algorithm>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        int size = nums.size(), i = size - 1, j, opers = 0;
        sort(nums.begin(), nums.end());

        for (j = i - 1; j >= 0 && opers + (nums[i] - nums[j]) <= k; --j) {
            opers += (nums[i] - nums[j]);
        }

        int freq = i - j, maxFreq = freq;

        for (i = size - 2; i >= 0; --i) {
            opers -= (freq - 1) * (nums[i + 1] - nums[i]);

            for (; j >= 0 && opers + (nums[i] - nums[j]) <= k; --j) {
                opers += (nums[i] - nums[j]);
            }

            freq = i - j;
            maxFreq = max(maxFreq, freq);
        }

        return maxFreq;
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<int> nums = { 1,2,4 };
    check.checkInt(3, o.maxFrequency(nums, 5));

    nums = { 1,4,8,13 };
    check.checkInt(2, o.maxFrequency(nums, 5));

    nums = { 3,9,6 };
    check.checkInt(1, o.maxFrequency(nums, 2));

    nums = { 3 };
    check.checkInt(1, o.maxFrequency(nums, 2));
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
