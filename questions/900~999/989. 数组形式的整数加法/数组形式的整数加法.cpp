/* 数组形式的整数加法.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
对于非负整数 X 而言，X 的数组形式是每位数字按从左到右的顺序形成的数组。例如，如果 X = 1231，那么其数组形式为 [1,2,3,1]。

给定非负整数 X 的数组形式 A，返回整数 X+K 的数组形式。

 

示例 1：

输入：A = [1,2,0,0], K = 34
输出：[1,2,3,4]
解释：1200 + 34 = 1234
示例 2：

输入：A = [2,7,4], K = 181
输出：[4,5,5]
解释：274 + 181 = 455
示例 3：

输入：A = [2,1,5], K = 806
输出：[1,0,2,1]
解释：215 + 806 = 1021
示例 4：

输入：A = [9,9,9,9,9,9,9,9,9,9], K = 1
输出：[1,0,0,0,0,0,0,0,0,0,0]
解释：9999999999 + 1 = 10000000000
 

提示：

1 <= A.length <= 10000
0 <= A[i] <= 9
0 <= K <= 10000
如果 A.length > 1，那么 A[0] != 0

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/add-to-array-form-of-integer
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <algorithm>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    vector<int> addToArrayForm(vector<int>& A, int K) {
        vector<int> vK;
        K2Vector(K, vK);

        int sizeA = A.size(), sizeK = vK.size(), sizeS = max(sizeA, sizeK) + 1;
        int i = sizeA - 1, j = sizeK - 1, k = sizeS - 1, carrier = 0, sum = 0;
        vector<int> vSum(sizeS, 0);

        for (;  i >= 0 && j >= 0; --i, --j, --k) {
            sum = A[i] + vK[j] + carrier;
            vSum[k] = sum % 10;
            carrier = sum / 10;
        }

        for (; i >= 0; --i, --k) {
            sum = A[i] + carrier;
            vSum[k] = sum % 10;
            carrier = sum / 10;
        }

        for (; j >= 0; --j, --k) {
            sum = vK[j] + carrier;
            vSum[k] = sum % 10;
            carrier = sum / 10;
        }

        vSum[0] = carrier;
        if (vSum[0] == 0) {
            vSum.erase(vSum.begin());
        }

        return vSum;
    }

    void K2Vector(int K, vector<int>& vK) {
        while (K != 0) {
            vK.push_back(K % 10);
            K /= 10;
        }

        reverse(vK.begin(), vK.end());
    }
};

int main()
{
    Solution o;
    CheckResult check;

    vector<int> A = { 1,2,0,0 };
    vector<int> actual = o.addToArrayForm(A, 34);
    vector<int> expected = { 1,2,3,4 };
    check.checkIntVector(expected, actual);

    A = { 3,4 };
    actual = o.addToArrayForm(A, 1200);
    expected = { 1,2,3,4 };
    check.checkIntVector(expected, actual);

    A = { 0 };
    actual = o.addToArrayForm(A, 0);
    expected = { 0 };
    check.checkIntVector(expected, actual);

    A = { 2 };
    actual = o.addToArrayForm(A, 0);
    expected = { 2 };
    check.checkIntVector(expected, actual);

    A = { 2,7,4 };
    actual = o.addToArrayForm(A, 181);
    expected = { 4,5,5 };
    check.checkIntVector(expected, actual);

    A = { 2,1,5 };
    actual = o.addToArrayForm(A, 806);
    expected = { 1,0,2,1 };
    check.checkIntVector(expected, actual);

    A = { 9,9,9,9,9,9,9,9,9,9 };
    actual = o.addToArrayForm(A, 1);
    expected = { 1,0,0,0,0,0,0,0,0,0,0 };
    check.checkIntVector(expected, actual);

    A = { 9,9,9,9,9,9,9,9,9,9 };
    actual = o.addToArrayForm(A, 0);
    expected = { 9,9,9,9,9,9,9,9,9,9 };
    check.checkIntVector(expected, actual);

    A = { 9,9,9,9,9,9,9,9,9,9 };
    actual = o.addToArrayForm(A, 10000);
    expected = { 1,0,0,0,0,0,0,9,9,9,9 };
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
