/* 使差值相等的最少数组改动次数.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你一个长度为 n 的整数数组 nums ，n 是 偶数 ，同时给你一个整数 k 。

你可以对数组进行一些操作。每次操作中，你可以将数组中 任一 元素替换为 0 到 k 之间的 任一 整数。

执行完所有操作以后，你需要确保最后得到的数组满足以下条件：

存在一个整数 X ，满足对于所有的 (0 <= i < n) 都有 abs(a[i] - a[n - i - 1]) = X 。
请你返回满足以上条件 最少 修改次数。



示例 1：

输入：nums = [1,0,1,2,4,3], k = 4

输出：2

解释：
我们可以执行以下操作：

将 nums[1] 变为 2 ，结果数组为 nums = [1,2,1,2,4,3] 。
将 nums[3] 变为 3 ，结果数组为 nums = [1,2,1,3,4,3] 。
整数 X 为 2 。

示例 2：

输入：nums = [0,1,2,3,3,6,5,4], k = 6

输出：2

解释：
我们可以执行以下操作：

将 nums[3] 变为 0 ，结果数组为 nums = [0,1,2,0,3,6,5,4] 。
将 nums[4] 变为 4 ，结果数组为 nums = [0,1,2,0,4,6,5,4] 。
整数 X 为 4 。



提示：

2 <= n == nums.length <= 105
n 是偶数。
0 <= nums[i] <= k <= 105
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int minChanges(vector<int>& nums, int k) {
        vector<int> diff(k + 2, 0);
        int n = (int)nums.size();

        for (int i = 0; i < n / 2; ++i) {
            int p = min(nums[i], nums[n - i - 1]);
            int q = max(nums[i], nums[n - i - 1]);
            diff[0] += 1;  // 对于[0, p, q, k]来说，x = q - p需要修改0次，x∈[0, q - p - 1]需要修改1次
            diff[q - p] -= 1;
            int max1 = max(q, k - p);
            diff[q - p + 1] += 1;  // x∈[q - p + 1, max1]需要修改1次
            diff[max1 + 1] -= 1;
            diff[max1 + 1] += 2;  // x∈[max1 + 1, k]需要修改2次
            diff[k + 1] -= 2;
        }

        int ans = diff[0];
        for (int x = 1; x <= k; ++x) {
            diff[x] += diff[x - 1];
            ans = min(ans, diff[x]);
        }

        return ans;
    }
};

int main()
{
    Solution o;
    CheckResult check;

    vector<int> nums = { 1,0,1,2,4,3 };
    check.checkInt(2, o.minChanges(nums, 4));

    nums = { 0,1,2,3,3,6,5,4 };
    check.checkInt(2, o.minChanges(nums, 6));
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
