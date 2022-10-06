/* 公因子的数目.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你两个正整数 a 和 b ，返回 a 和 b 的 公 因子的数目。

如果 x 可以同时整除 a 和 b ，则认为 x 是 a 和 b 的一个 公因子 。

 

示例 1：

输入：a = 12, b = 6
输出：4
解释：12 和 6 的公因子是 1、2、3、6 。
示例 2：

输入：a = 25, b = 30
输出：2
解释：25 和 30 的公因子是 1、5 。
 

提示：

1 <= a, b <= 1000

来源：力扣（LeetCode）
链接：https://leetcode.cn/problems/number-of-common-factors
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <algorithm>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int commonFactors(int a, int b) {
        int factors = 1;

        for (int factor = 2; factor <= min(a, b); ++factor) {
            if (a % factor == 0 && b % factor == 0) {
                ++factors;
            }
        }

        return factors;
    }
};

int main()
{
    CheckResult check;
    Solution o;

    check.checkInt(4, o.commonFactors(12, 6));
    check.checkInt(2, o.commonFactors(25, 30));
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
