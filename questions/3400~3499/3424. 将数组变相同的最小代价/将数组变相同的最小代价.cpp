/* 将数组变相同的最小代价.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你两个长度都为 n 的整数数组 arr 和 brr 以及一个整数 k 。你可以对 arr 执行以下操作任意次：

将 arr 分割成若干个 连续的 子数组，并将这些子数组按任意顺序重新排列。这个操作的代价为 k 。
选择 arr 中的任意一个元素，将它增加或者减少一个正整数 x 。这个操作的代价为 x 。

请你返回将 arr 变为 brr 的 最小 总代价。

子数组 是一个数组中一段连续 非空 的元素序列。



示例 1：

输入：arr = [-7,9,5], brr = [7,-2,-5], k = 2

输出：13

解释：

将 arr 分割成两个连续子数组：[-7] 和 [9, 5] 然后将它们重新排列成 [9, 5, -7] ，代价为 2 。
将 arr[0] 减小 2 ，数组变为 [7, 5, -7] ，操作代价为 2 。
将 arr[1] 减小 7 ，数组变为 [7, -2, -7] ，操作代价为 7 。
将 arr[2] 增加 2 ，数组变为 [7, -2, -5] ，操作代价为 2 。
将两个数组变相等的总代价为 2 + 2 + 7 + 2 = 13 。

示例 2：

输入：arr = [2,1], brr = [2,1], k = 0

输出：0

解释：

由于数组已经相等，不需要进行任何操作，所以总代价为 0 。



提示：

1 <= arr.length == brr.length <= 105
0 <= k <= 2 * 1010
-105 <= arr[i] <= 105
-105 <= brr[i] <= 105
*/

#include <iostream>
#include <algorithm>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    long long minCost(vector<int>& arr, vector<int>& brr, long long k) {
        int size = (int)arr.size();
        long long cost1 = 0, cost2 = k;

        for (int i = 0; i < size; ++i) {  // 不需要调整顺序
            cost1 += abs(arr[i] - brr[i]);
        }

        sort(arr.begin(), arr.end());
        sort(brr.begin(), brr.end());

        for (int i = 0; i < size; ++i) {  // 调整顺序的开销是k
            cost2 += abs(arr[i] - brr[i]);
        }

        return min(cost1, cost2);
    }
};

int main()
{
    Solution o;
    CheckResult check;

    vector<int> arr = { -7,9,5 };
    vector<int> brr = { 7,-2,-5 };
    check.checkLongLong(13, o.minCost(arr, brr, 2));

    arr = { 2,1 };
    brr = { 2,1 };
    check.checkLongLong(0, o.minCost(arr, brr, 0));

    arr = { 2,1 };
    brr = { 2,1 };
    check.checkLongLong(0, o.minCost(arr, brr, 2));
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
