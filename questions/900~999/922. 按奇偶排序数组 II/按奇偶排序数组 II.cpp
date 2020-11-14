/* 按奇偶排序数组 II.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给定一个非负整数数组 A， A 中一半整数是奇数，一半整数是偶数。

对数组进行排序，以便当 A[i] 为奇数时，i 也是奇数；当 A[i] 为偶数时， i 也是偶数。

你可以返回任何满足上述条件的数组作为答案。

 

示例：

输入：[4,2,5,7]
输出：[4,5,2,7]
解释：[4,7,2,5]，[2,5,4,7]，[2,7,4,5] 也会被接受。
 

提示：

2 <= A.length <= 20000
A.length % 2 == 0
0 <= A[i] <= 1000

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/sort-array-by-parity-ii
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    vector<int> sortArrayByParityII(vector<int>& A) {
        int evenIndex = 0, oddIndex = 1, len = A.size(), n = A[0];

        while ((evenIndex < len) && (oddIndex < len)) {
            while ((evenIndex < len) && (A[evenIndex] % 2 == 0)) {
                evenIndex += 2;
            }

            while ((oddIndex < len) && (A[oddIndex] % 2 == 1)) {
                oddIndex += 2;
            }

            if ((evenIndex < len) && (oddIndex < len)) {
                swap(A[evenIndex], A[oddIndex]);
                evenIndex += 2;
                oddIndex += 2;
            }
        }

        return A;
    }
};

int main()
{
    Solution o;
    CheckResult check;

    vector<int> A = { 4,2,5,7 };
    vector<int> actual = o.sortArrayByParityII(A);
    vector<int> expected = { 4,5,2,7 };
    check.checkIntVector(expected, actual);

    A = { 2,5 };
    actual = o.sortArrayByParityII(A);
    expected = { 2,5 };
    check.checkIntVector(expected, actual);

    A = { 5,2 };
    actual = o.sortArrayByParityII(A);
    expected = { 2,5 };
    check.checkIntVector(expected, actual);

    A = { 0,2,4,6,8,1,3,5,7,9 };
    actual = o.sortArrayByParityII(A);
    expected = { 0,3,4,7,8,1,2,5,6,9 };
    check.checkIntVector(expected, actual);

    A = { 0,1,2,3,4,5,6,7,8,9 };
    actual = o.sortArrayByParityII(A);
    expected = { 0,1,2,3,4,5,6,7,8,9 };
    check.checkIntVector(expected, actual);

    A = { 1,2,3,4,5,6,7,8,9,0 };
    actual = o.sortArrayByParityII(A);
    expected = { 2,1,4,3,6,5,8,7,0,9 };
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
