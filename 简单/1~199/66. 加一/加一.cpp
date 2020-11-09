/* 加一.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给定一个由整数组成的非空数组所表示的非负整数，在该数的基础上加一。

最高位数字存放在数组的首位， 数组中每个元素只存储单个数字。

你可以假设除了整数 0 之外，这个整数不会以零开头。

示例 1:

输入: [1,2,3]
输出: [1,2,4]
解释: 输入数组表示数字 123。
示例 2:

输入: [4,3,2,1]
输出: [4,3,2,2]
解释: 输入数组表示数字 4321。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/plus-one
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        for (int i = (digits.size() - 1); i >= 0; i--) {
            if (digits[i] != 9) {
                digits[i] += 1;
                return digits;
            }

            digits[i] = 0;
        }

        digits.insert(digits.begin(), 1);
        return digits;
    }
};

int main()
{
    Solution o;
    CheckResult check;

    vector<int> digits = { 1,2,3 };
    vector<int> expected = { 1,2,4 };
    vector<int> actual = o.plusOne(digits);
    check.checkIntVector(expected, actual);

    digits = { 0 };
    expected = { 1 };
    actual = o.plusOne(digits);
    check.checkIntVector(expected, actual);

    digits = { 9 };
    expected = { 1,0 };
    actual = o.plusOne(digits);
    check.checkIntVector(expected, actual);

    digits = { 1,9 };
    expected = { 2,0 };
    actual = o.plusOne(digits);
    check.checkIntVector(expected, actual);

    digits = { 9,9 };
    expected = { 1,0,0 };
    actual = o.plusOne(digits);
    check.checkIntVector(expected, actual);

    digits = { 9,9,9 };
    expected = { 1,0,0,0 };
    actual = o.plusOne(digits);
    check.checkIntVector(expected, actual);
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
