/* 找到所有好字符串.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你两个长度为 n 的字符串 s1 和 s2 ，以及一个字符串 evil 。请你返回 好字符串 的数目。

好字符串 的定义为：它的长度为 n ，字典序大于等于 s1 ，字典序小于等于 s2 ，且不包含 evil 为子字符串。

由于答案可能很大，请你返回答案对 10^9 + 7 取余的结果。



示例 1：

输入：n = 2, s1 = "aa", s2 = "da", evil = "b"
输出：51
解释：总共有 25 个以 'a' 开头的好字符串："aa"，"ac"，"ad"，...，"az"。还有 25 个以 'c' 开头的好字符串："ca"，"cc"，"cd"，...，"cz"。最后，还有一个以 'd' 开头的好字符串："da"。
示例 2：

输入：n = 8, s1 = "leetcode", s2 = "leetgoes", evil = "leet"
输出：0
解释：所有字典序大于等于 s1 且小于等于 s2 的字符串都以 evil 字符串 "leet" 开头。所以没有好字符串。
示例 3：

输入：n = 2, s1 = "gx", s2 = "gz", evil = "x"
输出：2


提示：

s1.length == n
s2.length == n
s1 <= s2
1 <= n <= 500
1 <= evil.length <= 50
所有字符串都只包含小写英文字母。
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int findGoodStrings(int n_, string s1_, string s2_, string evil_) {
        s1 = s1_;
        s2 = s2_;
        evil = evil_;
        n = n_;
        m = evil.size();
        mod = 1000000007;

        initFail();
        // memo[index][len][bound]表示当前是s1/s2的index位置，前面已经匹配了evil的长度为len，前面是否在边界上，这个状态的合法字符串数量
        memo.clear();
        memo.resize(n, vector<vector<int>>(m, vector<int>(4, -1)));
        matchLens.clear();
        matchLens.resize(m, vector<int>(26, -1));

        return DFS(0, 0, 3);
    }

    void initFail() {
        fail.clear();
        fail.resize(m, 0);

        for (int i = 1; i < m; ++i) {  // KMP算法求fail数组
            int j = fail[i - 1];

            while (j != 0 && evil[j] != evil[i]) {
                j = fail[j - 1];
            }

            if (evil[j] == evil[i]) {
                fail[i] = j + 1;
            }
        }
    }

    int DFS(int index, int len, int bound) {
        if (len == m) {  // 如果前面已经匹配上evil，那么后面无论如何都是非法的
            return 0;
        }

        if (index == n) {  // 如果匹配到了s1/s2的末尾，说明找到一个合法的字符串
            return 1;
        }

        int& ans = memo[index][len][bound];
        if (ans != -1) {
            return ans;
        }

        ans = 0;
        char low = ((bound & 1) == 0 ? 'a' : s1[index]);  // 前面不是下边界，当前可以从a开始枚举，否则只能从s1的当前字符开始枚举
        char high = ((bound & 2) == 0 ? 'z' : s2[index]);  // 前面不是上边界，当前可以枚举到z，否则只能枚举到s2的当前字符

        for (char c = low; c <= high; ++c) {
            ans = (ans + DFS(index + 1, getNextLen(len, c), getNextBound(index, c, bound))) % mod;
        }

        return ans;
    }

    int getNextLen(int len, char c) {
        int& nextLen = matchLens[len][c - 'a'];
        if (nextLen != -1) {
            return nextLen;
        }

        while (len != 0 && evil[len] != c) {
            len = fail[len - 1];
        }

        return nextLen = (evil[len] == c ? len + 1 : 0);
    }

    int getNextBound(int index, char c, int bound) {
        int nextBound = 0;

        if ((bound & 1) != 0 && c == s1[index]) {  // 当前已经是下边界，然后选择的字符又是s1的相同字符，那么仍然是下边界
            nextBound |= 1;
        }
        if ((bound & 2) != 0 && c == s2[index]) {  // 当前已经是上边界，然后选择的字符又是s2的相同字符，那么仍然是上边界
            nextBound |= 2;
        }

        return nextBound;
    }

private:
    string s1;
    string s2;
    string evil;
    int m;
    int n;
    int mod;
    vector<int> fail;
    vector<vector<int>> matchLens;
    vector<vector<vector<int>>> memo;
};

int main()
{
    CheckResult check;
    Solution o;

    check.checkInt(51, o.findGoodStrings(2, "aa", "da", "b"));
    check.checkInt(0, o.findGoodStrings(8, "leetcode", "leetgoes", "leet"));
    check.checkInt(2, o.findGoodStrings(2, "gx", "gz", "x"));
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
