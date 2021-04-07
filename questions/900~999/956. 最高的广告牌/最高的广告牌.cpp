/* 最高的广告牌.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
你正在安装一个广告牌，并希望它高度最大。这块广告牌将有两个钢制支架，两边各一个。每个钢支架的高度必须相等。

你有一堆可以焊接在一起的钢筋 rods。举个例子，如果钢筋的长度为 1、2 和 3，则可以将它们焊接在一起形成长度为 6 的支架。

返回广告牌的最大可能安装高度。如果没法安装广告牌，请返回 0。

 

示例 1：

输入：[1,2,3,6]
输出：6
解释：我们有两个不相交的子集 {1,2,3} 和 {6}，它们具有相同的和 sum = 6。
示例 2：

输入：[1,2,3,4,5,6]
输出：10
解释：我们有两个不相交的子集 {2,3,5} 和 {4,6}，它们具有相同的和 sum = 10。
示例 3：

输入：[1,2]
输出：0
解释：没法安装广告牌，所以返回 0。
 

提示：

0 <= rods.length <= 20
1 <= rods[i] <= 1000
钢筋的长度总和最多为 5000

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/tallest-billboard
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <algorithm>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int tallestBillboard(vector<int>& rods) {
        if (rods.empty()) {
            return 0;
        }

        /* dp[i][diff]表示选了i个rods，左右高度之差为diff时，左边的最大高度，那么每次新增一个rod，有三个选择：
           1、直接丢弃，dp[i][diff]不变
           2、加入到左边，则dp[i-1][diff-rods[i]]变为dp[i][diff]，左边的最大高度增加rods[i]
           3、加入到右边，则dp[i-1][diff+rods[i]]变为dp[i][diff]，左边的最大高度不变 */
        int i, diff, size = rods.size(), sum = getSum(rods);
        vector<vector<int>> dp(size, vector<int>(sum * 2 + 1, -1));
        dp[0][sum] = 0, dp[0][sum + rods[0]] = rods[0], dp[0][sum - rods[0]] = 0;

        for (i = 1; i < size; ++i) {
            for (diff = -sum; diff <= sum; ++diff) {
                dp[i][sum + diff] = dp[i - 1][sum + diff];

                if (sum + diff - rods[i] >= 0 && dp[i - 1][sum + diff - rods[i]] != -1) {
                    dp[i][sum + diff] = max(dp[i][sum + diff], dp[i - 1][sum + diff - rods[i]] + rods[i]);
                }

                if (diff + rods[i] <= sum && dp[i - 1][sum + diff + rods[i]] != -1) {
                    dp[i][sum + diff] = max(dp[i][sum + diff], dp[i - 1][sum + diff + rods[i]]);
                }
            }
        }

        return dp[size - 1][sum] != -1 ? dp[size - 1][sum] : 0;
    }

    int getSum(vector<int>& rods) {
        int sum = 0;

        for (int rod : rods) {
            sum += rod;
        }

        return sum;
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<int> rods = { 1,2,3,6 };
    check.checkInt(6, o.tallestBillboard(rods));

    rods = { 1,2,3,4,5,6 };
    check.checkInt(10, o.tallestBillboard(rods));

    rods = { 1,2 };
    check.checkInt(0, o.tallestBillboard(rods));

    rods = { 100,200,300,400,300,100,200,300,400,200,100,200,300,400,300,100,200,300,400,200 };
    check.checkInt(2500, o.tallestBillboard(rods));

    rods = { 100,200,300,400,8,100,200,300,400,200,100,200,300,400,8,100,200,300,400,200 };
    check.checkInt(2208, o.tallestBillboard(rods));

    rods = {  };
    check.checkInt(0, o.tallestBillboard(rods));

    rods = { 1 };
    check.checkInt(0, o.tallestBillboard(rods));
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
