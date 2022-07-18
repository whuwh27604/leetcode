/* 基本计算器 IV.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给定一个表达式如 expression = "e + 8 - a + 5" 和一个求值映射，如 {"e": 1}（给定的形式为 evalvars = ["e"] 和 evalints = [1]），返回表示简化表达式的标记列表，例如 ["-1*a","14"]

表达式交替使用块和符号，每个块和符号之间有一个空格。
块要么是括号中的表达式，要么是变量，要么是非负整数。
变量是一个由小写字母组成的字符串（不包括数字）。请注意，变量可以是多个字母，并注意变量从不具有像 "2x" 或 "-x" 这样的前导系数或一元运算符 。
表达式按通常顺序进行求值：先是括号，然后求乘法，再计算加法和减法。

例如，expression = "1 + 2 * 3" 的答案是 ["7"]。
输出格式如下：

对于系数非零的每个自变量项，我们按字典排序的顺序将自变量写在一个项中。
例如，我们永远不会写像 “b*a*c” 这样的项，只写 “a*b*c”。
项的次数等于被乘的自变量的数目，并计算重复项。我们先写出答案的最大次数项，用字典顺序打破关系，此时忽略词的前导系数。
例如，"a*a*b*c" 的次数为 4。
项的前导系数直接放在左边，用星号将它与变量分隔开(如果存在的话)。前导系数 1 仍然要打印出来。
格式良好的一个示例答案是 ["-2*a*a*a", "3*a*a*b", "3*b*b", "4*a", "5*c", "-6"] 。
系数为 0 的项（包括常数项）不包括在内。
例如，“0” 的表达式输出为 [] 。
 

示例 1：

输入：expression = "e + 8 - a + 5", evalvars = ["e"], evalints = [1]
输出：["-1*a","14"]
示例 2：

输入：expression = "e - 8 + temperature - pressure",
evalvars = ["e", "temperature"], evalints = [1, 12]
输出：["-1*pressure","5"]
示例 3：

输入：expression = "(e + 8) * (e - 8)", evalvars = [], evalints = []
输出：["1*e*e","-64"]
 

提示：

1 <= expression.length <= 250
expression 由小写英文字母，数字 '+', '-', '*', '(', ')', ' ' 组成
expression 不包含任何前空格或后空格
expression 中的所有符号都用一个空格隔开
0 <= evalvars.length <= 100
1 <= evalvars[i].length <= 20
evalvars[i] 由小写英文字母组成
evalints.length == evalvars.length
-100 <= evalints[i] <= 100

来源：力扣（LeetCode）
链接：https://leetcode.cn/problems/basic-calculator-iv
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <map>
#include <unordered_map>
#include <algorithm>
#include "../check/CheckResult.h"

using namespace std;

struct vectorComapre {
    bool operator()(const vector<string>& v1, const vector<string>& v2) const {
        if (v1.size() != v2.size()) {
            return v1.size() > v2.size();
        }

        for (int i = 0; i < (int)v1.size(); ++i) {
            if (v1[i] != v2[i]) {
                return v1[i] < v2[i];
            }
        }

        return false;
    }
};

class Poly {
public:
    Poly(string& var) {
        expr[{ var }] = 1;
    }

    Poly(int val) {
        expr[{"{"}] = val;  // 常数的key选择"{" > "z"，这样排序的时候可以排在最后
    }

    Poly() {

    }

    void add(Poly& poly) {
        for (auto& kv : poly.expr) {
            expr[kv.first] += kv.second;
        }
    }

    void sub(Poly& poly) {
        for (auto& kv : poly.expr) {
            expr[kv.first] -= kv.second;
        }
    }

    void mult(Poly& poly) {
        map<vector<string>, int, vectorComapre> ans;
        vector<string> numKey = { "{" };

        for (auto& kv : poly.expr) {
            for (auto& mykv : expr) {
                vector<string> key = kv.first;

                for (auto& s : mykv.first) {
                    key.push_back(s);
                }

                sort(key.begin(), key.end());  // key始终保持有序

                while (key.size() > 1 && key.back() == "{") {
                    key.pop_back();  // 将多余的"{"删除
                }

                ans[key] += kv.second * mykv.second;
            }
        }

        expr = ans;
    }

    vector<string> output() {
        vector<string> ans;

        for (auto& kv : expr) {
            if (kv.second != 0) {
                ans.push_back(to_string(kv.second));

                for (auto& s : kv.first) {
                    if (s != "{") {
                        ans.back() += '*';
                        ans.back() += s;
                    }
                }
            }
        }

        return ans;
    }

private:
    map<vector<string>, int, vectorComapre> expr;
};

class Solution {
public:
    vector<string> basicCalculatorIV(string expression, vector<string>& evalvars, vector<int>& evalints) {
        int index = 0;
        unordered_map<string, int> evals;

        getEvals(evalvars, evalints, evals);

        return parse(expression, index, evals).output();
    }

    void getEvals(vector<string>& evalvars, vector<int>& evalints, unordered_map<string, int>& evals) {
        for (int i = 0; i < (int)evalvars.size(); ++i) {
            evals[evalvars[i]] = evalints[i];
        }
    }

    Poly parse(string& expression, int& index, unordered_map<string, int>& evals) {
        Poly operand1(0), operand2(0), operand3;
        char oper1 = '+', oper2 = '+';  // 记录3个operand和2个operator，如果oper2是*，直接计算operand2 * operand3；如果oper2是+/-，计算operand1 oper1 operand2

        for (; index < (int)expression.size() && expression[index] != ')'; ++index) {  // 遇到 ) 或者结束，计算该operand的最终结果
            char c = expression[index];
            if (c == ' ') {
                continue;
            }

            if (c == '+' || c == '-' || c == '*') {
                oper2 = c;
                continue;
            }

            if (c == '(') {  // 遇到 ( ，递归解析出一个operand
                ++index;
                operand3 = parse(expression, index, evals);
            }
            else if (islower(c)) {
                string var = getVar(expression, index);

                if (evals.count(var) == 0) {
                    operand3 = Poly(var);
                }
                else {
                    operand3 = Poly(evals[var]);
                }
            }
            else if (isdigit(c)) {
                operand3 = Poly(getNumber(expression, index));
            }

            calc(operand1, operand2, operand3, oper1, oper2);
        }

        calc(operand1, operand2, oper1);

        return operand1;
    }

    void calc(Poly& operand1, Poly& operand2, Poly& operand3, char& oper1, char& oper2) {
        if (oper2 == '*') {
            operand2.mult(operand3);
        }
        else {
            if (oper1 == '+') {
                operand1.add(operand2);
            }
            else {
                operand1.sub(operand2);
            }

            operand2 = operand3;
            oper1 = oper2;
        }
    }

    void calc(Poly& operand1, Poly& operand2, char oper) {
        if (oper == '+') {
            operand1.add(operand2);
        }
        else if (oper == '-') {
            operand1.sub(operand2);
        }
        else {
            operand1.mult(operand2);
        }
    }

    string getVar(string& expression, int& index) {
        string var;

        while (index < (int)expression.size() && islower(expression[index])) {
            var += expression[index++];
        }

        --index;

        return var;
    }

    int getNumber(string& expression, int& index) {
        string var;

        while (index < (int)expression.size() && isdigit(expression[index])) {
            var += expression[index++];
        }

        --index;

        return stoi(var);
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<string> evalvars = { "e" };
    vector<int> evalints = { 1 };
    vector<string> actual = o.basicCalculatorIV("e + 8 - a + 5", evalvars, evalints);
    vector<string> expected = { "-1*a","14" };
    check.checkStringVector(expected, actual);

    evalvars = { "e", "temperature" };
    evalints = { 1,12 };
    actual = o.basicCalculatorIV("e - 8 + temperature - pressure", evalvars, evalints);
    expected = { "-1*pressure","5" };
    check.checkStringVector(expected, actual);

    evalvars = {  };
    evalints = {  };
    actual = o.basicCalculatorIV("(e + 8) * (e - 8)", evalvars, evalints);
    expected = { "1*e*e","-64" };
    check.checkStringVector(expected, actual);

    evalvars = {  };
    evalints = {  };
    actual = o.basicCalculatorIV("1 + 2 * 3", evalvars, evalints);
    expected = { "7" };
    check.checkStringVector(expected, actual);

    evalvars = {  };
    evalints = {  };
    actual = o.basicCalculatorIV("0", evalvars, evalints);
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
