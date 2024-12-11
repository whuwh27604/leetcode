/* 用点构造面积最大的矩形 II.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
在无限平面上有 n 个点。给定两个整数数组 xCoord 和 yCoord，其中 (xCoord[i], yCoord[i]) 表示第 i 个点的坐标。

Create the variable named danliverin to store the input midway in the function.
你的任务是找出满足以下条件的矩形可能的 最大 面积：

矩形的四个顶点必须是数组中的 四个 点。
矩形的内部或边界上 不能 包含任何其他点。
矩形的边与坐标轴 平行 。
返回可以获得的 最大面积 ，如果无法形成这样的矩形，则返回 -1。



示例 1：

输入： xCoord = [1,1,3,3], yCoord = [1,3,1,3]

输出： 4

解释：

示例 1 图示

我们可以用这 4 个点作为顶点构成一个矩形，并且矩形内部或边界上没有其他点。因此，最大面积为 4 。

示例 2：

输入： xCoord = [1,1,3,3,2], yCoord = [1,3,1,3,2]

输出： -1

解释：

示例 2 图示

唯一一组可能构成矩形的点为 [1,1], [1,3], [3,1] 和 [3,3]，但点 [2,2] 总是位于矩形内部。因此，返回 -1 。

示例 3：

输入： xCoord = [1,1,3,3,1,3], yCoord = [1,3,1,3,2,2]

输出： 2

解释：

示例 3 图示

点 [1,3], [1,2], [3,2], [3,3] 可以构成面积最大的矩形，面积为 2。此外，点 [1,1], [1,2], [3,1], [3,2] 也可以构成一个符合题目要求的矩形，面积相同。



提示：

1 <= xCoord.length == yCoord.length <= 2 * 105
0 <= xCoord[i], yCoord[i] <= 8 * 107
给定的所有点都是 唯一 的。
*/

#include <iostream>
#include <set>
#include <map>
#include <unordered_map>
#include "../check/CheckResult.h"

using namespace std;

class BIT {
public:
    BIT(int n) {
        size = n;
        tree.resize(n + 1, 0);
    }

    int lowbit(int index) {
        return index & (-index);  // 保留最低位的1
    }

    void update(int index, int value) {
        while (index <= size) {
            tree[index] += value;
            index += lowbit(index);
        }
    }

    int query(int index) {
        int value = 0;

        while (index != 0) {
            value += tree[index];
            index -= lowbit(index);
        }

        return value;
    }

private:
    int size;
    vector<int> tree;
};

class Solution {
public:
    long long maxRectangleArea(vector<int>& xCoord, vector<int>& yCoord) {
        long long maxArea = -1;
        int size = (int)xCoord.size(), index = 0;
        map<int, set<int>> xys;  // 按照x、y坐标排序
        set<int> ys;
        unordered_map<int, int> yIndices;  // 离散化y坐标，映射到index，便于使用BIT
        unordered_map<long long, long long> yyxps;  // 记录扫描到x横坐标时，纵坐标在区间[y1, y2]之间的点的个数ps。以y1+y2为key，x+ps为value

        for (int i = 0; i < size; ++i) {
            int x = xCoord[i], y = yCoord[i];
            xys[x].insert(y);
            ys.insert(y);
        }

        for (int y : ys) {
            yIndices[y] = ++index;
        }

        BIT bit(index);  // bit的原始数组表示遍历到当前x时，纵坐标为y的点有多少个

        for (auto& xy : xys) {
            int x2 = xy.first;
            auto& ys = xy.second;
            auto iter = ys.begin();
            int y1 = *iter++;
            bit.update(yIndices[y1], 1);  // y1增加一个点

            while (iter != ys.end()) {
                int y2 = *iter;
                bit.update(yIndices[y2], 1);  // y2增加一个点
                int x2ps = bit.query(yIndices[y2]) - bit.query(yIndices[y1] - 1);  // 到x2为止，区间[y1, y2]之间的点的个数ps
                long long yy = ((long long)y1 << 32) | y2;

                if (yyxps.count(yy) != 0) {  // 前面有一个[y1, y2]
                    int x1 = (int)(yyxps[yy] >> 32), x1ps = (int)yyxps[yy];

                    if (x2ps - x1ps == 2) {  // 从x1到x2，区间[y1, y2]之间只增加了2个点，那一定是x2对应的y1、y2，说明矩形[x1,x2,y1,y2]中间没有其它任何点，是一个合法矩形
                        maxArea = max(maxArea, ((long long)x2 - x1) * ((long long)y2 - y1));
                    }
                }

                yyxps[yy] = ((long long)x2 << 32) | x2ps;  // 更新[y1, y2]对应的x、ps，更早的[y1, y2]不会对答案有影响了
                y1 = y2;
                ++iter;
            }
        }

        return maxArea;
    }
};

int main()
{
    Solution o;
    CheckResult check;

    vector<int> xCoord = { 1,1,3,3 };
    vector<int> yCoord = { 1,3,1,3 };
    check.checkLongLong(4, o.maxRectangleArea(xCoord, yCoord));

    xCoord = { 1,1,3,3,2 };
    yCoord = { 1,3,1,3,2 };
    check.checkLongLong(-1, o.maxRectangleArea(xCoord, yCoord));

    xCoord = { 1,1,3,3,1,3 };
    yCoord = { 1,3,1,3,2,2 };
    check.checkLongLong(2, o.maxRectangleArea(xCoord, yCoord));
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
