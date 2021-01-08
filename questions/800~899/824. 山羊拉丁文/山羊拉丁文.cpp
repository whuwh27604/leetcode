/* 山羊拉丁文.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给定一个由空格分割单词的句子 S。每个单词只包含大写或小写字母。

我们要将句子转换为 “Goat Latin”（一种类似于 猪拉丁文 - Pig Latin 的虚构语言）。

山羊拉丁文的规则如下：

如果单词以元音开头（a, e, i, o, u），在单词后添加"ma"。
例如，单词"apple"变为"applema"。

如果单词以辅音字母开头（即非元音字母），移除第一个字符并将它放到末尾，之后再添加"ma"。
例如，单词"goat"变为"oatgma"。

根据单词在句子中的索引，在单词最后添加与索引相同数量的字母'a'，索引从1开始。
例如，在第一个单词后添加"a"，在第二个单词后添加"aa"，以此类推。
返回将 S 转换为山羊拉丁文后的句子。

示例 1:

输入: "I speak Goat Latin"
输出: "Imaa peaksmaaa oatGmaaaa atinLmaaaaa"
示例 2:

输入: "The quick brown fox jumped over the lazy dog"
输出: "heTmaa uickqmaaa rownbmaaaa oxfmaaaaa umpedjmaaaaaa overmaaaaaaa hetmaaaaaaaa azylmaaaaaaaaa ogdmaaaaaaaaaa"
说明:

S 中仅包含大小写字母和空格。单词间有且仅有一个空格。
1 <= S.length <= 150。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/goat-latin
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    string toGoatLatin(string S) {
        int vowelTable[26] = { 1,0,0,0,1,0,0,0,1,0,0,0,0,0,1,0,0,0,0,0,1,0,0,0,0,0 };
        string ans;
        int numberOfA = 1;
        char* p = const_cast<char*>(S.c_str());
        char* context;
        p = strtok_s(p, " ", &context);
        while (p != NULL) {
            string oneWord(p);
            int index = ((p[0] >= 'a') ? (p[0] - 'a') : (p[0] - 'A'));
            if (vowelTable[index] == 0) {
                oneWord.push_back(p[0]);
                oneWord.erase(oneWord.begin());
            }
            oneWord += "ma";
            oneWord.insert(oneWord.end(), numberOfA++, 'a');
            ans += oneWord;
            ans += " ";

            p = strtok_s(NULL, " ", &context);
        }

        ans.pop_back();
        return ans;
    }
};

int main()
{
    Solution o;
    CheckResult check;

    check.checkString("Imaa peaksmaaa oatGmaaaa atinLmaaaaa", o.toGoatLatin("I speak Goat Latin"));
    check.checkString("heTmaa uickqmaaa rownbmaaaa oxfmaaaaa umpedjmaaaaaa overmaaaaaaa hetmaaaaaaaa azylmaaaaaaaaa ogdmaaaaaaaaaa", o.toGoatLatin("The quick brown fox jumped over the lazy dog"));
    check.checkString("Amaa", o.toGoatLatin("A"));
    check.checkString("Bmaa", o.toGoatLatin("B"));
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
