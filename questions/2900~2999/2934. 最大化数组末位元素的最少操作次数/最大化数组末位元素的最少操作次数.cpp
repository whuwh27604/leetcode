/* 最大化数组末位元素的最少操作次数.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你两个下标从 0 开始的整数数组 nums1 和 nums2 ，这两个数组的长度都是 n 。

你可以执行一系列 操作（可能不执行）。

在每次操作中，你可以选择一个在范围 [0, n - 1] 内的下标 i ，并交换 nums1[i] 和 nums2[i] 的值。

你的任务是找到满足以下条件所需的 最小 操作次数：

nums1[n - 1] 等于 nums1 中所有元素的 最大值 ，即 nums1[n - 1] = max(nums1[0], nums1[1], ..., nums1[n - 1]) 。
nums2[n - 1] 等于 nums2 中所有元素的 最大值 ，即 nums2[n - 1] = max(nums2[0], nums2[1], ..., nums2[n - 1]) 。
以整数形式，表示并返回满足上述 全部 条件所需的 最小 操作次数，如果无法同时满足两个条件，则返回 -1 。



示例 1：

输入：nums1 = [1,2,7]，nums2 = [4,5,3]
输出：1
解释：在这个示例中，可以选择下标 i = 2 执行一次操作。
交换 nums1[2] 和 nums2[2] 的值，nums1 变为 [1,2,3] ，nums2 变为 [4,5,7] 。
同时满足两个条件。
可以证明，需要执行的最小操作次数为 1 。
因此，答案是 1 。
示例 2：

输入：nums1 = [2,3,4,5,9]，nums2 = [8,8,4,4,4]
输出：2
解释：在这个示例中，可以执行以下操作：
首先，选择下标 i = 4 执行操作。
交换 nums1[4] 和 nums2[4] 的值，nums1 变为 [2,3,4,5,4] ，nums2 变为 [8,8,4,4,9] 。
然后，选择下标 i = 3 执行操作。
交换 nums1[3] 和 nums2[3] 的值，nums1 变为 [2,3,4,4,4] ，nums2 变为 [8,8,4,5,9] 。
同时满足两个条件。
可以证明，需要执行的最小操作次数为 2 。
因此，答案是 2 。
示例 3：

输入：nums1 = [1,5,4]，nums2 = [2,5,3]
输出：-1
解释：在这个示例中，无法同时满足两个条件。
因此，答案是 -1 。


提示：

1 <= n == nums1.length == nums2.length <= 1000
1 <= nums1[i] <= 109
1 <= nums2[i] <= 109
*/

#include <iostream>
#include <algorithm>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int minOperations(vector<int>& nums1, vector<int>& nums2) {
        int size = nums1.size();
        int opers1 = minOperations(size, nums1, nums2);
        swap(nums1[size - 1], nums2[size - 1]);
        int opers2 = minOperations(size, nums1, nums2);

        if (opers2 == -1) {
            return opers1;
        }
        else {
            opers2 += 1;
            return opers1 == -1 ? opers2 : min(opers1, opers2);
        }
    }

    int minOperations(int size, vector<int>& nums1, vector<int>& nums2) {
        int opers = 0, max1 = nums1[size - 1], max2 = nums2[size - 1];

        for (int i = 0; i < size - 1; ++i) {
            if (nums1[i] <= max1 && nums2[i] <= max2) {
                continue;
            }

            if (nums1[i] <= max2 && nums2[i] <= max1) {
                ++opers;
            }
            else {
                return -1;
            }
        }

        return opers;
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<int> nums1 = { 1,2,7 };
    vector<int> nums2 = { 4,5,3 };
    check.checkInt(1, o.minOperations(nums1, nums2));

    nums1 = { 2,3,4,5,9 };
    nums2 = { 8,8,4,4,4 };
    check.checkInt(2, o.minOperations(nums1, nums2));

    nums1 = { 1,5,4 };
    nums2 = { 2,5,3 };
    check.checkInt(-1, o.minOperations(nums1, nums2));
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
