/* 山峰数组的顶部.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
符合下列属性的数组 arr 称为 山峰数组（山脉数组） ：

arr.length >= 3
存在 i（0 < i < arr.length - 1）使得：
arr[0] < arr[1] < ... arr[i-1] < arr[i]
arr[i] > arr[i+1] > ... > arr[arr.length - 1]
给定由整数组成的山峰数组 arr ，返回任何满足 arr[0] < arr[1] < ... arr[i - 1] < arr[i] > arr[i + 1] > ... > arr[arr.length - 1] 的下标 i ，即山峰顶部。

 

示例 1：

输入：arr = [0,1,0]
输出：1
示例 2：

输入：arr = [1,3,5,4,2]
输出：2
示例 3：

输入：arr = [0,10,5,2]
输出：1
示例 4：

输入：arr = [3,4,5,1]
输出：2
示例 5：

输入：arr = [24,69,100,99,79,78,67,36,26,19]
输出：2
 

提示：

3 <= arr.length <= 104
0 <= arr[i] <= 106
题目数据保证 arr 是一个山脉数组
 

进阶：很容易想到时间复杂度 O(n) 的解决方案，你可以设计一个 O(log(n)) 的解决方案吗？

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/B1IidL
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int left = 0, right = arr.size() - 1, middle = (left + right) / 2;

        while (arr[middle] < arr[middle - 1] || arr[middle] < arr[middle + 1]) {
            if (arr[middle] > arr[middle - 1]) {
                left = middle;
            }
            else {
                right = middle;
            }

            middle = (left + right) / 2;
        }

        return middle;
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<int> arr = { 0,1,0 };
    check.checkInt(1, o.peakIndexInMountainArray(arr));

    arr = { 0,2,1,0 };
    check.checkInt(1, o.peakIndexInMountainArray(arr));

    arr = { 0,10,5,2 };
    check.checkInt(1, o.peakIndexInMountainArray(arr));

    arr = { 3,4,5,1 };
    check.checkInt(2, o.peakIndexInMountainArray(arr));

    arr = { 24,69,100,99,79,78,67,36,26,19 };
    check.checkInt(2, o.peakIndexInMountainArray(arr));

    arr = { 3,5,3,2,0 };
    check.checkInt(1, o.peakIndexInMountainArray(arr));
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
