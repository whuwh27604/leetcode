/* 有效的括号字符串.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给定一个只包含三种字符的字符串：（ ，） 和 *，写一个函数来检验这个字符串是否为有效字符串。有效字符串具有如下规则：

任何左括号 ( 必须有相应的右括号 )。
任何右括号 ) 必须有相应的左括号 ( 。
左括号 ( 必须在对应的右括号之前 )。
* 可以被视为单个右括号 ) ，或单个左括号 ( ，或一个空字符串。
一个空字符串也被视为有效字符串。
示例 1:

输入: "()"
输出: True
示例 2:

输入: "(*)"
输出: True
示例 3:

输入: "(*))"
输出: True
注意:

字符串大小将在 [1，100] 范围内。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/valid-parenthesis-string
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    bool checkValidString(string s) {
        int leftMax = 0, leftMin = 0;

        for (char c : s) {
            if (c == '(') {
                leftMin++;
                leftMax++;
            }
            else if (c == ')') {
                if (leftMin > 0) {  // 如果最小值等于0了，说明前面有'*'选择了')'，到这里没得选了。所以只需要把前面选了')'的'*'改为选'('，那么这里就可以继续走下去了。
                    leftMin--;
                }

                leftMax--;
                if (leftMax < 0) {  // 任何时候最大值小于0了，说明')'一定比'('多，可以返回失败了
                    return false;
                }
            }
            else {
                if (leftMin > 0) {  // 同上
                    leftMin--;
                }
                leftMax++;
            }
        }

        return leftMin == 0;  // 最小可能必须是0，否则说明'('有多余的
    }
};

int main()
{
    Solution o;
    CheckResult check;

    check.checkBool(true, o.checkValidString("()"));
    check.checkBool(true, o.checkValidString("(*)"));
    check.checkBool(true, o.checkValidString("(*))"));
    check.checkBool(false, o.checkValidString(")"));
    check.checkBool(false, o.checkValidString("*))"));
    check.checkBool(true, o.checkValidString("(*****)))"));
    check.checkBool(false, o.checkValidString("(*)**))***)))))"));
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
