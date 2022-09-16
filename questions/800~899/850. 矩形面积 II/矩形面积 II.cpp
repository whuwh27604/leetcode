/* 矩形面积 II.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
我们给出了一个（轴对齐的）二维矩形列表 rectangles 。 对于 rectangle[i] = [x1, y1, x2, y2]，其中（x1，y1）是矩形 i 左下角的坐标， (xi1, yi1) 是该矩形 左下角 的坐标， (xi2, yi2) 是该矩形 右上角 的坐标。

计算平面中所有 rectangles 所覆盖的 总面积 。任何被两个或多个矩形覆盖的区域应只计算 一次 。

返回 总面积 。因为答案可能太大，返回 109 + 7 的 模 。

 

示例 1：



输入：rectangles = [[0,0,2,2],[1,0,2,3],[1,0,3,1]]
输出：6
解释：如图所示，三个矩形覆盖了总面积为6的区域。
从(1,1)到(2,2)，绿色矩形和红色矩形重叠。
从(1,0)到(2,3)，三个矩形都重叠。
示例 2：

输入：rectangles = [[0,0,1000000000,1000000000]]
输出：49
解释：答案是 1018 对 (109 + 7) 取模的结果， 即 49 。
 

提示：

1 <= rectangles.length <= 200
rectanges[i].length = 4
0 <= xi1, yi1, xi2, yi2 <= 109
矩形叠加覆盖后的总面积不会超越 2^63 - 1 ，这意味着可以用一个 64 位有符号整数来保存面积结果。

来源：力扣（LeetCode）
链接：https://leetcode.cn/problems/rectangle-area-ii
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <algorithm>
#include "../check/CheckResult.h"

using namespace std;

class Node {
public:
    int coordinate;
    int index;
    int lr;  // left or right

    Node(int x, int idx, int flag) : coordinate(x), index(idx), lr(flag) {}

    bool operator<(const Node& other) const {
        return coordinate < other.coordinate;
    }
};

class Solution {
public:
    int rectangleArea(vector<vector<int>>& rectangles) {
        int size = rectangles.size();
        vector<int> horizons;
        vector<Node> verticals;

        getVerticals(rectangles, verticals);
        sort(verticals.begin(), verticals.end());
        getHorisons(rectangles, horizons);
        sort(horizons.begin(), horizons.end());
        horizons.erase(unique(horizons.begin(), horizons.end()), horizons.end());

        return sweep(rectangles, horizons, verticals);
    }

    void getHorisons(vector<vector<int>>& rectangles, vector<int>& horizons) {
        for (auto& rectangle : rectangles) {
            horizons.push_back(rectangle[1]);  // 下边界
            horizons.push_back(rectangle[3]);  // 上边界
        }
    }

    void getVerticals(vector<vector<int>>& rectangles, vector<Node>& verticals) {
        for (int i = 0; i < (int)rectangles.size(); ++i) {
            verticals.push_back(Node(rectangles[i][0], i, 1));  // 左边界
            verticals.push_back(Node(rectangles[i][2], i, -1));  // 右边界
        }
    }

    int sweep(vector<vector<int>>& rectangles, vector<int>& horizons, vector<Node>& verticals) {
        long long area = 0;
        int i = 0, j = 0, k = 0, hsize = horizons.size(), vsize = verticals.size();
        vector<int> seg(hsize - 1, 0);

        for (int i = 0; i < vsize; ++i) {
            for (j = i; j + 1 < vsize && verticals[j + 1].coordinate == verticals[i].coordinate; ++j) {}
            if (j + 1 == vsize) {
                break;
            }

            for (k = i; k <= j; ++k) {
                for (int x = 0; x < hsize - 1; ++x) {
                    if (horizons[x] >= rectangles[verticals[k].index][1] && horizons[x + 1] <= rectangles[verticals[k].index][3]) {
                        seg[x] += verticals[k].lr;
                    }
                }
            }

            long long cover = 0;
            for (k = 0; k < hsize - 1; ++k) {
                if (seg[k] > 0) {
                    cover += ((long long)horizons[k + 1] - horizons[k]);
                }
            }

            area += cover * ((long long)verticals[j + 1].coordinate - verticals[j].coordinate);
            i = j;
        }

        return (int)(area % 1000000007);
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<vector<int>> rectangles = { {0,0,2,2},{1,0,2,3},{1,0,3,1} };
    check.checkInt(6, o.rectangleArea(rectangles));

    rectangles = { {0,0,1000000000,1000000000} };
    check.checkInt(49, o.rectangleArea(rectangles));

    rectangles = { {224386961,128668997,546647847,318900555},{852286866,238086790,992627088,949888275},{160239672,137108804,398130330,944807066},{431047948,462092719,870611028,856851714},{736895365,511285772,906155231,721626624},{289309389,607009433,558359552,883664714},{780746435,397872372,931219192,863727103},{573523994,124874359,889018012,471879750},{619886375,149607927,727026507,446976526},{51739879,716225241,115331335,785850603},{171077223,267051983,548436248,349498903},{314437215,169054168,950814572,481179241},{64126215,646689712,595562376,829164135},{926011655,481539702,982179297,832455610},{40370235,231510218,770233582,851797196},{292546319,45032676,413358795,783606009},{424366277,369838051,453541063,777456024},{211837048,142665527,217366958,952362711},{228416869,402115549,672143142,644930626},{755018294,194555696,846854520,939022548},{192890972,586071668,992336688,759060552},{127869582,392855032,338983665,954245205},{665603955,208757599,767586006,276627875},{260384651,10960359,736299693,761411808},{46440611,559601039,911666265,904518674},{54013763,90331595,332153447,106222561},{73093292,378586103,423488105,826750366},{327100855,516514806,676134763,653520887},{930781786,407609872,960671631,510621750},{35479655,449171431,931212840,617916927} };
    check.checkInt(862275791, o.rectangleArea(rectangles));
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
