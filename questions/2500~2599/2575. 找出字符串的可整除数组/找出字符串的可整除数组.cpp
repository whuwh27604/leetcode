/* 找出字符串的可整除数组.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你一个下标从 0 开始的字符串 word ，长度为 n ，由从 0 到 9 的数字组成。另给你一个正整数 m 。

word 的 可整除数组 div  是一个长度为 n 的整数数组，并满足：

如果 word[0,...,i] 所表示的 数值 能被 m 整除，div[i] = 1
否则，div[i] = 0
返回 word 的可整除数组。



示例 1：

输入：word = "998244353", m = 3
输出：[1,1,0,0,0,1,1,0,0]
解释：仅有 4 个前缀可以被 3 整除："9"、"99"、"998244" 和 "9982443" 。
示例 2：

输入：word = "1010", m = 10
输出：[0,1,0,1]
解释：仅有 2 个前缀可以被 10 整除："10" 和 "1010" 。


提示：

1 <= n <= 105
word.length == n
word 由数字 0 到 9 组成
1 <= m <= 109
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    vector<int> divisibilityArray(string word, int m) {
        long long num = 0;
        int size = word.size();
        vector<int> ans(size, 0);

        for (int i = 0; i < size; ++i) {
            num = (num * 10 + word[i] - '0') % m;
            if (num == 0) {
                ans[i] = 1;
            }
        }

        return ans;
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<int> actual = o.divisibilityArray("998244353", 3);
    vector<int> expected = { 1,1,0,0,0,1,1,0,0 };
    check.checkIntVector(expected, actual);

    actual = o.divisibilityArray("1010", 10);
    expected = { 0,1,0,1 };
    check.checkIntVector(expected, actual);

    actual = o.divisibilityArray("012345", 1);
    expected = { 1,1,1,1,1,1 };
    check.checkIntVector(expected, actual);

    actual = o.divisibilityArray("99824435310100123459982443531010012345998244353101001234599824435310100123459982443531010012345", 7);
    expected = { 0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,1,0,1,0,0,0,1,1,1,0,0,0,0,0,1,0,1,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0 };
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
