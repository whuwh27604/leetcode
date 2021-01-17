/* 销售价值减少的颜色球.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
你有一些球的库存 inventory ，里面包含着不同颜色的球。一个顾客想要 任意颜色 总数为 orders 的球。

这位顾客有一种特殊的方式衡量球的价值：每个球的价值是目前剩下的 同色球 的数目。比方说还剩下 6 个黄球，那么顾客买第一个黄球的时候该黄球的价值为 6 。这笔交易以后，只剩下 5 个黄球了，所以下一个黄球的价值为 5 （也就是球的价值随着顾客购买同色球是递减的）

给你整数数组 inventory ，其中 inventory[i] 表示第 i 种颜色球一开始的数目。同时给你整数 orders ，表示顾客总共想买的球数目。你可以按照 任意顺序 卖球。

请你返回卖了 orders 个球以后 最大 总价值之和。由于答案可能会很大，请你返回答案对 109 + 7 取余数 的结果。

 

示例 1：


输入：inventory = [2,5], orders = 4
输出：14
解释：卖 1 个第一种颜色的球（价值为 2 )，卖 3 个第二种颜色的球（价值为 5 + 4 + 3）。
最大总和为 2 + 5 + 4 + 3 = 14 。
示例 2：

输入：inventory = [3,5], orders = 6
输出：19
解释：卖 2 个第一种颜色的球（价值为 3 + 2），卖 4 个第二种颜色的球（价值为 5 + 4 + 3 + 2）。
最大总和为 3 + 2 + 5 + 4 + 3 + 2 = 19 。
示例 3：

输入：inventory = [2,8,4,10,6], orders = 20
输出：110
示例 4：

输入：inventory = [1000000000], orders = 1000000000
输出：21
解释：卖 1000000000 次第一种颜色的球，总价值为 500000000500000000 。 500000000500000000 对 109 + 7 取余为 21 。
 

提示：

1 <= inventory.length <= 105
1 <= inventory[i] <= 109
1 <= orders <= min(sum(inventory[i]), 109)

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/sell-diminishing-valued-colored-balls
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <algorithm>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& inventory, int orders) {
        int size = inventory.size(), index = size - 1, mod = 1000000007;
        long long count = 0, totalProfit = 0;

        sort(inventory.begin(), inventory.end());

        while (index >= 0) {
            long long profit = inventory[index];

            for (index -= 1; index >= 0 && inventory[index] == profit; --index) {}

            long long width = (long long)size - index - 1, nextProfit = index < 0 ? 0 : inventory[index];

            if ((profit - nextProfit) * width + count <= orders) {
                count += (profit - nextProfit) * width;
                totalProfit = (totalProfit + (profit + nextProfit + 1) * (profit - nextProfit) / 2 * width) % mod;
            }
            else {
                long long height = (orders - count) / width;
                totalProfit = (totalProfit + (profit + profit - height + 1) * height / 2 * width) % mod;
                totalProfit = (totalProfit + (profit - height) * (orders - count - height * width)) % mod;
                break;
            }
        }

        return (int)totalProfit;
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<int> inventory = { 2,5 };
    check.checkInt(14, o.maxProfit(inventory, 4));

    inventory = { 3,5 };
    check.checkInt(19, o.maxProfit(inventory, 6));

    inventory = { 2,8,4,10,6 };
    check.checkInt(110, o.maxProfit(inventory, 20));

    inventory = { 1000000000 };
    check.checkInt(21, o.maxProfit(inventory, 1000000000));

    inventory = { 773160767 };
    check.checkInt(70267492, o.maxProfit(inventory, 252264991));
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
