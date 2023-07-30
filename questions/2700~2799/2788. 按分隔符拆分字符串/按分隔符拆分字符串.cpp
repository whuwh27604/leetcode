/* 按分隔符拆分字符串.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你一个字符串数组 words 和一个字符 separator ，请你按 separator 拆分 words 中的每个字符串。

返回一个由拆分后的新字符串组成的字符串数组，不包括空字符串 。

注意

separator 用于决定拆分发生的位置，但它不包含在结果字符串中。
拆分可能形成两个以上的字符串。
结果字符串必须保持初始相同的先后顺序。


示例 1：

输入：words = ["one.two.three","four.five","six"], separator = "."
输出：["one","two","three","four","five","six"]
解释：在本示例中，我们进行下述拆分：

"one.two.three" 拆分为 "one", "two", "three"
"four.five" 拆分为 "four", "five"
"six" 拆分为 "six"

因此，结果数组为 ["one","two","three","four","five","six"] 。
示例 2：

输入：words = ["$easy$","$problem$"], separator = "$"
输出：["easy","problem"]
解释：在本示例中，我们进行下述拆分：

"$easy$" 拆分为 "easy"（不包括空字符串）
"$problem$" 拆分为 "problem"（不包括空字符串）

因此，结果数组为 ["easy","problem"] 。
示例 3：

输入：words = ["|||"], separator = "|"
输出：[]
解释：在本示例中，"|||" 的拆分结果将只包含一些空字符串，所以我们返回一个空数组 [] 。


提示：

1 <= words.length <= 100
1 <= words[i].length <= 20
words[i] 中的字符要么是小写英文字母，要么就是字符串 ".,|$#@" 中的字符（不包括引号）
separator 是字符串 ".,|$#@" 中的某个字符（不包括引号）
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    vector<string> splitWordsBySeparator(vector<string>& words, char separator) {
        vector<string> ans;

        for (string& word : words) {
            string tmp;

            for (char c : word) {
                if (c == separator) {
                    if (!tmp.empty()) {
                        ans.push_back(tmp);
                    }

                    tmp.clear();
                }
                else {
                    tmp += c;
                }
            }

            if (!tmp.empty()) {
                ans.push_back(tmp);
            }
        }

        return ans;
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<string> words = { "one.two.three","four.five","six" };
    vector<string> actual = o.splitWordsBySeparator(words, '.');
    vector<string> expected = { "one","two","three","four","five","six" };
    check.checkStringVector(expected, actual);

    words = { "$easy$","$problem$" };
    actual = o.splitWordsBySeparator(words, '$');
    expected = { "easy","problem" };
    check.checkStringVector(expected, actual);

    words = { "|||" };
    actual = o.splitWordsBySeparator(words, '|');
    expected = {  };
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
