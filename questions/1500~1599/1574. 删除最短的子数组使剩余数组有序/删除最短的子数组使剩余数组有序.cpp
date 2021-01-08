/* 删除最短的子数组使剩余数组有序.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你一个整数数组 arr ，请你删除一个子数组（可以为空），使得 arr 中剩下的元素是 非递减 的。

一个子数组指的是原数组中连续的一个子序列。

请你返回满足题目要求的最短子数组的长度。

 

示例 1：

输入：arr = [1,2,3,10,4,2,3,5]
输出：3
解释：我们需要删除的最短子数组是 [10,4,2] ，长度为 3 。剩余元素形成非递减数组 [1,2,3,3,5] 。
另一个正确的解为删除子数组 [3,10,4] 。
示例 2：

输入：arr = [5,4,3,2,1]
输出：4
解释：由于数组是严格递减的，我们只能保留一个元素。所以我们需要删除长度为 4 的子数组，要么删除 [5,4,3,2]，要么删除 [4,3,2,1]。
示例 3：

输入：arr = [1,2,3]
输出：0
解释：数组已经是非递减的了，我们不需要删除任何元素。
示例 4：

输入：arr = [1]
输出：0
 

提示：

1 <= arr.length <= 10^5
0 <= arr[i] <= 10^9

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/shortest-subarray-to-be-removed-to-make-array-sorted
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <algorithm>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int findLengthOfShortestSubarray(vector<int>& arr) {
        /* 1、arr分为3部分：A[a1,a2...an]递增，B[b1,b2...bn]乱序，C[c1,c2...cn]递增
           2、由于只能删除子数组，即删除的部分是连续的，这意味着B要全部被删除，然后还要删除部分A和C
           3、使用双指针遍历an,an-1...c1,c2，找到最短的子数组 */
        int i, size = arr.size();

        for (i = 1; i < size && arr[i] >= arr[i - 1]; ++i) {}

        if (i == size) {  // 已经是非递减序列，不需要删除子数组
            return 0;
        }
        int maxA = i - 1;

        for (i = size - 2; i >= 0 && arr[i] <= arr[i + 1]; --i) {}
        int minC = i + 1;

        int indexA = maxA, indexC = minC;

        for (; indexC < size && arr[indexC] < arr[indexA]; ++indexC) {}  // 先看看如果保留arr[maxA]，c在哪里
        int minSubarr = --indexC - indexA;

        for (indexA = maxA - 1; indexA >= 0 && arr[indexA] > arr[minC]; --indexA) {  // 然后遍历arr[maxA-1],arr[maxA-2]...直到最后一个大于arr[minC]的数
            for (; indexC >= minC && arr[indexC] >= arr[indexA]; --indexC) {}  // 查找保留arr[a]的情况下，c在哪里
            minSubarr = min(minSubarr, indexC - indexA);
        }

        return min(minSubarr, minC - indexA - 1);  // 最后还要比较一下保留arr[minC]的情况
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<int> arr = { 1,2,3,10,4,2,3,5 };
    check.checkInt(3, o.findLengthOfShortestSubarray(arr));

    arr = { 5,4,3,2,1 };
    check.checkInt(4, o.findLengthOfShortestSubarray(arr));

    arr = { 1,2,3 };
    check.checkInt(0, o.findLengthOfShortestSubarray(arr));

    arr = { 1 };
    check.checkInt(0, o.findLengthOfShortestSubarray(arr));

    arr = { 1,2,2,3,3,78,5,2,3,2,4,7 };
    check.checkInt(5, o.findLengthOfShortestSubarray(arr));

    arr = { 13,0,14,7,18,18,18,16,8,15,20 };
    check.checkInt(8, o.findLengthOfShortestSubarray(arr));

    arr = { 1,5,5,5,10,3,5,5,5,20 };
    check.checkInt(2, o.findLengthOfShortestSubarray(arr));

    arr = { 1,2,3,3,100,2,3,4,5 };
    check.checkInt(2, o.findLengthOfShortestSubarray(arr));

    arr = { 1,3,4,5,4,3,5,4,5,6 };
    check.checkInt(4, o.findLengthOfShortestSubarray(arr));

    arr = { 1,3,4,10,4,3,5,4,5,6 };
    check.checkInt(4, o.findLengthOfShortestSubarray(arr));

    arr = { 1,3,4,5,4,10,9,8,9,10 };
    check.checkInt(3, o.findLengthOfShortestSubarray(arr));

    arr = { 11,13,14,15,4,3,5,4,5,6 };
    check.checkInt(6, o.findLengthOfShortestSubarray(arr));

    arr = { 11,13,14,15,4,5,5,5,5,6 };
    check.checkInt(4, o.findLengthOfShortestSubarray(arr));

    arr = { 11,3,4,5,5,5,6 };
    check.checkInt(1, o.findLengthOfShortestSubarray(arr));
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
