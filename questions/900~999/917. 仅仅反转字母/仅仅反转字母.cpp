/* 仅仅反转字母.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给定一个字符串 S，返回 “反转后的” 字符串，其中不是字母的字符都保留在原地，而所有字母的位置发生反转。

 

示例 1：

输入："ab-cd"
输出："dc-ba"
示例 2：

输入："a-bC-dEf-ghIj"
输出："j-Ih-gfE-dCba"
示例 3：

输入："Test1ng-Leet=code-Q!"
输出："Qedo1ct-eeLg=ntse-T!"
 

提示：

S.length <= 100
33 <= S[i].ASCIIcode <= 122 
S 中不包含 \ or "

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/reverse-only-letters
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    string reverseOnlyLetters(string S) {
        int headIndex = -1, len = S.size(), tailIndex = len;

        while (1) {
            nextLetter(S, headIndex, len);
            prevLetter(S, tailIndex);

            if (headIndex >= tailIndex) {
                break;
            }

            swap(S[headIndex], S[tailIndex]);
        }

        return S;
    }

    bool isLetter(char c) {
        return (((c >= 'a') && (c <= 'z')) || ((c >= 'A') && (c <= 'Z')));
    }

    void nextLetter(string& S, int& index, int len) {
        index++;
        while (index < len) {
            if (isLetter(S[index])) {
                break;
            }
            index++;
        }
    }

    void prevLetter(string& S, int& index) {
        index--;
        while (index >= 0) {
            if (isLetter(S[index])) {
                break;
            }
            index--;
        }
    }
};

int main()
{
    Solution o;
    CheckResult check;

    string S = "ab-cd";
    string expected = "dc-ba";
    check.checkString(expected, o.reverseOnlyLetters(S));

    S = "a-bC-dEf-ghIj";
    expected = "j-Ih-gfE-dCba";
    check.checkString(expected, o.reverseOnlyLetters(S));

    S = "Test1ng-Leet=code-Q!";
    expected = "Qedo1ct-eeLg=ntse-T!";
    check.checkString(expected, o.reverseOnlyLetters(S));

    S = "";
    expected = "";
    check.checkString(expected, o.reverseOnlyLetters(S));

    S = "-";
    expected = "-";
    check.checkString(expected, o.reverseOnlyLetters(S));

    S = "-a";
    expected = "-a";
    check.checkString(expected, o.reverseOnlyLetters(S));

    S = "a-";
    expected = "a-";
    check.checkString(expected, o.reverseOnlyLetters(S));

    S = "a";
    expected = "a";
    check.checkString(expected, o.reverseOnlyLetters(S));

    S = "ab";
    expected = "ba";
    check.checkString(expected, o.reverseOnlyLetters(S));

    S = "-a-b-";
    expected = "-b-a-";
    check.checkString(expected, o.reverseOnlyLetters(S));

    S = "-a-b-c-";
    expected = "-c-b-a-";
    check.checkString(expected, o.reverseOnlyLetters(S));
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
