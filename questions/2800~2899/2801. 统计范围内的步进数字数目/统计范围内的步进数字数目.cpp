/* 统计范围内的步进数字数目.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你两个正整数 low 和 high ，都用字符串表示，请你统计闭区间 [low, high] 内的 步进数字 数目。

如果一个整数相邻数位之间差的绝对值都 恰好 是 1 ，那么这个数字被称为 步进数字 。

请你返回一个整数，表示闭区间 [low, high] 之间步进数字的数目。

由于答案可能很大，请你将它对 109 + 7 取余 后返回。

注意：步进数字不能有前导 0 。



示例 1：

输入：low = "1", high = "11"
输出：10
解释：区间 [1,11] 内的步进数字为 1 ，2 ，3 ，4 ，5 ，6 ，7 ，8 ，9 和 10 。总共有 10 个步进数字。所以输出为 10 。
示例 2：

输入：low = "90", high = "101"
输出：2
解释：区间 [90,101] 内的步进数字为 98 和 101 。总共有 2 个步进数字。所以输出为 2 。


提示：

1 <= int(low) <= int(high) < 10100
1 <= low.length, high.length <= 100
low 和 high 只包含数字。
low 和 high 都不含前导 0 。
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int countSteppingNumbers(string low, string high) {
        return ((isStepping(low) ? 1 : 0) + countStepping(high) + mod - countStepping(low)) % mod;
    }

    bool isStepping(string& s) {
        for (int i = 0; i < (int)s.size() - 1; ++i) {
            if (abs(s[i] - s[i + 1]) != 1) {
                return false;
            }
        }

        return true;
    }

    int countStepping(string& s) {
        int size = s.size();
        vector<int> memo(size * 10 * 2 * 2, -1);

        return DFS(0, size, s, '0', false, true, memo);
    }

    // DFS(index, digit, isNum, isBorder) 表示当前index位是数字digit，前面是否已经是一个合法数（前缀0不是合法数），前面是否已经在上限，这种状态下可以得到的步进数个数
    int DFS(int index, int size, string& s, char digit, bool isNum, bool isBorder, vector<int>& memo) {
        if (index == size) {
            return isNum ? 1 : 0;  // 枚举完成时，前缀0不是合法数，其它都可以构成一个步进数
        }

        int state = index * 10 * 2 * 2 + (digit - '0') * 2 * 2 + (isNum ? 1 : 0) * 2 + (isBorder ? 1 : 0);
        if (memo[state] != -1) {
            return memo[state];
        }

        int count = 0;

        if (!isNum) {  // 前面都是前缀0
            char upper = index == 0 ? s[0] : '9';  // 如果是第一位，最大可以枚举到s[0]，其它位可以枚举到9
            count = DFS(index + 1, size, s, '0', false, false, memo);  // 当这一位选0时，isNum仍然是false，isBorder不再是上限
            count = (count + DFS(index + 1, size, s, upper, true, isBorder, memo)) % mod;  // 当这一位选upper时，isNum变为一个合法数，isBorder保持不变

            for (char c = '1'; c < upper; ++c) {
                count = (count + DFS(index + 1, size, s, c, true, false, memo)) % mod;  // 当这一位选中间数时，isNum变为一个合法数，isBorder不再是上限
            }

            return memo[state] = count;
        }

        char upper = isBorder ? s[index] : '9';  // 前面已经是合法数，如果前面是上限，那么当前位最多只能选到s[index]，否则可以选到9
        char dig = digit + 1;  // 按步进数定义，当前是digit，下一位可以选digit + 1或者digit - 1
        if (dig <= upper) {
            count = DFS(index + 1, size, s, dig, true, isBorder && dig == s[index], memo);  // 如果前面是上限，并且当前位选到了s[index]，那么仍然是上限
        }
        dig = digit - 1;
        if (dig >= '0' && dig <= upper) {
            count = (count + DFS(index + 1, size, s, dig, true, isBorder && dig == s[index], memo)) % mod;
        }

        return memo[state] = count;
    }

private:
    int mod = 1000000007;
};

int main()
{
    CheckResult check;
    Solution o;

    check.checkInt(10, o.countSteppingNumbers("1", "11"));
    check.checkInt(2, o.countSteppingNumbers("90", "101"));
    check.checkInt(6210, o.countSteppingNumbers("100", "10000000000"));
    check.checkInt(125046265, o.countSteppingNumbers("1", "9999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999"));
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
