/* 下标对中的最大距离.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你两个 非递增 的整数数组 nums1​​​​​​ 和 nums2​​​​​​ ，数组下标均 从 0 开始 计数。

下标对 (i, j) 中 0 <= i < nums1.length 且 0 <= j < nums2.length 。如果该下标对同时满足 i <= j 且 nums1[i] <= nums2[j] ，则称之为 有效 下标对，该下标对的 距离 为 j - i​​ 。​​

返回所有 有效 下标对 (i, j) 中的 最大距离 。如果不存在有效下标对，返回 0 。

一个数组 arr ，如果每个 1 <= i < arr.length 均有 arr[i-1] >= arr[i] 成立，那么该数组是一个 非递增 数组。

 

示例 1：

输入：nums1 = [55,30,5,4,2], nums2 = [100,20,10,10,5]
输出：2
解释：有效下标对是 (0,0), (2,2), (2,3), (2,4), (3,3), (3,4) 和 (4,4) 。
最大距离是 2 ，对应下标对 (2,4) 。
示例 2：

输入：nums1 = [2,2,2], nums2 = [10,10,1]
输出：1
解释：有效下标对是 (0,0), (0,1) 和 (1,1) 。
最大距离是 1 ，对应下标对 (0,1) 。
示例 3：

输入：nums1 = [30,29,19,5], nums2 = [25,25,25,25,25]
输出：2
解释：有效下标对是 (2,2), (2,3), (2,4), (3,3) 和 (3,4) 。
最大距离是 2 ，对应下标对 (2,4) 。
示例 4：

输入：nums1 = [5,4], nums2 = [3,2]
输出：0
解释：不存在有效下标对，所以返回 0 。
 

提示：

1 <= nums1.length <= 105
1 <= nums2.length <= 105
1 <= nums1[i], nums2[j] <= 105
nums1 和 nums2 都是 非递增 数组

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/maximum-distance-between-a-pair-of-values
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <algorithm>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int maxDistance(vector<int>& nums1, vector<int>& nums2) {
        int i, j = 0, size1 = nums1.size(), size2 = nums2.size(), maxDist = 0;

        for (i = 0; i < size1; ++i) {
            while (j < size2 && nums2[j] >= nums1[i]) {
                ++j;
            }

            if (j != 0) {
                --j;
            }

            if (j >= i) {
                maxDist = max(maxDist, j - i);
            }
        }

        return maxDist;
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<int> nums1 = { 55,30,5,4,2 };
    vector<int> nums2 = { 100,20,10,10,5 };
    check.checkInt(2, o.maxDistance(nums1, nums2));

    nums1 = { 2,2,2 };
    nums2 = { 10,10,1 };
    check.checkInt(1, o.maxDistance(nums1, nums2));

    nums1 = { 30,29,19,5 };
    nums2 = { 25,25,25,25,25 };
    check.checkInt(2, o.maxDistance(nums1, nums2));

    nums1 = { 5,4 };
    nums2 = { 3,2 };
    check.checkInt(0, o.maxDistance(nums1, nums2));

    nums1 = { 3,2,1 };
    nums2 = { 9,8,7,6,5,4 };
    check.checkInt(5, o.maxDistance(nums1, nums2));

    nums1 = { 3 };
    nums2 = { 9 };
    check.checkInt(0, o.maxDistance(nums1, nums2));
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
