/* 表示数字的最少运算符.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给定一个正整数 x，我们将会写出一个形如 x (op1) x (op2) x (op3) x ... 的表达式，其中每个运算符 op1，op2，… 可以是加、减、乘、除（+，-，*，或是 /）之一。例如，对于 x = 3，我们可以写出表达式 3 * 3 / 3 + 3 - 3，该式的值为 3 。

在写这样的表达式时，我们需要遵守下面的惯例：

除运算符（/）返回有理数。
任何地方都没有括号。
我们使用通常的操作顺序：乘法和除法发生在加法和减法之前。
不允许使用一元否定运算符（-）。例如，“x - x” 是一个有效的表达式，因为它只使用减法，但是 “-x + x” 不是，因为它使用了否定运算符。 
我们希望编写一个能使表达式等于给定的目标值 target 且运算符最少的表达式。返回所用运算符的最少数量。

 

示例 1：

输入：x = 3, target = 19
输出：5
解释：3 * 3 + 3 * 3 + 3 / 3 。表达式包含 5 个运算符。
示例 2：

输入：x = 5, target = 501
输出：8
解释：5 * 5 * 5 * 5 - 5 * 5 * 5 + 5 / 5 。表达式包含 8 个运算符。
示例 3：

输入：x = 100, target = 100000000
输出：3
解释：100 * 100 * 100 * 100 。表达式包含 3 个运算符。
 

提示：

2 <= x <= 100
1 <= target <= 2 * 10^8

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/least-operators-to-express-number
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <unordered_map>
#include <algorithm>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int leastOpsExpressTarget(int x, int target) {
        unordered_map<long long, int> leastOps;
        return getLeastOps(x, target, leastOps);
    }

    int getLeastOps(long long x, long long target, unordered_map<long long, int>& leastOps) {
        long long num = x, sum = 1 + x;
        int ops = 0;

        if (leastOps.count(target) != 0) {
            return leastOps[target];
        }

        if (x == target) {
            ops = 0;
        }
        else if (x > target) {  // target已经小于x，那么可以选择x-x/x-x/x-...或者x/x+x/x+...
            ops = (int)min((2 * (x - target)), 2 * target - 1);
        }
        else {
            while (num * x < target) {
                num *= x;
                sum += num;
                ++ops;
            }

            if (num * x == target) {
                ops += 1;
            }
            else {
                int k = (int)(target / num);

                /* 如果大于target的数减多余部分的方案会导致target变大，则不能选择这个方案。因为这样新的target是num * x - target，
                   它小于num * x，这就会导致它要求num * x - (num * x - target) = target，变死循环了。 */
                if (num * x - target >= target) {
                    ops = k * (ops + 1) + getLeastOps(x, target - k * num, leastOps);
                }
                else {  // 比较小于target的数加余数部分的方案和大于target的数减多余部分的方案，选择更小的
                    ops = min(k * (ops + 1) + getLeastOps(x, target - k * num, leastOps), ops + 2 + getLeastOps(x, num * x - target, leastOps));
                }
            }
        }

        leastOps[target] = ops;
        return ops;
    }
};

int main()
{
    CheckResult check;
    Solution o;

    check.checkInt(5, o.leastOpsExpressTarget(3, 19));
    check.checkInt(8, o.leastOpsExpressTarget(5, 501));
    check.checkInt(3, o.leastOpsExpressTarget(100, 100000000));
    check.checkInt(1, o.leastOpsExpressTarget(2, 1));
    check.checkInt(151, o.leastOpsExpressTarget(97, 98765432));
    check.checkInt(0, o.leastOpsExpressTarget(97, 97));
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
