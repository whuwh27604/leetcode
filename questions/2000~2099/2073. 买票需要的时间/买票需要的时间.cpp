/* 买票需要的时间.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
有 n 个人前来排队买票，其中第 0 人站在队伍 最前方 ，第 (n - 1) 人站在队伍 最后方 。

给你一个下标从 0 开始的整数数组 tickets ，数组长度为 n ，其中第 i 人想要购买的票数为 tickets[i] 。

每个人买票都需要用掉 恰好 1 秒 。一个人 一次只能买一张票 ，如果需要购买更多票，他必须走到  队尾 重新排队（瞬间 发生，不计时间）。如果一个人没有剩下需要买的票，那他将会 离开 队伍。

返回位于位置 k（下标从 0 开始）的人完成买票需要的时间（以秒为单位）。

 

示例 1：

输入：tickets = [2,3,2], k = 2
输出：6
解释：
- 第一轮，队伍中的每个人都买到一张票，队伍变为 [1, 2, 1] 。
- 第二轮，队伍中的每个都又都买到一张票，队伍变为 [0, 1, 0] 。
位置 2 的人成功买到 2 张票，用掉 3 + 3 = 6 秒。
示例 2：

输入：tickets = [5,1,1,1], k = 0
输出：8
解释：
- 第一轮，队伍中的每个人都买到一张票，队伍变为 [4, 0, 0, 0] 。
- 接下来的 4 轮，只有位置 0 的人在买票。
位置 0 的人成功买到 5 张票，用掉 4 + 1 + 1 + 1 + 1 = 8 秒。
 

提示：

n == tickets.length
1 <= n <= 100
1 <= tickets[i] <= 100
0 <= k < n

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/time-needed-to-buy-tickets
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int timeRequiredToBuy(vector<int>& tickets, int k) {
        int i, size = tickets.size(), time = 0, ticket = tickets[k];

        for (i = 0; i <= k; ++i) {
            time += (tickets[i] > ticket ? ticket : tickets[i]);
        }

        --ticket;

        for (; i < size; ++i) {
            time += (tickets[i] > ticket ? ticket : tickets[i]);
        }

        return time;
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<int> tickets = { 2,3,2 };
    check.checkInt(6, o.timeRequiredToBuy(tickets, 2));

    tickets = { 5,1,1,1 };
    check.checkInt(8, o.timeRequiredToBuy(tickets, 0));

    tickets = { 100 };
    check.checkInt(100, o.timeRequiredToBuy(tickets, 0));
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
