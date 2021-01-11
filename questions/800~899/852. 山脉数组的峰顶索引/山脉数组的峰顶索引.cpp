/* 山脉数组的峰顶索引.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
我们把符合下列属性的数组 A 称作山脉：

A.length >= 3
存在 0 < i < A.length - 1 使得A[0] < A[1] < ... A[i-1] < A[i] > A[i+1] > ... > A[A.length - 1]
给定一个确定为山脉的数组，返回任何满足 A[0] < A[1] < ... A[i-1] < A[i] > A[i+1] > ... > A[A.length - 1] 的 i 的值。

 

示例 1：

输入：[0,1,0]
输出：1
示例 2：

输入：[0,2,1,0]
输出：1
 

提示：

3 <= A.length <= 10000
0 <= A[i] <= 10^6
A 是如上定义的山脉

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/peak-index-in-a-mountain-array
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int peakIndexInMountainArray(vector<int>& A) {
        return peakIndex(A, 0, A.size() - 1);
    }

    int peakIndex(vector<int>& A, int left, int right) {
        int middle = ((left + right) / 2);
        if ((A[middle] > A[middle - 1]) && (A[middle] > A[middle + 1])) {
            return middle;
        }

        if (A[middle] < A[middle + 1]) {
            return peakIndex(A, middle + 1, right);
        }

        return peakIndex(A, left, middle - 1);
    }
};

int main()
{
    Solution o;
    CheckResult check;

    vector<int> A = { 0,1,0 };
    check.checkInt(1, o.peakIndexInMountainArray(A));

    A = { 0,2,1,0 };
    check.checkInt(1, o.peakIndexInMountainArray(A));
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
