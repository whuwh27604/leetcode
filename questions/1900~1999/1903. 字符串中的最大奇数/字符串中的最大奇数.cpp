/* 字符串中的最大奇数.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你一个字符串 num ，表示一个大整数。请你在字符串 num 的所有 非空子字符串 中找出 值最大的奇数 ，并以字符串形式返回。如果不存在奇数，则返回一个空字符串 "" 。

子字符串 是字符串中的一个连续的字符序列。

 

示例 1：

输入：num = "52"
输出："5"
解释：非空子字符串仅有 "5"、"2" 和 "52" 。"5" 是其中唯一的奇数。
示例 2：

输入：num = "4206"
输出：""
解释：在 "4206" 中不存在奇数。
示例 3：

输入：num = "35427"
输出："35427"
解释："35427" 本身就是一个奇数。
 

提示：

1 <= num.length <= 105
num 仅由数字组成且不含前导零

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/largest-odd-number-in-string
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    string largestOddNumber(string num) {
        int i, size = num.size();

        for (i = size - 1; i >= 0; --i) {
            if (((num[i] - '0') & 1) == 1) {
                break;
            }
        }

        return string(num, 0, i + 1);
    }
};

int main()
{
    CheckResult check;
    Solution o;

    check.checkString("5", o.largestOddNumber("52"));
    check.checkString("", o.largestOddNumber("4206"));
    check.checkString("35427", o.largestOddNumber("35427"));
    check.checkString("7", o.largestOddNumber("7"));
    check.checkString("", o.largestOddNumber("6"));
    check.checkString("123456789", o.largestOddNumber("1234567890"));
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
