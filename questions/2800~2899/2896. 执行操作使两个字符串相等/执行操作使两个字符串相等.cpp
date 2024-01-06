/* 执行操作使两个字符串相等.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你两个下标从 0 开始的二进制字符串 s1 和 s2 ，两个字符串的长度都是 n ，再给你一个正整数 x 。

你可以对字符串 s1 执行以下操作 任意次 ：

选择两个下标 i 和 j ，将 s1[i] 和 s1[j] 都反转，操作的代价为 x 。
选择满足 i < n - 1 的下标 i ，反转 s1[i] 和 s1[i + 1] ，操作的代价为 1 。
请你返回使字符串 s1 和 s2 相等的 最小 操作代价之和，如果无法让二者相等，返回 -1 。

注意 ，反转字符的意思是将 0 变成 1 ，或者 1 变成 0 。



示例 1：

输入：s1 = "1100011000", s2 = "0101001010", x = 2
输出：4
解释：我们可以执行以下操作：
- 选择 i = 3 执行第二个操作。结果字符串是 s1 = "1101111000" 。
- 选择 i = 4 执行第二个操作。结果字符串是 s1 = "1101001000" 。
- 选择 i = 0 和 j = 8 ，执行第一个操作。结果字符串是 s1 = "0101001010" = s2 。
总代价是 1 + 1 + 2 = 4 。这是最小代价和。
示例 2：

输入：s1 = "10110", s2 = "00011", x = 4
输出：-1
解释：无法使两个字符串相等。


提示：

n == s1.length == s2.length
1 <= n, x <= 500
s1 和 s2 只包含字符 '0' 和 '1' 。
*/

#include <iostream>
#include <algorithm>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int minOperations(string s1, string s2, int x) {
        int n = s1.size();
        vector<int> indices;

        for (int i = 0; i < n; ++i) {
            if (s1[i] != s2[i]) {
                indices.push_back(i);
            }
        }

        int size = indices.size();
        if ((size & 1) == 1) {
            return -1;
        }

        vector<int> dp1(size + 1, 0), dp2(size + 1, 0);

        for (int i = size - 2; i >= 0; --i) {
            dp1[i] = x - (indices[i + 1] - indices[i]) + max(dp1[i + 2], dp2[i + 2]);
            dp2[i] = max(dp1[i + 1], dp2[i + 1]);
        }

        return size / 2 * x - max(dp1[0], dp2[0]);
    }
};

int main()
{
    CheckResult check;
    Solution o;

    check.checkInt(4, o.minOperations("1100011000", "0101001010", 2));
    check.checkInt(-1, o.minOperations("10110", "00011", 2));
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
