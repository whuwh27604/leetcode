/* 青蛙跳台阶问题.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
一只青蛙一次可以跳上1级台阶，也可以跳上2级台阶。求该青蛙跳上一个 n 级的台阶总共有多少种跳法。

答案需要取模 1e9+7（1000000007），如计算初始结果为：1000000008，请返回 1。

示例 1：

输入：n = 2
输出：2
示例 2：

输入：n = 7
输出：21
示例 3：

输入：n = 0
输出：1
提示：

0 <= n <= 100
注意：本题与主站 70 题相同：https://leetcode-cn.com/problems/climbing-stairs/

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/qing-wa-tiao-tai-jie-wen-ti-lcof
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int numWays(int n) {
        int i, prevTwo = 1, prev = 1, dp = 1, mod = 1000000007;

        for (i = 2; i <= n; ++i) {
            dp = prevTwo + prev;
            if (dp >= mod) {
                dp -= mod;
            }

            prevTwo = prev;
            prev = dp;
        }

        return dp;
    }
};

int main()
{
    CheckResult check;
    Solution o;

    check.checkInt(1, o.numWays(0));
    check.checkInt(1, o.numWays(1));
    check.checkInt(2, o.numWays(2));
    check.checkInt(21, o.numWays(7));
    check.checkInt(89, o.numWays(10));
    check.checkInt(782204094, o.numWays(100));
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
