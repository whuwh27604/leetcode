/* 最长重复子数组.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给两个整数数组 A 和 B ，返回两个数组中公共的、长度最长的子数组的长度。

示例 1:

输入:
A: [1,2,3,2,1]
B: [3,2,1,4,7]
输出: 3
解释:
长度最长的公共子数组是 [3, 2, 1]。
说明:

1 <= len(A), len(B) <= 1000
0 <= A[i], B[i] < 100

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/maximum-length-of-repeated-subarray
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int findLength(vector<int>& A, vector<int>& B) {
        int i, j, sizeA = A.size(), sizeB = B.size(), maxLength = 0;
        vector<vector<int>> dp(sizeA + 1, vector<int>(sizeB + 1, 0));

        for (i = sizeA - 1; i >= 0; i--) {
            for (j = sizeB - 1; j >= 0; j--) {
                dp[i][j] = (A[i] == B[j]) ? (dp[i + 1][j + 1] + 1) : 0;  // dp[i][j]表示A[i,i+1,...sizeA-1]和B[j,j+1,...sizeB-1]这两个数组的最大公共前缀
                maxLength = (maxLength > dp[i][j]) ? maxLength : dp[i][j];
            }
        }

        return maxLength;
    }
};

int main()
{
    Solution o;
    CheckResult check;

    vector<int> A = {};
    vector<int> B = {};
    check.checkInt(0, o.findLength(A, B));

    A = {  };
    B = { 2 };
    check.checkInt(0, o.findLength(A, B));
    
    A = { 1 };
    B = { 2 };
    check.checkInt(0, o.findLength(A, B));

    A = { 2 };
    B = { 2 };
    check.checkInt(1, o.findLength(A, B));

    A = { 1,2 };
    B = { 1 };
    check.checkInt(1, o.findLength(A, B));

    A = { 1,2 };
    B = { 2 };
    check.checkInt(1, o.findLength(A, B));

    A = { 1,2 };
    B = { 3 };
    check.checkInt(0, o.findLength(A, B));

    A = { 1,2 };
    B = { 2,3 };
    check.checkInt(1, o.findLength(A, B));

    A = { 1,2 };
    B = { 1,2 };
    check.checkInt(2, o.findLength(A, B));

    A = { 1,2 };
    B = { 3,4 };
    check.checkInt(0, o.findLength(A, B));

    A = { 1,2,3 };
    B = { 3 };
    check.checkInt(1, o.findLength(A, B));

    A = { 1,2,3 };
    B = { 2,3 };
    check.checkInt(2, o.findLength(A, B));

    A = { 1,2,3 };
    B = { 1,2,3 };
    check.checkInt(3, o.findLength(A, B));

    A = { 1,2,3 };
    B = { 4,1,2,3 };
    check.checkInt(3, o.findLength(A, B));

    A = { 1,2,3,2,1 };
    B = { 3,2,1,4,7 };
    check.checkInt(3, o.findLength(A, B));
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
