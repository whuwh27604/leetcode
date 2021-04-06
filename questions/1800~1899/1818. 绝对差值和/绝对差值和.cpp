/* 绝对差值和.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你两个正整数数组 nums1 和 nums2 ，数组的长度都是 n 。

数组 nums1 和 nums2 的 绝对差值和 定义为所有 |nums1[i] - nums2[i]|（0 <= i < n）的 总和（下标从 0 开始）。

你可以选用 nums1 中的 任意一个 元素来替换 nums1 中的 至多 一个元素，以 最小化 绝对差值和。

在替换数组 nums1 中最多一个元素 之后 ，返回最小绝对差值和。因为答案可能很大，所以需要对 109 + 7 取余 后返回。

|x| 定义为：

如果 x >= 0 ，值为 x ，或者
如果 x <= 0 ，值为 -x
 

示例 1：

输入：nums1 = [1,7,5], nums2 = [2,3,5]
输出：3
解释：有两种可能的最优方案：
- 将第二个元素替换为第一个元素：[1,7,5] => [1,1,5] ，或者
- 将第二个元素替换为第三个元素：[1,7,5] => [1,5,5]
两种方案的绝对差值和都是 |1-2| + (|1-3| 或者 |5-3|) + |5-5| = 3
示例 2：

输入：nums1 = [2,4,6,8,10], nums2 = [2,4,6,8,10]
输出：0
解释：nums1 和 nums2 相等，所以不用替换元素。绝对差值和为 0
示例 3：

输入：nums1 = [1,10,4,4,2,7], nums2 = [9,3,5,1,7,4]
输出：20
解释：将第一个元素替换为第二个元素：[1,10,4,4,2,7] => [10,10,4,4,2,7]
绝对差值和为 |10-9| + |10-3| + |4-5| + |4-1| + |2-7| + |7-4| = 20
 

提示：

n == nums1.length
n == nums2.length
1 <= n <= 105
1 <= nums1[i], nums2[i] <= 105

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/minimum-absolute-sum-difference
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <set>
#include <algorithm>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int minAbsoluteSumDiff(vector<int>& nums1, vector<int>& nums2) {
        long long minAbsSum = LLONG_MAX, sum = getAbsoluteSum(nums1, nums2);
        set<int> set1;

        for (int num : nums1) {
            set1.insert(num);
        }

        for (int i = 0; i < (int)nums1.size(); ++i) {
            int num = nums2[i];
            auto iter = set1.lower_bound(num);
            if (iter != set1.end()) {
                minAbsSum = min(minAbsSum, sum - abs(num - nums1[i]) + abs(num - *iter));
            }

            if (iter != set1.begin()) {
                --iter;
                minAbsSum = min(minAbsSum, sum - abs(num - nums1[i]) + abs(num - *iter));
            }
        }

        return (int)(minAbsSum % 1000000007);
    }

    long long getAbsoluteSum(vector<int>& nums1, vector<int>& nums2) {
        long long sum = 0;

        for (int i = 0; i < (int)nums1.size(); ++i) {
            sum += abs(nums1[i] - nums2[i]);
        }

        return sum;
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<int> nums1 = { 1,7,5 };
    vector<int> nums2 = { 2,3,5 };
    check.checkInt(3, o.minAbsoluteSumDiff(nums1, nums2));

    nums1 = { 2,4,6,8,10 };
    nums2 = { 2,4,6,8,10 };
    check.checkInt(0, o.minAbsoluteSumDiff(nums1, nums2));

    nums1 = { 1,10,4,4,2,7 };
    nums2 = { 9,3,5,1,7,4 };
    check.checkInt(20, o.minAbsoluteSumDiff(nums1, nums2));

    nums1 = { 1 };
    nums2 = { 9 };
    check.checkInt(8, o.minAbsoluteSumDiff(nums1, nums2));

    nums1 = { 300,201,350 };
    nums2 = { 500,400,351 };
    check.checkInt(251, o.minAbsoluteSumDiff(nums1, nums2));
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
