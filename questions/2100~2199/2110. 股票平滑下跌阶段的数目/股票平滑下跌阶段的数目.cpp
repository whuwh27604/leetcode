/* 股票平滑下跌阶段的数目.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你一个整数数组 prices ，表示一支股票的历史每日股价，其中 prices[i] 是这支股票第 i 天的价格。

一个 平滑下降的阶段 定义为：对于 连续一天或者多天 ，每日股价都比 前一日股价恰好少 1 ，这个阶段第一天的股价没有限制。

请你返回 平滑下降阶段 的数目。

 

示例 1：

输入：prices = [3,2,1,4]
输出：7
解释：总共有 7 个平滑下降阶段：
[3], [2], [1], [4], [3,2], [2,1] 和 [3,2,1]
注意，仅一天按照定义也是平滑下降阶段。
示例 2：

输入：prices = [8,6,7,7]
输出：4
解释：总共有 4 个连续平滑下降阶段：[8], [6], [7] 和 [7]
由于 8 - 6 ≠ 1 ，所以 [8,6] 不是平滑下降阶段。
示例 3：

输入：prices = [1]
输出：1
解释：总共有 1 个平滑下降阶段：[1]
 

提示：

1 <= prices.length <= 105
1 <= prices[i] <= 105

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/number-of-smooth-descent-periods-of-a-stock
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    long long getDescentPeriods(vector<int>& prices) {
        long long periods = 0, len = 1;
        int prev = 0;

        for (int price : prices) {
            if (prev == price + 1) {
                ++len;
            }
            else {
                len = 1;
            }

            periods += len;
            prev = price;
        }

        return periods;
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<int> prices = { 3,2,1,4 };
    check.checkLongLong(7, o.getDescentPeriods(prices));

    prices = { 8,6,7,7 };
    check.checkLongLong(4, o.getDescentPeriods(prices));

    prices = { 1 };
    check.checkLongLong(1, o.getDescentPeriods(prices));

    prices = { 9,8,7,6,5,8,7,6,7,6,5,4,4,3,2,1,2,1,1 };
    check.checkLongLong(45, o.getDescentPeriods(prices));
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
