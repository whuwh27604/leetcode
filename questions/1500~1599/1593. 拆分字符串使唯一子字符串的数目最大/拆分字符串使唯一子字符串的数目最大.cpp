/* 拆分字符串使唯一子字符串的数目最大.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你一个字符串 s ，请你拆分该字符串，并返回拆分后唯一子字符串的最大数目。

字符串 s 拆分后可以得到若干 非空子字符串 ，这些子字符串连接后应当能够还原为原字符串。但是拆分出来的每个子字符串都必须是 唯一的 。

注意：子字符串 是字符串中的一个连续字符序列。

 

示例 1：

输入：s = "ababccc"
输出：5
解释：一种最大拆分方法为 ['a', 'b', 'ab', 'c', 'cc'] 。像 ['a', 'b', 'a', 'b', 'c', 'cc'] 这样拆分不满足题目要求，因为其中的 'a' 和 'b' 都出现了不止一次。
示例 2：

输入：s = "aba"
输出：2
解释：一种最大拆分方法为 ['a', 'ba'] 。
示例 3：

输入：s = "aa"
输出：1
解释：无法进一步拆分字符串。
 

提示：

1 <= s.length <= 16

s 仅包含小写英文字母

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/split-a-string-into-the-max-number-of-unique-substrings
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <algorithm>
#include <unordered_set>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int maxUniqueSplit(string s) {
        unordered_set<string> substrs;
        int maxSplits = 0;

        DFS(s, s.size(), 0, substrs, maxSplits);

        return maxSplits;
    }

    void DFS(string& s, int size, int start, unordered_set<string>& substrs, int& maxSplits) {
        if (start == size) {
            maxSplits = max(maxSplits, (int)substrs.size());
            return;
        }

        for (int i = start; i < size; ++i) {
            string substr(s, start, i - start + 1);

            if (substrs.count(substr) == 0) {
                substrs.insert(substr);
                DFS(s, size, i + 1, substrs, maxSplits);
                substrs.erase(substr);
            }
        }
    }
};

int main()
{
    CheckResult check;
    Solution o;

    check.checkInt(5, o.maxUniqueSplit("ababccc"));
    check.checkInt(2, o.maxUniqueSplit("aba"));
    check.checkInt(1, o.maxUniqueSplit("aa"));
    check.checkInt(5, o.maxUniqueSplit("aaaaaaaaaaaaaaaa"));
    check.checkInt(16, o.maxUniqueSplit("abcdefghijklmnop"));
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
