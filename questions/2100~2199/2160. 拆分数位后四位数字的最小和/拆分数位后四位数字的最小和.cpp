/* 拆分数位后四位数字的最小和.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你一个四位 正 整数 num 。请你使用 num 中的 数位 ，将 num 拆成两个新的整数 new1 和 new2 。new1 和 new2 中可以有 前导 0 ，且 num 中 所有 数位都必须使用。

比方说，给你 num = 2932 ，你拥有的数位包括：两个 2 ，一个 9 和一个 3 。一些可能的 [new1, new2] 数对为 [22, 93]，[23, 92]，[223, 9] 和 [2, 329] 。
请你返回可以得到的 new1 和 new2 的 最小 和。

 

示例 1：

输入：num = 2932
输出：52
解释：可行的 [new1, new2] 数对为 [29, 23] ，[223, 9] 等等。
最小和为数对 [29, 23] 的和：29 + 23 = 52 。
示例 2：

输入：num = 4009
输出：13
解释：可行的 [new1, new2] 数对为 [0, 49] ，[490, 0] 等等。
最小和为数对 [4, 9] 的和：4 + 9 = 13 。
 

提示：

1000 <= num <= 9999

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/minimum-sum-of-four-digit-number-after-splitting-digits
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <algorithm>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int minimumSum(int num) {
        string number = to_string(num);
        sort(number.begin(), number.end());

        return (number[0] - '0') * 10 + (number[1] - '0') * 10 + (number[2] - '0') + (number[3] - '0');
    }
};

int main()
{
    CheckResult check;
    Solution o;

    check.checkInt(52, o.minimumSum(2932));
    check.checkInt(13, o.minimumSum(4009));
    check.checkInt(1, o.minimumSum(1000));
    check.checkInt(198, o.minimumSum(9999));
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
