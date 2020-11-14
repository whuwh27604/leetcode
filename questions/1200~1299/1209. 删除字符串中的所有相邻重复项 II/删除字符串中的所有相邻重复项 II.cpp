/* 删除字符串中的所有相邻重复项 II.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你一个字符串 s，「k 倍重复项删除操作」将会从 s 中选择 k 个相邻且相等的字母，并删除它们，使被删去的字符串的左侧和右侧连在一起。

你需要对 s 重复进行无限次这样的删除操作，直到无法继续为止。

在执行完所有删除操作后，返回最终得到的字符串。

本题答案保证唯一。

 

示例 1：

输入：s = "abcd", k = 2
输出："abcd"
解释：没有要删除的内容。
示例 2：

输入：s = "deeedbbcccbdaa", k = 3
输出："aa"
解释：
先删除 "eee" 和 "ccc"，得到 "ddbbbdaa"
再删除 "bbb"，得到 "dddaa"
最后删除 "ddd"，得到 "aa"
示例 3：

输入：s = "pbbcggttciiippooaais", k = 2
输出："ps"
 

提示：

1 <= s.length <= 10^5
2 <= k <= 10^4
s 中只含有小写英文字母。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/remove-all-adjacent-duplicates-in-string-ii
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <stack>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    string removeDuplicates(string s, int k) {
        string removed;
        stack<pair<char, int>> letters;
        letters.push({'#', 1});
        int count = 0;
        char prev = 0;
        s += '#';

        for (char c : s) {
            if (c == prev) {
                if (++count == k) {
                    prev = letters.top().first;
                    count = letters.top().second;
                    letters.pop();
                }
            }
            else {
                letters.push({prev, count});
                count = 1;
                prev = c;
            }
        }

        while (!letters.empty()) {
            removed.append(letters.top().second, letters.top().first);
            letters.pop();
        }

        removed.pop_back();
        reverse(removed.begin(), removed.end());

        return removed;
    }
};

int main()
{
    CheckResult check;
    Solution o;

    check.checkString("abcd", o.removeDuplicates("abcd", 2));
    check.checkString("aa", o.removeDuplicates("deeedbbcccbdaa", 3));
    check.checkString("ps", o.removeDuplicates("pbbcggttciiippooaais", 2));
    check.checkString("a", o.removeDuplicates("a", 2));
    check.checkString("", o.removeDuplicates("aa", 2));
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
