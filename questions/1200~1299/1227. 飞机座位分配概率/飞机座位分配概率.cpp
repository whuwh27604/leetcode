/* 飞机座位分配概率.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
有 n 位乘客即将登机，飞机正好有 n 个座位。第一位乘客的票丢了，他随便选了一个座位坐下。

剩下的乘客将会：

如果他们自己的座位还空着，就坐到自己的座位上，

当他们自己的座位被占用时，随机选择其他座位
第 n 位乘客坐在自己的座位上的概率是多少？

 

示例 1：

输入：n = 1
输出：1.00000
解释：第一个人只会坐在自己的位置上。
示例 2：

输入: n = 2
输出: 0.50000
解释：在第一个人选好座位坐下后，第二个人坐在自己的座位上的概率是 0.5。
 

提示：

1 <= n <= 10^5

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/airplane-seat-assignment-probability
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    double nthPersonGetsNthSeat(int n) {
        /* 令dp[n]表示n个人时，最后一个人坐自己座位的概率，则：
           n=1时，只有一个人一个座位，所以dp[1]=1
           n=2时，第一个人选1的概率是0.5，此时第二个人选2的概率是1；第一个人选2的概率是0.5，第二个人选2的概率是0。所以dp[2]=0.5*1+0.5*0=0.5
           n个人时，第一个人选i的概率是1/n，此时[2,i-1]的人都坐回自己的座位，问题变为了[1,i+1,...,n]个人，第i+1个人随机选了一个座位，问第n个人坐自己座位的概率。
           答案是dp[n-i+1]。所以dp[n]=1/n*1+1/n*dp[n-2+1]+1/n*dp[n-3+1]+...1/n*dp[n-(n-1)+1]+1/n*0=0.5 */
        return n == 1 ? 1 : 0.5;
    }
};

int main()
{
    CheckResult check;
    Solution o;

    check.checkDouble(1, o.nthPersonGetsNthSeat(1));
    check.checkDouble(0.5, o.nthPersonGetsNthSeat(2));
    check.checkDouble(0.5, o.nthPersonGetsNthSeat(100000));
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
