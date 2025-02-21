/* 分割正方形 I.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你一个二维整数数组 squares ，其中 squares[i] = [xi, yi, li] 表示一个与 x 轴平行的正方形的左下角坐标和正方形的边长。

找到一个最小的 y 坐标，它对应一条水平线，该线需要满足它以上正方形的总面积 等于 该线以下正方形的总面积。

答案如果与实际答案的误差在 10-5 以内，将视为正确答案。

注意：正方形 可能会 重叠。重叠区域应该被 多次计数 。



示例 1：

输入： squares = [[0,0,1],[2,2,1]]

输出： 1.00000

解释：



任何在 y = 1 和 y = 2 之间的水平线都会有 1 平方单位的面积在其上方，1 平方单位的面积在其下方。最小的 y 坐标是 1。

示例 2：

输入： squares = [[0,0,2],[1,1,1]]

输出： 1.16667

解释：



面积如下：

线下的面积：7/6 * 2 (红色) + 1/6 (蓝色) = 15/6 = 2.5。
线上的面积：5/6 * 2 (红色) + 5/6 (蓝色) = 15/6 = 2.5。
由于线以上和线以下的面积相等，输出为 7/6 = 1.16667。



提示：

1 <= squares.length <= 5 * 104
squares[i] = [xi, yi, li]
squares[i].length == 3
0 <= xi, yi <= 109
1 <= li <= 109
*/

#include <iostream>
#include <map>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    double separateSquares(vector<vector<int>>& squares) {
        map<int, long long> yLens;
        long long totalSqr = 0, sqr = 0;
        
        for (auto& sqr : squares) {
            int y = sqr[1], len = sqr[2];
            totalSqr += (long long)len * len;
            yLens[y] += len;
            yLens[y + len] -= len;
        }

        auto iter = yLens.begin();
        int y1 = iter->first, y2 = 0;
        long long len = iter->second;

        for (++iter; iter != yLens.end(); ++iter) {
            y2 = iter->first;
            sqr += len * (y2 - y1);

            if (sqr * 2 >= totalSqr) {
                break;
            }

            len += iter->second;
            y1 = y2;
        }

        return y2 - (sqr - (double)totalSqr / 2) / len;
    }
};

int main()
{
    Solution o;
    CheckResult check;

    vector<vector<int>> squares = { {0,0,1},{2,2,1} };
    check.checkDouble(1.00000, o.separateSquares(squares));

    squares = { {0,0,2},{1,1,1} };
    check.checkDouble(1.16667, o.separateSquares(squares));
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
