/* 单调递增的数字.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给定一个非负整数 N，找出小于或等于 N 的最大的整数，同时这个整数需要满足其各个位数上的数字是单调递增。

（当且仅当每个相邻位数上的数字 x 和 y 满足 x <= y 时，我们称这个整数是单调递增的。）

示例 1:

输入: N = 10
输出: 9
示例 2:

输入: N = 1234
输出: 1234
示例 3:

输入: N = 332
输出: 299
说明: N 是在 [0, 10^9] 范围内的一个整数。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/monotone-increasing-digits
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int monotoneIncreasingDigits(int N) {
        vector<int> digits;
        num2Digits(N, digits);

        int i, size = digits.size();
        for (i = size - 2; i >= 0; i--) {
            if (digits[i] < digits[i + 1]) {  // 找到第一个降序
                break;
            }
        }

        if (i < 0) {
            return N;
        }

        int index = i + 1, digit = digits[index];
        for (; i >= 0; i--) {
            digits[i] = 9;  // 低位全部置9
        }

        while ((index + 1 < size) && (digits[index + 1] == digit)) {
            digits[index++] = 9;  // 降序的位置减1，如果有连续相等的数字，则连续最高的一位减1，其它的置9
        }
        digits[index]--;

        return digits2Num(digits);
    }

    void num2Digits(int num, vector<int>& digits) {
        if (num == 0) {
            digits.push_back(0);
            return;
        }

        while (num != 0) {
            digits.push_back(num % 10);
            num /= 10;
        }
    }

    int digits2Num(vector<int>& digits) {
        int num = 0, i, size = digits.size();

        for (i = size - 1; i >= 0; i--) {
            num = num * 10 + digits[i];
        }

        return num;
    }
};

int main()
{
    Solution o;
    CheckResult check;

    check.checkInt(0, o.monotoneIncreasingDigits(0));
    check.checkInt(9, o.monotoneIncreasingDigits(9));
    check.checkInt(9, o.monotoneIncreasingDigits(10));
    check.checkInt(1234, o.monotoneIncreasingDigits(1234));
    check.checkInt(299, o.monotoneIncreasingDigits(332));
    check.checkInt(3999, o.monotoneIncreasingDigits(4321));
    check.checkInt(44999, o.monotoneIncreasingDigits(45321));
    check.checkInt(99, o.monotoneIncreasingDigits(100));
    check.checkInt(999, o.monotoneIncreasingDigits(1110));
    check.checkInt(999, o.monotoneIncreasingDigits(1001));
    check.checkInt(3999, o.monotoneIncreasingDigits(4365));
    check.checkInt(12344, o.monotoneIncreasingDigits(12344));
    check.checkInt(12339, o.monotoneIncreasingDigits(12343));
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
