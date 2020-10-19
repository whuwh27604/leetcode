/* 检查替换后的词是否有效.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给定有效字符串 "abc"。

对于任何有效的字符串 V，我们可以将 V 分成两个部分 X 和 Y，使得 X + Y（X 与 Y 连接）等于 V。（X 或 Y 可以为空。）那么，X + "abc" + Y 也同样是有效的。

例如，如果 S = "abc"，则有效字符串的示例是："abc"，"aabcbc"，"abcabc"，"abcabcababcc"。无效字符串的示例是："abccba"，"ab"，"cababc"，"bac"。

如果给定字符串 S 有效，则返回 true；否则，返回 false。

 

示例 1：

输入："aabcbc"
输出：true
解释：
从有效字符串 "abc" 开始。
然后我们可以在 "a" 和 "bc" 之间插入另一个 "abc"，产生 "a" + "abc" + "bc"，即 "aabcbc"。
示例 2：

输入："abcabcababcc"
输出：true
解释：
"abcabcabc" 是有效的，它可以视作在原串后连续插入 "abc"。
然后我们可以在最后一个字母之前插入 "abc"，产生 "abcabcab" + "abc" + "c"，即 "abcabcababcc"。
示例 3：

输入："abccba"
输出：false
示例 4：

输入："cababc"
输出：false
 

提示：

1 <= S.length <= 20000
S[i] 为 'a'、'b'、或 'c'

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/check-if-word-is-valid-after-substitutions
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <stack>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    bool isValid(string s) {
        stack<char> letters;
        letters.push('#');

        for (char c : s) {
            if (c != 'c') {
                letters.push(c);
            }
            else {
                if (letters.top() != 'b') {
                    return false;
                }
                letters.pop();
                
                if (letters.top() != 'a') {
                    return false;
                }
                letters.pop();
            }
        }

        return letters.top() == '#';
    }
};

int main()
{
    CheckResult check;
    Solution o;

    check.checkBool(true, o.isValid("aabcbc"));
    check.checkBool(true, o.isValid("abcabcababcc"));
    check.checkBool(true, o.isValid("aabababcccabcbc"));
    check.checkBool(true, o.isValid("abc"));
    check.checkBool(true, o.isValid("abcabc"));
    check.checkBool(true, o.isValid("aabcbabcc"));
    check.checkBool(false, o.isValid("abccba"));
    check.checkBool(false, o.isValid("cababc"));
    check.checkBool(false, o.isValid("a"));
    check.checkBool(false, o.isValid("b"));
    check.checkBool(false, o.isValid("c"));
    check.checkBool(false, o.isValid("ab"));
    check.checkBool(false, o.isValid("cbbbbcaaaccbaabccabacabcacbabbabbcbacabacabcabbccbccbccbcaccbacaabaaababacbbccabbcbcbabbcbabcacabcbababcaccbcbbbaaabbcbccaaabcbababaaaccbacbbcaabbacbbbabcccacbaacacccbcccbbbbccaaabaaababcbbaacbcccaaabcbacccaacbbbaabababbbbababcbaaaabbcacbacaaabbcacbccbbbbaabcacbccababaaaacbabbbaaccbccaacacccaaabacaaaacacbbaabcabcbcccbcabaaaccbcbaaaccaacbabcaabbccacbbcbbbcaccbaccacaabcbcccacacaccaabbcaaababbbbbbcabcbbacabbbbbaabcbabbbccaabccabccaaaccabcbcbabbcaccabcbaabaaabacccacacabbaccbabbbacaaabacacabacbcabaabaccacbbaacbcaccaccbacbaacbcbabccbcacbbbcabaabaabbabbcbbbcbbaabababcacacacbcabbccbbbacacccbbbbbbcbabaacacbbbaccbcaaccaccabbabbcbaababbcacaababaababcccbbcaaaabccabbbcbbaacacabaabbaabcaabaacaabcbaaabaccbbcbaaababcacaacabcbbbbabaccbabbccacbbbcbacccbbbcabaaaacacaacbbcabbbbaacacababccaaacaccaaaacbabbcacaabaacaaabcacaabcaaaaaaacbbabbababcbbccbabbabaccbbcccacaabcbccacaacbacbcccbabababababbacbabacbcccccbbcbcbabbbbaacbbabacccbcccbcaccabacaacbbbabacccccbcbbbacaccacccbccbbbcbcbaacbbaabaacbacabacacaaaccaaacabbbaabcaacacbaaabcbbbbcaacaaccbbbccbababcbcacbcbcbbaabcacbbcacaacacccababbcacbbcaaccaacbbabccabbccbacacaccccccbcbbcbabcabbcaabbaabaccababcbcbcbabbcabcbabacaababcbcacbaacbcccbbbcbaacabcccbbabccacaaaaccaabccbbaabababcacabbaccbbacbcbcaacabbaccccabbccbbcabcbcccaabcccbabbacabccaacababcaaaacccbabcccabcccabccbacaacabcbbaacbaacbbcbaaaacbbcaccbacaccaaaccabaaabcbabababbcbbcbacbabaacbbbaacabbbaacbaccccaaccccabcabaabaccacaaacabbbbcbccccbcacaacbcbbbcbabcbccaaabbaccbaacccbaacbbbbcccacbcacabccbbcbabbccabbbaabaacbbacacacccbcbcbaabcccacbccbbcacaababbcbaaabaccaaaaacbbbacaaaaabbacaabacbcaccaacbacbaaaabcbaaabcccccbcacbccacbccccaacaaccbbcbabcbaacbbabbbbaabcacbaaacbbcabcbcbbbcabbbbcbcbacccbcaacaccccbcccacbbbbbacbccaabcbabcacacbbaccbbbaccbcaacacabaaccbccabbccbacbaacbbbbacacccabbbbabaaaabcbabcccacccababbabcabbbaabacbcbaaccccacbbbccccacaaaacabaacaccaabccacbbbccaabbccccbccbbbabacbabacbabcbaccbabbaccaccbabcababbbbcbbcabababaacaccacbacccabcacbbbcccacacabcabccaacbacbcaccbaaaacbbccccccaabbabcbaaaacbbbaabbcacabaccabbcbbbbabbccabcccccbbcbbcccbbacacbaaacccccbbcaacaacabbbcacaaaaaacabacbbbbbacbbacbbcbbbcbbaccaacbcbaaaabbbababbbccccaabacbcaacacbbcacccaacccccbbccbbbbbacbabcabbcacccbcbabbaabbacaabaacabcccbbbbcacabbbaacaaacbabbaccaacabbcbbaaabaccaccacccbbbacaccacbabbaacabbcbbcbbccbbbacbbacbbbabcaababaacbaacaabbacbabbccccaccccaabbaaabcccabccbccaaacbbccabbbcbaaaacabbbbbbcbbacbbcccbbabbacbbccbccccccaabacaabaaaccccaabcacbbccbbabccaacccaababbccbabcbabcccbbabaaaababaabbbcbabbccaacbacccaabccababccabcbbcccaacabbbcbaaabbcaacbbbaabaacbbacbbcacbcabccbbccbcbcbbcbaacacbbbbcacbabbaacccaccbacbbcabbbbabcabaabbcaacabbbbbbccbacacaaacabaacbcbacbaaacabcbbcbbbabaccabaaaacaaaaaacaccbccaabaabcaaabaaababcabcccbbcacbcacaabbaaacbbbbcbabaabaabacacaaccbaacabcacbaaabbacccbccaabbaccabbbbacbcbccbcbbcbcbcbcabcccbccaacacccccbbbabbabcbcbabbacaabcbaabbacbcaccacacccacbabbabacababcbaccaabcbacabbacaaaabccbbbbcaabbccbcccccbccacaababcccacbcbcbccabbcbcbcccccccacaaccbbccccbbbcabbacaacacbbabcaacacbcccacbcbcbaaaaccaabaaabcabcaacaacabaacccabaabbaac"));
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
