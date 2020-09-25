/* 迷你语法分析器.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给定一个用字符串表示的整数的嵌套列表，实现一个解析它的语法分析器。

列表中的每个元素只可能是整数或整数嵌套列表

提示：你可以假定这些字符串都是格式良好的：

字符串非空
字符串不包含空格
字符串只包含数字0-9、[、-、,、]
 

示例 1：

给定 s = "324",

你应该返回一个 NestedInteger 对象，其中只包含整数值 324。
示例 2：

给定 s = "[123,[456,[789]]]",

返回一个 NestedInteger 对象包含一个有两个元素的嵌套列表：

1. 一个 integer 包含值 123
2. 一个包含两个元素的嵌套列表：
    i.  一个 integer 包含值 456
    ii. 一个包含一个元素的嵌套列表
         a. 一个 integer 包含值 789

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/mini-parser
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <stack>
#include "../header/NestedInteger.h"
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    NestedInteger deserialize(string s) {
        int index = 0, size = s.size(), end, number;
        stack<NestedInteger> niStack;

        if (s[0] != '[') {
            number = getNumber(s, index, end);
            NestedInteger ni(number);
            return ni;
        }

        while (index < size) {
            if (s[index] == '[') {
                NestedInteger ni;
                niStack.push(ni);
            }
            else if ((s[index] == '-') || ((s[index] >= '0') && (s[index] <= '9'))) {
                number = getNumber(s, index, end);
                NestedInteger ni(number);
                niStack.top().add(ni);
                index = end - 1;
            }
            else if (s[index] == ']') {
                NestedInteger ni = niStack.top();
                niStack.pop();
                if (niStack.empty()) {
                    niStack.push(ni);
                }
                else {
                    niStack.top().add(ni);
                }
            }

            index++;
        }

        return niStack.top();
    }

    int getNumber(string& s, int start, int& end) {
        bool negative = false;
        int index = start, number = 0, size = s.size();

        if (s[start] == '-') {
            negative = true;
            index += 1;
        }

        while ((index < size) && (s[index] >= '0') && (s[index] <= '9')) {
            number = number * 10 + s[index++] - '0';
        }

        end = index;
        return negative ? -number : number;
    }
};

int main()
{
    Solution o;
    CheckResult check;

    NestedInteger actual = o.deserialize("1");
    check.checkBool(true, actual.isInteger());
    check.checkInt(1, actual.getInteger());

    actual = o.deserialize("-324");
    check.checkBool(true, actual.isInteger());
    check.checkInt(-324, actual.getInteger());

    actual = o.deserialize("[-324]");
    check.checkBool(false, actual.isInteger());
    check.checkBool(true, actual.getList()[0].isInteger());
    check.checkInt(-324, actual.getList()[0].getInteger());

    actual = o.deserialize("[[[-324]]]");
    check.checkBool(false, actual.isInteger());
    check.checkBool(false, actual.getList()[0].isInteger());
    check.checkBool(false, actual.getList()[0].getList()[0].isInteger());
    check.checkBool(true, actual.getList()[0].getList()[0].getList()[0].isInteger());
    check.checkInt(-324, actual.getList()[0].getList()[0].getList()[0].getInteger());

    actual = o.deserialize("[[-324],[4567]]");
    check.checkBool(false, actual.isInteger());
    check.checkBool(false, actual.getList()[0].isInteger());
    check.checkBool(true, actual.getList()[0].getList()[0].isInteger());
    check.checkInt(-324, actual.getList()[0].getList()[0].getInteger());
    check.checkBool(false, actual.getList()[1].isInteger());
    check.checkBool(true, actual.getList()[1].getList()[0].isInteger());
    check.checkInt(4567, actual.getList()[1].getList()[0].getInteger());

    actual = o.deserialize("[-1,-2]");
    check.checkBool(false, actual.isInteger());
    check.checkBool(true, actual.getList()[0].isInteger());
    check.checkInt(-1, actual.getList()[0].getInteger());
    check.checkBool(true, actual.getList()[1].isInteger());
    check.checkInt(-2, actual.getList()[1].getInteger());

    actual = o.deserialize("[1,[-2]]");
    check.checkBool(false, actual.isInteger());
    check.checkBool(true, actual.getList()[0].isInteger());
    check.checkInt(1, actual.getList()[0].getInteger());
    check.checkBool(false, actual.getList()[1].isInteger());
    check.checkBool(true, actual.getList()[1].getList()[0].isInteger());
    check.checkInt(-2, actual.getList()[1].getList()[0].getInteger());
    
    actual = o.deserialize("[123,[456,[789]]]");
    check.checkBool(false, actual.isInteger());
    check.checkBool(true, actual.getList()[0].isInteger());
    check.checkInt(123, actual.getList()[0].getInteger());
    check.checkBool(false, actual.getList()[1].isInteger());
    check.checkBool(true, actual.getList()[1].getList()[0].isInteger());
    check.checkInt(456, actual.getList()[1].getList()[0].getInteger());
    check.checkBool(false, actual.getList()[1].getList()[1].isInteger());
    check.checkBool(true, actual.getList()[1].getList()[1].getList()[0].isInteger());
    check.checkInt(789, actual.getList()[1].getList()[1].getList()[0].getInteger());
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
