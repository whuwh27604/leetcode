/* 大小为 K 且平均值大于等于阈值的子数组数目.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你一个整数数组 arr 和两个整数 k 和 threshold 。

请你返回长度为 k 且平均值大于等于 threshold 的子数组数目。

 

示例 1：

输入：arr = [2,2,2,2,5,5,5,8], k = 3, threshold = 4
输出：3
解释：子数组 [2,5,5],[5,5,5] 和 [5,5,8] 的平均值分别为 4，5 和 6 。其他长度为 3 的子数组的平均值都小于 4 （threshold 的值)。
示例 2：

输入：arr = [1,1,1,1,1], k = 1, threshold = 0
输出：5
示例 3：

输入：arr = [11,13,17,23,29,31,7,5,2,3], k = 3, threshold = 5
输出：6
解释：前 6 个长度为 3 的子数组平均值都大于 5 。注意平均值不是整数。
示例 4：

输入：arr = [7,7,7,7,7,7,7], k = 7, threshold = 7
输出：1
示例 5：

输入：arr = [4,4,4,4], k = 4, threshold = 1
输出：1
 

提示：

1 <= arr.length <= 10^5
1 <= arr[i] <= 10^4
1 <= k <= arr.length
0 <= threshold <= 10^4

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/number-of-sub-arrays-of-size-k-and-average-greater-than-or-equal-to-threshold
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int numOfSubarrays(vector<int>& arr, int k, int threshold) {
        int i, size = arr.size(), sum = 0, minSum = k * threshold;

        for (i = 0; i < k; ++i) {
            sum += arr[i];
        }

        int count = sum >= minSum ? 1 : 0;

        for (; i < size; ++i) {
            sum = sum - arr[i - k] + arr[i];
            count += (sum >= minSum ? 1 : 0);
        }

        return count;
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<int> arr = { 2,2,2,2,5,5,5,8 };
    check.checkInt(3, o.numOfSubarrays(arr, 3, 4));

    arr = { 1,1,1,1,1 };
    check.checkInt(5, o.numOfSubarrays(arr, 1, 0));

    arr = { 11,13,17,23,29,31,7,5,2,3 };
    check.checkInt(6, o.numOfSubarrays(arr, 3, 5));

    arr = { 7,7,7,7,7,7,7 };
    check.checkInt(1, o.numOfSubarrays(arr, 7, 7));

    arr = { 4,4,4,4 };
    check.checkInt(1, o.numOfSubarrays(arr, 4, 1));
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
