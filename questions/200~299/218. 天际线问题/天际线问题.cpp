/* 天际线问题.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
城市的 天际线 是从远处观看该城市中所有建筑物形成的轮廓的外部轮廓。给你所有建筑物的位置和高度，请返回 由这些建筑物形成的 天际线 。

每个建筑物的几何信息由数组 buildings 表示，其中三元组 buildings[i] = [lefti, righti, heighti] 表示：

lefti 是第 i 座建筑物左边缘的 x 坐标。
righti 是第 i 座建筑物右边缘的 x 坐标。
heighti 是第 i 座建筑物的高度。
你可以假设所有的建筑都是完美的长方形，在高度为 0 的绝对平坦的表面上。

天际线 应该表示为由 “关键点” 组成的列表，格式 [[x1,y1],[x2,y2],...] ，并按 x 坐标 进行 排序 。关键点是水平线段的左端点。列表中最后一个点是最右侧建筑物的终点，y 坐标始终为 0 ，仅用于标记天际线的终点。此外，任何两个相邻建筑物之间的地面都应被视为天际线轮廓的一部分。

注意：输出天际线中不得有连续的相同高度的水平线。例如 [...[2 3], [4 5], [7 5], [11 5], [12 7]...] 是不正确的答案；三条高度为 5 的线应该在最终输出中合并为一个：[...[2 3], [4 5], [12 7], ...]

 

示例 1：


输入：buildings = [[2,9,10],[3,7,15],[5,12,12],[15,20,10],[19,24,8]]
输出：[[2,10],[3,15],[7,12],[12,0],[15,10],[20,8],[24,0]]
解释：
图 A 显示输入的所有建筑物的位置和高度，
图 B 显示由这些建筑物形成的天际线。图 B 中的红点表示输出列表中的关键点。
示例 2：

输入：buildings = [[0,2,3],[2,5,3]]
输出：[[0,3],[5,0]]
 

提示：

1 <= buildings.length <= 104
0 <= lefti < righti <= 231 - 1
1 <= heighti <= 231 - 1
buildings 按 lefti 非递减排序

来源：力扣（LeetCode）
链接：https://leetcode.cn/problems/the-skyline-problem
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <algorithm>
#include <queue>
#include "../check/CheckResult.h"

using namespace std;

struct pairCompare {
    bool operator()(const pair<int, int>& p1, const pair<int, int>& p2) const {
        return p1.second < p2.second;
    }
};

class Solution {
public:
    vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
        vector<int> boundaries;
        vector<vector<int>> skylines;

        getBoundaries(buildings, boundaries);
        sort(boundaries.begin(), boundaries.end());
        getSkylines(buildings, boundaries, skylines);

        return skylines;
    }

    void getBoundaries(vector<vector<int>>& buildings, vector<int>& boundaries) {
        for (auto& building : buildings) {
            boundaries.push_back(building[0]);
            boundaries.push_back(building[1]);
        }
    }

    void getSkylines(vector<vector<int>>& buildings, vector<int>& boundaries, vector<vector<int>>& skylines) {
        int index = 0, size = buildings.size();
        priority_queue<pair<int, int>, vector<pair<int, int>>, pairCompare> q;

        for (auto& boundary : boundaries) {
            while (index < size && buildings[index][0] <= boundary) {
                q.push({ buildings[index][1], buildings[index][2] });
                ++index;
            }

            while (!q.empty() && q.top().first <= boundary) {
                q.pop();
            }

            int maxn = q.empty() ? 0 : q.top().second;
            if (skylines.size() == 0 || maxn != skylines.back()[1]) {
                skylines.push_back({ boundary, maxn });
            }
        }
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<vector<int>> buildings = { {2,9,10},{3,7,15},{5,12,12},{15,20,10},{19,24,8} };
    vector<vector<int>> actual = o.getSkyline(buildings);
    vector<vector<int>> expected = { {2,10},{3,15},{7,12},{12,0},{15,10},{20,8},{24,0} };
    check.checkIntVectorVector(expected, actual);

    buildings = { {0,2,3},{2,5,3} };
    actual = o.getSkyline(buildings);
    expected = { {0,3},{5,0} };
    check.checkIntVectorVector(expected, actual);

    buildings = { {0,2147483647,2147483647} };
    actual = o.getSkyline(buildings);
    expected = { {0,2147483647},{2147483647,0} };
    check.checkIntVectorVector(expected, actual);

    buildings = { {2,14,4},{4,8,8},{6,16,4} };
    actual = o.getSkyline(buildings);
    expected = { {2,4},{4,8},{8,4},{16,0} };
    check.checkIntVectorVector(expected, actual);

    buildings = { {4,9,10},{4,9,15},{4,9,12},{10,12,10},{10,12,8} };
    actual = o.getSkyline(buildings);
    expected = { {4,15},{9,0},{10,10},{12,0} };
    check.checkIntVectorVector(expected, actual);

    buildings = { {0,1,3},{1,2,5},{2,5,3},{2,3,5},{2,7,3} };
    actual = o.getSkyline(buildings);
    expected = { {0,3},{1,5},{3,3},{7,0} };
    check.checkIntVectorVector(expected, actual);
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
