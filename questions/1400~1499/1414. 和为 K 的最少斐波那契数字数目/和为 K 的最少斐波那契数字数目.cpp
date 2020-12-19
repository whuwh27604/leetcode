/* 和为 K 的最少斐波那契数字数目.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你数字 k ，请你返回和为 k 的斐波那契数字的最少数目，其中，每个斐波那契数字都可以被使用多次。

斐波那契数字定义为：

F1 = 1
F2 = 1
Fn = Fn-1 + Fn-2 ， 其中 n > 2 。
数据保证对于给定的 k ，一定能找到可行解。

 

示例 1：

输入：k = 7
输出：2
解释：斐波那契数字为：1，1，2，3，5，8，13，……
对于 k = 7 ，我们可以得到 2 + 5 = 7 。
示例 2：

输入：k = 10
输出：2
解释：对于 k = 10 ，我们可以得到 2 + 8 = 10 。
示例 3：

输入：k = 19
输出：3
解释：对于 k = 19 ，我们可以得到 1 + 5 + 13 = 19 。
 

提示：

1 <= k <= 10^9

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/find-the-minimum-number-of-fibonacci-numbers-whose-sum-is-k
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int findMinFibonacciNumbers(int k) {
        int i, count = 1;
        vector<int> Fibonaccis(44);  // Fibonaccis[44] = 1134903170已经超过k了
        Fibonaccis[0] = Fibonaccis[1] = 1;

        for (i = 2; i < 44; ++i) {
            Fibonaccis[i] = Fibonaccis[i - 2] + Fibonaccis[i - 1];
        }

        for (i = 43; i >= 0; --i) {
            if (Fibonaccis[i] > k) {
                continue;
            }
            else if (Fibonaccis[i] == k) {
                break;
            }
            else {
                /* 贪心算法，小于k的最大Fibonacci一定要选上。证明：
                   1、不会选连续的2个数
                   2、不会选同一个数多次
                   3、由1、2，小于Fibonaccis[i]的所有可选数的和不会超过Fibonaccis[i]，所以Fibonaccis[i]一定要选上 */
                ++count;
                k -= Fibonaccis[i];
            }
        }

        return count;
    }
};

int main()
{
    CheckResult check;
    Solution o;

    check.checkInt(2, o.findMinFibonacciNumbers(7));
    check.checkInt(2, o.findMinFibonacciNumbers(10));
    check.checkInt(3, o.findMinFibonacciNumbers(19));
    check.checkInt(1, o.findMinFibonacciNumbers(1));
    check.checkInt(1, o.findMinFibonacciNumbers(2));
    check.checkInt(14, o.findMinFibonacciNumbers(1000000000));
    check.checkInt(13, o.findMinFibonacciNumbers(100000000));
    check.checkInt(9, o.findMinFibonacciNumbers(10000000));
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
