/* 翻转子数组得到最大的数组值.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你一个整数数组 nums 。「数组值」定义为所有满足 0 <= i < nums.length-1 的 |nums[i]-nums[i+1]| 的和。

你可以选择给定数组的任意子数组，并将该子数组翻转。但你只能执行这个操作 一次 。

请你找到可行的最大 数组值 。

 

示例 1：

输入：nums = [2,3,1,5,4]
输出：10
解释：通过翻转子数组 [3,1,5] ，数组变成 [2,5,1,3,4] ，数组值为 10 。
示例 2：

输入：nums = [2,4,9,24,2,1,10]
输出：68
 

提示：

1 <= nums.length <= 3*10^4
-10^5 <= nums[i] <= 10^5

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/reverse-subarray-to-maximize-array-value
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <algorithm>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int maxValueAfterReverse(vector<int>& nums) {
        int i, size = nums.size();
        long long maxValue = 0;

        if (size == 1) {
            return 0;
        }

        for (i = 0; i < size - 1; ++i) {
            maxValue += abs(nums[i] - nums[i + 1]);
        }

        long long raw = maxValue, delta;

        for (i = 1; i <= size - 2; ++i) {  // reverse nums[i, size)
            delta = abs((long long)nums[size - 1] - nums[i - 1]) - abs((long long)nums[i] - nums[i - 1]);
            maxValue = max(maxValue, raw + delta);
        }

        for (i = 1; i <= size - 2; ++i) {  // reverse nums[0, i]
            delta = abs((long long)nums[i + 1] - nums[0]) - abs((long long)nums[i + 1] - nums[i]);
            maxValue = max(maxValue, raw + delta);
        }

        for (long long f1 : { -1,1 })
            for (long long f2 : { -1,1 }) {
                long long mx = -1000000000;

                for (i = 1; i < size; ++i) {
                    maxValue = max(maxValue, raw + mx + f1 * nums[i - 1] + f2 * nums[i] - abs(nums[i - 1] - nums[i]));
                    mx = max(mx, -f1 * nums[i - 1] - f2 * nums[i] - abs(nums[i - 1] - nums[i]));
                }
            }

        return (int)maxValue;
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<int> nums = { 2,3,1,5,4 };
    check.checkInt(10, o.maxValueAfterReverse(nums));

    nums = { 2,4,9,24,2,1,10 };
    check.checkInt(68, o.maxValueAfterReverse(nums));

    nums = { 63674,-34608,86424,-52056,-3992,93347,2084,-28546,-75702,-28400 };
    check.checkInt(811768, o.maxValueAfterReverse(nums));
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
