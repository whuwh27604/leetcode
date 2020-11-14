/* 骑士拨号器.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
国际象棋中的骑士可以按下图所示进行移动：

 .           


这一次，我们将 “骑士” 放在电话拨号盘的任意数字键（如上图所示）上，接下来，骑士将会跳 N-1 步。每一步必须是从一个数字键跳到另一个数字键。

每当它落在一个键上（包括骑士的初始位置），都会拨出键所对应的数字，总共按下 N 位数字。

你能用这种方式拨出多少个不同的号码？

因为答案可能很大，所以输出答案模 10^9 + 7。

 

示例 1：

输入：1
输出：10
示例 2：

输入：2
输出：20
示例 3：

输入：3
输出：46
 

提示：

1 <= N <= 5000

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/knight-dialer
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int knightDialer(int n) {
        if (n == 1) {
            return 10;
        }

        int dp[10] = { 1,1,1,1,1,0,1,1,1,1 }, tmp[10] = { 0 }, mod = 1000000007;
        int* p1 = dp;
        int* p2 = tmp;

        for (int i = 1; i < n; ++i) {
            p2[0] = (p1[4] + p1[6]) % mod;
            p2[1] = (p1[6] + p1[8]) % mod;
            p2[2] = (p1[7] + p1[9]) % mod;
            p2[3] = (p1[4] + p1[8]) % mod;
            p2[4] = ((p1[3] + p1[9]) % mod + p1[0]) % mod;
            p2[6] = ((p1[1] + p1[7]) % mod + p1[0]) % mod;
            p2[7] = (p1[2] + p1[6]) % mod;
            p2[8] = (p1[1] + p1[3]) % mod;
            p2[9] = (p1[2] + p1[4]) % mod;

            swap(p1, p2);
        }

        int ans = 0;
        for (int i = 0; i < 10; ++i) {
            ans = (ans + p1[i]) % mod;
        }

        return ans;
    }
};

int main()
{
    CheckResult check;
    Solution o;

    check.checkInt(10, o.knightDialer(1));
    check.checkInt(20, o.knightDialer(2));
    check.checkInt(46, o.knightDialer(3));
    check.checkInt(14912, o.knightDialer(10));
    check.checkInt(540641702, o.knightDialer(100));
    check.checkInt(88106097, o.knightDialer(1000));
    check.checkInt(406880451, o.knightDialer(5000));
    check.checkInt(136006598, o.knightDialer(3131));
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
