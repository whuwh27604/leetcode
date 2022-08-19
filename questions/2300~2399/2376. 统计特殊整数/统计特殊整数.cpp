/* 统计特殊整数.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
如果一个正整数每一个数位都是 互不相同 的，我们称它是 特殊整数 。

给你一个 正 整数 n ，请你返回区间 [1, n] 之间特殊整数的数目。

 

示例 1：

输入：n = 20
输出：19
解释：1 到 20 之间所有整数除了 11 以外都是特殊整数。所以总共有 19 个特殊整数。
示例 2：

输入：n = 5
输出：5
解释：1 到 5 所有整数都是特殊整数。
示例 3：

输入：n = 135
输出：110
解释：从 1 到 135 总共有 110 个整数是特殊整数。
不特殊的部分数字为：22 ，114 和 131 。
 

提示：

1 <= n <= 2 * 109

来源：力扣（LeetCode）
链接：https://leetcode.cn/problems/count-special-integers
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int countSpecialNumbers(int n) {
        vector<int> digits;
        int count = getDigits(n, digits);
        if (count == 1) {  // 1位数，全部都是specials
            return n;
        }

        int numbers = 9;  // 比n位数少的specials，1位数共9个
        for (int digitsCnt = 2; digitsCnt < count; ++digitsCnt) {  // 统计[2, count - 1]位数
            numbers += 9 * permutation(9, digitsCnt - 1);  // 第一位可选[1,9]共9个选择，剩下从9个数字中选digitsCnt - 1个的排列
        }

        // 下面计算和n一样位数并且比n小的specials
        vector<bool> exist(10, false);
        exist[digits[0]] = true;
        numbers += (digits[0] - 1) * permutation(9, count - 1);  // 第一位比digits[0]小的specials

        for (int i = 1; i < count; ++i) {  // 从左到右依次选定为digits[i]，看剩下还有多少specials
            int choseable = 0;
            for (int k = 0; k < digits[i]; ++k) {
                if (!exist[k]) {
                    ++choseable;
                }
            }

            numbers += choseable * permutation(9 - i, count - 1 - i);  // 从剩下的9 - i个数字中选count - 1 - i个的排列

            if (exist[digits[i]]) {
                break;  // 如果这一位的数字已经出现过，那么就不会再有specials了
            }
            else {
                exist[digits[i]] = true;  // 否则这一位选定为digits[i]，继续往后寻找
            }
        }

        return numbers + (isSpecial(digits) ? 1 : 0);
    }

    int getDigits(int n, vector<int>& digits) {
        int count = 0;

        while (n != 0) {
            digits.push_back(n % 10);
            n /= 10;
            ++count;
        }

        reverse(digits.begin(), digits.end());

        return count;
    }

    bool isSpecial(vector<int>& digits) {
        vector<bool> exist(10, false);

        for (int digit : digits) {
            if (exist[digit]) {
                return false;
            }

            exist[digit] = true;
        }

        return true;
    }

    int permutation(int x, int y) {
        int ans = 1;

        for (int i = 0; i < y; ++i) {
            ans *= x--;
        }

        return ans;
    }
};

int main()
{
    CheckResult check;
    Solution o;

    check.checkInt(1, o.countSpecialNumbers(1));
    check.checkInt(5, o.countSpecialNumbers(5));
    check.checkInt(19, o.countSpecialNumbers(20));
    check.checkInt(90, o.countSpecialNumbers(99));
    check.checkInt(110, o.countSpecialNumbers(135));
    check.checkInt(418, o.countSpecialNumbers(555));
    check.checkInt(738, o.countSpecialNumbers(999));
    check.checkInt(5658004, o.countSpecialNumbers(1234567890));
    check.checkInt(5611770, o.countSpecialNumbers(987654321));
    check.checkInt(5611770, o.countSpecialNumbers(999999999));
    check.checkInt(5943791, o.countSpecialNumbers(1928073645));
    check.checkInt(5974650, o.countSpecialNumbers(2000000000));
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
