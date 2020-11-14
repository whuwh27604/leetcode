/* 有序数组的平方.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给定一个按非递减顺序排序的整数数组 A，返回每个数字的平方组成的新数组，要求也按非递减顺序排序。

 

示例 1：

输入：[-4,-1,0,3,10]
输出：[0,1,9,16,100]
示例 2：

输入：[-7,-3,2,3,11]
输出：[4,9,9,49,121]
 

提示：

1 <= A.length <= 10000
-10000 <= A[i] <= 10000
A 已按非递减顺序排序。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/squares-of-a-sorted-array
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    vector<int> sortedSquares(vector<int>& A) {
        int i = 0, j = 0, size = A.size();
        for (i = 0; i < size && A[i] < 0; ++i) {}

        int negativeIndex = i - 1, positiveIndex = i;
        vector<int> ans(size, 0);

        while ((negativeIndex >= 0) && (positiveIndex < size)) {
            int m = A[negativeIndex] * A[negativeIndex];
            int n = A[positiveIndex] * A[positiveIndex];
            if (m < n) {
                ans[j++] = m;
                --negativeIndex;
            }
            else {
                ans[j++] = n;
                ++positiveIndex;
            }
        }

        for (; positiveIndex < size; ++positiveIndex) {
            ans[j++] = A[positiveIndex] * A[positiveIndex];
        }

        for (; negativeIndex >= 0; --negativeIndex) {
            ans[j++] = A[negativeIndex] * A[negativeIndex];
        }

        return ans;
    }
};

int main()
{
    Solution o;
    CheckResult check;

    vector<int> A = { -4,-1,0,3,10 };
    vector<int> actual = o.sortedSquares(A);
    vector<int> expected = { 0,1,9,16,100 };
    check.checkIntVector(expected, actual);

    A = { -7,-3,2,3,11 };
    actual = o.sortedSquares(A);
    expected = { 4,9,9,49,121 };
    check.checkIntVector(expected, actual);

    A = { -7 };
    actual = o.sortedSquares(A);
    expected = { 49 };
    check.checkIntVector(expected, actual);

    A = { 0 };
    actual = o.sortedSquares(A);
    expected = { 0 };
    check.checkIntVector(expected, actual);

    A = { 5 };
    actual = o.sortedSquares(A);
    expected = { 25 };
    check.checkIntVector(expected, actual);

    A = { -7,-5 };
    actual = o.sortedSquares(A);
    expected = { 25,49 };
    check.checkIntVector(expected, actual);

    A = { 5,7 };
    actual = o.sortedSquares(A);
    expected = { 25,49 };
    check.checkIntVector(expected, actual);

    A = { -7,0 };
    actual = o.sortedSquares(A);
    expected = { 0,49 };
    check.checkIntVector(expected, actual);

    A = { -7,5 };
    actual = o.sortedSquares(A);
    expected = { 25,49 };
    check.checkIntVector(expected, actual);

    A = { -7,-5,-3,-1,0,2,4,6,8 };
    actual = o.sortedSquares(A);
    expected = { 0,1,4,9,16,25,36,49,64 };
    check.checkIntVector(expected, actual);

    A = { -7,-5,-3,-1,2,4,6,8 };
    actual = o.sortedSquares(A);
    expected = { 1,4,9,16,25,36,49,64 };
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
