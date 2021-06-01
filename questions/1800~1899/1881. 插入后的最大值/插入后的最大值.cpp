/* 插入后的最大值.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你一个非常大的整数 n 和一个整数数字 x ，大整数 n 用一个字符串表示。n 中每一位数字和数字 x 都处于闭区间 [1, 9] 中，且 n 可能表示一个 负数 。

你打算通过在 n 的十进制表示的任意位置插入 x 来 最大化 n 的 数值 ​​​​​​。但 不能 在负号的左边插入 x 。

例如，如果 n = 73 且 x = 6 ，那么最佳方案是将 6 插入 7 和 3 之间，使 n = 763 。
如果 n = -55 且 x = 2 ，那么最佳方案是将 2 插在第一个 5 之前，使 n = -255 。
返回插入操作后，用字符串表示的 n 的最大值。

 

示例 1：

输入：n = "99", x = 9
输出："999"
解释：不管在哪里插入 9 ，结果都是相同的。
示例 2：

输入：n = "-13", x = 2
输出："-123"
解释：向 n 中插入 x 可以得到 -213、-123 或者 -132 ，三者中最大的是 -123 。
 

提示：

1 <= n.length <= 105
1 <= x <= 9
n​​​ 中每一位的数字都在闭区间 [1, 9] 中。
n 代表一个有效的整数。
当 n 表示负数时，将会以字符 '-' 开始。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/maximum-value-after-insertion
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    string maxValue(string n, int x) {
        int i, size = n.size();

        if (n[0] == '-') {
            for (i = 1; i < size; ++i) {
                if (n[i] - '0' > x) {
                    break;
                }
            }
        }
        else {
            for (i = 0; i < size; ++i) {
                if (n[i] - '0' < x) {
                    break;
                }
            }
        }

        return string(n, 0, i) + to_string(x) + string(n, i, size - i);
    }
};

int main()
{
    CheckResult check;
    Solution o;

    check.checkString("763", o.maxValue("73", 6));
    check.checkString("-255", o.maxValue("-55", 2));
    check.checkString("999", o.maxValue("99", 9));
    check.checkString("-123", o.maxValue("-13", 2));
    check.checkString("11", o.maxValue("1", 1));
    check.checkString("3221123", o.maxValue("321123", 2));
    check.checkString("-89", o.maxValue("-9", 8));
    check.checkString("-2321123", o.maxValue("-321123", 2));
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
