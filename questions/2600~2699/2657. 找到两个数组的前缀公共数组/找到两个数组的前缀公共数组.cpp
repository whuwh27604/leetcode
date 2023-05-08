/* 找到两个数组的前缀公共数组.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你两个下标从 0 开始长度为 n 的整数排列 A 和 B 。

A 和 B 的 前缀公共数组 定义为数组 C ，其中 C[i] 是数组 A 和 B 到下标为 i 之前公共元素的数目。

请你返回 A 和 B 的 前缀公共数组 。

如果一个长度为 n 的数组包含 1 到 n 的元素恰好一次，我们称这个数组是一个长度为 n 的 排列 。



示例 1：

输入：A = [1,3,2,4], B = [3,1,2,4]
输出：[0,2,3,4]
解释：i = 0：没有公共元素，所以 C[0] = 0 。
i = 1：1 和 3 是两个数组的前缀公共元素，所以 C[1] = 2 。
i = 2：1，2 和 3 是两个数组的前缀公共元素，所以 C[2] = 3 。
i = 3：1，2，3 和 4 是两个数组的前缀公共元素，所以 C[3] = 4 。
示例 2：

输入：A = [2,3,1], B = [3,1,2]
输出：[0,1,3]
解释：i = 0：没有公共元素，所以 C[0] = 0 。
i = 1：只有 3 是公共元素，所以 C[1] = 1 。
i = 2：1，2 和 3 是两个数组的前缀公共元素，所以 C[2] = 3 。


提示：

1 <= A.length == B.length == n <= 50
1 <= A[i], B[i] <= n
题目保证 A 和 B 两个数组都是 n 个元素的排列。
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        int n = A.size(), count = 0;
        vector<bool> existA(n + 1, false), existB(n + 1, false);
        vector<int> ans(n);

        for (int i = 0; i < n; ++i) {
            if (existB[A[i]]) {
                ++count;
            }

            existA[A[i]] = true;

            if (existA[B[i]]) {
                ++count;
            }

            existB[B[i]] = true;
            ans[i] = count;
        }

        return ans;
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<int> A = { 1,3,2,4 };
    vector<int> B = { 3,1,2,4 };
    vector<int> actual = o.findThePrefixCommonArray(A, B);
    vector<int> expected = { 0,2,3,4 };
    check.checkIntVector(expected, actual);

    A = { 2,3,1 };
    B = { 3,1,2 };
    actual = o.findThePrefixCommonArray(A, B);
    expected = { 0,1,3 };
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
