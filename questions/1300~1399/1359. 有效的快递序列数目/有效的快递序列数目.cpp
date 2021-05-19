/* 有效的快递序列数目.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你 n 笔订单，每笔订单都需要快递服务。

请你统计所有有效的 收件/配送 序列的数目，确保第 i 个物品的配送服务 delivery(i) 总是在其收件服务 pickup(i) 之后。

由于答案可能很大，请返回答案对 10^9 + 7 取余的结果。

 

示例 1：

输入：n = 1
输出：1
解释：只有一种序列 (P1, D1)，物品 1 的配送服务（D1）在物品 1 的收件服务（P1）后。
示例 2：

输入：n = 2
输出：6
解释：所有可能的序列包括：
(P1,P2,D1,D2)，(P1,P2,D2,D1)，(P1,D1,P2,D2)，(P2,P1,D1,D2)，(P2,P1,D2,D1) 和 (P2,D2,P1,D1)。
(P1,D2,P2,D1) 是一个无效的序列，因为物品 2 的收件服务（P2）不应在物品 2 的配送服务（D2）之后。
示例 3：

输入：n = 3
输出：90
 

提示：

1 <= n <= 500

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/count-all-valid-pickup-and-delivery-options
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int countOrders(int n) {
        long long dp = 1;

        for (int i = 1; i < n; ++i) {
            int slot = 2 * i + 1;
            int ways = (1 + slot) * slot / 2;
            dp = (dp * ways) % 1000000007;
        }

        return (int)dp;
    }
};

int main()
{
    CheckResult check;
    Solution o;

    check.checkInt(1, o.countOrders(1));
    check.checkInt(6, o.countOrders(2));
    check.checkInt(90, o.countOrders(3));
    check.checkInt(850728840, o.countOrders(10));
    check.checkInt(14159051, o.countOrders(100));
    check.checkInt(764678010, o.countOrders(500));
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
