/* 最长的斐波那契子序列的长度.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
如果序列 X_1, X_2, ..., X_n 满足下列条件，就说它是 斐波那契式 的：

n >= 3
对于所有 i + 2 <= n，都有 X_i + X_{i+1} = X_{i+2}
给定一个严格递增的正整数数组形成序列，找到 A 中最长的斐波那契式的子序列的长度。如果一个不存在，返回  0 。

（回想一下，子序列是从原序列 A 中派生出来的，它从 A 中删掉任意数量的元素（也可以不删），而不改变其余元素的顺序。例如， [3, 5, 8] 是 [3, 4, 5, 6, 7, 8] 的一个子序列）

 

示例 1：

输入: [1,2,3,4,5,6,7,8]
输出: 5
解释:
最长的斐波那契式子序列为：[1,2,3,5,8] 。
示例 2：

输入: [1,3,7,11,12,14,18]
输出: 3
解释:
最长的斐波那契式子序列有：
[1,11,12]，[3,11,14] 以及 [7,11,18] 。
 

提示：

3 <= A.length <= 1000
1 <= A[0] < A[1] < ... < A[A.length - 1] <= 10^9
（对于以 Java，C，C++，以及 C# 的提交，时间限制被减少了 50%）

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/length-of-longest-fibonacci-subsequence
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <unordered_map>
#include <algorithm>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int lenLongestFibSubseq(vector<int>& A) {
        /* 令dp[i][j]表示以索引i、j结束的序列，则dp[j][k]=dp[i][j]+1 if(A[i]+A[j]==A[k]) */
        unordered_map<int, int> indices;
        saveIndices(A, indices);

        int i, j, k, size = A.size(), maxLen = 0;
        vector<vector<int>> dp(size, vector<int>(size, 2));

        for (j = 1; j < size - 1; ++j) {
            for (k = j + 1; k < size; ++k) {
                int Ai = A[k] - A[j];
                if (Ai >= A[j]) {
                    continue;
                }

                if (indices.count(Ai) == 1) {
                    i = indices[Ai];
                    dp[j][k] = dp[i][j] + 1;
                    maxLen = max(maxLen, dp[j][k]);
                }
            }
        }

        return maxLen;
    }

    void saveIndices(vector<int>& A, unordered_map<int, int>& indices) {
        for (int index = 0; index < (int)A.size(); ++index) {
            indices[A[index]] = index;
        }
    }
};

int main()
{
    Solution o;
    CheckResult check;

    vector<int> A = { 1,2,3,4,5,6,7,8 };
    check.checkInt(5, o.lenLongestFibSubseq(A));

    A = { 1,3,7,11,12,14,18 };
    check.checkInt(3, o.lenLongestFibSubseq(A));

    A = { 1 };
    check.checkInt(0, o.lenLongestFibSubseq(A));

    A = { 1,2 };
    check.checkInt(0, o.lenLongestFibSubseq(A));

    A = { 1,2,3 };
    check.checkInt(3, o.lenLongestFibSubseq(A));

    A = { 2,4,7,8,9,10,14,15,18,23,32,50 };
    check.checkInt(5, o.lenLongestFibSubseq(A));
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
