/* 使数组 K 递增的最少操作次数.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你一个下标从 0 开始包含 n 个正整数的数组 arr ，和一个正整数 k 。

如果对于每个满足 k <= i <= n-1 的下标 i ，都有 arr[i-k] <= arr[i] ，那么我们称 arr 是 K 递增 的。

比方说，arr = [4, 1, 5, 2, 6, 2] 对于 k = 2 是 K 递增的，因为：
arr[0] <= arr[2] (4 <= 5)
arr[1] <= arr[3] (1 <= 2)
arr[2] <= arr[4] (5 <= 6)
arr[3] <= arr[5] (2 <= 2)
但是，相同的数组 arr 对于 k = 1 不是 K 递增的（因为 arr[0] > arr[1]），对于 k = 3 也不是 K 递增的（因为 arr[0] > arr[3] ）。
每一次 操作 中，你可以选择一个下标 i 并将 arr[i] 改成任意 正整数。

请你返回对于给定的 k ，使数组变成 K 递增的 最少操作次数 。

 

示例 1：

输入：arr = [5,4,3,2,1], k = 1
输出：4
解释：
对于 k = 1 ，数组最终必须变成非递减的。
可行的 K 递增结果数组为 [5,6,7,8,9]，[1,1,1,1,1]，[2,2,3,4,4] 。它们都需要 4 次操作。
次优解是将数组变成比方说 [6,7,8,9,10] ，因为需要 5 次操作。
显然我们无法使用少于 4 次操作将数组变成 K 递增的。
示例 2：

输入：arr = [4,1,5,2,6,2], k = 2
输出：0
解释：
这是题目描述中的例子。
对于每个满足 2 <= i <= 5 的下标 i ，有 arr[i-2] <= arr[i] 。
由于给定数组已经是 K 递增的，我们不需要进行任何操作。
示例 3：

输入：arr = [4,1,5,2,6,2], k = 3
输出：2
解释：
下标 3 和 5 是仅有的 3 <= i <= 5 且不满足 arr[i-3] <= arr[i] 的下标。
将数组变成 K 递增的方法之一是将 arr[3] 变为 4 ，且将 arr[5] 变成 5 。
数组变为 [4,1,5,4,6,5] 。
可能有其他方法将数组变为 K 递增的，但没有任何一种方法需要的操作次数小于 2 次。
 

提示：

1 <= arr.length <= 105
1 <= arr[i], k <= arr.length

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/minimum-operations-to-make-the-array-k-increasing
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <algorithm>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int kIncreasing(vector<int>& arr, int k) {
        int i, j, size = arr.size(), opers = 0;

        for (i = 0; i < k; ++i) {
            vector<int> nums;

            for (j = i; j < size; j += k) {
                nums.push_back(arr[j]);
            }

            opers += ((int)nums.size() - getLIS(nums));
        }

        return opers;
    }

    int getLIS(vector<int>& nums) {
        int i, size = nums.size(), len = 1;
        vector<int> minNums(size + 1, 0);  // minNums[i]表示LIS长度为i时，最后一个数的最小值，显然minNums单调不降
        minNums[1] = nums[0];

        for (i = 1; i < size; ++i) {
            if (nums[i] >= minNums[len]) {  // 如果比当前LIS的最后一个数大，那么可以直接添加在后面，LIS长度加1
                minNums[++len] = nums[i];
            }
            else {  // 否则用nums[i]更新第一个大于nums[i]的minNums，即完成相同长度的LIS，最后一个数可以更小
                auto iter = upper_bound(minNums.begin(), minNums.begin() + len + 1, nums[i]);
                *iter = nums[i];
            }
        }

        return len;
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<int> arr = { 5,4,3,2,1 };
    check.checkInt(4, o.kIncreasing(arr, 1));

    arr = { 4,1,5,2,6,2 };
    check.checkInt(0, o.kIncreasing(arr, 2));

    arr = { 4,1,5,2,6,2 };
    check.checkInt(2, o.kIncreasing(arr, 3));

    arr = { 12,6,12,6,14,2,13,17,3,8,11,7,4,11,18,8,8,3 };
    check.checkInt(12, o.kIncreasing(arr, 1));

    arr = { 4 };
    check.checkInt(0, o.kIncreasing(arr, 1));
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
