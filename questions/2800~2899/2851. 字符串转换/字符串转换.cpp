/* 字符串转换.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你两个长度都为 n 的字符串 s 和 t 。你可以对字符串 s 执行以下操作：

将 s 长度为 l （0 < l < n）的 后缀字符串 删除，并将它添加在 s 的开头。
比方说，s = 'abcd' ，那么一次操作中，你可以删除后缀 'cd' ，并将它添加到 s 的开头，得到 s = 'cdab' 。
给你一个整数 k ，请你返回 恰好 k 次操作将 s 变为 t 的方案数。

由于答案可能很大，返回答案对 109 + 7 取余 后的结果。



示例 1：

输入：s = "abcd", t = "cdab", k = 2
输出：2
解释：
第一种方案：
第一次操作，选择 index = 3 开始的后缀，得到 s = "dabc" 。
第二次操作，选择 index = 3 开始的后缀，得到 s = "cdab" 。

第二种方案：
第一次操作，选择 index = 1 开始的后缀，得到 s = "bcda" 。
第二次操作，选择 index = 1 开始的后缀，得到 s = "cdab" 。
示例 2：

输入：s = "ababab", t = "ababab", k = 1
输出：2
解释：
第一种方案：
选择 index = 2 开始的后缀，得到 s = "ababab" 。

第二种方案：
选择 index = 4 开始的后缀，得到 s = "ababab" 。


提示：

2 <= s.length <= 5 * 105
1 <= k <= 1015
s.length == t.length
s 和 t 都只包含小写英文字母。
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class KMP {
public:
    KMP(string& patt) {
        pattern = patt;
        size = pattern.size();
        fail.resize(size, 0);
        initFail();
    }

    void initFail() {
        for (int i = 1; i < size; ++i) {  // KMP算法求fail数组
            int j = fail[i - 1];

            while (j != 0 && pattern[j] != pattern[i]) {
                j = fail[j - 1];
            }

            if (pattern[j] == pattern[i]) {
                fail[i] = j + 1;
            }
        }
    }

    int search(string& text) {  // 在text中查找pattern，返回第一个匹配的位置
        int len = text.size(), i = 0, j = 0;

        for (; i < len; ++i) {
            while (j != 0 && pattern[j] != text[i]) {
                j = fail[j - 1];
            }

            if (pattern[j] == text[i]) {
                ++j;
            }

            if (j == size) {
                return i - size + 1;
            }
        }

        return len;
    }

    int searchCount(string& text) {  // 在text中查找pattern，返回匹配的个数
        int len = text.size(), i = 0, j = 0, count = 0;

        for (; i < len; ++i) {
            while (j != 0 && pattern[j] != text[i]) {
                j = fail[j - 1];
            }

            if (pattern[j] == text[i]) {
                ++j;
            }

            if (j == size) {
                ++count;
                j = fail[j - 1];
            }
        }

        return count;
    }

    vector<int> fail;  // fail[i]表示pattern[0, i - 1]的最长公共前后缀
    string pattern;
    int size;
};

class Matrix22 {  // 2 * 2 矩阵乘法和快速幂
public:
    vector<vector<long long>> multiply(vector<vector<long long>>& a, vector<vector<long long>>& b) {  // a * b
        vector<vector<long long>> ans(2, vector<long long>(2));

        for (int i = 0; i < 2; ++i) {
            for (int j = 0; j < 2; ++j) {
                ans[i][j] = (a[i][0] * b[0][j] + a[i][1] * b[1][j]) % mod;
            }
        }

        return ans;
    }

    vector<vector<long long>> fastPower(vector<vector<long long>>& a, long long n) {  // a ^ n
        vector<vector<long long>> ans = { {1,0},{0,1} };

        while (n != 0) {
            if ((n & 1) == 1) {
                ans = multiply(ans, a);
            }

            a = multiply(a, a);
            n >>= 1;
        }

        return ans;
    }

private:
    int mod = 1000000007;
};

class Solution {
public:
    int numberOfWays(string s, string t, long long k) {
        string ss = s + s;
        ss.pop_back();
        KMP kmp(t);
        int good = kmp.searchCount(ss);
        int bad = (int)s.size() - good;
        vector<vector<long long>> count = { {(long long)good - 1,good},{bad,(long long)bad - 1} };
        Matrix22 matrix;
        count = matrix.fastPower(count, k);

        return (int)(s == t ? count[0][0] : count[0][1]);
    }
};

int main()
{
    CheckResult check;
    Solution o;

    check.checkInt(2, o.numberOfWays("abcd", "cdab", 2));
    check.checkInt(2, o.numberOfWays("ababab", "ababab", 1));
    check.checkInt(208, o.numberOfWays("ceoceo", "eoceoc", 4));
    check.checkInt(13, o.numberOfWays("abab", "abab", 3));
    check.checkInt(14, o.numberOfWays("abab", "baba", 3));
    check.checkInt(0, o.numberOfWays("abc", "abd", 3));
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
