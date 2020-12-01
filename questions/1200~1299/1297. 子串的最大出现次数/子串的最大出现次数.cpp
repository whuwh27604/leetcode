/* 子串的最大出现次数.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你一个字符串 s ，请你返回满足以下条件且出现次数最大的 任意 子串的出现次数：

子串中不同字母的数目必须小于等于 maxLetters 。
子串的长度必须大于等于 minSize 且小于等于 maxSize 。
 

示例 1：

输入：s = "aababcaab", maxLetters = 2, minSize = 3, maxSize = 4
输出：2
解释：子串 "aab" 在原字符串中出现了 2 次。
它满足所有的要求：2 个不同的字母，长度为 3 （在 minSize 和 maxSize 范围内）。
示例 2：

输入：s = "aaaa", maxLetters = 1, minSize = 3, maxSize = 3
输出：2
解释：子串 "aaa" 在原字符串中出现了 2 次，且它们有重叠部分。
示例 3：

输入：s = "aabcabcab", maxLetters = 2, minSize = 2, maxSize = 3
输出：3
示例 4：

输入：s = "abcde", maxLetters = 2, minSize = 3, maxSize = 3
输出：0
 

提示：

1 <= s.length <= 10^5
1 <= maxLetters <= 26
1 <= minSize <= maxSize <= min(26, s.length)
s 只包含小写英文字母。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/maximum-number-of-occurrences-of-a-substring
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <unordered_map>
#include <algorithm>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int maxFreq(string s, int maxLetters, int minSize, int maxSize) {
        (void)maxSize;  // 很显然最大值没什么用，混淆视听的
        unordered_map<string, int> substringCount;
        vector<int> lettersCount('z' + 1, 0);
        int index = 0, count = 0;

        initWindow(s, index, minSize, count, lettersCount);
        if (count <= maxLetters) {
            string substring(s, 0, minSize);
            substringCount[substring] = 1;
        }

        slideWindow(s, index, minSize, maxLetters, count, lettersCount, substringCount);

        return getMaxFreq(substringCount);
    }

    void initWindow(string& s, int& index, int windowSize, int& count, vector<int>& lettersCount) {
        for (; index < windowSize; ++index) {
            if (++lettersCount[s[index]] == 1) {
                ++count;
            }
        }
    }

    void slideWindow(string& s, int& index, int windowSize, int maxLetters, int& count, vector<int>& lettersCount, unordered_map<string, int>& substringCount) {
        for (; index < (int)s.size(); ++index) {
            if (--lettersCount[s[index - windowSize]] == 0) {
                --count;
            }

            if (++lettersCount[s[index]] == 1) {
                ++count;
            }

            if (count <= maxLetters) {
                string substring(s, index - windowSize + 1, windowSize);
                ++substringCount[substring];
            }
        }
    }

    int getMaxFreq(unordered_map<string, int>& substringCount) {
        int maxFrequence = 0;

        for (auto iter = substringCount.begin(); iter != substringCount.end(); ++iter) {
            maxFrequence = max(maxFrequence, iter->second);
        }

        return maxFrequence;
    }
};

int main()
{
    CheckResult check;
    Solution o;

    check.checkInt(2, o.maxFreq("aababcaab", 2, 3, 4));
    check.checkInt(2, o.maxFreq("aaaa", 1, 3, 3));
    check.checkInt(1, o.maxFreq("aaaa", 1, 4, 4));
    check.checkInt(1, o.maxFreq("a", 1, 1, 1));
    check.checkInt(3, o.maxFreq("aabcabcab", 2, 2, 3));
    check.checkInt(0, o.maxFreq("abcde", 2, 3, 3));
    check.checkInt(0, o.maxFreq("ababab", 1, 2, 3));
    check.checkInt(5, o.maxFreq("aaaaaa", 1, 2, 3));
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
