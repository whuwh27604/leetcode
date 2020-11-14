/* 24 点游戏.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
你有 4 张写有 1 到 9 数字的牌。你需要判断是否能通过 *，/，+，-，(，) 的运算得到 24。

示例 1:

输入: [4, 1, 8, 7]
输出: True
解释: (8-4) * (7-1) = 24
示例 2:

输入: [1, 2, 1, 2]
输出: False
注意:

除法运算符 / 表示实数除法，而不是整数除法。例如 4 / (1 - 2/3) = 12 。
每个运算符对两个数进行运算。特别是我们不能用 - 作为一元运算符。例如，[1, 1, 1, 1] 作为输入时，表达式 -1 - 1 - 1 - 1 是不允许的。
你不能将数字连接在一起。例如，输入为 [1, 2, 1, 2] 时，不能写成 12 + 12 。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/24-game
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <queue>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    bool judgePoint24(vector<int>& nums) {
        return judgePoint24_4(nums[0], nums[1], nums[2], nums[3]);
    }

    bool judgePoint24_1(double a) {
        return fabs(a - 24) < EPSILON;
    }

    bool judgePoint24_2(double a, double b) {
        return judgePoint24_1(a + b)
            || judgePoint24_1(a - b)
            || judgePoint24_1(b - a)
            || judgePoint24_1(a * b)
            || ((fabs(b) > EPSILON) && judgePoint24_1(a / b))
            || ((fabs(a) > EPSILON) && judgePoint24_1(b / a));
    }

    bool judgePoint24_3(double a, double b, double c) {
        return judgePoint24_2(a + b, c)
            || judgePoint24_2(a - b, c)
            || judgePoint24_2(b - a, c)
            || judgePoint24_2(a * b, c)
            || ((fabs(b) > EPSILON) && judgePoint24_2(a / b, c))
            || ((fabs(a) > EPSILON) && judgePoint24_2(b / a, c))
            || judgePoint24_2(a + c, b)
            || judgePoint24_2(a - c, b)
            || judgePoint24_2(c - a, b)
            || judgePoint24_2(a * c, b)
            || ((fabs(c) > EPSILON) && judgePoint24_2(a / c, b))
            || ((fabs(a) > EPSILON) && judgePoint24_2(c / a, b))
            || judgePoint24_2(c + b, a)
            || judgePoint24_2(c - b, a)
            || judgePoint24_2(b - c, a)
            || judgePoint24_2(c * b, a)
            || ((fabs(b) > EPSILON) && judgePoint24_2(c / b, a))
            || ((fabs(c) > EPSILON) && judgePoint24_2(b / c, a));
    }

    bool judgePoint24_4(double a, double b, double c, double d) {
        return judgePoint24_3(a + b, c, d)
            || judgePoint24_3(a - b, c, d)
            || judgePoint24_3(b - a, c, d)
            || judgePoint24_3(a * b, c, d)
            || ((fabs(b) > EPSILON) && judgePoint24_3(a / b, c, d))
            || ((fabs(a) > EPSILON) && judgePoint24_3(b / a, c, d))
            || judgePoint24_3(a + c, b, d)
            || judgePoint24_3(a - c, b, d)
            || judgePoint24_3(c - a, b, d)
            || judgePoint24_3(a * c, b, d)
            || ((fabs(c) > EPSILON) && judgePoint24_3(a / c, b, d))
            || ((fabs(a) > EPSILON) && judgePoint24_3(c / a, b, d))
            || judgePoint24_3(a + d, b, c)
            || judgePoint24_3(a - d, b, c)
            || judgePoint24_3(d - a, b, c)
            || judgePoint24_3(a * d, b, c)
            || ((fabs(d) > EPSILON) && judgePoint24_3(a / d, b, c))
            || ((fabs(a) > EPSILON) && judgePoint24_3(d / a, b, c))
            || judgePoint24_3(b + c, a, d)
            || judgePoint24_3(b - c, a, d)
            || judgePoint24_3(c - b, a, d)
            || judgePoint24_3(b * c, a, d)
            || ((fabs(c) > EPSILON) && judgePoint24_3(b / c, a, d))
            || ((fabs(b) > EPSILON) && judgePoint24_3(c / b, a, d))
            || judgePoint24_3(b + d, a, c)
            || judgePoint24_3(b - d, a, c)
            || judgePoint24_3(d - b, a, c)
            || judgePoint24_3(b * d, a, c)
            || ((fabs(d) > EPSILON) && judgePoint24_3(b / d, a, c))
            || ((fabs(b) > EPSILON) && judgePoint24_3(d / b, a, c))
            || judgePoint24_3(c + d, a, b)
            || judgePoint24_3(c - d, a, b)
            || judgePoint24_3(d - c, a, b)
            || judgePoint24_3(c * d, a, b)
            || ((fabs(d) > EPSILON) && judgePoint24_3(c / d, a, b))
            || ((fabs(c) > EPSILON) && judgePoint24_3(d / c, a, b));
    }

private:
    const double EPSILON = 1e-6;
};

int main()
{
    Solution o;
    CheckResult check;

    vector<int> nums = { 4,1,8,7 };
    check.checkBool(true, o.judgePoint24(nums));

    nums = { 1,2,1,2 };
    check.checkBool(false, o.judgePoint24(nums));

    nums = { 1,5,9,1 };
    check.checkBool(false, o.judgePoint24(nums));

    nums = { 9,9,5,9 };
    check.checkBool(false, o.judgePoint24(nums));

    nums = { 1,1,7,7 };
    check.checkBool(false, o.judgePoint24(nums));

    nums = { 3,4,6,7 };
    check.checkBool(false, o.judgePoint24(nums));

    nums = { 7,7,8,9 };
    check.checkBool(false, o.judgePoint24(nums));

    nums = { 5, 5, 8, 9 };
    check.checkBool(true, o.judgePoint24(nums));

    nums = { 4, 5, 5, 5 };
    check.checkBool(true, o.judgePoint24(nums));

    nums = { 3, 7, 9, 9 };
    check.checkBool(true, o.judgePoint24(nums));

    nums = { 3, 3, 8, 8 };
    check.checkBool(true, o.judgePoint24(nums));
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
