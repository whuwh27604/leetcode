/* 累加数.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
累加数是一个字符串，组成它的数字可以形成累加序列。

一个有效的累加序列必须至少包含 3 个数。除了最开始的两个数以外，字符串中的其他数都等于它之前两个数相加的和。

给定一个只包含数字 '0'-'9' 的字符串，编写一个算法来判断给定输入是否是累加数。

说明: 累加序列里的数不会以 0 开头，所以不会出现 1, 2, 03 或者 1, 02, 3 的情况。

示例 1:

输入: "112358"
输出: true
解释: 累加序列为: 1, 1, 2, 3, 5, 8 。1 + 1 = 2, 1 + 2 = 3, 2 + 3 = 5, 3 + 5 = 8
示例 2:

输入: "199100199"
输出: true
解释: 累加序列为: 1, 99, 100, 199。1 + 99 = 100, 99 + 100 = 199
进阶:
你如何处理一个溢出的过大的整数输入?

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/additive-number
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <algorithm>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    bool isAdditiveNumber(string num) {
        int len1, len2, size = num.size(), half = (size + 1) / 2;

        for (len1 = 1; len1 < half; ++len1) {
            for (len2 = 1; size - len1 - len2 >= max(len1, len2); ++len2) {
                string num1(num, 0, len1), num2(num, len1, len2);  // 枚举前两个数
                if (check(num, num1, num2, len1 + len2)) {
                    return true;
                }
            }
        }

        return false;
    }

    bool check(string& num, string& num1, string& num2, int start) {
        if (start == num.size()) {
            return true;
        }

        if ((num1[0] == '0' && num1.size() != 1) || (num2[0] == '0' && num2.size() != 1)) {  // 不能有前导0
            return false;
        }

        string sum = add(num1, num2);
        if (start + sum.size() > num.size() || sum != string(num, start, sum.size())) {
            return false;
        }

        return check(num, num2, sum, start + sum.size());
    }

    string add(string& num1, string& num2) {
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
    CheckResult check;
    Solution o;

    check.checkBool(true, o.isAdditiveNumber("112358"));
    check.checkBool(true, o.isAdditiveNumber("199100199"));
    check.checkBool(true, o.isAdditiveNumber("121474836472147483648"));
    check.checkBool(false, o.isAdditiveNumber("1123581"));
    check.checkBool(false, o.isAdditiveNumber("12"));
    check.checkBool(false, o.isAdditiveNumber("1023"));
    check.checkBool(false, o.isAdditiveNumber("10203"));
    check.checkBool(false, o.isAdditiveNumber("121224036"));
    check.checkBool(true, o.isAdditiveNumber("101"));
    check.checkBool(true, o.isAdditiveNumber("12122436"));
    check.checkBool(true, o.isAdditiveNumber("199111992"));
    check.checkBool(true, o.isAdditiveNumber("12012122436"));
    check.checkBool(true, o.isAdditiveNumber("198019823962"));
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
