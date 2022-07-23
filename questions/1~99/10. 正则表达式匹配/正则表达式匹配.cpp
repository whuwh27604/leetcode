/* 正则表达式匹配.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你一个字符串 s 和一个字符规律 p，请你来实现一个支持 '.' 和 '*' 的正则表达式匹配。

'.' 匹配任意单个字符
'*' 匹配零个或多个前面的那一个元素
所谓匹配，是要涵盖 整个 字符串 s的，而不是部分字符串。

 
示例 1：

输入：s = "aa", p = "a"
输出：false
解释："a" 无法匹配 "aa" 整个字符串。
示例 2:

输入：s = "aa", p = "a*"
输出：true
解释：因为 '*' 代表可以匹配零个或多个前面的那一个元素, 在这里前面的元素就是 'a'。因此，字符串 "aa" 可被视为 'a' 重复了一次。
示例 3：

输入：s = "ab", p = ".*"
输出：true
解释：".*" 表示可匹配零个或多个（'*'）任意字符（'.'）。
 

提示：

1 <= s.length <= 20
1 <= p.length <= 30
s 只包含从 a-z 的小写字母。
p 只包含从 a-z 的小写字母，以及字符 . 和 *。
保证每次出现字符 * 时，前面都匹配到有效的字符

来源：力扣（LeetCode）
链接：https://leetcode.cn/problems/regular-expression-matching
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    bool isMatch(string s, string p) {
        int i, j, k, size1 = s.size(), size2 = p.size();
        vector<vector<bool>> match(size1 + 1, vector<bool>(size2 + 1, false));
        match[size1][size2] = true;  // 两个空字符串匹配

        for (j = size2 - 1; j >= 0 && p[j] == '*'; j -= 2) {  // 末尾的x*可以匹配到空字符串
            match[size1][j - 1] = true;
        }

        for (i = size1 - 1; i >= 0; --i) {
            for (j = size2 - 1; j >= 0; --j) {
                if (p[j] >= 'a' && p[j] <= 'z') {
                    if (j != size2 - 1 && p[j + 1] == '*') {  // 后面是*
                        if (match[i][j + 2]) {  // x*匹配0次
                            match[i][j] = true;
                        }
                        else {
                            for (k = i; k < size1 && s[k] == p[j]; ++k) {  // x*匹配1,2,3...次
                                if (match[k + 1][j + 2]) {
                                    match[i][j] = true;
                                    break;
                                }
                            }
                        }
                    }
                    else {  // 后面不是*，匹配当前字符，然后看剩下的是否匹配
                        match[i][j] = (s[i] == p[j] && match[i + 1][j + 1]);
                    }
                }
                else if (p[j] == '.') {
                    if (j != size2 - 1 && p[j + 1] == '*') {  // 后面是*，.*可以匹配任意长度的字符串
                        for (k = i; k <= size1; ++k) {
                            if (match[k][j + 2]) {
                                match[i][j] = true;
                                break;
                            }
                        }
                    }
                    else {  // 后面不是*，当前字符肯定匹配，看剩下的是否匹配
                        match[i][j] = match[i + 1][j + 1];
                    }
                }
            }
        }

        return match[0][0];
    }
};

int main()
{
    CheckResult check;
    Solution o;

    check.checkBool(true, o.isMatch("aa", "a*"));
    check.checkBool(true, o.isMatch("ab", ".*"));
    check.checkBool(true, o.isMatch("abc", ".*"));
    check.checkBool(true, o.isMatch("aab", "c*a*b"));
    check.checkBool(true, o.isMatch("aaa", "ab*ac*a"));
    check.checkBool(true, o.isMatch("abbbb", "ab*"));
    check.checkBool(true, o.isMatch("a", "ab*"));
    check.checkBool(false, o.isMatch("aa", "a"));
    check.checkBool(false, o.isMatch("a", "aa"));
    check.checkBool(false, o.isMatch("mississippi", "mis*is*p*."));
    check.checkBool(false, o.isMatch("ab", ".*c"));
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
