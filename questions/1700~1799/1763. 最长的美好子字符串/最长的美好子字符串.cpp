/* 最长的美好子字符串.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
当一个字符串 s 包含的每一种字母的大写和小写形式 同时 出现在 s 中，就称这个字符串 s 是 美好 字符串。比方说，"abABB" 是美好字符串，因为 'A' 和 'a' 同时出现了，且 'B' 和 'b' 也同时出现了。然而，"abA" 不是美好字符串因为 'b' 出现了，而 'B' 没有出现。

给你一个字符串 s ，请你返回 s 最长的 美好子字符串 。如果有多个答案，请你返回 最早 出现的一个。如果不存在美好子字符串，请你返回一个空字符串。

 

示例 1：

输入：s = "YazaAay"
输出："aAa"
解释："aAa" 是一个美好字符串，因为这个子串中仅含一种字母，其小写形式 'a' 和大写形式 'A' 也同时出现了。
"aAa" 是最长的美好子字符串。
示例 2：

输入：s = "Bb"
输出："Bb"
解释："Bb" 是美好字符串，因为 'B' 和 'b' 都出现了。整个字符串也是原字符串的子字符串。
示例 3：

输入：s = "c"
输出：""
解释：没有美好子字符串。
示例 4：

输入：s = "dDzeE"
输出："dD"
解释："dD" 和 "eE" 都是最长美好子字符串。
由于有多个美好子字符串，返回 "dD" ，因为它出现得最早。
 

提示：

1 <= s.length <= 100
s 只包含大写和小写英文字母。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/longest-nice-substring
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <algorithm>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    string longestNiceSubstring(string s) {
        pair<int, int> LNS = getLNS(s, 0, s.size() - 1);

        return LNS.first == -1 ? "" : string(s, LNS.first, LNS.second - LNS.first + 1);
    }

    pair<int, int> getLNS(string& s, int start, int end) {
        pair<int, int> LNS = { -1, -1 };
        if (start >= end) {
            return LNS;
        }

        vector<vector<int>> indices(26);
        vector<int> upperLower(26, 0);
        vector<int> badIndices;
        int i, index;

        for (i = start; i <= end; ++i) {
            if (s[i] >= 'a') {
                index = s[i] - 'a';
                upperLower[index] |= 0b01;
            }
            else {
                index = s[i] - 'A';
                upperLower[index] |= 0b10;
            }
            indices[index].push_back(i);
        }

        for (i = 0; i < 26; ++i) {
            if (upperLower[i] == 1 || upperLower[i] == 2) {
                badIndices.insert(badIndices.end(), indices[i].begin(), indices[i].end());
            }
        }

        if (badIndices.empty()) {
            return { start, end };
        }

        sort(badIndices.begin(), badIndices.end());
        badIndices.push_back(end + 1);
        int left = start - 1;

        for (int right : badIndices) {
            pair<int, int> subLNS = getLNS(s, left + 1, right - 1);
            if (subLNS.second - subLNS.first > LNS.second - LNS.first) {
                LNS = subLNS;
            }

            left = right;
        }

        return LNS;
    }
};


int main()
{
    CheckResult check;
    Solution o;

    check.checkString("aAa", o.longestNiceSubstring("YazaAay"));
    check.checkString("Bb", o.longestNiceSubstring("Bb"));
    check.checkString("", o.longestNiceSubstring("c"));
    check.checkString("dD", o.longestNiceSubstring("dDzeE"));
    check.checkString("aZbcDEedCBzA", o.longestNiceSubstring("aZbcDEedCBzA"));
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
