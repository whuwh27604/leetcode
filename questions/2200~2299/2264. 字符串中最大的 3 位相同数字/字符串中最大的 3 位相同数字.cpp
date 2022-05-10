/* 字符串中最大的 3 位相同数字.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你一个字符串 num ，表示一个大整数。如果一个整数满足下述所有条件，则认为该整数是一个 优质整数 ：

该整数是 num 的一个长度为 3 的 子字符串 。
该整数由唯一一个数字重复 3 次组成。
以字符串形式返回 最大的优质整数 。如果不存在满足要求的整数，则返回一个空字符串 "" 。

注意：

子字符串 是字符串中的一个连续字符序列。
num 或优质整数中可能存在 前导零 。
 

示例 1：

输入：num = "6777133339"
输出："777"
解释：num 中存在两个优质整数："777" 和 "333" 。
"777" 是最大的那个，所以返回 "777" 。
示例 2：

输入：num = "2300019"
输出："000"
解释："000" 是唯一一个优质整数。
示例 3：

输入：num = "42352338"
输出：""
解释：不存在长度为 3 且仅由一个唯一数字组成的整数。因此，不存在优质整数。
 

提示：

3 <= num.length <= 1000
num 仅由数字（0 - 9）组成

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/largest-3-same-digit-number-in-string
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    string largestGoodInteger(string num) {
        char prev = 0, digit = 0;
        int consecutive = 0;

        for (char c : num) {
            if (c == prev) {
                ++consecutive;

                if (consecutive == 3 && c > digit) {
                    digit = c;
                }
            }
            else {
                consecutive = 1;
            }

            prev = c;
        }

        return digit == 0 ? "" : string(3, digit);
    }
};

int main()
{
    CheckResult check;
    Solution o;

    check.checkString("777", o.largestGoodInteger("6777133339"));
    check.checkString("000", o.largestGoodInteger("2300019"));
    check.checkString("", o.largestGoodInteger("42352338"));
    check.checkString("111", o.largestGoodInteger("111"));
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
