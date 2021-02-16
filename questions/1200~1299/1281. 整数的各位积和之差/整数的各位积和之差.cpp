/* 整数的各位积和之差.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你一个整数 n，请你帮忙计算并返回该整数「各位数字之积」与「各位数字之和」的差。

 

示例 1：

输入：n = 234
输出：15
解释：
各位数之积 = 2 * 3 * 4 = 24
各位数之和 = 2 + 3 + 4 = 9
结果 = 24 - 9 = 15
示例 2：

输入：n = 4421
输出：21
解释：
各位数之积 = 4 * 4 * 2 * 1 = 32
各位数之和 = 4 + 4 + 2 + 1 = 11
结果 = 32 - 11 = 21
 

提示：

1 <= n <= 10^5

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/subtract-the-product-and-sum-of-digits-of-an-integer
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int subtractProductAndSum(int n) {
        int remainder, sum = 0, product = 1;

        while (n != 0) {
            remainder = n % 10;
            n /= 10;

            sum += remainder;
            product *= remainder;
        }

        return product - sum;
    }
};

int main()
{
    Solution o;
    CheckResult check;

    check.checkInt(15, o.subtractProductAndSum(234));
    check.checkInt(21, o.subtractProductAndSum(4421));
    check.checkInt(0, o.subtractProductAndSum(1));
    check.checkInt(-1, o.subtractProductAndSum(100000));
    check.checkInt(-6, o.subtractProductAndSum(105));
    check.checkInt(59004, o.subtractProductAndSum(99999));
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
