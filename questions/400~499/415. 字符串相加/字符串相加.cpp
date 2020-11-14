/* 字符串相加.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给定两个字符串形式的非负整数 num1 和num2 ，计算它们的和。

注意：

num1 和num2 的长度都小于 5100.
num1 和num2 都只包含数字 0-9.
num1 和num2 都不包含任何前导零。
你不能使用任何內建 BigInteger 库， 也不能直接将输入的字符串转换为整数形式。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/add-strings
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <algorithm>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    string addStrings(string num1, string num2) {
        int i, sum, carrier = 0;
        int size1 = num1.size(), size2 = num2.size(), size = max(size1, size2);
        string sumString(size, 0);

        for (i = 0; i < size1 && i < size2; i++) {
            sum = num1[size1 - 1 - i] - '0' + num2[size2 - 1 - i] - '0' + carrier;
            sumString[size - 1 - i] = (sum % 10 + '0');
            carrier = sum / 10;
        }

        for (; i < size1; i++) {
            sum = num1[size1 - 1 - i] - '0' + carrier;
            sumString[size - 1 - i] = (sum % 10 + '0');
            carrier = sum / 10;
        }

        for (; i < size2; i++) {
            sum = num2[size2 - 1 - i] - '0' + carrier;
            sumString[size - 1 - i] = (sum % 10 + '0');
            carrier = sum / 10;
        }

        if (carrier == 1) {
            sumString.insert(sumString.begin(), '1');
        }

        return sumString;
    }
};

int main()
{
    Solution o;
    CheckResult check;

    check.checkString("4690", o.addStrings("123", "4567"));
    check.checkString("579", o.addStrings("123", "456"));
    check.checkString("10000", o.addStrings("1", "9999"));
    check.checkString("0", o.addStrings("0", "0"));
    check.checkString("9999", o.addStrings("0", "9999"));
    check.checkString("99100", o.addStrings("99099", "1"));
    check.checkString("10000", o.addStrings("1111", "8889"));
    check.checkString("3333333333333333333333333333333333333333333333333333333333333333333333", o.addStrings("1111111111111111111111111111111111111111111111111111111111111111111111", "2222222222222222222222222222222222222222222222222222222222222222222222"));
    check.checkString("10000000000000000000000000000000000000000000000000000000000000000000000", o.addStrings("1111111111111111111111111111111111111111111111111111111111111111111111", "8888888888888888888888888888888888888888888888888888888888888888888889"));
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
