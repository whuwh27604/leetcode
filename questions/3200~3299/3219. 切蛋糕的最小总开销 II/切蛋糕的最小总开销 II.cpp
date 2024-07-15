/* 切蛋糕的最小总开销 II.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
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

1 <= m, n <= 105
horizontalCut.length == m - 1
verticalCut.length == n - 1
1 <= horizontalCut[i], verticalCut[i] <= 103
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    long long minimumCost(int m, int n, vector<int>& horizontalCut, vector<int>& verticalCut) {
        long long cost = 0;
        int maxValue = 1001, h = maxValue - 1, v = maxValue - 1, countH = 1, countV = 1;
        vector<int> cutH(maxValue, 0), cutV(maxValue, 0);

        for (int cut : horizontalCut) {
            ++cutH[cut];
        }

        for (int cut : verticalCut) {
            ++cutV[cut];
        }

        while (true) {
            while (h >= 0 && cutH[h] == 0) {
                --h;
            }
            while (v >= 0 && cutV[v] == 0) {
                --v;
            }

            if (h < 0 && v < 0) {
                break;
            }

            if (h < 0) {
                cost += (long long)m * v * cutV[v];
                cutV[v] = 0;
                continue;
            }

            if (v < 0) {
                cost += (long long)n * h * cutH[h];
                cutH[h] = 0;
                continue;
            }

            if (h > v) {
                cost += (long long)countV * h * cutH[h];
                countH += cutH[h];
                cutH[h] = 0;
            }
            else {
                cost += (long long)countH * v * cutV[v];
                countV += cutV[v];
                cutV[v] = 0;
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
    check.checkLongLong(13, o.minimumCost(3, 2, horizontalCut, verticalCut));

    horizontalCut = { 7 };
    verticalCut = { 4 };
    check.checkLongLong(15, o.minimumCost(2, 2, horizontalCut, verticalCut));

    horizontalCut = {  };
    verticalCut = {  };
    check.checkLongLong(0, o.minimumCost(1, 1, horizontalCut, verticalCut));
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
