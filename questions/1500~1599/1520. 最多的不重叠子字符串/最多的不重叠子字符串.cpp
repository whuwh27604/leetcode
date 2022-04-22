/* 最多的不重叠子字符串.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你一个只包含小写字母的字符串 s ，你需要找到 s 中最多数目的非空子字符串，满足如下条件：

这些字符串之间互不重叠，也就是说对于任意两个子字符串 s[i..j] 和 s[k..l] ，要么 j < k 要么 i > l 。
如果一个子字符串包含字符 char ，那么 s 中所有 char 字符都应该在这个子字符串中。
请你找到满足上述条件的最多子字符串数目。如果有多个解法有相同的子字符串数目，请返回这些子字符串总长度最小的一个解。可以证明最小总长度解是唯一的。

请注意，你可以以 任意 顺序返回最优解的子字符串。

 

示例 1：

输入：s = "adefaddaccc"
输出：["e","f","ccc"]
解释：下面为所有满足第二个条件的子字符串：
[
  "adefaddaccc"
  "adefadda",
  "ef",
  "e",
  "f",
  "ccc",
]
如果我们选择第一个字符串，那么我们无法再选择其他任何字符串，所以答案为 1 。如果我们选择 "adefadda" ，剩下子字符串中我们只可以选择 "ccc" ，它是唯一不重叠的子字符串，所以答案为 2 。同时我们可以发现，选择 "ef" 不是最优的，因为它可以被拆分成 2 个子字符串。所以最优解是选择 ["e","f","ccc"] ，答案为 3 。不存在别的相同数目子字符串解。
示例 2：

输入：s = "abbaccd"
输出：["d","bb","cc"]
解释：注意到解 ["d","abba","cc"] 答案也为 3 ，但它不是最优解，因为它的总长度更长。
 

提示：

1 <= s.length <= 10^5
s 只包含小写英文字母。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/maximum-number-of-non-overlapping-substrings
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <algorithm>
#include "../check/CheckResult.h"

using namespace std;

bool pairCompare(const pair<int, int>& p1, const pair<int, int>& p2) {
    return p1.second < p2.second;  // 按照end排序
}

class Solution {
public:
    vector<string> maxNumOfSubstrings(string s) {
        int end = -1;
        vector<pair<int, int>> startEnds(26, { -1,-1 });
        vector<string> ans;

        getStartEnds(s, startEnds);
        merge(s, startEnds);
        sort(startEnds.begin(), startEnds.end(), pairCompare);

        for (auto& startEnd : startEnds) {
            if (startEnd.first > end) {  // 按照end排序后，每次贪心选择最早结束的一个区间，然后选择下一个不重合的区间
                ans.push_back(string(s, startEnd.first, startEnd.second - startEnd.first + 1));
                end = startEnd.second;
            }
        }

        return ans;
    }

    void getStartEnds(string& s, vector<pair<int, int>>& startEnds) {
        for (int i = 0; i < (int)s.size(); ++i) {
            int idx = s[i] - 'a';

            if (startEnds[idx].first == -1) {
                startEnds[idx].first = i;
            }

            startEnds[idx].second = i;
        }
    }

    void merge(string& s, vector<pair<int, int>>& startEnds) {
        for (auto& startEnd : startEnds) {
            if (startEnd.first != -1) {
                merge(s, startEnd, startEnds);
            }
        }
    }

    void merge(string& s, pair<int, int>& startEnd, vector<pair<int, int>>& startEnds) {  // 将ABAB型的区间合并
        int i = startEnd.first, j = startEnd.first;

        while (i != startEnd.second || j != startEnd.first) {
            while (i < startEnd.second) {
                int idx = s[i++] - 'a';
                startEnd.first = min(startEnd.first, startEnds[idx].first);
                startEnd.second = max(startEnd.second, startEnds[idx].second);
            }

            while (j > startEnd.first) {
                int idx = s[j--] - 'a';
                startEnd.first = min(startEnd.first, startEnds[idx].first);
                startEnd.second = max(startEnd.second, startEnds[idx].second);
            }
        }
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<string> actual = o.maxNumOfSubstrings("adefaddaccc");
    vector<string> expected = { "e","f","ccc" };
    check.checkStringVectorRandomOrder(expected, actual);

    actual = o.maxNumOfSubstrings("abbaccd");
    expected = { "d","bb","cc" };
    check.checkStringVectorRandomOrder(expected, actual);

    actual = o.maxNumOfSubstrings("ababa");
    expected = { "ababa" };
    check.checkStringVectorRandomOrder(expected, actual);

    actual = o.maxNumOfSubstrings("dabddcdc");
    expected = { "a","b" };
    check.checkStringVectorRandomOrder(expected, actual);
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
