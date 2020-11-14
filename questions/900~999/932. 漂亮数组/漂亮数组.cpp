/* 漂亮数组.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
对于某些固定的 N，如果数组 A 是整数 1, 2, ..., N 组成的排列，使得：

对于每个 i < j，都不存在 k 满足 i < k < j 使得 A[k] * 2 = A[i] + A[j]。

那么数组 A 是漂亮数组。

 

给定 N，返回任意漂亮数组 A（保证存在一个）。

 

示例 1：

输入：4
输出：[2,1,4,3]
示例 2：

输入：5
输出：[3,1,2,5,4]
 

提示：

1 <= N <= 1000

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/beautiful-array
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    vector<int> beautifulArray(int N) {
        /* if [A0,A1...An] is beautiful, then :
           1, [2*A0,2*A1...2*An] is beautiful
           2, [A0+b,A1+b...An+b] is beautiful, and so [2*A0+b,2*A1+b...2*An+b] is beautiful
           3, delete any Ax is beautiful
           4, if [A0,A1...An] is beautiful, Ax is odd; [B0,B1...Bn] is beautiful, Bx is even; then [A0,A1...An,B0,B1...Bn] is beautiful,
              because any Ax + any Bx is odd, so there is no num*2 is odd */
        vector<int> beautifulArr(N, 0);
        vector<int> arr(1024, 0);
        arr[0] = 1;
        int len = 1, i, j = 0;

        while (len < N) {
            for (i = 0; i < len; ++i) {
                arr[len + i] = arr[i] * 2;
                arr[i] = arr[i] * 2 - 1;
            }

            len *= 2;
        }

        for (i = 0; i < 1024 && j < N; ++i) {
            if (arr[i] <= N) {
                beautifulArr[j++] = arr[i];
            }
        }

        return beautifulArr;
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<int> actual = o.beautifulArray(1);
    vector<int> expected = { 1 };
    check.checkIntVector(expected, actual);

    actual = o.beautifulArray(2);
    expected = { 1,2 };
    check.checkIntVector(expected, actual);

    actual = o.beautifulArray(3);
    expected = { 1,3,2 };
    check.checkIntVector(expected, actual);

    actual = o.beautifulArray(4);
    expected = { 1,3,2,4 };
    check.checkIntVector(expected, actual);

    actual = o.beautifulArray(5);
    expected = { 1,5,3,2,4 };
    check.checkIntVector(expected, actual);

    actual = o.beautifulArray(6);
    expected = { 1,5,3,2,6,4 };
    check.checkIntVector(expected, actual);

    actual = o.beautifulArray(7);
    expected = { 1,5,3,7,2,6,4 };
    check.checkIntVector(expected, actual);

    actual = o.beautifulArray(8);
    expected = { 1,5,3,7,2,6,4,8 };
    check.checkIntVector(expected, actual);

    actual = o.beautifulArray(9);
    expected = { 1,9,5,3,7,2,6,4,8 };
    check.checkIntVector(expected, actual);

    actual = o.beautifulArray(10);
    expected = { 1,9,5,3,7,2,10,6,4,8 };
    check.checkIntVector(expected, actual);

    actual = o.beautifulArray(11);
    expected = { 1,9,5,3,11,7,2,10,6,4,8 };
    check.checkIntVector(expected, actual);

    actual = o.beautifulArray(12);
    expected = { 1,9,5,3,11,7,2,10,6,4,12,8 };
    check.checkIntVector(expected, actual);

    actual = o.beautifulArray(13);
    expected = { 1,9,5,13,3,11,7,2,10,6,4,12,8 };
    check.checkIntVector(expected, actual);

    actual = o.beautifulArray(14);
    expected = { 1,9,5,13,3,11,7,2,10,6,14,4,12,8 };
    check.checkIntVector(expected, actual);

    actual = o.beautifulArray(15);
    expected = { 1,9,5,13,3,11,7,15,2,10,6,14,4,12,8 };
    check.checkIntVector(expected, actual);

    actual = o.beautifulArray(16);
    expected = { 1,9,5,13,3,11,7,15,2,10,6,14,4,12,8,16 };
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
