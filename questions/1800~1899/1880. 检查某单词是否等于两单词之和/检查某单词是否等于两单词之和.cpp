﻿/* 检查某单词是否等于两单词之和.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
字母的 字母值 取决于字母在字母表中的位置，从 0 开始 计数。即，'a' -> 0、'b' -> 1、'c' -> 2，以此类推。

对某个由小写字母组成的字符串 s 而言，其 数值 就等于将 s 中每个字母的 字母值 按顺序 连接 并 转换 成对应整数。

例如，s = "acb" ，依次连接每个字母的字母值可以得到 "021" ，转换为整数得到 21 。
给你三个字符串 firstWord、secondWord 和 targetWord ，每个字符串都由从 'a' 到 'j' （含 'a' 和 'j' ）的小写英文字母组成。

如果 firstWord 和 secondWord 的 数值之和 等于 targetWord 的数值，返回 true ；否则，返回 false 。

 

示例 1：

输入：firstWord = "acb", secondWord = "cba", targetWord = "cdb"
输出：true
解释：
firstWord 的数值为 "acb" -> "021" -> 21
secondWord 的数值为 "cba" -> "210" -> 210
targetWord 的数值为 "cdb" -> "231" -> 231
由于 21 + 210 == 231 ，返回 true
示例 2：

输入：firstWord = "aaa", secondWord = "a", targetWord = "aab"
输出：false
解释：
firstWord 的数值为 "aaa" -> "000" -> 0
secondWord 的数值为 "a" -> "0" -> 0
targetWord 的数值为 "aab" -> "001" -> 1
由于 0 + 0 != 1 ，返回 false
示例 3：

输入：firstWord = "aaa", secondWord = "a", targetWord = "aaaa"
输出：true
解释：
firstWord 的数值为 "aaa" -> "000" -> 0
secondWord 的数值为 "a" -> "0" -> 0
targetWord 的数值为 "aaaa" -> "0000" -> 0
由于 0 + 0 == 0 ，返回 true
 

提示：

1 <= firstWord.length, secondWord.length, targetWord.length <= 8
firstWord、secondWord 和 targetWord 仅由从 'a' 到 'j' （含 'a' 和 'j' ）的小写英文字母组成。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/check-if-word-equals-summation-of-two-words
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    bool isSumEqual(string firstWord, string secondWord, string targetWord) {
        return getNum(firstWord) + getNum(secondWord) == getNum(targetWord);
    }

    int getNum(string& word) {
        int num = 0; 

        for (char c : word) {
            num = num * 10 + c - 'a';
        }

        return num;
    }
};

int main()
{
    CheckResult check;
    Solution o;

    check.checkBool(true, o.isSumEqual("acb", "cba", "cdb"));
    check.checkBool(false, o.isSumEqual("aaa", "a", "aab"));
    check.checkBool(true, o.isSumEqual("aaa", "a", "aaaa"));
    check.checkBool(true, o.isSumEqual("b", "j", "ba"));
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
