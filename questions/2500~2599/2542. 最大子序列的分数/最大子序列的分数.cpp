/* 最大子序列的分数.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你两个下标从 0 开始的整数数组 nums1 和 nums2 ，两者长度都是 n ，再给你一个正整数 k 。你必须从 nums1 中选一个长度为 k 的 子序列 对应的下标。

对于选择的下标 i0 ，i1 ，...， ik - 1 ，你的 分数 定义如下：

nums1 中下标对应元素求和，乘以 nums2 中下标对应元素的 最小值 。
用公示表示： (nums1[i0] + nums1[i1] +...+ nums1[ik - 1]) * min(nums2[i0] , nums2[i1], ... ,nums2[ik - 1]) 。
请你返回 最大 可能的分数。

一个数组的 子序列 下标是集合 {0, 1, ..., n-1} 中删除若干元素得到的剩余集合，也可以不删除任何元素。



示例 1：

输入：nums1 = [1,3,3,2], nums2 = [2,1,3,4], k = 3
输出：12
解释：
四个可能的子序列分数为：
- 选择下标 0 ，1 和 2 ，得到分数 (1+3+3) * min(2,1,3) = 7 。
- 选择下标 0 ，1 和 3 ，得到分数 (1+3+2) * min(2,1,4) = 6 。
- 选择下标 0 ，2 和 3 ，得到分数 (1+3+2) * min(2,3,4) = 12 。
- 选择下标 1 ，2 和 3 ，得到分数 (3+3+2) * min(1,3,4) = 8 。
所以最大分数为 12 。
示例 2：

输入：nums1 = [4,2,3,1,1], nums2 = [7,5,10,9,6], k = 1
输出：30
解释：
选择下标 2 最优：nums1[2] * nums2[2] = 3 * 10 = 30 是最大可能分数。


提示：

n == nums1.length == nums2.length
1 <= n <= 105
0 <= nums1[i], nums2[j] <= 105
1 <= k <= n
*/

#include <iostream>
#include <algorithm>
#include <queue>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    long long maxScore(vector<int>& nums1, vector<int>& nums2, int k) {
        long long sum = 0;
        int i, size = nums1.size();
        vector<pair<int, int>> nums(size);
        priority_queue<int, vector<int>, greater<int>> q;

        for (i = 0; i < size; ++i) {
            nums[i] = { nums2[i],nums1[i] };
        }

        sort(nums.begin(), nums.end());

        for (i = size - 1; i > size - 1 - k; --i) {
            sum += nums[i].second;
            q.push(nums[i].second);
        }

        long long mxScore = sum * nums[i + 1].first;

        for (; i >= 0; --i) {
            sum += nums[i].second;
            q.push(nums[i].second);
            sum -= q.top();
            q.pop();
            mxScore = max(mxScore, sum * nums[i].first);
        }

        return mxScore;
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<int> nums1 = { 1,3,3,2 };
    vector<int> nums2 = { 2,1,3,4 };
    check.checkLongLong(12, o.maxScore(nums1, nums2, 3));

    nums1 = { 4,2,3,1,1 };
    nums2 = { 7,5,10,9,6 };
    check.checkLongLong(30, o.maxScore(nums1, nums2, 1));

    nums1 = { 4,2,3,1,1 };
    nums2 = { 7,5,10,9,6 };
    check.checkLongLong(55, o.maxScore(nums1, nums2, 5));
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
