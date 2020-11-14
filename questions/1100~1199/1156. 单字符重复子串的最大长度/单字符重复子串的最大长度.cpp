/* 单字符重复子串的最大长度.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
如果字符串中的所有字符都相同，那么这个字符串是单字符重复的字符串。

给你一个字符串 text，你只能交换其中两个字符一次或者什么都不做，然后得到一些单字符重复的子串。返回其中最长的子串的长度。

 

示例 1：

输入：text = "ababa"
输出：3
示例 2：

输入：text = "aaabaaa"
输出：6
示例 3：

输入：text = "aaabbaaa"
输出：4
示例 4：

输入：text = "aaaaa"
输出：5
示例 5：

输入：text = "abcdef"
输出：1
 

提示：

1 <= text.length <= 20000
text 仅由小写英文字母组成。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/swap-for-longest-repeated-character-substring
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <algorithm>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int maxRepOpt1(string text) {
        int maxRepeat = 0;
        vector<vector<vector<int>>> letters(26, vector<vector<int>>{});
        countLetters(text, letters);

        for (vector<vector<int>>& letter : letters) {
            if (!letter.empty()) {
                maxRepeat = max(maxRepeat, getMaxLen(letter));
            }
        }

        return maxRepeat;
    }

    void countLetters(string& text, vector<vector<vector<int>>>& letters) {
        int i, size = text.size(), consecutive = 1, start = 0;

        for (i = 1; i < size; ++i) {
            if (text[i] == text[i - 1]) {
                ++consecutive;
            }
            else {
                letters[text[i - 1] - 'a'].push_back({ consecutive, start, i - 1 });
                start = i;
                consecutive = 1;
            }
        }

        letters[text[i - 1] - 'a'].push_back({ consecutive, start, i - 1 });
    }

    int getMaxLen(vector<vector<int>>& letter) {
        int i, size = letter.size(), len, maxLen = letter[0][0] + ((size > 1) ? 1 : 0);  // 如果有2段，就可以从第2段换来一个相同的字母

        for (i = 1; i < size; ++i) {
            if (letter[i][1] == letter[i - 1][2] + 2) {
                len = letter[i][0] + letter[i - 1][0] + ((size > 2) ? 1 : 0);  // 如果有3段，就可以从第3段换来一个相同的字母，否则就只能把自己最后一个字母换过来
            }
            else {
                len = letter[i][0] + ((size > 1) ? 1 : 0);
            }

            maxLen = max(maxLen, len);
        }

        return maxLen;
    }
};

int main()
{
    CheckResult check;
    Solution o;

    check.checkInt(3, o.maxRepOpt1("ababa"));
    check.checkInt(6, o.maxRepOpt1("aaabaaa"));
    check.checkInt(4, o.maxRepOpt1("aaabbaaa"));
    check.checkInt(5, o.maxRepOpt1("aaaaa"));
    check.checkInt(1, o.maxRepOpt1("abcdef"));
    check.checkInt(5, o.maxRepOpt1("baaaaab"));
    check.checkInt(5, o.maxRepOpt1("aababaaa"));
    check.checkInt(6, o.maxRepOpt1("aabaaabbbbb"));
    check.checkInt(3, o.maxRepOpt1("aabba"));
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
