/* 替换子串得到平衡字符串.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
有一个只含有 'Q', 'W', 'E', 'R' 四种字符，且长度为 n 的字符串。

假如在该字符串中，这四个字符都恰好出现 n/4 次，那么它就是一个「平衡字符串」。

 

给你一个这样的字符串 s，请通过「替换一个子串」的方式，使原字符串 s 变成一个「平衡字符串」。

你可以用和「待替换子串」长度相同的 任何 其他字符串来完成替换。

请返回待替换子串的最小可能长度。

如果原字符串自身就是一个平衡字符串，则返回 0。

 

示例 1：

输入：s = "QWER"
输出：0
解释：s 已经是平衡的了。
示例 2：

输入：s = "QQWE"
输出：1
解释：我们需要把一个 'Q' 替换成 'R'，这样得到的 "RQWE" (或 "QRWE") 是平衡的。
示例 3：

输入：s = "QQQW"
输出：2
解释：我们可以把前面的 "QQ" 替换成 "ER"。
示例 4：

输入：s = "QQQQ"
输出：3
解释：我们可以替换后 3 个 'Q'，使 s = "QWER"。
 

提示：

1 <= s.length <= 10^5
s.length 是 4 的倍数
s 中只含有 'Q', 'W', 'E', 'R' 四种字符

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/replace-the-substring-for-balanced-string
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <unordered_map>
#include <algorithm>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int balancedString(string s) {
        int left = 0, right, size = s.size();
        vector<int> letters(127, 0);
        countLetters(s, letters);

        unordered_map<char, int> decreasingLetters, lettersInWindow = { {'Q',0},{'W',0},{'E',0},{'R',0} };
        getDecreasingLetters(size / 4, letters, decreasingLetters);
        initWindow(s, decreasingLetters, lettersInWindow, right);

        int minSubstr = right + 1;
        for (right += 1; right < size; ++right) {
            ++lettersInWindow[s[right]];

            while (lettersInWindow[s[left]] > decreasingLetters[s[left]]) {  // 尝试缩小窗口
                --lettersInWindow[s[left++]];
            }

            minSubstr = min(minSubstr, right - left + 1);
        }

        return minSubstr;
    }

    void countLetters(string& s, vector<int>& letters) {
        for (char c : s) {
            ++letters[c];
        }
    }

    void getDecreasingLetters(int balanceLen, vector<int>& letters, unordered_map<char, int>& decreasingLetters) {
        decreasingLetters['Q'] = letters['Q'] > balanceLen ? letters['Q'] - balanceLen : 0;
        decreasingLetters['W'] = letters['W'] > balanceLen ? letters['W'] - balanceLen : 0;
        decreasingLetters['E'] = letters['E'] > balanceLen ? letters['E'] - balanceLen : 0;
        decreasingLetters['R'] = letters['R'] > balanceLen ? letters['R'] - balanceLen : 0;
    }

    void initWindow(string& s, unordered_map<char, int>& decreasingLetters, unordered_map<char, int>& lettersInWindow, int& right) {
        for (right = 0; right < (int)s.size(); ++right) {
            ++lettersInWindow[s[right]];
            int count = 0;

            for (pair<const char, int>& letter : lettersInWindow) {
                if (letter.second >= decreasingLetters[letter.first]) {
                    ++count;
                }
                else {
                    break;
                }
            }

            if (count == 4) {
                break;
            }
        }
    }
};

int main()
{
    CheckResult check;
    Solution o;

    check.checkInt(0, o.balancedString("QWER"));
    check.checkInt(1, o.balancedString("QQER"));
    check.checkInt(2, o.balancedString("QQQR"));
    check.checkInt(3, o.balancedString("QQQQ"));
    check.checkInt(4, o.balancedString("WWEQERQWQWWRWWERQWEQ"));
    check.checkInt(5, o.balancedString("WWWEQRQEWWQQQWQQQWEWEEWRRRRRWWQE"));
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
