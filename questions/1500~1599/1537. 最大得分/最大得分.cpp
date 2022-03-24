/* 最大得分.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
你有两个 有序 且数组内元素互不相同的数组 nums1 和 nums2 。

一条 合法路径 定义如下：

选择数组 nums1 或者 nums2 开始遍历（从下标 0 处开始）。
从左到右遍历当前数组。
如果你遇到了 nums1 和 nums2 中都存在的值，那么你可以切换路径到另一个数组对应数字处继续遍历（但在合法路径中重复数字只会被统计一次）。
得分定义为合法路径中不同数字的和。

请你返回所有可能合法路径中的最大得分。

由于答案可能很大，请你将它对 10^9 + 7 取余后返回。

 

示例 1：



输入：nums1 = [2,4,5,8,10], nums2 = [4,6,8,9]
输出：30
解释：合法路径包括：
[2,4,5,8,10], [2,4,5,8,9], [2,4,6,8,9], [2,4,6,8,10],（从 nums1 开始遍历）
[4,6,8,9], [4,5,8,10], [4,5,8,9], [4,6,8,10]  （从 nums2 开始遍历）
最大得分为上图中的绿色路径 [2,4,6,8,10] 。
示例 2：

输入：nums1 = [1,3,5,7,9], nums2 = [3,5,100]
输出：109
解释：最大得分由路径 [1,3,5,100] 得到。
示例 3：

输入：nums1 = [1,2,3,4,5], nums2 = [6,7,8,9,10]
输出：40
解释：nums1 和 nums2 之间无相同数字。
最大得分由路径 [6,7,8,9,10] 得到。
示例 4：

输入：nums1 = [1,4,5,8,9,11,19], nums2 = [2,3,4,11,12]
输出：61
 

提示：

1 <= nums1.length <= 10^5
1 <= nums2.length <= 10^5
1 <= nums1[i], nums2[i] <= 10^7
nums1 和 nums2 都是严格递增的数组。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/get-the-maximum-score
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <algorithm>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int maxSum(vector<int>& nums1, vector<int>& nums2) {
        vector<pair<int, int>> sames = { {-1,-1} };
        getSame(nums1, nums2, sames);

        int size1 = nums1.size(), size2 = nums2.size(), size = sames.size(), i = size1, j = size2, k;
        vector<long long> dp1(size1 + 1, 0), dp2(size2 + 1, 0);

        for (k = size - 1; k >= 0; --k) {
            for (--i; i > sames[k].first; --i) {
                dp1[i] = nums1[i] + dp1[i + 1];
            }

            for (--j; j > sames[k].second; --j) {
                dp2[j] = nums2[j] + dp2[j + 1];
            }

            if (i >= 0) {
                dp1[i] = dp2[j] = max(dp1[i + 1], dp2[j + 1]) + nums1[i];
            }
        }

        return (int)(max(dp1[0], dp2[0]) % 1000000007);
    }

    void getSame(vector<int>& nums1, vector<int>& nums2, vector<pair<int, int>>& sames) {
        int i, j = 0, size1 = nums1.size(), size2 = nums2.size();

        for (i = 0; i < size1; ++i) {
            for (; j < size2 && nums2[j] < nums1[i]; ++j) {}

            if (j < size2 && nums2[j] == nums1[i]) {
                sames.push_back({ i,j });
            }
        }
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<int> nums1 = { 2,4,5,8,10 };
    vector<int> nums2 = { 4,6,8,9 };
    check.checkInt(30, o.maxSum(nums1, nums2));

    nums1 = { 1,3,5,7,9 };
    nums2 = { 3,5,100 };
    check.checkInt(109, o.maxSum(nums1, nums2));

    nums1 = { 3,5,7,9 };
    nums2 = { 1,3,5,100 };
    check.checkInt(109, o.maxSum(nums1, nums2));

    nums1 = { 1,2,3,4,5 };
    nums2 = { 6,7,8,9,10 };
    check.checkInt(40, o.maxSum(nums1, nums2));

    nums1 = { 1,4,5,8,9,11,19 };
    nums2 = { 2,3,4,11,12 };
    check.checkInt(61, o.maxSum(nums1, nums2));

    nums1 = { 1,4,5,8,9,11,19 };
    nums2 = { 1,3,4,11,12 };
    check.checkInt(60, o.maxSum(nums1, nums2));

    nums1 = { 1,4,5,8,9,11,19 };
    nums2 = { 2,3,4,11,19 };
    check.checkInt(61, o.maxSum(nums1, nums2));

    nums1 = { 1,4,5,8,9,11,19 };
    nums2 = { 2,3,4,11,19,35 };
    check.checkInt(96, o.maxSum(nums1, nums2));

    nums1 = { 1,4,5,8,9,11,19,30 };
    nums2 = { 2,3,4,11,19 };
    check.checkInt(91, o.maxSum(nums1, nums2));

    nums1 = { 6,7,8,10,16,19 };
    nums2 = { 9,10,18,25,27 };
    check.checkInt(101, o.maxSum(nums1, nums2));
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
