/* 竖直打印单词.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你一个字符串 s。请你按照单词在 s 中的出现顺序将它们全部竖直返回。
单词应该以字符串列表的形式返回，必要时用空格补位，但输出尾部的空格需要删除（不允许尾随空格）。
每个单词只能放在一列上，每一列中也只能有一个单词。

 

示例 1：

输入：s = "HOW ARE YOU"
输出：["HAY","ORO","WEU"]
解释：每个单词都应该竖直打印。
 "HAY"
 "ORO"
 "WEU"
示例 2：

输入：s = "TO BE OR NOT TO BE"
输出：["TBONTB","OEROOE","   T"]
解释：题目允许使用空格补位，但不允许输出末尾出现空格。
"TBONTB"
"OEROOE"
"   T"
示例 3：

输入：s = "CONTEST IS COMING"
输出：["CIC","OSO","N M","T I","E N","S G","T"]
 

提示：

1 <= s.length <= 200
s 仅含大写英文字母。
题目数据保证两个单词之间只有一个空格。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/print-words-vertically
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <algorithm>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    vector<string> printVertically(string s) {
        int count = 0, maxLen = 0;
        vector<string> horizonalWords;
        parse(s, count, maxLen, horizonalWords);

        vector<vector<char>> verticalWords(maxLen, vector<char>(count, ' '));
        print(horizonalWords, verticalWords);

        vector<string> table(maxLen, "");
        output(verticalWords, table);

        return table;
    }

    void parse(string& s, int& count, int& maxLen, vector<string>& horizonalWords) {
        s += ' ';
        int start = 0, end = 0;

        while ((end = s.find(' ', start)) != s.npos) {
            int len = end - start;
            string word(s, start, len);
            horizonalWords.push_back(word);

            maxLen = max(maxLen, len);
            ++count;
            start = end + 1;
        }
    }

    void print(vector<string>& horizonalWords, vector<vector<char>>& verticalWords) {
        int column = 0;

        for (string& word : horizonalWords) {
            int row = 0;

            for (char c : word) {
                verticalWords[row++][column] = c;
            }

            ++column;
        }
    }

    void output(vector<vector<char>>& verticalWords, vector<string>& table) {
        int i, j, row = verticalWords.size(), column = verticalWords[0].size();

        for (i = 0; i < row; ++i) {
            int len = column;
            while (verticalWords[i][len - 1] == ' ') {
                --len;
            }

            table[i].resize(len);
            for (j = 0; j < len; ++j) {
                table[i][j] = verticalWords[i][j];
            }
        }
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<string> actual = o.printVertically("HOW ARE YOU");
    vector<string> expected = { {"HAY"},{"ORO"},{"WEU"} };
    check.checkStringVector(expected, actual);

    actual = o.printVertically("TO BE OR NOT TO BE");
    expected = { {"TBONTB"},{"OEROOE"},{"   T"} };
    check.checkStringVector(expected, actual);

    actual = o.printVertically("TO BE OR NOT T B");
    expected = { {"TBONTB"},{"OERO"},{"   T"} };
    check.checkStringVector(expected, actual);

    actual = o.printVertically("CONTEST IS COMING");
    expected = { {"CIC"},{"OSO"},{"N M"},{"T I"},{"E N"},{"S G"},{"T"} };
    check.checkStringVector(expected, actual);

    actual = o.printVertically("A");
    expected = { {"A"} };
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
