/* 按奇偶排序数组.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给定一个非负整数数组 A，返回一个数组，在该数组中， A 的所有偶数元素之后跟着所有奇数元素。

你可以返回满足此条件的任何数组作为答案。

 

示例：

输入：[3,1,2,4]
输出：[2,4,3,1]
输出 [4,2,3,1]，[2,4,1,3] 和 [4,2,1,3] 也会被接受。
 

提示：

1 <= A.length <= 5000
0 <= A[i] <= 5000

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/sort-array-by-parity
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& A) {
        int headIndex = -1, len = A.size(), tailIndex = len;

        while (1) {
            nextOddNumber(A, headIndex, len);
            prevEvenNumber(A, tailIndex);

            if (headIndex > tailIndex) {
                break;
            }

            swap(A[headIndex], A[tailIndex]);
        }

        return A;
    }

    void nextOddNumber(vector<int>& A, int& headIndex, int len) {
        headIndex++;
        while ((A[headIndex] % 2) == 0) {
            headIndex++;
            if (headIndex == len) {
                break;
            }
        }
    }

    void prevEvenNumber(vector<int>& A, int& TailIndex) {
        TailIndex--;
        while ((A[TailIndex] % 2) == 1) {
            TailIndex--;
            if (TailIndex == -1) {
                break;
            }
        }
    }
};

int main()
{
    Solution o;
    CheckResult check;

    vector<int> A = { 3,1,2,4 };
    vector<int> actual = o.sortArrayByParity(A);
    vector<int> expected = { 4,2,1,3 };
    check.checkIntVector(expected, actual);
    
    A = { 3 };
    actual = o.sortArrayByParity(A);
    expected = { 3 };
    check.checkIntVector(expected, actual);

    A = { 4 };
    actual = o.sortArrayByParity(A);
    expected = { 4 };
    check.checkIntVector(expected, actual);

    A = { 3,6 };
    actual = o.sortArrayByParity(A);
    expected = { 6,3 };
    check.checkIntVector(expected, actual);

    A = { 6,3 };
    actual = o.sortArrayByParity(A);
    expected = { 6,3 };
    check.checkIntVector(expected, actual);

    A = { 3,0,6 };
    actual = o.sortArrayByParity(A);
    expected = { 6,0,3 };
    check.checkIntVector(expected, actual);

    A = { 3,1,6 };
    actual = o.sortArrayByParity(A);
    expected = { 6,1,3 };
    check.checkIntVector(expected, actual);

    A = { 3,5,7 };
    actual = o.sortArrayByParity(A);
    expected = { 3,5,7 };
    check.checkIntVector(expected, actual);

    A = { 2,4 };
    actual = o.sortArrayByParity(A);
    expected = { 2,4 };
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
