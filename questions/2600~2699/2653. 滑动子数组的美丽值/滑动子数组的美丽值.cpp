/* 滑动子数组的美丽值.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你一个长度为 n 的整数数组 nums ，请你求出每个长度为 k 的子数组的 美丽值 。

一个子数组的 美丽值 定义为：如果子数组中第 x 小整数 是 负数 ，那么美丽值为第 x 小的数，否则美丽值为 0 。

请你返回一个包含 n - k + 1 个整数的数组，依次 表示数组中从第一个下标开始，每个长度为 k 的子数组的 美丽值 。

子数组指的是数组中一段连续 非空 的元素序列。



示例 1：

输入：nums = [1,-1,-3,-2,3], k = 3, x = 2
输出：[-1,-2,-2]
解释：总共有 3 个 k = 3 的子数组。
第一个子数组是 [1, -1, -3] ，第二小的数是负数 -1 。
第二个子数组是 [-1, -3, -2] ，第二小的数是负数 -2 。
第三个子数组是 [-3, -2, 3] ，第二小的数是负数 -2 。
示例 2：

输入：nums = [-1,-2,-3,-4,-5], k = 2, x = 2
输出：[-1,-2,-3,-4]
解释：总共有 4 个 k = 2 的子数组。
[-1, -2] 中第二小的数是负数 -1 。
[-2, -3] 中第二小的数是负数 -2 。
[-3, -4] 中第二小的数是负数 -3 。
[-4, -5] 中第二小的数是负数 -4 。
示例 3：

输入：nums = [-3,1,2,-3,0,-3], k = 2, x = 1
输出：[-3,0,-3,-3,-3]
解释：总共有 5 个 k = 2 的子数组。
[-3, 1] 中最小的数是负数 -3 。
[1, 2] 中最小的数不是负数，所以美丽值为 0 。
[2, -3] 中最小的数是负数 -3 。
[-3, 0] 中最小的数是负数 -3 。
[0, -3] 中最小的数是负数 -3 。


提示：

n == nums.length
1 <= n <= 105
1 <= k <= n
1 <= x <= k
-50 <= nums[i] <= 50
*/

#include <iostream>
#include <map>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    vector<int> getSubarrayBeauty(vector<int>& nums, int k, int x) {
        int size = nums.size(), i = 0;
        vector<int> numsCount(101, 0);
        vector<int> ans(size - k + 1);

        for (; i < k - 1; ++i) {
            ++numsCount[nums[i] + 50];
        }

        for (; i < size; ++i) {
            ++numsCount[nums[i] + 50];
            ans[i + 1 - k] = getBeauty(numsCount, x);
            --numsCount[nums[i + 1 - k] + 50];
        }

        return ans;
    }

    int getBeauty(vector<int>& numsCount, int x) {
        int count = 0;

        for (int i = 0; i < 50; ++i) {
            count += numsCount[i];

            if (count >= x) {
                return i - 50;
            }
        }

        return 0;
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<int> nums = { 1,-1,-3,-2,3 };
    vector<int> actual = o.getSubarrayBeauty(nums, 3, 2);
    vector<int> expected = { -1,-2,-2 };
    check.checkIntVector(expected, actual);

    nums = { -1,-2,-3,-4,-5 };
    actual = o.getSubarrayBeauty(nums, 2, 2);
    expected = { -1,-2,-3,-4 };
    check.checkIntVector(expected, actual);

    nums = { -3,1,2,-3,0,-3 };
    actual = o.getSubarrayBeauty(nums, 2, 1);
    expected = { -3,0,-3,-3,-3 };
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
