/* 整数反转.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给出一个 32 位的有符号整数，你需要将这个整数中每位上的数字进行反转。

示例 1:

输入: 123
输出: 321
 示例 2:

输入: -123
输出: -321
示例 3:

输入: 120
输出: 21
注意:

假设我们的环境只能存储得下 32 位的有符号整数，则其数值范围为 [−231,  231 − 1]。请根据这个假设，如果反转后整数溢出那么就返回 0。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/reverse-integer
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int reverse(int x) {
        string s = to_string(x);
        std::reverse(x < 0 ? s.begin() + 1 : s.begin(), s.end());

        long long longdata = stoll(s);
        return ((longdata < INT_MIN) || (longdata > INT_MAX)) ? 0 : (int)longdata;
    }
};

int main()
{
    Solution o;
    CheckResult check;
    check.checkInt(321, o.reverse(123));
    check.checkInt(21, o.reverse(120));
    check.checkInt(0, o.reverse(2147483647));
    check.checkInt(-321, o.reverse(-123));
    check.checkInt(0, o.reverse(-2147483648));
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
