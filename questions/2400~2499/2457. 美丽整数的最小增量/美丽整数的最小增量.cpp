/* 美丽整数的最小增量.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你两个正整数 n 和 target 。

如果某个整数每一位上的数字相加小于或等于 target ，则认为这个整数是一个 美丽整数 。

找出并返回满足 n + x 是 美丽整数 的最小非负整数 x 。生成的输入保证总可以使 n 变成一个美丽整数。

 

示例 1：

输入：n = 16, target = 6
输出：4
解释：最初，n 是 16 ，且其每一位数字的和是 1 + 6 = 7 。在加 4 之后，n 变为 20 且每一位数字的和变成 2 + 0 = 2 。可以证明无法加上一个小于 4 的非负整数使 n 变成一个美丽整数。
示例 2：

输入：n = 467, target = 6
输出：33
解释：最初，n 是 467 ，且其每一位数字的和是 4 + 6 + 7 = 17 。在加 33 之后，n 变为 500 且每一位数字的和变成 5 + 0 + 0 = 5 。可以证明无法加上一个小于 33 的非负整数使 n 变成一个美丽整数。
示例 3：

输入：n = 1, target = 1
输出：0
解释：最初，n 是 1 ，且其每一位数字的和是 1 ，已经小于等于 target 。
 

提示：

1 <= n <= 1012
1 <= target <= 150
生成的输入保证总可以使 n 变成一个美丽整数。

来源：力扣（LeetCode）
链接：https://leetcode.cn/problems/minimum-addition-to-make-integer-beautiful
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    long long makeIntegerBeautiful(long long n, int target) {
        long long x = 0;
        string s = to_string(n);
        int i = 0, size = s.size();

        while (i < size && s[i] - '0' < target) {
            target -= (s[i++] - '0');
        }

        if (i == size) {  // 数位和比target小，x = 0
            return 0;
        }

        if (s[i] - '0' == target) {  // 当前位等于target，并且剩下的位都是0，x = 0
            string left(s, i + 1, size - i - 1);
            if (left.empty() || stoll(left) == 0) {
                return 0;
            }
        }

        for (; i < size; ++i) {  // 从不够的位开始，到结束位，要转化为100...00
            x = x * 10 + 9 - s[i] + '0';
        }

        return x + 1;
    }
};

int main()
{
    CheckResult check;
    Solution o;

    check.checkLongLong(4, o.makeIntegerBeautiful(16, 6));
    check.checkLongLong(33, o.makeIntegerBeautiful(467, 6));
    check.checkLongLong(0, o.makeIntegerBeautiful(1, 1));
    check.checkLongLong(99, o.makeIntegerBeautiful(1901, 10));
    check.checkLongLong(81, o.makeIntegerBeautiful(19, 1));
    check.checkLongLong(0, o.makeIntegerBeautiful(1, 2));
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
