/* 半径为 k 的子数组平均值.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你一个下标从 0 开始的数组 nums ，数组中有 n 个整数，另给你一个整数 k 。

半径为 k 的子数组平均值 是指：nums 中一个以下标 i 为 中心 且 半径 为 k 的子数组中所有元素的平均值，即下标在 i - k 和 i + k 范围（含 i - k 和 i + k）内所有元素的平均值。如果在下标 i 前或后不足 k 个元素，那么 半径为 k 的子数组平均值 是 -1 。

构建并返回一个长度为 n 的数组 avgs ，其中 avgs[i] 是以下标 i 为中心的子数组的 半径为 k 的子数组平均值 。

x 个元素的 平均值 是 x 个元素相加之和除以 x ，此时使用截断式 整数除法 ，即需要去掉结果的小数部分。

例如，四个元素 2、3、1 和 5 的平均值是 (2 + 3 + 1 + 5) / 4 = 11 / 4 = 2.75，截断后得到 2 。
 

示例 1：



输入：nums = [7,4,3,9,1,8,5,2,6], k = 3
输出：[-1,-1,-1,5,4,4,-1,-1,-1]
解释：
- avg[0]、avg[1] 和 avg[2] 是 -1 ，因为在这几个下标前的元素数量都不足 k 个。
- 中心为下标 3 且半径为 3 的子数组的元素总和是：7 + 4 + 3 + 9 + 1 + 8 + 5 = 37 。
  使用截断式 整数除法，avg[3] = 37 / 7 = 5 。
- 中心为下标 4 的子数组，avg[4] = (4 + 3 + 9 + 1 + 8 + 5 + 2) / 7 = 4 。
- 中心为下标 5 的子数组，avg[5] = (3 + 9 + 1 + 8 + 5 + 2 + 6) / 7 = 4 。
- avg[6]、avg[7] 和 avg[8] 是 -1 ，因为在这几个下标后的元素数量都不足 k 个。
示例 2：

输入：nums = [100000], k = 0
输出：[100000]
解释：
- 中心为下标 0 且半径 0 的子数组的元素总和是：100000 。
  avg[0] = 100000 / 1 = 100000 。
示例 3：

输入：nums = [8], k = 100000
输出：[-1]
解释：
- avg[0] 是 -1 ，因为在下标 0 前后的元素数量均不足 k 。
 

提示：

n == nums.length
1 <= n <= 105
0 <= nums[i], k <= 105

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/k-radius-subarray-averages
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    vector<int> getAverages(vector<int>& nums, int k) {
        int i, j = k, size = nums.size(), window = 2 * k + 1;
        long long sum = 0;
        vector<int> averages(size, -1);

        if (window <= size) {
            for (i = 0; i < window; ++i) {
                sum += nums[i];
            }

            averages[j++] = (int)(sum / window);

            for (; i < size; ++i) {
                sum += ((long long)nums[i] - nums[i - window]);
                averages[j++] = (int)(sum / window);
            }
        }

        return averages;
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<int> nums = { 7,4,3,9,1,8,5,2,6 };
    vector<int> actual = o.getAverages(nums, 3);
    vector<int> expected = { -1,-1,-1,5,4,4,-1,-1,-1 };
    check.checkIntVector(expected, actual);

    nums = { 100000 };
    actual = o.getAverages(nums, 0);
    expected = { 100000 };
    check.checkIntVector(expected, actual);

    nums = { 1,2,3 };
    actual = o.getAverages(nums, 0);
    expected = { 1,2,3 };
    check.checkIntVector(expected, actual);

    nums = { 8 };
    actual = o.getAverages(nums, 100000);
    expected = { -1 };
    check.checkIntVector(expected, actual);

    nums = { 1,5 };
    actual = o.getAverages(nums, 1);
    expected = { -1,-1 };
    check.checkIntVector(expected, actual);

    nums = { 1,5,8 };
    actual = o.getAverages(nums, 1);
    expected = { -1,4,-1 };
    check.checkIntVector(expected, actual);
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
