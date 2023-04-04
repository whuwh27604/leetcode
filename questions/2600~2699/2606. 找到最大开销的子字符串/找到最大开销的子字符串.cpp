/* 找到最大开销的子字符串.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你一个字符串 s ，一个字符 互不相同 的字符串 chars 和一个长度与 chars 相同的整数数组 vals 。

子字符串的开销 是一个子字符串中所有字符对应价值之和。空字符串的开销是 0 。

字符的价值 定义如下：

如果字符不在字符串 chars 中，那么它的价值是它在字母表中的位置（下标从 1 开始）。
比方说，'a' 的价值为 1 ，'b' 的价值为 2 ，以此类推，'z' 的价值为 26 。
否则，如果这个字符在 chars 中的位置为 i ，那么它的价值就是 vals[i] 。
请你返回字符串 s 的所有子字符串中的最大开销。



示例 1：

输入：s = "adaa", chars = "d", vals = [-1000]
输出：2
解释：字符 "a" 和 "d" 的价值分别为 1 和 -1000 。
最大开销子字符串是 "aa" ，它的开销为 1 + 1 = 2 。
2 是最大开销。
示例 2：

输入：s = "abc", chars = "abc", vals = [-1,-1,-1]
输出：0
解释：字符 "a" ，"b" 和 "c" 的价值分别为 -1 ，-1 和 -1 。
最大开销子字符串是 "" ，它的开销为 0 。
0 是最大开销。


提示：

1 <= s.length <= 105
s 只包含小写英文字母。
1 <= chars.length <= 26
chars 只包含小写英文字母，且 互不相同 。
vals.length == chars.length
-1000 <= vals[i] <= 1000
*/

#include <iostream>
#include <algorithm>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int maximumCostSubstring(string s, string chars, vector<int>& vals) {
        vector<int> values(26);
        int size = chars.size(), cost = 0, maxCost = 0;

        for (int i = 0; i < 26; ++i) {
            values[i] = i + 1;
        }

        for (int i = 0; i < size; ++i) {
            values[chars[i] - 'a'] = vals[i];
        }

        for (char c : s) {
            cost += values[c - 'a'];
            maxCost = max(maxCost, cost);

            if (cost < 0) {
                cost = 0;
            }
        }

        return maxCost;
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<int> vals = { -1000 };
    check.checkInt(2, o.maximumCostSubstring("adaa", "d", vals));

    vals = { -1,-1,-1 };
    check.checkInt(0, o.maximumCostSubstring("abc", "abc", vals));
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
