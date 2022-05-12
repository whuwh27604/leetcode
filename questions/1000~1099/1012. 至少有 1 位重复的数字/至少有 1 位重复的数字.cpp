/* 至少有 1 位重复的数字.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给定正整数 n，返回在 [1, n] 范围内具有 至少 1 位 重复数字的正整数的个数。

 

示例 1：

输入：n = 20
输出：1
解释：具有至少 1 位重复数字的正数（<= 20）只有 11 。
示例 2：

输入：n = 100
输出：10
解释：具有至少 1 位重复数字的正数（<= 100）有 11，22，33，44，55，66，77，88，99 和 100 。
示例 3：

输入：n = 1000
输出：262
 

提示：

1 <= n <= 109

来源：力扣（LeetCode）
链接：https://leetcode.cn/problems/numbers-with-repeated-digits
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int numDupDigitsAtMostN(int n) {
        vector<int> noDups = { 0,9,81,648,4536,27216,136080,544320,1632960,3265920 };
        vector<bool> exist(10, false);
        vector<int> digits = to_digits(n);
        int i, size = digits.size(), count = 0;

        for (i = 1; i < size; ++i) {
            count += noDups[i];  // 小于n位数的不重复数
        }

        count += (digits[0] - 1) * getNoDups(size, 0);  // 最高位小于n的不重复数，最高位不能取0
        exist[digits[0]] = true;

        for (i = 1; i < size; ++i) {  // 从高到低遍历每一位等于n的情况下，还可以有多少不重复数
            count += getLess(exist, digits[i]) * getNoDups(size, i);

            if (exist[digits[i]]) {  // 到第i位n本身已经重复，不可能再有不重复数
                break;
            }

            exist[digits[i]] = true;
        }

        return n - count - (i == size ? 1 : 0);  // n本身是一个不重复数的情况下，count要加1
    }

    int getLess(vector<bool>& exist, int digit) {
        int count = 0;

        for (int i = 0; i < digit; ++i) {
            if (!exist[i]) {
                ++count;
            }
        }

        return count;
    }

    int getNoDups(int size, int index) {
        int count = 1, chosable = 9 - index;

        for (int i = index + 1; i < size; ++i, --chosable) {
            count *= chosable;
        }

        return count;
    }

    vector<int> to_digits(int n) {
        vector<int> digits;

        while (n != 0) {
            digits.push_back(n % 10);
            n /= 10;
        }

        reverse(digits.begin(), digits.end());

        return digits;
    }
};

int main()
{
    CheckResult check;
    Solution o;

    check.checkInt(1, o.numDupDigitsAtMostN(20));
    check.checkInt(10, o.numDupDigitsAtMostN(100));
    check.checkInt(262, o.numDupDigitsAtMostN(1000));
    check.checkInt(982042551, o.numDupDigitsAtMostN(987654321));
    check.checkInt(97541916, o.numDupDigitsAtMostN(99887766));
    check.checkInt(9, o.numDupDigitsAtMostN(99));
    check.checkInt(0, o.numDupDigitsAtMostN(1));
    check.checkInt(218729331, o.numDupDigitsAtMostN(221518701));
    check.checkInt(1058309, o.numDupDigitsAtMostN(1234599));
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
