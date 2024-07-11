/* 最小矩形面积.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
二维平面上有 N 条直线，形式为 y = kx + b，其中 k、b为整数 且 k > 0。所有直线以 [k,b] 的形式存于二维数组 lines 中，不存在重合的两条直线。两两直线之间可能存在一个交点，最多会有 C
N
2
​
  个交点。我们用一个平行于坐标轴的矩形覆盖所有的交点，请问这个矩形最小面积是多少。若直线之间无交点、仅有一个交点或所有交点均在同一条平行坐标轴的直线上，则返回0。

注意：返回结果是浮点数，与标准答案 绝对误差或相对误差 在 10^-4 以内的结果都被视为正确结果

示例 1：

输入：lines = [[2,3],[3,0],[4,1]]

输出：48.00000

解释：三条直线的三个交点为 (3, 9) (1, 5) 和 (-1, -3)。最小覆盖矩形左下角为 (-1, -3) 右上角为 (3,9)，面积为 48

示例 2：

输入：lines = [[1,1],[2,3]]

输出：0.00000

解释：仅有一个交点 (-2，-1）

限制：

1 <= lines.length <= 10^5 且 lines[i].length == 2
1 <= lines[0] <= 10000
-10000 <= lines[1] <= 10000
与标准答案绝对误差或相对误差在 10^-4 以内的结果都被视为正确结果
*/

#include <iostream>
#include <map>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    double minRecSize(vector<vector<int>>& lines) {
        map<int, pair<int, int>> kbs;

        getMaxBs(lines, kbs);
        if (kbs.size() == 1) {
            return 0;
        }

        double minX = DBL_MAX, minY = DBL_MAX, maxX = -DBL_MAX, maxY = -DBL_MAX;
        auto iter = kbs.begin();
        int k1 = iter->first;
        double minB1 = iter->second.first, maxB1 = iter->second.second;
        
        while (++iter != kbs.end()) {  // 最远的交点只会出现在k相邻的2条直线上
            int k2 = iter->first, k = k1 - k2;
            double minB2 = iter->second.first, maxB2 = iter->second.second;
            minX = min(minX, (maxB2 - minB1) / k);
            maxX = max(maxX, (minB2 - maxB1) / k);
            minY = min(minY, (k1 * maxB2 - k2 * minB1) / k);
            maxY = max(maxY, (k1 * minB2 - k2 * maxB1) / k);
            k1 = k2, minB1 = minB2, maxB1 = maxB2;
        }

        return (maxX - minX) * (maxY - minY);
    }

    void getMaxBs(vector<vector<int>>& lines, map<int, pair<int, int>>& kbs) {
        for (auto& line : lines) {
            int k = line[0], b = line[1];
            if (kbs.count(k) == 0) {
                kbs[k] = { b,b };
            }
            else {
                kbs[k] = { min(kbs[k].first, b), max(kbs[k].second, b)};
            }
        }
    }
};

int main()
{
    Solution o;
    CheckResult check;

    vector<vector<int>> lines = { {2,3},{3,0},{4,1} };
    check.checkDouble(48.0, o.minRecSize(lines));

    lines = { {1,1},{2,3} };
    check.checkDouble(0, o.minRecSize(lines));

    lines = { {1,1} };
    check.checkDouble(0, o.minRecSize(lines));
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
