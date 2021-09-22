/* 检测正方形.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你一个在 X-Y 平面上的点构成的数据流。设计一个满足下述要求的算法：

添加 一个在数据流中的新点到某个数据结构中。可以添加 重复 的点，并会视作不同的点进行处理。
给你一个查询点，请你从数据结构中选出三个点，使这三个点和查询点一同构成一个 面积为正 的 轴对齐正方形 ，统计 满足该要求的方案数目。
轴对齐正方形 是一个正方形，除四条边长度相同外，还满足每条边都与 x-轴 或 y-轴 平行或垂直。

实现 DetectSquares 类：

DetectSquares() 使用空数据结构初始化对象
void add(int[] point) 向数据结构添加一个新的点 point = [x, y]
int count(int[] point) 统计按上述方式与点 point = [x, y] 共同构造 轴对齐正方形 的方案数。
 

示例：


输入：
["DetectSquares", "add", "add", "add", "count", "count", "add", "count"]
[[], [[3, 10]], [[11, 2]], [[3, 2]], [[11, 10]], [[14, 8]], [[11, 2]], [[11, 10]]]
输出：
[null, null, null, null, 1, 0, null, 2]

解释：
DetectSquares detectSquares = new DetectSquares();
detectSquares.add([3, 10]);
detectSquares.add([11, 2]);
detectSquares.add([3, 2]);
detectSquares.count([11, 10]); // 返回 1 。你可以选择：
                               //   - 第一个，第二个，和第三个点
detectSquares.count([14, 8]);  // 返回 0 。查询点无法与数据结构中的这些点构成正方形。
detectSquares.add([11, 2]);    // 允许添加重复的点。
detectSquares.count([11, 10]); // 返回 2 。你可以选择：
                               //   - 第一个，第二个，和第三个点
                               //   - 第一个，第三个，和第四个点
 

提示：

point.length == 2
0 <= x, y <= 1000
调用 add 和 count 的 总次数 最多为 5000

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/detect-squares
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <unordered_map>
#include "../check/CheckResult.h"

using namespace std;

class DetectSquares {
public:
    DetectSquares() {

    }

    void add(vector<int> point) {
        ++points[point[0]][point[1]];
    }

    int count(vector<int> point) {
        int x1 = point[0], y1 = point[1], squares = 0;

        for (auto& p : points[x1]) {
            if (p.first != y1) {
                int y2 = p.first, side = abs(y1 - y2), x3 = x1 + side;

                if (points.count(x3) != 0 && points[x3].count(y1) != 0 && points[x3].count(y2) != 0) {
                    squares += (p.second * points[x3][y1] * points[x3][y2]);
                }

                x3 = x1 - side;

                if (points.count(x3) != 0 && points[x3].count(y1) != 0 && points[x3].count(y2) != 0) {
                    squares += (p.second * points[x3][y1] * points[x3][y2]);
                }
            }
        }

        return squares;
    }

private:
    unordered_map<int, unordered_map<int, int>> points;  // {x,{y,times}}
};

int main()
{
    CheckResult check;

    DetectSquares o1;
    o1.add({ 3,10 });
    o1.add({ 11,2 });
    o1.add({ 3,2 });
    check.checkInt(1, o1.count({ 11,10 }));
    check.checkInt(0, o1.count({ 14,8 }));
    o1.add({ 11,2 });
    check.checkInt(2, o1.count({ 11,10 }));

    DetectSquares o2;
    o2.add({ 0,0 });
    o2.add({ 1,0 });
    o2.add({ 0,1 });
    o2.add({ 1,1 });
    check.checkInt(1, o2.count({ 1,1 }));
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
