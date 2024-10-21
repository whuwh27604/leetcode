/* 出现在屏幕上的字符串序列.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你一个字符串 target。

Alice 将会使用一种特殊的键盘在她的电脑上输入 target，这个键盘 只有两个 按键：

按键 1：在屏幕上的字符串后追加字符 'a'。
按键 2：将屏幕上字符串的 最后一个 字符更改为英文字母表中的 下一个 字符。例如，'c' 变为 'd'，'z' 变为 'a'。
注意，最初屏幕上是一个空字符串 ""，所以她 只能 按按键 1。

请你考虑按键次数 最少 的情况，按字符串出现顺序，返回 Alice 输入 target 时屏幕上出现的所有字符串列表。



示例 1：

输入： target = "abc"

输出： ["a","aa","ab","aba","abb","abc"]

解释：

Alice 按键的顺序如下：

按下按键 1，屏幕上的字符串变为 "a"。
按下按键 1，屏幕上的字符串变为 "aa"。
按下按键 2，屏幕上的字符串变为 "ab"。
按下按键 1，屏幕上的字符串变为 "aba"。
按下按键 2，屏幕上的字符串变为 "abb"。
按下按键 2，屏幕上的字符串变为 "abc"。
示例 2：

输入： target = "he"

输出： ["a","b","c","d","e","f","g","h","ha","hb","hc","hd","he"]



提示：

1 <= target.length <= 400
target 仅由小写英文字母组成。
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    vector<string> stringSequence(string target) {
        int size = (int)target.size();
        string s = "a";
        vector<string> seqs;

        for (int i = 0; i < size; ++i) {
            while (s.back() != target[i]) {
                seqs.push_back(s);
                s.back() += 1;
            }

            seqs.push_back(s);
            s += 'a';
        }

        return seqs;
    }
};

int main()
{
    Solution o;
    CheckResult check;

    vector<string> actual = o.stringSequence("abc");
    vector<string> expected = { "a","aa","ab","aba","abb","abc" };
    check.checkStringVector(expected, actual);

    actual = o.stringSequence("he");
    expected = { "a","b","c","d","e","f","g","h","ha","hb","hc","hd","he" };
    check.checkStringVector(expected, actual);

    actual = o.stringSequence("aa");
    expected = { "a","aa" };
    check.checkStringVector(expected, actual);

    actual = o.stringSequence("z");
    expected = { "a","b","c","d","e","f","g","h","i","j","k","l","m","n","o","p","q","r","s","t","u","v","w","x","y","z" };
    check.checkStringVector(expected, actual);
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
