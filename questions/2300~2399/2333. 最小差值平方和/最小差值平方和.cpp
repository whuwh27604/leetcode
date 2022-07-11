/* 最小差值平方和.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你两个下标从 0 开始的整数数组 nums1 和 nums2 ，长度为 n 。

数组 nums1 和 nums2 的 差值平方和 定义为所有满足 0 <= i < n 的 (nums1[i] - nums2[i])2 之和。

同时给你两个正整数 k1 和 k2 。你可以将 nums1 中的任意元素 +1 或者 -1 至多 k1 次。类似的，你可以将 nums2 中的任意元素 +1 或者 -1 至多 k2 次。

请你返回修改数组 nums1 至多 k1 次且修改数组 nums2 至多 k2 次后的最小 差值平方和 。

注意：你可以将数组中的元素变成 负 整数。

 

示例 1：

输入：nums1 = [1,2,3,4], nums2 = [2,10,20,19], k1 = 0, k2 = 0
输出：579
解释：nums1 和 nums2 中的元素不能修改，因为 k1 = 0 和 k2 = 0 。
差值平方和为：(1 - 2)2 + (2 - 10)2 + (3 - 20)2 + (4 - 19)2 = 579 。
示例 2：

输入：nums1 = [1,4,10,12], nums2 = [5,8,6,9], k1 = 1, k2 = 1
输出：43
解释：一种得到最小差值平方和的方式为：
- 将 nums1[0] 增加一次。
- 将 nums2[2] 增加一次。
最小差值平方和为：
(2 - 5)2 + (4 - 8)2 + (10 - 7)2 + (12 - 9)2 = 43 。
注意，也有其他方式可以得到最小差值平方和，但没有得到比 43 更小答案的方案。
 

提示：

n == nums1.length == nums2.length
1 <= n <= 105
0 <= nums1[i], nums2[i] <= 105
0 <= k1, k2 <= 109

来源：力扣（LeetCode）
链接：https://leetcode.cn/problems/minimum-sum-of-squared-difference
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <algorithm>
#include "../check/CheckResult.h"
#include "../tools/TestData.h"

using namespace std;

class Solution {
public:
    long long minSumSquareDiff(vector<int>& nums1, vector<int>& nums2, int k1, int k2) {
        int n = nums1.size();
        vector<int> nums(n);

        getNums(n, nums1, nums2, nums);
        sort(nums.begin(), nums.end());
        adjust(n, nums, k1 + k2);

        return getSum(nums);
    }

    void getNums(int n, vector<int>& nums1, vector<int>& nums2, vector<int>& nums) {
        for (int i = 0; i < n; ++i) {
            nums[i] = abs(nums1[i] - nums2[i]);
        }
    }

    void adjust(int n, vector<int>& nums, int k) {
        int index = 0, last = 0;

        for (int i = n - 1, width = 1; i >= 0; --i, ++width) {
            long long height = (i == 0 ? nums[0] : nums[i] - nums[i - 1]);

            if (height * width <= k) {
                k -= (int)(height * width);
            }
            else {
                index = i;
                last = (nums[i] - k / width);
                k %= width;
                break;
            }
        }

        if (last == 0) {
            nums = vector<int>(n, 0);
        }
        else {
            for (int j = 0; j < k; ++j) {
                nums[index + j] = last - 1;
            }

            for (index += k; index < n; ++index) {
                nums[index] = last;
            }
        }
    }

    long long getSum(vector<int>& nums) {
        long long sum = 0;

        for (int num : nums) {
            sum += ((long long)num * num);
        }

        return sum;
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<int> nums1 = { 1,2,3,4 };
    vector<int> nums2 = { 2,10,20,19 };
    check.checkLongLong(579, o.minSumSquareDiff(nums1, nums2, 0, 0));

    nums1 = { 1,2,3,4 };
    nums2 = { 2,10,20,19 };
    check.checkLongLong(0, o.minSumSquareDiff(nums1, nums2, 0, 1000));

    nums1 = { 1,4,10,12 };
    nums2 = { 5,8,6,9 };
    check.checkLongLong(43, o.minSumSquareDiff(nums1, nums2, 1, 1));

    nums1 = getIntVector("./testcase1nums1.txt");
    nums2 = getIntVector("./testcase1nums2.txt");
    check.checkLongLong(1000000000000000, o.minSumSquareDiff(nums1, nums2, 0, 0));
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
