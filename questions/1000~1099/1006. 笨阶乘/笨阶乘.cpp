/* 笨阶乘.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
通常，正整数 n 的阶乘是所有小于或等于 n 的正整数的乘积。例如，factorial(10) = 10 * 9 * 8 * 7 * 6 * 5 * 4 * 3 * 2 * 1。

相反，我们设计了一个笨阶乘 clumsy：在整数的递减序列中，我们以一个固定顺序的操作符序列来依次替换原有的乘法操作符：乘法(*)，除法(/)，加法(+)和减法(-)。

例如，clumsy(10) = 10 * 9 / 8 + 7 - 6 * 5 / 4 + 3 - 2 * 1。然而，这些运算仍然使用通常的算术运算顺序：我们在任何加、减步骤之前执行所有的乘法和除法步骤，并且按从左到右处理乘法和除法步骤。

另外，我们使用的除法是地板除法（floor division），所以 10 * 9 / 8 等于 11。这保证结果是一个整数。

实现上面定义的笨函数：给定一个整数 N，它返回 N 的笨阶乘。

 

示例 1：

输入：4
输出：7
解释：7 = 4 * 3 / 2 + 1
示例 2：

输入：10
输出：12
解释：12 = 10 * 9 / 8 + 7 - 6 * 5 / 4 + 3 - 2 * 1
 

提示：

1 <= N <= 10000
-2^31 <= answer <= 2^31 - 1  （答案保证符合 32 位整数。）

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/clumsy-factorial
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int clumsy(int N) {
        /* n*(n-1)/(n-2)+(n-3)-(n-4)*(n-5)/(n-6)+(n-7)-....1，分3种情况：
           第一种，最开始1组4个数n*(n-1)/(n-2)+(n-3)=(n-2+2)*(n-2+1)/(n-2)+(n-3)=(n-2)+3+2/(n-2)+(n-3)=(n-2)+3+(n-3)=2(n-1)
           第二种，中间x组4个数，x=(n-1)/4-1。对每一组4个数，假设为-(n+2)*(n+1)/n+(n-1)=-(n+3+2/n)+(n-1)=-(n+3)+(n-1)=-4
           第三种，最后剩余的1~4个数 */
        int first4[4] = { 1, (2 * 1), (3 * 2 / 1), (4 * 3 / 2 + 1) };
        int remainder[4] = { (-4 * 3 / 2 + 1), -1, (-2*1), (-3 * 2 / 1) };
        return (N > 4) ? (2 * (N - 1) - 4 * ((N - 1) / 4 - 1) + remainder[N % 4]) : first4[N - 1];
    }
};

int main()
{
    CheckResult check;
    Solution o;

    check.checkInt(1, o.clumsy(1));
    check.checkInt(2, o.clumsy(2));
    check.checkInt(6, o.clumsy(3));
    check.checkInt(7, o.clumsy(4));
    check.checkInt(7, o.clumsy(5));
    check.checkInt(8, o.clumsy(6));
    check.checkInt(6, o.clumsy(7));
    check.checkInt(9, o.clumsy(8));
    check.checkInt(11, o.clumsy(9));
    check.checkInt(12, o.clumsy(10));
    check.checkInt(10, o.clumsy(11));
    check.checkInt(13, o.clumsy(12));
    check.checkInt(15, o.clumsy(13));
    check.checkInt(101, o.clumsy(100));
    check.checkInt(1001, o.clumsy(1000));
    check.checkInt(10001, o.clumsy(10000));
    check.checkInt(9998, o.clumsy(9999));
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
