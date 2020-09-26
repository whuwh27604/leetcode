/* 股票价格跨度.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
编写一个 StockSpanner 类，它收集某些股票的每日报价，并返回该股票当日价格的跨度。

今天股票价格的跨度被定义为股票价格小于或等于今天价格的最大连续日数（从今天开始往回数，包括今天）。

例如，如果未来7天股票的价格是 [100, 80, 60, 70, 60, 75, 85]，那么股票跨度将是 [1, 1, 1, 2, 1, 4, 6]。

 

示例：

输入：["StockSpanner","next","next","next","next","next","next","next"], [[],[100],[80],[60],[70],[60],[75],[85]]
输出：[null,1,1,1,2,1,4,6]
解释：
首先，初始化 S = StockSpanner()，然后：
S.next(100) 被调用并返回 1，
S.next(80) 被调用并返回 1，
S.next(60) 被调用并返回 1，
S.next(70) 被调用并返回 2，
S.next(60) 被调用并返回 1，
S.next(75) 被调用并返回 4，
S.next(85) 被调用并返回 6。

注意 (例如) S.next(75) 返回 4，因为截至今天的最后 4 个价格
(包括今天的价格 75) 小于或等于今天的价格。
 

提示：

调用 StockSpanner.next(int price) 时，将有 1 <= price <= 10^5。
每个测试用例最多可以调用  10000 次 StockSpanner.next。
在所有测试用例中，最多调用 150000 次 StockSpanner.next。
此问题的总时间限制减少了 50%。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/online-stock-span
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <stack>
#include "../check/CheckResult.h"

using namespace std;

class StockSpanner {
public:
    StockSpanner() {
        prices.push({ INT_MAX,0 });
    }

    int next(int price) {
        int days = 1;

        while (price >= prices.top().first) {
            days += prices.top().second;
            prices.pop();
        }

        prices.push({ price, days });

        return days;
    }

private:
    stack<pair<int, int>> prices;
};

int main()
{
    CheckResult check;

    StockSpanner o1;
    check.checkInt(1, o1.next(100));
    check.checkInt(1, o1.next(80));
    check.checkInt(1, o1.next(60));
    check.checkInt(2, o1.next(70));
    check.checkInt(1, o1.next(60));
    check.checkInt(4, o1.next(75));
    check.checkInt(6, o1.next(85));

    StockSpanner o2;
    check.checkInt(1, o2.next(10));
    check.checkInt(2, o2.next(10));
    check.checkInt(3, o2.next(10));

    StockSpanner o3;
    check.checkInt(1, o3.next(10));
    check.checkInt(1, o3.next(9));
    check.checkInt(1, o3.next(8));
    check.checkInt(4, o3.next(10));
    check.checkInt(1, o3.next(9));
    check.checkInt(1, o3.next(8));
    check.checkInt(7, o3.next(10));
    check.checkInt(1, o3.next(9));
    check.checkInt(1, o3.next(8));
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
