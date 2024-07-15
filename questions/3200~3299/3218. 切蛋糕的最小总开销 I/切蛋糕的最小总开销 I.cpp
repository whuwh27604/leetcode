/* 切蛋糕的最小总开销 I.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
有一个 m x n 大小的矩形蛋糕，需要切成 1 x 1 的小块。

给你整数 m ，n 和两个数组：

horizontalCut 的大小为 m - 1 ，其中 horizontalCut[i] 表示沿着水平线 i 切蛋糕的开销。
verticalCut 的大小为 n - 1 ，其中 verticalCut[j] 表示沿着垂直线 j 切蛋糕的开销。
一次操作中，你可以选择任意不是 1 x 1 大小的矩形蛋糕并执行以下操作之一：

沿着水平线 i 切开蛋糕，开销为 horizontalCut[i] 。
沿着垂直线 j 切开蛋糕，开销为 verticalCut[j] 。
每次操作后，这块蛋糕都被切成两个独立的小蛋糕。

每次操作的开销都为最开始对应切割线的开销，并且不会改变。

请你返回将蛋糕全部切成 1 x 1 的蛋糕块的 最小 总开销。



示例 1：

输入：m = 3, n = 2, horizontalCut = [1,3], verticalCut = [5]

输出：13

解释：



沿着垂直线 0 切开蛋糕，开销为 5 。
沿着水平线 0 切开 3 x 1 的蛋糕块，开销为 1 。
沿着水平线 0 切开 3 x 1 的蛋糕块，开销为 1 。
沿着水平线 1 切开 2 x 1 的蛋糕块，开销为 3 。
沿着水平线 1 切开 2 x 1 的蛋糕块，开销为 3 。
总开销为 5 + 1 + 1 + 3 + 3 = 13 。

示例 2：

输入：m = 2, n = 2, horizontalCut = [7], verticalCut = [4]

输出：15

解释：

沿着水平线 0 切开蛋糕，开销为 7 。
沿着垂直线 0 切开 1 x 2 的蛋糕块，开销为 4 。
沿着垂直线 0 切开 1 x 2 的蛋糕块，开销为 4 。
总开销为 7 + 4 + 4 = 15 。



提示：

1 <= m, n <= 20
horizontalCut.length == m - 1
verticalCut.length == n - 1
1 <= horizontalCut[i], verticalCut[i] <= 103
*/

#include <iostream>
#include <algorithm>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int minimumCost(int m, int n, vector<int>& horizontalCut, vector<int>& verticalCut) {
        sort(horizontalCut.begin(), horizontalCut.end());
        sort(verticalCut.begin(), verticalCut.end());
        
        int cost = 0, h = m - 2, v = n - 2;

        while (h >= 0 || v >= 0) {
            if (h < 0) {
                cost += m * verticalCut[v--];
                continue;
            }

            if (v < 0) {
                cost += n * horizontalCut[h--];
                continue;
            }

            if (horizontalCut[h] > verticalCut[v]) {
                cost += (n - v - 1) * horizontalCut[h--];
            }
            else {
                cost += (m - h - 1) * verticalCut[v--];
            }
        }

        return cost;
    }
};

int main()
{
    Solution o;
    CheckResult check;

    vector<int> horizontalCut = { 1,3 };
    vector<int> verticalCut = { 5 };
    check.checkInt(13, o.minimumCost(3, 2, horizontalCut, verticalCut));

    horizontalCut = { 7 };
    verticalCut = { 4 };
    check.checkInt(15, o.minimumCost(2, 2, horizontalCut, verticalCut));

    horizontalCut = {  };
    verticalCut = {  };
    check.checkInt(0, o.minimumCost(1, 1, horizontalCut, verticalCut));
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
