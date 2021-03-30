/* 替换字符串中的括号内容.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你一个字符串 s ，它包含一些括号对，每个括号中包含一个 非空 的键。

比方说，字符串 "(name)is(age)yearsold" 中，有 两个 括号对，分别包含键 "name" 和 "age" 。
你知道许多键对应的值，这些关系由二维字符串数组 knowledge 表示，其中 knowledge[i] = [keyi, valuei] ，表示键 keyi 对应的值为 valuei 。

你需要替换 所有 的括号对。当你替换一个括号对，且它包含的键为 keyi 时，你需要：

将 keyi 和括号用对应的值 valuei 替换。
如果从 knowledge 中无法得知某个键对应的值，你需要将 keyi 和括号用问号 "?" 替换（不需要引号）。
knowledge 中每个键最多只会出现一次。s 中不会有嵌套的括号。

请你返回替换 所有 括号对后的结果字符串。

 

示例 1：

输入：s = "(name)is(age)yearsold", knowledge = [["name","bob"],["age","two"]]
输出："bobistwoyearsold"
解释：
键 "name" 对应的值为 "bob" ，所以将 "(name)" 替换为 "bob" 。
键 "age" 对应的值为 "two" ，所以将 "(age)" 替换为 "two" 。
示例 2：

输入：s = "hi(name)", knowledge = [["a","b"]]
输出："hi?"
解释：由于不知道键 "name" 对应的值，所以用 "?" 替换 "(name)" 。
示例 3：

输入：s = "(a)(a)(a)aaa", knowledge = [["a","yes"]]
输出："yesyesyesaaa"
解释：相同的键在 s 中可能会出现多次。
键 "a" 对应的值为 "yes" ，所以将所有的 "(a)" 替换为 "yes" 。
注意，不在括号里的 "a" 不需要被替换。
示例 4：

输入：s = "(a)(b)", knowledge = [["a","b"],["b","a"]]
输出："ba"
 

提示：

1 <= s.length <= 105
0 <= knowledge.length <= 105
knowledge[i].length == 2
1 <= keyi.length, valuei.length <= 10
s 只包含小写英文字母和圆括号 '(' 和 ')' 。
s 中每一个左圆括号 '(' 都有对应的右圆括号 ')' 。
s 中每对括号内的键都不会为空。
s 中不会有嵌套括号对。
keyi 和 valuei 只包含小写英文字母。
knowledge 中的 keyi 不会重复。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/evaluate-the-bracket-pairs-of-a-string
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <unordered_map>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    string evaluate(string s, vector<vector<string>>& knowledge) {
        int i, j, size = s.size();
        string ans;
        unordered_map<string, string> keyValues;
        getKeyValues(knowledge, keyValues);

        for (i = 0; i < size; ++i) {
            if (s[i] == '(') {
                for (j = i + 1; s[j] != ')'; ++j) {}
                string key(s, i + 1, j - 1 - i);
                ans += keyValues.count(key) == 0 ? "?" : keyValues[key];
                i = j;
            }
            else {
                ans += s[i];
            }
        }

        return ans;
    }

    void getKeyValues(vector<vector<string>>& knowledge, unordered_map<string, string>& keyValues) {
        for (auto& keyValue : knowledge) {
            keyValues[keyValue[0]] = keyValue[1];
        }
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<vector<string>> knowledge = { {"name","bob"},{"age","two"} };
    check.checkString("bobistwoyearsold", o.evaluate("(name)is(age)yearsold", knowledge));

    knowledge = { {"a","b"} };
    check.checkString("hi?", o.evaluate("hi(name)", knowledge));

    knowledge = { {"a","yes"} };
    check.checkString("yesyesyesaaa", o.evaluate("(a)(a)(a)aaa", knowledge));

    knowledge = { {"a","b"},{"b","a"} };
    check.checkString("ba", o.evaluate("(a)(b)", knowledge));

    knowledge = { {"a","a"} };
    check.checkString("a", o.evaluate("(a)", knowledge));

    knowledge = { {"a","a"} };
    check.checkString("?", o.evaluate("(b)", knowledge));

    knowledge = {  };
    check.checkString("z", o.evaluate("z", knowledge));
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
