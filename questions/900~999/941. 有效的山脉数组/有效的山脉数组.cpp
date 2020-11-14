/* 有效的山脉数组.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给定一个整数数组 A，如果它是有效的山脉数组就返回 true，否则返回 false。

让我们回顾一下，如果 A 满足下述条件，那么它是一个山脉数组：

A.length >= 3
在 0 < i < A.length - 1 条件下，存在 i 使得：
A[0] < A[1] < ... A[i-1] < A[i]
A[i] > A[i+1] > ... > A[A.length - 1]
 



 

示例 1：

输入：[2,1]
输出：false
示例 2：

输入：[3,5,5]
输出：false
示例 3：

输入：[0,3,2,1]
输出：true
 

提示：

0 <= A.length <= 10000
0 <= A[i] <= 10000

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/valid-mountain-array
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    bool validMountainArray(vector<int>& A) {
        int i, size = A.size();
        if (size < 3) {
            return false;
        }

        for (i = 1; i < size && A[i - 1] < A[i]; ++i) {}

        if (i == 1 || i == size) {
            return false;
        }

        for (; i < size && A[i - 1] > A[i]; ++i) {}

        return i == size;
    }
};

int main()
{
    Solution o;
    CheckResult check;

    vector<int> A = { 2,1 };
    check.checkBool(false, o.validMountainArray(A));

    A = { 3,5,5 };
    check.checkBool(false, o.validMountainArray(A));

    A = { 3,3,5 };
    check.checkBool(false, o.validMountainArray(A));

    A = { 3,5,6 };
    check.checkBool(false, o.validMountainArray(A));

    A = { 5,5,3 };
    check.checkBool(false, o.validMountainArray(A));

    A = { 5,3,3 };
    check.checkBool(false, o.validMountainArray(A));

    A = { 5,3,1 };
    check.checkBool(false, o.validMountainArray(A));

    A = { 5,3,5 };
    check.checkBool(false, o.validMountainArray(A));

    A = { 0,3,2,1 };
    check.checkBool(true, o.validMountainArray(A));

    A = { 0,1,3,2 };
    check.checkBool(true, o.validMountainArray(A));

    A = {  };
    check.checkBool(false, o.validMountainArray(A));

    A = { 3 };
    check.checkBool(false, o.validMountainArray(A));

    A = { 1,3,2,2 };
    check.checkBool(false, o.validMountainArray(A));

    A = { 1,1,3,2 };
    check.checkBool(false, o.validMountainArray(A));

    A = { 1,3,2,4 };
    check.checkBool(false, o.validMountainArray(A));

    A = { 1,3,3,2 };
    check.checkBool(false, o.validMountainArray(A));

    A = { 1,7,9,5,4,1,2 };
    check.checkBool(false, o.validMountainArray(A));
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
