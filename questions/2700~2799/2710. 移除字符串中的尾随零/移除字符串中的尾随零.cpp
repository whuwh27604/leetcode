/* 移除字符串中的尾随零.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你一个用字符串表示的正整数 num ，请你以字符串形式返回不含尾随零的整数 num 。



示例 1：

输入：num = "51230100"
输出："512301"
解释：整数 "51230100" 有 2 个尾随零，移除并返回整数 "512301" 。
示例 2：

输入：num = "123"
输出："123"
解释：整数 "123" 不含尾随零，返回整数 "123" 。


提示：

1 <= num.length <= 1000
num 仅由数字 0 到 9 组成
num 不含前导零
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    string removeTrailingZeros(string num) {
        while (num.size() > 1 && num.back() == '0') {
            num.pop_back();
        }

        return num;
    }
};

int main()
{
    CheckResult check;
    Solution o;

    check.checkString("512301", o.removeTrailingZeros("51230100"));
    check.checkString("123", o.removeTrailingZeros("123"));
    check.checkString("0", o.removeTrailingZeros("0"));
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
