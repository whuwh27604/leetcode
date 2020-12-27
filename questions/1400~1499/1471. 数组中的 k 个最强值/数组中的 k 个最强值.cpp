/* 数组中的 k 个最强值.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你一个整数数组 arr 和一个整数 k 。

设 m 为数组的中位数，只要满足下述两个前提之一，就可以判定 arr[i] 的值比 arr[j] 的值更强：

 |arr[i] - m| > |arr[j] - m|
 |arr[i] - m| == |arr[j] - m|，且 arr[i] > arr[j]
请返回由数组中最强的 k 个值组成的列表。答案可以以 任意顺序 返回。

中位数 是一个有序整数列表中处于中间位置的值。形式上，如果列表的长度为 n ，那么中位数就是该有序列表（下标从 0 开始）中位于 ((n - 1) / 2) 的元素。

例如 arr = [6, -3, 7, 2, 11]，n = 5：数组排序后得到 arr = [-3, 2, 6, 7, 11] ，数组的中间位置为 m = ((5 - 1) / 2) = 2 ，中位数 arr[m] 的值为 6 。
例如 arr = [-7, 22, 17, 3]，n = 4：数组排序后得到 arr = [-7, 3, 17, 22] ，数组的中间位置为 m = ((4 - 1) / 2) = 1 ，中位数 arr[m] 的值为 3 。
 

示例 1：

输入：arr = [1,2,3,4,5], k = 2
输出：[5,1]
解释：中位数为 3，按从强到弱顺序排序后，数组变为 [5,1,4,2,3]。最强的两个元素是 [5, 1]。[1, 5] 也是正确答案。
注意，尽管 |5 - 3| == |1 - 3| ，但是 5 比 1 更强，因为 5 > 1 。
示例 2：

输入：arr = [1,1,3,5,5], k = 2
输出：[5,5]
解释：中位数为 3, 按从强到弱顺序排序后，数组变为 [5,5,1,1,3]。最强的两个元素是 [5, 5]。
示例 3：

输入：arr = [6,7,11,7,6,8], k = 5
输出：[11,8,6,6,7]
解释：中位数为 7, 按从强到弱顺序排序后，数组变为 [11,8,6,6,7,7]。
[11,8,6,6,7] 的任何排列都是正确答案。
示例 4：

输入：arr = [6,-3,7,2,11], k = 3
输出：[-3,11,2]
示例 5：

输入：arr = [-7,22,17,3], k = 2
输出：[22,17]
 

提示：

1 <= arr.length <= 10^5
-10^5 <= arr[i] <= 10^5
1 <= k <= arr.length

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/the-k-strongest-values-in-an-array
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <algorithm>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    vector<int> getStrongest(vector<int>& arr, int k) {        
        sort(arr.begin(), arr.end());

        int size = arr.size(), median = arr[(size - 1) / 2];
        int i = 0, left = 0, right = size - 1;
        vector<int> kStrongest(k);

        for (i = 0; i < k; ++i) {
            if (abs(arr[left] - median) > abs(arr[right] - median)) {
                kStrongest[i] = arr[left++];
            }
            else {
                kStrongest[i] = arr[right--];
            }
        }

        return kStrongest;
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<int> arr = { 1,2,3,4,5 };
    vector<int> actual = o.getStrongest(arr, 2);
    vector<int> expected = { 5,1 };
    check.checkIntVector(expected, actual);

    arr = { 1,2,3,4,5 };
    actual = o.getStrongest(arr, 5);
    expected = { 5,1,4,2,3 };
    check.checkIntVector(expected, actual);

    arr = { 1,1,3,5,5 };
    actual = o.getStrongest(arr, 2);
    expected = { 5,5 };
    check.checkIntVector(expected, actual);

    arr = { 6,7,11,7,6,8 };
    actual = o.getStrongest(arr, 5);
    expected = { 11,8,6,6,7 };
    check.checkIntVector(expected, actual);

    arr = { 6,-3,7,2,11 };
    actual = o.getStrongest(arr, 3);
    expected = { -3,11,2 };
    check.checkIntVector(expected, actual);

    arr = { -7,22,17,3 };
    actual = o.getStrongest(arr, 2);
    expected = { 22,17 };
    check.checkIntVector(expected, actual);

    arr = { -7 };
    actual = o.getStrongest(arr, 1);
    expected = { -7 };
    check.checkIntVector(expected, actual);
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
