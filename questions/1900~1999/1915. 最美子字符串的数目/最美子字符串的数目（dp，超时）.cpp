// 最美子字符串的数目.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    long long wonderfulSubstrings(string word) {
        int i, j, size = word.size();
        vector<vector<int>> dp(size + 1, vector<int>(1024, 0));
        long long sum = 0;
        
        for (i = 1; i <= size; ++i) {
            int bit = 1 << (word[i - 1] - 'a');

            dp[i][0] = dp[i - 1][bit];  // 其它都是偶数，当前字符是奇数，加上当前字符后也变成偶数

            for (j = 1; j < 1024; ++j) {
                dp[i][j] = dp[i - 1][j ^ bit];  // 当前字符的奇偶性发生变化
            }

            dp[i][bit] += 1;  // 当前字符单独作为一个子串的情况
            sum += dp[i][0];  // 全部为偶数

            for (bit = 1; bit < 1024; bit <<= 1) {  // 只有一个字符为奇数
                sum += dp[i][bit];
            }
        }

        return sum;
    }
};

int main()
{
    CheckResult check;
    Solution o;

    check.checkInt(4, o.wonderfulSubstrings("aba"));
    check.checkInt(9, o.wonderfulSubstrings("aabb"));
    check.checkInt(2, o.wonderfulSubstrings("he"));
    check.checkInt(1, o.wonderfulSubstrings("j"));
    check.checkInt(715, o.wonderfulSubstrings("abcdefghijabcdefghijabcdefghijabcdefghijabcdefghijabcdefghijabcdefghijabcdefghijabcdefghijabcdefghij"));
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
