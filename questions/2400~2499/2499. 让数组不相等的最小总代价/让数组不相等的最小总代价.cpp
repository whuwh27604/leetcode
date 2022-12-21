/* 让数组不相等的最小总代价.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你两个下标从 0 开始的整数数组 nums1 和 nums2 ，两者长度都为 n 。

每次操作中，你可以选择交换 nums1 中任意两个下标处的值。操作的 开销 为两个下标的 和 。

你的目标是对于所有的 0 <= i <= n - 1 ，都满足 nums1[i] != nums2[i] ，你可以进行 任意次 操作，请你返回达到这个目标的 最小 总代价。

请你返回让 nums1 和 nums2 满足上述条件的 最小总代价 ，如果无法达成目标，返回 -1 。



示例 1：

输入：nums1 = [1,2,3,4,5], nums2 = [1,2,3,4,5]
输出：10
解释：
实现目标的其中一种方法为：
- 交换下标为 0 和 3 的两个值，代价为 0 + 3 = 3 。现在 nums1 = [4,2,3,1,5] 。
- 交换下标为 1 和 2 的两个值，代价为 1 + 2 = 3 。现在 nums1 = [4,3,2,1,5] 。
- 交换下标为 0 和 4 的两个值，代价为 0 + 4 = 4 。现在 nums1 = [5,3,2,1,4] 。
最后，对于每个下标 i ，都有 nums1[i] != nums2[i] 。总代价为 10 。
还有别的交换值的方法，但是无法得到代价和小于 10 的方案。
示例 2：

输入：nums1 = [2,2,2,1,3], nums2 = [1,2,2,3,3]
输出：10
解释：
实现目标的一种方法为：
- 交换下标为 2 和 3 的两个值，代价为 2 + 3 = 5 。现在 nums1 = [2,2,1,2,3] 。
- 交换下标为 1 和 4 的两个值，代价为 1 + 4 = 5 。现在 nums1 = [2,3,1,2,2] 。
总代价为 10 ，是所有方案中的最小代价。
示例 3：

输入：nums1 = [1,2,2], nums2 = [1,2,2]
输出：-1
解释：
不管怎么操作，都无法满足题目要求。
所以返回 -1 。


提示：

n == nums1.length == nums2.length
1 <= n <= 105
1 <= nums1[i], nums2[i] <= n
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    long long minimumTotalCost(vector<int>& nums1, vector<int>& nums2) {
        long long cost = 0;
        int size = nums1.size(), swapCnt = 0, mode = 0, modeCnt = 0;
        vector<int> count(size + 1, 0);

        for (int i = 0; i < size; ++i) {
            if (nums1[i] == nums2[i]) {
                int x = nums1[i];
                cost += i;
                ++swapCnt;
                if (++count[x] > modeCnt) {
                    modeCnt = count[x];
                    mode = x;
                }
            }
        }

        for (int i = 0; i < size && modeCnt * 2 > swapCnt; ++i) {
            if (nums1[i] != nums2[i] && nums1[i] != mode && nums2[i] != mode) {
                cost += i;
                ++swapCnt;
            }
        }

        return modeCnt * 2 > swapCnt ? -1 : cost;
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<int> nums1 = { 1,2,3,4,5 };
    vector<int> nums2 = { 1,2,3,4,5 };
    check.checkLongLong(10, o.minimumTotalCost(nums1, nums2));

    nums1 = { 2,2,2,1,3 };
    nums2 = { 1,2,2,3,3 };
    check.checkLongLong(10, o.minimumTotalCost(nums1, nums2));

    nums1 = { 1,2,2 };
    nums2 = { 1,2,2 };
    check.checkLongLong(-1, o.minimumTotalCost(nums1, nums2));

    nums1 = { 1,2,3,4,4 };
    nums2 = { 1,2,3,4,5 };
    check.checkLongLong(6, o.minimumTotalCost(nums1, nums2));

    nums1 = { 2,2,2,1,3 };
    nums2 = { 2,1,2,3,3 };
    check.checkLongLong(9, o.minimumTotalCost(nums1, nums2));
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
