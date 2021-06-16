/* 游乐园的迷宫.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
小王来到了游乐园，她玩的第一个项目是模拟推销员。有一个二维平面地图，其中散布着 N 个推销点，编号 0 到 N-1，不存在三点共线的情况。每两点之间有一条直线相连。游戏没有规定起点和终点，但限定了每次转角的方向。首先，小王需要先选择两个点分别作为起点和终点，然后从起点开始访问剩余 N-2 个点恰好一次并回到终点。访问的顺序需要满足一串给定的长度为 N-2 由 L 和 R 组成的字符串 direction，表示从起点出发之后在每个顶点上转角的方向。根据这个提示，小王希望你能够帮她找到一个可行的遍历顺序，输出顺序下标（若有多个方案，输出任意一种）。可以证明这样的遍历顺序一定是存在的。



（上图：A->B->C 右转； 下图：D->E->F 左转）

示例 1：

输入：points = [[1,1],[1,4],[3,2],[2,1]], direction = "LL"

输入：[0,2,1,3]

解释：[0,2,1,3] 是符合"LL"的方案之一。在 [0,2,1,3] 方案中，0->2->1 是左转方向， 2->1->3 也是左转方向

示例 2：

输入：points = [[1,3],[2,4],[3,3],[2,1]], direction = "LR"

输入：[0,3,1,2]

解释：[0,3,1,2] 是符合"LR"的方案之一。在 [0,3,1,2] 方案中，0->3->1 是左转方向， 3->1->2 是右转方向

限制：

3 <= points.length <= 1000 且 points[i].length == 2
1 <= points[i][0],points[i][1] <= 10000
direction.length == points.length - 2
direction 只包含 "L","R"

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/you-le-yuan-de-mi-gong
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Point {
public:
    int x;
    int y;
    int index;

    Point() : x(0), y(0), index(0) {}
    Point(int _x, int _y, int _index) : x(_x), y(_y), index(_index) {}
};

class Solution {
public:
    vector<int> visitOrder(vector<vector<int>>& points, string direction) {
        int size = points.size(), index = 0, end = size - 1;
        vector<int> order(size);
        vector<Point> allPoints(size);

        getPoints(points, allPoints);

        int leftmost = getLeftMost(allPoints);  // 从最左边的点开始
        Point original = allPoints[leftmost];
        choose(allPoints, leftmost, order, index, end);

        for (char dir : direction) {
            int next = 0;

            if (dir == 'L') {  // 如果向左转，则贪心的找最右边的点
                for (int i = 1; i <= end; ++i) {
                    if (getCrossProduct(original, allPoints[next], allPoints[i]) < 0) {  // 叉积小于0，相对于original，点b在点a的右边
                        next = i;
                    }
                }
            }
            else {  // 如果向右转，则贪心的找最左边的点
                for (int i = 1; i <= end; ++i) {
                    if (getCrossProduct(original, allPoints[next], allPoints[i]) > 0) {  // 叉积大于0，相对于original，点b在点a的左边
                        next = i;
                    }
                }
            }

            original = allPoints[next];
            choose(allPoints, next, order, index, end);
        }

        order.back() = allPoints[0].index;  // 最后还剩一个点

        return order;
    }

    void getPoints(vector<vector<int>>& points, vector<Point>& allPoints) {
        int index = 0;

        for (auto& point : points) {
            allPoints[index] = Point(point[0], point[1], index);
            ++index;
        }
    }

    int getLeftMost(vector<Point>& allPoints) {
        int leftmost = INT_MAX, index = 0, i, size = allPoints.size();

        for (i = 0; i < size; ++i) {
            if (allPoints[i].x < leftmost) {
                leftmost = allPoints[i].x;
                index = i;
            }
        }

        return index;
    }

    int getCrossProduct(Point& ori, Point& a, Point& b) {  // 求向量ori_a、ori_b的叉积
        return (a.x - ori.x) * (b.y - ori.y) - (a.y - ori.y) * (b.x - ori.x);
    }

    void choose(vector<Point>& allPoints, int chosen, vector<int>& order, int& index, int& end) {
        order[index++] = allPoints[chosen].index;  // 保存选中点的索引
        swap(allPoints[chosen], allPoints[end--]);  // 将选中的点交换到最后，可选范围减1
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<vector<int>> points = { {1,1},{1,4},{3,2},{2,1} };
    vector<int> actual = o.visitOrder(points, "LL");
    vector<int> expected = { 0,3,2,1 };
    check.checkIntVector(expected, actual);

    points = { {1,3},{2,4},{3,3},{2,1} };
    actual = o.visitOrder(points, "LR");
    expected = { 0,3,1,2 };
    check.checkIntVector(expected, actual);

    points = { {0,1},{1,0},{2,0},{3,1},{2,2},{1,2} };
    actual = o.visitOrder(points, "LRLR");
    expected = { 0,1,5,2,4,3 };
    check.checkIntVector(expected, actual);
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
