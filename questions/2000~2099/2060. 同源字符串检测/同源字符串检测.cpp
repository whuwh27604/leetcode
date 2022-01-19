/* 同源字符串检测.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
原字符串由小写字母组成，可以按下述步骤编码：

任意将其 分割 为由若干 非空 子字符串组成的一个 序列 。
任意选择序列中的一些元素（也可能不选择），然后将这些元素替换为元素各自的长度（作为一个数字型的字符串）。
重新 顺次连接 序列，得到编码后的字符串。
例如，编码 "abcdefghijklmnop" 的一种方法可以描述为：

将原字符串分割得到一个序列：["ab", "cdefghijklmn", "o", "p"] 。
选出其中第二个和第三个元素并分别替换为它们自身的长度。序列变为 ["ab", "12", "1", "p"] 。
重新顺次连接序列中的元素，得到编码后的字符串："ab121p" 。
给你两个编码后的字符串 s1 和 s2 ，由小写英文字母和数字 1-9 组成。如果存在能够同时编码得到 s1 和 s2 原字符串，返回 true ；否则，返回 false。

注意：生成的测试用例满足 s1 和 s2 中连续数字数不超过 3 。

 

示例 1：

输入：s1 = "internationalization", s2 = "i18n"
输出：true
解释："internationalization" 可以作为原字符串
- "internationalization"
  -> 分割：      ["internationalization"]
  -> 不替换任何元素
  -> 连接：      "internationalization"，得到 s1
- "internationalization"
  -> 分割：      ["i", "nternationalizatio", "n"]
  -> 替换：      ["i", "18",                 "n"]
  -> 连接：      "i18n"，得到 s2
示例 2：

输入：s1 = "l123e", s2 = "44"
输出：true
解释："leetcode" 可以作为原字符串
- "leetcode"
  -> 分割：       ["l", "e", "et", "cod", "e"]
  -> 替换：       ["l", "1", "2",  "3",   "e"]
  -> 连接：       "l123e"，得到 s1
- "leetcode"
  -> 分割：       ["leet", "code"]
  -> 替换：       ["4",    "4"]
  -> 连接：       "44"，得到 s2
示例 3：

输入：s1 = "a5b", s2 = "c5b"
输出：false
解释：不存在这样的原字符串
- 编码为 s1 的字符串必须以字母 'a' 开头
- 编码为 s2 的字符串必须以字母 'c' 开头
示例 4：

输入：s1 = "112s", s2 = "g841"
输出：true
解释："gaaaaaaaaaaaas" 可以作为原字符串
- "gaaaaaaaaaaaas"
  -> 分割：       ["g", "aaaaaaaaaaaa", "s"]
  -> 替换：       ["1", "12",           "s"]
  -> 连接：       "112s"，得到 s1
- "gaaaaaaaaaaaas"
  -> 分割：       ["g", "aaaaaaaa", "aaaa", "s"]
  -> 替换：       ["g", "8",        "4",    "1"]
  -> 连接         "g841"，得到 s2
示例 5：

输入：s1 = "ab", s2 = "a2"
输出：false
解释：不存在这样的原字符串
- 编码为 s1 的字符串由两个字母组成
- 编码为 s2 的字符串由三个字母组成
 

提示：

1 <= s1.length, s2.length <= 40
s1 和 s2 仅由数字 1-9 和小写英文字母组成
s1 和 s2 中连续数字数不超过 3

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/check-if-an-original-string-exists-given-two-encoded-strings
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    bool possiblyEquals(string s1, string s2) {
        int size1 = s1.size(), size2 = s2.size(), bias = 1000;
        char* match = new char[(size1 + 1) * (size2 + 1) * 2 * bias]();

        return DFS(s1, s2, match, 0, 0, bias) == 1;
    }

    int DFS(string& s1, string& s2, char* match, int p1, int p2, int diff) {
        int size1 = s1.size(), size2 = s2.size(), bias = 1000;
        char& result = match[p1 * size2 * 2 * bias + p2 * 2 * bias + diff];

        if (result != 0) {
            return result;
        }

        if (p1 == size1 && p2 == size2) {
            return result = ((diff == bias) ? 1 : -1);
        }

        result = -1;

        if (diff == bias && p1 < size1 && s1[p1] >= 'a' && p2 < size2 && s2[p2] >= 'a') {
            return result = (s1[p1] == s2[p2] ? DFS(s1, s2, match, p1 + 1, p2 + 1, diff) : -1);
        }

        if (diff <= bias && p1 < size1) {
            if (s1[p1] <= '9') {
                for (int i = p1, d = 0; i < size1 && s1[i] <= '9'; ++i) {
                    d = d * 10 + s1[i] - '0';

                    if (DFS(s1, s2, match, i + 1, p2, diff + d) == 1) {
                        return result = 1;
                    }
                }
            }
            else if (diff < bias && DFS(s1, s2, match, p1 + 1, p2, diff + 1) == 1) {
                return result = 1;
            }
        }

        if (diff >= bias && p2 < size2) {
            if (s2[p2] <= '9') {
                for (int i = p2, d = 0; i < size2 && s2[i] <= '9'; ++i) {
                    d = d * 10 + s2[i] - '0';

                    if (DFS(s1, s2, match, p1, i + 1, diff - d) == 1) {
                        return result = 1;
                    }
                }
            }
            else if (diff > bias && DFS(s1, s2, match, p1, p2 + 1, diff - 1) == 1) {
                return result = 1;
            }
        }

        return result;
    }
};

int main()
{
    CheckResult check;
    Solution o;

    check.checkBool(false, o.possiblyEquals("a", "b"));
    check.checkBool(true, o.possiblyEquals("internationalization", "i18n"));
    check.checkBool(true, o.possiblyEquals("l123e", "44"));
    check.checkBool(false, o.possiblyEquals("a5b", "c5b"));
    check.checkBool(true, o.possiblyEquals("112s", "g841"));
    check.checkBool(false, o.possiblyEquals("ab", "a2"));
    check.checkBool(false, o.possiblyEquals("a776a2", "a765a"));
    check.checkBool(false, o.possiblyEquals("p74p4q73p69q22p3", "29p134p9q64p22p2p"));
    check.checkBool(false, o.possiblyEquals("p4q85q68q447q5p1", "543p57q63p177q7"));
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
