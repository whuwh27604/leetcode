/* 判断通过操作能否让字符串相等 II.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你两个字符串 s1 和 s2 ，两个字符串长度都为 n ，且只包含 小写 英文字母。

你可以对两个字符串中的 任意一个 执行以下操作 任意 次：

选择两个下标 i 和 j ，满足 i < j 且 j - i 是 偶数，然后 交换 这个字符串中两个下标对应的字符。


如果你可以让字符串 s1 和 s2 相等，那么返回 true ，否则返回 false 。





示例 1：

输入：s1 = "abcdba", s2 = "cabdab"
输出：true
解释：我们可以对 s1 执行以下操作：
- 选择下标 i = 0 ，j = 2 ，得到字符串 s1 = "cbadba" 。
- 选择下标 i = 2 ，j = 4 ，得到字符串 s1 = "cbbdaa" 。
- 选择下标 i = 1 ，j = 5 ，得到字符串 s1 = "cabdab" = s2 。
示例 2：

输入：s1 = "abe", s2 = "bea"
输出：false
解释：无法让两个字符串相等。


提示：

n == s1.length == s2.length
1 <= n <= 105
s1 和 s2 只包含小写英文字母。
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    bool checkStrings(string s1, string s2) {
        int n = s1.size();
        vector<int> evenCount1(26, 0), oddCount1(26, 0), evenCount2(26, 0), oddCount2(26, 0);

        count(n, s1, evenCount1, oddCount1);
        count(n, s2, evenCount2, oddCount2);

        return evenCount1 == evenCount2 && oddCount1 == oddCount2;
    }

    void count(int n, string& s, vector<int>& evenCount, vector<int>& oddCount) {
        for (int i = 0; i < n; i += 2) {
            ++evenCount[s[i] - 'a'];
        }

        for (int i = 1; i < n; i += 2) {
            ++oddCount[s[i] - 'a'];
        }
    }
};

int main()
{
    CheckResult check;
    Solution o;

    check.checkBool(true, o.checkStrings("abcdba", "cabdab"));
    check.checkBool(false, o.checkStrings("abe", "bea"));
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
