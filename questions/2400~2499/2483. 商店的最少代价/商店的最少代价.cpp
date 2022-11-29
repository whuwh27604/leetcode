/* 商店的最少代价.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你一个顾客访问商店的日志，用一个下标从 0 开始且只包含字符 'N' 和 'Y' 的字符串 customers 表示：

如果第 i 个字符是 'Y' ，它表示第 i 小时有顾客到达。
如果第 i 个字符是 'N' ，它表示第 i 小时没有顾客到达。
如果商店在第 j 小时关门（0 <= j <= n），代价按如下方式计算：

在开门期间，如果某一个小时没有顾客到达，代价增加 1 。
在关门期间，如果某一个小时有顾客到达，代价增加 1 。
请你返回在确保代价 最小 的前提下，商店的 最早 关门时间。

注意，商店在第 j 小时关门表示在第 j 小时以及之后商店处于关门状态。



示例 1：

输入：customers = "YYNY"
输出：2
解释：
- 第 0 小时关门，总共 1+1+0+1 = 3 代价。
- 第 1 小时关门，总共 0+1+0+1 = 2 代价。
- 第 2 小时关门，总共 0+0+0+1 = 1 代价。
- 第 3 小时关门，总共 0+0+1+1 = 2 代价。
- 第 4 小时关门，总共 0+0+1+0 = 1 代价。
在第 2 或第 4 小时关门代价都最小。由于第 2 小时更早，所以最优关门时间是 2 。
示例 2：

输入：customers = "NNNNN"
输出：0
解释：最优关门时间是 0 ，因为自始至终没有顾客到达。
示例 3：

输入：customers = "YYYY"
输出：4
解释：最优关门时间是 4 ，因为每一小时均有顾客到达。


提示：

1 <= customers.length <= 105
customers 只包含字符 'Y' 和 'N' 。
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int bestClosingTime(string customers) {
        int ys = 0, ns = 0;

        for (char c : customers) {
            c == 'Y' ? ++ys : ++ns;
        }

        int size = customers.size(), best = ys, bestTime = 0, yys = 0, nns = 0;

        for (int i = 0; i < size; ++i) {
            customers[i] == 'Y' ? ++yys : ++nns;
            int cost = nns + (ys - yys);
            if (cost < best) {
                best = cost;
                bestTime = i + 1;
            }
        }

        return bestTime;
    }
};

int main()
{
    CheckResult check;
    Solution o;

    check.checkInt(2, o.bestClosingTime("YYNY"));
    check.checkInt(0, o.bestClosingTime("NNNNN"));
    check.checkInt(4, o.bestClosingTime("YYYY"));
    check.checkInt(41, o.bestClosingTime("YYNYNNNNNYYYYYYNYNNNNNYYYYYYNYNNNNNYYYYYYNYNNNNNYYYY"));
    check.checkInt(65, o.bestClosingTime("NNNNNYYNYYYYYNNNNNYYNYYYYYNNNNNYYNYYYYYNNNNNYYNYYYYYNNNNNYYNYYYYY"));
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
