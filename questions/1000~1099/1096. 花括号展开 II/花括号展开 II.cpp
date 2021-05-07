/* 花括号展开 II.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
如果你熟悉 Shell 编程，那么一定了解过花括号展开，它可以用来生成任意字符串。

花括号展开的表达式可以看作一个由 花括号、逗号 和 小写英文字母 组成的字符串，定义下面几条语法规则：

如果只给出单一的元素 x，那么表达式表示的字符串就只有 "x"。R(x) = {x}
例如，表达式 {"a"} 表示字符串 "a"。
而表达式 {"w"} 就表示字符串 "w"。
当两个或多个表达式并列，以逗号分隔时，我们取这些表达式中元素的并集。R({e_1,e_2,...}) = R(e_1) ∪ R(e_2) ∪ ...
例如，表达式 "{a,b,c}" 表示字符串 "a","b","c"。
而表达式 "{{a,b},{b,c}}" 也可以表示字符串 "a","b","c"。
要是两个或多个表达式相接，中间没有隔开时，我们从这些表达式中各取一个元素依次连接形成字符串。R(e_1 + e_2) = {a + b for (a, b) in R(e_1) × R(e_2)}
例如，表达式 "{a,b}{c,d}" 表示字符串 "ac","ad","bc","bd"。
表达式之间允许嵌套，单一元素与表达式的连接也是允许的。
例如，表达式 "a{b,c,d}" 表示字符串 "ab","ac","ad"​​​​​​。
例如，表达式 "a{b,c}{d,e}f{g,h}" 可以表示字符串 "abdfg", "abdfh", "abefg", "abefh", "acdfg", "acdfh", "acefg", "acefh"。
给出表示基于给定语法规则的表达式 expression，返回它所表示的所有字符串组成的有序列表。

假如你希望以「集合」的概念了解此题，也可以通过点击 “显示英文描述” 获取详情。

 

示例 1：

输入："{a,b}{c,{d,e}}"
输出：["ac","ad","ae","bc","bd","be"]
示例 2：

输入："{{a,z},a{b,c},{ab,z}}"
输出：["a","ab","ac","z"]
解释：输出中 不应 出现重复的组合结果。
 

提示：

1 <= expression.length <= 50
expression[i] 由 '{'，'}'，',' 或小写英文字母组成
给出的表达式 expression 用以表示一组基于题目描述中语法构造的字符串

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/brace-expansion-ii
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <unordered_set>
#include <algorithm>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    vector<string> braceExpansionII(string expression) {
        unordered_set<string> value;
        vector<string> ans;

        braceExpansion(expression, 0, expression.size() - 1, value);

        for (auto iter = value.begin(); iter != value.end(); ++iter) {
            ans.push_back(*iter);
        }

        sort(ans.begin(), ans.end());

        return ans;
    }

    void braceExpansion(string& expression, int start, int end, unordered_set<string>& value) {
        unordered_set<string> value1, value2;

        for (int i = start; i <= end; ++i) {
            if (expression[i] == '{') {
                value2.clear();
                int right = getRightBrace(expression, i);
                braceExpansion(expression, i + 1, right - 1, value2);
                value1 = concatenate(value1, value2);
                i = right;
            }
            else if (expression[i] == ',') {
                merge(value, value1);
                value1.clear();
            }
            else if (expression[i] >= 'a' && expression[i] <= 'z') {
                string str = getString(expression, i);
                value2 = { str };
                value1 = concatenate(value1, value2);
                i += (str.size() - 1);
            }
        }

        merge(value, value1);
    }

    int getRightBrace(string& expression, int start) {
        int i, brace = 1;

        for (i = start + 1; brace != 0; ++i) {
            if (expression[i] == '{') {
                ++brace;
            }
            else if (expression[i] == '}') {
                --brace;
            }
        }

        return i - 1;
    }

    string getString(string& expression, int start) {
        int i, size = expression.size();

        for (i = start + 1; i < size && expression[i] >= 'a' && expression[i] <= 'z'; ++i) {}

        return string(expression, start, i - start);
    }

    unordered_set<string> concatenate(unordered_set<string>& value1, unordered_set<string>& value2) {
        if (value1.empty()) {
            return value2;
        }

        unordered_set<string> value;

        for (auto it1 = value1.begin(); it1 != value1.end(); ++it1) {
            for (auto it2 = value2.begin(); it2 != value2.end(); ++it2) {
                value.insert(*it1 + *it2);
            }
        }

        return value;
    }

    void merge(unordered_set<string>& value1, unordered_set<string>& value2) {
        for (auto it2 = value2.begin(); it2 != value2.end(); ++it2) {
            value1.insert(*it2);
        }
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<string> actual = o.braceExpansionII("a");
    vector<string> expected = { "a" };
    check.checkStringVector(expected, actual);

    actual = o.braceExpansionII("{a,b}");
    expected = { "a","b" };
    check.checkStringVector(expected, actual);

    actual = o.braceExpansionII("{a}{b}");
    expected = { "ab" };
    check.checkStringVector(expected, actual);

    actual = o.braceExpansionII("{a,b}{c,{d,e}}");
    expected = { "ac","ad","ae","bc","bd","be" };
    check.checkStringVector(expected, actual);

    actual = o.braceExpansionII("{{a,z},a{b,c},{ab,z}}");
    expected = { "a","ab","ac","z" };
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
