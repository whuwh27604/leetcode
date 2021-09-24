/* 访问完所有房间的第一天.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
你需要访问 n 个房间，房间从 0 到 n - 1 编号。同时，每一天都有一个日期编号，从 0 开始，依天数递增。你每天都会访问一个房间。

最开始的第 0 天，你访问 0 号房间。给你一个长度为 n 且 下标从 0 开始 的数组 nextVisit 。在接下来的几天中，你访问房间的 次序 将根据下面的 规则 决定：

假设某一天，你访问 i 号房间。
如果算上本次访问，访问 i 号房间的次数为 奇数 ，那么 第二天 需要访问 nextVisit[i] 所指定的房间，其中 0 <= nextVisit[i] <= i 。
如果算上本次访问，访问 i 号房间的次数为 偶数 ，那么 第二天 需要访问 (i + 1) mod n 号房间。
请返回你访问完所有房间的第一天的日期编号。题目数据保证总是存在这样的一天。由于答案可能很大，返回对 109 + 7 取余后的结果。

 

示例 1：

输入：nextVisit = [0,0]
输出：2
解释：
- 第 0 天，你访问房间 0 。访问 0 号房间的总次数为 1 ，次数为奇数。
  下一天你需要访问房间的编号是 nextVisit[0] = 0
- 第 1 天，你访问房间 0 。访问 0 号房间的总次数为 2 ，次数为偶数。
  下一天你需要访问房间的编号是 (0 + 1) mod 2 = 1
- 第 2 天，你访问房间 1 。这是你第一次完成访问所有房间的那天。
示例 2：

输入：nextVisit = [0,0,2]
输出：6
解释：
你每天访问房间的次序是 [0,0,1,0,0,1,2,...] 。
第 6 天是你访问完所有房间的第一天。
示例 3：

输入：nextVisit = [0,1,2,0]
输出：6
解释：
你每天访问房间的次序是 [0,0,1,1,2,2,3,...] 。
第 6 天是你访问完所有房间的第一天。
 

提示：

n == nextVisit.length
2 <= n <= 105
0 <= nextVisit[i] <= i

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/first-day-where-you-have-been-in-all-the-rooms
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int firstDayBeenInAllRooms(vector<int>& nextVisit) {
        /* 1、根据关键条件0 <= nextVisit[i] <= i可知，第一次到达位置i时，必然要回到前面某个位置j；第二次到达位置i时，下一步可以到达位置i+1。
           2、第一次到达位置i，必然回到位置j。注意此时区间[j,i]肯定都是偶数次访问，因为任何一个位置奇数次访问都将导致返回，到不了位置i。
              所以，这就相当于又要重复第一次到达位置j，并最终第一次到达位置i，但实际此时是第二次到达位置i，然后可以继续往前走了。
           3、令dp[i]表示第一次到达位置i的天数，根据上面的推理可知dp[i+1]=dp[i]+1+dp[i]-dp[nextVisit[i]]+1，即第一次走到位置i需要dp[i]天；
              然后返回位置j需要1天；然后从位置j第一次访问走到位置i需要dp[i]-dp[j]天；此时位置i是第二次访问，最后需要一天走到位置i+1。 */
        int i, n = nextVisit.size(), mod = 1000000007;
        vector<int> dp(n);
        dp[1] = 2;

        for (i = 2; i < n; ++i) {
            dp[i] = (2 * (long long)dp[i - 1] - dp[nextVisit[i - 1]] + 2 + mod) % mod;
        }

        return dp.back();
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<int> nextVisit = { 0,0 };
    check.checkInt(2, o.firstDayBeenInAllRooms(nextVisit));

    nextVisit = { 0,0,2 };
    check.checkInt(6, o.firstDayBeenInAllRooms(nextVisit));

    nextVisit = { 0,1,2,0 };
    check.checkInt(6, o.firstDayBeenInAllRooms(nextVisit));

    nextVisit = { 0,0,0,0 };
    check.checkInt(14, o.firstDayBeenInAllRooms(nextVisit));

    nextVisit = { 0,1,0,2,4,4 };
    check.checkInt(20, o.firstDayBeenInAllRooms(nextVisit));

    nextVisit = { 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 };
    check.checkInt(383381196, o.firstDayBeenInAllRooms(nextVisit));

    nextVisit = { 0,1,2,3,4,5,6,7,8,9,0,1,2,3,4,5,6,7,8,9,0,1,2,3,4,5,6,7,8,9,0,1,2,3,4,5,6,7,8,9,0,1,2,3,4,5,6,7,8,9 };
    check.checkInt(864114983, o.firstDayBeenInAllRooms(nextVisit));
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
