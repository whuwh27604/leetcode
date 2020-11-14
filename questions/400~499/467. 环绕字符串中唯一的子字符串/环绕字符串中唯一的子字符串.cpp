/* 环绕字符串中唯一的子字符串.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
把字符串 s 看作是“abcdefghijklmnopqrstuvwxyz”的无限环绕字符串，所以 s 看起来是这样的："...zabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcd....". 

现在我们有了另一个字符串 p 。你需要的是找出 s 中有多少个唯一的 p 的非空子串，尤其是当你的输入是字符串 p ，你需要输出字符串 s 中 p 的不同的非空子串的数目。 

注意: p 仅由小写的英文字母组成，p 的大小可能超过 10000。

 

示例 1:

输入: "a"
输出: 1
解释: 字符串 S 中只有一个"a"子字符。
 

示例 2:

输入: "cac"
输出: 2
解释: 字符串 S 中的字符串“cac”只有两个子串“a”、“c”。.
 

示例 3:

输入: "zab"
输出: 6
解释: 在字符串 S 中有六个子串“z”、“a”、“b”、“za”、“ab”、“zab”。.

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/unique-substrings-in-wraparound-string
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int findSubstringInWraproundString(string p) {
        int i = 0, size = p.size(), substringLen = 1, count = 0;
        int endAtLetterLen[123] = { 0 };
        char prev = 0;

        for (i = 0; i < size; i++) {
            char c = p[i];
            if ((c == prev + 1) || ((c == 'a') && prev == 'z')) {
                substringLen++;
            }
            else {
                substringLen = 1;
            }

            endAtLetterLen[c] = endAtLetterLen[c] > substringLen ? endAtLetterLen[c] : substringLen;
            prev = c;
        }

        for (char c = 'a'; c <= 'z'; c++) {
            count += endAtLetterLen[c];
        }

        return count;
    }
};

int main()
{
    Solution o;
    CheckResult check;

    check.checkInt(1, o.findSubstringInWraproundString("a"));
    check.checkInt(3, o.findSubstringInWraproundString("za"));
    check.checkInt(2, o.findSubstringInWraproundString("cac"));
    check.checkInt(6, o.findSubstringInWraproundString("zab"));
    check.checkInt(0, o.findSubstringInWraproundString(""));
    check.checkInt(10, o.findSubstringInWraproundString("zabcabc"));
    check.checkInt(16, o.findSubstringInWraproundString("zabcefg"));
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
