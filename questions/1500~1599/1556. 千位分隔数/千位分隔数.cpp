/* 千位分隔数.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你一个整数 n，请你每隔三位添加点（即 "." 符号）作为千位分隔符，并将结果以字符串格式返回。

 

示例 1：

输入：n = 987
输出："987"
示例 2：

输入：n = 1234
输出："1.234"
示例 3：

输入：n = 123456789
输出："123.456.789"
示例 4：

输入：n = 0
输出："0"
 

提示：

0 <= n < 2^31

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/thousand-separator
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    string thousandSeparator(int n) {
        string s = to_string(n);
        int size = s.size();
        int index = size % 3;
        string separator(s, 0, index);

        while (index < size) {
            if (!separator.empty()) {
                separator += '.';
            }
            separator.insert(separator.size(), s, index, 3);
            index += 3;
        }

        return separator;
    }
};

int main()
{
    CheckResult check;
    Solution o;

    check.checkString("0", o.thousandSeparator(0));
    check.checkString("1", o.thousandSeparator(1));
    check.checkString("11", o.thousandSeparator(11));
    check.checkString("111", o.thousandSeparator(111));
    check.checkString("1.111", o.thousandSeparator(1111));
    check.checkString("11.111", o.thousandSeparator(11111));
    check.checkString("111.111", o.thousandSeparator(111111));
    check.checkString("1.111.111", o.thousandSeparator(1111111));
    check.checkString("11.111.111", o.thousandSeparator(11111111));
    check.checkString("111.111.111", o.thousandSeparator(111111111));
    check.checkString("1.111.111.111", o.thousandSeparator(1111111111));
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
