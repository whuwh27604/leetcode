/* 表示一个折线图的最少线段数.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你一个二维整数数组 stockPrices ，其中 stockPrices[i] = [dayi, pricei] 表示股票在 dayi 的价格为 pricei 。折线图 是一个二维平面上的若干个点组成的图，横坐标表示日期，纵坐标表示价格，折线图由相邻的点连接而成。比方说下图是一个例子：


请你返回要表示一个折线图所需要的 最少线段数 。

 

示例 1：



输入：stockPrices = [[1,7],[2,6],[3,5],[4,4],[5,4],[6,3],[7,2],[8,1]]
输出：3
解释：
上图为输入对应的图，横坐标表示日期，纵坐标表示价格。
以下 3 个线段可以表示折线图：
- 线段 1 （红色）从 (1,7) 到 (4,4) ，经过 (1,7) ，(2,6) ，(3,5) 和 (4,4) 。
- 线段 2 （蓝色）从 (4,4) 到 (5,4) 。
- 线段 3 （绿色）从 (5,4) 到 (8,1) ，经过 (5,4) ，(6,3) ，(7,2) 和 (8,1) 。
可以证明，无法用少于 3 条线段表示这个折线图。
示例 2：



输入：stockPrices = [[3,4],[1,2],[7,8],[2,3]]
输出：1
解释：
如上图所示，折线图可以用一条线段表示。
 

提示：

1 <= stockPrices.length <= 105
stockPrices[i].length == 2
1 <= dayi, pricei <= 109
所有 dayi 互不相同 。

来源：力扣（LeetCode）
链接：https://leetcode.cn/problems/minimum-lines-to-represent-a-line-chart
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <algorithm>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int minimumLines(vector<vector<int>>& stockPrices) {
        int i, size = stockPrices.size(), lines = 1;

        if (size < 3) {
            return size - 1;
        }

        sort(stockPrices.begin(), stockPrices.end());

        for (i = 2; i < size; ++i) {
            int x1 = stockPrices[i - 1][0] - stockPrices[i - 2][0], x2 = stockPrices[i][0] - stockPrices[i - 1][0];
            int y1 = stockPrices[i - 1][1] - stockPrices[i - 2][1], y2 = stockPrices[i][1] - stockPrices[i - 1][1];

            if ((long long)x1 * y2 != (long long)x2 * y1) {
                ++lines;
            }
        }

        return lines;
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<vector<int>> stockPrices = {{1,1},{2,1},{3,2},{4,2},{5,1},{6,1}};
    check.checkInt(5,o.minimumLines(stockPrices));

    stockPrices = {{1,1}};
    check.checkInt(0,o.minimumLines(stockPrices));

    stockPrices = {{1,1},{2,2}};
    check.checkInt(1,o.minimumLines(stockPrices));

    stockPrices = {{1,7},{2,6},{3,5},{4,4},{5,4},{6,3},{7,2},{8,1}};
    check.checkInt(3,o.minimumLines(stockPrices));

    stockPrices = {{3,4},{1,2},{7,8},{2,3}};
    check.checkInt(1,o.minimumLines(stockPrices));

    stockPrices = {{1,1},{500000000,499999999},{1000000000,999999998}};
    check.checkInt(2,o.minimumLines(stockPrices));

    stockPrices = {{72,98},{62,27},{32,7},{71,4},{25,19},{91,30},{52,73},{10,9},{99,71},{47,22},{19,30},{80,63},{18,15},{48,17},{77,16},{46,27},{66,87},{55,84},{65,38},{30,9},{50,42},{100,60},{75,73},{98,53},{22,80},{41,61},{37,47},{95,8},{51,81},{78,79},{57,95}};
    check.checkInt(29,o.minimumLines(stockPrices));
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
